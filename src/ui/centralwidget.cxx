#include "centralwidget.hxx"
#include <QVBoxLayout>
#include "accounttypwidget.hxx"

//---------------------------------------------------------------------
CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent),
    m_TabWidget(new QTabWidget(this))
{
    m_TabWidget->setTabPosition(QTabWidget::West);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_TabWidget);
    AccountTypeWidget* account_type_widget = new AccountTypeWidget(this);
    m_TabWidget->addTab(account_type_widget, "Account types");
    setLayout(layout);
    setMinimumSize(900, 400);
}
