#ifndef ACCOUNTTYPEMODEL_HXX
#define ACCOUNTTYPEMODEL_HXX

#include <QSqlTableModel>

class AccountTypeModel : public QSqlTableModel
{
public:
    AccountTypeModel(QObject* parent = 0);
};

#endif // ACCOUNTTYPEMODEL_HXX
