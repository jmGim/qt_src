#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
//    connect(ui->pushButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(myslot()));
    connect(this, SIGNAL(mysignal()), qApp, SLOT(quit()));
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::myslot()
{
    emit mysignal();
    qDebug() << "myslot()";
//    qApp->quit();
}