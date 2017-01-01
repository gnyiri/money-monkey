#include "expensetypewidget.hxx"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QPushButton>

#include "expensetypedialog.hxx"

//---------------------------------------------------------------------
ExpenseTypeWidget::ExpenseTypeWidget(QWidget *parent) :
  QWidget(parent),
  m_ExpenseTypeModel(0),
  m_ExpenseTypeView(0)
{
  QVBoxLayout* layout = new QVBoxLayout();
  QHBoxLayout* button_layout = new QHBoxLayout();
  m_ExpenseTypeModel = new ExpenseTypeModel();
  m_ExpenseTypeView = new QTableView(this);
  m_ExpenseTypeView->setModel(m_ExpenseTypeModel);
  m_ExpenseTypeView->setShowGrid(false);
  m_ExpenseTypeView->verticalHeader()->setVisible(0);
  m_ExpenseTypeView->setSelectionBehavior(QTableView::SelectRows);
  m_ExpenseTypeView->hideColumn(0);
  m_ExpenseTypeView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch );
  layout->addWidget(m_ExpenseTypeView);

  QPushButton* add_new_expense_type_button = new QPushButton("Add New Expense Type");
  connect(add_new_expense_type_button, &QPushButton::clicked, this, &ExpenseTypeWidget::add_new_expense_type);
  QPushButton* delete_expense_type_button = new QPushButton("Delete Expense Type");
  connect(delete_expense_type_button, &QPushButton::clicked, this, &ExpenseTypeWidget::delete_expense_type);
  button_layout->addWidget(add_new_expense_type_button);
  button_layout->addWidget(delete_expense_type_button);
  layout->addLayout(button_layout);

  setLayout(layout);
}
//---------------------------------------------------------------------
void ExpenseTypeWidget::add_new_expense_type()
{
  ExpenseTypeDialog* dialog = new ExpenseTypeDialog(m_ExpenseTypeModel, this);

  if(dialog->exec() == ExpenseTypeDialog::Accepted)
  {
    m_ExpenseTypeModel->select();
  }

  delete dialog;
}
//---------------------------------------------------------------------
void ExpenseTypeWidget::delete_expense_type()
{
  QModelIndex index = m_ExpenseTypeView->currentIndex();
  m_ExpenseTypeModel->removeRow(index.row());
  m_ExpenseTypeModel->select();
}
