#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QMainWindow>
#include "centralwidget.hxx"

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  /*!
   * \brief MainWindow CTOR
   * \param parent
   */
  MainWindow(QWidget *parent = 0);
  /*!
   * \brief MainWindow DTOR
   */
  ~MainWindow();
private:
  /*!
   * \brief build_ui
   */
  void build_ui();
  /*!
   * \brief init_database
   */
  void init_database();
  /*!
   * \brief m_CentralWidget
   */
  CentralWidget* m_CentralWidget;
};

#endif // MAINWINDOW_HXX
