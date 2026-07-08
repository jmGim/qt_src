/********************************************************************************
** Form generated from reading UI file 'tab1devicecontrol.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1DEVICECONTROL_H
#define UI_TAB1DEVICECONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1DeviceControl
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pPBTimerStart;
    QComboBox *pCBTimerValue;
    QPushButton *pPBQuit;
    QHBoxLayout *horizontalLayout_2;
    QDial *pDialLed;
    QLCDNumber *pLNLed;
    QHBoxLayout *horizontalLayout_3;
    QProgressBar *pPBLed;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QCheckBox *pCBkey6;
    QCheckBox *pCBkey8;
    QCheckBox *pCBkey7;
    QCheckBox *pCBkey5;
    QCheckBox *pCBkey4;
    QCheckBox *pCBkey3;
    QCheckBox *pCBkey2;
    QCheckBox *pCBkey1;
    QLCDNumber *pLNKey;

    void setupUi(QWidget *Tab1DeviceControl)
    {
        if (Tab1DeviceControl->objectName().isEmpty())
            Tab1DeviceControl->setObjectName("Tab1DeviceControl");
        Tab1DeviceControl->resize(511, 385);
        verticalLayout_2 = new QVBoxLayout(Tab1DeviceControl);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pPBTimerStart = new QPushButton(Tab1DeviceControl);
        pPBTimerStart->setObjectName("pPBTimerStart");
        pPBTimerStart->setCheckable(true);

        horizontalLayout->addWidget(pPBTimerStart);

        pCBTimerValue = new QComboBox(Tab1DeviceControl);
        pCBTimerValue->addItem(QString());
        pCBTimerValue->addItem(QString());
        pCBTimerValue->addItem(QString());
        pCBTimerValue->addItem(QString());
        pCBTimerValue->addItem(QString());
        pCBTimerValue->setObjectName("pCBTimerValue");

        horizontalLayout->addWidget(pCBTimerValue);

        pPBQuit = new QPushButton(Tab1DeviceControl);
        pPBQuit->setObjectName("pPBQuit");

        horizontalLayout->addWidget(pPBQuit);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pDialLed = new QDial(Tab1DeviceControl);
        pDialLed->setObjectName("pDialLed");
        pDialLed->setMaximum(255);
        pDialLed->setWrapping(true);
        pDialLed->setNotchesVisible(true);

        horizontalLayout_2->addWidget(pDialLed);

        pLNLed = new QLCDNumber(Tab1DeviceControl);
        pLNLed->setObjectName("pLNLed");
        pLNLed->setDigitCount(2);
        pLNLed->setMode(QLCDNumber::Mode::Hex);
        pLNLed->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);

        horizontalLayout_2->addWidget(pLNLed);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pPBLed = new QProgressBar(Tab1DeviceControl);
        pPBLed->setObjectName("pPBLed");
        pPBLed->setMaximum(255);
        pPBLed->setValue(0);

        horizontalLayout_3->addWidget(pPBLed);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pCBkey6 = new QCheckBox(Tab1DeviceControl);
        pCBkey6->setObjectName("pCBkey6");

        gridLayout->addWidget(pCBkey6, 0, 2, 1, 1);

        pCBkey8 = new QCheckBox(Tab1DeviceControl);
        pCBkey8->setObjectName("pCBkey8");

        gridLayout->addWidget(pCBkey8, 0, 0, 1, 1);

        pCBkey7 = new QCheckBox(Tab1DeviceControl);
        pCBkey7->setObjectName("pCBkey7");

        gridLayout->addWidget(pCBkey7, 0, 1, 1, 1);

        pCBkey5 = new QCheckBox(Tab1DeviceControl);
        pCBkey5->setObjectName("pCBkey5");

        gridLayout->addWidget(pCBkey5, 0, 3, 1, 1);

        pCBkey4 = new QCheckBox(Tab1DeviceControl);
        pCBkey4->setObjectName("pCBkey4");

        gridLayout->addWidget(pCBkey4, 1, 0, 1, 1);

        pCBkey3 = new QCheckBox(Tab1DeviceControl);
        pCBkey3->setObjectName("pCBkey3");

        gridLayout->addWidget(pCBkey3, 1, 1, 1, 1);

        pCBkey2 = new QCheckBox(Tab1DeviceControl);
        pCBkey2->setObjectName("pCBkey2");

        gridLayout->addWidget(pCBkey2, 1, 2, 1, 1);

        pCBkey1 = new QCheckBox(Tab1DeviceControl);
        pCBkey1->setObjectName("pCBkey1");

        gridLayout->addWidget(pCBkey1, 1, 3, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        pLNKey = new QLCDNumber(Tab1DeviceControl);
        pLNKey->setObjectName("pLNKey");
        pLNKey->setDigitCount(2);
        pLNKey->setMode(QLCDNumber::Mode::Hex);
        pLNKey->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);

        horizontalLayout_4->addWidget(pLNKey);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 4);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Tab1DeviceControl);
        QObject::connect(pDialLed, &QDial::valueChanged, pLNLed, qOverload<int>(&QLCDNumber::display));
        QObject::connect(pDialLed, &QDial::valueChanged, pPBLed, &QProgressBar::setValue);

        QMetaObject::connectSlotsByName(Tab1DeviceControl);
    } // setupUi

    void retranslateUi(QWidget *Tab1DeviceControl)
    {
        Tab1DeviceControl->setWindowTitle(QCoreApplication::translate("Tab1DeviceControl", "Form", nullptr));
        pPBTimerStart->setText(QCoreApplication::translate("Tab1DeviceControl", "TimerStart", nullptr));
        pCBTimerValue->setItemText(0, QCoreApplication::translate("Tab1DeviceControl", "50", nullptr));
        pCBTimerValue->setItemText(1, QCoreApplication::translate("Tab1DeviceControl", "100", nullptr));
        pCBTimerValue->setItemText(2, QCoreApplication::translate("Tab1DeviceControl", "500", nullptr));
        pCBTimerValue->setItemText(3, QCoreApplication::translate("Tab1DeviceControl", "1000", nullptr));
        pCBTimerValue->setItemText(4, QCoreApplication::translate("Tab1DeviceControl", "2000", nullptr));

        pPBQuit->setText(QCoreApplication::translate("Tab1DeviceControl", "Quit", nullptr));
        pCBkey6->setText(QCoreApplication::translate("Tab1DeviceControl", "6", nullptr));
        pCBkey8->setText(QCoreApplication::translate("Tab1DeviceControl", "8", nullptr));
        pCBkey7->setText(QCoreApplication::translate("Tab1DeviceControl", "7", nullptr));
        pCBkey5->setText(QCoreApplication::translate("Tab1DeviceControl", "5", nullptr));
        pCBkey4->setText(QCoreApplication::translate("Tab1DeviceControl", "4", nullptr));
        pCBkey3->setText(QCoreApplication::translate("Tab1DeviceControl", "3", nullptr));
        pCBkey2->setText(QCoreApplication::translate("Tab1DeviceControl", "2", nullptr));
        pCBkey1->setText(QCoreApplication::translate("Tab1DeviceControl", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab1DeviceControl: public Ui_Tab1DeviceControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1DEVICECONTROL_H
