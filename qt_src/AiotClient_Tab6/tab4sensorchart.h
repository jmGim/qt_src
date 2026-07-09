#ifndef TAB4SENSORCHART_H
#define TAB4SENSORCHART_H

#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QDate>
#include <QTime>
#include <QDebug>

namespace Ui {
class Tab4SensorChart;
}

class Tab4SensorChart : public QWidget
{
    Q_OBJECT

public:
    explicit Tab4SensorChart(QWidget *parent = nullptr);
    ~Tab4SensorChart();
    void updateLastDateTime(bool);
private:
    Ui::Tab4SensorChart *ui;
    QChart *pQChart;
    QLineSeries *pIlluLine;
    QChartView *pQChartView;
    QDateTimeAxis *pQDateTimeAxis;
    QDateTime firstDateTime;
    QDateTime lastDateTime;

public slots:
    void tab4RecvDataSlot(QStringList);
private slots:
    void on_pPBChartClear_clicked();
};

#endif // TAB4SENSORCHART_H
