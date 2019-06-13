#include "cancommuniction.h"

using namespace std;

QMutex  CANcommuniction::m_lock ;
CANcommuniction::CANcommuniction():
    QObject ()
{
    connect (&timeout ,SIGNAL (timeout()),this ,SLOT(timeouthandle()));
#if 1
    closecan = nullptr;
    opencan = nullptr;
    startcan = nullptr;
    send = nullptr;
    initcan = nullptr;
    resetCan = nullptr;
    receive = nullptr;
    finddevice = nullptr;
    readboardinfo = nullptr;
    getReceiveNum = nullptr;
    clearBuffer = nullptr;

    CANwrite = nullptr;
    CANread = nullptr;
    connectDevice = nullptr;
    usbDeviceReset = nullptr;
    findUsbDevice = nullptr;
    readErrInfo =nullptr;
#endif
}

CANcommuniction:: ~CANcommuniction()
{
    qDebug()<<"~CANcommuniction()";
}

ERR_INFO CANcommuniction::getCanERR_INFO()
{

    ERR_INFO err_info;
    uint returnValue = readErrInfo(DeviceType ,DeviceInd , CANInd , &err_info);
    return  err_info;

}
/*******************************
 * 发送数据的函数
 *
*********************************/
int  CANcommuniction::SendData(uint id,char main, char sub, QList<char> param , int channel , int index)
{
               //如果存在，默认channel index放在子命令之后
               //qDebug("%s %d",__FUNCTION__,__LINE__);
               QString cmddata= "Send::";
               cmddata += QTime::currentTime ().toString ();
               cmddata.append("  ");
               cmddata.append (" {  ");
               QList<char>* data = new QList<char > {main, sub};
               cmddata.append (QString("%1").number (id));
               cmddata.append("  ");
               cmddata.append (QString("%1").number (main));
               cmddata.append("  ");
               cmddata.append (QString("%1").number (sub));
               cmddata.append("  ");
               if (channel != -1)//说明有CHANNEL这一项
               {
                   data->append((char)channel);
                   cmddata.append (QString("%1").number (channel));
                   cmddata.append("  ");
               }

               if (index != -1)//说明有index这一项
               {
                   data->append((char)index);
                   cmddata.append (QString("%1").number (index));
                   cmddata.append("  ");
               }

               if (param.count()>0)
               {
                   data->append(param);
                   int count = 0;
                   for(count = 0; count <param.count ();count++)
                   {
                       cmddata.append (QString("%1").number (param.at (count)));
                       cmddata.append("  ");
                   }
               }

               //int count=data->count();
               char  send_data[9]={0};
               int i=0;
               for(i=0;i< data->count() ;i++)
               {
                   send_data[i] = data->value(i);
               }

               int length=data->count();
               CAN_OBJ *sendobj=new CAN_OBJ;
               sendobj->RemoteFlag = 0;
               sendobj->ExternFlag = 1;
               sendobj->ID = id;
               sendobj->DataLen = static_cast<char >(length);
               /* 数据帧
                * 扩展
                * 暂时认为,命令+参数不会超过8个字节*****/

               /*将数据复制到标准的发送数据的结构体*/
               for ( i = 0; i < length; i++)
               {
                   sendobj->Data[i] = send_data[i];
               }

               /*发送数据*/
               if (send(DeviceType,DeviceInd , CANInd, sendobj,1) == 0)
               {
                    qDebug()<<"send fail....";
                    if (send(DeviceType, DeviceInd ,  CANInd,sendobj,1) == 0)
                    {
                         return -1;
                    }
               }
               /*将发送的所有的命令数据发送到命令显示窗口*/
               cmddata.append (" }");
               emit messgInfo(cmddata);

               delete sendobj;
               return 0;
}
/*已经组好帧的CAN数据发送*/
int CANcommuniction::SendData(uint id, QList<char> param )
{
    int length = param.count ();

    //m_lock.lock ();
    QString OneCmd = "CmdWidget Send::";
    OneCmd += QTime::currentTime ().toString ();
    OneCmd += "  {  ";
    OneCmd.append (QString("%1").number (id));
    OneCmd.append("  ");
    CAN_OBJ *sendobj=new CAN_OBJ;
    sendobj->RemoteFlag = 0;
    sendobj->ExternFlag = 1;
    sendobj->ID = id;
    sendobj->DataLen = static_cast<char >(length);
    /* 数据帧
     * 扩展
     * 暂时认为,命令+参数不会超过8个字节*****/

    /*将数据复制到标准的发送数据的结构体*/
    int i=0;
    for ( i = 0; i < length; i++)
    {
        sendobj->Data[i] = param[i];

        OneCmd.append (QString("%1").number (param.at (i)));
        OneCmd.append("  ");
    }

    /*发送数据*/
    if (send(DeviceType,DeviceInd,CANInd, sendobj,1) == 0)
    {
         qDebug()<<"send fail....";
         if (send(DeviceType, DeviceInd,  CANInd,sendobj,1) == 0)
         {
              return -1;
         }
    }
    OneCmd.append (" }");
    emit messgInfo(OneCmd);
    delete sendobj;
    //m_lock.unlock ();
}

