#ifndef TAB1DEVICECONTROL_H
#define TAB1DEVICECONTROL_H

#include <QWidget>
#include <QTimer>
#include <ledkeydev.h>
#include <QCheckBox>
#include <QButtonGroup>

namespace Ui {
class Tab1DeviceControl;
}

class Tab1DeviceControl : public QWidget
{
    Q_OBJECT

public:
    explicit Tab1DeviceControl(QWidget *parent = nullptr);
    ~Tab1DeviceControl();

private slots:
    void on_pDialLed_valueChanged(int value);

    void on_pPBTTimerStart_clicked(bool checked);
    void updateDialValueSlot();
    void on_pCBTimerValue_currentTextChanged(const QString &arg1);
    void updateCheckBoxSlot(int);
    void updateCheckBoxMouseSlot(int);

private:
    Ui::Tab1DeviceControl *ui;
    LedKeyDev *pLedKeyDev;
    QTimer *pQTimer;
    QCheckBox *pQCheckBox[8];
    QButtonGroup *pQButtonGroup;
    unsigned char lcdData;
    int keyCount;
};

#endif // TAB1DEVICECONTROL_H
