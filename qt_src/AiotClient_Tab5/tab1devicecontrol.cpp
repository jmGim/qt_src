#include "tab1devicecontrol.h"
#include "ui_tab1devicecontrol.h"

Tab1DeviceControl::Tab1DeviceControl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab1DeviceControl)
{
    ui->setupUi(this);
    pLedKeyDev = new LedKeyDev(this);
    pQTimer = new QTimer(this);
    pQButtonGroup = new QButtonGroup(this);
    lcdData = 0;

    int rowCount = ui->gridLayout->rowCount();
    int columCount = ui->gridLayout->columnCount();
    keyCount = rowCount * columCount;
    for(int i=0;i<rowCount;i++)
    {
        for(int j=0;j<columCount;j++)
        {
            pQCheckBox[--keyCount] = dynamic_cast<QCheckBox*>(ui->gridLayout->itemAtPosition(i,j)->widget());
        }
    }
    keyCount = rowCount * columCount;
    for(int i=0;i<keyCount;i++)
    {
        pQButtonGroup->addButton(pQCheckBox[i],i+1);
    }
    pQButtonGroup->setExclusive(false);

#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    connect(pQButtonGroup, SIGNAL(idClicked(int)), this , SLOT(updateCheckBoxMouseSlot(int)));
#else
    connect(pQButtonGroup, SIGNAL(buttonClicked(int)), this , SLOT(updateCheckBoxMouseSlot(int)));
#endif

    connect(ui->pDialLed, SIGNAL(valueChanged(int)), pLedKeyDev, SLOT(writeLedDataSlot(int)));
    connect(ui->pPBQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pQTimer, SIGNAL(timeout()), this, SLOT(updateDialValueSlot()));
    connect(pLedKeyDev, SIGNAL(updateKeyDataSig(int)), this, SLOT(updateCheckBoxSlot(int)));
}

Tab1DeviceControl::~Tab1DeviceControl()
{
    delete ui;
}

void Tab1DeviceControl::on_pPBTimerStart_clicked(bool checked)
{
    if(checked)
    {
        ui->pPBTimerStart->setText("TimerStop");
        QString strValue = ui->pCBTimerValue->currentText();
        pQTimer->start(strValue.toInt());
    }
    else
    {
        ui->pPBTimerStart->setText("TimerStart");
        pQTimer->stop();
    }
}

void Tab1DeviceControl::updateDialValueSlot()
{
    int dialValue = ui->pDialLed->value();
    dialValue++;
    if(dialValue > ui->pDialLed->maximum())
        dialValue = 0;
    ui->pDialLed->setValue(dialValue);
}

void Tab1DeviceControl::on_pCBTimerValue_currentTextChanged(const QString &arg1)
{
    if(pQTimer->isActive())
    {
        pQTimer->stop();
        pQTimer->start(arg1.toInt());
    }
}

void Tab1DeviceControl::updateCheckBoxSlot(int keyNo)
{
//    qDebug() << " keyNo : " << keyNo << " keyCount : " << keyCount;
    lcdData = lcdData ^ (0x01 << (keyNo -1)) ;
    ui->pLNKey->display(lcdData);

    for(int i=0;i<keyCount;i++)
    {
        if(keyNo == i+1)
        {
            if(pQCheckBox[i]->isChecked())
                pQCheckBox[i]->setChecked(false);
            else
                pQCheckBox[i]->setChecked(true);
        }
    }
}
void Tab1DeviceControl::updateCheckBoxMouseSlot(int keyNo)
{
    lcdData = lcdData ^ (0x01 << (keyNo -1)) ;
    ui->pLNKey->display(lcdData);
    QString strSendLed = "[KSH_QT]LED@0x"+QString::number(lcdData,16);
    emit socketWriteDataSig(strSendLed);
}
QDial *Tab1DeviceControl::getpDialLed()
{
    return ui->pDialLed;
}