#include "accounttypwidget.hxx"
#include <QPushButton>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QHeaderView>
#include <QSqlRecord>
#include <QDebug>
#include <QInputDialog>
#include "accounttypemodel.hxx"
#include "application_manager.hxx"

//---------------------------------------------------------------------
AccountTypeWidget::AccountTypeWidget(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* button_layout = new QHBoxLayout(this);
    m_AccountTypeModel = new AccountTypeModel(this);
    m_AccountTypeView = new QTableView(this);
    m_AccountTypeView->setModel(m_AccountTypeModel);
    m_AccountTypeView->verticalHeader()->setVisible(0);
    layout->addWidget(m_AccountTypeView);
    QPushButton* add_new_account_type_button = new QPushButton("Add new account type", this);
    connect(add_new_account_type_button, &QPushButton::clicked, this, &AccountTypeWidget::add_new_account_type);
    QPushButton* delete_account_type_button = new QPushButton("Delete account type", this);
    connect(delete_account_type_button, &QPushButton::clicked, this, &AccountTypeWidget::delete_account_type);
    button_layout->addWidget(add_new_account_type_button);
    button_layout->addWidget(delete_account_type_button);
    layout->addLayout(button_layout);
}
//---------------------------------------------------------------------
void AccountTypeWidget::add_new_account_type()
{
    QSqlRecord record = m_AccountTypeModel->record();
    record.setGenerated("id", true);
    record.setValue("name", QVariant("hoki"));

    bool res = m_AccountTypeModel->insertRecord(-1, record);

    if (!res)
    {
        qDebug() << m_AccountTypeModel->lastError();
        return;
    }

    m_AccountTypeModel->select();
}
//---------------------------------------------------------------------
void AccountTypeWidget::delete_account_type()
{
    QModelIndex index = m_AccountTypeView->currentIndex();
    m_AccountTypeModel->removeRow(index.row());
    m_AccountTypeModel->select();
}

