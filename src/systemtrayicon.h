#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

#include <QObject>
#include <QSystemTrayIcon>

class QMenu;
class QAction;

class SystemTrayIcon : public QObject
{
    Q_OBJECT

public:
    explicit SystemTrayIcon(QObject *parent = nullptr);
    ~SystemTrayIcon();

    QList<QAction*> mainMenu();

public slots:
    void updateWindowMenu();
    void updateMonitorMenu();

private:
    void initSystemTray();
    void initCaptureMenu();
    void initUploadMenu();
    void initWorkflowsMenu();
    void initToolsMenu();
    void initAfterCaptureTasksMenu();
    void initAfterUploadTasksMenu();
    void initDestinationsMenu();
    void initScreenshotDelayMenu(QMenu *pMenu);
    void initImageEffectsMenu(QMenu *pMenu);
    void initImageUploaderMenu(QMenu *pMenu);
    void initTextUploaderMenu(QMenu *pMenu);
    void initFileUploaderMenu(QMenu *pMenu);
    void initURLShortenerMenu(QMenu *pMenu);
    void initURLSharingServiceMenu(QMenu *pMenu);



private slots:
    void slotIconActivated(QSystemTrayIcon::ActivationReason reason);
    void slotShowActiveWidget();
    void slotSystemTrayIconActivated();

private:
    QSystemTrayIcon *m_pTrayIcon;
    QTimer *m_pSystemTrayIconTimer;
    QSystemTrayIcon::ActivationReason m_enReason;

    QMenu *m_pWindowMenu;
    QMenu *m_pMonitorMenu;
};

#endif // SYSTEMTRAYICON_H
