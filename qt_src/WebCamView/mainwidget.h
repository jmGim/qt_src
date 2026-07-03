#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QWebEngineView>
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
    QWebEngineView *pQWebEngineView0_0;
    QWebEngineView *pQWebEngineView0_1;
    QWebEngineView *pQWebEngineView1_0;
    QWebEngineView *pQWebEngineView1_1;
};
#endif // MAINWIDGET_H
