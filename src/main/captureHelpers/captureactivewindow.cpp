#include "captureactivewindow.h"

#include <QDebug>

#include "main/tasksettings.h"
#include "main/taskmetadata.h"
#include "helpers/helpers/capturehelpers.h"
#include "main/taskhelpers.h"

TaskMetadata CaptureActiveWindow::execute(TaskSettings *pTaskSettings)
{
    qDebug() << __FUNCTION__;

    TaskMetadata metadata = createMetadata();

    if(pTaskSettings != nullptr
        && pTaskSettings->getCaptureSettings().CaptureTransparent
        && !pTaskSettings->getCaptureSettings().CaptureClientArea)
    {
        metadata.m_image = TaskHelpers::getScreenshot(pTaskSettings).captureActiveWindowTransparent();
    }
    else
    {
        metadata.m_image = TaskHelpers::getScreenshot(pTaskSettings).captureActiveWindow();
    }


    return metadata;
}