/*******************************
 * 发送PVT点位数据的函数
 * 注意：和直接发送其他的命令数据时有区别的
*********************************/
int  CANcommuniction::SendPvtData(uint id,char mainCmd, QList<char> param , int channel , int index)
{
               //如果存在，默认channel index放在子命令之后
               //qDebug("%s %d",__FUNCTION__,__LINE__);
               //QList<char>* data = new QList<char>;

               /*Pvt下发的数据*/
               m_lock.lock ();
               QString PvtData = "SendPvt::";
               PvtData += QTime::currentTime ().toString ();
               PvtData.append("  ");
               PvtData.append (" {  ");

               PvtData.append (QString("%1").number (id));
               PvtData.append("  ");

               QList<char> data;
               data.append (mainCmd);
               /*添加主命令的*/
               PvtData.append (QString("%1").number (mainCmd));
               PvtData.append("  ");

               /*说明有CHANNEL这一项*/
               if (channel != -1)
               {
                   data.append((char)channel);
                   PvtData.append (QString("%1").number (channel));
                   PvtData.append("  ");

               }
               if (param.count()>0)
               {
                   data.append(param.takeAt (0));
               }

               /*说明有index这一项*/
               if (index != -1)
               {
                   data.append((char)index);
                   PvtData.append (QString("%1").number (index));
                   PvtData.append("  ");
               }

               if (param.count()>0)
               {
                   data.append(param);

                   int count = 0;
                   for(count = 0; count <param.count ();count++)
                   {
                       PvtData.append (QString("%1").number (param.at (count)));
                       PvtData.append("  ");
                   }

               }

               //int count=data->count();
               char  send_data[9]={0};
               int i=0;
               for(i=0;i<data.count();i++)
               {
                   send_data[i]=data.value(i);
               }

               int length=data.count();
               CAN_OBJ *sendobj = new CAN_OBJ ;
               //CAN_OBJ sendobj;
               sendobj->RemoteFlag = 0;
               sendobj->ExternFlag = 1;
               sendobj->ID = id;
               sendobj->DataLen = static_cast<char >(length);

               /* 数据帧
                * 扩展
                * 暂时认为,命令+参数不会超过8个字节
                */

               /*将数据复制到标准的发送数据的结构体*/
               for ( i = 0; i < length; i++)
               {
                   sendobj->Data[i] = send_data[i];
               }

               /*发送数据*/
               if (send(DeviceType,DeviceInd,CANInd, sendobj,1) == 0)
               {
                    qDebug()<<"send fail....";
                    if (send(DeviceType, DeviceInd, CANInd,sendobj,1) == 0)
                    {
                         return -1;
                    }
               }

               PvtData.append (" }");
               //printWidget->addItem (PvtData);
               //printWidget->scrollToBottom ();
               emit messgInfo(PvtData);

               delete sendobj;
               m_lock.unlock();
               return 0;

}


