#include "accountmodel.hxx"
#include <QSqlRelation>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QString>
#include <QSqlField>

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
      case Qt::DisplayRole:
        QVariant current_data(QSqlRelationalTableModel::data(idx.sibling(idx.row(), 2), Qt::DisplayRole));
        qDebug() << current_data;
        QSqlRecord current_record = record(idx.row());
        qDebug() << current_record;
        //QVariant current_value(current_record.field(2));
        QSqlField field = current_record.field(2);
        qDebug() << field.typeID();
        QSqlQuery query(QString("select icon from account_type where id=3"));
      break;
    }
  }
  return QSqlRelationalTableModel::data(idx, role);
}
