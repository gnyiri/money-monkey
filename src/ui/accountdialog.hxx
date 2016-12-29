#ifndef ACCOUNTDIALOG_HXX
#define ACCOUNTDIALOG_HXX

#include <QDialog>
#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QLineEdit>
#include <QComboBox>
#include <QGroupBox>
#include <QDialogButtonBox>

/*!
 * \brief The AccountDialog class
 */
class AccountDialog : public QDialog
{
  Q_OBJECT

public:
  /*!
   * \brief AccountDialog
   * \param account_model
   * \param parent
   */
  AccountDialog(QSqlRelationalTableModel* account_model, QWidget* parent = 0);
  /*!
   * \brief accept
   */
  virtual void accept();
private:
  /*!
   * \brief m_AccountModel
   */
  QSqlRelationalTableModel* m_AccountModel;
  /*!
   * \brief m_GroupBox
   */
  QGroupBox* m_GroupBox;
  /*!
   * \brief m_NameLineEdit
   */
  QLineEdit* m_NameLineEdit;
  /*!
   * \brief m_AccountTypeCombo
   */
  QComboBox* m_AccountTypeCombo;
  /*!
   * \brief m_InitialBalanceLineEdit
   */
  QLineEdit* m_InitialBalanceLineEdit;
  /*!
   * \brief m_ButtonBox
   */
  QDialogButtonBox* m_ButtonBox;
};

#endif // ACCOUNTDIALOG_HXX
