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
#include <QPushButton>

ExpenseDialog::ExpenseDialog(QSqlRelationalTableModel* expense_model, QWidget* parent) :
  QDialog(parent),
  m_ExpenseModel(0),
  m_GroupBox(0),
  m_NameLineEdit(0),
  m_CalendarWidget(0),
  m_ValueLineEdit(0),
  m_ExpenseTypeCombo(0),
  m_AccountCombo(0),
  m_CommentLineEdit(0),
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
  m_CalendarWidget = new QCalendarWidget;
  form_layout->addRow(tr("Date"), m_CalendarWidget);
  m_ValueLineEdit = new QLineEdit;
  form_layout->addRow(tr("Value"), m_ValueLineEdit);
  // expense type combobox
  m_ExpenseTypeCombo = new QComboBox;
  // SQL query model for account type combo box
  QSqlQueryModel* sql_query_model_exp = new QSqlQueryModel;
  QSqlQuery* sql_query_exp = new QSqlQuery;
  sql_query_exp->prepare("select id, name from expense_type");
  sql_query_exp->exec();
  sql_query_model_exp->setQuery(*sql_query_exp);
  m_ExpenseTypeCombo->setModel(sql_query_model_exp);
  m_ExpenseTypeCombo->setModelColumn(1);
  form_layout->addRow(tr("Expense Type"), m_ExpenseTypeCombo);
  // account combobox
  m_AccountCombo = new QComboBox;
  QSqlQueryModel* sql_query_model_acc = new QSqlQueryModel;
  QSqlQuery* sql_query_acc= new QSqlQuery;
  sql_query_acc->prepare("select id, name from account");
  sql_query_acc->exec();
  sql_query_model_acc->setQuery(*sql_query_acc);
  m_AccountCombo->setModel(sql_query_model_acc);
  m_AccountCombo->setModelColumn(1);
  form_layout->addRow(tr("Account"), m_AccountCombo);
  m_CommentLineEdit = new QLineEdit;
  form_layout->addRow(tr("Comment"), m_CommentLineEdit);
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

  QSqlQuery sql_query;

  sql_query.prepare("insert into expense (name, expense_type_id, account_id, date, value, comment) values(:name, :expense_type_id, :account_id, :date, :value, :comment)");
  sql_query.bindValue(":name", m_NameLineEdit->text());
  QSqlQueryModel* sql_query_model_expense_type_id = static_cast<QSqlQueryModel*>(m_ExpenseTypeCombo->model());
  sql_query.bindValue(":expense_type_id", sql_query_model_expense_type_id->data(sql_query_model_expense_type_id->index(m_ExpenseTypeCombo->currentIndex(), 0)));
  QSqlQueryModel* sql_query_model_account_id = static_cast<QSqlQueryModel*>(m_AccountCombo->model());
  sql_query.bindValue(":account_id", sql_query_model_account_id->index(m_AccountCombo->currentIndex(), 0));
  sql_query.bindValue(":date", "hekk");
  sql_query.bindValue(":value", m_ValueLineEdit->text());

  if(!sql_query.exec())
  {
    qDebug() << sql_query.lastError();
    QMessageBox::warning(this, tr("Warning"), tr("Error occurred!"), QMessageBox::Ok);
  }

  QDialog::accept();
}
