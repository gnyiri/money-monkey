#include "application_manager.hxx"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

//---------------------------------------------------------------------
ApplicationManager& ApplicationManager::get_instance()
{
  static ApplicationManager s_instance;
  return s_instance;
}
//---------------------------------------------------------------------
ApplicationManager::ApplicationManager()
{
  m_TableCreates.push_back(std::string("create table account_type(id integer, name varchar(40), color varchar(40), primary key(id));"));
  m_TableCreates.push_back(std::string("create table account(id integer, name varchar(40), account_type_id integer, initial_balance integer, current_balance, integer, primary key(id));"));

  m_TableDrops.push_back(std::string("drop table account_type"));
  m_TableDrops.push_back(std::string("drop table account"));

  open_db();
}
//---------------------------------------------------------------------
ApplicationManager::~ApplicationManager()
{
  m_Database.close();
}
//---------------------------------------------------------------------
QSqlError ApplicationManager::open_db()
{
  QCoreApplication* app = QCoreApplication::instance();
  QString database_file_path = app->applicationDirPath() + QDir::separator() + "money_monkey.db";

  qDebug() << "Open Database " << database_file_path;

  m_Database = QSqlDatabase::addDatabase("QSQLITE");
  m_Database.setDatabaseName(database_file_path);

  if (!m_Database.open())
  {
    return m_Database.lastError();
  }

  qDebug() << "Database tables: " << m_Database.tables();

  return QSqlError();
}
//---------------------------------------------------------------------
QSqlError ApplicationManager::init_db()
{
  QSqlQuery q;

  qDebug() << "Initialize Database";

  for(std::vector<std::string>::const_iterator it = m_TableDrops.begin(); it != m_TableDrops.end(); it++)
  {
    if(!q.exec(it->c_str()))
    {
      qDebug() << "Error occured during table drops!" << q.lastError();
      return q.lastError();
    }
  }

  for(std::vector<std::string>::const_iterator it = m_TableCreates.begin(); it != m_TableCreates.end(); it++)
  {
    if(!q.exec(it->c_str()))
    {
      qDebug() << "Error occured during table creates!" << q.lastError();
      return q.lastError();
    }
  }

  return QSqlError();
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
