/********************************************************************************
** Form generated from reading UI file 'tab3controlpannel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB3CONTROLPANNEL_H
#define UI_TAB3CONTROLPANNEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab3ControlPannel
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pPBLamp;
    QPushButton *pPBPlug;
    QFormLayout *formLayout;
    QLabel *label;

    void setupUi(QWidget *Tab3ControlPannel)
    {
        if (Tab3ControlPannel->objectName().isEmpty())
            Tab3ControlPannel->setObjectName("Tab3ControlPannel");
        Tab3ControlPannel->resize(564, 365);
        verticalLayout = new QVBoxLayout(Tab3ControlPannel);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(Tab3ControlPannel);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 547, 344));
        pPBLamp = new QPushButton(scrollAreaWidgetContents);
        pPBLamp->setObjectName("pPBLamp");
        pPBLamp->setGeometry(QRect(50, 70, 71, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/Images/light_off.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8(":/Images/Images/light_on.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pPBLamp->setIcon(icon);
        pPBLamp->setIconSize(QSize(70, 70));
        pPBLamp->setCheckable(true);
        pPBPlug = new QPushButton(scrollAreaWidgetContents);
        pPBPlug->setObjectName("pPBPlug");
        pPBPlug->setGeometry(QRect(210, 170, 71, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/Images/plug_off.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon1.addFile(QString::fromUtf8(":/Images/Images/plug_on.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pPBPlug->setIcon(icon1);
        pPBPlug->setIconSize(QSize(70, 70));
        pPBPlug->setCheckable(true);
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName("formLayout");
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/Images/room1.png")));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label->raise();
        pPBLamp->raise();
        pPBPlug->raise();

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Tab3ControlPannel);

        QMetaObject::connectSlotsByName(Tab3ControlPannel);
    } // setupUi

    void retranslateUi(QWidget *Tab3ControlPannel)
    {
        Tab3ControlPannel->setWindowTitle(QCoreApplication::translate("Tab3ControlPannel", "Form", nullptr));
        pPBLamp->setText(QString());
        pPBPlug->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tab3ControlPannel: public Ui_Tab3ControlPannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB3CONTROLPANNEL_H