/*******************************
 * 通讯的静态重载接收函数
 *
*********************************/
CAN_OBJ CANcommuniction::receivedata(void *  m_this )
{
    /*上锁*/
    //m_lock.lock ();
    CANcommuniction * m_CANcommuntion = static_cast<CANcommuniction * >(m_this);
    /*静态的线程锁*/
    CAN_OBJ receivedDataBuff[1];

    int i=0;
    for(i=0;i<1;i++)
    {
        receivedDataBuff[i].ID=0;
        receivedDataBuff[i].DataLen=0;
    }
    int count = 0;
    int cou=0;
    while(!(m_CANcommuntion->receive(m_CANcommuntion->DeviceType, m_CANcommuntion->DeviceInd, m_CANcommuntion->CANInd,
                   &receivedDataBuff[0 + count], 1, 6)))
    {
        cou++;
        /*设定接收次数等待的限定*/
        if(cou == 10)
        {
            cou = 0;
            /*屏蔽提示窗口*/
            if(false)
            {
                /*显示提示消息*/
                QMessageBox message(QMessageBox::Warning,\
                                    "ReceiveData","Receive timeout ",\
                                    QMessageBox::Yes|QMessageBox::No,\
                                    nullptr);
                /*点击YES按钮*/
                if (message.exec()==QMessageBox::Yes)
                {
                    qDebug()<<"clicked yes\n";

                }
                /*点击NO按钮*/
                else
                {
                    qDebug()<<"clicked no\n";
                }
            }

            break;
        }
    }
    /*时间溢出*/
    QString CmdData = "Receive::";
    CmdData += " ";
    CmdData += QTime::currentTime ().toString ();
    CmdData += " ";

    /*定时器溢出*/
    if(false)
    {
        CmdData.append ("fail....");
    }
    else
    {
        CmdData.append (" {  ");
        CmdData.append (QString("%1").number (receivedDataBuff[0].ID));
        CmdData.append (" ");
        int datalen = 0;
        for(datalen = 0;datalen <receivedDataBuff[0].DataLen;datalen++)
        {
            CmdData.append (QString("%1").number (receivedDataBuff[0].Data[datalen]));
            CmdData.append (" ");
        }
        CmdData.append (" }");
    }
    /*将接收的数据添加到显示窗口*/
    return receivedDataBuff[0];
}



/***********************************
 * 静态的函数
*******************************************/
int CANcommuniction::SendData(uint id, QList<char> param ,void * m_this)
{
    CANcommuniction * M_this = static_cast<CANcommuniction * >( m_this );
    int length = param.count ();
    QString OneCmd = "CmdWidget Send::";
    OneCmd += QTime::currentTime ().toString ();
    OneCmd += "  {  ";
    OneCmd.append (QString("%1").number (id));
    OneCmd.append("  ");
    CAN_OBJ *sendobj=new CAN_OBJ;
    sendobj->RemoteFlag = 0;
    sendobj->ExternFlag = 1;
    sendobj->ID = id;
    sendobj->DataLen = static_cast<char >(length);
    /* 数据帧
     * 扩展
     * 暂时认为,命令+参数不会超过8个字节*****/

    /*将数据复制到标准的发送数据的结构体*/
    int i=0;
    for ( i = 0; i < length; i++)
    {
        sendobj->Data[i] = param[i];

        OneCmd.append (QString("%1").number (param.at (i)));
        OneCmd.append("  ");
    }

    /*发送数据*/
    if (M_this->send(M_this->DeviceType,M_this->DeviceInd,M_this->CANInd, sendobj,1) == 0)
    {
         qDebug()<<"send fail....";
         if (M_this->send(M_this->DeviceType, M_this->DeviceInd, M_this->CANInd,sendobj,1) == 0)
         {
              return -1;
         }
    }
    OneCmd.append (" }");
    delete sendobj;
}
/*******************************
 * 用于线程接收回传的CAN数据
 *
 * 问题点 如果软件关闭的时候出现没有接收到数据会成为孤儿线程 出现程序异常
 *
*********************************/
CAN_OBJ CANcommuniction::receivedata(uint DeviceType ,uint DeviceInd ,uint CANInd )
{
    CAN_OBJ receivedDataBuff;
    int cnt = 0;
clcReceive:
    int value = receive(DeviceType, DeviceInd , CANInd ,&receivedDataBuff, 1, 6);
    if(!value )
    {
        qDebug()<<"goto clcReceive";

        goto clcReceive;
    }
    return receivedDataBuff;

}

