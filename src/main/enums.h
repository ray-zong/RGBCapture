#ifndef ENUMS_H
#define ENUMS_H


enum UpdateChannel // Localized
{
    Release,
    PreRelease,
    Dev
};

enum SupportedLanguage
{
    Automatic, // Localized
    //[Description("Nederlands (Dutch)")]
    Dutch,
    //[Description("English")]
    English,
    //[Description("Français (French)")]
    French,
    //[Description("Deutsch (German)")]
    German,
    //[Description("עִברִית (Hebrew)")]
    Hebrew,
    //[Description("Magyar (Hungarian)")]
    Hungarian,
    //[Description("Bahasa Indonesia (Indonesian)")]
    Indonesian,
    //[Description("Italiano (Italian)")]
    Italian,
    //[Description("日本語 (Japanese)")]
    Japanese,
    //[Description("한국어 (Korean)")]
    Korean,
    //[Description("Español mexicano (Mexican Spanish)")]
    MexicanSpanish,
    //[Description("فارسی (Persian)")]
    Persian,
    //[Description("Polski (Polish)")]
    Polish,
    //[Description("Português (Portuguese)")]
    Portuguese,
    //[Description("Português-Brasil (Portuguese-Brazil)")]
    PortugueseBrazil,
    //[Description("Română (Romanian)")]
    Romanian,
    //[Description("Русский (Russian)")]
    Russian,
    //[Description("简体中文 (Simplified Chinese)")]
    SimplifiedChinese,
    //[Description("Español (Spanish)")]
    Spanish,
    //[Description("繁體中文 (Traditional Chinese)")]
    TraditionalChinese,
    //[Description("Türkçe (Turkish)")]
    Turkish,
    //[Description("Українська (Ukrainian)")]
    Ukrainian,
    //[Description("Tiếng Việt (Vietnamese)")]
    Vietnamese
};

enum TaskJob
{
    Job,
    DataUpload,
    //FileUpload,
    TextUpload,
    //ShortenURL,
    ShareURL,
    Download,
    DownloadUpload
};

enum TaskStatus
{
    InQueue,
    Preparing,
    Working,
    Stopping,
    Stopped,
    Failed,
    Completed,
    History
};

enum AfterCaptureTasks // Localized
{
    Capture_None = 0,
    Capture_ShowQuickTaskMenu = 1,
    Capture_ShowAfterCaptureWindow = 1 << 1,
    Capture_BeautifyImage = 1 << 2,
    Capture_AddImageEffects = 1 << 3,
    Capture_AnnotateImage = 1 << 4,
    Capture_CopyImageToClipboard = 1 << 5,
    Capture_PinToScreen = 1 << 6,
    Capture_SendImageToPrinter = 1 << 7,
    Capture_SaveImageToFile = 1 << 8,
    Capture_SaveImageToFileWithDialog = 1 << 9,
    Capture_SaveThumbnailImageToFile = 1 << 10,
    Capture_PerformActions = 1 << 11,
    Capture_CopyFileToClipboard = 1 << 12,
    Capture_CopyFilePathToClipboard = 1 << 13,
    Capture_ShowInExplorer = 1 << 14,
    Capture_ScanQRCode = 1 << 15,
    Capture_DoOCR = 1 << 16,
    Capture_ShowBeforeUploadWindow = 1 << 17,
    Capture_UploadImageToHost = 1 << 18,
    Capture_DeleteFile = 1 << 19
};

enum AfterUploadTasks // Localized
{
    Upload_None = 0,
    Upload_ShowAfterUploadWindow = 1,
    Upload_UseURLShortener = 1 << 1,
    Upload_ShareURL = 1 << 2,
    Upload_CopyURLToClipboard = 1 << 3,
    Upload_OpenURL = 1 << 4,
    Upload_ShowQRCode = 1 << 5
};

enum CaptureType
{
    Fullscreen,
    Monitor,
    //ActiveMonitor,
    Window,
    //ActiveWindow,
    Region
    //CustomRegion,
    //LastRegion
};

//enum ScreenRecordStartMethod
//{
//    Region,
//    ActiveWindow,
//    CustomRegion,
//    LastRegion
//};

