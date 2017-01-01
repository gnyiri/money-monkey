#include "application_manager.hxx"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QFile>

//---------------------------------------------------------------------
ApplicationManager& ApplicationManager::get_instance()
{
  static ApplicationManager s_instance;
  return s_instance;
}
//---------------------------------------------------------------------
ApplicationManager::ApplicationManager()
{
}
//---------------------------------------------------------------------
ApplicationManager::~ApplicationManager()
{
}
//---------------------------------------------------------------------
bool ApplicationManager::open_db()
{
  QCoreApplication* app = QCoreApplication::instance();
  QString database_file_path = app->applicationDirPath() + QDir::separator() + "money_monkey.db";

  qDebug() << "Open Database " << database_file_path;

  m_Database = QSqlDatabase::addDatabase("QSQLITE");
  m_Database.setDatabaseName(database_file_path);

  if(!m_Database.open())
  {
    qDebug() << "Could not open database!";
    return false;
  }

  if(m_Database.tables().size() == 0)
  {
    init_db();
  }

  return true;
}
//---------------------------------------------------------------------
bool ApplicationManager::init_db()
{
  QSqlQuery q;

  qDebug() << "Initialize Database";

  QFile file(QString(":/database/db_init.sql"));

  if (!file.open(QFile::ReadOnly))
  {
    qDebug() << "Could not open SQL file!";
    return false;
  }

  while (!file.atEnd())
  {
    QByteArray line = file.readLine();
    std::string line_str = line.toStdString();

    if(line_str.empty())
    {
      continue;
    }

    if(!q.exec(line_str.c_str()))
    {
      qDebug() << q.lastError();
      file.close();
      return false;
    }
  }

  file.close();
  return true;
}
//---------------------------------------------------------------------
QSqlError ApplicationManager::execute_sql(const QString &statement)
{
  QSqlQuery q;

  if(!q.exec(statement.toStdString().c_str()))
  {
    qDebug() << q.lastError();
    return q.lastError();
  }

  return QSqlError();
}
