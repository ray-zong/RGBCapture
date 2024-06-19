#include "capturemonitor.h"

#include <QDebug>

#include "main/taskhelpers.h"


TaskMetadata CaptureMonitor::execute(TaskSettings *pTaskSettings)
{
    qDebug() << __FUNCTION__;

    TaskMetadata metadata = createMetadata(m_monitorRectangle);
    metadata.m_image = TaskHelpers::getScreenshot().captureRectangle(m_monitorRectangle);
    return metadata;
}

void CaptureMonitor::setMonitorRectangle(QRect rect)
{
    m_monitorRectangle = rect;
}

QRect CaptureMonitor::getMonitorRectangle()
{
    return m_monitorRectangle;
}

void CaptureMonitor::captureMonitor(QRect rect)
{
    m_monitorRectangle = rect;
}

