#include "capturecustomwindow.h"

#include <QDebug>
#include <QMessageBox>

#include "main/tasksettings.h"
#include "main/taskmetadata.h"
#include "helpers/native/nativemethods_helpers.h"

TaskMetadata CaptureCustomWindow::execute(TaskSettings *pTaskSettings)
{
    qDebug() << __FUNCTION__;
    QString strWindowTitle = pTaskSettings->getCaptureSettings().CaptureCustomWindow;
    TaskMetadata metadata;

    if (!strWindowTitle.isEmpty())
    {
        int hWnd = NativeMethods_Helpers::searchWindow(strWindowTitle);

        if (hWnd == 0)
        {
            QMessageBox msgBox(QMessageBox::NoIcon, "RGBCapture", tr("Unable to find a window with specified window title"));
            msgBox.exec();
        }
        else
        {
            //m_nWindowHandle = hWnd;
            return CaptureBase::execute(pTaskSettings);
        }
    }

    return metadata;
}

