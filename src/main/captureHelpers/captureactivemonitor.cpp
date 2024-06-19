#include "captureactivemonitor.h"

#include <QDebug>

#include "main/tasksettings.h"
#include "main/taskmetadata.h"
#include "helpers/helpers/capturehelpers.h"
#include "main/taskhelpers.h"



TaskMetadata CaptureActiveMonitor::execute(TaskSettings *pTaskSettings)
{
    qDebug() << __FUNCTION__;

    QRect rect = CaptureHelpers::getActiveScreenWorkingArea();

    TaskMetadata metadata = createMetadata(rect);
    metadata.m_image = TaskHelpers::getScreenshot(pTaskSettings).captureActiveMonitor();
    return metadata;
}

