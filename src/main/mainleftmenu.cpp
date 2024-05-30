#include "mainleftmenu.h"

#include <QVBoxLayout>
#include <QMenu>

#include "menuitem.h"

MainLeftMenu::MainLeftMenu(QWidget *parent)
    : QWidget{parent}
    , m_pVLayout(nullptr)
{
    initUI();
}

void MainLeftMenu::addAction(const QIcon &icon, const QString &text, QMenu *menu)
{
    if(m_pVLayout != nullptr)
    {
        MenuItem *pItem = new MenuItem(icon, text, menu != nullptr, this);
        m_pVLayout->addWidget(pItem);
    }
}

void MainLeftMenu::addAction(QAction *pAction)
{
    if(pAction == nullptr)
        return;

    if(m_pVLayout == nullptr)
        return;

    if(pAction->text().isEmpty())
    {
        QWidget *pLineWidget = new QWidget(this);
        pLineWidget->setAutoFillBackground(true);
        m_pVLayout->addSpacing(3);
        pLineWidget->setFixedHeight(1);

        QPalette palette(pLineWidget->palette());
        palette.setBrush(QPalette::Window, Qt::lightGray);
        pLineWidget->setPalette(palette);

        m_pVLayout->addSpacing(3);
        m_pVLayout->addWidget(pLineWidget);
    }
    else
    {
        MenuItem *pItem = new MenuItem(pAction->icon(), pAction->text(), pAction->menu() != nullptr, this);
        m_pVLayout->addWidget(pItem);
    }
}

void MainLeftMenu::initUI()
{
    m_pVLayout = new QVBoxLayout(this);
    m_pVLayout->setContentsMargins(8, 0, 8, 0);
    m_pVLayout->setSpacing(0);
}
