#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);


    pTab1Socket = new Tab1Socket(ui->pTab1);
    ui->pTab1->setLayout(pTab1Socket->layout());

    pTab2Sensor = new Tab2Sensor(ui->pTab2);
    ui->pTab2->setLayout(pTab2Sensor->layout());

    pTab3Sqlite = new Tab3Sqlite (ui->pTab3);
    ui->pTab3->setLayout(pTab3Sqlite->layout());


    ui->tabWidget->setCurrentIndex(6);

    connect(pTab1Socket, SIGNAL(socketWriteDataSig(QString)), pTab1Socket->getpSocketClient(), SLOT(socketWriteDataSlot(QString)));
    connect(pTab1Socket,SIGNAL(tab2RecvDataSig(QStringList)), pTab2Sensor, SLOT(tab2RecvDataSlot(QStringList)));
    connect(pTab1Socket,SIGNAL(tab3RecvDataSig(QStringList&)), pTab3Sqlite, SLOT(tab3RecvDataSlot(QStringList&)));
    
}

MainWidget::~MainWidget()
{
    delete ui;
}

