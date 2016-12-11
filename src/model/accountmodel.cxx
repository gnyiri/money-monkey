#include "accountmodel.hxx"

//---------------------------------------------------------------------
AccountModel::AccountModel(QObject* parent) : QSqlTableModel(parent)
{
  setTable("account");
  setEditStrategy(QSqlTableModel::OnRowChange);
  setHeaderData(0, Qt::Horizontal, "id");
  setHeaderData(1, Qt::Horizontal, "name");
  setHeaderData(2, Qt::Horizontal, "account_type");
  setHeaderData(3, Qt::Horizontal, "initial_balance");
  setHeaderData(3, Qt::Horizontal, "current_balance");
  select();
}
