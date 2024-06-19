#ifndef WINDOWINFO_H
#define WINDOWINFO_H

#include <QString>
#include <QRect>

namespace Helpers
{
class WindowInfo
{
public:
    WindowInfo(int handle);
    void setHandle(int handle);

    int m_nHandle;
    bool m_bIsHandleCreated;
    QString m_strText;
    QString m_strClassName;
    unsigned long m_nProcessId;
    QString m_strProcessName;
    QString m_strProcessFilePath;
    QString m_strProcessFileName;
    int m_nParent;
    QRect m_windowRect;
    QRect m_clientRect;

    //public WindowStyles Style
    //{
    //    get
    //    {
    //        return (WindowStyles)(ulong)NativeMethods.GetWindowLong(Handle, NativeConstants.GWL_STYLE);
    //    }
    //    set
    //    {
    //        NativeMethods.SetWindowLong(Handle, NativeConstants.GWL_STYLE, (IntPtr)value);
    //    }
    //}

    //public WindowStyles ExStyle
    //{
    //    get
    //    {
    //        return (WindowStyles)(ulong)NativeMethods.GetWindowLong(Handle, NativeConstants.GWL_EXSTYLE);
    //    }
    //    set
    //    {
    //        NativeMethods.SetWindowLong(Handle, NativeConstants.GWL_EXSTYLE, (IntPtr)value);
    //    }
    //}

    //public bool Layered
    //{
    //    get
    //    {
    //        return ExStyle.HasFlag(WindowStyles.WS_EX_LAYERED);
    //    }
    //    set
    //    {
    //        if (value)
    //        {
    //            ExStyle |= WindowStyles.WS_EX_LAYERED;
    //        }
    //        else
    //        {
    //            ExStyle &= ~WindowStyles.WS_EX_LAYERED;
    //        }
    //    }
    //}

    //public bool TopMost
    //{
    //    get
    //    {
    //        return ExStyle.HasFlag(WindowStyles.WS_EX_TOPMOST);
    //    }
    //    set
    //    {
    //        SetWindowPos(value ? (IntPtr)NativeConstants.HWND_TOPMOST : (IntPtr)NativeConstants.HWND_NOTOPMOST,
    //            SetWindowPosFlags.SWP_NOMOVE | SetWindowPosFlags.SWP_NOSIZE);
    //    }
    //}

    //public byte Opacity
    //{
    //    get
    //    {
    //        if (Layered)
    //        {
    //            NativeMethods.GetLayeredWindowAttributes(Handle, out _, out byte alpha, out _);
    //            return alpha;
    //        }

    //        return 255;
    //    }
    //    set
    //    {
    //        if (value < 255)
    //        {
    //            Layered = true;
    //            NativeMethods.SetLayeredWindowAttributes(Handle, 0, value, NativeConstants.LWA_ALPHA);
    //        }
    //        else
    //        {
    //            Layered = false;
    //        }
    //    }
    //}

    //public Icon Icon => NativeMethods.GetApplicationIcon(Handle);

    //public bool IsMaximized => NativeMethods.IsZoomed(Handle);

    //public bool IsMinimized => NativeMethods.IsIconic(Handle);

    //public bool IsVisible => NativeMethods.IsWindowVisible(Handle) && !IsCloaked;

    //public bool IsCloaked => NativeMethods.IsWindowCloaked(Handle);

    //public bool IsActive => NativeMethods.IsActive(Handle);

    //public WindowInfo(IntPtr handle)
    //{
    //    Handle = handle;
    //}

    //public void Activate()
    //{
    //    if (IsHandleCreated)
    //    {
    //        NativeMethods.SetForegroundWindow(Handle);
    //    }
    //}

    //public void BringToFront()
    //{
    //    if (IsHandleCreated)
    //    {
    //        SetWindowPos(SetWindowPosFlags.SWP_NOMOVE | SetWindowPosFlags.SWP_NOSIZE);
    //    }
    //}

    //public void Restore()
    //{
    //    if (IsHandleCreated)
    //    {
    //        NativeMethods.ShowWindow(Handle, (int)WindowShowStyle.Restore);
    //    }
    //}

    //public void SetWindowPos(SetWindowPosFlags flags)
    //{
    //    SetWindowPos((IntPtr)NativeConstants.HWND_TOP, 0, 0, 0, 0, flags);
    //}

    //public void SetWindowPos(Rectangle rect, SetWindowPosFlags flags)
    //{
    //    SetWindowPos((IntPtr)NativeConstants.HWND_TOP, rect.X, rect.Y, rect.Width, rect.Height, flags);
    //}

    //public void SetWindowPos(IntPtr insertAfter, SetWindowPosFlags flags)
    //{
    //    SetWindowPos(insertAfter, 0, 0, 0, 0, flags);
    //}

    //public void SetWindowPos(IntPtr insertAfter, int x, int y, int width, int height, SetWindowPosFlags flags)
    //{
    //    NativeMethods.SetWindowPos(Handle, insertAfter, x, y, width, height, flags);
    //}

    //public override string ToString()
    //{
    //    return Text;
    //}
};
}

#endif //WINDOWINFO_H
