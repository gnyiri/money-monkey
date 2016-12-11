#ifndef _APPLICATION_MANAGER_HXX
#define _APPLICATION_MANAGER_HXX

#include <QtSql/QSqlError>
#include <QString>

class ApplicationManager
{
public:
    static ApplicationManager& get_instance();
    QSqlError open_db();
    QSqlError init_db();
    QSqlError execute_sql(const QString& statement);
private:
    ApplicationManager()
    {
    }
    ~ApplicationManager()
    {
    }
};

#endif
