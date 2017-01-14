#include "expensewidget.hxx"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QHeaderView>
#include <QSqlRelationalDelegate>
#include <QMessageBox>

#include "expensedialog.hxx"

//---------------------------------------------------------------------
ExpenseWidget::ExpenseWidget(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout* layout = new QVBoxLayout();
  QHBoxLayout* button_layout = new QHBoxLayout();
  m_ExpenseModel = new ExpenseModel();
  m_ExpenseView = new QTableView(this);
  m_ExpenseView->setModel(m_ExpenseModel);
  m_ExpenseView->setShowGrid(false);
  m_ExpenseView->verticalHeader()->setVisible(0);
  m_ExpenseView->setSelectionBehavior(QTableView::SelectRows);
  m_ExpenseView->setSelectionMode(QTableView::SingleSelection);
  m_ExpenseView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
  m_ExpenseView->hideColumn(0);
  layout->addWidget(m_ExpenseView);
  QPushButton* add_new_expense_button = new QPushButton("Add New Expense");
  connect(add_new_expense_button, &QPushButton::clicked, this, &ExpenseWidget::add_new_expense);
  QPushButton* delete_expense_button = new QPushButton("Delete Expense");
  connect(delete_expense_button, &QPushButton::clicked, this, &ExpenseWidget::delete_expense);
  button_layout->addWidget(add_new_expense_button);
  button_layout->addWidget(delete_expense_button);
  layout->addLayout(button_layout);
  setLayout(layout);
}
//---------------------------------------------------------------------
void ExpenseWidget::add_new_expense()
{
  ExpenseDialog* dialog = new ExpenseDialog(m_ExpenseModel, this);

  if(dialog->exec() == ExpenseDialog::Accepted)
  {
    m_ExpenseModel->select();
  }

  delete dialog;
}
//---------------------------------------------------------------------
void ExpenseWidget::delete_expense()
{

}
