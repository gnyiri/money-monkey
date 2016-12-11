#include "accountmodel.hxx"

//---------------------------------------------------------------------
AccountModel::AccountModel(QObject* parent) : QSqlRelationalTableModel(parent)
{
  setTable("account");
  setEditStrategy(QSqlRelationalTableModel::OnRowChange);
  setHeaderData(0, Qt::Horizontal, "id");
  setHeaderData(1, Qt::Horizontal, "Name");
  setHeaderData(2, Qt::Horizontal, "Account type");
  setHeaderData(3, Qt::Horizontal, "Initial balance");
  setHeaderData(4, Qt::Horizontal, "Current balance");
  select();
}
