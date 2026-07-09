#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <tab1socket.h>
#include <tab2sensor.h>
#include <tab3sqlite.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget() override;

private:
    Ui::MainWidget *ui;
    Tab1Socket *pTab1Socket;
    Tab2Sensor *pTab2Sensor;
    Tab3Sqlite *pTab3Sqlite;

};
#endif // MAINWIDGET_H
