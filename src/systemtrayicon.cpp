#include "systemtrayicon.h"

#include <QApplication>
#include <QMenu>
#include <QTimer>
#include <QMainWindow>

SystemTrayIcon::SystemTrayIcon(QObject *parent)
    : QObject(parent)
    , m_pTrayIcon(nullptr)
    , m_pSystemTrayIconTimer(nullptr)
    , m_pWindowMenu(nullptr)
    , m_pMonitorMenu(nullptr)
{
    initSystemTray();
}

inline SystemTrayIcon::~SystemTrayIcon()
{
    if(m_pTrayIcon != nullptr)
    {
        delete m_pTrayIcon->contextMenu();
    }
}

QList<QAction *> SystemTrayIcon::mainMenu()
{
    QList<QAction *> listActions;

    if(m_pTrayIcon == nullptr)
        return listActions;

    if(m_pTrayIcon->contextMenu() == nullptr)
        return listActions;

    listActions = m_pTrayIcon->contextMenu()->actions();

    return listActions;
}

void SystemTrayIcon::updateWindowMenu()
{
    if(m_pWindowMenu != nullptr)
    {
        //
    }
}

void SystemTrayIcon::updateMonitorMenu()
{
    if(m_pMonitorMenu != nullptr)
    {
        //
    }
}

void SystemTrayIcon::initSystemTray()
{
    QIcon trayIconFile = QIcon(":/images/RGBCapture.ico");

    if(m_pTrayIcon == nullptr)
    {
        m_pTrayIcon = new QSystemTrayIcon(trayIconFile, this);
        connect(m_pTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(slotIconActivated(QSystemTrayIcon::ActivationReason)));

        m_pTrayIcon->setToolTip(qApp->applicationDisplayName());
        QMenu *pTrayMenu = new QMenu();
        m_pTrayIcon->setContextMenu(pTrayMenu);

        initCaptureMenu();
        initUploadMenu();
        initWorkflowsMenu();
        initToolsMenu();
        pTrayMenu->addSeparator();

        initAfterCaptureTasksMenu();
        initAfterUploadTasksMenu();
        initDestinationsMenu();

        pTrayMenu->addAction(QIcon(":/images/wrench-screwdriver.png"), tr("Application settings..."));
        pTrayMenu->addAction(QIcon(":/images/gear.png"), tr("Task settings..."));
        pTrayMenu->addAction(QIcon(":/images/keyboard.png"), tr("Hotkey settings..."));
        pTrayMenu->addAction(QIcon(":/images/keyboard--minus.png"), tr("Disable hotkeys..."));
        pTrayMenu->addSeparator();

        pTrayMenu->addAction(QIcon(":/images/folder-open-image.png"), tr("Screenshots folder..."));
        pTrayMenu->addAction(QIcon(":/images/application-blog.png"), tr("History..."));
        pTrayMenu->addAction(QIcon(":/images/application-icon-large.png"), tr("Image history..."));
        pTrayMenu->addSeparator();

        pTrayMenu->addAction(QIcon(":/images/ui-toolbar--arrow.png"), tr("Toggle actions toolbar"));
        pTrayMenu->addAction(QIcon(":/images/tick.png"), tr("Open main window"));
        pTrayMenu->addAction(QIcon(":/images/cross.png"), tr("Exit"));
    }

    m_pTrayIcon->show();
}

void SystemTrayIcon::initCaptureMenu()
{
    QMenu *pMenu = m_pTrayIcon->contextMenu();
    QMenu *pCaptureMenu = pMenu->addMenu(QIcon(":/images/camera.png"), tr("Capture"));
    pCaptureMenu->addAction(QIcon(":/images/layer_fullscreen.png"), tr("FullScreen"));
    m_pWindowMenu = pCaptureMenu->addMenu(QIcon(":/images/application-blue.png"), tr("Window"));
    updateWindowMenu();
    m_pMonitorMenu = pCaptureMenu->addMenu(QIcon(":/images/monitor.png"), tr("Monitor"));
    pCaptureMenu->addAction(QIcon(":/images/layer.png"), tr("Region"));
    pCaptureMenu->addAction(QIcon(":/images/layer-transparent.png"), tr("Region (Light)"));
    pCaptureMenu->addAction(QIcon(":/images/layer-transparent.png"), tr("Region (Transparent)"));
    pCaptureMenu->addAction(QIcon(":/images/layers.png"), tr("Last region"));
    pCaptureMenu->addAction(QIcon(":/images/camcorder-image.png"), tr("Screen recording"));
    pCaptureMenu->addAction(QIcon(":/images/film.png"), tr("Screen recording (GIF)"));
    pCaptureMenu->addAction(QIcon(":/images/ui-scroll-pane-image.png"), tr("Scrolling capture..."));
    pCaptureMenu->addAction(QIcon(":/images/clock.png"), tr("Auto capture"));
    pCaptureMenu->addAction(QIcon(":/images/cursor.png"), tr("Show cursor"));
    QMenu *pScreenshotDelayMenu = pCaptureMenu->addMenu(QIcon(":/images/clock-select.png"), tr("Screenshot delay: 0s"));
    initScreenshotDelayMenu(pScreenshotDelayMenu);
}

