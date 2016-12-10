#include "centralwidget.hxx"
#include <QVBoxLayout>
#include <QTableView>
#include "accounttypemodel.hxx"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent),
    m_TabWidget(new QTabWidget(this))
{
    this->setMinimumSize(900, 400);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_TabWidget);
    QTableView* account_type_view = new QTableView(this);
    account_type_view->setModel(new AccountTypeModel(this));
    m_TabWidget->setTabPosition(QTabWidget::West);
    m_TabWidget->addTab(account_type_view, "Accounts");
    this->setLayout(layout);
}
