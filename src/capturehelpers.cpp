#include "capturehelpers.h"

#include <QScreen>
#include <QApplication>

#ifdef Q_OS_WIN
#include <Windows.h>
#pragma comment(lib, "User32.lib")
#else

#endif

#include "nativemethods_helpers.h"
#include "helpers.h"

CaptureHelpers::CaptureHelpers(QObject *parent)
    : QObject{parent}
{

}

QRect CaptureHelpers::getScreenBounds()
{
    QRect rect;
    QList<QScreen *> screens = QApplication::screens();

    foreach (QScreen *screen, screens) {
        rect = rect.united(screen->geometry());
    }

    qDebug() << __FUNCTION__ << rect;

    return rect;
}

QRect CaptureHelpers::getScreenWorkingArea()
{
    return QRect();
}

QRect CaptureHelpers::getActiveScreenBounds()
{
    return QRect();
}

QRect CaptureHelpers::getActiveScreenWorkingArea()
{
    return QRect();
}

QPoint CaptureHelpers::screenToClient(QPoint p)
{
    return p;
}

QRect CaptureHelpers::screenToClient(QRect rect)
{
    return rect;
}

QPoint CaptureHelpers::GetCursorPosition()
{
    return QPoint();
}

QColor CaptureHelpers::getPixelColor(int x, int y)
{
    return QColor();
}

QPointF CaptureHelpers::snapPositionToDegree(QPointF pos, QPointF pos2, float degree, float startDegree)
{
    return QPointF();
}

QPointF CaptureHelpers::calculateNewPosition(QPointF posOnClick, QPointF posCurrent, QSize size)
{
    return QPointF();
}

QRectF CaptureHelpers::calculateNewRectangle(QPointF posOnClick, QPointF posCurrent, QSize size)
{
    return QRectF();
}

QRect CaptureHelpers::getWindowRectangle(int handle)
{
    QRect rect;
    QRect tempRect;
    if (NativeMethods_Helpers::isDWMEnabled() && NativeMethods_Helpers::getExtendedFrameBounds(handle, tempRect))
    {
        rect = tempRect;
    }

    if (rect.isEmpty())
    {
        rect = NativeMethods_Helpers::getWindowRect(handle);
    }

    if (!Helpers::isWindows10OrGreater() && IsZoomed((HWND)IntToPtr(handle)))
    {
        rect = NativeMethods_Helpers::maximizedWindowFix(handle, rect);
    }

    return rect;
}

QRect CaptureHelpers::getActiveWindowRectangle()
{
    return QRect();
}

QRect CaptureHelpers::getActiveWindowClientRectangle()
{
    return QRect();
}

bool CaptureHelpers::isActiveWindowFullscreen()
{
    return false;
}

QRect CaptureHelpers::evenRectangleSize(QRect rect)
{
    return QRect();
}

