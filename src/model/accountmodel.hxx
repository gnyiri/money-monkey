#ifndef ACCOUNTMODEL_HXX
#define ACCOUNTMODEL_HXX

#include <QObject>
#include <QSqlTableModel>

/*!
 * \brief The AccountModel class
 */
class AccountModel : public QSqlTableModel
{
public:
  /*!
   * \brief AccountModel
   * \param parent
   */
  AccountModel(QObject* parent = 0);
};

#endif // ACCOUNTMODEL_HXX
