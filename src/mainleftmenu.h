#ifndef MAINLEFTMENU_H
#define MAINLEFTMENU_H

#include <QWidget>

class QVBoxLayout;

class MainLeftMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainLeftMenu(QWidget *parent = nullptr);

    void addAction(const QIcon &icon, const QString &text, QMenu *menu);
    void addAction(QAction *pAction);

signals:

private:
    void initUI();

private:
    QVBoxLayout *m_pVLayout;
};

#endif // MAINLEFTMENU_H
