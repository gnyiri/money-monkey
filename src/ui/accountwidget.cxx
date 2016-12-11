#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QHeaderView>
#include <QSqlRelationalDelegate>

#include "accountwidget.hxx"

//---------------------------------------------------------------------
AccountWidget::AccountWidget(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout* layout = new QVBoxLayout();
  QHBoxLayout* button_layout = new QHBoxLayout();
  m_AccountModel = new AccountModel();
  m_AccountView = new QTableView(this);
  m_AccountView->setModel(m_AccountModel);
  m_AccountView->verticalHeader()->setVisible(0);
  m_AccountView->setSelectionBehavior(QTableView::SelectRows);
  m_AccountView->hideColumn(0);
  m_AccountView->setItemDelegate(new QSqlRelationalDelegate(m_AccountView));
  m_AccountView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch );
  layout->addWidget(m_AccountView);
  QPushButton* add_new_account_button = new QPushButton("Add New Account");
  connect(add_new_account_button, &QPushButton::clicked, this, &AccountWidget::add_new_account);
  QPushButton* delete_account_button = new QPushButton("Delete Account");
  connect(delete_account_button, &QPushButton::clicked, this, &AccountWidget::delete_account);
  button_layout->addWidget(add_new_account_button);
  layout->addLayout(button_layout);
  setLayout(layout);
}
//---------------------------------------------------------------------
void AccountWidget::add_new_account()
{
  m_AccountModel->insertRow(m_AccountModel->rowCount());
  m_AccountModel->submit();
}
//---------------------------------------------------------------------
void AccountWidget::delete_account()
{

}