void SystemTrayIcon::initUploadMenu()
{
    QMenu *pMenu = m_pTrayIcon->contextMenu();
    QMenu *pUploadMenu = pMenu->addMenu(QIcon(":/images/arrow-090.png"), tr("Upload"));
    pUploadMenu->addAction(QIcon(":/images/folder-open-document.png"), tr("Upload file..."));
    pUploadMenu->addAction(QIcon(":/images/folder.png"), tr("Upload folder..."));
    pUploadMenu->addAction(QIcon(":/images/clipboard.png"), tr("Upload from clipboard..."));
    pUploadMenu->addAction(QIcon(":/images/notebook.png"), tr("Upload text..."));
    pUploadMenu->addAction(QIcon(":/images/drive.png"), tr("Upload from URL..."));
    pUploadMenu->addAction(QIcon(":/images/inbox.png"), tr("Drag and drop upload..."));
    pUploadMenu->addAction(QIcon(":/images/edit-scale.png"), tr("Shorten URL..."));
    pUploadMenu->addAction(QIcon(":/images/X-black.png"), tr("Tweet message..."));
}

void SystemTrayIcon::initWorkflowsMenu()
{
    QMenu *pMenu = m_pTrayIcon->contextMenu();
    QMenu *pWorkflowsMenu = pMenu->addMenu(QIcon(":/images/categories.png"), tr("Workflows"));
    pWorkflowsMenu->addAction(tr("Capture region"), QKeySequence(Qt::CTRL | Qt::Key_Print));
    pWorkflowsMenu->addAction(tr("Capture entire screen"), QKeySequence(Qt::Key_Print));
    pWorkflowsMenu->addAction(tr("Capture active window"), QKeySequence(Qt::ALT | Qt::Key_Print));
    pWorkflowsMenu->addAction(tr("Start/Stop screen recording"), QKeySequence(Qt::SHIFT | Qt::Key_Print));
    pWorkflowsMenu->addAction(tr("Start/Stop screen recording (GIF)"), QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Print));
}

void SystemTrayIcon::initToolsMenu()
{
    QMenu *pMenu = m_pTrayIcon->contextMenu();
    QMenu *pToolsMenu = pMenu->addMenu(QIcon(":/images/toolbox.png"), tr("Tools"));
    pToolsMenu->addAction(QIcon(":/images/clock.png"), tr("Color picker..."));
    pToolsMenu->addAction(QIcon(":/images/pipette.png"), tr("Screen color picker..."));
    pToolsMenu->addAction(QIcon(":/images/ruler-triangle.png"), tr("Ruler..."));
    pToolsMenu->addAction(QIcon(":/images/pin.png"), tr("Pin to screen..."));
    pToolsMenu->addAction(QIcon(":/images/image--pencil.png"), tr("Image editor..."));
    pToolsMenu->addAction(QIcon(":/images/picture-sunset.png"), tr("Image beautifier..."));
    pToolsMenu->addAction(QIcon(":/images/image-saturation.png"), tr("Image effects..."));
    pToolsMenu->addAction(QIcon(":/images/images-flickr.png"), tr("Image viewer..."));
    pToolsMenu->addAction(QIcon(":/images/document-break.png"), tr("Image combiner..."));
    pToolsMenu->addAction(QIcon(":/images/image-split.png"), tr("Image splitter..."));
    pToolsMenu->addAction(QIcon(":/images/image-resize-actual.png"), tr("Image thumbnailer..."));
    pToolsMenu->addAction(QIcon(":/images/camcorder--pencil.png"), tr("Video coverter..."));
    pToolsMenu->addAction(QIcon(":/images/images-stack.png"), tr("Video thumbnailer..."));
    pToolsMenu->addAction(QIcon(":/images/edit-drop-cap.png"), tr("OCR..."));
    pToolsMenu->addAction(QIcon(":/images/barcode-2d.png"), tr("QR code..."));
    pToolsMenu->addAction(QIcon(":/images/application-task.png"), tr("Hash checker..."));
    pToolsMenu->addAction(QIcon(":/images/folder-tree.png"), tr("Directory viewer..."));
    pToolsMenu->addAction(QIcon(":/images/clipboard-block.png"), tr("Clipboard viewer..."));
    pToolsMenu->addAction(QIcon(":/images/application-resize-full.png"), tr("Borderless window..."));
    pToolsMenu->addAction(QIcon(":/images/application-search-result.png"), tr("Inspect window..."));
    pToolsMenu->addAction(QIcon(":/images/monitor.png"), tr("Monitor test..."));
    pToolsMenu->addAction(QIcon(":/images/network-ip.png"), tr("DNS changer..."));
}

