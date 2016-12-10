#include "accounttypemodel.hxx"

AccountTypeModel::AccountTypeModel(QObject* parent) : QSqlTableModel(parent)
{
    this->setTable("account_type");
    this->setEditStrategy(QSqlTableModel::OnRowChange);
    this->setHeaderData(0, Qt::Horizontal, "id");
    this->setHeaderData(1, Qt::Horizontal, "name");
    this->select();
}
