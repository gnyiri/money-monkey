#include "centralwidget.hxx"
#include <QVBoxLayout>
#include "accounttypewidget.hxx"
#include "accountwidget.hxx"

//---------------------------------------------------------------------
CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent),
    m_TabWidget(new QTabWidget(this))
{
    m_TabWidget->setTabPosition(QTabWidget::West);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_TabWidget);
    AccountTypeWidget* account_type_widget = new AccountTypeWidget(this);
    AccountWidget* account_widget = new AccountWidget(this);
    m_TabWidget->addTab(account_type_widget, "Account types");
    m_TabWidget->addTab(account_widget, "Accounts");
    setLayout(layout);
    setMinimumSize(900, 575);
}
