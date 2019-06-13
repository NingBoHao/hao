#include "teste2promwidget.h"
#include "ui_teste2promwidget.h"

TestE2promWidget::TestE2promWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestE2promWidget)
{
    ui->setupUi(this);
    qRegisterMetaType<QList<char >>("QList<char >");
    connect (&seclectCmdWidget ,SIGNAL (signals_CmdData(QList<char >)) , this ,SLOT (Slot_setCmd(QList<char > )));
    connect (&seclectCmdWidgetQue ,SIGNAL (signals_CmdData(QList<char >)) , this ,SLOT (Slot_QueCmd(QList<char > )));

    connect (&timer0 ,SIGNAL (timeout()), this ,SLOT(Slot_timeout()));
    connect (&timer1 ,SIGNAL (timeout()), this ,SLOT(Slot_timeout1()));
    canComm = new CANcommuniction;
    initCANCONMM();
}

void TestE2promWidget::Slot_timeout()
{
    //qDebug()<<"Slot_timeout";
    timer0.stop ();
    canComm->SendData (1, QueCmd);
    timer1.start (Cmd_find_Timer);
}

void TestE2promWidget::Slot_timeout1()
{
    //qDebug()<<"Slot_timeout1";
    allCmdTimer += Cmd_find_Timer;
    if(allCmdTimer< 5000 )
    {
        canComm->SendData (1, QueCmd);
        //timer0.start (Cmd_find_Timer);
    }
    else {

        if(Cmd_find_spliter >2000)
        {
            allCmdTimer = 0;
            ui->StartpushButton->setEnabled (true);
            timer0.stop ();
            timer1.stop ();
            return;
        }
        allCmdTimer = 0;
        Cmd_find_spliter += Cmd_find_spliter_Add;


        myCMD::MOTOR_CURRENT  MOTOR_current;
        if(isret)
        {
            isret = false;
            qDebug()<<"1";
            canComm->SendData (1 , MOTOR_current.Add_U8_0_0 (0)->Add_U8_1_1 (10)->GetCmdData ().TranData ());
        }
        else {
            qDebug()<<"2";
            isret = true;
            canComm->SendData (1 , MOTOR_current.Add_U8_0_0 (0)->Add_U8_1_1 (15)->GetCmdData ().TranData ());
        }
        timer0.start ();
        timer1.stop ();

    }


}
TestE2promWidget::~TestE2promWidget()
{
    delete ui;
}
void TestE2promWidget::Slot_setCmd(QList<char > p_cmd_List )
{
    qDebug()<<"Slot_setCmd"<<p_cmd_List;
    //Setcmd = p_cmd_List;

    ui->SetCmd_lineEdit->clear ();
    int i = 0 ;
    QString cmdStr;
    for(i = 0 ; i <p_cmd_List.count (); i++)
    {
        cmdStr.append (QString("%1").setNum (p_cmd_List.at (i)));
        cmdStr.append (" ");
    }
    ui->SetCmd_lineEdit->setText (cmdStr);
}
void TestE2promWidget::Slot_QueCmd(QList<char > p_cmd_List )
{
    QueCmd = p_cmd_List;

    //qDebug()<<"Slot_QueCmd"<<p_cmd_List;
    ui->FindCmd_lineEdit->clear ();
    int i = 0 ;
    QString cmdStr;
    for(i = 0 ; i <p_cmd_List.count (); i++)
    {
        cmdStr.append (QString("%1").setNum (p_cmd_List.at (i)));
        cmdStr.append (" ");
    }
    ui->FindCmd_lineEdit->setText (cmdStr);
}


void TestE2promWidget::on_SetCmdSelectpushButton_clicked()
{
    seclectCmdWidgetQue.setWindowTitle ("设置项命令");
    seclectCmdWidget.show ();
}

void TestE2promWidget::on_QueCmdSelectpushButton_clicked()
{
    seclectCmdWidgetQue.setWindowTitle ("挑选查询命令");
    seclectCmdWidgetQue.show ();
}

void TestE2promWidget::on_StartpushButton_clicked()
{
    ui->StartpushButton->setEnabled (false);
    Cmd_find_spliter = ui->Cmd_find_spliter_spinBox->value ();
    Cmd_find_spliter_Add = ui->Cmd_find_spliter_Add_spinBox->value ();
    Cmd_find_Timer = ui->Cmd_find_Timer_spinBox->value ();
    //qDebug()<<"canComm->SendData (1,Setcmd );";

    Slot_timeout();
    timer0.start (Cmd_find_spliter);
}

void TestE2promWidget::on_StoppushButton_clicked()
{
    allCmdTimer = 0;
    timer0.stop ();
    timer1.stop ();
    ui->StartpushButton->setEnabled (true);
}

/*初始化通讯库*/
int  TestE2promWidget::initCANCONMM()
{

clc_OpenCanLib:
    /*加载通讯库*/
    uint deviceType = 0;
    deviceType = USBCAN2;

    canComm->OpenCanLib ( static_cast<CANTYPE >(deviceType) );
    qDebug()<<"deviceType:::: "<<static_cast<CANTYPE >(deviceType);
    if(!canComm->isLoadCanLibSucess ())
    {
        QMessageBox message(QMessageBox::Warning,\
                            tr("LoadCanLib"),tr("LoadCanLibFail! 是否重新加载？"),\
                            QMessageBox::Yes|QMessageBox::No,\
                            nullptr);
        /*点击YES按钮*/
        if (message.exec()==QMessageBox::Yes)
        {
            /*CANLIB加载失败就重新加载*/
            canComm->CloseCanLib();
            goto clc_OpenCanLib;
        }
        else
        {
            canComm->CloseCanLib();
            return -1;
        }
    }

    /*打开CAN设备*/
    int value = canComm->OpenCAN ( deviceType ,0);
    if(value == -1 )
    {
        return -1;
    }
    /*开启CAN 设备 第一路CAN*/
    int statu = canComm->StartCANDevice(deviceType,0,0);
    if(statu == -1)//打开CAN设备失败
    {
        return -1;
    }

    canComm->SendData (1 ,1, 0 ,{ 1 });
    canComm->SendData (1 ,1, 2 ,{});
    CAN_OBJ ret =  canComm->receivedata ();
    if(ret.Data[0]== 1)
    {
        qDebug()<<"连接成功";
        ui->pushButton->setText ("连接成功");

    }
    else {
        ui->pushButton->setText ("重新连接");
    }

}
//重新连接按钮
void TestE2promWidget::on_pushButton_clicked()
{
    if(canComm != nullptr)
    {
        canComm->SendData (1 ,1, 0 ,{ 1 });
        canComm->SendData (1 ,1, 2 ,{});
        CAN_OBJ ret =  canComm->receivedata ();
        if(ret.Data[0]== 1)
        {
            qDebug()<<"连接成功";
            ui->pushButton->setText ("连接成功");

        }
        else {
            ui->pushButton->setText ("重新连接");
        }
    }
}