/*******************************
 * 接收CAN数据的函数 重写CAN接收函数
 *
*********************************/
CAN_OBJ CANcommuniction::receivedata()
{
                //QMutex m_lock;
                CAN_OBJ receivedDataBuff[1];
                int i=0;
                for(i=0;i<1;i++)
                {
                    receivedDataBuff[i].ID=0;
                    receivedDataBuff[i].DataLen=0;
                }
                int count = 0;
                int cou=0;

                /*上锁*/
                while(!(receive(DeviceType, DeviceInd , CANInd ,&receivedDataBuff[0 + count], 1, 6)))
                {
                    /*接收消息的定时器溢出*/
                    if(timeOutFlag)
                    {
                        /*显示提示消息*/
                        QMessageBox message(QMessageBox::Warning,"ReceiveData","Receive timeout ",QMessageBox::Yes|QMessageBox::No,NULL);
                        if (message.exec()==QMessageBox::Yes)
                        {
                            qDebug()<<"timeout clicked yes\n";
                        }
                        else
                        {
                            qDebug()<<"timeout clicked no\n";
                            //timeout.stop ();
                        }
                        break;
                    }
                    /*接收的定时器没有溢出*/
                    else
                    {
                        cou++;
                    }
                    /*设定接收次数等待的限定*/
                    if(cou == 100)
                    {
                        cou = 0;
                        /*屏蔽提示窗口*/
                        if(TipWidget)
                        {
                            /*显示提示消息*/
                            QMessageBox message(QMessageBox::Warning,\
                                                "ReceiveData","Receive timeout ",\
                                                QMessageBox::Yes|QMessageBox::No,\
                                                nullptr);
                            /*点击YES按钮*/
                            if (message.exec()==QMessageBox::Yes)
                            {
                                qDebug()<<"clicked yes\n";
                                TipWidget = false;
                                //timeout.stop ();

                            }
                            /*点击NO按钮*/
                            else
                            {
                                qDebug()<<"clicked no\n";
                                TipWidget = true;
                                //timeout.stop ();
                            }
                        }

                        break;
                    }

                }
                /*时间溢出*/
                QString CmdData = "Receive::";
                CmdData += " ";
                CmdData += QTime::currentTime ().toString ();
                CmdData += " ";

                /*定时器溢出*/
                if(timeOutFlag)
                {
                    timeOutFlag = false;
                    CmdData.append ("fail....");
                }
                else
                {
                    CmdData.append (" {  ");
                    CmdData.append (QString("%1").number (receivedDataBuff[0].ID));
                    CmdData.append (" ");
                    int datalen = 0;
                    for(datalen = 0;datalen <receivedDataBuff[0].DataLen;datalen++)
                    {
                        CmdData.append (QString("%1").number (receivedDataBuff[0].Data[datalen]));
                        CmdData.append (" ");
                    }
                    CmdData.append (" }");
                    timeOutFlag = false ;
                }

                emit messgInfo(CmdData);
                return receivedDataBuff[0];

}


/*******************************
 * 接收CAN数据的函数 重写CAN接收函数
 *
*********************************/
CAN_OBJ CANcommuniction::receivedata( int delayCount)
{
                /*计数器--数据个数*/
                CAN_OBJ receivedDataBuff[1];
                int i=0;
                for(i=0;i<1;i++)
                {
                    receivedDataBuff[i].ID=0;
                    receivedDataBuff[i].DataLen=0;
                }
                int count = 0;
                /*增加延时接收不到信息的提示*/
                timeout.stop ();
                timeout.start (50);
                int cou=0;
                while(!(receive(DeviceType, DeviceInd , CANInd,
                               &receivedDataBuff[0 + count], 1, 6)))
                {
                    /*接收消息的定时器溢出*/
                    if(timeOutFlag)
                    {
                        /*显示提示消息*/
                        QMessageBox message(QMessageBox::Warning,"ReceiveData","Receive timeout ",QMessageBox::Yes|QMessageBox::No,NULL);
                        if (message.exec()==QMessageBox::Yes)
                        {
                            qDebug()<<"timeout clicked yes\n";
                            timeout.stop ();
                        }
                        else
                        {
                            qDebug()<<"timeout clicked no\n";
                            timeout.stop ();
                        }
                        break;
                    }
                    /*接收的定时器没有溢出*/
                    else
                    {
                        cou++;
                    }
                    /*设定接收次数等待的限定*/
                    if(cou == delayCount)
                    {
                        cou = 0;
                        /*屏蔽提示窗口*/
                        if(TipWidget)
                        {
                            /*显示提示消息*/
                            QMessageBox message(QMessageBox::Warning,\
                                                "ReceiveData","Receive timeout 是否永久关闭提示窗口 ",\
                                                QMessageBox::Yes|QMessageBox::No,\
                                                nullptr);
                            /*点击YES按钮*/
                            if (message.exec()==QMessageBox::Yes)
                            {
                                qDebug()<<"clicked yes\n";
                                TipWidget = false;
                                timeout.stop ();

                            }
                            /*点击NO按钮*/
                            else
                            {
                                qDebug()<<"clicked no\n";
                                TipWidget = true;
                                timeout.stop ();
                            }
                        }

                        break;
                    }
                }
                /*时间溢出*/
                QString CmdData = "Receive::";
                CmdData += " ";
                CmdData += QTime::currentTime ().toString ();
                CmdData += " ";

                /*定时器溢出*/
                if(timeOutFlag)
                {
                    timeOutFlag = false;
                    timeout.stop ();
                    CmdData.append ("fail....");
                }
                else
                {
                    CmdData.append (" {  ");
                    CmdData.append (QString("%1").number (receivedDataBuff[0].ID));
                    CmdData.append (" ");
                    int datalen = 0;
                    for(datalen = 0;datalen <receivedDataBuff[0].DataLen;datalen++)
                    {
                        CmdData.append (QString("%1").number (receivedDataBuff[0].Data[datalen]));
                        CmdData.append (" ");
                    }
                    CmdData.append (" }");
                    timeOutFlag = false ;
                    timeout.stop () ;
                }
                emit messgInfo(CmdData);

                /*无论什么情况都停止定时器*/
                timeout.stop ();
                return receivedDataBuff[0];

}


