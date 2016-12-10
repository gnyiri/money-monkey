#include "mainwindow.hxx"
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include "application_manager.hxx"

//---------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_CentralWidget(new CentralWidget(this))
{
    build_ui();
}
//---------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete m_CentralWidget;
}
//---------------------------------------------------------------------
void MainWindow::build_ui()
{
    QMenu* database_menu = menuBar()->addMenu(tr("&Database"));
    QToolBar* database_toolbar = addToolBar(tr("Database"));

    const QIcon init_icon = QIcon::fromTheme("document-new", QIcon(":ic_loop_white_24px.svg"));
    QAction* init_action = new QAction(init_icon, tr("&Init"), this);

    database_menu->addAction(init_action);
    database_toolbar->addAction(init_action);

    connect(init_action, &QAction::triggered, this, &MainWindow::init_database);

    setCentralWidget(m_CentralWidget);
}
//---------------------------------------------------------------------
void MainWindow::init_database()
{
    ApplicationManager::get_instance().init_db();
}
