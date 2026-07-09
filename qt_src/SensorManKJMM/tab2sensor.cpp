#include "tab2sensor.h"
#include "ui_tab2sensor.h"

Tab2Sensor::Tab2Sensor(QWidget *parent)
    : QWidget{parent}
    ,ui(new Ui::Tab2Sensor)
{
    ui->setupUi(this);
    pIlluLine = new QLineSeries(this);
    pIlluLine->setName("조도");

    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    pIlluLine->setPen(pen);

    pTempLine = new QLineSeries(this);
    pTempLine->setName("온도");
    QPen penTemp;
    penTemp.setWidth(2);
    penTemp.setBrush(Qt::blue);
    penTemp.setCapStyle(Qt::FlatCap);
    penTemp.setJoinStyle(Qt::MiterJoin);
    pTempLine->setPen(penTemp);

    pHumiLine = new QLineSeries(this);
    pHumiLine->setName("습도");

    pQChart = new QChart();
    pQChart->addSeries(pIlluLine);
    pQChart->addSeries(pTempLine);
    pQChart->addSeries(pHumiLine);
    pQChart->createDefaultAxes();
    pQChart->axes(Qt::Vertical).constFirst()->setRange(0,100);

    pQChartView = new QChartView(pQChart);
    pQChartView->setRenderHint(QPainter::Antialiasing);

    pQDateTimeAxis = new QDateTimeAxis;
    pQDateTimeAxis->setFormat("hh:mm");

    updateLastDateTime(false);

    ui->pChartViewLayout->layout()->addWidget(pQChartView);
    pQChartView->chart()->setAxisX(pQDateTimeAxis, pIlluLine);
    pQChartView->chart()->setAxisX(pQDateTimeAxis, pTempLine);
    pQChartView->chart()->setAxisX(pQDateTimeAxis, pHumiLine);

    // QDateTime dateTime = QDateTime::currentDateTime();
    // pIlluLine->append(dateTime.toMSecsSinceEpoch(), 30);
    // dateTime = dateTime.addSecs(60);
    // pIlluLine->append(dateTime.toMSecsSinceEpoch(), 80);
    // dateTime = dateTime.addSecs(60);
    // pIlluLine->append(dateTime.toMSecsSinceEpoch(), 50);
}

Tab2Sensor::~Tab2Sensor()
{
    delete ui;
}

void Tab2Sensor::updateLastDateTime(bool bFlag)
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
void Tab2Sensor::tab2RecvDataSlot(QStringList strList)
{
    //strList[1] = "HM_CON"
    //strList[2] = "SENSOR"
    //strList[3] = "10" //illu
    //strList[4] = "20.1" //temp
    //strList[5] = "30.2" //humi
    QDateTime dateTime = QDateTime::currentDateTime();
    pIlluLine->append(dateTime.toMSecsSinceEpoch(), strList[3].toInt());
    pTempLine->append(dateTime.toMSecsSinceEpoch(), strList[4].toDouble());
    pHumiLine->append(dateTime.toMSecsSinceEpoch(), strList[5].toDouble());
}
void Tab2Sensor::on_pPBChartClear_clicked()
{
    pIlluLine->clear();
    pTempLine->clear();
    pHumiLine->clear();
}

