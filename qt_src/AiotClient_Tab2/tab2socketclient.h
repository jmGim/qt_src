#ifndef TAB2SOCKETCLIENT_H
#define TAB2SOCKETCLIENT_H

#include <QWidget>
#include <socketclient.h>
#include <QTime>
#include <QLineEdit>
#include "keyboard.h"

namespace Ui {
class Tab2SocketClient;
}

class Tab2SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2SocketClient(QWidget *parent = nullptr);
    ~Tab2SocketClient();
    SocketClient *getpSocketClient();

private slots:
    void on_pPBServerConnect_clicked(bool checked);
    void on_pPBSend_clicked();
    void UpdateRecvDataSlot(QString);

    void on_pLERecvId_selectionChanged();

    void on_pLESendMsg_selectionChanged();

private:
    Ui::Tab2SocketClient *ui;
    SocketClient *pSocketClient;
    Keyboard *pKeyboard;

signals:
    void ledWriteSig(int);
};

#endif // TAB2SOCKETCLIENT_H
