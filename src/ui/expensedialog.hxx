#ifndef EXPENSEDIALOG_HXX
#define EXPENSEDIALOG_HXX

#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QLineEdit>
#include <QComboBox>
#include <QGroupBox>
#include <QDialogButtonBox>

class ExpenseDialog : public QDialog
{
  Q_OBJECT

public:
  /*!
   * \brief ExpenseDialog
   * \param expense_model
   * \param parent
   */
  ExpenseDialog(QSqlRelationalTableModel* expense_model, QWidget* parent = 0);
  /*!
   * \brief accept
   */
  virtual void accept();
private:
  /*!
   * \brief m_ExpenseModel
   */
  QSqlRelationalTableModel* m_ExpenseModel;
  /*!
   * \brief m_GroupBox
   */
  QGroupBox* m_GroupBox;
  /*!
   * \brief m_NameLineEdit
   */
  QLineEdit* m_NameLineEdit;
  /*!
   * \brief m_ButtonBox
   */
  QDialogButtonBox* m_ButtonBox;
};

#endif // EXPENSEDIALOG_HXX
