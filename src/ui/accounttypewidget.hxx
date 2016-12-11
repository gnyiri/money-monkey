#ifndef ACCOUNTTYPEVIEW_HXX
#define ACCOUNTTYPEVIEW_HXX

#include <QWidget>
#include <QTableView>
#include "accounttypemodel.hxx"

/*!
 * \brief The AccountTypeWidget class
 */
class AccountTypeWidget : public QWidget
{
  //Q_OBJECT

public:
  /*!
   * \brief AccountTypeWidget
   * \param parent
   */
  AccountTypeWidget(QWidget* parent = 0);
  /*!
   * \brief AccountTypeWidget
   */
  ~AccountTypeWidget();
  /*!
   * \brief add_new_account_type
   */
  void add_new_account_type();
  /*!
   * \brief delete_account_type
   */
  void delete_account_type();
private:
  /*!
   * \brief m_AccountTypeModel
   */
  AccountTypeModel* m_AccountTypeModel;
  /*!
   * \brief m_AccountTypeView
   */
  QTableView* m_AccountTypeView;
};

#endif // ACCOUNTTYPEVIEW_HXX
