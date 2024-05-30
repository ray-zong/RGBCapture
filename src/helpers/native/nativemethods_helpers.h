#ifndef NATIVEMETHODS_HELPERS_H
#define NATIVEMETHODS_HELPERS_H

#include <QObject>
#include <QRect>

class NativeMethods_Helpers : public QObject
{
    Q_OBJECT
public:
    explicit NativeMethods_Helpers(QObject *parent = nullptr);

    static QString getForegroundWindowText();
    static QString getWindowText(int handle);
    static int getForegroundWindowProcess();
    static QString getForegroundWindowProcessName();
    static unsigned long getProcessByWindowHandle(int handle);
    static QString getClassName(int handle);
    static unsigned long getClassLongPtrSafe(int handle, int index);
    static unsigned long getWindowLong(int hWnd, int index);
    static int setWindowLong(int hWnd, int index, long newLong);
    static QImage getSmallApplicationIcon(int handle);
    static QImage getBigApplicationIcon(int handle);
    static QImage getApplicationIcon(int handle);
    static bool getBorderSize(int handle, QSize &size);
    static bool isDWMEnabled();
    static bool getExtendedFrameBounds(int handle, QRect &rect);
    static bool getNCRenderingEnabled(int handle);
    static void setNCRenderingPolicy(int handle, int type);
    static bool useImmersiveDarkMode(int handle, bool enabled);
    static void setWindowCornerPreference(int handle, int type);
    static QRect getWindowRect(int handle);
    static QRect getClientRect(int handle);
    static QRect maximizedWindowFix(int handle, QRect windowRect);
    static QRect getTaskbarRectangle();
    static bool setTaskbarVisibilityIfIntersect(bool visible, QRect rect);
    static bool setTaskbarVisibility(bool visible);
    static bool isWindowCloaked(int handle);
    static bool isActive(int handle);
    static void restoreWindow(int handle);
    static bool flashWindowEx(int handle, uint flashCount = UINT32_MAX);
    static void openFolderAndSelectFile(QString filePath);
    static bool createProcess(QString path, QString arguments, unsigned int flags);
    static QImage getFileIcon(QString filePath, bool isSmallIcon);
    static QImage getJumboFileIcon(QString filePath, bool jumboSize = true);
    static float getScreenScalingFactor();
    static int searchWindow(QString title);

signals:

};

#endif // NATIVEMETHODS_HELPERS_H
