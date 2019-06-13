#include "cmddialog.h"
#include "ui_cmddialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QObject>
#include <QDebug>


cmdDialog::cmdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cmdDialog)
{
    ui->setupUi(this);
    /*初始化软件的工具栏函数*/
    initCmdDialog();
}

/*初始化设备信息*/
void cmdDialog::initDeviceInfo(DeviceInfo* p_deviceInfo)
{
    deviceInfo = p_deviceInfo;
    setComm (p_deviceInfo->canComm);
    SENDID = p_deviceInfo->receiveId ;
}

/********************************************************************
 * 函数的描述: 初始化软件的工具栏函数
 * 函数的注意:
 * 函数的待完成项:
 * 函数的BUG点:
 * 函数的其他描述：
*********************************************************************/
void cmdDialog::initCmdDialog()
{

    QDir fileDir(QCoreApplication::applicationDirPath());
    //QString filepath=fileDir.currentPath();
    QString filepath;
    //filepath.append("/cmdexcel.xlsx");
    filepath.append(":/resource/cmdexcel.xlsx");

    qDebug()<<filepath;
    xlsx = new QXlsx::Document(filepath);

    QVariant val=xlsx->read (1, 1);
    mainCmdIndex = val.toString ().split (":").at (0).toInt ();
    qDebug()<<val.toString ();
    mainCmdCount = val.toString ().split (":").at (1).toInt ();

    mainLable.setText ("mainLable:");
    subLable.setText ("subLable:");
    mainLable.setParent (this);
    subLable.setParent (this);
    mainCmd.setParent (this);
    subCmd.setParent (this);
#if 1
    int i=0;

    /*添加主命令的COM窗口和子命令的窗口*/
    for(i=0;i<mainCmdCount;i++)
    {
        mainCmd.addItem ( xlsx->read (mainCmdIndex+i,1).toString ().split (":").at (0) );//主命令字符串
    }
    on_MainCmdchanged(0);
#endif
    ui->gridLayout->addWidget (&mainLable,0,0);
    ui->gridLayout->addWidget (&subLable,1,0);
    ui->gridLayout->addWidget (&mainCmd,0,1);
    ui->gridLayout->addWidget (&subCmd,1,1);

    connect (&mainCmd,SIGNAL ( activated(int) ),this ,SLOT (on_MainCmdchanged(int)));
    connect (&subCmd,SIGNAL ( activated(int) ),this ,SLOT (on_SubCmdchanged(int)));
}
/********************************************************************
 * 函数的描述: 主命令的选取改变之后对应的槽函数处理事件
 * 函数的注意:
 * 函数的待完成项:
 * 函数的BUG点:
 * 函数的其他描述：
*********************************************************************/
void cmdDialog::on_MainCmdchanged(int indexOffset)
{

    QString tmp=xlsx->read ((mainCmdIndex+indexOffset),1).toString ();
    currentMainStr.clear ();
    currentMainStr=tmp.split (":").at (0);
    currentMainCmdNum =tmp.split (":").at (1).toInt ();
    subCmdIndex = tmp.split (":").at (2).toInt ();
    subCmdCount = tmp.split (":").at (3).toInt ();
    subCmd.clear ();
    int i=0;
    /*根据主命令的索引行信息来加载对应子命令的数量和对应子命令项*/
    for(i=0;i<subCmdCount;i++)
    {
        subCmd.addItem (xlsx->read (subCmdIndex+i,1).toString ().split (":").at (0));
    }

    on_SubCmdchanged(0);

}
/********************************************************************
 * 函数的描述: 子命令的选取改变对应的槽函数处理事件
 * 函数的注意:
 * 函数的待完成项:
 * 函数的BUG:
 * 函数的其他描述：
*********************************************************************/
void cmdDialog::on_SubCmdchanged(int indexOffset)
{
    int i= 0 ;
    for(i = 0; i< ENUM.count (); i++)
    {
        ui->gridLayout->removeWidget (ENUM.at (i));
        delete ENUM.at (i);
    }
    ENUM.clear ();

    for(i = 0; i< LineEdit.count (); i++)
    {
        ui->gridLayout->removeWidget (LineEdit.at (i));
        delete LineEdit.at (i);
    }
    LineEdit.clear ();

    for(i = 0; i< Lable.count (); i++)
    {
        ui->gridLayout->removeWidget (Lable.at (i));
        delete Lable.at (i);
    }
    Lable.clear ();

    currentSubCmdNum = xlsx->read (subCmdIndex+indexOffset,1).toString ().split (":").at (1).toInt ();
    //qDebug()<<"currentSubCmdNum:"<<currentSubCmdNum;
    int paramCount=0;
    QStringList  paramList;
    paramList=xlsx->read (subCmdIndex+indexOffset,2).toString ().split ("&");
    paramCount = paramList.count ();
    if(xlsx->read (subCmdIndex+indexOffset,2).toString () != "")//有参数
    {
        int i=0;
        if(xlsx->read (subCmdIndex+indexOffset,1).toString ().split (":").at (0) == "FLOWCTL")//枚举的个别特里处理
        {

        }
        else if(xlsx->read (subCmdIndex+indexOffset,1).toString ().split (":").at (0) == "RESPONSE")
        {

        }

        for(i=0;i < paramCount  ; i++)
        {
            if(paramList.at (i) == "ENUM")
            {

                QComboBox * newEnum = new QComboBox;
                int enumCount=0;
                QStringList enumVal=xlsx->read (subCmdIndex+indexOffset,3).toString ().split ("&");
                for(enumCount=0;enumCount<enumVal.at (i).split ("|").count ();enumCount++)
                {
                    newEnum->addItem (enumVal.at (i).split ("|").at (enumCount));
                }

                QLabel * newLable = new QLabel;
                newLable->setText ("ENUM");
                ui->gridLayout->addWidget (newEnum,i+2,1);
                ui->gridLayout->addWidget (newLable,i+2,0);
                ENUM.append (newEnum);
                Lable.append (newLable);
            }
            else if(paramList.at (i) == "F32")
            {
#if 1
                QLineEdit * newInputParam = new QLineEdit;
                //connect (newInputParam,SIGNAL (textChanged(const QString& )),this,SLOT ( floatText(const QString &)));
                QLabel * newLable = new QLabel;
                newLable->setText (paramList.at (i));

                ui->gridLayout->addWidget (newInputParam,i+2,1);
                ui->gridLayout->addWidget (newLable,i+2,0);
                LineEdit.append (newInputParam);
                Lable.append (newLable);
#endif
            }
            else if(paramList.at (i) == "U8")
            {
                QLineEdit * newInputParam = new QLineEdit;
                QLabel * newLable = new QLabel;
                QStringList paramListVal=xlsx->read (subCmdIndex+indexOffset,3).toString ().split ("&");
                if(paramListVal.at (i) == "[CHANNUM]")
                {
                    newLable->setText ("U8(CH)");
                }
                else
                {
                    newLable->setText (paramList.at (i));
                }
                ui->gridLayout->addWidget (newInputParam,i+2,1);
                ui->gridLayout->addWidget (newLable,i+2,0);
                LineEdit.append (newInputParam);
                Lable.append (newLable);
            }
            else
            {
                QLineEdit * newInputParam = new QLineEdit;
                QLabel * newLable = new QLabel;

                newLable->setText (paramList.at (i));

                ui->gridLayout->addWidget (newInputParam,i+2,1);
                ui->gridLayout->addWidget (newLable,i+2,0);
                LineEdit.append (newInputParam);
                Lable.append (newLable);
            }
        }
    }

}
/********************************************************************
 * 函数的描述: 获取当前的选取的命令数据
 * 函数的注意:前提是要确保已经有选取命令
 * 函数的待完成项:
 * 函数的BUG点:
 * 函数的其他描述：
*********************************************************************/
void cmdDialog::GetCmdData()
{
    int clearCnt=0;
    for(clearCnt =0; clearCnt <10; clearCnt ++)
    {
        cmdData[clearCnt] = -1 ;
    }
    cmdData[0] = static_cast< char >(currentMainCmdNum);
    cmdData[1] = static_cast< char >(currentSubCmdNum);
    int i = 0 ;
    //int paramCnt = 0;

    int     enumCnt=0,
            U8Cnt=0,
            U16Cnt=0,
            U32Cnt=0,
            F32Cnt=0,
            S8Cnt=0,
            S16Cnt=0,
            S32Cnt=0,
            CHAR1Cnt=0,
            CHAR2Cnt=0,
            CHAR3Cnt=0,
            CHAR4Cnt=0,
            CHAR5Cnt=0,
            CHAR6Cnt=0;
    int labelCnt = 0;
    int Cnt=2;
    for(i = 0; i<Lable.count (); i++)
    {
        if(Lable.at (i)->text () == "ENUM")
        {
            cmdData[Cnt++] = static_cast< char >(ENUM.at (enumCnt)->currentIndex ());
            enumCnt++;
        }
        //else if(Lable.at (i)->text () == "U8" )
        else if(Lable.at (i)->text ().contains ("U8"))
        {
            cmdData[Cnt++] = static_cast< char >(LineEdit.at (labelCnt++)->text ().toUInt ());
            U8Cnt++;
        }
        else if(Lable.at (i)->text () == "U16" )
        {

            unsigned short tmp = static_cast< unsigned short >(LineEdit.at (labelCnt++)->text ().toUShort ());
            char * ptr= (char * )&tmp;
            cmdData[Cnt++] = ptr[0];
            cmdData[Cnt++] = ptr[1];
            U16Cnt++;
        }
        else if(Lable.at (i)->text () == "U32" )
        {
            unsigned int tmp = static_cast< unsigned int >(LineEdit.at (labelCnt++)->text ().toUInt ());
            char * ptr= (char * )&tmp;
            cmdData[Cnt++] = ptr[0];
            cmdData[Cnt++] = ptr[1];
            cmdData[Cnt++] = ptr[2];
            cmdData[Cnt++] = ptr[3];
            U32Cnt++;
        }
        else if( Lable.at (i)->text () == "F32" )
        {
            float tmp = (LineEdit.at (labelCnt++)->text ().toFloat ());
            char * ptr= (char * )&tmp;
            cmdData[Cnt++] = ptr[0];
            cmdData[Cnt++] = ptr[1];
            cmdData[Cnt++] = ptr[2];
            cmdData[Cnt++] = ptr[3];
            F32Cnt++;
        }
        else if(Lable.at (i)->text () == "S8")
        {
            short tmp = static_cast< short >(LineEdit.at (labelCnt++)->text ().toShort ());
            char * ptr= (char * )&tmp;
            cmdData[Cnt++] = ptr[0];
            S8Cnt++;

        }
        else if(Lable.at (i)->text () == "S16")
        {
            short tmp = static_cast< short >(LineEdit.at (labelCnt++)->text ().toShort ());
            char * ptr= (char * )&tmp;
            cmdData[Cnt++] = ptr[0];
            cmdData[Cnt++] = ptr[1];
            S16Cnt++;

        }
        else if(Lable.at (i)->text () == "S32")
        {
            int tmp = static_cast< int >(LineEdit.at (labelCnt++)->text ().toInt ());
            char * ptr= (char * )&tmp;
            cmdData[Cnt++] = ptr[0];
            cmdData[Cnt++] = ptr[1];
            cmdData[Cnt++] = ptr[2];
            cmdData[Cnt++] = ptr[3];
            S32Cnt++;
        }
        else if(Lable.at (i)->text () == "CHAR1")
        {
            cmdData[Cnt++] = static_cast< char >(ENUM.at (CHAR1Cnt)->currentText ().toInt ());
            CHAR1Cnt++;
            labelCnt++;
        }
        else if(Lable.at (i)->text () == "CHAR2")
        {
            cmdData[Cnt++] = static_cast< char >(ENUM.at (CHAR2Cnt)->currentText ().toInt ());
            CHAR2Cnt++;
            labelCnt++;
        }
        else if(Lable.at (i)->text () == "CHAR3")
        {
            cmdData[Cnt++] = static_cast< char >(ENUM.at (CHAR3Cnt)->currentText ().toInt ());
            CHAR3Cnt++;
            labelCnt++;
        }
        else if(Lable.at (i)->text () == "CHAR4")
        {
            cmdData[Cnt++] = static_cast< char >(ENUM.at (CHAR4Cnt)->currentText ().toInt ());
            CHAR4Cnt++;
            labelCnt++;
        }
        else if(Lable.at (i)->text () == "CHAR5")
        {
            cmdData[Cnt++] = static_cast< char >(ENUM.at (CHAR5Cnt)->currentText ().toInt ());
            CHAR5Cnt++;
            labelCnt++;
        }
        else if(Lable.at (i)->text () == "CHAR6")
        {
            cmdData[Cnt++] = static_cast< char >(ENUM.at (CHAR6Cnt)->currentText ().toInt ());
            CHAR6Cnt++;
            labelCnt++;
        }
    }
}


