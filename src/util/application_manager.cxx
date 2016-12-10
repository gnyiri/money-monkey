#include "application_manager.hxx"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

//---------------------------------------------------------------------
ApplicationManager& ApplicationManager::get_instance()
{
    static ApplicationManager s_instance;
    return s_instance;
}
//---------------------------------------------------------------------
QSqlError ApplicationManager::open_db()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/tmp/money_monkey.db");

    if (!db.open())
    {
        return db.lastError();
    }

    qDebug() << "Tables: ";
    qDebug() << db.tables();

    return QSqlError();
}
//---------------------------------------------------------------------
QSqlError ApplicationManager::init_db()
{
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/tmp/money_monkey.db");

    if (!db.open())
    {
        return db.lastError();
    }*/

    QSqlQuery q;

    q.exec("DROP TABLE account_type;");
    q.exec("DROP TABLE account;");

    if (!q.exec(QLatin1String("CREATE TABLE account_type (id INTEGER, name TEXT, PRIMARY KEY(id));")))
    {
        qDebug() << q.lastError();
        return q.lastError();
    }
    if (!q.exec(QLatin1String("create table account(id integer, name varchar(40), account_type_id integer, initial_balance integer, current_balance, integer, primary key(id));")))
    {
        return q.lastError();
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
