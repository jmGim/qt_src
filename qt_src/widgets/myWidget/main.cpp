#include <QApplication>
//#include <QPushButton>
//#include <QLabel>
#include <mywidget.h>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MyWidget *pMyWidget = new MyWidget();
	pMyWidget->show();	
	return app.exec();
}
