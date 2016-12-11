#include "accounttypemodel.hxx"

#include <QColor>
#include <QString>
#include <QDebug>
#include <QIcon>

//---------------------------------------------------------------------
AccountTypeModel::AccountTypeModel(QObject* parent) : QSqlTableModel(parent)
{
  setTable("account_type");
  setEditStrategy(QSqlTableModel::OnRowChange);
  setHeaderData(0, Qt::Horizontal, "id");
  setHeaderData(1, Qt::Horizontal, "Name");
  setHeaderData(2, Qt::Horizontal, "Color");
  setHeaderData(3, Qt::Horizontal, "Icon");
  select();
}
//---------------------------------------------------------------------
QVariant AccountTypeModel::data(const QModelIndex &idx, int role) const
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
