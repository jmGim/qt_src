#include <mywidget.h>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
	pQPushButton = new QPushButton("Quit",this);
    pQPushButton->resize(100,20);
//    pQPushButton->move(500,250);
	pQPushButton->setCheckable(true);
    pQPushButton->show();

    pQLabel = new QLabel("Hello",this);
	pQLabel->resize(100,20);
	pQLabel->move(0,30);
	pQLabel->show();

	this->resize(300,200);
//    QObject::connect(pQPushButton,SIGNAL(clicked()), qApp, SLOT(quit()));
//   QObject::connect(pQPushButton,SIGNAL(clicked()), this, SLOT(myquit()));
   QObject::connect(pQPushButton,SIGNAL(clicked(bool)), this, SLOT(myquit(bool)));
//   connect(this,SIGNAL(mysignal()), qApp, SLOT(quit()));
   connect(this,SIGNAL(mysignal(bool)), this, SLOT(myslot(bool)));

}
MyWidget::~MyWidget()
{
}
void MyWidget::myslot(bool bFlag)
{
	if(bFlag)
	{
		pQLabel->setText("버턴이 On");
		qDebug() << "On"; 
	}
	else
	{
		pQLabel->setText("버턴이 Off");
		qDebug() << "Off"; 
	}
}
void MyWidget::myquit()
{
	if(pQPushButton->isChecked())
	{
		pQLabel->setText("버턴이 On");
		qDebug() << "On"; 
	}
	else
	{
		pQLabel->setText("버턴이 Off");
		qDebug() << "Off"; 
	}

	emit mysignal();
//	qApp->quit();
}
void MyWidget::myquit(bool bCheck)
{
	if(bCheck)
		pQLabel->setText("버턴이 On");
	else
		pQLabel->setText("버턴이 Off");

	emit mysignal(bCheck);
//	qApp->quit();
}
