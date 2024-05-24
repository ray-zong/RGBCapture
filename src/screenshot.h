#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QObject>
#include <QImage>

class Screenshot : public QObject
{
    Q_OBJECT
public:
    explicit Screenshot(QObject *parent = nullptr);

    QImage captureRectangle(QRect rect);

    QImage captureFullScreen();

    QImage captureWindow(int wid);

    QImage captureActiveWindow();

    QImage captureActiveMonitor();

private:
    QImage captureRectangleNative(const QRect &rect, bool captureCursor = false);

    QImage captureRectangleNative(WId wid, const QRect &rect, bool captureCursor = false);

    QImage cpatureRectangleManaged(const QRect &rect);

signals:

private:
    bool m_bCaptureCursor;
    bool m_bCaptureClientArea;
    bool m_bRemoveOutsideScreenArea;
    bool m_bCaptureShadow;
    int m_nShadowOffset;
    bool m_bAutoHideTaskbar;
};

#endif // SCREENSHOT_H
