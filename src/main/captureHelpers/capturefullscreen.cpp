#include "capturefullscreen.h"

#include <QDebug>

#include "main/tasksettings.h"
#include "main/taskmetadata.h"
#include "helpers/helpers/capturehelpers.h"
#include "main/taskhelpers.h"

TaskMetadata CaptureFullScreen::execute(TaskSettings *pTaskSettings)
{
    qDebug() << __FUNCTION__;

    QRect rect = CaptureHelpers::getScreenWorkingArea();

    TaskMetadata metadata = createMetadata(rect);
    metadata.m_image = TaskHelpers::getScreenshot(pTaskSettings).captureFullscreen();

    return metadata;
}

