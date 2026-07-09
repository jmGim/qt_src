
#ifndef Tab2Sensor_H
#define Tab2Sensor_H

#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QDate>
#include <QTime>
#include <QDebug>

namespace Ui {
class Tab2Sensor;
}

class Tab2Sensor : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2Sensor(QWidget *parent = nullptr);
    ~Tab2Sensor();
    void updateLastDateTime(bool);
private:
    Ui::Tab2Sensor *ui;
    QChart *pQChart;
    QLineSeries *pIlluLine;
    QLineSeries *pTempLine;
    QLineSeries *pHumiLine;
    QChartView *pQChartView;
    QDateTimeAxis *pQDateTimeAxis;
    QDateTime firstDateTime;
    QDateTime lastDateTime;

public slots:
    void tab2RecvDataSlot(QStringList);
private slots:
    void on_pPBChartClear_clicked();
};

#endif // Tab2Sensor_H
