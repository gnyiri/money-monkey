#include "accountmodel.hxx"
#include <QSqlRelation>

//---------------------------------------------------------------------
AccountModel::AccountModel(QObject* parent) : QSqlRelationalTableModel(parent)
{
  setTable("account");
  setEditStrategy(QSqlTableModel::OnRowChange);
  setHeaderData(0, Qt::Horizontal, "id");
  setHeaderData(1, Qt::Horizontal, "Name");
  QSqlRelation relation("account_type", "id", "name");
  setRelation(2, relation);
  setHeaderData(2, Qt::Horizontal, "Account type");
  setHeaderData(3, Qt::Horizontal, "Initial balance");
  setHeaderData(4, Qt::Horizontal, "Current balance");

  select();
}
//---------------------------------------------------------------------
QVariant AccountModel::data(const QModelIndex &idx, int role) const
{
  return QSqlRelationalTableModel::data(idx, role);
}
