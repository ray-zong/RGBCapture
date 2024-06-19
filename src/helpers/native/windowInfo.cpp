#include "windowInfo.h"


#include <QDebug>

#ifdef Q_OS_WIN
#include <Windows.h>
//#include <windef.h>
//#include <dwmapi.h>
//#include <ShlObj_core.h>
//#include <commoncontrols.h>
#pragma comment(lib, "User32.lib")
//#pragma comment(lib, "Dwmapi.lib")
//#pragma comment(lib, "Shell32.lib")
//#pragma comment(lib, "Gdi32.lib")
//#pragma comment(lib, "Ole32.lib")
//#pragma comment(lib, "Comctl32.lib")

#else

#endif

namespace Helpers
{
WindowInfo::WindowInfo(int handle)
{
    setHandle(handle);
}

void WindowInfo::setHandle(int handle)
{
    m_nHandle = handle;
    m_bIsHandleCreated = (m_nHandle != 0);

    TCHAR processFullName[_MAX_PATH] = {0};
    if(GetWindowText((HWND)IntToPtr(handle), processFullName, _MAX_PATH))
    {
        m_strText = QString::fromStdWString(processFullName);
    }


    if(GetClassName((HWND)IntToPtr(handle), processFullName, _MAX_PATH))
    {
        m_strClassName = QString::fromStdWString(processFullName);

    }

    if(GetWindowThreadProcessId((HWND)IntToPtr(handle), &m_nProcessId) != 0)
    {
        if(GetModuleFileName(NULL, processFullName, _MAX_PATH) != 0)
        {
            m_strProcessName = QString::fromStdWString(processFullName);
        }
        else
        {
            qCritical() << __FUNCTION__ << "error:" << "GetModuleFileName" << GetLastError();
        }
    }

    m_nParent = PtrToInt(GetParent((HWND)IntToPtr(handle)));

    //CaptureHelpers.GetWindowRectangle(Handle);

    //NativeMethods.GetClientRect(Handle);
}
}