/*******************************
 * 加载CanLib库的函数
 * 保存CAN类型标志
*********************************/
int CANcommuniction::OpenCanLib(CANTYPE canType)//USBCAN2 MRH_U MRH_E MRH_T
{
    /*加载当前运行路径*/
    QString runLoadPath = QDir::currentPath();
    qDebug()<<"runLoadPath:  "<<runLoadPath;

    if(canType==MRH_U)
    {
        /*发布时的程序路径*/
        runLoadPath+="/lib/ControlCAN.dll";
        CanType = MRH_U;
    }
    else if(canType==MRH_T)
    {
        runLoadPath+="/lib/MegaCanDevice.dll";
        CanType = MRH_T;
    }
    else if(canType==MRH_E)
    {
        /*发布时的程序路径*/
        runLoadPath+="/lib/MegaCanDevice.dll";
        CanType = MRH_E;
    }
    else if(canType==USBCAN2)
    {
        /*发布时的程序路径*/
        runLoadPath+="/lib/ECanVci.dll";
        CanType = USBCAN2;
    }
    else if(canType == USBCAN1)
    {
        /*发布时的程序路径*/
        runLoadPath+="/lib/ECanVci.dll";
        CanType = USBCAN1;
    }

    else
    {
        /*通讯的设备类型选取错误*/
        throw "CAN Device Error";
    }

    /*加载CAN设备函数库*/
    Canlib.setFileName (runLoadPath);
    /*CAN设备函数库加载成功*/
    qDebug()<<"isLibrary"<<Canlib.isLibrary("E:/QT_demo/MRCS(5.9.6)/MRCS/lib/MegaCanDevice.dll");
    if( Canlib.load( ))
    {
        switch (CanType)
        {
            case USBCAN2:
                    opencan =( OpenCan )Canlib.resolve( "VCI_OpenDevice" );//加载函数

                    closecan =( CloseCan )Canlib.resolve( "VCI_CloseDevice" );//加载函数

                    startcan =( StartCan )Canlib.resolve( "VCI_StartCAN" );//加载函数

                    initcan =( InitCan )Canlib.resolve( "VCI_InitCAN" );//加载函数

                    send = ( Transmit )Canlib.resolve( "VCI_Transmit" );//加载函数

                    receive = ( Receive ) Canlib.resolve("VCI_Receive");//加载接收函数

                    //finddevice = ( FindDevice ) Canlib.resolve("VCI_FindDevice");

                    readboardinfo = ( ReadBoardInfo ) Canlib.resolve("VCI_ReadBoardInfo");

                    getReceiveNum = ( GetReceiveNum ) Canlib.resolve("VCI_GetReceiveNum");

                    clearBuffer = ( ClearBuffer ) Canlib.resolve("VCI_ClearBuffer");

                    resetCan  = ( ResetCan ) Canlib.resolve("VCI_ResetCAN");

                    readErrInfo = (ReadErrInfo)Canlib.resolve("VCI_ReadErrInfo");
                    break;
        case USBCAN1:
                opencan =( OpenCan )Canlib.resolve( "VCI_OpenDevice" );//加载函数

                closecan =( CloseCan )Canlib.resolve( "VCI_CloseDevice" );//加载函数

                startcan =( StartCan )Canlib.resolve( "VCI_StartCAN" );//加载函数

                initcan =( InitCan )Canlib.resolve( "VCI_InitCAN" );//加载函数

                send = ( Transmit )Canlib.resolve( "VCI_Transmit" );//加载函数

                receive = ( Receive ) Canlib.resolve("VCI_Receive");//加载接收函数

                //finddevice = ( FindDevice ) Canlib.resolve("VCI_FindDevice");

                readboardinfo = ( ReadBoardInfo ) Canlib.resolve("VCI_ReadBoardInfo");

                getReceiveNum = ( GetReceiveNum ) Canlib.resolve("VCI_GetReceiveNum");

                clearBuffer = ( ClearBuffer ) Canlib.resolve("VCI_ClearBuffer");

                resetCan  = ( ResetCan ) Canlib.resolve("VCI_ResetCAN");

                break;

            case MRH_U:
                    opencan =( OpenCan )Canlib.resolve( "VCI_OpenDevice" );//加载函数

                    closecan =( CloseCan )Canlib.resolve( "VCI_CloseDevice" );//加载函数

                    startcan =( StartCan )Canlib.resolve( "VCI_StartCAN" );//加载函数

                    initcan =( InitCan )Canlib.resolve( "VCI_InitCAN" );//加载函数

                    send = ( Transmit )Canlib.resolve( "VCI_Transmit" );//加载函数

                    receive = ( Receive ) Canlib.resolve("VCI_Receive");//加载接收函数

                    //finddevice = ( FindDevice ) Canlib.resolve("VCI_FindDevice");

                    readboardinfo = ( ReadBoardInfo ) Canlib.resolve("VCI_ReadBoardInfo");

                    getReceiveNum = ( GetReceiveNum ) Canlib.resolve("VCI_GetReceiveNum");

                    clearBuffer = ( ClearBuffer ) Canlib.resolve("VCI_ClearBuffer");

                    resetCan  = ( ResetCan ) Canlib.resolve("VCI_ResetCAN");
                    break;

            case MRH_E:
                    opencan =( OpenCan )Canlib.resolve( "_VCI_OpenDevice@12" );//加载函数

                    closecan =( CloseCan )Canlib.resolve( "_VCI_CloseDevice@8" );//加载函数

                    startcan =( StartCan )Canlib.resolve( "_VCI_StartCAN@12" );//加载函数

                    initcan =( InitCan )Canlib.resolve( "_VCI_InitCAN@16" );//加载函数

                    send = ( Transmit )Canlib.resolve( "_VCI_Transmit@20" );//加载函数

                    receive = ( Receive ) Canlib.resolve("_VCI_Receive@24");//加载接收函数

                    finddevice = ( FindDevice ) Canlib.resolve("_VCI_FindDevice@12");

                    readboardinfo = ( ReadBoardInfo ) Canlib.resolve("_VCI_ReadBoardInfo@12");

                    getReceiveNum = ( GetReceiveNum ) Canlib.resolve("_VCI_GetReceiveNum@12");

                    clearBuffer = ( ClearBuffer ) Canlib.resolve("_VCI_ClearBuffer@12");

                    resetCan  = ( ResetCan ) Canlib.resolve("_VCI_ResetCAN@12");

                    CANwrite =( CanWrite ) Canlib.resolve("_VCI_Write@16");

                    CANread  = ( CanRead ) Canlib.resolve("_VCI_Read@20");

                    //connectDevice = ( ConnectDevice ) Canlib.resolve("_VCI_ConnectDevice");

                    //usbDeviceReset =( UsbDeviceReset ) Canlib.resolve("_VCI_UsbDeviceReset");
                    break;
            case MRH_T:
                    opencan =( OpenCan )Canlib.resolve( "_VCI_OpenDevice@12" );//加载函数

                    closecan =( CloseCan )Canlib.resolve( "_VCI_CloseDevice@8" );//加载函数

                    startcan =( StartCan )Canlib.resolve( "_VCI_StartCAN@12" );//加载函数

                    initcan =( InitCan )Canlib.resolve( "_VCI_InitCAN@16" );//加载函数

                    send = ( Transmit )Canlib.resolve( "_VCI_Transmit@20" );//加载函数

                    receive = ( Receive ) Canlib.resolve("_VCI_Receive@24");//加载接收函数

                    finddevice = ( FindDevice ) Canlib.resolve("_VCI_FindDevice@12");

                    readboardinfo = ( ReadBoardInfo ) Canlib.resolve("_VCI_ReadBoardInfo@12");

                    getReceiveNum = ( GetReceiveNum ) Canlib.resolve("_VCI_GetReceiveNum@12");

                    clearBuffer = ( ClearBuffer ) Canlib.resolve("_VCI_ClearBuffer@12");

                    resetCan  = ( ResetCan ) Canlib.resolve("_VCI_ResetCAN@12");

                    CANwrite =( CanWrite ) Canlib.resolve("_VCI_Write@16");

                    CANread  = ( CanRead ) Canlib.resolve("_VCI_Read@20");
                    break;
            default:
                    break;
        }
    }
    /*CAN设备函数库加载失败*/
    else
    {
        qDebug()<<"CAN LIBS Load Fail"<<Canlib.errorString();
        //throw "CAN LIBS Load Fail";
    }

    return 1;
}

