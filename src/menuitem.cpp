#include "menuitem.h"

#include <QLabel>
#include <QHBoxLayout>

MenuItem::MenuItem(const QIcon &icon, const QString &text, bool displayArrow, QWidget *parent)
    : QWidget{parent}
    , m_pImageLabel(nullptr)
    , m_pTextLabel(nullptr)
    , m_pArrowLabel(nullptr)
{
    setFixedHeight(24);

    initUI();

    m_pImageLabel->setPixmap(icon.pixmap(m_pImageLabel->size()));
    m_pTextLabel->setText(text);

    if(displayArrow)
    {
        m_pArrowLabel->setPixmap(QPixmap(":/images/menuitem-arrow.png").scaled(m_pArrowLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void MenuItem::initUI()
{
    QHBoxLayout *pHLayout = new QHBoxLayout(this);
    pHLayout->setContentsMargins(0, 0, 0, 0);
    pHLayout->setSpacing(4);

    m_pImageLabel = new QLabel(this);

    m_pTextLabel = new QLabel(this);
    m_pTextLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    m_pArrowLabel = new QLabel(this);
    m_pArrowLabel->setFixedSize(8, 8);

    pHLayout->addWidget(m_pImageLabel);
    pHLayout->addWidget(m_pTextLabel);
    pHLayout->addStretch();
    pHLayout->addWidget(m_pArrowLabel);
}
