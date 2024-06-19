#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QScreen>
#include <QApplication>

#include "systemtrayicon.h"
#include "mainleftmenu.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#pragma comment(lib, "User32.lib")
#else

#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_pSystemTrayIcon(nullptr)
    , m_pMainLeftMenu(nullptr)

{
    ui->setupUi(this);

    setWindowTitle(qApp->applicationName());
    setWindowIcon(QIcon(":/images/RGBCapture.ico"));

    m_pSystemTrayIcon = new SystemTrayIcon(this);
    QList<QAction *> listActions = m_pSystemTrayIcon->mainMenu();


    m_pMainLeftMenu = new MainLeftMenu(this);
    QVBoxLayout *pVLayout = new QVBoxLayout(ui->frame_menu);
    pVLayout->setContentsMargins(0, 0, 0, 0);
    pVLayout->setSpacing(0);
    pVLayout->addWidget(m_pMainLeftMenu);

    //add menu item
    int count = 0;
    for(auto ite = listActions.begin(); ite != listActions.end() && count < 3; ++ite)
    {
        QAction *pAction = *ite;
        if(pAction == nullptr)
            continue;

        if(pAction->text().isEmpty())
            ++count;

        m_pMainLeftMenu->addAction(pAction);
    }

    m_pMainLeftMenu->addAction(QIcon(":/images/traffic-cone.png"), "Debug", nullptr);
    m_pMainLeftMenu->addAction(QIcon(":/images/heart.png"), "Donate...", nullptr);
    m_pMainLeftMenu->addAction(QIcon(":/images/X-black.png"), "Follow @ShareX...", nullptr);
    m_pMainLeftMenu->addAction(QIcon(":/images/Discord-black.png"), "Discord...", nullptr);
    m_pMainLeftMenu->addAction(QIcon(":/images/crown.png"), "About...", nullptr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