void SystemTrayIcon::initAfterCaptureTasksMenu()
{
    QMenu *pMenu = m_pTrayIcon->contextMenu();
    QMenu *pAfterCaptureTasksMenu = pMenu->addMenu(QIcon(":/images/image-export.png"), tr("After capture tasks"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/ui-menu-blue.png"), tr("Show quick task menu"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/application-text-image.png"), tr("Show \"After capture\" window"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/picture-sunset.png"), tr("Beautify image"));
    QMenu *pImageEffectsMenu = pAfterCaptureTasksMenu->addMenu(QIcon(":/images/image-saturation.png"), tr("Add image effects"));
    initImageEffectsMenu(pImageEffectsMenu);
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/image--pencil.png"), tr("Open in image editor"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/clipboard-paste-image.png"), tr("Copy image to clipboard"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/pin.png"), tr("Pin to screen"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/printer.png"), tr("Print image"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/disk.png"), tr("Save image to file"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/disk-rename.png"), tr("Save image to file as..."));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/disk-small.png"), tr("Save thumbnail image to file"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/application-terminal.png"), tr("Perform actions"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/clipboard-block.png"), tr("Copy file to clipboard"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/clipboard-list.png"), tr("Copy file path to clipboard"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/folder-stand.png"), tr("Show file in explorer"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/barcode-2d.png"), tr("Scan QR code"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/edit-drop-cap.png"), tr("Recognie text (OCR)"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/application--arrow.png"), tr("Show \"Before upload\" window"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/upload-cloud.png"), tr("Upload image to host"));
    pAfterCaptureTasksMenu->addAction(QIcon(":/images/bin.png"), tr("Delete file locally"));
}

void SystemTrayIcon::initAfterUploadTasksMenu()
{
    QMenu *pMenu = m_pTrayIcon->contextMenu();
    QMenu *pAfterUploadTasksMenu = pMenu->addMenu(QIcon(":/images/upload-cloud.png"), tr("After upload tasks"));
    pAfterUploadTasksMenu->addAction(QIcon(":/images/application-browser.png"), tr("Show \"After upload\" window"));
    pAfterUploadTasksMenu->addAction(QIcon(":/images/edit-scale.png"), tr("Shorten URL"));
    pAfterUploadTasksMenu->addAction(QIcon(":/images/globe-share.png"), tr("Share URL"));
    pAfterUploadTasksMenu->addAction(QIcon(":/images/clipboard-paste-document-text.png"), tr("Copy URL to clipboard"));
    pAfterUploadTasksMenu->addAction(QIcon(":/images/globe--arrow.png"), tr("Open URL"));
    pAfterUploadTasksMenu->addAction(QIcon(":/images/barcode-2d.png"), tr("Show QR code window"));
}

void SystemTrayIcon::initDestinationsMenu()
{
    QMenu *pMenu = m_pTrayIcon->contextMenu();
    QMenu *pDestinationsMenu = pMenu->addMenu(QIcon(":/images/drive-globe.png"), tr("Destinations"));
    QMenu *pImageUploaderMenu = pDestinationsMenu->addMenu(QIcon(":/images/image.png"), tr("Image uploader: Imgur"));
    initImageUploaderMenu(pImageUploaderMenu);
    QMenu *pTextUploaderMenu = pDestinationsMenu->addMenu(QIcon(":/images/notebook.png"), tr("Text uploader: Pastebin"));
    initTextUploaderMenu(pTextUploaderMenu);
    QMenu *pFileUploaderMenu = pDestinationsMenu->addMenu(QIcon(":/images/application-block.png"), tr("File uploader: Dropbox"));
    initFileUploaderMenu(pFileUploaderMenu);
    QMenu *pURLShortenerMenu = pDestinationsMenu->addMenu(QIcon(":/images/edit-scale.png"), tr("URL shortener: bit.ly"));
    initURLShortenerMenu(pURLShortenerMenu);
    QMenu *pURLSharingServiceMenu = pDestinationsMenu->addMenu(QIcon(":/images/globe-share.png"), tr("URL sharing service: X"));
    initURLSharingServiceMenu(pURLSharingServiceMenu);
    pDestinationsMenu->addAction(QIcon(":/images/globe--pencil.png"), tr("Destination settings..."));
    pDestinationsMenu->addAction(QIcon(":/images/upload-cloud.png"), tr("Custom uploader settings..."));
}

