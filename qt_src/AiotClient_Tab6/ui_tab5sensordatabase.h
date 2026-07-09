/********************************************************************************
** Form generated from reading UI file 'tab5sensordatabase.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB5SENSORDATABASE_H
#define UI_TAB5SENSORDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab5SensorDatabase
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *pDateTimeEditFrom;
    QDateTimeEdit *pDateTimeEditTo;
    QVBoxLayout *verticalLayout;
    QTableWidget *pTBsensor;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pPBDbSearch;
    QPushButton *pPBDbDelete;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *pChartViewLayout;

    void setupUi(QWidget *Tab5SensorDatabase)
    {
        if (Tab5SensorDatabase->objectName().isEmpty())
            Tab5SensorDatabase->setObjectName("Tab5SensorDatabase");
        Tab5SensorDatabase->resize(607, 379);
        verticalLayout_6 = new QVBoxLayout(Tab5SensorDatabase);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pDateTimeEditFrom = new QDateTimeEdit(Tab5SensorDatabase);
        pDateTimeEditFrom->setObjectName("pDateTimeEditFrom");
        pDateTimeEditFrom->setEnabled(true);
        pDateTimeEditFrom->setFrame(true);
        pDateTimeEditFrom->setDateTime(QDateTime(QDate(2026, 7, 7), QTime(9, 0, 0)));

        horizontalLayout->addWidget(pDateTimeEditFrom);

        pDateTimeEditTo = new QDateTimeEdit(Tab5SensorDatabase);
        pDateTimeEditTo->setObjectName("pDateTimeEditTo");
        pDateTimeEditTo->setDateTime(QDateTime(QDate(2026, 7, 8), QTime(0, 0, 0)));

        horizontalLayout->addWidget(pDateTimeEditTo);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pTBsensor = new QTableWidget(Tab5SensorDatabase);
        if (pTBsensor->columnCount() < 3)
            pTBsensor->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        pTBsensor->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        pTBsensor->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        pTBsensor->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        pTBsensor->setObjectName("pTBsensor");
        pTBsensor->horizontalHeader()->setDefaultSectionSize(50);

        verticalLayout->addWidget(pTBsensor);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);

        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pPBDbSearch = new QPushButton(Tab5SensorDatabase);
        pPBDbSearch->setObjectName("pPBDbSearch");

        horizontalLayout_2->addWidget(pPBDbSearch);

        pPBDbDelete = new QPushButton(Tab5SensorDatabase);
        pPBDbDelete->setObjectName("pPBDbDelete");

        horizontalLayout_2->addWidget(pPBDbDelete);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        pChartViewLayout = new QVBoxLayout();
        pChartViewLayout->setObjectName("pChartViewLayout");

        verticalLayout_4->addLayout(pChartViewLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 9);

        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_4);


        retranslateUi(Tab5SensorDatabase);

        QMetaObject::connectSlotsByName(Tab5SensorDatabase);
    } // setupUi

    void retranslateUi(QWidget *Tab5SensorDatabase)
    {
        Tab5SensorDatabase->setWindowTitle(QCoreApplication::translate("Tab5SensorDatabase", "Form", nullptr));
        pDateTimeEditFrom->setDisplayFormat(QCoreApplication::translate("Tab5SensorDatabase", "yyyy M. d. Ap h:mm", nullptr));
        pDateTimeEditTo->setDisplayFormat(QCoreApplication::translate("Tab5SensorDatabase", "yyyy. M. d. Ap h:mm", nullptr));
        QTableWidgetItem *___qtablewidgetitem = pTBsensor->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Tab5SensorDatabase", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = pTBsensor->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Tab5SensorDatabase", "\353\202\240\354\247\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = pTBsensor->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Tab5SensorDatabase", "\354\241\260\353\217\204", nullptr));
        pPBDbSearch->setText(QCoreApplication::translate("Tab5SensorDatabase", "\354\241\260\355\232\214", nullptr));
        pPBDbDelete->setText(QCoreApplication::translate("Tab5SensorDatabase", "\354\202\255\354\240\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab5SensorDatabase: public Ui_Tab5SensorDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB5SENSORDATABASE_H
