#include "accounttypewidget.hxx"
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
  QVBoxLayout* layout = new QVBoxLayout();
  m_AccountTypeModel = new AccountTypeModel();
  m_AccountTypeView = new QTableView(this);
  m_AccountTypeView->setModel(m_AccountTypeModel);
  m_AccountTypeView->setShowGrid(false);
  m_AccountTypeView->verticalHeader()->setVisible(0);
  m_AccountTypeView->setSelectionBehavior(QTableView::SelectRows);
  m_AccountTypeView->hideColumn(0);
  m_AccountTypeView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch );
  layout->addWidget(m_AccountTypeView);
  setLayout(layout);
}
//---------------------------------------------------------------------
AccountTypeWidget::~AccountTypeWidget()
{
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

