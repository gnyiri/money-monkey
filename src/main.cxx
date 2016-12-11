#include "mainwindow.hxx"
#include <QApplication>
#include "application_manager.hxx"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ApplicationManager::get_instance().open_db();

    MainWindow w;
    w.show();

    return a.exec();
}