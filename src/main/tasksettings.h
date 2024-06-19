#ifndef TASKSETTINGS_H
#define TASKSETTINGS_H

#include <QObject>
#include <QSize>
#include <QList>
#include <QRect>

#include "enums.h"
#include "uploaders/enums.h"
#include "helpers/enums.h"
#include "screenCapture/regioncaptureoptions.h"


class ExternalProgram;
class WatchFolderSettings;

class TaskSettingsGeneral
{
public:
    bool PlaySoundAfterCapture = true;
    bool PlaySoundAfterUpload = true;
    bool ShowToastNotificationAfterTaskCompleted = true;
    float ToastWindowDuration = 3.0f;
    float ToastWindowFadeDuration = 1.0f;
    //ContentAlignment ToastWindowPlacement = ContentAlignment.BottomRight;
    QSize ToastWindowSize = QSize(400, 300);
    //ToastClickAction ToastWindowLeftClickAction = ToastClickAction.OpenUrl;
    //ToastClickAction ToastWindowRightClickAction = ToastClickAction.CloseNotification;
    //ToastClickAction ToastWindowMiddleClickAction = ToastClickAction.AnnotateImage;
    bool ToastWindowAutoHide = true;
    bool UseCustomCaptureSound = false;
    QString CustomCaptureSoundPath;
    bool UseCustomTaskCompletedSound = false;
    QString CustomTaskCompletedSoundPath;
    bool UseCustomErrorSound = false;
    QString CustomErrorSoundPath;
    bool DisableNotifications = false;
    bool DisableNotificationsOnFullscreen = false;
};

class TaskSettingsImage
{
public:
    //EImageFormat ImageFormat = EImageFormat.PNG;
    //PNGBitDepth ImagePNGBitDepth = PNGBitDepth.Default;
    //int ImageJPEGQuality = 90;
    //GIFQuality ImageGIFQuality = GIFQuality.Default;
    //bool ImageAutoUseJPEG = true;
    //int ImageAutoUseJPEGSize = 2048;
    //bool ImageAutoJPEGQuality = false;
    //FileExistAction FileExistAction = FileExistAction.Ask;
    //
    //List<ImageEffectPreset> ImageEffectPresets = new List<ImageEffectPreset>() { ImageEffectPreset.GetDefaultPreset() };
    //int SelectedImageEffectPreset = 0;
    //
    //bool ShowImageEffectsWindowAfterCapture = false;
    //bool ImageEffectOnlyRegionCapture = false;
    //bool UseRandomImageEffect = false;
    //
    //int ThumbnailWidth = 200;
    //int ThumbnailHeight = 0;
    //string ThumbnailName = "-thumbnail";
    //bool ThumbnailCheckSize = false;
};

class TaskSettingsCapture
{
public:
    bool ShowCursor = true;
    float ScreenshotDelay = 0;
    bool CaptureTransparent = false;
    bool CaptureShadow = true;
    int CaptureShadowOffset = 100;
    bool CaptureClientArea = false;
    bool CaptureAutoHideTaskbar = false;
    QRect CaptureCustomRegion = QRect(0, 0, 0, 0);
    QString CaptureCustomWindow = "";
    ScreenCapture::RegionCaptureOptions SurfaceOptions;
    //FFmpegOptions FFmpegOptions = new FFmpegOptions();
    int ScreenRecordFPS = 30;
    int GIFFPS = 15;
    bool ScreenRecordShowCursor = true;
    bool ScreenRecordAutoStart = true;
    float ScreenRecordStartDelay = 0.0f;
    bool ScreenRecordFixedDuration = false;
    float ScreenRecordDuration = 3.0f;
    bool ScreenRecordTwoPassEncoding = false;
    bool ScreenRecordAskConfirmationOnAbort = false;
    bool ScreenRecordTransparentRegion = false;
    //ScrollingCaptureOptions ScrollingCaptureOptions = new ScrollingCaptureOptions();
    //OCROptions OCROptions = new OCROptions();

};

class TaskSettingsUpload
{
public:
    //bool UseCustomTimeZone = false;
    //TimeZoneInfo CustomTimeZone = TimeZoneInfo.Utc;
    //string NameFormatPattern = "%ra{10}";
    //string NameFormatPatternActiveWindow = "%pn_%ra{10}";
    //bool FileUploadUseNamePattern = false;
    //bool FileUploadReplaceProblematicCharacters = false;
    //bool URLRegexReplace = false;
    //string URLRegexReplacePattern = "^https?://(.+)$";
    //string URLRegexReplaceReplacement = "https://$1";
    //bool ClipboardUploadURLContents = false;
    //bool ClipboardUploadShortenURL = false;
    //bool ClipboardUploadShareURL = false;
    //bool ClipboardUploadAutoIndexFolder = false;
    //List<UploaderFilter> UploaderFilters = new List<UploaderFilter>();

};

