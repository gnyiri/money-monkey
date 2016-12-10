#include "accountmodel.hxx"

AccountModel::AccountModel(QObject* parent) : QSqlTableModel(parent)
{
    this->setTable("account");
    this->setEditStrategy(QSqlTableModel::OnRowChange);
    this->setHeaderData(0, Qt::Horizontal, "id");
    this->setHeaderData(1, Qt::Horizontal, "name");
    this->setHeaderData(2, Qt::Horizontal, "account_type");
    this->setHeaderData(3, Qt::Horizontal, "initial_balance");
    this->setHeaderData(3, Qt::Horizontal, "current_balance");
    this->select();
}
