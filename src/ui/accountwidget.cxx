#include <QVBoxLayout>
#include <QHeaderView>

#include "accountwidget.hxx"

//---------------------------------------------------------------------
AccountWidget::AccountWidget(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout* layout = new QVBoxLayout();
  m_AccountModel = new AccountModel();
  m_AccountView = new QTableView(this);
  m_AccountView->setModel(m_AccountModel);
  m_AccountView->verticalHeader()->setVisible(0);
  m_AccountView->setSelectionBehavior(QTableView::SelectRows);
  m_AccountView->hideColumn(0);
  layout->addWidget(m_AccountView);
  setLayout(layout);
}
