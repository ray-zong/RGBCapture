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

    QImage captureFullscreen();

    QImage captureWindow(int wid);

    QImage captureActiveWindow();

    QImage captureActiveMonitor();

    QImage captureWindowTransparent(int handle);

    QImage captureActiveWindowTransparent();

    QImage createTransparentImage(QImage whiteBackground, QImage blackBackground);

    void trimShadow(QImage image);

    void setCaptureCursor(bool captureCurosr);
    bool getCaptureCursor();

    void setCaptureClientArea(bool captureClientArea);
    bool getCaptureClientArea();

    void setRemoveOutsideScreenArea(bool removeOutsideScreenArea);
    bool getRemoveOutsideScreenArea();

    void setCaptureShadow(bool captureShadow);
    bool getCaptureShadow();

    void setShadowOffset(int shadowOffset);
    int getShadowOffset();

    void setAutoHideTaskbar(bool autoHideTaskbar);
    bool getAutoHideTaskbar();

private:
    QImage captureRectangleNative(const QRect &rect, bool captureCursor = false);

    QImage captureRectangleNative(int handle, const QRect &rect, bool captureCursor = false);

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
