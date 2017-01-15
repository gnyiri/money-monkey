#include "accountdialog.hxx"
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

//---------------------------------------------------------------------
AccountDialog::AccountDialog(QSqlRelationalTableModel* account_model, QWidget* parent) :
  QDialog(parent),
  m_AccountModel(0),
  m_GroupBox(0),
  m_NameLineEdit(0),
  m_AccountTypeCombo(0),
  m_InitialBalanceLineEdit(0),
  m_ButtonBox(0)
{
  m_AccountModel = account_model;
  // layout elements
  QVBoxLayout* main_layout = new QVBoxLayout;
  m_GroupBox = new QGroupBox(tr("Add New Account"));
  QFormLayout* form_layout = new QFormLayout;
  // line edit for name
  m_NameLineEdit = new QLineEdit;
  form_layout->addRow(tr("Name"), m_NameLineEdit);
  m_AccountTypeCombo = new QComboBox;
  // SQL query model for account type combo box
  QSqlQueryModel* sql_query_model = new QSqlQueryModel;
  QSqlQuery* sql_query = new QSqlQuery();
  sql_query->prepare("select id, name from account_type");
  sql_query->exec();
  sql_query_model->setQuery(*sql_query);
  m_AccountTypeCombo->setModel(sql_query_model);
  m_AccountTypeCombo->setModelColumn(1);
  form_layout->addRow(tr("Account Type"), m_AccountTypeCombo);
  // line edit for initial balance
  m_InitialBalanceLineEdit = new QLineEdit;
  m_InitialBalanceLineEdit->setValidator(new QIntValidator(-9999999, 9999999, this));
  m_InitialBalanceLineEdit->setText("0");
  form_layout->addRow(tr("Initial Balance"), m_InitialBalanceLineEdit);
  // line edit for limit
  m_LimitLineEdit = new QLineEdit;
  m_LimitLineEdit->setValidator(new QIntValidator(0, 9999999, this));
  m_LimitLineEdit->setText("0");
  form_layout->addRow(tr("Limit"), m_LimitLineEdit);
  // layouts
  m_GroupBox->setLayout(form_layout);
  main_layout->addWidget(m_GroupBox);
  // button box for Ok and Cancel buttons
  m_ButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  // signal handlers
  connect(m_ButtonBox, &QDialogButtonBox::accepted, this, &AccountDialog::accept);
  connect(m_ButtonBox, &QDialogButtonBox::rejected, this, &AccountDialog::reject);
  connect(m_AccountTypeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(account_changed(int)));
  // final layout settings
  main_layout->addWidget(m_ButtonBox);
  setLayout(main_layout);
  // window title
  setWindowTitle(tr("New Account"));
}
//---------------------------------------------------------------------
void AccountDialog::account_changed(int index)
{
}
//---------------------------------------------------------------------
void AccountDialog::accept()
{
  if(m_NameLineEdit->text().isEmpty())
  {
    QMessageBox::warning(this, tr("Warning"), tr("Name field is empty!"), QMessageBox::Ok);
    return;
  }

  QSqlQuery sql_query;

  sql_query.prepare("insert into account (name, account_type_id, initial_balance, balance_limit) values(:name, :account_type_id, :initial_balance, :balance_limit)");
  sql_query.bindValue(":name", m_NameLineEdit->text());
  QSqlQueryModel* sql_query_model = static_cast<QSqlQueryModel*>(m_AccountTypeCombo->model());
  sql_query.bindValue(":account_type_id", sql_query_model->data(sql_query_model->index(m_AccountTypeCombo->currentIndex(), 0)));
  sql_query.bindValue(":initial_balance", m_InitialBalanceLineEdit->text());
  sql_query.bindValue(":balance_limit", m_LimitLineEdit->text());

  if(!sql_query.exec())
  {
    qDebug() << sql_query.lastError();
    QMessageBox::warning(this, tr("Warning"), tr("Error occurred!"), QMessageBox::Ok);
  }

  QDialog::accept();
}