class TaskSettingsTools
{
public:
    QString ScreenColorPickerFormat = "$hex";
    QString ScreenColorPickerFormatCtrl = "$r255, $g255, $b255";
    QString ScreenColorPickerInfoText = "RGB: $r255, $g255, $b255$nHex: $hex$nX: $x Y: $y";
    //PinToScreenOptions PinToScreenOptions = new PinToScreenOptions();
    //IndexerSettings IndexerSettings = new IndexerSettings();
    //ImageBeautifierOptions ImageBeautifierOptions = new ImageBeautifierOptions();
    //ImageCombinerOptions ImageCombinerOptions = new ImageCombinerOptions();
    //VideoConverterOptions VideoConverterOptions = new VideoConverterOptions();
    //VideoThumbnailOptions VideoThumbnailOptions = new VideoThumbnailOptions();
    //BorderlessWindowSettings BorderlessWindowSettings = new BorderlessWindowSettings();
};

class TaskSettingsAdvanced
{
public:
    bool ProcessImagesDuringFileUpload;

    bool ProcessImagesDuringClipboardUpload;

    bool ProcessImagesDuringExtensionUpload;

    bool UseAfterCaptureTasksDuringFileUpload;

    bool TextTaskSaveAsFile;

    bool AutoClearClipboard;

    bool RegionCaptureDisableAnnotation;

    QList<QString> ImageExtensions;

    QList<QString> TextExtensions;

    bool EarlyCopyURL;

    QString TextFileExtension;

    QString TextFormat;

    QString TextCustom;

    bool TextCustomEncodeInput;

    bool ResultForceHTTPS;

    QString ClipboardContentFormat;

    QString BalloonTipContentFormat;

    QString OpenURLFormat;

    int AutoShortenURLLength;

    bool AutoCloseAfterUploadForm;

    int NamePatternMaxLength;

    int NamePatternMaxTitleLength;

    //public TaskSettingsAdvanced()
    //{
    //    this.ApplyDefaultPropertyValues();
    //    ImageExtensions = FileHelpers.ImageFileExtensions.ToList();
    //    TextExtensions = FileHelpers.TextFileExtensions.ToList();
    //}
};

class TaskSettings : public QObject
{
    Q_OBJECT
public:
    explicit TaskSettings(QObject *parent = nullptr);

    static TaskSettings &getDefaultTaskSettings();

    static TaskSettingsImage &getImageSettings();

    static TaskSettingsTools &getToolsSettings();

    TaskSettingsGeneral &getGeneralSettings();

    static TaskSettingsCapture &getCaptureSettings();

    static TaskSettingsAdvanced &getAdvancedSettings();

    QString toString();

    bool isUsingDefaultSettings();
    void setDefaultSettings();

    Uploaders::FileDestination getFileDestinationByDataType(Helpers::EDataType dataType);

signals:

private:
    QString m_strDescription;
    HotkeyType m_enJob;
    bool m_bUseDefaultAfterCaptureJob;
    QFlags<AfterCaptureTasks> m_enAfterCaptureJob;
    bool m_bUseDefaultAfterUploadJob;
    QFlags<AfterUploadTasks> m_enAfterUploadJob;
    bool m_bUseDefaultDestinations;
    Uploaders::ImageDestination m_enImageDestination;
    Uploaders::FileDestination m_enImageFileDestination;
    Uploaders::TextDestination m_enTextDestination;
    Uploaders::FileDestination m_enTextFileDestination;
    Uploaders::FileDestination m_enFileDestination;
    Uploaders::UrlShortenerType m_enURLShortenerDestination;
    Uploaders::URLSharingServices m_enURLSharingServiceDestination;
    bool m_bOverrideFTP;
    int m_nFTPIndex;
    bool m_bOverrideCustomUploader;
    int m_nCustomUploaderIndex;
    bool m_bOverrideScreenshotsFolder;
    QString m_strScreenshotsFolder;
    bool m_bUseDefaultGeneralSettings;
    TaskSettingsGeneral m_generalSettings;
    bool m_bUseDefaultImageSettings;
    bool m_bUseDefaultCaptureSettings;
    bool m_bUseDefaultUploadSettings;
    bool m_bUseDefaultActions;
    QList<ExternalProgram *> m_listExternalPrograms;
    bool m_bUseDefaultToolsSettings;
    bool m_bUseDefaultAdvancedSettings;
    bool m_bWatchFolderEnabled;
    QList<WatchFolderSettings *> m_listWatchFolderSettings;

private:
    static TaskSettings m_sTaskSettings;
    static TaskSettingsImage m_sImageSettings;
    static TaskSettingsCapture m_sCaptureSettings;
    static TaskSettingsUpload m_sUploadSettings;
    static TaskSettingsTools m_sToolsSettings;
    static TaskSettingsAdvanced m_sAdvancedSettings;
};

#endif // TASKSETTINGS_H
