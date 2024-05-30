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
#include "mathhelpers.h"

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
    //todo return Screen.AllScreens.Select(x => x.WorkingArea).Combine();
    return getScreenBounds();
}

QRect CaptureHelpers::getActiveScreenBounds()
{
    QPoint topLeft;
    QPoint bottomRight;

    QList<QScreen *> screens = QApplication::screens();

    foreach (QScreen *screen, screens)
    {
        if(screen->geometry().x() < topLeft.x())
            topLeft.setX(screen->geometry().x());

        if(screen->geometry().y() < topLeft.y())
            topLeft.setY(screen->geometry().y());

        if((screen->geometry().x() + screen->geometry().width()) > bottomRight.x())
            bottomRight.setX(screen->geometry().x() + screen->geometry().width());

        if ((screen->geometry().y() + screen->geometry().height()) > bottomRight.y())
            bottomRight.setY(screen->geometry().y() + screen->geometry().height());
    }

    return QRect(topLeft.x(), topLeft.y(), bottomRight.x() + qAbs(topLeft.x()), bottomRight.y() + qAbs(topLeft.y()));
}

QRect CaptureHelpers::getActiveScreenWorkingArea()
{
    QPoint topLeft;
    QPoint bottomRight;

    QList<QScreen *> screens = QApplication::screens();

    foreach (QScreen *screen, screens)
    {
        topLeft.setX(qMin(topLeft.x(), screen->geometry().x()));
        topLeft.setY(qMin(topLeft.y(), screen->geometry().y()));
        bottomRight.setX(qMax(bottomRight.x(), screen->geometry().right()));
        bottomRight.setY(qMax(bottomRight.y(), screen->geometry().bottom()));
    }

    return QRect(topLeft.x(), topLeft.y(), bottomRight.x() + qAbs(topLeft.x()), bottomRight.y() + qAbs(topLeft.y()));
}

QPoint CaptureHelpers::screenToClient(QPoint p)
{
    int screenX = GetSystemMetrics(SM_XVIRTUALSCREEN);
    int screenY = GetSystemMetrics(SM_YVIRTUALSCREEN);
    return QPoint(p.x() - screenX, p.y() - screenY);
}

QRect CaptureHelpers::screenToClient(QRect rect)
{
    return QRect(screenToClient(rect.topLeft()), rect.size());
}

QPoint CaptureHelpers::getCursorPosition()
{
    POINT point;
    if (GetCursorPos(&point))
    {
        return QPoint(point.x, point.y);
    }

    return QPoint();
}

QColor CaptureHelpers::getPixelColor()
{
    QPoint point = getCursorPosition();
    return getPixelColor(point.x(), point.y());
}

QColor CaptureHelpers::getPixelColor(int x, int y)
{
    HDC hdc = GetDC(NULL);
    uint pixel = GetPixel(hdc, x, y);
    ReleaseDC(NULL, hdc);

    return QColor((int)(pixel & 0x000000FF), (int)(pixel & 0x0000FF00) >> 8, (int)(pixel & 0x00FF0000) >> 16);
}

QRect CaptureHelpers::createRectangle(int x, int y, int x2, int y2)
{
    int width, height;

    if (x <= x2)
    {
        width = x2 - x + 1;
    }
    else
    {
        width = x - x2 + 1;
        x = x2;
    }

    if (y <= y2)
    {
        height = y2 - y + 1;
    }
    else
    {
        height = y - y2 + 1;
        y = y2;
    }

    return QRect(x, y, width, height);
}

QRectF CaptureHelpers::createRectangle(float x, float y, float x2, float y2)
{
    float width, height;

    if (x <= x2)
    {
        width = x2 - x + 1;
    }
    else
    {
        width = x - x2 + 1;
        x = x2;
    }

    if (y <= y2)
    {
        height = y2 - y + 1;
    }
    else
    {
        height = y - y2 + 1;
        y = y2;
    }

    return QRectF(x, y, width, height);
}

QPointF CaptureHelpers::snapPositionToDegree(QPointF pos, QPointF pos2, float degree, float startDegree)
{
    float angle = MathHelpers::lookAtRadian(pos, pos2);
    float startAngle = MathHelpers::degreeToRadian(startDegree);
    float snapAngle = MathHelpers::degreeToRadian(degree);
    float newAngle = ((float)qRound((angle + startAngle) / snapAngle) * snapAngle) - startAngle;
    float distance = MathHelpers::distance(pos, pos2);
    pos += MathHelpers::radianToVector2(newAngle, distance);

    return pos;
}

QPointF CaptureHelpers::calculateNewPosition(QPointF posOnClick, QPointF posCurrent, QSize size)
{
    if (posCurrent.x() > posOnClick.x())
    {
        if (posCurrent.y() > posOnClick.y())
        {
            return QPointF(posOnClick.x() + size.width() - 1, posOnClick.y() + size.height() - 1);
        }
        else
        {
            return QPointF(posOnClick.x() + size.width() - 1, posOnClick.y() - size.height() + 1);
        }
    }
    else
    {
        if (posCurrent.y() > posOnClick.y())
        {
            return QPointF(posOnClick.x() - size.width() + 1, posOnClick.y() + size.height() - 1);
        }
        else
        {
            return QPointF(posOnClick.x() - size.width() + 1, posOnClick.y() - size.height() + 1);
        }
    }

    return QPointF();
}

QRectF CaptureHelpers::calculateNewRectangle(QPointF posOnClick, QPointF posCurrent, QSize size)
{
    QPointF point = calculateNewPosition(posOnClick, posCurrent, size);

    return createRectangle((float)posOnClick.x(), posOnClick.y(), point.x(), point.y());
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
    HWND hwnd = GetForegroundWindow();
    return getWindowRectangle(PtrToInt(hwnd));
}

QRect CaptureHelpers::getActiveWindowClientRectangle()
{
    QRect result;
    HWND hwnd = GetForegroundWindow();
    RECT rect;
    if(GetClientRect(hwnd, &rect))
    {
        result.setRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
    }
    else
    {
        qCritical() << __FUNCTION__ << "error:" << GetLastError();
    }

    return result;
}

bool CaptureHelpers::isActiveWindowFullscreen()
{
    HWND hwnd = GetForegroundWindow();

    if (hwnd != NULL)
    {
        tagWINDOWINFO windowInfo;
        windowInfo.cbSize = sizeof(tagWINDOWINFO);

        if(GetWindowInfo(hwnd, &windowInfo))
        {
            QString className = NativeMethods_Helpers::getWindowText(PtrToInt(hwnd));

            if (className.isEmpty() || className.contains("Progman") || className.contains("WorkerW"))
            {
                return false;
            }
            else
            {
                QRect windowRectangle(windowInfo.rcWindow.left, windowInfo.rcWindow.top, windowInfo.rcWindow.right - windowInfo.rcWindow.left, windowInfo.rcWindow.bottom - windowInfo.rcWindow.top);

                QList<QScreen *> screens = QApplication::screens();

                foreach (QScreen *screen, screens) {
                    if(screen->geometry() == windowRectangle)
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            qCritical() << __FUNCTION__ << "error:" << GetLastError();
        }
    }

    return false;
}

QRect CaptureHelpers::evenRectangleSize(QRect rect)
{
    rect.setWidth(rect.width() - rect.width() & 1);
    rect.setHeight(rect.height() - rect.height() & 1);
    return rect;
}

