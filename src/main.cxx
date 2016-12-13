#include <QApplication>
#include <QDebug>

#include "mainwindow.hxx"
#include "application_manager.hxx"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!ApplicationManager::get_instance().open_db())
    {
      qDebug() << "Cold not open Database!";
      exit(-1);
    }

    MainWindow w;
    w.show();

    return a.exec();
}
