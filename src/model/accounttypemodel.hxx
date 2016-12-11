#ifndef ACCOUNTTYPEMODEL_HXX
#define ACCOUNTTYPEMODEL_HXX

#include <QSqlTableModel>
#include <QObject>

class AccountTypeModel : public QSqlTableModel
{
public:
  AccountTypeModel(QObject* parent = 0);
  QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;
};

#endif // ACCOUNTTYPEMODEL_HXX
