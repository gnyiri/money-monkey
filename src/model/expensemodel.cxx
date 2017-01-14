#include "expensemodel.hxx"

#include <QColor>
#include <QIcon>
#include <QSqlRelation>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QString>
#include <QSqlField>

//---------------------------------------------------------------------
ExpenseModel::ExpenseModel(QObject* parent) : QSqlRelationalTableModel(parent)
{
  setTable("expense");

  setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
  setHeaderData(0, Qt::Horizontal, "id");
  setHeaderData(1, Qt::Horizontal, "Name");

  QSqlRelation type_relation("expense_type", "id", "name");
  setRelation(2, type_relation);
  setHeaderData(2, Qt::Horizontal, "Expense Type");

  QSqlRelation account_relation("account", "id", "name");
  setRelation(3, account_relation);
  setHeaderData(3, Qt::Horizontal, "Account");
  setHeaderData(4, Qt::Horizontal, "Date");
  setHeaderData(5, Qt::Horizontal, "Value");
  setHeaderData(6, Qt::Horizontal, "Comment");

  select();
}
//---------------------------------------------------------------------
QVariant ExpenseModel::data(const QModelIndex &idx, int role) const
{
  /*if(idx.column() == 1)
  {
    switch(role)
    {
      case Qt::DecorationRole:
        QSqlRecord current_record = record(idx.row());
        QSqlField id = current_record.field(0);
        QSqlQuery query(QString("select color from expense_type, expense where expense_type.id=account.expense_type_id and expense_type.id=") + QString(id.value().toString()));
        query.exec();

        if(query.next())
        {
          return QVariant(QColor(query.value(0).toString()));
        }
      break;
    }
  }*/
  return QSqlRelationalTableModel::data(idx, role);
}
