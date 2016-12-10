#ifndef CENTRALWIDGET_HXX
#define CENTRALWIDGET_HXX

#include <QWidget>
#include <QTabWidget>

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = 0);

signals:

public slots:
private:
    QTabWidget* m_TabWidget;
};

#endif // CENTRALWIDGET_HXX
