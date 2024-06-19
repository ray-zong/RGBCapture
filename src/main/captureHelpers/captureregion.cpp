#include "captureregion.h"

#include <QDebug>

#include "screenCapture/enums.h"
#include "main/tasksettings.h"
#include "main/taskmetadata.h"
#include "main/taskhelpers.h"
#include "helpers/native/windowInfo.h"

RegionCaptureType CaptureRegion::lastRegionCaptureType = RegionDefault;

CaptureRegion::CaptureRegion()
{

}

CaptureRegion::CaptureRegion(RegionCaptureType type)
    : m_enRegionCaptureType(type)
{

}

TaskMetadata CaptureRegion::execute(TaskSettings *pTaskSettings)
{
    qDebug() << __FUNCTION__;

    switch(m_enRegionCaptureType)
    {
    case RegionDefault:
        return executeRegionCapture(pTaskSettings);
    case RegionLight:
        return executeRegionCaptureLight(pTaskSettings);
    case RegionTransparent:
        return executeRegionCaptureTransparent(pTaskSettings);
    }
    TaskMetadata metadata;
    return metadata;
}

void CaptureRegion::setRegionCaptureType(RegionCaptureType type)
{
    m_enRegionCaptureType = type;
}

RegionCaptureType CaptureRegion::getRegionCaptureType()
{
    return m_enRegionCaptureType;
}

TaskMetadata CaptureRegion::executeRegionCapture(TaskSettings *pTaskSettings)
{
    ScreenCapture::RegionCaptureMode mode;

    if(TaskSettings::getAdvancedSettings().RegionCaptureDisableAnnotation)
    {
        mode = ScreenCapture::Default;
    }
    else
    {
        mode = ScreenCapture::Annotation;
    }

    QImage image;
    Screenshot &screenshot = TaskHelpers::getScreenshot(pTaskSettings);
    screenshot.setCaptureCursor(false);

    if(pTaskSettings != nullptr && pTaskSettings->getCaptureSettings().SurfaceOptions.ActiveMonitorMode)
    {
        image = screenshot.captureActiveMonitor();
    }
    else
    {
        image = screenshot.captureFullscreen();
    }

    //show widget//

    TaskMetadata metadata;
    return metadata;
}

TaskMetadata CaptureRegion::executeRegionCaptureLight(TaskSettings *pTaskSettings)
{
    TaskMetadata metadata;
    return metadata;
}

TaskMetadata CaptureRegion::executeRegionCaptureTransparent(TaskSettings *pTaskSettings)
{
    TaskMetadata metadata;
    return metadata;
}

