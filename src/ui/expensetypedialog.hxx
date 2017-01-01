#ifndef EXPENSETYPEDIALOG_HXX
#define EXPENSETYPEDIALOG_HXX

#include <QObject>
#include <QDialog>
#include <QSqlTableModel>
#include <QGroupBox>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QColor>
#include <QPushButton>

class ExpenseTypeDialog : public QDialog
{
  Q_OBJECT

public:
  /*!
   * \brief ExpenseTypeDialog
   * \param expense_type_model
   * \param parent
   */
  ExpenseTypeDialog(QSqlTableModel* expense_type_model, QWidget* parent = 0);
  /*!
   * \brief accept
   */
  virtual void accept();
  /*!
   * \brief select_color
   */
  void select_color();
private:
  /*!
   * \brief m_ExpenseTypeModel
   */
  QSqlTableModel* m_ExpenseTypeModel;
  /*!
   * \brief m_GroupBox
   */
  QGroupBox* m_GroupBox;
  /*!
   * \brief m_NameLineEdit
   */
  QLineEdit* m_NameLineEdit;
  /*!
   * \brief m_ColorButton
   */
  QPushButton* m_ColorButton;
  /*!
   * \brief m_ButtonBox
   */
  QDialogButtonBox* m_ButtonBox;
  /*!
   * \brief m_Color
   */
  QColor m_Color;
};

#endif // EXPENSETYPEDIALOG_HXX
