#include "nativemethods_helpers.h"

#include <QSysInfo>
#include <QImage>
#include <QDebug>
#include <QFileInfo>
#include <QFileDialog>

#ifdef Q_OS_WIN
#include <Windows.h>
#include <windef.h>
#include <dwmapi.h>
#include <ShlObj_core.h>
#include <commoncontrols.h>
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Dwmapi.lib")
#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "Ole32.lib")
#pragma comment(lib, "Comctl32.lib")

#else

#endif

#include "helpers/helpers/helpers.h"

NativeMethods_Helpers::NativeMethods_Helpers(QObject *parent)
    : QObject{parent}
{

}

QString NativeMethods_Helpers::getForegroundWindowText()
{
    HWND handle = GetForegroundWindow();
    return getWindowText(PtrToInt(handle));
}

QString NativeMethods_Helpers::getWindowText(int handle)
{
    QString text;
    if(handle > 0)
    {
        TCHAR processFullName[_MAX_PATH] = {0};
        if(GetWindowText((HWND)IntToPtr(handle), processFullName, _MAX_PATH))
        {
            text = QString::fromStdWString(processFullName);
        }
    }
    return text;
}

int NativeMethods_Helpers::getForegroundWindowProcess()
{
    HWND handle = GetForegroundWindow();
    return getProcessByWindowHandle(PtrToInt(handle));
}