/*******************************
 * 打开CAN设备
 *
*********************************/
int CANcommuniction::OpenCAN(uint DeviceType,uint DeviceInd)
{

clc_openCAN:
    if(DeviceType == MRH_T)
    {
        char outPut[1024];
        int len = finddevice(DeviceType , outPut ,1024);
        //string s = Encoding.ASCII.GetString(outPut, 0, len).Split(';').at(0);
        qDebug()<<outPut;
    }

    uint value = opencan(DeviceType,DeviceInd, 0 );
    if( value  == Sucess)
    {

    }
    else {
        QMessageBox message(QMessageBox::Warning,\
                            tr("OPEN CAN DEVICE FAIL "),tr("OPEN CAN DEVICE FAIL! Try Again？"),\
                            QMessageBox::Yes|QMessageBox::No,\
                            nullptr);
        /*点击YES按钮*/
        if (message.exec()==QMessageBox::Yes)
        {
            value = opencan(DeviceType,DeviceInd,CANInd);
            if(value == fail )
            {
                goto clc_openCAN ;
            }
        }
        /*点击NO按钮*/
        else
        {
            return  -1;
        }
    }
}

/*******************************
 * 启动CAN设备
 *
*********************************/
int  CANcommuniction::StartCANDevice (uint DeviceType,uint DeviceInd, uint CANInd, CAN_INIT_CONFIG *config )
{

    /*初始化CAN设备*/
    uint value = initcan(DeviceType,DeviceInd,CANInd,config);
    if( value  == Sucess  )
    {
    }
    else {
        QMessageBox message(QMessageBox::Warning,\
                            tr("INIT CAN DEVICE FAIL "),tr("INIT CAN DEVICE! Try Again？"),\
                            QMessageBox::Yes|QMessageBox::No,\
                            nullptr);
        /*点击YES按钮*/
        if (message.exec()==QMessageBox::Yes)
        {
            value = initcan(DeviceType,DeviceInd,CANInd,config);
            if(value == fail )
            {
                return  -1;
            }
        }
        /*点击NO按钮*/
        else
        {
            return  -1;
        }
    }
    /*启动CAN设备*/
    value = startcan(DeviceType,DeviceInd,CANInd);
    if( value  == Sucess  )
    {
    }
    else {

        QMessageBox message(QMessageBox::Warning,\
                            tr("START CAN DEVICE FAIL "),tr("START CAN DEVICE! Try Again？"),\
                            QMessageBox::Yes|QMessageBox::No,\
                            nullptr);
        /*点击YES按钮*/
        if (message.exec()==QMessageBox::Yes)
        {
            value = startcan(DeviceType,DeviceInd,CANInd);
            if(value == fail )
            {
                return  -1;
            }
        }
        /*点击NO按钮*/
        else
        {
            return  -1;
        }
    }
    return 1;
}
/*******************************
 * 重载启动CAN设备 默认的CAN配置
 *
*********************************/
int CANcommuniction::StartCANDevice (uint DeviceType ,uint DeviceInd, uint CANInd)
{
    CAN_INIT_CONFIG *config=new CAN_INIT_CONFIG;//配置CAN设备的结构体对象
    config->AccCode=0;
    config->AccMask=0xFFFFFFFF;
    config->Timing0=0x00;
    config->Timing1=0x14;
    config->Filter=0;
    config->Mode=0;      //CAN MODE
    config->Baud=1000000;//配置CAN通讯波特率
    StartCANDevice (DeviceType,DeviceInd, CANInd ,config);
}

