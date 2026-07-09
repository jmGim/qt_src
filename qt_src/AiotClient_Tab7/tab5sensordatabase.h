#ifndef TAB5SENSORDATABASE_H
#define TAB5SENSORDATABASE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QWidget>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QDate>
#include <QTime>
#include <QDebug>
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    #include <QChartView>
    #include <QLineSeries>
    #include <QDateTimeAxis>
    #include <QValueAxis>
#else
    #include <QtCharts/QChartView>
    #include <QtCharts/QChart>
    #include <QtCharts/QLineSeries>
    #include <QtCharts/QDateTimeAxis>
    #include <QtCharts/QValueAxis>
    QT_CHARTS_USE_NAMESPACE
#endif
/*
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QDate>
#include <QTime>
#include <QDebug>
*/

namespace Ui {
class Tab5SensorDatabase;
}

class Tab5SensorDatabase : public QWidget
{
    Q_OBJECT

public:
    explicit Tab5SensorDatabase(QWidget *parent = nullptr);
    ~Tab5SensorDatabase();
    void updateLastDateTimeSql(bool);

private:
    Ui::Tab5SensorDatabase *ui;
    QSqlDatabase qSqlDatabase;

    QLineSeries *illuLine;
    QChart *pQChart;
    QChartView *pQChartView;
    QDateTimeAxis *pQDateTimeAxis;
    QDateTime   firstDateTime;
    QDateTime   lastDateTime;

private slots:
    void tab5RecvDataSlot(QStringList& strList);
    void on_pPBDbSearch_clicked();
    void on_pPBDbDelete_clicked();

};

#endif // TAB5SENSORDATABASE_H