enum HotkeyType // Localized
{
    NoneType,
    // Upload
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    FileUpload,
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    FolderUpload,
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    ClipboardUpload,
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    ClipboardUploadWithContentViewer,
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    UploadText,
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    UploadURL,
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    DragDropUpload,
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    ShortenURL,
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    TweetMessage,
    //[Category(EnumExtensions.HotkeyType_Category_Upload)]
    StopUploads,
    // Screen capture
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    PrintScreen,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    ActiveWindow,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    CustomWindow,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    ActiveMonitor,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    RectangleRegion,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    RectangleLight,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    RectangleTransparent,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    CustomRegion,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    LastRegion,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    ScrollingCapture,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    AutoCapture,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenCapture)]
    StartAutoCapture,
    // Screen record
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    ScreenRecorder,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    ScreenRecorderActiveWindow,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    ScreenRecorderCustomRegion,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    StartScreenRecorder,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    ScreenRecorderGIF,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    ScreenRecorderGIFActiveWindow,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    ScreenRecorderGIFCustomRegion,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    StartScreenRecorderGIF,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    StopScreenRecording,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    PauseScreenRecording,
    //[Category(EnumExtensions.HotkeyType_Category_ScreenRecord)]
    AbortScreenRecording,
    // Tools
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ColorPicker,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ScreenColorPicker,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    Ruler,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    PinToScreen,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    PinToScreenFromScreen,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    PinToScreenFromClipboard,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    PinToScreenFromFile,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ImageEditor,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ImageBeautifier,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ImageEffects,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ImageViewer,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ImageCombiner,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ImageSplitter,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ImageThumbnailer,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    VideoConverter,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    VideoThumbnailer,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    OCR,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    QRCode,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    QRCodeDecodeFromScreen,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    HashCheck,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    IndexFolder,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    ClipboardViewer,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    BorderlessWindow,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    InspectWindow,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    MonitorTest,
    //[Category(EnumExtensions.HotkeyType_Category_Tools)]
    DNSChanger,
    // Other
    //[Category(EnumExtensions.HotkeyType_Category_Other)]
    DisableHotkeys,
    //[Category(EnumExtensions.HotkeyType_Category_Other)]
    OpenMainWindow,
    //[Category(EnumExtensions.HotkeyType_Category_Other)]
    OpenScreenshotsFolder,
    //[Category(EnumExtensions.HotkeyType_Category_Other)]
    OpenHistory,
    //[Category(EnumExtensions.HotkeyType_Category_Other)]
    OpenImageHistory,
    //[Category(EnumExtensions.HotkeyType_Category_Other)]
    ToggleActionsToolbar,
    //[Category(EnumExtensions.HotkeyType_Category_Other)]
    ToggleTrayMenu,
    //[Category(EnumExtensions.HotkeyType_Category_Other)]
    ExitShareX
};

//enum ToastClickAction // Localized
//{
//    CloseNotification,
//    AnnotateImage,
//    CopyImageToClipboard,
//    CopyFile,
//    CopyFilePath,
//    CopyUrl,
//    OpenFile,
//    OpenFolder,
//    OpenUrl,
//    Upload,
//    PinToScreen
//};

//enum ThumbnailViewClickAction // Localized
//{
//    Default,
//    Select,
//    OpenImageViewer,
//    OpenFile,
//    OpenFolder,
//    OpenURL,
//    EditImage
//};

enum FileExistAction // Localized
{
    Ask,
    Overwrite,
    UniqueName,
    Cancel
};

enum ImagePreviewVisibility // Localized
{
    Show,
    Hide,
    AutoVisible
};

enum ImagePreviewLocation // Localized ThumbnailTitleLocation
{
    Side,
    Top,
    Bottom
};

//enum RegionCaptureType
//{
//    Default,
//    Light,
//    Transparent
//};

enum StartupState
{
    Disabled,
    DisabledByUser,
    Enabled,
    DisabledByPolicy,
    EnabledByPolicy
};

//enum BalloonTipClickAction
//{
//    None,
//    OpenURL,
//    OpenDebugLog
//};

enum TaskViewMode // Localized
{
    ListView,
    ThumbnailView
};

//enum NativeMessagingAction
//{
//    None,
//    UploadImage,
//    UploadVideo,
//    UploadAudio,
//    UploadText,
//    ShortenURL
//};

#endif // ENUMS_H
