#include "screenshot.h"

#include <QDebug>

#ifdef Q_OS_WIN
#include <Windows.h>
#include <winuser.h>
#include <wingdi.h>
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Gdi32.lib")
#else

#endif

#include "helpers/helpers/capturehelpers.h"
#include "helpers/helpers/helpers.h"
#include "helpers/native/nativemethods_helpers.h"

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

QImage Screenshot::captureFullscreen()
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

QImage Screenshot::captureWindowTransparent(int handle)
{
    QImage image;

    /*
    if (handle > 0)
    {
        QRect rect = CaptureHelpers::getWindowRectangle(handle);

        if (m_bCaptureShadow && !::IsZoomed((HWND)IntToPtr(handle)) && NativeMethods_Helpers::isDWMEnabled())
        {
            rect.setWidth(rect.width() + m_nShadowOffset * 2);
            rect.setHeight(rect.height() + m_nShadowOffset * 2);

            //todo
            //Rectangle intersectBounds = Screen.AllScreens.Select(x => x.Bounds).Where(x => x.IntersectsWith(rect)).Combine();
            //rect.Intersect(intersectBounds);
        }

        QImage whiteBackground;
        QImage blackBackground;
        QImage whiteBackground2;
        bool isTransparent = false, isTaskbarHide = false;

        try
        {
            if (m_bAutoHideTaskbar)
            {
                isTaskbarHide = NativeMethods_Helpers::setTaskbarVisibilityIfIntersect(false, rect);
            }

                form.BackColor = Color.White;
                form.FormBorderStyle = FormBorderStyle.None;
                form.ShowInTaskbar = false;
                form.StartPosition = FormStartPosition.Manual;
                form.Location = new Point(rect.X, rect.Y);
                form.Size = new Size(rect.Width, rect.Height);

                NativeMethods_Helpers::ShowWindow(form.Handle, (int)WindowShowStyle.ShowNoActivate);

                if (!NativeMethods.SetWindowPos(form.Handle, handle, 0, 0, 0, 0,
                                                SetWindowPosFlags.SWP_NOMOVE | SetWindowPosFlags.SWP_NOSIZE | SetWindowPosFlags.SWP_NOACTIVATE))
                {
                    form.Close();
                    DebugHelper.WriteLine("Transparent capture failed. Reason: SetWindowPos fail.");
                    return CaptureWindow(handle);
                }

                Application.DoEvents();
                Thread.Sleep(10);

                whiteBackground = CaptureRectangleNative(rect);

                form.BackColor = Color.Black;
                Application.DoEvents();
                Thread.Sleep(10);

                blackBackground = CaptureRectangleNative(rect);

                form.BackColor = Color.White;
                Application.DoEvents();
                Thread.Sleep(10);

                whiteBackground2 = CaptureRectangleNative(rect);

            Bitmap transparentImage;

            if (ImageHelpers.CompareImages(whiteBackground, whiteBackground2))
            {
                transparentImage = CreateTransparentImage(whiteBackground, blackBackground);
                isTransparent = true;
            }
            else
            {
                DebugHelper.WriteLine("Transparent capture failed. Reason: Images not equal.");
                transparentImage = whiteBackground2;
            }

            if (m_bCaptureCursor)
            {
                //    tagCURSORINFO cursorInfo;
                //    cursorInfo.cbSize = sizeof(tagCURSORINFO);
                //    GetCursorInfo(&cursorInfo);
                //    if(DrawIcon(hdcDest, cursorInfo.ptScreenPos.x, cursorInfo.ptScreenPos.y, cursorInfo.hCursor) == 0)
                //    {
                //        qCritical() << __FUNCTION__ << "error:" << GetLastError();
                //    }

                //cursorData.DrawCursor(transparentImage, rect.Location);
            }

            if (isTransparent)
            {
                transparentImage = ImageHelpers.AutoCropImage(transparentImage);

                if (!CaptureShadow)
                {
                    TrimShadow(transparentImage);
                }
            }

            return transparentImage;
        }
        finally
        {
            if (isTaskbarHide)
            {
                NativeMethods.SetTaskbarVisibility(true);
            }

            if (whiteBackground != null) whiteBackground.Dispose();
            if (blackBackground != null) blackBackground.Dispose();
            if (isTransparent && whiteBackground2 != null) whiteBackground2.Dispose();
        }
    }
*/
    return image;
}

QImage Screenshot::captureActiveWindowTransparent()
{
    QImage image;
    return image;
}

QImage Screenshot::createTransparentImage(QImage whiteBackground, QImage blackBackground)
{
    QImage image;
    return image;
}

void Screenshot::trimShadow(QImage image)
{
    int cornerSize = 10;
    int alphaOffset = Helpers::isWindows11OrGreater() ? 50 : 200;


    for (int i = 0; i < cornerSize; i++)
    {
        int y = i;
        int width = image.width();

        // Left top
        for (int x = 0; x < cornerSize; x++)
        {
            if (qAlpha(image.pixel(x, y)) < alphaOffset)
            {
                image.setPixel(x, y, 0);
            }
            else
            {
                break;
            }
        }

        // Right top
        for (int x = width - 1; x > width - cornerSize - 1; x--)
        {
            if (qAlpha(image.pixel(x, y)) < alphaOffset)
            {
                image.setPixel(x, y, 0);
            }
            else
            {
                break;
            }
        }

        y = image.height() - i - 1;

        // Left bottom
        for (int x = 0; x < cornerSize; x++)
        {
            if (qAlpha(image.pixel(x, y)) < alphaOffset)
            {
                image.setPixel(x, y, 0);
            }
            else
            {
                break;
            }
        }

        // Right bottom
        for (int x = width - 1; x > width - cornerSize - 1; x--)
        {
            if (qAlpha(image.pixel(x, y)) < alphaOffset)
            {
                image.setPixel(x, y, 0);
            }
            else
            {
                break;
            }
        }
    }
}

void Screenshot::setCaptureCursor(bool captureCurosr)
{
    m_bCaptureCursor = captureCurosr;
}

bool Screenshot::getCaptureCursor()
{
    return m_bCaptureCursor;
}

void Screenshot::setCaptureClientArea(bool captureClientArea)
{
    m_bCaptureClientArea = captureClientArea;
}

bool Screenshot::getCaptureClientArea()
{
    return m_bCaptureClientArea;
}

void Screenshot::setRemoveOutsideScreenArea(bool removeOutsideScreenArea)
{
    m_bRemoveOutsideScreenArea = removeOutsideScreenArea;
}

bool Screenshot::getRemoveOutsideScreenArea()
{
    return m_bRemoveOutsideScreenArea;
}

void Screenshot::setCaptureShadow(bool captureShadow)
{
    m_bCaptureShadow = captureShadow;
}

bool Screenshot::getCaptureShadow()
{
    return m_bCaptureShadow;
}

void Screenshot::setShadowOffset(int shadowOffset)
{
    m_nShadowOffset = shadowOffset;
}

int Screenshot::getShadowOffset()
{
    return m_nShadowOffset;
}

void Screenshot::setAutoHideTaskbar(bool autoHideTaskbar)
{
    m_bAutoHideTaskbar = autoHideTaskbar;
}

bool Screenshot::getAutoHideTaskbar()
{
    return m_bAutoHideTaskbar;
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
