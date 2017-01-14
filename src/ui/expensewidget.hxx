#ifndef EXPENSEWIDGET_HXX
#define EXPENSEWIDGET_HXX

#include "expensemodel.hxx"

#include <QWidget>
#include <QTableView>

class ExpenseWidget : public QWidget
{
  Q_OBJECT
public:
  /*!
   * \brief ExpenseWidget
   * \param parent
   */
  explicit ExpenseWidget(QWidget *parent = 0);
  /*!
   * \brief add_new_expense
   */
  void add_new_expense();
  /*!
   * \brief delete_expense
   */
  void delete_expense();

signals:

public slots:

private:
  /*!
   * \brief m_ExpenseModel
   */
  ExpenseModel* m_ExpenseModel;
  /*!
   * \brief m_ExpenseView
   */
  QTableView* m_ExpenseView;

};

#endif // EXPENSEWIDGET_HXX
