#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPushButton *pQPushButton = new QPushButton("Quit", 0);	
	pQPushButton->resize(100, 50);
	pQPushButton->move(500,250);
	pQPushButton->show();

	QLabel *pQLabel = new QLabel("Hello", 0);
	pQLabel->show();

	QObject::connect(pQPushButton, SIGNAL(clicked()), &app, SLOT(quit()));
	return app.exec();
} 


