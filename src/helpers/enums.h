#ifndef HELPERS_ENUMS_H
#define HELPERS_ENUMS_H

namespace Helpers
{
    enum EDataType // Localized
    {
        Default,
        File,
        Image,
        Text,
        URL
    };

    enum PNGBitDepth // Localized
    {
        //Default,
        Automatic,
        Bit32,
        Bit24
    };

    enum GIFQuality // Localized
    {
        //Default,
        Bit8,
        Bit4,
        Grayscale
    };

    enum EImageFormat
    {
        PNG,
        JPEG,
        GIF,
        BMP,
        TIFF
    };

    enum HashType
    {
        CRC32,
        MD5,
        SHA1,
        SHA256,
        SHA384,
        SHA512
    };

    enum BorderType
    {
        Outside,
        Inside
    };

    enum DownloaderFormStatus
    {
        Waiting,
        DownloadStarted,
        DownloadCompleted,
        InstallStarted
    };

    enum InstallType
    {
        //Default,
        //Silent,
        //VerySilent,
        //Event
    };

    enum ReleaseChannelType
    {
        Stable,
        Beta,
        Dev
    };

    enum UpdateStatus
    {
        None,
        UpdateCheckFailed,
        UpdateAvailable,
        UpToDate
    };

    enum PrintType
    {
        //Image,
        //Text
    };

    enum DrawStyle
    {
        Hue,
        Saturation,
        Brightness,
        Red,
        Green,
        Blue
    };

    enum ColorType
    {
        //None, RGBA, HSB, CMYK, Hex, Decimal
    };

    enum ColorFormat
    {
        RGB, RGBA, ARGB
    };

    enum ProxyMethod // Localized
    {
        //None,
        //Manual,
        //Automatic
    };

    enum SlashType
    {
        Prefix,
        Suffix
    };

    enum ScreenTearingTestMode
    {
        VerticalLines,
        HorizontalLines
    };

    enum HotkeyStatus
    {
        Registered,
        Failed,
        NotConfigured
    };

    enum ImageCombinerAlignment
    {
        LeftOrTop,
        Center,
        RightOrBottom
    };

    enum ImageInterpolationMode
    {
        HighQualityBicubic,
        Bicubic,
        HighQualityBilinear,
        Bilinear,
        NearestNeighbor
    };

    enum ArrowHeadDirection // Localized
    {
        End,
        Start,
        Both
    };

    enum FFmpegArchitecture
    {
        win64,
        win32,
        macos64
    };

    enum StepType // Localized
    {
        Numbers,
        LettersUppercase,
        LettersLowercase,
        RomanNumeralsUppercase,
        RomanNumeralsLowercase
    };

    enum CutOutEffectType // Localized
    {
        //None,
        ZigZag,
        TornEdge,
        Wave
    };
}

#endif // UPLOADERS_ENUMS_H
