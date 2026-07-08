#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    pQWebEngineView0_0 = new QWebEngineView(this);
//    pQWebEngineView->load(QUrl("https://www.naver.com"));
    pQWebEngineView0_0->load(QUrl("http://10.10.16.252:8080/?action=stream"));
    ui->verticalLayout0_0->addWidget(pQWebEngineView0_0);

    pQWebEngineView0_1 = new QWebEngineView(this);
    pQWebEngineView0_1->load(QUrl("http://10.10.16.252:8080/?action=stream"));
    ui->verticalLayout0_1->addWidget(pQWebEngineView0_1);

    pQWebEngineView1_0 = new QWebEngineView(this);
    pQWebEngineView1_0->load(QUrl("http://10.10.16.252:8080/?action=stream"));
    ui->verticalLayout1_0->addWidget(pQWebEngineView1_0);

    pQWebEngineView1_1 = new QWebEngineView(this);
    pQWebEngineView1_1->load(QUrl("http://10.10.16.252:8080/?action=stream"));
    ui->verticalLayout1_1->addWidget(pQWebEngineView1_1);
}

MainWidget::~MainWidget()
{
    delete ui;
}
