#ifndef REGIONCAPTUREOPTIONS
#define REGIONCAPTUREOPTIONS

#include <QList>
#include <QSize>
#include <QPoint>
#include <QColor>

namespace ScreenCapture
{
    class RegionCaptureOptions
    {
		public:
        const int DefaultMinimumSize = 5;
        const int MagnifierPixelCountMinimum = 3;
        const int MagnifierPixelCountMaximum = 35;
        const int MagnifierPixelSizeMinimum = 3;
        const int MagnifierPixelSizeMaximum = 30;
        const int SnapDistance = 30;
        const int MoveSpeedMinimum = 1;
        const int MoveSpeedMaximum = 10;
		
        bool QuickCrop = true;
        int MinimumSize = DefaultMinimumSize;
        //RegionCaptureAction RegionCaptureActionRightClick = RegionCaptureAction.RemoveShapeCancelCapture;
        //RegionCaptureAction RegionCaptureActionMiddleClick = RegionCaptureAction.SwapToolType;
        //RegionCaptureAction RegionCaptureActionX1Click = RegionCaptureAction.CaptureFullscreen;
        //RegionCaptureAction RegionCaptureActionX2Click = RegionCaptureAction.CaptureActiveMonitor;
        bool DetectWindows = true;
        bool DetectControls = true;
        // TEMP: For backward compatibility
        bool UseDimming = true;
        int BackgroundDimStrength = 10;
        bool UseCustomInfoText = false;
        QString CustomInfoText = "X: $x, Y: $y$nR: $r, G: $g, B: $b$nHex: $hex"; // Formats: $x, $y, $r, $g, $b, $hex, $HEX, $n
        //QList<SnapSize> SnapSizes{
        //    new SnapSize(426, 240), // 240p
        //    new SnapSize(640, 360), // 360p
        //    new SnapSize(854, 480), // 480p
        //    new SnapSize(1280, 720), // 720p
        //    new SnapSize(1920, 1080) // 1080p
        //};
        bool ShowInfo = true;
        bool ShowMagnifier = true;
        bool UseSquareMagnifier = false;
        int MagnifierPixelCount = 15; // Must be odd number like 11, 13, 15 etc.
        int MagnifierPixelSize = 10;
        bool ShowCrosshair = false;
        bool UseLightResizeNodes = false;
        bool EnableAnimations = true;
        bool IsFixedSize = false;
        QSize FixedSize = QSize(250, 250);
        bool ShowFPS = false;
        int FPSLimit = 100;
        int MenuIconSize = 0;
        bool MenuLocked = false;
        bool RememberMenuState = false;
        bool MenuCollapsed = false;
        QPoint MenuPosition;
        int InputDelay = 500;
        bool SwitchToDrawingToolAfterSelection = false;
        bool SwitchToSelectionToolAfterDrawing = false;
        bool ActiveMonitorMode = false;

        // Annotation
        //AnnotationOptions AnnotationOptions;
        //ShapeType LastRegionTool = ShapeType.RegionRectangle;
        //ShapeType LastAnnotationTool = ShapeType.DrawingRectangle;
        //ShapeType LastEditorTool = ShapeType.DrawingRectangle;

        // Image editor
        //ImageEditorStartMode ImageEditorStartMode = ImageEditorStartMode.AutoSize;
        //WindowState ImageEditorWindowState = new WindowState();
        bool ZoomToFitOnOpen = false;
        bool EditorAutoCopyImage = false;
        bool AutoCloseEditorOnTask = false;
        bool ShowEditorPanTip = true;
        //ImageInterpolationMode ImageEditorResizeInterpolationMode = ImageInterpolationMode.Bicubic;
        QSize EditorNewImageSize = QSize(800, 600);
        bool EditorNewImageTransparent = false;
        QColor EditorNewImageBackgroundColor = Qt::white;
        QColor EditorCanvasColor = Qt::transparent;
        //QList<ImageEffectPreset> ImageEffectPresets = new List<ImageEffectPreset>();
        int SelectedImageEffectPreset = 0;

        // Color picker
        //ColorPickerOptions ColorPickerOptions = new ColorPickerOptions();

        // Screen color picker
        QString ScreenColorPickerInfoText = "";
    };
}

#endif
