#ifndef TASKSETTINGS_H
#define TASKSETTINGS_H

#include <QObject>
#include <QSize>
#include <QList>

#include "enums.h"
#include "uploaders/enums.h"
#include "helpers/enums.h"


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
//Rectangle CaptureCustomRegion = new Rectangle(0, 0, 0, 0);
//string CaptureCustomWindow = "";
//RegionCaptureOptions SurfaceOptions = new RegionCaptureOptions();
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
//[Category("General"), DefaultValue(false), Description("Allow after capture tasks for image files by loading them as bitmap when files are handled during file upload, clipboard file upload, drag && drop file upload, watch folder and other image file tasks.")]
//    public bool ProcessImagesDuringFileUpload { get; set; }
//
//[Category("General"), DefaultValue(false), Description("Use after capture tasks for clipboard image uploads.")]
//    public bool ProcessImagesDuringClipboardUpload { get; set; }
//
//[Category("General"), DefaultValue(false), Description("Use after capture tasks for browser extension image uploads.")]
//    public bool ProcessImagesDuringExtensionUpload { get; set; }
//
//[Category("General"), DefaultValue(true), Description("Allows file related after capture tasks (\"Perform actions\", \"Copy file to clipboard\" etc.) to be used when doing file upload.")]
//    public bool UseAfterCaptureTasksDuringFileUpload { get; set; }
//
//[Category("General"), DefaultValue(true), Description("Save text as file for tasks such as clipboard text upload, drag and drop text upload, index folder etc.")]
//    public bool TextTaskSaveAsFile { get; set; }
//
//[Category("General"), DefaultValue(false), Description("If task contains upload job then this setting will clear clipboard when task start.")]
//    public bool AutoClearClipboard { get; set; }
//
//[Category("Capture"), DefaultValue(false), Description("Disable annotation support in region capture.")]
//    public bool RegionCaptureDisableAnnotation { get; set; }
//
//[Category("Upload"), Description("Files with these file extensions will be uploaded using image uploader."),
// Editor("System.Windows.Forms.Design.StringCollectionEditor,System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", typeof(UITypeEditor))]
//    public List<string> ImageExtensions { get; set; }
//
//[Category("Upload"), Description("Files with these file extensions will be uploaded using text uploader."),
// Editor("System.Windows.Forms.Design.StringCollectionEditor,System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", typeof(UITypeEditor))]
//    public List<string> TextExtensions { get; set; }
//
//[Category("Upload"), DefaultValue(false), Description("Copy URL before start upload. Only works for FTP, FTPS, SFTP, Amazon S3, Google Cloud Storage and Azure Storage.")]
//    public bool EarlyCopyURL { get; set; }
//
//[Category("Upload text"), DefaultValue("txt"), Description("File extension when saving text to the local hard disk.")]
//    public string TextFileExtension { get; set; }
//
//[Category("Upload text"), DefaultValue("text"), Description("Text format e.g. csharp, cpp, etc.")]
//    public string TextFormat { get; set; }
//
//[Category("Upload text"), DefaultValue(""), Description("Custom text input. Use %input for text input. Example you can create web page with your text in it."),
// Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
//    public string TextCustom { get; set; }
//
//[Category("Upload text"), DefaultValue(true), Description("HTML encode custom text input.")]
//    public bool TextCustomEncodeInput { get; set; }
//
//[Category("After upload"), DefaultValue(false), Description("If result URL starts with \"http://\" then replace it with \"https://\".")]
//    public bool ResultForceHTTPS { get; set; }
//
//[Category("After upload"), DefaultValue("$result"),
// Description("Clipboard content format after uploading. Supported variables: $result, $url, $shorturl, $thumbnailurl, $deletionurl, $filepath, $filename, $filenamenoext, $folderpath, $foldername, $uploadtime and other variables such as %y-%mo-%d etc.")]
//    public string ClipboardContentFormat { get; set; }
//
//[Category("After upload"), DefaultValue("$result"), Description("Balloon tip content format after uploading. Supported variables: $result, $url, $shorturl, $thumbnailurl, $deletionurl, $filepath, $filename, $filenamenoext, $folderpath, $foldername, $uploadtime and other variables such as %y-%mo-%d etc.")]
//    public string BalloonTipContentFormat { get; set; }
//
//[Category("After upload"), DefaultValue("$result"), Description("After upload task \"Open URL\" format. Supported variables: $result, $url, $shorturl, $thumbnailurl, $deletionurl, $filepath, $filename, $filenamenoext, $folderpath, $foldername, $uploadtime and other variables such as %y-%mo-%d etc.")]
//    public string OpenURLFormat { get; set; }
//
//[Category("After upload"), DefaultValue(0), Description("Automatically shorten URL if the URL is longer than the specified number of characters. 0 means automatic URL shortening is not active.")]
//    public int AutoShortenURLLength { get; set; }
//
//[Category("After upload"), DefaultValue(false), Description("After upload form will be automatically closed after 60 seconds.")]
//    public bool AutoCloseAfterUploadForm { get; set; }
//
//[Category("Name pattern"), DefaultValue(100), Description("Maximum name pattern length for file name.")]
//    public int NamePatternMaxLength { get; set; }
//
//[Category("Name pattern"), DefaultValue(50), Description("Maximum name pattern title (%t) length for file name.")]
//    public int NamePatternMaxTitleLength { get; set; }
//
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
