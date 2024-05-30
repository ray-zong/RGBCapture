#include "screenshot.h"

#include <QDebug>

#ifdef Q_OS_WIN
#include <Windows.h>
#include <wingdi.h>
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Gdi32.lib")
#else

#endif

#include "capturehelpers.h"
#include "nativemethods_helpers.h"

Screenshot::Screenshot(QObject *parent)
    : QObject{parent}
    , m_bCaptureCursor(false)
    , m_bCaptureClientArea(false)
    , m_bRemoveOutsideScreenArea(true)
    , m_bCaptureShadow(false)
    , m_nShadowOffset(20)
    , m_bAutoHideTaskbar(false)
{

}

QImage Screenshot::captureRectangle(QRect rect)
{
    if(m_bRemoveOutsideScreenArea)
    {
        QRect bounds = CaptureHelpers::getScreenBounds();
        rect = rect.intersected(bounds);
    }

    return captureRectangleNative(rect, m_bCaptureCursor);
}

QImage Screenshot::captureFullScreen()
{
    return captureRectangle(CaptureHelpers::getScreenBounds());
}

QImage Screenshot::captureWindow(int wid)
{
    QImage image;

    if(wid > 0)
    {
        QRect rect;
        if(m_bCaptureClientArea)
        {
            rect = NativeMethods_Helpers::getClientRect(wid);
        }
        else
        {
            rect = CaptureHelpers::getWindowRectangle(wid);
        }

        bool bIsTaskbarHide = false;
        if(m_bAutoHideTaskbar)
        {
            bIsTaskbarHide = NativeMethods_Helpers::setTaskbarVisibilityIfIntersect(false, rect);
        }

        image = captureRectangle(rect);

        if(bIsTaskbarHide)
        {
            NativeMethods_Helpers::setTaskbarVisibility(true);
        }
    }
    else
    {
        qCritical() << __FUNCTION__ << "error:" << wid;
    }

    return image;
}

QImage Screenshot::captureActiveWindow()
{
    HWND hwnd = GetForegroundWindow();
    return captureWindow(PtrToInt(hwnd));
}

QImage Screenshot::captureActiveMonitor()
{
    QRect bounds = CaptureHelpers::getActiveScreenBounds();
    return captureRectangle(bounds);
}

QImage Screenshot::captureRectangleNative(const QRect &rect, bool captureCursor)
{
    HWND hwnd = GetDesktopWindow();
    return captureRectangleNative(PtrToInt(hwnd), rect, captureCursor);
}

QImage Screenshot::captureRectangleNative(int handle, const QRect &rect, bool captureCursor)
{
    QImage image;

    if (rect.width() == 0 || rect.height() == 0)
    {
        return image;
    }

    HDC hdcSrc = GetWindowDC((HWND)IntToPtr(handle));
    HDC hdcDest = CreateCompatibleDC(hdcSrc);
    HBITMAP hBitmap = CreateCompatibleBitmap(hdcSrc, rect.width(), rect.height());
    HGDIOBJ hOld = SelectObject(hdcDest, hBitmap);
    if(BitBlt(hdcDest, 0, 0, rect.width(), rect.height(), hdcSrc, rect.x(), rect.y(), SRCCOPY | CAPTUREBLT))
    {

        if (captureCursor)
        {
            tagCURSORINFO cursorInfo;
            cursorInfo.cbSize = sizeof(tagCURSORINFO);
            GetCursorInfo(&cursorInfo);
            if(DrawIcon(hdcDest, cursorInfo.ptScreenPos.x, cursorInfo.ptScreenPos.y, cursorInfo.hCursor) == 0)
            {
                qCritical() << __FUNCTION__ << "error:" << GetLastError();
            }
        }
    }
    else
    {
        qCritical() << __FUNCTION__ << "error1:";
    }

    SelectObject(hdcDest, hOld);
    DeleteDC(hdcDest);
    ReleaseDC((HWND)IntToPtr(handle), hdcSrc);
    image = QImage::fromHBITMAP(hBitmap);
    DeleteObject(hBitmap);

    return image;
}
