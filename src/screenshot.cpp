#include "screenshot.h"

#include <QDebug>

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
    return QImage();
}

QImage Screenshot::captureActiveMonitor()
{
    return QImage();
}

QImage Screenshot::captureRectangleNative(const QRect &rect, bool captureCursor)
{
    return QImage();
}

QImage Screenshot::captureRectangleNative(WId wid, const QRect &rect, bool captureCursor)
{
    return QImage();
}

QImage Screenshot::cpatureRectangleManaged(const QRect &rect)
{
    return QImage();
}
