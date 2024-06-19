
namespace ScreenCapture
{
enum ScreenRecordOutput
{
    //FFmpeg,
    //GIF
};

enum ScreenRecordGIFEncoding // Localized
{
    //FFmpeg,
    //NET,
    //OctreeQuantizer
};

enum RegionResult
{
    //Close,
    //Region,
    //LastRegion,
    //Fullscreen,
    //Monitor,
    //ActiveMonitor,
    //AnnotateRunAfterCaptureTasks,
    //AnnotateContinueTask,
    //AnnotateCancelTask
};

enum NodeType
{
    //None,
    //Rectangle,
    //Line,
    //Point,
    //Freehand
};

enum NodePosition
{
    //TopLeft,
    //Top,
    //TopRight,
    //Right,
    //BottomRight,
    //Bottom,
    //BottomLeft,
    //Left,
    //Extra
};

enum NodeShape
{
    //Square,
    //Circle,
    //Diamond,
    //CustomNode
};

enum FFmpegVideoCodec
{
    //libx264,
    //libx265,
    //libvpx,
    //libvpx_vp9,
    //libxvid,
    //h264_nvenc,
    //hevc_nvenc,
    //h264_amf,
    //hevc_amf,
    //h264_qsv,
    //hevc_qsv,
    //gif,
    //libwebp,
    //apng
};

enum FFmpegAudioCodec
{
    //libvoaacenc,
    //libopus,
    //libvorbis,
    //libmp3lame
};

enum FFmpegPreset
{
    //ultrafast,
    //superfast,
    //veryfast,
    //faster,
    //fast,
    //medium,
    //slow,
    //slower,
    //veryslow,
    //placebo
};

enum FFmpegTune
{
    //film,
    //animation,
    //grain,
    //stillimage,
    //psnr,
    //ssim,
    //fastdecode,
    //zerolatency
};

enum FFmpegNVENCPreset
{
    //p1,
    //p2,
    //p3,
    //p4,
    //p5,
    //p6,
    //p7
};

enum FFmpegNVENCTune
{
    hq,
    ll,
    ull,
    lossless
};

enum FFmpegAMFUsage
{
    transcoding,
    ultralowlatency,
    lowlatency,
    webcam,
    high_quality,
    lowlatency_high_quality
};

enum FFmpegAMFQuality
{
    speed,
    balanced,
    quality
};

enum FFmpegQSVPreset
{
    veryfast,
    faster,
    fast,
    medium,
    slow,
    slower,
    veryslow
};

enum FFmpegPaletteGenStatsMode
{
    full,
    diff,
    single
};

enum FFmpegPaletteUseDither
{
    none,
    bayer,
    heckbert,
    floyd_steinberg,
    sierra2,
    sierra2_4a,
    sierra3,
    burkes,
    atkinson
};

enum RegionCaptureMode
{
    Default,
    Annotation,
    ScreenColorPicker,
    Ruler,
    OneClick,
    Editor,
    TaskEditor
};

enum RegionCaptureAction // Localized
{
    None,
    CancelCapture,
    RemoveShapeCancelCapture,
    RemoveShape,
    SwapToolType,
    CaptureFullscreen,
    CaptureActiveMonitor,
    CaptureLastRegion
};

enum ShapeCategory
{
    Region,
    Drawing,
    Effect,
    Tool
};

enum ShapeType // Localized
{
    RegionRectangle,
    RegionEllipse,
    RegionFreehand,
    ToolSelect,
    DrawingRectangle,
    DrawingEllipse,
    DrawingFreehand,
    DrawingFreehandArrow,
    DrawingLine,
    DrawingArrow,
    DrawingTextOutline,
    DrawingTextBackground,
    DrawingSpeechBalloon,
    DrawingStep,
    DrawingMagnify,
    DrawingImage,
    DrawingImageScreen,
    DrawingSticker,
    DrawingCursor,
    DrawingSmartEraser,
    EffectBlur,
    EffectPixelate,
    EffectHighlight,
    ToolCrop,
    ToolCutOut
};

enum ImageEditorStartMode // Localized
{
    AutoSize,
    Normal,
    Maximized,
    PreviousState,
    Fullscreen
};

enum ImageInsertMethod
{
    //None,
    //Center,
    //CanvasExpandDown,
    //CanvasExpandRight
};

enum BorderStyle // Localized
{
    Solid,
    Dash,
    Dot,
    DashDot,
    DashDotDot
};

enum ScreenRecordState
{
    Waiting,
    BeforeStart,
    AfterStart,
    AfterRecordingStart,
    RecordingEnd,
    Encoding
};

enum ScreenRecordingStatus
{
    //Waiting,
    //Working,
    //Recording,
    //Paused,
    //Stopped,
    //Aborted
};

enum ScrollingCaptureStatus
{
    Failed,
    PartiallySuccessful,
    Successful
};
}
