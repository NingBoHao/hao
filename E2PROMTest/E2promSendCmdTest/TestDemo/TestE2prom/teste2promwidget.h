#ifndef TESTE2PROMWIDGET_H
#define TESTE2PROMWIDGET_H

#include <QWidget>
#include "Global/deviceinfo.h"
#include "CmdStruct/cmdstruct.h"
#include "CmdWidget/cmddialog.h"
#include "cancommuniction.h"
#include "QTimer"

namespace Ui {
class TestE2promWidget;
}

class TestE2promWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestE2promWidget(QWidget *parent = nullptr);
    ~TestE2promWidget();
    int initCANCONMM();

    QList<char > Setcmd;
    QList<char > QueCmd;
    bool isret = false;
private slots:
    void on_SetCmdSelectpushButton_clicked();

    void on_QueCmdSelectpushButton_clicked();

    void on_StartpushButton_clicked();

    void on_StoppushButton_clicked();

    void Slot_setCmd(QList<char > p_cmd_List );
    void Slot_QueCmd(QList<char > p_cmd_List );
    void Slot_timeout();
    void Slot_timeout1();

    void on_pushButton_clicked();

private:
    Ui::TestE2promWidget *ui;
    cmdDialog seclectCmdWidgetQue;
    cmdDialog seclectCmdWidget;

    int Cmd_find_spliter;
    int Cmd_find_spliter_Add;
    int Cmd_find_Timer;

    int allCmdTimer = 0;

    /*软件CAN通讯*/
    CANcommuniction *canComm = nullptr;

    QTimer timer0 ;
    QTimer timer1 ;

};

#endif // TESTE2PROMWIDGET_H
