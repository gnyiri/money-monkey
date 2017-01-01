#ifndef EXPENSETYPEMODEL_HXX
#define EXPENSETYPEMODEL_HXX

#include <QObject>
#include <QSqlRelationalTableModel>

class ExpenseTypeModel : public QSqlRelationalTableModel
{
  Q_OBJECT

public:
  /*!
   * \brief ExpenseTypeModel
   * \param parent
   */
  ExpenseTypeModel(QObject* parent = 0);
  /*!
   * \brief data
   * \param idx
   * \param role
   * \return
   */
  QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;
};

#endif // EXPENSETYPEMODEL_HXX
