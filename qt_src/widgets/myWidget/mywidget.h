#ifndef WIDGET_H
#define WIDGET_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

class MyWidget : public QWidget 
{
	Q_OBJECT
public:
	MyWidget(QWidget *parent = nullptr);
	~MyWidget();

private:
	QPushButton *pQPushButton;
	QLabel *pQLabel;

private slots:
	void myquit();	
	void myquit(bool);	
	void myslot(bool);	

signals:
	void mysignal();
	void mysignal(bool);
};

#endif
