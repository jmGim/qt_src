#include "tab4sensorchart.h"
#include "ui_tab4sensorchart.h"

Tab4SensorChart::Tab4SensorChart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab4SensorChart)
{
    ui->setupUi(this);
    pIlluLine = new QLineSeries(this);
    pIlluLine->setName("Illu");

    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    pIlluLine->setPen(pen);

    pQChart = new QChart();
    pQChart->addSeries(pIlluLine);
    pQChart->createDefaultAxes();
    pQChart->axes(Qt::Vertical).constFirst()->setRange(0,100);

    pQChartView = new QChartView(pQChart);
    pQChartView->setRenderHint(QPainter::Antialiasing);

    pQDateTimeAxis = new QDateTimeAxis;
    pQDateTimeAxis->setFormat("hh:mm");

    updateLastDateTime(false);

    ui->pChartViewLayout->layout()->addWidget(pQChartView);
    pQChartView->chart()->setAxisX(pQDateTimeAxis, pIlluLine);

    // QDateTime dateTime = QDateTime::currentDateTime();
    // pIlluLine->append(dateTime.toMSecsSinceEpoch(), 30);
    // dateTime = dateTime.addSecs(60);
    // pIlluLine->append(dateTime.toMSecsSinceEpoch(), 80);
    // dateTime = dateTime.addSecs(60);
    // pIlluLine->append(dateTime.toMSecsSinceEpoch(), 50);
}

Tab4SensorChart::~Tab4SensorChart()
{
    delete ui;
}

void Tab4SensorChart::updateLastDateTime(bool bFlag)
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    if(!bFlag) {
        firstDateTime.setDate(date);
        firstDateTime.setTime(time);
    }
    lastDateTime.setDate(date);
    lastDateTime.setTime(time.addSecs(10*60));
    pQDateTimeAxis->setRange(firstDateTime, lastDateTime);
}
void Tab4SensorChart::tab4RecvDataSlot(QStringList strList)
{
    //strList[1] = "HM_CON"
    //strList[2] = "SENSOR"
    //strList[3] = "10" //illu
    //strList[4] = "20.1" //temp
    //strList[5] = "30.2" //humi
    QDateTime dateTime = QDateTime::currentDateTime();
    pIlluLine->append(dateTime.toMSecsSinceEpoch(), strList[3].toInt());
}
void Tab4SensorChart::on_pPBChartClear_clicked()
{
    pIlluLine->clear();
}