/********************************************************************
 * 函数的描述: 验证输入的命令参数是否是浮点数处理
 * 函数的注意:
 * 函数的待完成项:
 * 函数的BUG点:
 * 函数的其他描述：
 * 函数是否完成： 否
*********************************************************************/
void cmdDialog::floatText(const QString & text)
{
    qDebug()<<text;
}

cmdDialog::~cmdDialog()
{
    int i= 0 ;
    for(i = 0; i< ENUM.count (); i++)
    {
        delete ENUM.at (i);
    }
    ENUM.clear ();

    for(i = 0; i< LineEdit.count (); i++)
    {
        delete LineEdit.at (i);
    }
    LineEdit.clear ();

    for(i = 0; i< Lable.count (); i++)
    {
        delete Lable.at (i);
    }
    Lable.clear ();
    delete ui;

    //delete can;
}

/********************************************************************
 * 函数的描述: 发送按钮的处理槽函数
 * 函数的注意:
 * 函数的待完成项:
 * 函数的BUG点:
 * 函数的其他描述：
 * 函数是否完成：
*********************************************************************/
void cmdDialog::on_sendPushButton_clicked()
{
    GetCmdData ();
    sendCmdData();
}
/********************************************************************
 * 函数的描述: 发送命令数据
 * 函数的注意:
 * 函数的待完成项:
 * 函数的BUG点:
 * 函数的其他描述：
 * 函数是否完成：
*********************************************************************/
void cmdDialog::sendCmdData()
{
    //qDebug()<<"发送";
        QList<char > CmdData;
        CmdData.clear();
        int i =0;
        for(i = 0; i<10; i++)
        {
            if (cmdData[i] != -1)
            {
                CmdData.append (cmdData[i]);
            }
        }
        //can->SendData (SENDID,CmdData);
         emit signals_CmdData(CmdData);
        this->hide ();
}

/*设置SENDID */
void cmdDialog::setSENDID(unsigned int p_sendId)
{
    SENDID = p_sendId;
}

/********************************************************************
 * 函数的描述: 设置通讯的句柄
 * 函数的注意:
 * 函数的待完成项:
 * 函数的BUG点:
 * 函数的其他描述：
 * 函数的return值：-1 已经有句柄
*********************************************************************/
int cmdDialog::setComm(CANcommuniction * setCan)
{
    if(can == nullptr)
    {
        can = setCan;
        return 1;
    }
    else
    {
        return -1;
    }
}