void SystemTrayIcon::initScreenshotDelayMenu(QMenu *pMenu)
{
    if(pMenu != nullptr)
    {
        pMenu->addAction(QIcon(""), tr("No delay"));
        pMenu->addAction(QIcon(""), tr("1 second"));
        pMenu->addAction(QIcon(""), tr("2 seconds"));
        pMenu->addAction(QIcon(""), tr("3 seconds"));
        pMenu->addAction(QIcon(""), tr("4 seconds"));
        pMenu->addAction(QIcon(""), tr("5 seconds"));
    }
}

void SystemTrayIcon::initImageEffectsMenu(QMenu *pMenu)
{
    if(pMenu != nullptr)
    {
        pMenu->addAction(QIcon(""), tr("Name"));
    }
}

void SystemTrayIcon::initImageUploaderMenu(QMenu *pMenu)
{
    if(pMenu != nullptr)
    {
        pMenu->addAction(QIcon(""), tr("Imgur"));
        pMenu->addAction(QIcon(""), tr("ImageShark"));
        pMenu->addAction(QIcon(""), tr("Flick"));
        pMenu->addAction(QIcon(""), tr("Photobucket"));
        pMenu->addAction(QIcon(""), tr("Google Photos"));
        pMenu->addAction(QIcon(""), tr("X"));
        pMenu->addAction(QIcon(""), tr("Chevereto"));
        pMenu->addAction(QIcon(""), tr("vgy.me"));
        pMenu->addAction(QIcon(""), tr("Custom image uploader"));
        QMenu *pFileUploader = pMenu->addMenu(QIcon(""), tr("File uploader"));
        initFileUploaderMenu(pFileUploader);
    }
}

void SystemTrayIcon::initTextUploaderMenu(QMenu *pMenu)
{
    if(pMenu != nullptr)
    {
        pMenu->addAction(QIcon(""), tr("Pastebin"));
        pMenu->addAction(QIcon(""), tr("Paste2"));
        pMenu->addAction(QIcon(""), tr("slexy"));
        pMenu->addAction(QIcon(""), tr("Paste.ee"));
        pMenu->addAction(QIcon(""), tr("Github Gist"));
        pMenu->addAction(QIcon(""), tr("uPaste"));
        pMenu->addAction(QIcon(""), tr("Hastebin"));
        pMenu->addAction(QIcon(""), tr("OneTimeSecret"));
        pMenu->addAction(QIcon(""), tr("Pastie"));
        pMenu->addAction(QIcon(""), tr("Custom text uploader"));
        QMenu *pFileUploader = pMenu->addMenu(QIcon(""), tr("File uploader"));
        initFileUploaderMenu(pFileUploader);
    }
}

void SystemTrayIcon::initFileUploaderMenu(QMenu *pMenu)
{
    if(pMenu != nullptr)
    {
        pMenu->addAction(QIcon(""), tr("Dropbox"));
        pMenu->addAction(QIcon(""), tr("FTP"));
        pMenu->addAction(QIcon(""), tr("OneDrive"));
        pMenu->addAction(QIcon(""), tr("Google Drive"));
        pMenu->addAction(QIcon(""), tr("Puush"));
        pMenu->addAction(QIcon(""), tr("Box"));
        pMenu->addAction(QIcon(""), tr("MEGA"));
        pMenu->addAction(QIcon(""), tr("Amazon S3"));
        pMenu->addAction(QIcon(""), tr("Google Cloud"));
        pMenu->addAction(QIcon(""), tr("Azure Storage"));
        pMenu->addAction(QIcon(""), tr("Backblaze B2"));
        pMenu->addAction(QIcon(""), tr("ownCloud/Nextcloud"));
        pMenu->addAction(QIcon(""), tr("MediaFire"));
        pMenu->addAction(QIcon(""), tr("Pushbullet"));
        pMenu->addAction(QIcon(""), tr("SendSpace"));
        pMenu->addAction(QIcon(""), tr("Hostr"));
        pMenu->addAction(QIcon(""), tr("JIRA"));
        pMenu->addAction(QIcon(""), tr("Lambda"));
        pMenu->addAction(QIcon(""), tr("Pomf"));
        pMenu->addAction(QIcon(""), tr("Storage"));
        pMenu->addAction(QIcon(""), tr("Uguu"));
        pMenu->addAction(QIcon(""), tr("seafile"));
        pMenu->addAction(QIcon(""), tr("Streamable"));
        pMenu->addAction(QIcon(""), tr("s-ul"));
        pMenu->addAction(QIcon(""), tr("LobFile"));
        pMenu->addAction(QIcon(""), tr("transfer.sh"));
        pMenu->addAction(QIcon(""), tr("Plik"));
        pMenu->addAction(QIcon(""), tr("YouTube"));
        pMenu->addAction(QIcon(""), tr("vault.ooo"));
        pMenu->addAction(QIcon(""), tr("Shared folder"));
        pMenu->addAction(QIcon(""), tr("Email"));
        pMenu->addAction(QIcon(""), tr("Custom file uploader"));
    }
}

