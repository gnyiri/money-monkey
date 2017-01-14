#ifndef EXPENSEMODEL_HXX
#define EXPENSEMODEL_HXX

#include <QObject>
#include <QSqlRelationalTableModel>

class ExpenseModel : public QSqlRelationalTableModel
{
  Q_OBJECT

public:
  /*!
   * \brief ExpenseModel
   * \param parent
   */
  ExpenseModel(QObject* parent = 0);
  /*!
   * \brief data
   * \param idx
   * \param role
   * \return
   */
  QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;
};

#endif // EXPENSEMODEL_HXX
