#include "accountmodel.hxx"
#include <QSqlRelation>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QString>
#include <QSqlField>
#include <QIcon>

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
  if(idx.column() == 1)
  {
    switch(role)
    {
      case Qt::DecorationRole:
        QSqlRecord current_record = record(idx.row());
        QSqlField id = current_record.field(0);
        QSqlQuery query(QString("select icon from account_type, account where account_type.id=account.account_type_id and account.id=") + QString(id.value().toString()));
        query.exec();

        if(query.next())
        {
          return QVariant(QIcon(QString(":/images/") + query.value(0).toString()));
        }
      break;
    }
  }
  return QSqlRelationalTableModel::data(idx, role);
}
