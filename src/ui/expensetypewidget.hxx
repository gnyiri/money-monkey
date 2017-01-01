#ifndef EXPENSETYPEWIDGET_HXX
#define EXPENSETYPEWIDGET_HXX

#include <QWidget>
#include <QTableView>

#include "expensetypemodel.hxx"

class ExpenseTypeWidget : public QWidget
{
  Q_OBJECT
public:
  /*!
   * \brief ExpenseTypeWidget
   * \param parent
   */
  explicit ExpenseTypeWidget(QWidget *parent = 0);
  /*!
   * \brief add_new_expense_type
   */
  void add_new_expense_type();
  /*!
   * \brief delete_expense_type
   */
  void delete_expense_type();

signals:

public slots:
private:
  /*!
   * \brief m_ExpenseTypeModel
   */
  ExpenseTypeModel* m_ExpenseTypeModel;
  /*!
   * \brief m_ExpenseTypeView
   */
  QTableView* m_ExpenseTypeView;
};

#endif // EXPENSETYPEWIDGET_HXX
