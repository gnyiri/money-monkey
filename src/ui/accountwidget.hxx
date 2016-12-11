#ifndef ACCOUNTWIDGET_HXX
#define ACCOUNTWIDGET_HXX

#include "accountmodel.hxx"

#include <QWidget>
#include <QTableView>


class AccountWidget : public QWidget
{
  Q_OBJECT
public:
  /*!
   * \brief AccountWidget
   * \param parent
   */
  explicit AccountWidget(QWidget *parent = 0);
  /*!
   * \brief add_new_account
   */
  void add_new_account();
  /*!
   * \brief delete_account
   */
  void delete_account();

private:
  /*!
   * \brief m_AccountTypeModel
   */
  AccountModel* m_AccountModel;
  /*!
   * \brief m_AccountTypeView
   */
  QTableView* m_AccountView;

signals:

public slots:
};

#endif // ACCOUNTWIDGET_HXX
