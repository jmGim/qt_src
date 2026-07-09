
///////////////////////
#ifndef Tab3Sqlite_H
#define Tab3Sqlite_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QDate>
#include <QTime>
#include <QDebug>

namespace Ui {
class Tab3Sqlite;
}

class Tab3Sqlite : public QWidget
{
    Q_OBJECT

public:
    explicit Tab3Sqlite(QWidget *parent = nullptr);
    ~Tab3Sqlite();
    void updateLastDateTimeSql(bool);

private:
    Ui::Tab3Sqlite *ui;
    QSqlDatabase qSqlDatabase;

    QLineSeries *illuLine;
    QLineSeries *tempLine;
    QLineSeries *humiLine;
    QChart *pQChart;
    QChartView *pQChartView;
    QDateTimeAxis *pQDateTimeAxis;
    QDateTime   firstDateTime;
    QDateTime   lastDateTime;

private slots:
    void tab3RecvDataSlot(QStringList& strList);
    void on_pPBDbSearch_clicked();
    void on_pPBDbDelete_clicked();

};

#endif // Tab3Sqlite_H

