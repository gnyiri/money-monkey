#ifndef _APPLICATION_MANAGER_HXX
#define _APPLICATION_MANAGER_HXX

#include <vector>
#include <string>

#include <QtSql/QSqlError>
#include <QString>
#include <QSqlDatabase>

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
  QSqlError open_db();
  /*!
   * \brief init_db
   * \return
   */
  QSqlError init_db();
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
  /*!
   * \brief m_TableDrops
   */
  std::vector<std::string> m_TableDrops;
  /*!
   * \brief m_TableCreates
   */
  std::vector<std::string> m_TableCreates;
};

#endif
