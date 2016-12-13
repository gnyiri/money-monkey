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
  m_TableCreates.push_back(std::string("create table account_type(id integer, name varchar(40), color varchar(40), icon varchar(40), primary key(id))"));
  m_TableCreates.push_back(std::string("create table account(id integer, name varchar(40), account_type_id integer, initial_balance integer, current_balance integer, primary key(id))"));

  m_TableDrops.push_back(std::string("drop table account_type"));
  m_TableDrops.push_back(std::string("drop table account"));

  m_TableInserts.push_back(std::string("insert into account_type (name, color, icon) values('Debit Card', '#7777FF', 'debit-card.svg')"));
  m_TableInserts.push_back(std::string("insert into account_type (name, color, icon) values('Credit Card', '#FF4444', 'credit-card.svg')"));
  m_TableInserts.push_back(std::string("insert into account_type (name, color, icon) values('Saving', '#44FF44', 'piggy-bank.svg')"));
  m_TableInserts.push_back(std::string("insert into account_type (name, color, icon) values('Loan', '#FFFF44', 'house.svg')"));
  m_TableInserts.push_back(std::string("insert into account_type (name, color, icon) values('Cash', '#00FF00', 'cash.svg')"));

  m_TableInserts.push_back(std::string("insert into account (name, account_type_id) values('Cash', 1)"));
}
//---------------------------------------------------------------------
ApplicationManager::~ApplicationManager()
{
  /*if (m_Database.isOpen())
  {
    m_Database.close();
  }*/
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

  //qDebug() << "Database tables: " << m_Database.tables();

  return true;
}
//---------------------------------------------------------------------
bool ApplicationManager::init_db()
{
  QSqlQuery q;

  qDebug() << "Initialize Database";

  for(std::vector<std::string>::const_iterator it = m_TableDrops.begin(); it != m_TableDrops.end(); it++)
  {
    q.exec(it->c_str());
  }

  for(std::vector<std::string>::const_iterator it = m_TableCreates.begin(); it != m_TableCreates.end(); it++)
  {
    if(!q.exec(it->c_str()))
    {
      qDebug() << "Error occured during table creates!" << q.lastError();
      return false;
    }
  }

  for(std::vector<std::string>::const_iterator it = m_TableInserts.begin(); it != m_TableInserts.end(); it++)
  {
    if(!q.exec(it->c_str()))
    {
      qDebug() << "Error occured during table insertions!" << q.lastError();
      return false;
    }
  }

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
