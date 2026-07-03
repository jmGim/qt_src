/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout0_0;
    QVBoxLayout *verticalLayout0_1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout1_0;
    QVBoxLayout *verticalLayout1_1;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(500, 400);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout0_0 = new QVBoxLayout();
        verticalLayout0_0->setObjectName("verticalLayout0_0");

        horizontalLayout->addLayout(verticalLayout0_0);

        verticalLayout0_1 = new QVBoxLayout();
        verticalLayout0_1->setObjectName("verticalLayout0_1");

        horizontalLayout->addLayout(verticalLayout0_1);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout1_0 = new QVBoxLayout();
        verticalLayout1_0->setObjectName("verticalLayout1_0");

        horizontalLayout_2->addLayout(verticalLayout1_0);

        verticalLayout1_1 = new QVBoxLayout();
        verticalLayout1_1->setObjectName("verticalLayout1_1");

        horizontalLayout_2->addLayout(verticalLayout1_1);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_5);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
