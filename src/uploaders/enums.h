#ifndef UPLOADERS_ENUMS_H
#define UPLOADERS_ENUMS_H

namespace Uploaders
{

enum ImageDestination
{
    Imgur,
    ImageShack,
    Flickr,
    Photobucket,
    Picasa,
    Twitter,
    Chevereto,
    Vgyme,
    CustomImageUploader, // Localized
    //FileUploader // Localized
};

enum TextDestination
{
    Pastebin,
    Paste2,
    Slexy,
    Paste_ee,
    Gist,
    Upaste,
    Hastebin,
    OneTimeSecret,
    Pastie,
    CustomTextUploader, // Localized
    //FileUploader // Localized
};

enum FileDestination
{
    Dropbox,
    FTP,
    OneDrive,
    GoogleDrive,
    Puush,
    Box,
    Mega,
    AmazonS3,
    GoogleCloudStorage,
    AzureStorage,
    BackblazeB2,
    OwnCloud,
    MediaFire,
    Pushbullet,
    SendSpace,
    Localhostr,
    Jira,
    Lambda,
    Pomf,
    Uguu,
    Seafile,
    Streamable,
    Sul,
    Lithiio,
    Transfersh,
    Plik,
    YouTube,
    Vault_ooo,
    SharedFolder, // Localized
    Email, // Localized
    CustomFileUploader // Localized
};

enum UrlShortenerType
{
    BITLY,
    ISGD,
    VGD,
    TINYURL,
    TURL,
    YOURLS,
    AdFly,
    QRnet,
    VURL,
    TwoGP,
    Polr,
    FirebaseDynamicLinks,
    Kutt,
    ZeroWidthShortener,
    CustomURLShortener // Localized
};

enum URLSharingServices
{
    //Email, // Localized
    //Twitter,
    Facebook,
    Reddit,
    Pinterest,
    Tumblr,
    LinkedIn,
    StumbleUpon,
    Delicious,
    VK,
    //Pushbullet,
    GoogleImageSearch, // Localized
    BingVisualSearch, // Localized
    CustomURLSharingService // Localized
};

enum HttpMethod
{
    GET,
    POST,
    PUT,
    PATCH,
    DELETE
};

enum ResponseType // Localized
{
    Text,
    RedirectionURL,
    Headers,
    LocationHeader
};

enum FTPProtocol
{
    //FTP,
    //FTPS,
    //SFTP
};

enum BrowserProtocol
{
    http,
    https,
    ftp,
    ftps,
    file
};

enum Privacy //YouTubeVideoPrivacy
{
    PrivacyPublic,
    PrivacyUnlisted,
    PrivacyPrivate
};

enum AccountType
{
    Anonymous,
    User
};

enum LinkFormatEnum
{
    URL,
    ForumImage,
    HTMLImage,
    WikiImage,
    ShortenedURL,
    ForumLinkedImage,
    HTMLLinkedImage,
    WikiLinkedImage,
    ThumbnailURL,
    LocalFilePath,
    LocalFilePathUri
};

enum CustomUploaderBody
{
    None,
    MultipartFormData,
    FormURLEncoded,
    JSON,
    XML,
    Binary
};

enum CustomUploaderDestinationType
{
    DestNone = 0,
    ImageUploader = 1, // Localized
    TextUploader = 1 << 1, // Localized
    FileUploader = 1 << 2, // Localized
    URLShortener = 1 << 3, // Localized
    URLSharingService = 1 << 4 // Localized
};

enum FTPSEncryption
{
    /// <summary>
    /// Connection starts in plain text and encryption is enabled with the AUTH command immediately after the server greeting.
    /// </summary>
    Explicit,
    /// <summary>
    /// Encryption is used from the start of the connection, port 990
    /// </summary>
    Implicit
};

enum OAuthLoginStatus
{
    LoginRequired,
    LoginSuccessful,
    LoginFailed
};

enum BoxShareAccessLevel
{
    Open,
    Company,
    Collaborators
};
}

#endif // UPLOADERS_ENUMS_H
