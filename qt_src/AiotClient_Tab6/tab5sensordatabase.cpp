#include "tab5sensordatabase.h"
#include "ui_tab5sensordatabase.h"

Tab5SensorDatabase::Tab5SensorDatabase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab5SensorDatabase)
{
    ui->setupUi(this);
    qSqlDatabase =QSqlDatabase::addDatabase("QSQLITE");
    qSqlDatabase.setDatabaseName("aiot.db");
    if(qSqlDatabase.open())
        qDebug() << "Success DB Connection";
    else
        qDebug() << "Fail DB Connection";
    QString strQuery =  "create table sensor_tb ("
                        "name varchar(10),"
                        "date DATETIME primary key,"
                        "illu varchar(10))";
    QSqlQuery qSqlQuery;
    if(qSqlQuery.exec(strQuery))
        qDebug() << "Create Table";


    illuLine = new QLineSeries(this);
    illuLine->setName("조도");

    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    illuLine->setPen(pen);

    pQChart = new QChart();
    pQChart->addSeries(illuLine);

    pQChart->createDefaultAxes();
    pQChart->axes(Qt::Vertical).constFirst()->setRange(0,100);

    pQChartView = new QChartView(pQChart);

    pQDateTimeAxis = new QDateTimeAxis;
    pQDateTimeAxis->setFormat("hh:mm");

    updateLastDateTimeSql(false);

    ui->pChartViewLayout->layout()->addWidget(pQChartView);
    pQChartView->chart()->setAxisX(pQDateTimeAxis, illuLine);
}

Tab5SensorDatabase::~Tab5SensorDatabase()
{
    delete ui;
}

void Tab5SensorDatabase::updateLastDateTimeSql(bool bFlag)
{
    QDateTime fromDateTime = ui->pDateTimeEditFrom->dateTime();
    QString strFromDateTime = fromDateTime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime toDateTime = ui->pDateTimeEditTo->dateTime();
    QString strToDateTime = toDateTime.toString("yyyy/MM/dd hh:mm:ss");

    QString strQuery = "select * from sensor_tb where '" + strFromDateTime + "' <= date AND date <= '" + strToDateTime + "'";
    QSqlQuery sqlQuery;
    if(sqlQuery.exec(strQuery))
    {
            sqlQuery.first();
            firstDateTime = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");
            sqlQuery.last();
            lastDateTime = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");
    }
    if(!firstDateTime.isValid())
        firstDateTime = QDateTime::fromString(strFromDateTime, "yyyy/MM/dd hh:mm:ss");
    if(!lastDateTime.isValid())
        lastDateTime = QDateTime::fromString(strToDateTime, "yyyy/MM/dd hh:mm:ss");
    pQDateTimeAxis->setRange(firstDateTime,lastDateTime);
}

void Tab5SensorDatabase::tab5RecvDataSlot(QStringList& strList)
{
    //    qDebug() << strList[2];
    //    qDebug() << strList[3];
    QDateTime dateTime = QDateTime::currentDateTime();
    QString name = strList[1];
    QString strIllu = strList[3];  //조도

    QString strQuery = "insert into sensor_tb(name, date, illu) values('" + name + "' , '" + dateTime.toString("yyyy/MM/dd hh:mm:ss") + "' , '" + strIllu + "') ";
    QSqlQuery qSqlQuery;
    if(qSqlQuery.exec(strQuery))
        qDebug() << "Insert Query Ok";
 //   illuLine->append(dateTime.toMSecsSinceEpoch(), strIllu.toInt());
}
void Tab5SensorDatabase::on_pPBDbSearch_clicked()
{

    ui->pTBsensor->clearContents();
    illuLine->clear();

    int rowCount = 0;
    QDateTime fromDateTime = ui->pDateTimeEditFrom->dateTime();
    QString strFromDateTime = fromDateTime.toString("yyyy/MM/dd hh:mm:ss");

    QDateTime toDateTime = ui->pDateTimeEditTo->dateTime();
    QString strToDateTime = toDateTime.toString("yyyy/MM/dd hh:mm:ss");

    updateLastDateTimeSql(false);

    QString strQuery = " select * from sensor_tb where '" + strFromDateTime + "' <= date AND date < '" + strToDateTime + "' ";
    QSqlQuery qSqlQuery;
    if(qSqlQuery.exec(strQuery))
    {
        qDebug() << "Select Query Ok";
        while(qSqlQuery.next())
        {
            QTableWidgetItem *pQTableWidgetItemId = new QTableWidgetItem();
            QTableWidgetItem *pQTableWidgetItemDate = new QTableWidgetItem();
            QTableWidgetItem *pQTableWidgetItemIllu = new QTableWidgetItem();

            pQTableWidgetItemId->setText(qSqlQuery.value("name").toString());
            pQTableWidgetItemDate->setText(qSqlQuery.value("date").toString());
            pQTableWidgetItemIllu->setText(qSqlQuery.value("illu").toString());

            ui->pTBsensor->setRowCount(rowCount+1);
            ui->pTBsensor->setItem(rowCount, 0, pQTableWidgetItemId);
            ui->pTBsensor->setItem(rowCount, 1, pQTableWidgetItemDate);
            ui->pTBsensor->setItem(rowCount, 2, pQTableWidgetItemIllu);

            QDateTime xValue = QDateTime::fromString(pQTableWidgetItemDate->text(), "yyyy/MM/dd hh:mm:ss");
            illuLine->append(xValue.toMSecsSinceEpoch(), pQTableWidgetItemIllu->text().toInt());
//            qDebug() << " illu : " << pQTableWidgetItemIllu->text().toInt();

            rowCount++;
        }
        ui->pTBsensor->resizeColumnToContents(0);
        ui->pTBsensor->resizeColumnToContents(1);
        ui->pTBsensor->resizeColumnToContents(2);
    }

}


void Tab5SensorDatabase::on_pPBDbDelete_clicked()
{
    QDateTime fromDateTime = ui->pDateTimeEditFrom->dateTime();
    QString strFromDateTime = fromDateTime.toString("yyyy/MM/dd hh:mm:ss");

    QDateTime toDateTime = ui->pDateTimeEditTo->dateTime();
    QString strToDateTime = toDateTime.toString("yyyy/MM/dd hh:mm:ss");

    QString strQuery = "delete from sensor_tb where '" + strFromDateTime + "' <= date AND date < '" + strToDateTime + "' ";
    QSqlQuery qSqlQuery;
    if(qSqlQuery.exec(strQuery))
    {
        qDebug() << "delete query ok";
    }

    ui->pTBsensor->clearContents();
    illuLine->clear();
}

