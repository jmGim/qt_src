#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    pTab1DeviceControl = new Tab1DeviceControl(ui->pTab1);
    ui->pTab1->setLayout(pTab1DeviceControl->layout());

    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);
    ui->pTab2->setLayout(pTab2SocketClient->layout());

    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    ui->pTab3->setLayout(pTab3ControlPannel->layout());

    ui->tabWidget->setCurrentIndex(2);

    connect(pTab2SocketClient, SIGNAL(ledWriteSig(int)), pTab1DeviceControl->getpDialLed(),SLOT(setValue(int)));
    connect(pTab1DeviceControl, SIGNAL(socketWriteDataSig(QString)), pTab2SocketClient->getpSocketClient(), SLOT(socketWriteDataSlot(QString)));
    connect(pTab3ControlPannel, SIGNAL(socketSendDataSig(QString)), pTab2SocketClient->getpSocketClient(), SLOT(socketWriteDataSlot(QString)));
    connect(pTab2SocketClient,SIGNAL(tab3RecvDataSig(QStringList)), pTab3ControlPannel, SLOT(tab3RecvDataSlot(QStringList)));
}

MainWidget::~MainWidget()
{
    delete ui;
}

