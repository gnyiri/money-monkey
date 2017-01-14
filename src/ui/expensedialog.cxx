#include "expensedialog.hxx"
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

ExpenseDialog::ExpenseDialog(QSqlRelationalTableModel* expense_model, QWidget* parent) :
  QDialog(parent),
  m_ExpenseModel(0),
  m_GroupBox(0),
  m_NameLineEdit(0),
  m_ButtonBox(0)
{
  m_ExpenseModel = expense_model;
  // layout elements
  QVBoxLayout* main_layout = new QVBoxLayout;
  m_GroupBox = new QGroupBox(tr("Add New Expense"));
  QFormLayout* form_layout = new QFormLayout;
  // line edit for name
  m_NameLineEdit = new QLineEdit;
  form_layout->addRow(tr("Name"), m_NameLineEdit);
  // layouts
  m_GroupBox->setLayout(form_layout);
  main_layout->addWidget(m_GroupBox);
  // button box for Ok and Cancel buttons
  m_ButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  connect(m_ButtonBox, &QDialogButtonBox::accepted, this, &ExpenseDialog::accept);
  connect(m_ButtonBox, &QDialogButtonBox::rejected, this, &ExpenseDialog::reject);
  main_layout->addWidget(m_ButtonBox);

  setLayout(main_layout);
  setWindowTitle(tr("New Expense"));
}
//---------------------------------------------------------------------
void ExpenseDialog::accept()
{
  if(m_NameLineEdit->text().isEmpty())
  {
    QMessageBox::warning(this, tr("Warning"), tr("Name field is empty!"), QMessageBox::Ok);
    return;
  }

  QDialog::accept();
}
