#include "accountdialog.hxx"
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

//---------------------------------------------------------------------
AccountDialog::AccountDialog(QSqlRelationalTableModel* account_model, QWidget* parent) :
  QDialog(parent),
  m_AccountModel(0),
  m_GroupBox(0),
  m_NameLineEdit(0),
  m_AccountTypeCombo(0),
  m_InitialBalanceLineEdit(0),
  m_CurrentBalanceLineEdit(0),
  m_ButtonBox(0)
{
  m_AccountModel = account_model;

  QVBoxLayout* main_layout = new QVBoxLayout;
  m_GroupBox = new QGroupBox(tr("Add New Account"));
  QFormLayout* form_layout = new QFormLayout;
  m_NameLineEdit = new QLineEdit;
  form_layout->addRow(tr("Name"), m_NameLineEdit);
  m_AccountTypeCombo = new QComboBox;
  form_layout->addRow(tr("Account Type"), m_AccountTypeCombo);
  m_InitialBalanceLineEdit = new QLineEdit;
  m_InitialBalanceLineEdit->setText("0");
  form_layout->addRow(tr("Initial Balance"), m_InitialBalanceLineEdit);
  m_CurrentBalanceLineEdit = new QLineEdit;
  m_CurrentBalanceLineEdit->setText("0");
  form_layout->addRow(tr("Current Balance"), m_CurrentBalanceLineEdit);
  m_GroupBox->setLayout(form_layout);
  main_layout->addWidget(m_GroupBox);
  m_ButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

  connect(m_ButtonBox, &QDialogButtonBox::accepted, this, &AccountDialog::accept);
  connect(m_ButtonBox, &QDialogButtonBox::rejected, this, &AccountDialog::reject);

  main_layout->addWidget(m_ButtonBox);
  setLayout(main_layout);

  setWindowTitle(tr("New Account"));
}
