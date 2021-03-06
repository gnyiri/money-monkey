#ifndef _APPLICATION_MANAGER_HXX
#define _APPLICATION_MANAGER_HXX

#include <vector>
#include <string>

#include <QtSql/QSqlError>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

/*!
 * \brief The ApplicationManager class
 */
class ApplicationManager
{
public:
  /*!
   * \brief get_instance
   * \return
   */
  static ApplicationManager& get_instance();
  /*!
   * \brief open_db
   * \return
   */
  bool open_db();
  /*!
   * \brief init_db
   * \return
   */
  bool init_db();
  /*!
   * \brief execute_sql
   * \param statement
   * \return
   */
  QSqlError execute_sql(const QString& statement);
private:
  /*!
   * \brief ApplicationManager CTOR
   */
  ApplicationManager();
  /*!
   * \brief ApplicationManager DTOR
   */
  ~ApplicationManager();
  /*!
   * \brief m_Database
   */
  QSqlDatabase m_Database;
};

#endif
