#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SystemTrayIcon;
class MainLeftMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

private:
    Ui::MainWindow *ui;
    SystemTrayIcon *m_pSystemTrayIcon;
    MainLeftMenu *m_pMainLeftMenu;
};
#endif // MAINWINDOW_H
