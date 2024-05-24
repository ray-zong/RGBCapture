#ifndef MENUITEM_H
#define MENUITEM_H

#include <QWidget>

class QLabel;
class QIcon;

class MenuItem : public QWidget
{
    Q_OBJECT
public:
    explicit MenuItem(const QIcon &icon, const QString &text, bool displayArrow, QWidget *parent = nullptr);

    void initUI();

signals:

private:
    QLabel *m_pImageLabel;
    QLabel *m_pTextLabel;
    QLabel *m_pArrowLabel;
};

#endif // MENUITEM_H
