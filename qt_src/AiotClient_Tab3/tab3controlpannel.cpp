#include "tab3controlpannel.h"
#include "ui_tab3controlpannel.h"

Tab3ControlPannel::Tab3ControlPannel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab3ControlPannel)
{
    ui->setupUi(this);
    paletteOn.setColor(ui->pPBLamp->backgroundRole(),QColor(255,0,0)); //Red
    paletteOff.setColor(ui->pPBLamp->backgroundRole(),QColor(0,0,255));//blue
    ui->pPBLamp->setPalette(paletteOff);
    ui->pPBPlug->setPalette(paletteOff);
}

Tab3ControlPannel::~Tab3ControlPannel()
{
    delete ui;
}

void Tab3ControlPannel::on_pPBLamp_clicked(bool checked)
{
    if(checked)
    {
        emit socketSendDataSig("[KSH_LIN]LAMPON");
        ui->pPBLamp->setChecked(false);
    } else {
        emit socketSendDataSig("[KSH_LIN]LAMPOFF");
        ui->pPBLamp->setChecked(true);
    }
}


void Tab3ControlPannel::on_pPBPlug_clicked(bool checked)
{

}

void Tab3ControlPannel::tab3RecvDataSlot(QStringList strList)
{
    if(strList[2] == "LAMPON") {
        ui->pPBLamp->setChecked(true);
        ui->pPBLamp->setPalette(paletteOn);
    } else if(strList[2] == "LAMPOFF") {
        ui->pPBLamp->setChecked(false);
        ui->pPBLamp->setPalette(paletteOff);
    }
}
