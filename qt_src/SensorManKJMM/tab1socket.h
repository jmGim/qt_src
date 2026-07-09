#ifndef Tab1Socket_H
#define Tab1Socket_H

#include <QWidget>
#include <socketclient.h>
#include <QTime>
#include <QLineEdit>
#include "keyboard.h"

namespace Ui {
class Tab1Socket;
}

class Tab1Socket : public QWidget
{
    Q_OBJECT

public:
    explicit Tab1Socket(QWidget *parent = nullptr);
    ~Tab1Socket();
    SocketClient *getpSocketClient();

private slots:
    void on_pPBServerConnect_clicked(bool checked);
    void on_pPBSend_clicked();
    void UpdateRecvDataSlot(QString);

    void on_pLERecvId_selectionChanged();

    void on_pLESendMsg_selectionChanged();

private:
    Ui::Tab1Socket *ui;
    SocketClient *pSocketClient;
    Keyboard *pKeyboard;

signals:
    void ledWriteSig(int);
    void tab1RecvDataSig(QStringList);
    void tab2RecvDataSig(QStringList);
    void tab3RecvDataSig(QStringList&);
};

#endif // Tab1Socket_H
