/********************************************************************************
** Form generated from reading UI file 'tab2socketclient.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB2SOCKETCLIENT_H
#define UI_TAB2SOCKETCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab2SocketClient
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pPBRecvDataClear;
    QPushButton *pPBServerConnect;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *pTERecvData;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pLERecvId;
    QLineEdit *pLESendMsg;
    QPushButton *pPBSend;

    void setupUi(QWidget *Tab2SocketClient)
    {
        if (Tab2SocketClient->objectName().isEmpty())
            Tab2SocketClient->setObjectName("Tab2SocketClient");
        Tab2SocketClient->resize(503, 402);
        verticalLayout_2 = new QVBoxLayout(Tab2SocketClient);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Tab2SocketClient);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pPBRecvDataClear = new QPushButton(Tab2SocketClient);
        pPBRecvDataClear->setObjectName("pPBRecvDataClear");

        horizontalLayout->addWidget(pPBRecvDataClear);

        pPBServerConnect = new QPushButton(Tab2SocketClient);
        pPBServerConnect->setObjectName("pPBServerConnect");
        pPBServerConnect->setCheckable(true);

        horizontalLayout->addWidget(pPBServerConnect);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pTERecvData = new QTextEdit(Tab2SocketClient);
        pTERecvData->setObjectName("pTERecvData");

        horizontalLayout_2->addWidget(pTERecvData);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pLERecvId = new QLineEdit(Tab2SocketClient);
        pLERecvId->setObjectName("pLERecvId");

        horizontalLayout_3->addWidget(pLERecvId);

        pLESendMsg = new QLineEdit(Tab2SocketClient);
        pLESendMsg->setObjectName("pLESendMsg");

        horizontalLayout_3->addWidget(pLESendMsg);

        pPBSend = new QPushButton(Tab2SocketClient);
        pPBSend->setObjectName("pPBSend");

        horizontalLayout_3->addWidget(pPBSend);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 7);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Tab2SocketClient);
        QObject::connect(pPBRecvDataClear, &QPushButton::clicked, pTERecvData, qOverload<>(&QTextEdit::clear));
        QObject::connect(pLESendMsg, &QLineEdit::returnPressed, pPBSend, qOverload<>(&QPushButton::click));

        QMetaObject::connectSlotsByName(Tab2SocketClient);
    } // setupUi

    void retranslateUi(QWidget *Tab2SocketClient)
    {
        Tab2SocketClient->setWindowTitle(QCoreApplication::translate("Tab2SocketClient", "Form", nullptr));
        label->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240 \353\215\260\354\235\264\355\204\260", nullptr));
        pPBRecvDataClear->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240 \354\202\255\354\240\234", nullptr));
        pPBServerConnect->setText(QCoreApplication::translate("Tab2SocketClient", "\354\204\234\353\262\204 \354\227\260\352\262\260", nullptr));
        pPBSend->setText(QCoreApplication::translate("Tab2SocketClient", "\354\206\241\354\213\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab2SocketClient: public Ui_Tab2SocketClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2SOCKETCLIENT_H