/*******************************
 * 判定加载的函数是否加载成功，有一个是NULL 就判定为加载失败
 *
*********************************/
bool CANcommuniction::isLoadCanLibSucess()
{
    if((CanType == USBCAN2) || (CanType == USBCAN1))
    {
       if(( closecan == nullptr ) || \
          ( opencan == nullptr ) || \
          ( startcan == nullptr ) || \
          ( send == nullptr ) || \
          ( receive == nullptr ) || \
          ( initcan == nullptr ) || \
          ( resetCan == nullptr ) || \
          ( readboardinfo == nullptr ) || \
          ( getReceiveNum == nullptr ) || \
          ( clearBuffer == nullptr )||\
          (readErrInfo == nullptr))
       {
           qDebug()<<closecan<<" "<<opencan<<" "<<startcan<<" "<<send<<" "<<receive<<" "<<initcan<<" "<<resetCan<<" "<<\
                     finddevice<<" "<<readboardinfo<<" "<<getReceiveNum<<" "<<clearBuffer<<" "<<readErrInfo;
           return false ;
       }
       else
       {
             qDebug()<<"加载成功";
             return  true ;
       }
    }


    if(CanType == MRH_U )
    {
       if(( closecan == nullptr ) || \
          ( opencan == nullptr ) || \
          ( startcan == nullptr ) || \
          ( send == nullptr ) || \
          ( receive == nullptr ) || \
          ( initcan == nullptr ) || \
          ( resetCan == nullptr ) || \
          //( finddevice == nullptr ) ||
          ( readboardinfo == nullptr ) || \
          ( getReceiveNum == nullptr ) || \
          (clearBuffer == nullptr ))
       {
              qDebug()<<"加载失败";
              qDebug()<<closecan<<" "<<opencan<<" "<<startcan<<" "<<send<<" "<<receive<<" "<<initcan<<" "<<resetCan<<" "<<\
                        " "<<readboardinfo<<" "<<getReceiveNum<<" "<<clearBuffer;
              return false ;
       }
       else
       {
             return  true ;
       }
    }


    if(CanType == MRH_E )
       {
          if(( closecan == nullptr ) || \
             ( opencan == nullptr ) || \
             ( startcan == nullptr ) || \
             ( send == nullptr ) || \
             ( receive == nullptr ) || \
             ( initcan == nullptr ) || \
             ( resetCan == nullptr ) || \
             //( finddevice == nullptr ) ||
             ( readboardinfo == nullptr ) || \
             ( getReceiveNum == nullptr ) || \
             (clearBuffer == nullptr )||
             (CANread == nullptr ) ||
             (CANwrite == nullptr ) ||
             (clearBuffer == nullptr )
                  )
          {
               qDebug()<<"加载失败";
               qDebug()<<closecan<<" "<<opencan<<" "<<startcan<<" "<<send<<" "<<receive<<" "<<initcan<<" "<<resetCan<<" "<<\
                         " "<<readboardinfo<<" "<<getReceiveNum<<" "<<clearBuffer<<" "<<CANread<<" "<<CANwrite<<" "<<clearBuffer;
                return false ;
          }
          else
          {
                return  true ;
          }
       }

    if(CanType == MRH_T )
    {

        if(( closecan == nullptr ) || \
           ( opencan == nullptr ) || \
           ( startcan == nullptr ) || \
           ( send == nullptr ) || \
           ( receive == nullptr ) || \
           ( initcan == nullptr ) || \
           ( resetCan == nullptr ) || \
           ( finddevice == nullptr ) ||
           ( readboardinfo == nullptr ) || \
           ( getReceiveNum == nullptr ) || \
           (clearBuffer == nullptr )||
           (CANread == nullptr ) ||
           (CANwrite == nullptr ) ||
           (clearBuffer == nullptr )
                )
        {
             qDebug()<<"加载失败";
             qDebug()<<closecan<<" "<<opencan<<" "<<startcan<<" "<<send<<" "<<receive<<" "<<initcan<<" "<<resetCan<<" "<<\
                       " "<<readboardinfo<<" "<<getReceiveNum<<" "<<clearBuffer<<" "<<CANread<<" "<<CANwrite<<" "<<clearBuffer;
              return false ;
        }
        else
        {
              return  true ;
        }
    }
}

