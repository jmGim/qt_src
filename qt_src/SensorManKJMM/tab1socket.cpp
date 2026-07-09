#include "tab1socket.h"
#include "ui_tab1socket.h"

Tab1Socket::Tab1Socket(QWidget *parent)
    : QWidget{parent}
    ,ui(new Ui::Tab1Socket)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    pKeyboard = new Keyboard();
    connect(pSocketClient, SIGNAL(socketRecvDataSig(QString)), this, SLOT(UpdateRecvDataSlot(QString)));
}

Tab1Socket::~Tab1Socket()
{
    delete ui;
}

void Tab1Socket::on_pPBServerConnect_clicked(bool checked)
{
    bool bFlag;
    if(checked)
    {
        pSocketClient->connectToServerSlot(bFlag);
        if(bFlag)
        {
            ui->pPBServerConnect->setText("서버 해제");
        }
    }
    else
    {
        pSocketClient->socketClosedServerSlot();
        ui->pPBServerConnect->setText("서버 연결");
    }

}


void Tab1Socket::on_pPBSend_clicked()
{
    QString strRecvId = ui->pLERecvId->text();
    QString strSendData = ui->pLESendMsg->text();
    if(strRecvId.isEmpty())
    {
        strSendData = "[ALLMSG]" + strSendData;
    } else {
        strSendData = "["+strRecvId+"]" + strSendData;
    }
    pSocketClient->socketWriteDataSlot(strSendData);
    ui->pLESendMsg->clear();
}

void Tab1Socket::UpdateRecvDataSlot(QString strRecvData)
{
    strRecvData.chop(1);    //'\n' remove
    QTime vQTime = QTime::currentTime();
    QString strTime = vQTime.toString() + " " + strRecvData;
    ui->pTERecvData->append(strTime);

    //[KSH_QT]LED@0xff
    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    //@KSH_QT@LED@0xff
    QStringList strList = strRecvData.split("@");
    //strList[0] = ""
    //strList[1] = "KSH_QT"
    //strList[2] = "LED"
    //strList[3] = "0xff"
    if(strList[2].compare("LED") == 0)
    {
        bool bFlag;
        int ledNo = strList[3].toInt(&bFlag, 16);
        if(bFlag)
            emit ledWriteSig(ledNo);
    } else if((strList[2].indexOf("LAMP") == 0) || (strList[2].indexOf("GAS") == 0))  { //LAMPON, LAMPOFF
        emit tab3RecvDataSig(strList) ;
    } else if((strList[2].indexOf("SENSOR") == 0))  {
        emit tab2RecvDataSig(strList) ;
        emit tab3RecvDataSig(strList) ;
    }
}
SocketClient *Tab1Socket::getpSocketClient()
{
    return pSocketClient;
}
void Tab1Socket::on_pLERecvId_selectionChanged()
{
    QLineEdit *pQLineEdit = (QLineEdit*)sender();
    pKeyboard->setLineEdit(pQLineEdit);
    pKeyboard->show();
}


void Tab1Socket::on_pLESendMsg_selectionChanged()
{
    QLineEdit *pQLineEdit = (QLineEdit*)sender();
    pKeyboard->setLineEdit(pQLineEdit);
    pKeyboard->show();
}

