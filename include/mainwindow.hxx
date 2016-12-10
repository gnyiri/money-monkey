#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QMainWindow>

#include "centralwidget.hxx"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void build_ui();
    void init_database();
    CentralWidget* m_CentralWidget;
};

#endif // MAINWINDOW_HXX
