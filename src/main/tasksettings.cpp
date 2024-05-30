#include "tasksettings.h"

TaskSettings TaskSettings::m_sTaskSettings;
TaskSettingsImage TaskSettings::m_sImageSettings;
TaskSettingsCapture TaskSettings::m_sCaptureSettings;
TaskSettingsUpload TaskSettings::m_sUploadSettings;
TaskSettingsTools TaskSettings::m_sToolsSettings;

TaskSettings::TaskSettings(QObject *parent)
    : QObject{parent}
    , m_enJob(NoneType)
    , m_bUseDefaultAfterCaptureJob(true)
    , m_enAfterCaptureJob(Capture_CopyImageToClipboard | Capture_SaveImageToFile | Capture_UploadImageToHost)
    , m_bUseDefaultAfterUploadJob(true)
    , m_enAfterUploadJob(Upload_CopyURLToClipboard)
    , m_bUseDefaultDestinations(true)
    , m_enImageDestination(Uploaders::Imgur)
    , m_enImageFileDestination(Uploaders::Dropbox)
    , m_enTextDestination(Uploaders::Pastebin)
    , m_enTextFileDestination(Uploaders::Dropbox)
    , m_enFileDestination(Uploaders::Dropbox)
    , m_enURLShortenerDestination(Uploaders::BITLY)
    , m_enURLSharingServiceDestination(Uploaders::Facebook)
    , m_bOverrideFTP(false)
    , m_nFTPIndex(0)
    , m_bOverrideCustomUploader(false)
    , m_nCustomUploaderIndex(0)
    , m_bOverrideScreenshotsFolder(false)
    , m_bUseDefaultGeneralSettings(true)
    , m_bUseDefaultImageSettings(true)
    , m_bUseDefaultCaptureSettings(true)
{

}

TaskSettings &TaskSettings::getDefaultTaskSettings()
{
    return m_sTaskSettings;
}

TaskSettingsImage &TaskSettings::getImageSettings()
{
    return m_sImageSettings;
}

TaskSettingsTools &TaskSettings::getToolsSettings()
{
    return m_sToolsSettings;
}

TaskSettingsGeneral &TaskSettings::getGeneralSettings()
{
    return m_generalSettings;
}

TaskSettingsCapture &TaskSettings::getCaptureSettings()
{
    return m_sCaptureSettings;
}

QString TaskSettings::toString()
{
    return QString();
}

bool TaskSettings::isUsingDefaultSettings()
{
        //UseDefaultAfterCaptureJob && UseDefaultAfterUploadJob && UseDefaultDestinations && !OverrideFTP && !OverrideCustomUploader &&
        //!OverrideScreenshotsFolder && UseDefaultGeneralSettings && UseDefaultImageSettings && UseDefaultCaptureSettings && UseDefaultUploadSettings &&
        //UseDefaultActions && UseDefaultToolsSettings && UseDefaultAdvancedSettings && !WatchFolderEnabled;
    return false;
}

void TaskSettings::setDefaultSettings()
{

}

Uploaders::FileDestination TaskSettings::getFileDestinationByDataType(Helpers::EDataType dataType)
{
    return Uploaders::Dropbox;
}