void SystemTrayIcon::initURLShortenerMenu(QMenu *pMenu)
{
    if(pMenu != nullptr)
    {
        pMenu->addAction(QIcon(""), tr("bit.ly"));
        pMenu->addAction(QIcon(""), tr("is.gd"));
        pMenu->addAction(QIcon(""), tr("v.gd"));
        pMenu->addAction(QIcon(""), tr("tinyurl.com"));
        pMenu->addAction(QIcon(""), tr("turl.ca"));
        pMenu->addAction(QIcon(""), tr("yourls.org"));
        pMenu->addAction(QIcon(""), tr("adf.ly"));
        pMenu->addAction(QIcon(""), tr("qr.net"));
        pMenu->addAction(QIcon(""), tr("vurl.com"));
        pMenu->addAction(QIcon(""), tr("2.gp"));
        pMenu->addAction(QIcon(""), tr("Polr"));
        pMenu->addAction(QIcon(""), tr("Firebase Dynamic Links"));
        pMenu->addAction(QIcon(""), tr("Kutt"));
        pMenu->addAction(QIcon(""), tr("Zero Width Shortener"));
        pMenu->addAction(QIcon(""), tr("Custom URL shortener"));
    }
}

void SystemTrayIcon::initURLSharingServiceMenu(QMenu *pMenu)
{
    if(pMenu != nullptr)
    {
        pMenu->addAction(QIcon(""), tr("Email"));
        pMenu->addAction(QIcon(""), tr("X"));
        pMenu->addAction(QIcon(""), tr("Facebook"));
        pMenu->addAction(QIcon(""), tr("Reddit"));
        pMenu->addAction(QIcon(""), tr("Pinterest"));
        pMenu->addAction(QIcon(""), tr("Tumblr"));
        pMenu->addAction(QIcon(""), tr("LinkedIn"));
        pMenu->addAction(QIcon(""), tr("Stumble Upon"));
        pMenu->addAction(QIcon(""), tr("Delicious"));
        pMenu->addAction(QIcon(""), tr("VK"));
        pMenu->addAction(QIcon(""), tr("Pushbullet"));
        pMenu->addAction(QIcon(""), tr("Google Lens"));
        pMenu->addAction(QIcon(""), tr("Bing visual search"));
        pMenu->addAction(QIcon(""), tr("Custom URL sharing service"));
    }
}

void SystemTrayIcon::slotIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    m_enReason = reason;

    if(reason == QSystemTrayIcon::Context)
    {
        //nothing to do
    }
    else if(reason == QSystemTrayIcon::DoubleClick || reason == QSystemTrayIcon::Trigger)
    {
        if(m_pSystemTrayIconTimer == nullptr)
        {
            m_pSystemTrayIconTimer = new QTimer(this);
            connect(m_pSystemTrayIconTimer, &QTimer::timeout, this, &SystemTrayIcon::slotSystemTrayIconActivated);
            m_pSystemTrayIconTimer->setSingleShot(true);
            m_pSystemTrayIconTimer->setInterval(200);
        }

        m_pSystemTrayIconTimer->start();
    }
    else if(reason == QSystemTrayIcon::MiddleClick)
    {
        //nothing to do
    }
    else
    {
        qCritical() << __FUNCTION__ << "error:" << reason;
    }
}

void SystemTrayIcon::slotShowActiveWidget()
{
    qDebug() << __FUNCTION__;
}

void SystemTrayIcon::slotSystemTrayIconActivated()
{
    qDebug() << __FUNCTION__ << m_enReason;
    if(m_enReason == QSystemTrayIcon::DoubleClick)
    {
        //this->show();
        //this->activateWindow();
    }
    else if(m_enReason == QSystemTrayIcon::Trigger)
    {
        //start capture
    }
    else
    {
        qCritical() << __FUNCTION__ << "error:" << m_enReason;
    }
}


