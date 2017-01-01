#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QHeaderView>
#include <QSqlRelationalDelegate>
#include <QMessageBox>

#include "accountwidget.hxx"
#include "accountdialog.hxx"

//---------------------------------------------------------------------
AccountWidget::AccountWidget(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout* layout = new QVBoxLayout();
  QHBoxLayout* button_layout = new QHBoxLayout();
  m_AccountModel = new AccountModel();
  m_AccountView = new QTableView(this);
  m_AccountView->setModel(m_AccountModel);
  m_AccountView->setShowGrid(false);
  m_AccountView->verticalHeader()->setVisible(0);
  m_AccountView->setSelectionBehavior(QTableView::SelectRows);
  m_AccountView->setSelectionMode(QTableView::SingleSelection);
  m_AccountView->hideColumn(0);
  m_AccountView->setItemDelegate(new QSqlRelationalDelegate(m_AccountView));
  m_AccountView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
  layout->addWidget(m_AccountView);
  QPushButton* add_new_account_button = new QPushButton("Add New Account");
  connect(add_new_account_button, &QPushButton::clicked, this, &AccountWidget::add_new_account);
  QPushButton* delete_account_button = new QPushButton("Delete Account");
  connect(delete_account_button, &QPushButton::clicked, this, &AccountWidget::delete_account);
  button_layout->addWidget(add_new_account_button);
  button_layout->addWidget(delete_account_button);
  layout->addLayout(button_layout);
  setLayout(layout);
}
//---------------------------------------------------------------------
void AccountWidget::add_new_account()
{
  AccountDialog* dialog = new AccountDialog(m_AccountModel, this);

  if(dialog->exec() == AccountDialog::Accepted)
  {
    m_AccountModel->select();
  }

  delete dialog;
}
//---------------------------------------------------------------------
void AccountWidget::delete_account()
{
  if(QMessageBox::question(this, "Delete Account", "Are you sure to delete the selected Account?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
  {
    QModelIndex index = m_AccountView->currentIndex();
    m_AccountModel->removeRow(index.row());
    m_AccountModel->select();
  }
}
