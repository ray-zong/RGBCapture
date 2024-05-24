#ifndef CAPTUREHELPERS_H
#define CAPTUREHELPERS_H

#include <QObject>
#include <QRect>

class CaptureHelpers : public QObject
{
    Q_OBJECT

    Q_DISABLE_COPY(CaptureHelpers)

public:
    explicit CaptureHelpers(QObject *parent = nullptr);

    static QRect getScreenBounds();
    static QRect getScreenWorkingArea();
    static QRect getActiveScreenBounds();
    static QRect getActiveScreenWorkingArea();
    static QPoint screenToClient(QPoint p);
    static QRect screenToClient(QRect rect);
    static QPoint GetCursorPosition();
    static QColor getPixelColor(int x, int y);
    static QPointF snapPositionToDegree(QPointF pos, QPointF pos2, float degree, float startDegree);
    static QPointF calculateNewPosition(QPointF posOnClick, QPointF posCurrent, QSize size);
    static QRectF calculateNewRectangle(QPointF posOnClick, QPointF posCurrent, QSize size);
    static QRect getWindowRectangle(int handle);
    static QRect getActiveWindowRectangle();
    static QRect getActiveWindowClientRectangle();
    static bool isActiveWindowFullscreen();
    static QRect evenRectangleSize(QRect rect);
signals:
};

#endif // CAPTUREHELPERS_H
