#include "taskhelpers.h"

#include "screenCapture/screenshot.h"
#include "main/tasksettings.h"

Screenshot TaskHelpers::m_sScreenshot;

Screenshot &TaskHelpers::getScreenshot(TaskSettings *pTaskSettings)
{
    if(pTaskSettings == nullptr)
    {
        pTaskSettings = &TaskSettings::getDefaultTaskSettings();
    }

    m_sScreenshot.setCaptureCursor(pTaskSettings->getCaptureSettings().ShowCursor);
    m_sScreenshot.setCaptureClientArea(pTaskSettings->getCaptureSettings().CaptureClientArea);
    m_sScreenshot.setRemoveOutsideScreenArea(true);
    m_sScreenshot.setCaptureShadow(pTaskSettings->getCaptureSettings().CaptureShadow);
    m_sScreenshot.setShadowOffset(pTaskSettings->getCaptureSettings().CaptureShadowOffset);
    m_sScreenshot.setAutoHideTaskbar(pTaskSettings->getCaptureSettings().CaptureAutoHideTaskbar);

    return m_sScreenshot;
}
