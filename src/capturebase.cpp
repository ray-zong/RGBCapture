#include "capturebase.h"

#include "tasksettings.h"
#include "taskmetadata.h"

#include <QTimer>
#include <QDebug>

CaptureBase::CaptureBase(QObject *parent)
    : QObject{parent}
    , m_bAllowAutoHideForm(false)
    , m_bAllowAnnotation(false)
{

}

void CaptureBase::capture(bool autoHideForm)
{
    capture(nullptr, autoHideForm);
}

void CaptureBase::capture(TaskSettings *pTaskSettings, bool autoHideForm)
{
    if(pTaskSettings == nullptr)
    {
        pTaskSettings = &TaskSettings::getDefaultTaskSettings();
    }

    if(pTaskSettings->getGeneralSettings().ToastWindowAutoHide)
    {
        //close active UI
    }

    if(TaskSettings::getCaptureSettings().ScreenshotDelay > 0)
    {
        int delay = (int)(TaskSettings::getCaptureSettings().ScreenshotDelay * 1000);

        //QTimer::singleShot(delay, [this](TaskSettings *pTaskSettings, bool autoHideForm){
        //    captureInternal(pTaskSettings, autoHideForm);
        //});
    }
    else
    {
        captureInternal(pTaskSettings, autoHideForm);
    }
}

TaskMetadata CaptureBase::execute(TaskSettings *pTaskSettings)
{
    qDebug() << __FUNCTION__;

    TaskMetadata metadata;
    return metadata;
}

void CaptureBase::afterCapture(TaskMetadata &metadata, TaskSettings *pTaskSettings)
{

}

void CaptureBase::captureInternal(TaskSettings *pTaskSettings, bool autoHideForm)
{
    qDebug() << __FUNCTION__ << pTaskSettings << autoHideForm;

    if(autoHideForm && m_bAllowAutoHideForm)
    {
        //hide main window
        //todo Sleep(250);
    }

    m_bAllowAnnotation = true;
    TaskMetadata metadata = execute(pTaskSettings);

    if(autoHideForm && m_bAllowAutoHideForm)
    {
        //show main window
        //active main window
    }

    afterCapture(metadata, pTaskSettings);

}