QString NativeMethods_Helpers::getForegroundWindowProcessName()
{
#ifdef Q_OS_WIN

    //https://blog.csdn.net/u014677109/article/details/127444425
    QString path;

    HWND handle = GetForegroundWindow();

    if(handle != NULL)
    {
        DWORD processId;
        if(GetWindowThreadProcessId(handle, &processId) != 0)
        {
            TCHAR processFullName[_MAX_PATH] = {0};
            if(GetModuleFileName(NULL, processFullName, _MAX_PATH) != 0)
            {
                path = QString::fromStdWString(processFullName);
            }
            else
            {
                qCritical() << __FUNCTION__ << "error:" << "GetModuleFileName" << GetLastError();
            }
        }
        else
        {
            qCritical() << __FUNCTION__ << "error1:" << GetLastError();
        }
    }
    else
    {
        qCritical() << __FUNCTION__ << "error2:" << GetLastError();
    }
#elif Q_OS_UNIX
#else
    //https://blog.csdn.net/u014677109/article/details/127444425

    void getNameByPid(pid_t pid, char *task_name) {
        char proc_pid_path[BUF_SIZE];
        char buf[BUF_SIZE];

        sprintf(proc_pid_path, "/proc/%d/status", pid);
        FILE* fp = fopen(proc_pid_path, "r");
        if(NULL != fp){
            if( fgets(buf, BUF_SIZE-1, fp)== NULL ){
                fclose(fp);
            }
            fclose(fp);
            sscanf(buf, "%*s %s", task_name);
        }
#endif

    if(!path.isEmpty())
    {
        QFileInfo fileInfo(path);
        if(fileInfo.isExecutable())
        {
            return fileInfo.completeBaseName();
        }
        else
        {
            qCritical() << __FUNCTION__ << "error3:" << path;
        }
    }
    return "";
}

unsigned long NativeMethods_Helpers::getProcessByWindowHandle(int handle)
{
    DWORD processId = 0;
    if(GetWindowThreadProcessId((HWND)IntToPtr(handle), &processId) == 0)
    {
        qCritical() << __FUNCTION__ << "error:" << GetLastError();
    }
    return processId;
}

QString NativeMethods_Helpers::getClassName(int handle)
{
    if(handle > 0)
    {
        TCHAR path[_MAX_PATH] = {0};
        if(GetClassName((HWND)IntToPtr(handle), path, _MAX_PATH) == 0)
        {
            qCritical() << __FUNCTION__ << "error:" << GetLastError();
        }
        else
        {
            return QString::fromStdWString(path);
        }
    }
    return "";
}

unsigned long NativeMethods_Helpers::getClassLongPtrSafe(int handle, int index)
{
    return GetClassLong((HWND)IntToPtr(handle), index);
}

unsigned long NativeMethods_Helpers::getWindowLong(int hWnd, int index)
{
    return GetWindowLong((HWND)IntToPtr(hWnd), index);
}

int NativeMethods_Helpers::setWindowLong(int hWnd, int index, long newLong)
{
    return SetWindowLongPtr((HWND)IntToPtr(hWnd), index, newLong);
}

QImage NativeMethods_Helpers::getSmallApplicationIcon(int handle)
{
    QImage image;
    DWORD_PTR iconHandle;
    if(SendMessageTimeout((HWND)IntToPtr(handle), WM_GETICON, 0x2, 0, SMTO_ABORTIFHUNG, 1000, &iconHandle) == 0)
    {
        if(SendMessageTimeout((HWND)IntToPtr(handle), WM_GETICON, 0, 0, SMTO_ABORTIFHUNG, 1000, &iconHandle) == 0)
        {
            if(getClassLongPtrSafe(handle, -34) == 0) //GCL_HICONSM
            {
                if(SendMessageTimeout((HWND)IntToPtr(handle), WM_QUERYDRAGICON, 0, 0, SMTO_ABORTIFHUNG, 1000, &iconHandle) == 0)
                {
                    qCritical() << __FUNCTION__ << "error:" << GetLastError();
                }
            }
        }
    }

    if(iconHandle != 0)
    {
        image.fromHICON((HICON)ULongToPtr(iconHandle));
    }

    return image;
}

QImage NativeMethods_Helpers::getBigApplicationIcon(int handle)
{
    QImage image;
    DWORD_PTR iconHandle;
    if(SendMessageTimeout((HWND)IntToPtr(handle), WM_GETICON, 0x1, 0, SMTO_ABORTIFHUNG, 1000, &iconHandle) == 0)
    {
        iconHandle = getClassLongPtrSafe(handle, -14);//GCL_HICON
    }

    if(iconHandle != 0)
    {
        image.fromHICON((HICON)ULongToPtr(iconHandle));
    }

    return image;
}

QImage NativeMethods_Helpers::getApplicationIcon(int handle)
{
    QImage image;
    image = getSmallApplicationIcon(handle);

    if(image.isNull())
    {
        image = getBigApplicationIcon(handle);
    }

    return image;
}

bool NativeMethods_Helpers::getBorderSize(int handle, QSize &size)
{
    WINDOWINFO wi;
    if(GetWindowInfo((HWND)IntToPtr(handle), &wi))
    {
        size.setWidth(wi.cxWindowBorders);
        size.setHeight(wi.cyWindowBorders);
        return true;
    }
    else
    {
        qCritical() << __FUNCTION__ << "error:" << GetLastError();
        return false;
    }
}

bool NativeMethods_Helpers::isDWMEnabled()
{
    if(!Helpers::isWindowsVistaOrGreater())
    {
        return false;
    }

    BOOL bEnabled = TRUE;
    return (DwmIsCompositionEnabled(&bEnabled) == S_OK);
}

bool NativeMethods_Helpers::getExtendedFrameBounds(int handle, QRect &rect)
{
    RECT temRect;
    HRESULT result = DwmGetWindowAttribute((HWND)IntToPtr(handle), DWMWA_EXTENDED_FRAME_BOUNDS, &temRect, sizeof(RECT));

    if(result == S_OK)
    {
        rect.setRect(temRect.left, temRect.top, temRect.right - temRect.left, temRect.bottom - temRect.top);
        return true;
    }
    else
    {
        qCritical() << __FUNCTION__ << "error:" << result;
        return false;
    }
}

bool NativeMethods_Helpers::getNCRenderingEnabled(int handle)
{
    BOOL enabled;
    HRESULT result = DwmGetWindowAttribute((HWND)IntToPtr(handle), DWMWA_EXTENDED_FRAME_BOUNDS, &enabled, sizeof(BOOL));

    return result == S_OK && enabled;
}

void NativeMethods_Helpers::setNCRenderingPolicy(int handle, int type)
{
    HRESULT result = DwmSetWindowAttribute((HWND)IntToPtr(handle), DWMWA_NCRENDERING_POLICY, &type, sizeof(int));
    if(result != S_OK)
    {
        qCritical() << __FUNCTION__ << "error:" << result;
    }
}

bool NativeMethods_Helpers::useImmersiveDarkMode(int handle, bool enabled)
{
    if (Helpers::isWindows10OrGreater(18985))
    {
        int useImmersiveDarkMode = enabled ? 1 : 0;
        return DwmSetWindowAttribute((HWND)IntToPtr(handle), DWMWA_USE_IMMERSIVE_DARK_MODE, &useImmersiveDarkMode, sizeof(int)) == 0;
    }

    return false;
}

void NativeMethods_Helpers::setWindowCornerPreference(int handle, int type)
{
    HRESULT result = DwmSetWindowAttribute((HWND)IntToPtr(handle), DWMWA_WINDOW_CORNER_PREFERENCE, &type, sizeof(int));
    if(result != S_OK)
    {
        qCritical() << __FUNCTION__ << "error:" << result;
    }
}

QRect NativeMethods_Helpers::getWindowRect(int handle)
{
    RECT rect;
    if(GetWindowRect((HWND)IntToPtr(handle), &rect))
    {
        return QRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
    }
    else
    {
        qCritical() << __FUNCTION__ << "error:" << GetLastError();
        return QRect();
    }
}

QRect NativeMethods_Helpers::getClientRect(int handle)
{
#ifdef Q_OS_WIN
    RECT rect;
    if(GetClientRect((HWND)IntToPtr(handle), &rect))
    {
        tagPOINT pos;
        pos.x = rect.left;
        pos.y = rect.top;
        if(ClientToScreen((HWND)IntToPtr(handle), &pos))
        {
            return QRect(pos.x, pos.y, rect.right - rect.left, rect.bottom - rect.top);
        }
        else
        {
            qCritical() << __FUNCTION__ << "error:" << GetLastError();
            return QRect();
        }
    }
    else
    {
        qCritical() << __FUNCTION__ << "error1:" << GetLastError();
        return QRect();
    }
#else
#endif
}

QRect NativeMethods_Helpers::maximizedWindowFix(int handle, QRect windowRect)
{
    QSize size;
    if (getBorderSize(handle, size))
    {
        windowRect.setRect(windowRect.x() + size.width(),
                           windowRect.y() + size.height(),
                           windowRect.width() - (size.width() * 2),
                           windowRect.height() - (size.height() * 2));
    }

    return windowRect;
}

QRect NativeMethods_Helpers::getTaskbarRectangle()
{
    APPBARDATA appBarData;
    if(SHAppBarMessage(ABM_GETTASKBARPOS, &appBarData))
    {
        return QRect(appBarData.rc.left, appBarData.rc.top, appBarData.rc.right - appBarData.rc.left, appBarData.rc.bottom - appBarData.rc.top);
    }
    else
    {
        return QRect();
    }
}

bool NativeMethods_Helpers::setTaskbarVisibilityIfIntersect(bool visible, QRect rect)
{
    bool result = false;

#ifdef Q_OS_WIN
    HWND taskbarHandle = FindWindow(L"Shell_TrayWnd", NULL);

    if (taskbarHandle != NULL)
    {
        RECT taskbarRect;
        if(GetWindowRect(taskbarHandle, &taskbarRect))
        {
            QRect qTaskbarRect(taskbarRect.left, taskbarRect.top,
                               taskbarRect.right - taskbarRect.left,
                               taskbarRect.bottom - taskbarRect.top);

            if (rect.intersects(qTaskbarRect))
            {
                ShowWindow(taskbarHandle, visible ? SW_SHOW : SW_HIDE);
                result = true;
            }

            if (Helpers::isWindowsVista() || Helpers::isWindows7())
            {
                HWND startHandle = FindWindowEx(0, 0, MAKEINTATOM(0xC017), NULL);

                if (startHandle != NULL)
                {
                    QRect startRect = getWindowRect(PtrToInt(startHandle));

                    if (rect.intersects(startRect))
                    {
                        ShowWindow(startHandle, visible ? SW_SHOW : SW_HIDE);
                        result = true;
                    }
                }
            }
        }
    }
#else

#endif
    return result;
}

bool NativeMethods_Helpers::setTaskbarVisibility(bool visible)
{
#ifdef Q_OS_WIN
    HWND taskbarHandle = FindWindow(L"Shell_TrayWnd", NULL);

    if (taskbarHandle != NULL)
    {

        ShowWindow(taskbarHandle, visible ? SW_SHOW : SW_HIDE);

        if (Helpers::isWindowsVista() || Helpers::isWindows7())
        {
            HWND startHandle = FindWindowEx(0, 0, MAKEINTATOM(0xC017), NULL);

            if (startHandle != NULL)
            {
                ShowWindow(startHandle, visible ? SW_SHOW : SW_HIDE);
            }
        }

        return true;
    }
#else

#endif

    return false;
}

bool NativeMethods_Helpers::isWindowCloaked(int handle)
{
    if(isDWMEnabled())
    {
        int cloaked;
        HRESULT result = DwmGetWindowAttribute((HWND)IntToPtr(handle), DWMWA_EXTENDED_FRAME_BOUNDS, &cloaked, sizeof(int));
        return result == S_OK && cloaked != 0;
    }
    return false;
}

bool NativeMethods_Helpers::isActive(int handle)
{
    return GetForegroundWindow() == (HWND)IntToPtr(handle);
}

void NativeMethods_Helpers::restoreWindow(int handle)
{
    WINDOWPLACEMENT wp;
    wp.length = sizeof(wp);

    if (GetWindowPlacement((HWND)IntToPtr(handle), &wp))
    {
        if (wp.flags == WPF_RESTORETOMAXIMIZED)
        {
            wp.showCmd = SW_SHOWMAXIMIZED;
        }
        else
        {
            wp.showCmd = SW_RESTORE;
        }

        SetWindowPlacement((HWND)IntToPtr(handle), &wp);
    }
}

bool NativeMethods_Helpers::flashWindowEx(int handle, uint flashCount)
{
    FLASHWINFO fInfo;
    fInfo.cbSize = sizeof(fInfo);
    fInfo.hwnd = (HWND)IntToPtr(handle);
    fInfo.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG;
    fInfo.uCount = flashCount;
    fInfo.dwTimeout = 0;

    return FlashWindowEx(&fInfo);
}

void NativeMethods_Helpers::openFolderAndSelectFile(QString filePath)
{
    QFileDialog fileDialog;
    fileDialog.selectFile(filePath);
    fileDialog.exec();
}

bool NativeMethods_Helpers::createProcess(QString path, QString arguments, unsigned int flags)
{
    //STARTUPINFO sInfo;
    //SECURITY_ATTRIBUTES pSec;
    //SECURITY_ATTRIBUTES tSec;
    //pSec.nLength = sizeof(pSec);
    //tSec.nLength = sizeof(tSec);

    //PROCESS_INFORMATION processInfo;

    return false;
    //return CreateProcess(path.toStdWString().c_str(), arguments.toStdWString(), &pSec, &tSec, false, flags, 0, NULL, &sInfo, &processInfo);
}

QImage NativeMethods_Helpers::getFileIcon(QString filePath, bool isSmallIcon)
{
    SHFILEINFO shfi;

    unsigned int flags = SHGFI_ICON;

    if (isSmallIcon)
    {
        flags |= SHGFI_SMALLICON;
    }
    else
    {
        flags |= SHGFI_LARGEICON;
    }

    SHGetFileInfo(filePath.toStdWString().c_str(), 0, &shfi, sizeof(shfi), flags);

    QImage image = QImage::fromHICON(shfi.hIcon);

    DestroyIcon(shfi.hIcon);

    return image;
}

QImage NativeMethods_Helpers::getJumboFileIcon(QString filePath, bool jumboSize)
{
    //https://blog.csdn.net/cair2/article/details/104044008

    static bool bInit = false;
    static IImageList *imageList = NULL;

    if (!bInit && imageList == NULL)
    {
        bInit = true;
        IID IID_IImageList = { 0 };
        HRESULT hr = IIDFromString(L"{46EB5926-582E-4017-9FDF-E8998DAA0950}", &IID_IImageList);
        Q_ASSERT(SUCCEEDED(hr));
        SHGetImageList(jumboSize ? SHIL_JUMBO : SHIL_EXTRALARGE, IID_IImageList, (void **)(&imageList));
    }

    SHFILEINFO info = { 0 };

    if (SHGetFileInfo(filePath.toStdWString().c_str(), FILE_ATTRIBUTE_DIRECTORY, &info, sizeof(info), SHGFI_ICON | SHGFI_DISPLAYNAME))
    {
        HICON hIcon = info.hIcon;
        if (imageList)
        {
            hIcon = ImageList_GetIcon((HIMAGELIST)imageList, info.iIcon, 0);
            if (hIcon)
                DestroyIcon(info.hIcon);
            else
                hIcon = info.hIcon;
        }
        QImage image = QImage::fromHICON(hIcon);
        return image;
    }

    return QImage();
}

float NativeMethods_Helpers::getScreenScalingFactor()
{
    //https://zhuanlan.zhihu.com/p/528345722
    float scalingFactor;

    HWND hwd = ::GetDesktopWindow();
    HDC hdc = ::GetDC(hwd);
    int LogicalScreenHeight = ::GetDeviceCaps(hdc, VERTRES);
    int PhysicalScreenHeight = ::GetDeviceCaps(hdc, DESKTOPVERTRES);
    int logpixelsy = GetDeviceCaps(hdc, LOGPIXELSY);
    float screenScalingFactor = (float)PhysicalScreenHeight / LogicalScreenHeight;
    float dpiScalingFactor = logpixelsy / 96.0f;
    scalingFactor = qMax(screenScalingFactor, dpiScalingFactor);
    ::ReleaseDC(hwd, hdc);

    return scalingFactor;
}

int NativeMethods_Helpers::searchWindow(QString title)
{
    HWND hWnd = FindWindow(NULL, title.toStdWString().c_str());


    return PtrToInt(hWnd);
}
