#include "expensetypedialog.hxx"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QPushButton>
#include <QColorDialog>

//---------------------------------------------------------------------
ExpenseTypeDialog::ExpenseTypeDialog(QSqlTableModel* expense_type_model, QWidget* parent) :
  QDialog(parent),
  m_ExpenseTypeModel(0),
  m_GroupBox(0),
  m_NameLineEdit(0),
  m_ButtonBox(0)
{
  m_Color.setNamedColor("#00FF00");

  m_ExpenseTypeModel = expense_type_model;

  QVBoxLayout* main_layout = new QVBoxLayout;
  m_GroupBox = new QGroupBox(tr("Add new expense type"));
  QFormLayout* form_layout = new QFormLayout;
  // line edit for name
  m_NameLineEdit = new QLineEdit;
  form_layout->addRow(tr("Name"), m_NameLineEdit);
  m_ColorButton = new QPushButton(m_Color.name());
  form_layout->addRow(tr("Color"), m_ColorButton);
  // layouts
  m_GroupBox->setLayout(form_layout);
  main_layout->addWidget(m_GroupBox);
  // button box for Ok and Cancel buttons
  m_ButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  // signal handlers
  connect(m_ButtonBox, &QDialogButtonBox::accepted, this, &ExpenseTypeDialog::accept);
  connect(m_ButtonBox, &QDialogButtonBox::rejected, this, &ExpenseTypeDialog::reject);
  connect(m_ColorButton, &QPushButton::clicked, this, &ExpenseTypeDialog::select_color);
  // final layout settings
  main_layout->addWidget(m_ButtonBox);
  setLayout(main_layout);
  // window title
  setWindowTitle(tr("New Expense Type"));
}
//---------------------------------------------------------------------
void ExpenseTypeDialog::accept()
{
  if(m_NameLineEdit->text().isEmpty())
  {
    QMessageBox::warning(this, tr("Warning"), tr("Name field is empty!"), QMessageBox::Ok);
    return;
  }

  QSqlQuery sql_query;

  sql_query.prepare("insert into expense_type (name, color) values(:name, :color)");
  sql_query.bindValue(":name", m_NameLineEdit->text());
  sql_query.bindValue(":color", m_Color.name());

  if(!sql_query.exec())
  {
    qDebug() << sql_query.lastError();
    QMessageBox::warning(this, tr("Warning"), tr("Error occurred!"), QMessageBox::Ok);
  }

  QDialog::accept();
}
//---------------------------------------------------------------------
void ExpenseTypeDialog::select_color()
{
  m_Color = QColorDialog::getColor(m_Color, this);
  m_ColorButton->setText(m_Color.name());
}