/*******************************
 * 关闭CANLIB 库
 *
 * 有BUG,CAN设备类型目前是定死的
*********************************/
int CANcommuniction::CloseCanLib()//USBCAN2 MRH_U MRH_E MRH_T
{
    if(Canlib.isLoaded ())
    {
        if(closecan)
        {
            closecan(DeviceType,DeviceInd);
        }
        Canlib.unload ();
    }

}

/*时间接收时间溢出的槽函数处理*/
void CANcommuniction::timeouthandle()
{
    timeOutFlag = true;
    qDebug()<<"timeouthandle";
    timeout.stop ();

}

/*设置打印的窗口句柄*/
void CANcommuniction::setPrintfWidget(QListWidget * printf )
{
    printWidget = printf;
}

/*得到能够接收的CAN接收的数量*/
unsigned int  CANcommuniction::getNum()
{
    return  getReceiveNum(DeviceType,DeviceInd,CANInd);
}

/*清理clearReceiveBuffer*/
void CANcommuniction::clearReceiveBuffer()
{
    clearBuffer(DeviceType, DeviceInd ,CANInd );
}

/*获取CAN板子的信息*/
VCI_BOARD_INFO CANcommuniction::getCAN_BOARD_INFO()
{
    readboardinfo(DeviceType, DeviceInd,&CAN_BOARD_INFO);

    return CAN_BOARD_INFO ;
}


/*关闭CAN*/
void CANcommuniction::closeCan()
{
    closecan(DeviceType, DeviceInd);
}





