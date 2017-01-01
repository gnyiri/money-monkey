#ifndef CENTRALWIDGET_HXX
#define CENTRALWIDGET_HXX

#include <QWidget>
#include <QTabWidget>


/*!
 * \brief The CentralWidget class
 */
class CentralWidget : public QWidget
{
  Q_OBJECT
public:
  /*!
   * \brief CentralWidget
   * \param parent
   */
  explicit CentralWidget(QWidget *parent = 0);

signals:
public slots:
private:
  /*!
   * \brief m_TabWidget
   */
  QTabWidget* m_TabWidget;
};

#endif // CENTRALWIDGET_HXX
