#ifndef ACCOUNTMODEL_HXX
#define ACCOUNTMODEL_HXX

#include <QObject>
#include <QSqlTableModel>

class AccountModel : public QSqlTableModel
{
public:
    AccountModel(QObject* parent = 0);
};

#endif // ACCOUNTMODEL_HXX
