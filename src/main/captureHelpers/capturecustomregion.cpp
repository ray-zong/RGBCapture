#include "capturecustomregion.h"

#include <QDebug>

#include "main/tasksettings.h"
#include "main/taskmetadata.h"
#include "main/taskhelpers.h"

TaskMetadata CaptureCustomRegion::execute(TaskSettings *pTaskSettings)
{
    qDebug() << __FUNCTION__;

    QRect rect = pTaskSettings->getCaptureSettings().CaptureCustomRegion;

    TaskMetadata metadata = createMetadata(rect);
    metadata.m_image = TaskHelpers::getScreenshot(pTaskSettings).captureRectangle(rect);

    return metadata;
}

