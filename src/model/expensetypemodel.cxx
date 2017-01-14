#include "expensetypemodel.hxx"

#include <QColor>
#include <QIcon>

//---------------------------------------------------------------------
ExpenseTypeModel::ExpenseTypeModel(QObject* parent) : QSqlRelationalTableModel(parent)
{
  setTable("expense_type");

  setEditStrategy(QSqlTableModel::OnFieldChange);
  setHeaderData(0, Qt::Horizontal, "id");
  setHeaderData(1, Qt::Horizontal, "Name");
  setHeaderData(2, Qt::Horizontal, "Color");
  setHeaderData(3, Qt::Horizontal, "Icon");
  setHeaderData(4, Qt::Horizontal, "Importance");
  select();
}
//---------------------------------------------------------------------
QVariant ExpenseTypeModel::data(const QModelIndex &idx, int role) const
{
  if(idx.column() == 2)
  {
    switch(role)
    {
      case Qt::BackgroundRole:
      {
        QVariant data(QSqlTableModel::data(idx, Qt::DisplayRole));
        QColor color;
        color.setNamedColor(data.toString());
        return QVariant(color);
      }
      break;
      default:
      break;
    }
  }
  else if(idx.column() == 3)
  {
    switch(role)
    {
      case Qt::DecorationRole:
      {
        QVariant data(QSqlTableModel::data(idx, Qt::DisplayRole));
        QIcon icon(":/images/" + data.toString());
        return QVariant(icon);
      }
      break;
      default:
      break;
    }
  }

  return QSqlTableModel::data(idx, role);
}
