#ifndef ACCOUNTTYPEVIEW_HXX
#define ACCOUNTTYPEVIEW_HXX

#include <QWidget>
#include <QTableView>
#include "accounttypemodel.hxx"

class AccountTypeWidget : public QWidget
{
    //Q_OBJECT

public:
    AccountTypeWidget(QWidget* parent = 0);
    void add_new_account_type();
    void delete_account_type();
private:
    AccountTypeModel* m_AccountTypeModel;
    QTableView* m_AccountTypeView;
};

#endif // ACCOUNTTYPEVIEW_HXX
