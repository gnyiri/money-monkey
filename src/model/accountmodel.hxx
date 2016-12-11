#ifndef ACCOUNTMODEL_HXX
#define ACCOUNTMODEL_HXX

#include <QObject>
#include <QSqlRelationalTableModel>

/*!
 * \brief The AccountModel class
 */
class AccountModel : public QSqlRelationalTableModel
{
public:
  /*!
   * \brief AccountModel
   * \param parent
   */
  AccountModel(QObject* parent = 0);
  /*!
   * \brief data
   * \param idx
   * \param role
   * \return
   */
  QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;
};

#endif // ACCOUNTMODEL_HXX
