#include "e2prommainwindow.h"
#include "ui_e2prommainwindow.h"

E2PROMMainWindow::E2PROMMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::E2PROMMainWindow)
{
    ui->setupUi(this);
    //ui->Struct_textEdit->setPlainText ("werqerq\n werqreqrew");
    //ui->Struct_textEdit->setReadOnly (true);
    ui->Struct_treeWidget->setHeaderLabels ({"StructName " , " DEC_value" ,"Hex_value " , " type"});



    ui->comboBox->addItem ("BootInfo");
    ui->comboBox->addItem ("CommIntfc");
    ui->comboBox->addItem ("PlanInfo");
    ui->comboBox->addItem ("PvtInfo");
    ui->comboBox->addItem ("DeviceInfo");
    ui->comboBox->addItem ("SystemInfo");
    ui->comboBox->addItem ("MotorInfo");
    ui->comboBox->addItem ("MotionInfo");
    ui->comboBox->addItem ("ReportInfo");
    ui->comboBox->addItem ("TrigInInfo");
    ui->comboBox->addItem ("DigitalOut");

    ui->comboBox->addItem ("IsolatorOut");
    ui->comboBox->addItem ("SensorUart");
    ui->comboBox->addItem ("DriverInfo");
    ui->comboBox->addItem ("SensorAlarm");

}

E2PROMMainWindow::~E2PROMMainWindow()
{
    delete ui;
}


void E2PROMMainWindow::analysisStruct(QString StructFileNamePath)
{
    /*获取文件的名字*/
    //QString StructFileName = StructFileNamePath.split (".").at (0);

    QFile file(StructFileNamePath);
    file.open (QIODevice::ReadOnly | QIODevice::Text);
    QByteArray Struct_Hex ;//需要获取文本的HEX信息
    Struct_Hex = file.readAll ();

    QByteArray tmp ;
    char data[Struct_Hex.split (' ').count ()+1];
    qDebug()<<Struct_Hex.split (' ')<< "  "<<Struct_Hex.size ();
    int i =0 ;
    for(i = 0; i <Struct_Hex.split (' ').count (); i++)
    {
        bool ok;
        tmp.append (Struct_Hex.split (' ').at (i).toInt (&ok ,16));
        data[i] = Struct_Hex.split (' ').at (i).toInt (&ok ,16);
    }

    qDebug()<<"tmp::"<<tmp <<" "<<tmp.count ();
    QString savePath("E:/E2PROMTest");
    QFile struct_file;
    QTextStream out(&struct_file);

//    DeviceInfoStruct  g_deviceInfo;
//    SystemInfoStruct  g_systemInfo;
//    MotorInfoStruct   g_motorInfo;
//    MotionInfoStruct  g_motionInfo;
//    ReportInfoStruct  g_reportInfo;
//    TrigInInfoStruct  g_trigInInfo;
//    DigitalOutStruct  g_digitalOut;
//    IsolatorOutStruct g_isolatorOut;
//    SensorUartStruct  g_sensorUart;
//    DriverInfoStruct  g_driverInfo;

//    qDebug()<<"DeviceInfoStruct "<<sizeof (DeviceInfoStruct);
//    qDebug()<<"SystemInfoStruct "<<sizeof (SystemInfoStruct);
//    qDebug()<<"MotorInfoStruct "<<sizeof (MotorInfoStruct);
//    qDebug()<<"MotionInfoStruct "<<sizeof (MotionInfoStruct);
//    qDebug()<<"ReportInfoStruct "<<sizeof (ReportInfoStruct);
//    qDebug()<<"TrigInInfoStruct "<<sizeof (TrigInInfoStruct);

//    qDebug()<<"MotorManageStruct "<<sizeof (MotorManageStruct);
//    qDebug()<<"BootInfoStruct "<<sizeof (BootInfoStruct);



    if(StructFileName == "BootInfo")//OK
    {
        if(tmp.count ()-1 == sizeof (BootInfoStruct) )
        {
            savePath += "/BootInfoStruct_Analysis.txt";
            qDebug()<<"analysisStruct";
            struct_file.setFileName (savePath);
            struct_file.open (QIODevice::WriteOnly | QIODevice::Text);
            memcpy (&g_bootInfo ,&data ,sizeof (BootInfoStruct));


            /*获取文本内容*/
            //QByteArray().append (g_bootInfo.u8BootFlag).toHex ();
            out  << "U8  u8BootFlag "<<g_bootInfo.u8BootFlag<<" 0X" <<QByteArray().append (g_bootInfo.u8BootFlag).toHex ().toUpper ()<<"\n";
            out  << "U8  u8AppFlag "<<g_bootInfo.u8AppFlag<<" 0X" << QByteArray().append (g_bootInfo.u8AppFlag).toHex ().toUpper ()<<"\n";
            out  << "U8  u8TryCount "<<g_bootInfo.u8TryCount<<" 0X" << QByteArray().append (g_bootInfo.u8TryCount).toHex ().toUpper ()<<"\n";
            out  << "U8  au8BootVer[0] "<<g_bootInfo.au8BootVer[0]<<" 0X" << QByteArray().append (g_bootInfo.au8BootVer[0]).toHex ().toUpper ()<<"\n";
            out  << "    au8BootVer[1] "<<g_bootInfo.au8BootVer[1]<<" 0X" << QByteArray().append (g_bootInfo.au8BootVer[1]).toHex ().toUpper ()<<"\n";

            out  << "U32 u32AppBaseAddr "<<g_bootInfo.u32AppBaseAddr<<" 0X" <<QByteArray((char *)&(g_bootInfo.u32AppBaseAddr) ,4).toHex ().toUpper ()<<"\n";
            out  << "U32 u32FpgaBaseAddr "<<g_bootInfo.u32FpgaBaseAddr<<" 0X" << QByteArray((char *)&(g_bootInfo.u32FpgaBaseAddr) ,4).toHex ().toUpper ()<<"\n";
            out  << "U8  resv[0] "<<g_bootInfo.resv[0]<<" 0X" <<QByteArray().append (g_bootInfo.resv[0]).toHex ().toUpper ()<<"\n";
            out  << "    resv[1] "<<g_bootInfo.resv[1]<<" 0X" <<QByteArray().append (g_bootInfo.resv[1]).toHex ().toUpper ()<<"\n";
            out  << "    resv[2] "<<g_bootInfo.resv[2]<<" 0X" <<QByteArray().append (g_bootInfo.resv[2]).toHex ().toUpper ()<<"\n";
            out  << "    resv[3] "<<g_bootInfo.resv[3]<<" 0X" <<QByteArray().append (g_bootInfo.resv[3]).toHex ().toUpper ()<<"\n";
            out  << "    resv[4] "<<g_bootInfo.resv[4]<<" 0X" <<QByteArray().append (g_bootInfo.resv[4]).toHex ().toUpper ()<<"\n";
            out  << "    resv[5] "<<g_bootInfo.resv[5]<<" 0X" <<QByteArray().append (g_bootInfo.resv[5]).toHex ().toUpper ()<<"\n";
            out  << "    resv[6] "<<g_bootInfo.resv[6]<<" 0X" <<QByteArray().append (g_bootInfo.resv[6]).toHex ().toUpper ()<<"\n";
            out  << "    resv[7] "<<g_bootInfo.resv[7]<<" 0X" <<QByteArray().append (g_bootInfo.resv[7]).toHex ().toUpper ()<<"\n";
            out  << "    resv[8] "<<g_bootInfo.resv[8]<<" 0X" <<QByteArray().append (g_bootInfo.resv[8]).toHex ().toUpper ()<<"\n";
            out  << "    resv[9] "<<g_bootInfo.resv[9]<<" 0X" <<QByteArray().append (g_bootInfo.resv[9]).toHex ().toUpper ()<<"\n";
            out  << "    resv[10] "<<g_bootInfo.resv[10]<<" 0X" <<QByteArray().append (g_bootInfo.resv[10]).toHex ().toUpper ()<<"\n";
            out  << "    resv[11] "<<g_bootInfo.resv[11]<<" 0X" << QByteArray().append (g_bootInfo.resv[11]).toHex ().toUpper ()<<"\n";
            out  << "    resv[12] "<<g_bootInfo.resv[12]<<" 0X" << QByteArray().append (g_bootInfo.resv[12]).toHex ().toUpper ()<<"\n";
            out  << "    resv[13] "<<g_bootInfo.resv[13]<<" 0X" << QByteArray().append (g_bootInfo.resv[13]).toHex ().toUpper ()<<"\n";
            out  << "    resv[14] "<<g_bootInfo.resv[14]<<" 0X" << QByteArray().append (g_bootInfo.resv[14]).toHex ().toUpper ()<<"\n";
            out  << "    resv[15] "<<g_bootInfo.resv[15]<<" 0X" << QByteArray().append (g_bootInfo.resv[15]).toHex ().toUpper ()<<"\n";
            out  << "    resv[16] "<<g_bootInfo.resv[16]<<" 0X" << QByteArray().append (g_bootInfo.resv[16]).toHex ().toUpper ()<<"\n";
            out  << "    resv[17] "<<g_bootInfo.resv[17]<<" 0X" << QByteArray().append (g_bootInfo.resv[17]).toHex ().toUpper ()<<"\n";
            out  << "    resv[18] "<<g_bootInfo.resv[18]<<" 0X" << QByteArray().append (g_bootInfo.resv[18]).toHex ().toUpper ()<<"\n";
            out  << "    resv[19] "<<g_bootInfo.resv[19]<<" 0X" << QByteArray().append (g_bootInfo.resv[19]).toHex ().toUpper ()<<"\n";
            //out  << "    resv[20] "<<g_bootInfo.resv[20]<<"\n";

            out  << "U32 crc "<<g_bootInfo.crc<<" 0X" <<QByteArray((char *)&(g_bootInfo.crc) ,4).toHex ().toUpper () <<"\n";


            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"BootInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            addtree_node (top ,\
                          "u8BootFlag" ,\
                          QString("%1").number (g_bootInfo.u8BootFlag) ,\
                          QString("0x%1").arg (QByteArray().append (g_bootInfo.u8BootFlag).toHex ().toUpper ().data ())\
                          ,"U8");
            addtree_node (top ,\
                          "u8AppFlag" ,\
                          QString("%1").number (g_bootInfo.u8AppFlag) ,\
                          QString("0x%1").arg (QByteArray().append (g_bootInfo.u8AppFlag).toHex ().toUpper ().data ())\
                          ,"U8");
            addtree_node (top ,\
                          "u8TryCount" ,\
                          QString("%1").number (g_bootInfo.u8TryCount) ,\
                          QString("0x%1").arg (QByteArray().append (g_bootInfo.u8TryCount).toHex ().toUpper ().data ())\
                          ,"U8");


            QTreeWidgetItem * au8BootVer= new QTreeWidgetItem;
            au8BootVer->setText (0, "au8BootVer");
            au8BootVer->setText (3, "array[]");
            top->addChild (au8BootVer);

            addtree_node (au8BootVer ,\
                          "[0]" ,\
                          QString("%1").number (g_bootInfo.au8BootVer[0]) ,\
                          QString("0x%1").arg (QByteArray().append (g_bootInfo.au8BootVer[0]).toHex ().toUpper ().data ())\
                          ,"U8");
            addtree_node (au8BootVer ,\
                          "[0]" ,\
                          QString("%1").number (g_bootInfo.au8BootVer[1]) ,\
                          QString("0x%1").arg (QByteArray().append (g_bootInfo.au8BootVer[1]).toHex ().toUpper ().data ())\
                          ,"U8");

            addtree_node (top ,\
                          "u32AppBaseAddr" ,\
                          QString("%1").number (g_bootInfo.u32AppBaseAddr) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_bootInfo.u32AppBaseAddr,4).toHex ().toUpper ().data ())\
                          ,"U32");
            addtree_node (top ,\
                          "u32AppBaseAddr" ,\
                          QString("%1").number (g_bootInfo.u32FpgaBaseAddr) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_bootInfo.u32FpgaBaseAddr ,4).toHex ().toUpper ().data ())\
                          ,"U32");

            QTreeWidgetItem * resv= new QTreeWidgetItem;
            resv->setText (0, "resv");
            resv->setText (3, "array[]");
            top->addChild (resv);
            int clc = 0;
            for(clc = 0 ; clc <20 ;clc++)
            {
                addtree_node (resv ,\
                              QString("[%1]").arg (clc),\
                              QString("%1").number (g_bootInfo.resv[clc]) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_bootInfo.resv[clc] ,1).toHex ().toUpper ().data ())\
                              ,"U8");
            }

            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_bootInfo.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_bootInfo.crc ,4).toHex ().toUpper ().data ())\
                          ,"U32");



        }
        else {
            /*结构体出错*/
        }


        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "CommIntfc")
    {
        savePath += "/CommIntfcStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (CommIntfcStruct) )
        {
            memcpy (&g_commIntfc ,&Struct_Hex ,sizeof (CommIntfcStruct));
            //out<<
            out  << "LinkTypeEnum  linkType "<<g_commIntfc.linkType<<"\n";
            out  << "CanIntfcStruct  {"<<"\n";
            out  <<                  "CanTypeEnum  idType "<<g_commIntfc.canIntfc.idType<<"\n";
            out  <<                  "CanBaudEnum  baud   "<<g_commIntfc.canIntfc.baud<<"\n";
            out  <<                  "u32 sendId  "<<g_commIntfc.canIntfc.sendId<<"\n";
            out  <<                  "u32 receiveId  "<<g_commIntfc.canIntfc.receiveId<<"\n";
            out  <<                  "u32 groupId1  "<<g_commIntfc.canIntfc.groupId1<<"\n";
            out  <<                  "u32 groupId2  "<<g_commIntfc.canIntfc.groupId2<<"\n";
            out  <<                  "u32 radioId  "<<g_commIntfc.canIntfc.radioId<<"\n";
            out  << "                 }canIntfc ;"<<"\n";

            out  << "UartIntfcStruct  {"<<"\n";
            out  <<                  "UartBaudEnum  baud "<<g_commIntfc.uartIntfc.baud<<"\n";
            out  <<                  "WordLenEnum   wordLen "<<g_commIntfc.uartIntfc.wordLen<<"\n";
            out  <<                  "StopBitEnum   stopBit "<<g_commIntfc.uartIntfc.stopBit<<"\n";
            out  <<                  "ParityEnum    parity "<<g_commIntfc.uartIntfc.parity<<"\n";
            out  <<                  "FlowCtlEnum   flowCtl "<<g_commIntfc.uartIntfc.flowCtl<<"\n";
            out  << "                 } uartIntfc ;"<<"\n";

            out  << "u8  reserve[0] "<< g_commIntfc.reserve[0] <<"\n";
            out  << "    reserve[1] "<< g_commIntfc.reserve[1] <<"\n";
            out  << "    reserve[2] "<< g_commIntfc.reserve[2] <<"\n";
            out  << "    reserve[3] "<< g_commIntfc.reserve[3] <<"\n";
            out  << "    reserve[4] "<< g_commIntfc.reserve[4] <<"\n";
            out  << "    reserve[5] "<< g_commIntfc.reserve[5] <<"\n";
            out  << "    reserve[6] "<< g_commIntfc.reserve[6] <<"\n";
            out  << "    reserve[7] "<< g_commIntfc.reserve[7] <<"\n";
            out  << "    reserve[8] "<< g_commIntfc.reserve[8] <<"\n";
            out  << "    reserve[9] "<< g_commIntfc.reserve[9] <<"\n";
            out  << "    reserve[10] "<< g_commIntfc.reserve[10] <<"\n";
            out  << "    reserve[11] "<< g_commIntfc.reserve[11] <<"\n";
            out  << "u32 crc "<< g_commIntfc.crc <<"\n";

            /*获取文本内容*/

            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"CommIntfcStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            addtree_node (top ,\
                          "linkType" ,\
                          QString("%1").number (g_commIntfc.linkType) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.linkType ,1).toHex ().toUpper ().data ())\
                          ,"U8");

            QTreeWidgetItem * struct_node = new QTreeWidgetItem;
            struct_node->setText (0, "canIntfc");
            struct_node->setText (3, "CanIntfcStruct");
            top->addChild (struct_node);
            addtree_node (struct_node ,\
                          "idType" ,\
                          QString("%1").number (g_commIntfc.canIntfc.idType) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.canIntfc.idType ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (struct_node ,\
                          "baud" ,\
                          QString("%1").number (g_commIntfc.canIntfc.baud) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.canIntfc.baud ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (struct_node ,\
                          "group" ,\
                          QString("%1").number (g_commIntfc.canIntfc.group) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.canIntfc.group ,1).toHex ().toUpper ().data ())\
                          ,"u8");

            addtree_node (struct_node ,\
                          "sendId" ,\
                          QString("%1").number (g_commIntfc.canIntfc.sendId) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.canIntfc.sendId ,1).toHex ().toUpper ().data ())\
                          ,"u32");
            addtree_node (struct_node ,\
                          "receiveId" ,\
                          QString("%1").number (g_commIntfc.canIntfc.receiveId) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.canIntfc.receiveId ,1).toHex ().toUpper ().data ())\
                          ,"u32");
            addtree_node (struct_node ,\
                          "groupId1" ,\
                          QString("%1").number (g_commIntfc.canIntfc.groupId1) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.canIntfc.groupId1 ,1).toHex ().toUpper ().data ())\
                          ,"u32");
            addtree_node (struct_node ,\
                          "groupId2" ,\
                          QString("%1").number (g_commIntfc.canIntfc.groupId2) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.canIntfc.groupId2 ,1).toHex ().toUpper ().data ())\
                          ,"u32");
            addtree_node (struct_node ,\
                          "radioId" ,\
                          QString("%1").number (g_commIntfc.canIntfc.radioId) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.canIntfc.radioId ,1).toHex ().toUpper ().data ())\
                          ,"u32");


            QTreeWidgetItem * struct_node1 = new QTreeWidgetItem;
            struct_node1->setText (0, "uartIntfc");
            struct_node1->setText (3, "UartIntfcStruct");
            top->addChild (struct_node1);
            addtree_node (struct_node1 ,\
                          "baud" ,\
                          QString("%1").number (g_commIntfc.uartIntfc.baud) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.uartIntfc.baud ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (struct_node1 ,\
                          "wordLen" ,\
                          QString("%1").number (g_commIntfc.uartIntfc.wordLen) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.uartIntfc.wordLen ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (struct_node1 ,\
                          "stopBit" ,\
                          QString("%1").number (g_commIntfc.uartIntfc.stopBit) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.uartIntfc.stopBit ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (struct_node1 ,\
                          "parity" ,\
                          QString("%1").number (g_commIntfc.uartIntfc.parity) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.uartIntfc.parity ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (struct_node1 ,\
                          "flowCtl" ,\
                          QString("%1").number (g_commIntfc.uartIntfc.flowCtl) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.uartIntfc.flowCtl ,1).toHex ().toUpper ().data ())\
                          ,"u8");


            QTreeWidgetItem * reserve= new QTreeWidgetItem;
            reserve->setText (0, "reserve");
            reserve->setText (3, "array[]");
            top->addChild (reserve);
            int clc = 0;
            for(clc = 0 ; clc <12 ;clc++)
            {
                addtree_node (reserve ,\
                              QString("[%1]").arg (clc),\
                              QString("%1").number (g_commIntfc.reserve[clc]) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.reserve[clc] ,1).toHex ().toUpper ().data ())\
                              ,"U8");
            }

            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_commIntfc.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_commIntfc.crc ,4).toHex ().toUpper ().data ())\
                          ,"U32");

            //g_commIntfc;
        }
        else {
            /*结构体出错*/
        }

        /* 打开文本 解析处理工作*/
        return;
    }

    if(StructFileName == "PlanInfo")
    {

        savePath += "/PlanInfoStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (PlanInfoStruct) )
        {
            memcpy (&g_planInfo ,&Struct_Hex ,sizeof (PlanInfoStruct));
            /*获取文本内容*/
            int i = 0 , j = 0 ;
            for(i = 0 ; i < CH_TOTAL ; i++)
            {
                for(j = 0 ; j< WTTYPE_RESERVE ; j++)
                {
                    out  <<"PlanManageStruct  {"<<"\n";
                    out  <<"                   ExecModeEnum execMode "<<g_planInfo.plan[i][j].execMode;
                    out  <<"                   PlanModeEnum planMode "<<g_planInfo.plan[i][j].planMode;
                    out  <<"                   MotionModeEnum motionMode "<<g_planInfo.plan[i][j].motionMode;
                    out  <<"                   ModifyDutyEnum modifyDuty "<<g_planInfo.plan[i][j].modifyDuty;
                    out  <<"                   EndStateEnum endState "<<g_planInfo.plan[i][j].endState;

                    out  <<"                   u8  validPoint "<<g_planInfo.plan[i][j].validPoint;
                    out  <<"                   u8  warnPoint "<<g_planInfo.plan[i][j].warnPoint;
                    out  <<"                   u32 cycleNum "<<g_planInfo.plan[i][j].cycleNum;
                    out  <<"                   u32 bufferTime "<<g_planInfo.plan[i][j].bufferTime;

                    out  <<"                   StopDecelerationStruct { \n";
                    out  <<"                                          StopModeEnum stopMode "<<g_planInfo.plan[i][j].stopDecelInfo.stopMode<<"\n";
                    out  <<"                                          f32  distance "<<g_planInfo.plan[i][j].stopDecelInfo.distance<<"\n";
                    out  <<"                                          f32  time "<<g_planInfo.plan[i][j].stopDecelInfo.time<<"\n";
                    out  <<"                                          }stopDecelInfo ;\n";

                    out  <<"                   OutOfStepInfoStruct { \n";
                    out  <<"                                        SensorStateEnum lineState "<<g_planInfo.plan[i][j].outOfStepInfo.lineState<<"\n";
                    out  <<"                                        SensorStateEnum  totalState "<<g_planInfo.plan[i][j].outOfStepInfo.totalState<<"\n";
                    out  <<"                                        ResponseTypeEnum lineResp "<<g_planInfo.plan[i][j].outOfStepInfo.lineResp<<"\n";
                    out  <<"                                        ResponseTypeEnum totalResp "<<g_planInfo.plan[i][j].outOfStepInfo.totalResp<<"\n";
                    out  <<"                                        u16  lineOutNum "<<g_planInfo.plan[i][j].outOfStepInfo.lineOutNum<<"\n";
                    out  <<"                                        u32  totalOutNum "<<g_planInfo.plan[i][j].outOfStepInfo.totalOutNum<<"\n";

                    out  <<"                                        }outOfStepInfo ;\n";

                    out  << "                 } plan["<<i<<"]"<<"["<<j<<"] ;"<<"\n";

                }
            }

            out <<"u32 crc "<<g_planInfo.crc<<"\n";


            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"PlanInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * plan = new QTreeWidgetItem;
            plan->setText (0, "plan");
            plan->setText (3, "PlanManageStruct[][]");
            top->addChild (plan);

            for(i = 0 ; i < CH_TOTAL ; i++)
            {
                QTreeWidgetItem * plan_x = new QTreeWidgetItem;
                plan_x->setText (0, QString("plan[%1]").arg (i));
                plan_x->setText (3, "PlanManageStruct[]");
                plan->addChild (plan_x);


                for(j = 0 ; j< WTTYPE_RESERVE ; j++)
                {
                    QTreeWidgetItem * plan_x_x = new QTreeWidgetItem;
                    plan_x_x->setText (0, QString("[%1]").arg (j));
                    plan_x_x->setText (3, "PlanManageStruct[]");
                    plan_x->addChild (plan_x_x);

                    addtree_node (plan_x_x ,\
                                  "execMode" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].execMode) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].execMode ,1).toHex ().toUpper ().data ())\
                                  ,"U8");
                    addtree_node (plan_x_x ,\
                                  "planMode" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].planMode) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].planMode ,1).toHex ().toUpper ().data ())\
                                  ,"U8");
                    addtree_node (plan_x_x ,\
                                  "motionMode" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].motionMode) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].motionMode ,1).toHex ().toUpper ().data ())\
                                  ,"U8");
                    addtree_node (plan_x_x ,\
                                  "modifyDuty" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].modifyDuty) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].modifyDuty ,1).toHex ().toUpper ().data ())\
                                  ,"U8");

                    addtree_node (plan_x_x ,\
                                  "endState" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].endState) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].endState ,1).toHex ().toUpper ().data ())\
                                  ,"U8");

                    addtree_node (plan_x_x ,\
                                  "validPoint" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].validPoint) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].validPoint ,1).toHex ().toUpper ().data ())\
                                  ,"U8");
                    addtree_node (plan_x_x ,\
                                  "warnPoint" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].warnPoint) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].warnPoint ,1).toHex ().toUpper ().data ())\
                                  ,"U8");

                    addtree_node (plan_x_x ,\
                                  "cycleNum" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].cycleNum) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].cycleNum ,4).toHex ().toUpper ().data ())\
                                  ,"U32");

                    addtree_node (plan_x_x ,\
                                  "bufferTime" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].bufferTime) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].bufferTime ,4).toHex ().toUpper ().data ())\
                                  ,"U32");

                    QTreeWidgetItem * plan_x_x_stopDecelInfo = new QTreeWidgetItem;
                    plan_x_x_stopDecelInfo->setText (0, "stopDecelInfo");
                    plan_x_x_stopDecelInfo->setText (3, "StopDecelerationStruct");
                    plan_x_x->addChild (plan_x_x_stopDecelInfo);
                    addtree_node (plan_x_x_stopDecelInfo ,\
                                  "stopMode" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].stopDecelInfo.stopMode) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].stopDecelInfo.stopMode ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
                    addtree_node (plan_x_x_stopDecelInfo ,\
                                  "distance" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].stopDecelInfo.distance) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].stopDecelInfo.distance ,4).toHex ().toUpper ().data ())\
                                  ,"f32");
                    addtree_node (plan_x_x_stopDecelInfo ,\
                                  "time" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].stopDecelInfo.time) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].stopDecelInfo.time ,4).toHex ().toUpper ().data ())\
                                  ,"f32");

                    QTreeWidgetItem * plan_x_x_outOfStepInfo = new QTreeWidgetItem;
                    plan_x_x_outOfStepInfo->setText (0, "outOfStepInfo");
                    plan_x_x_outOfStepInfo->setText (3, "OutOfStepInfoStruct");
                    plan_x_x->addChild (plan_x_x_outOfStepInfo);
                    addtree_node (plan_x_x_outOfStepInfo ,\
                                  "lineState" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].outOfStepInfo.lineState) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].outOfStepInfo.lineState ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
                    addtree_node (plan_x_x_outOfStepInfo ,\
                                  "totalState" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].outOfStepInfo.totalState) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].outOfStepInfo.totalState ,1).toHex ().toUpper ().data ())\
                                  ,"u8");

                    addtree_node (plan_x_x_outOfStepInfo ,\
                                  "lineResp" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].outOfStepInfo.lineResp) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].outOfStepInfo.lineResp ,1).toHex ().toUpper ().data ())\
                                  ,"u8");

                    addtree_node (plan_x_x_outOfStepInfo ,\
                                  "totalResp" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].outOfStepInfo.totalResp) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].outOfStepInfo.totalResp ,1).toHex ().toUpper ().data ())\
                                  ,"u8");

                    addtree_node (plan_x_x_outOfStepInfo ,\
                                  "lineOutNum" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].outOfStepInfo.lineOutNum) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].outOfStepInfo.lineOutNum ,2).toHex ().toUpper ().data ())\
                                  ,"u16");

                    addtree_node (plan_x_x_outOfStepInfo ,\
                                  "totalOutNum" ,\
                                  QString("%1").number (g_planInfo.plan[i][j].outOfStepInfo.totalOutNum) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.plan[i][j].outOfStepInfo.totalOutNum ,4).toHex ().toUpper ().data ())\
                                  ,"u32");
                }
            }
            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_planInfo.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_planInfo.crc ,4).toHex ().toUpper ().data ())\
                          ,"U32");




            //g_planInfo;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "PvtInfo")
    {
        savePath += "/PvtInfoStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (PvtInfoStruct) )
        {

            memcpy (&pvtPointBuffer ,&data ,sizeof (PvtInfoStruct));
            int i = 0 ,j =  0 ;
            out<<"CH0.....................................\n";
            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[0].mainPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[0].mainPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[0].mainPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[0].mainPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[0].mainPvtPoint[i].decScale<<"\n";
                out<<"               }mainPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[0].smallPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[0].smallPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[0].smallPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[0].smallPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[0].smallPvtPoint[i].decScale<<"\n";
                out<<"               }smallPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(j = 0 ; j<PRESET_RESERVE; j++)
            {
                for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
                {
                    out<<"PvtPointStruct { \n";
                    out<<"                f32 position "<<pvtPointBuffer[0].presetPvtPoint[j][i].position<<"\n";
                    out<<"                f32 speed "<<pvtPointBuffer[0].presetPvtPoint[j][i].speed<<"\n";
                    out<<"                f32 time "<<pvtPointBuffer[0].presetPvtPoint[j][i].time<<"\n";
                    out<<"                u16 accScale "<<pvtPointBuffer[0].presetPvtPoint[j][i].accScale<<"\n";
                    out<<"                u16 decScale "<<pvtPointBuffer[0].presetPvtPoint[j][i].decScale<<"\n";
                    out<<"               }presetPvtPoint"<<"["<<j<<"]["<<i<<"] \n";
                }
            }

            out <<"u32 crc "<<pvtPointBuffer->crc<<"\n";

            out<<"CH1.....................................\n";
            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[1].mainPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[1].mainPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[1].mainPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[1].mainPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[1].mainPvtPoint[i].decScale<<"\n";
                out<<"               }mainPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[1].smallPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[1].smallPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[1].smallPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[1].smallPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[1].smallPvtPoint[i].decScale<<"\n";
                out<<"               }smallPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(j = 0 ; j<PRESET_RESERVE; j++)
            {
                for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
                {
                    out<<"PvtPointStruct { \n";
                    out<<"                f32 position "<<pvtPointBuffer[1].presetPvtPoint[j][i].position<<"\n";
                    out<<"                f32 speed "<<pvtPointBuffer[1].presetPvtPoint[j][i].speed<<"\n";
                    out<<"                f32 time "<<pvtPointBuffer[1].presetPvtPoint[j][i].time<<"\n";
                    out<<"                u16 accScale "<<pvtPointBuffer[1].presetPvtPoint[j][i].accScale<<"\n";
                    out<<"                u16 decScale "<<pvtPointBuffer[1].presetPvtPoint[j][i].decScale<<"\n";
                    out<<"               }presetPvtPoint"<<"["<<j<<"]["<<i<<"] \n";
                }
            }
            out <<"u32 crc "<<pvtPointBuffer->crc<<"\n";

            out<<"CH2.....................................\n";
            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[2].mainPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[2].mainPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[2].mainPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[2].mainPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[2].mainPvtPoint[i].decScale<<"\n";
                out<<"               }mainPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[2].smallPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[2].smallPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[2].smallPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[2].smallPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[2].smallPvtPoint[i].decScale<<"\n";
                out<<"               }smallPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(j = 0 ; j<PRESET_RESERVE; j++)
            {
                for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
                {
                    out<<"PvtPointStruct { \n";
                    out<<"                f32 position "<<pvtPointBuffer[2].presetPvtPoint[j][i].position<<"\n";
                    out<<"                f32 speed "<<pvtPointBuffer[2].presetPvtPoint[j][i].speed<<"\n";
                    out<<"                f32 time "<<pvtPointBuffer[2].presetPvtPoint[j][i].time<<"\n";
                    out<<"                u16 accScale "<<pvtPointBuffer[2].presetPvtPoint[j][i].accScale<<"\n";
                    out<<"                u16 decScale "<<pvtPointBuffer[2].presetPvtPoint[j][i].decScale<<"\n";
                    out<<"               }presetPvtPoint"<<"["<<j<<"]["<<i<<"] \n";
                }
            }
            out <<"u32 crc "<<pvtPointBuffer->crc<<"\n";

            out<<"CH3.....................................\n";
            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[3].mainPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[3].mainPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[3].mainPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[3].mainPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[3].mainPvtPoint[i].decScale<<"\n";
                out<<"               }mainPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[3].smallPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[3].smallPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[3].smallPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[3].smallPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[3].smallPvtPoint[i].decScale<<"\n";
                out<<"               }smallPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(j = 0 ; j<PRESET_RESERVE; j++)
            {
                for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
                {
                    out<<"PvtPointStruct { \n";
                    out<<"                f32 position "<<pvtPointBuffer[3].presetPvtPoint[j][i].position<<"\n";
                    out<<"                f32 speed "<<pvtPointBuffer[3].presetPvtPoint[j][i].speed<<"\n";
                    out<<"                f32 time "<<pvtPointBuffer[3].presetPvtPoint[j][i].time<<"\n";
                    out<<"                u16 accScale "<<pvtPointBuffer[3].presetPvtPoint[j][i].accScale<<"\n";
                    out<<"                u16 decScale "<<pvtPointBuffer[3].presetPvtPoint[j][i].decScale<<"\n";
                    out<<"               }presetPvtPoint"<<"["<<j<<"]["<<i<<"] \n";
                }
            }
            out <<"u32 crc "<<pvtPointBuffer->crc<<"\n";


            out<<"CH4.....................................\n";
            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[4].mainPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[4].mainPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[4].mainPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[4].mainPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[4].mainPvtPoint[i].decScale<<"\n";
                out<<"               }mainPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
            {
                out<<"PvtPointStruct { \n";
                out<<"                f32 position "<<pvtPointBuffer[4].smallPvtPoint[i].position<<"\n";
                out<<"                f32 speed "<<pvtPointBuffer[4].smallPvtPoint[i].speed<<"\n";
                out<<"                f32 time "<<pvtPointBuffer[4].smallPvtPoint[i].time<<"\n";
                out<<"                u16 accScale "<<pvtPointBuffer[4].smallPvtPoint[i].accScale<<"\n";
                out<<"                u16 decScale "<<pvtPointBuffer[4].smallPvtPoint[i].decScale<<"\n";
                out<<"               }smallPvtPoint"<<"["<<i<<"]"<<"\n";
            }

            for(j = 0 ; j<PRESET_RESERVE; j++)
            {
                for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
                {
                    out<<"PvtPointStruct { \n";
                    out<<"                f32 position "<<pvtPointBuffer[4].presetPvtPoint[j][i].position<<"\n";
                    out<<"                f32 speed "<<pvtPointBuffer[4].presetPvtPoint[j][i].speed<<"\n";
                    out<<"                f32 time "<<pvtPointBuffer[4].presetPvtPoint[j][i].time<<"\n";
                    out<<"                u16 accScale "<<pvtPointBuffer[4].presetPvtPoint[j][i].accScale<<"\n";
                    out<<"                u16 decScale "<<pvtPointBuffer[4].presetPvtPoint[j][i].decScale<<"\n";
                    out<<"               }presetPvtPoint"<<"["<<j<<"]["<<i<<"] \n";
                }
            }

            out <<"u32 crc "<<pvtPointBuffer->crc<<"\n";


            /*获取文本内容*/
            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"PvtInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            int ch_count = 0 ;
            for(ch_count = 0 ; ch_count<CH_TOTAL ; ch_count++)
            {
                qDebug()<<"dfg 739";
                QTreeWidgetItem * PvtInfoStruct = new QTreeWidgetItem;
                PvtInfoStruct->setText (0, QString("[%1]").arg (ch_count));
                PvtInfoStruct->setText (3, "PvtInfoStruct");
                top->addChild (PvtInfoStruct);

                QTreeWidgetItem * mainPvtPoint = new QTreeWidgetItem;
                mainPvtPoint->setText (0, "mainPvtPoint");
                mainPvtPoint->setText (3, "PvtPointStruct[]");
                PvtInfoStruct->addChild (mainPvtPoint);

                QTreeWidgetItem * smallPvtPoint = new QTreeWidgetItem;
                smallPvtPoint->setText (0, "smallPvtPoint");
                smallPvtPoint->setText (3, "PvtPointStruct[]");
                PvtInfoStruct->addChild (smallPvtPoint);

                QTreeWidgetItem * presetPvtPoint = new QTreeWidgetItem;
                presetPvtPoint->setText (0, "presetPvtPoint");
                presetPvtPoint->setText (3, "PvtPointStruct[][]");
                PvtInfoStruct->addChild (presetPvtPoint);


                for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
                {
                    qDebug()<<"dfg 817";
                    QTreeWidgetItem * smallPvtPoint_x = new QTreeWidgetItem;
                    smallPvtPoint_x->setText (0, QString("[%1]").arg (i));
                    smallPvtPoint_x->setText (3, "PvtPointStruct");
                    smallPvtPoint->addChild (smallPvtPoint_x);

                    addtree_node (smallPvtPoint_x ,\
                                  "position" ,\
                                  QString("%1").number (pvtPointBuffer[4].smallPvtPoint[i].position) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].smallPvtPoint[i].position ,4).toHex ().toUpper ().data ())\
                                  ,"f32");
                    addtree_node (smallPvtPoint_x ,\
                                  "speed" ,\
                                  QString("%1").number (pvtPointBuffer[4].smallPvtPoint[i].speed) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].smallPvtPoint[i].speed ,4).toHex ().toUpper ().data ())\
                                  ,"f32");

                    addtree_node (smallPvtPoint_x ,\
                                  "time" ,\
                                  QString("%1").number (pvtPointBuffer[4].smallPvtPoint[i].time) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].smallPvtPoint[i].time ,4).toHex ().toUpper ().data ())\
                                  ,"f32");

                    addtree_node (smallPvtPoint_x ,\
                                  "accScale" ,\
                                  QString("%1").number (pvtPointBuffer[4].smallPvtPoint[i].accScale) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].smallPvtPoint[i].accScale ,4).toHex ().toUpper ().data ())\
                                  ,"f32");
                    addtree_node (smallPvtPoint_x ,\
                                  "decScale" ,\
                                  QString("%1").number (pvtPointBuffer[4].smallPvtPoint[i].time) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].smallPvtPoint[i].decScale ,4).toHex ().toUpper ().data ())\
                                  ,"f32");
                }


                for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
                {
                    qDebug()<<"dfg 855";
                    QTreeWidgetItem * mainPvtPoint_x = new QTreeWidgetItem;
                    mainPvtPoint_x->setText (0, QString("[%1]").arg (i));
                    mainPvtPoint_x->setText (3, "PvtPointStruct");
                    mainPvtPoint->addChild (mainPvtPoint_x);

                    addtree_node (mainPvtPoint_x ,\
                                  "position" ,\
                                  QString("%1").number (pvtPointBuffer[4].mainPvtPoint[i].position) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].mainPvtPoint[i].position ,4).toHex ().toUpper ().data ())\
                                  ,"f32");
                    addtree_node (mainPvtPoint_x ,\
                                  "speed" ,\
                                  QString("%1").number (pvtPointBuffer[4].mainPvtPoint[i].speed) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].mainPvtPoint[i].speed ,4).toHex ().toUpper ().data ())\
                                  ,"f32");

                    addtree_node (mainPvtPoint_x ,\
                                  "time" ,\
                                  QString("%1").number (pvtPointBuffer[4].mainPvtPoint[i].time) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].mainPvtPoint[i].time ,4).toHex ().toUpper ().data ())\
                                  ,"f32");

                    addtree_node (mainPvtPoint_x ,\
                                  "accScale" ,\
                                  QString("%1").number (pvtPointBuffer[4].mainPvtPoint[i].accScale) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].mainPvtPoint[i].accScale ,4).toHex ().toUpper ().data ())\
                                  ,"f32");
                    addtree_node (mainPvtPoint_x ,\
                                  "decScale" ,\
                                  QString("%1").number (pvtPointBuffer[4].mainPvtPoint[i].time) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[4].mainPvtPoint[i].decScale ,4).toHex ().toUpper ().data ())\
                                  ,"f32");
                }

                for(j = 0 ; j<PRESET_RESERVE; j++)
                {
                    QTreeWidgetItem * presetPvtPoint_x = new QTreeWidgetItem;
                    presetPvtPoint_x->setText (0, QString("presetPvtPoint[%1]").arg (i));
                    presetPvtPoint_x->setText (3, "PvtPointStruct[]");
                    presetPvtPoint->addChild (presetPvtPoint_x);

                    for(i = 0 ; i <PVT_POINT_BUFFER_SIZE ;i++)
                    {
                        qDebug()<<"dfg 899"<<j<<i;
                        QTreeWidgetItem * presetPvtPoint_x_x = new QTreeWidgetItem;
                        qDebug()<<"dfg 902"<<j<<i;
                        presetPvtPoint_x_x->setText (0, QString("[%1]").arg (i));
                        presetPvtPoint_x_x->setText (3, "PvtPointStruct");
                        presetPvtPoint_x->addChild (presetPvtPoint_x_x);


                        addtree_node (presetPvtPoint_x_x ,\
                                      "position" ,\
                                      QString("%1").number (pvtPointBuffer[ch_count].presetPvtPoint[j][i].position) ,\
                                      QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[ch_count].presetPvtPoint[j][i].position ,4).toHex ().toUpper ().data ())\
                                      ,"f32");

                        addtree_node (presetPvtPoint_x_x ,\
                                      "speed" ,\
                                      QString("%1").number (pvtPointBuffer[ch_count].presetPvtPoint[j][i].speed) ,\
                                      QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[ch_count].presetPvtPoint[j][i].speed ,4).toHex ().toUpper ().data ())\
                                      ,"f32");

                        qDebug()<<"dfg 918"<<j<<i;
                        addtree_node (presetPvtPoint_x_x ,\
                                      "time" ,\
                                      QString("%1").number (pvtPointBuffer[ch_count].presetPvtPoint[j][i].time) ,\
                                      QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[ch_count].presetPvtPoint[j][i].time ,4).toHex ().toUpper ().data ())\
                                      ,"f32");

                        addtree_node (presetPvtPoint_x_x ,\
                                      "accScale" ,\
                                      QString("%1").number (pvtPointBuffer[ch_count].presetPvtPoint[j][i].accScale) ,\
                                      QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[ch_count].presetPvtPoint[j][i].accScale ,4).toHex ().toUpper ().data ())\
                                      ,"f32");
                        addtree_node (presetPvtPoint_x_x ,\
                                      "decScale" ,\
                                      QString("%1").number (pvtPointBuffer[ch_count].presetPvtPoint[j][i].time) ,\
                                      QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[ch_count].presetPvtPoint[j][i].decScale ,4).toHex ().toUpper ().data ())\
                                      ,"f32");
                        qDebug()<<"dfg 933"<<j<<i;
                    }
                }

                addtree_node (top ,\
                              "crc" ,\
                              QString("%1").number (pvtPointBuffer[ch_count].crc) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&pvtPointBuffer[ch_count].crc ,4).toHex ().toUpper ().data ())\
                              ,"U32");

            }


        }
        else {
            /*结构体出错*/
        }
        //pvtPointBuffer[CH_TOTAL];
        /* 打开文本 解析处理工作*/
        return;
    }

    if(StructFileName == "DeviceInfo")
    {
        savePath += "/DeviceInfoStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (DeviceInfoStruct) )
        {
            savePath += "/BootInfoStruct_Analysis.txt";
            qDebug()<<"analysisStruct";
            struct_file.setFileName (savePath);
            struct_file.open (QIODevice::WriteOnly | QIODevice::Text);
            memcpy (&g_deviceInfo ,&data ,sizeof (DeviceInfoStruct));
            /*获取文本内容*/
            out<<"MotorInfoStruct \n";
            out<<"{\n";


            out<<"  storageInfo \n";
            out<<"  {\n";
            out<<"    sDevcModel " <<g_deviceInfo.storageInfo.sDevcModel;
            out<<"\n";
            int i = 0;
            for(i = 0 ; i<DEVICE_SN_LEN ; i++)
            {
                out<<"    deviceSn["<<i<<"] " <<g_deviceInfo.storageInfo.deviceSn[i];
                out<<"\n";
            }
            out<<"    crc "<<g_deviceInfo.storageInfo.crc;
            out<<"\n";
            out<<"  }\n";

            out<<"  mDevcModel "<<g_deviceInfo.mDevcModel;
            out<<"\n";
            out<<"  sDevcModel "<<g_deviceInfo.sDevcModel;
            out<<"\n";

            out<<"  fpga \n";
            out<<"  {\n";
            for(i = 0 ; i<FPGA_VER_LEN ; i++)
            {
                out<<"    verArray["<<i<<"] " <<g_deviceInfo.fpga.verArray[i];
                out<<"\n";
            }


            out<<"    verStruct \n";
            out<<"    {\n";
            out<<"      majorType "<<g_deviceInfo.fpga.verStruct.majorType;
            out<<"\n";
            out<<"      minorType "<<g_deviceInfo.fpga.verStruct.minorType;
            out<<"\n";
            out<<"      hardVer "<<g_deviceInfo.fpga.verStruct.hardVer;
            out<<"\n";
            out<<"      majorVer "<<g_deviceInfo.fpga.verStruct.majorVer;
            out<<"\n";
            out<<"      minorVer "<<g_deviceInfo.fpga.verStruct.minorVer;
            out<<"\n";
            out<<"      buildVer "<<g_deviceInfo.fpga.verStruct.buildVer;
            out<<"\n";
            out<<"    }\n";

            out<<"\n";
            out<<"  }\n";



            for(i = 0 ; i<SOFTWARE_VER_LEN ; i++)
            {
                out<<"  software["<<i<<"] " <<g_deviceInfo.software[i];
                out<<"\n";
            }

            for(i = 0 ; i<HARDWARE_VER_LEN ; i++)
            {
                out<<"  hardware["<<i<<"] " <<g_deviceInfo.hardware[i];
                out<<"\n";
            }

            for(i = 0 ; i<BOOT_VER_LEN ; i++)
            {
                out<<"  boot["<<i<<"] " <<g_deviceInfo.boot[i];
                out<<"\n";
            }

            for(i = 0 ; i<DRVBOARD_VER_LEN ; i++)
            {
                out<<"  driverBoardDn["<<i<<"] " <<g_deviceInfo.driverBoardDn[i];
                out<<"\n";
            }

            for(i = 0 ; i<DRVBOARD_VER_LEN ; i++)
            {
                out<<"  driverBoardUp["<<i<<"] " <<g_deviceInfo.driverBoardUp[i];
                out<<"\n";
            }
            out<<"}\n";



            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"DeviceInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * storageInfo = new QTreeWidgetItem;
            storageInfo->setText (0, "storageInfo");
            storageInfo->setText (3, "DeviceInfoStorageStruct");
            top->addChild (storageInfo);
            addtree_node (storageInfo ,\
                          "sDevcModel" ,\
                          QString("%1").number (g_deviceInfo.storageInfo.sDevcModel) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.storageInfo.sDevcModel ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            QTreeWidgetItem * deviceSn = new QTreeWidgetItem;
            deviceSn->setText (0, "deviceSn");
            deviceSn->setText (3, "u8[]");
            storageInfo->addChild (deviceSn);
            int device_sn=0 ;
            for(device_sn = 0 ; device_sn <DEVICE_SN_LEN ;device_sn++ )
            {
                addtree_node (storageInfo ,\
                              QString("[%1]").arg (device_sn),\
                              QString("%1").number (g_deviceInfo.storageInfo.deviceSn[device_sn]) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.storageInfo.deviceSn[device_sn] ,1).toHex ().toUpper ().data ())\
                              ,"u8");
            }
            addtree_node (storageInfo ,\
                          "crc" ,\
                          QString("%1").number (g_deviceInfo.storageInfo.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.storageInfo.crc ,4).toHex ().toUpper ().data ())\
                          ,"u32");

            addtree_node (top ,\
                          "mDevcModel" ,\
                          QString("%1").number (g_deviceInfo.mDevcModel) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.mDevcModel ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (top ,\
                          "sDevcModel" ,\
                          QString("%1").number (g_deviceInfo.sDevcModel) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.sDevcModel ,1).toHex ().toUpper ().data ())\
                          ,"u8");



            QTreeWidgetItem * fpga = new QTreeWidgetItem;
            fpga->setText (0, "fpga");
            fpga->setText (3, "FpgaVersionUnion");
            top->addChild (fpga);

            QTreeWidgetItem * verArray = new QTreeWidgetItem;
            verArray->setText (0, "verArray");
            verArray->setText (3, "u8[]");
            fpga->addChild (verArray);
            for(i = 0 ; i<FPGA_VER_LEN ; i++)
            {
                addtree_node (verArray ,\
                              QString("[%1]").arg (i),\
                              QString("%1").number (g_deviceInfo.fpga.verArray[i]) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.fpga.verArray[i] ,1).toHex ().toUpper ().data ())\
                              ,"u8");
            }
            QTreeWidgetItem * verStruct = new QTreeWidgetItem;
            verStruct->setText (0, "verStruct");
            verStruct->setText (3, "FpgaVersionStruct");
            fpga->addChild (verStruct);

            addtree_node (verStruct ,\
                          "majorType",\
                          QString("%1").number (g_deviceInfo.fpga.verStruct.majorType) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.fpga.verStruct.majorType ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (verStruct ,\
                          "minorType",\
                          QString("%1").number (g_deviceInfo.fpga.verStruct.minorType) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.fpga.verStruct.minorType ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (verStruct ,\
                          "hardVer",\
                          QString("%1").number (g_deviceInfo.fpga.verStruct.hardVer) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.fpga.verStruct.hardVer ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (verStruct ,\
                          "majorVer",\
                          QString("%1").number (g_deviceInfo.fpga.verStruct.majorVer) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.fpga.verStruct.majorVer ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (verStruct ,\
                          "minorVer",\
                          QString("%1").number (g_deviceInfo.fpga.verStruct.minorVer) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.fpga.verStruct.minorVer ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (verStruct ,\
                          "buildVer",\
                          QString("%1").number (g_deviceInfo.fpga.verStruct.buildVer) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.fpga.verStruct.buildVer ,1).toHex ().toUpper ().data ())\
                          ,"u8");



            QTreeWidgetItem * software = new QTreeWidgetItem;
            software->setText (0, "software");
            software->setText (3, "u8[]");
            top->addChild (software);

            QTreeWidgetItem * hardware = new QTreeWidgetItem;
            hardware->setText (0, "hardware");
            hardware->setText (3, "u8[]");
            top->addChild (hardware);

            QTreeWidgetItem * boot = new QTreeWidgetItem;
            boot->setText (0, "boot");
            boot->setText (3, "u8[]");
            top->addChild (boot);

            QTreeWidgetItem * driverBoardDn = new QTreeWidgetItem;
            driverBoardDn->setText (0, "driverBoardDn");
            driverBoardDn->setText (3, "u8[]");
            top->addChild (driverBoardDn);

            QTreeWidgetItem * driverBoardUp = new QTreeWidgetItem;
            driverBoardUp->setText (0, "driverBoardUp");
            driverBoardUp->setText (3, "u8[]");
            top->addChild (driverBoardUp);

            for(i = 0 ; i<SOFTWARE_VER_LEN ; i++)
            {
                addtree_node (software ,\
                              QString("[%1]").arg (i),\
                              QString("%1").number (g_deviceInfo.software[i]) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.software[i] ,1).toHex ().toUpper ().data ())\
                              ,"u8");

            }

            for(i = 0 ; i<HARDWARE_VER_LEN ; i++)
            {
                addtree_node (hardware ,\
                              QString("[%1]").arg (i),\
                              QString("%1").number (g_deviceInfo.hardware[i]) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.hardware[i] ,1).toHex ().toUpper ().data ())\
                              ,"u8");
            }

            for(i = 0 ; i<BOOT_VER_LEN ; i++)
            {
                addtree_node (boot ,\
                              QString("[%1]").arg (i),\
                              QString("%1").number (g_deviceInfo.boot[i]) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.boot[i] ,1).toHex ().toUpper ().data ())\
                              ,"u8");
            }

            for(i = 0 ; i<DRVBOARD_VER_LEN ; i++)
            {
                addtree_node (driverBoardDn ,\
                              QString("[%1]").arg (i),\
                              QString("%1").number (g_deviceInfo.driverBoardDn[i]) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.driverBoardDn[i] ,1).toHex ().toUpper ().data ())\
                              ,"u8");
            }

            for(i = 0 ; i<DRVBOARD_VER_LEN ; i++)
            {
                addtree_node (driverBoardUp ,\
                              QString("[%1]").arg (i),\
                              QString("%1").number (g_deviceInfo.driverBoardUp[i]) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_deviceInfo.driverBoardUp[i] ,1).toHex ().toUpper ().data ())\
                              ,"u8");
            }


            //g_deviceInfo;

        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "SystemInfo")
    {
        savePath += "/SystemInfoStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (SystemInfoStruct) )
        {
            memcpy (&g_systemInfo ,&data ,sizeof (SystemInfoStruct));

            /*获取文本内容*/
            out<<"SystemInfoStruct {\n";
            //out<<" "

            out<<"                        }storageInfo ;";

            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"SystemInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);
            addtree_node (top ,\
                          "workMode" ,\
                          QString("%1").number (g_systemInfo.workMode) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.workMode ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (top ,\
                          "powerOn" ,\
                          QString("%1").number (g_systemInfo.powerOn) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.powerOn ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (top ,\
                          "revMotion" ,\
                          QString("%1").number (g_systemInfo.revMotion) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.revMotion ,1).toHex ().toUpper ().data ())\
                          ,"u8");

            QTreeWidgetItem * group = new QTreeWidgetItem;
            group->setText (0, "group");
            group->setText (3, "u8[][]");
            top->addChild (group);
            int i = 0 , j = 0 ;
            for(i = 0 ; i<CH_TOTAL; i++)
            {
                QTreeWidgetItem * group_x = new QTreeWidgetItem;
                group_x->setText (0, QString("group[%1]").arg (i));
                group_x->setText (3, "u8[]");
                group->addChild (group_x);
                for(j = 0 ; j < GROUP_NUM; j++)
                {
                    addtree_node (group_x ,\
                                  QString("[%1]").arg (j) ,\
                                  QString("%1").number (g_systemInfo.group[i][j]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.group[i][j] ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
                }
            }

            QTreeWidgetItem * mainLabel = new QTreeWidgetItem;
            mainLabel->setText (0, "mainLabel");
            mainLabel->setText (3, "u8[]");
            top->addChild (mainLabel);
            for(i = 0 ; i<CH_TOTAL; i++)
            {

                    addtree_node (mainLabel ,\
                                  QString("[%1]").arg (i) ,\
                                  QString("%1").number (g_systemInfo.mainLabel[i]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.mainLabel[i] ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
            }

            QTreeWidgetItem * subLabel = new QTreeWidgetItem;
            subLabel->setText (0, "subLabel");
            subLabel->setText (3, "u8[]");
            top->addChild (subLabel);
            for(i = 0 ; i<CH_TOTAL; i++)
            {

                    addtree_node (subLabel ,\
                                  QString("[%1]").arg (i) ,\
                                  QString("%1").number (g_systemInfo.subLabel[i]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.subLabel[i] ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
            }

            addtree_node (top ,\
                          "fanDuty" ,\
                          QString("%1").number (g_systemInfo.fanDuty) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.fanDuty ,1).toHex ().toUpper ().data ())\
                          ,"u8");

            QTreeWidgetItem * armLedDuty = new QTreeWidgetItem;
            armLedDuty->setText (0, "armLedDuty");
            armLedDuty->setText (3, "u8[]");
            top->addChild (armLedDuty);
            for(i = 0 ; i<ARMLED_RESERVE; i++)
            {

                    addtree_node (armLedDuty ,\
                                  QString("[%1]").arg (i) ,\
                                  QString("%1").number (g_systemInfo.armLedDuty[i]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.armLedDuty[i] ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
            }

            addtree_node (top ,\
                          "fanFrequency" ,\
                          QString("%1").number (g_systemInfo.fanFrequency) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.fanFrequency ,1).toHex ().toUpper ().data ())\
                          ,"u8");


            QTreeWidgetItem * armLedFreq = new QTreeWidgetItem;
            armLedFreq->setText (0, "armLedFreq");
            armLedFreq->setText (3, "u32[]");
            top->addChild (armLedFreq);
            for(i = 0 ; i<ARMLED_RESERVE; i++)
            {

                    addtree_node (armLedFreq ,\
                                  QString("[%1]").arg (i) ,\
                                  QString("%1").number (g_systemInfo.armLedFreq[i]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.armLedFreq[i] ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
            }

            QTreeWidgetItem * otpInfo = new QTreeWidgetItem;
            otpInfo->setText (0, "otpInfo");
            otpInfo->setText (3, "OtpInfoStruct");
            top->addChild (otpInfo);
            addtree_node (otpInfo ,\
                          QString("state") ,\
                          QString("%1").number (g_systemInfo.otpInfo.state) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.otpInfo.state ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (otpInfo ,\
                          QString("response") ,\
                          QString("%1").number (g_systemInfo.otpInfo.response) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.otpInfo.response ,1).toHex ().toUpper ().data ())\
                          ,"u8");
            addtree_node (otpInfo ,\
                          QString("threshold") ,\
                          QString("%1").number (g_systemInfo.otpInfo.threshold) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.otpInfo.threshold ,2).toHex ().toUpper ().data ())\
                          ,"u16");
            addtree_node (otpInfo ,\
                          QString("period") ,\
                          QString("%1").number (g_systemInfo.otpInfo.period) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.otpInfo.period ,4).toHex ().toUpper ().data ())\
                          ,"u32");

            addtree_node (top ,\
                          "fpgaClockOffset" ,\
                          QString("%1").number (g_systemInfo.fpgaClockOffset) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.fpgaClockOffset ,4).toHex ().toUpper ().data ())\
                          ,"f32");

            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_systemInfo.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_systemInfo.crc ,4).toHex ().toUpper ().data ())\
                          ,"u32");

            /*获取文本内容*/
            g_systemInfo;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "MotorInfo")//OK
    {
        savePath += "/MotorInfoStruct_Analysis.txt";

        if(tmp.count ()-1 == sizeof (MotorInfoStruct) )
        {
            qDebug()<<"analysisStruct";
            struct_file.setFileName (savePath);
            struct_file.open (QIODevice::WriteOnly | QIODevice::Text);
            memcpy (&g_motorInfo ,&data ,sizeof (MotorInfoStruct));

            out<<"MotorInfoStruct \n";
            out<<"{\n";
            int i = 0 ;
            for(i = 0 ; i< CH_TOTAL ; i++)
            {
                out<<"  motor["<<i<<"]"<<"\n";
                out<<"  {\n";
                out<<"    motorType "<<g_motorInfo.motor[i].motorType<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].motorType).toHex ().toUpper ();
                out<<"\n";
                out<<"    stepAngel "<<g_motorInfo.motor[i].stepAngel<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].stepAngel).toHex ().toUpper ();
                out<<"\n";
                out<<"    microSteps "<<g_motorInfo.motor[i].microSteps<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].microSteps).toHex ().toUpper ();
                out<<"\n";
                out<<"    motorSize "<<g_motorInfo.motor[i].motorSize<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].motorSize).toHex ().toUpper ();
                out<<"\n";
                out<<"    encoderState "<<g_motorInfo.motor[i].encoderState<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].encoderState).toHex ().toUpper ();
                out<<"\n";
                out<<"    encoderType "<<g_motorInfo.motor[i].encoderType<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].encoderType).toHex ().toUpper ();
                out<<"\n";
                out<<"    encoderChanNum "<<g_motorInfo.motor[i].encoderChanNum<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].encoderChanNum).toHex ().toUpper ();
                out<<"\n";
                out<<"    encoderMult "<<g_motorInfo.motor[i].encoderMult<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].encoderMult).toHex ().toUpper ();
                out<<"\n";
                out<<"    posnUnit "<<g_motorInfo.motor[i].posnUnit<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].posnUnit).toHex ().toUpper ();
                out<<"\n";


                out<<"    motorVolt "<<g_motorInfo.motor[i].motorVolt<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].motorVolt).toHex ().toUpper ();
                out<<"\n";
                out<<"    motorCurr "<<g_motorInfo.motor[i].motorCurr<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].motorCurr).toHex ().toUpper ();
                out<<"\n";
                out<<"    feedbackRatio "<<g_motorInfo.motor[i].feedbackRatio<<" 0X" <<QByteArray().append (g_motorInfo.motor[i].feedbackRatio).toHex ().toUpper ();
                out<<"\n";
                out<<"    gearRatioNum "<<g_motorInfo.motor[i].gearRatioNum<<" 0X" <<QByteArray().append ((char* )&g_motorInfo.motor[i].gearRatioNum ,2).toHex ().toUpper ();
                out<<"\n";

                out<<"    gearRatioDen "<<g_motorInfo.motor[i].gearRatioDen<<" 0X" <<QByteArray().append ((char* )&g_motorInfo.motor[i].gearRatioDen ,2).toHex ().toUpper ();
                out<<"\n";

                out<<"    lead "<<g_motorInfo.motor[i].lead<<" 0X" <<QByteArray().append (( char *)&g_motorInfo.motor[i].lead ,4).toHex ().toUpper ();
                out<<"\n";
                out<<"    peakSpeed "<<g_motorInfo.motor[i].peakSpeed<<" 0X" <<QByteArray().append (( char *)&g_motorInfo.motor[i].peakSpeed ,4).toHex ().toUpper ();
                out<<"\n";
                out<<"    backlash "<<g_motorInfo.motor[i].backlash<<" 0X" <<QByteArray().append (( char *)&g_motorInfo.motor[i].backlash ,4).toHex ().toUpper ();
                out<<"\n";
                out<<"    encoderLineNum "<<g_motorInfo.motor[i].encoderLineNum<<" 0X" <<QByteArray().append (( char *)&g_motorInfo.motor[i].encoderLineNum ,4).toHex ().toUpper ();
                out<<"\n";

                out<<"  }\n";
            }
            out<<"  crc "<<g_motorInfo.crc<<" 0X" <<QByteArray().append (( char *)&g_motorInfo.crc , 4).toHex ().toUpper ();;
            out<<"\n";
            out<<"}\n";

            //qDebug()<<g_motorInfo.motor[0].encoderLineNum;
            //qDebug()<<g_motorInfo.crc;
            /*获取文本内容*/

            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"MotorInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * motor = new QTreeWidgetItem;
            motor->setText (0, QString("motor"));
            motor->setText (3, "MotorManageStruct");
            top->addChild (motor);
            int ch_count = 0 ;
            for(ch_count = 0 ; ch_count<CH_TOTAL ; ch_count++)
            {
                QTreeWidgetItem * motor_x = new QTreeWidgetItem;
                motor_x->setText (0, QString("[%1]").arg (ch_count));
                motor_x->setText (3, "MotorManageStruct");
                motor->addChild (motor_x);

                addtree_node (motor_x ,\
                              "motorType" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].motorType) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].motorType ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "stepAngel" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].stepAngel) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].stepAngel ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "microSteps" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].microSteps) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].microSteps ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "motorSize" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].motorSize) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].motorSize ,1).toHex ().toUpper ().data ())\
                              ,"u8");

                addtree_node (motor_x ,\
                              "encoderState" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].encoderState) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].encoderState ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "encoderType" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].encoderType) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].encoderType ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "encoderChanNum" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].encoderChanNum) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].encoderChanNum ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "encoderMult" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].encoderMult) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].encoderMult ,1).toHex ().toUpper ().data ())\
                              ,"u8");

                addtree_node (motor_x ,\
                              "posnUnit" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].posnUnit) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].posnUnit ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "motorVolt" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].motorVolt) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].motorVolt ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "motorCurr" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].motorCurr) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].motorCurr ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "feedbackRatio" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].feedbackRatio) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].feedbackRatio ,1).toHex ().toUpper ().data ())\
                              ,"u8");

                addtree_node (motor_x ,\
                              "gearRatioNum" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].gearRatioNum) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].gearRatioNum ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "gearRatioDen" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].gearRatioDen) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].gearRatioDen ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "lead" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].lead) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].lead ,1).toHex ().toUpper ().data ())\
                              ,"u8");

                addtree_node (motor_x ,\
                              "peakSpeed" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].peakSpeed) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].peakSpeed ,1).toHex ().toUpper ().data ())\
                              ,"u8");
                addtree_node (motor_x ,\
                              "peakAcc" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].peakAcc) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].peakAcc ,1).toHex ().toUpper ().data ())\
                              ,"u8");

                addtree_node (motor_x ,\
                              "backlash" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].backlash) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].backlash ,1).toHex ().toUpper ().data ())\
                              ,"u8");

                addtree_node (motor_x ,\
                              "encoderLineNum" ,\
                              QString("%1").number (g_motorInfo.motor[ch_count].encoderLineNum) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.motor[ch_count].encoderLineNum ,1).toHex ().toUpper ().data ())\
                              ,"u8");

            }
            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_motorInfo.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_motorInfo.crc ,4).toHex ().toUpper ().data ())\
                          ,"U32");

            //g_motorInfo;

        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "MotionInfo")
    {
        savePath += "/MotionInfoStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (MotionInfoStruct) )
        {
            memcpy (&g_motionInfo ,&data ,sizeof (MotionInfoStruct));
            /*获取文本内容*/
            out<<"MotionInfoStruct \n";
            out<<"{\n";
            int i = 0 ;
            for(i = 0 ; i< CH_TOTAL ; i++)
            {
                out<<"  motion["<<i<<"]"<<"\n";
                out<<"  {\n";
                out<<"    stateReport "<<g_motionInfo.motion[i].stateReport<<" 0X" <<QByteArray().append (g_motionInfo.motion[i].stateReport).toHex ().toUpper ();
                out<<"\n";
                out<<"    initPostUnit "<<g_motionInfo.motion[i].initPostUnit<<" 0X" <<QByteArray().append (g_motionInfo.motion[i].initPostUnit).toHex ().toUpper ();
                out<<"\n";
                out<<"    initIOPin "<<g_motionInfo.motion[i].initIOPin<<" 0X" <<QByteArray().append (g_motionInfo.motion[i].initIOPin).toHex ().toUpper ();
                out<<"\n";
                out<<"    offsetState "<<g_motionInfo.motion[i].offsetState<<" 0X" <<QByteArray().append (g_motionInfo.motion[i].offsetState).toHex ().toUpper ();
                out<<"\n";
                out<<"    reserve "<<g_motionInfo.motion[i].reserve<<" 0X" <<QByteArray().append (g_motionInfo.motion[i].reserve).toHex ().toUpper ();
                out<<"\n";
                out<<"    startSrc "<<g_motionInfo.motion[i].startSrc<<" 0X" <<QByteArray().append (g_motionInfo.motion[i].startSrc).toHex ().toUpper ();
                out<<"\n";
                out<<"    startType "<<g_motionInfo.motion[i].startType<<" 0X" <<QByteArray().append (g_motionInfo.motion[i].startType).toHex ().toUpper ();
                out<<"\n";
                out<<"    maxSpeed "<<g_motionInfo.motion[i].maxSpeed<<" 0X" <<QByteArray().append ((char* )&g_motionInfo.motion[i].maxSpeed , 4 ).toHex ().toUpper ();
                out<<"\n";
                out<<"    minSpeed "<<g_motionInfo.motion[i].minSpeed<<" 0X" <<QByteArray().append ((char* )&g_motionInfo.motion[i].minSpeed , 4 ).toHex ().toUpper ();
                out<<"\n";


                out<<"    maxPosn "<<g_motionInfo.motion[i].maxPosn<<" 0X" <<QByteArray().append ((char* )&g_motionInfo.motion[i].maxPosn , 4 ).toHex ().toUpper ();
                out<<"\n";
                out<<"    minPosn "<<g_motionInfo.motion[i].minPosn<<" 0X" <<QByteArray().append ((char* )&g_motionInfo.motion[i].minPosn , 4 ).toHex ().toUpper ();
                out<<"\n";
                out<<"    maxTorque "<<g_motionInfo.motion[i].maxTorque<<" 0X" <<QByteArray().append ((char* )&g_motionInfo.motion[i].maxTorque , 4 ).toHex ().toUpper ();
                out<<"\n";
                out<<"    minTorque "<<g_motionInfo.motion[i].minTorque<<" 0X" <<QByteArray().append ((char* )&g_motionInfo.motion[i].minTorque ,4).toHex ().toUpper ();
                out<<"\n";

                out<<"    maxAcc "<<g_motionInfo.motion[i].maxAcc<<" 0X" <<QByteArray().append ((char* )&g_motionInfo.motion[i].maxAcc ,4).toHex ().toUpper ();
                out<<"\n";

                out<<"    minAcc "<<g_motionInfo.motion[i].minAcc<<" 0X" <<QByteArray().append (( char *)&g_motionInfo.motion[i].minAcc ,4).toHex ().toUpper ();
                out<<"\n";
                out<<"    origin "<<g_motionInfo.motion[i].origin<<" 0X" <<QByteArray().append (( char *)&g_motionInfo.motion[i].origin ,4).toHex ().toUpper ();
                out<<"\n";


                out<<"  }\n";
            }
            out<<"  crc "<<g_motionInfo.crc<<" 0X" <<QByteArray().append (( char *)&g_motionInfo.crc , 4).toHex ().toUpper ();;
            out<<"\n";
            out<<"}\n";


            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"MotionInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * motion = new QTreeWidgetItem;
            motion->setText (0, QString("motion"));
            motion->setText (3, "MotionManageStruct[]");
            top->addChild (motion);

            for(i = 0 ; i< CH_TOTAL ; i++)
            {
                QTreeWidgetItem * motion_x = new QTreeWidgetItem;
                motion_x->setText (0, QString("[%1]").arg (i));
                motion_x->setText (3, "MotionManageStruct");
                motion->addChild (motion_x);

                addtree_node (motion_x ,\
                              "stateReport" ,\
                              QString("%1").number (g_motionInfo.motion[i].stateReport) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].stateReport ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (motion_x ,\
                              "initPostUnit" ,\
                              QString("%1").number (g_motionInfo.motion[i].initPostUnit) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].initPostUnit ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (motion_x ,\
                              "initIOPin" ,\
                              QString("%1").number (g_motionInfo.motion[i].initIOPin) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].initIOPin ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (motion_x ,\
                              "offsetState" ,\
                              QString("%1").number (g_motionInfo.motion[i].offsetState) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].offsetState ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (motion_x ,\
                              "reserve" ,\
                              QString("%1").number (g_motionInfo.motion[i].reserve) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].reserve ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (motion_x ,\
                              "startSrc" ,\
                              QString("%1").number (g_motionInfo.motion[i].startSrc) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].startSrc ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (motion_x ,\
                              "startType" ,\
                              QString("%1").number (g_motionInfo.motion[i].startType) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].startType ,1).toHex ().toUpper ().data ())\
                              ,"U8");


                addtree_node (motion_x ,\
                              "maxSpeed" ,\
                              QString("%1").number (g_motionInfo.motion[i].maxSpeed) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].maxSpeed ,4).toHex ().toUpper ().data ())\
                              ,"f32");

                addtree_node (motion_x ,\
                              "minSpeed" ,\
                              QString("%1").number (g_motionInfo.motion[i].minSpeed) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].minSpeed ,4).toHex ().toUpper ().data ())\
                              ,"f32");
                addtree_node (motion_x ,\
                              "maxPosn" ,\
                              QString("%1").number (g_motionInfo.motion[i].maxPosn) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].maxPosn ,4).toHex ().toUpper ().data ())\
                              ,"f32");

                addtree_node (motion_x ,\
                              "minPosn" ,\
                              QString("%1").number (g_motionInfo.motion[i].minPosn) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].minPosn ,4).toHex ().toUpper ().data ())\
                              ,"f32");
                addtree_node (motion_x ,\
                              "maxTorque" ,\
                              QString("%1").number (g_motionInfo.motion[i].maxTorque) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].maxTorque ,4).toHex ().toUpper ().data ())\
                              ,"f32");
                addtree_node (motion_x ,\
                              "minTorque" ,\
                              QString("%1").number (g_motionInfo.motion[i].minTorque) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].minTorque ,4).toHex ().toUpper ().data ())\
                              ,"f32");
                addtree_node (motion_x ,\
                              "maxAcc" ,\
                              QString("%1").number (g_motionInfo.motion[i].maxAcc) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].maxAcc ,4).toHex ().toUpper ().data ())\
                              ,"f32");

                addtree_node (motion_x ,\
                              "minAcc" ,\
                              QString("%1").number (g_motionInfo.motion[i].minAcc) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].minAcc ,4).toHex ().toUpper ().data ())\
                              ,"f32");

                addtree_node (motion_x ,\
                              "origin" ,\
                              QString("%1").number (g_motionInfo.motion[i].origin) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.motion[i].origin ,4).toHex ().toUpper ().data ())\
                              ,"u32");
            }
            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_motionInfo.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_motionInfo.crc ,4).toHex ().toUpper ().data ())\
                          ,"u32");
            g_motionInfo;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "ReportInfo")
    {
        savePath += "/ReportInfoStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (ReportInfoStruct) )
        {
            memcpy (&g_reportInfo ,&data ,sizeof (ReportInfoStruct));
            /*获取文本内容*/
            out<<"ReportInfoStruct \n";
            out<<"{\n";

            int i = 0 ;
            for(i = 0 ; i< CH_TOTAL ; i++)
            {
                out<<"  report["<<i<<"]"<<"\n";
                out<<"  {\n";
                int j = 0;
                for(j = 0; j<REPTTYPE_RESERVE ; j++)
                {
                    out<<"    state["<<j<<"] "<<g_reportInfo.report->state[j]<<"\n";
                    out<<"    period["<<j<<"] "<<g_reportInfo.report->period[j]<<"\n";
                }
                out<<"  }\n";
            }
            out<<"  crc "<<g_reportInfo.crc<<" 0X" <<QByteArray().append (( char *)&g_reportInfo.crc , 4).toHex ().toUpper ();
            out<<"\n";

            out<<"}\n";


            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"ReportInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * report = new QTreeWidgetItem;
            report->setText (0, QString("report"));
            report->setText (3, "ReportManageStruct[]");
            top->addChild (report);

            for(i = 0 ; i< CH_TOTAL ; i++)
            {
                QTreeWidgetItem * report_x = new QTreeWidgetItem;
                report_x->setText (0, QString("[%1]").arg (i));
                report_x->setText (3, "ReportManageStruct");
                report->addChild (report_x);

                QTreeWidgetItem * state = new QTreeWidgetItem;
                state->setText (0, "state");
                state->setText (3, "u8[]");
                report_x->addChild (state);

                QTreeWidgetItem * period = new QTreeWidgetItem;
                period->setText (0, "period");
                period->setText (3, "u32[]");
                report_x->addChild (period);
                int j = 0;
                for(j = 0; j<REPTTYPE_RESERVE ; j++)
                {
                    addtree_node (state ,\
                                  QString("[%1]").arg (j) ,\
                                  QString("%1").number (g_reportInfo.report[i].state[j]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_reportInfo.report[i].state[j] ,1).toHex ().toUpper ().data ())\
                                  ,"U8");

                }

                for(j = 0; j<REPTTYPE_RESERVE ; j++)
                {
                    addtree_node (period ,\
                                  QString("[%1]").arg (j) ,\
                                  QString("%1").number (g_reportInfo.report[i].period[j]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_reportInfo.report[i].period[j] ,1).toHex ().toUpper ().data ())\
                                  ,"U32");

                }

            }

            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_reportInfo.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_reportInfo.crc ,4).toHex ().toUpper ().data ())\
                          ,"U32");


            g_reportInfo;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "TrigInInfo")
    {
        savePath += "/TrigInInfoStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (TrigInInfoStruct) )
        {
            memcpy (&g_trigInInfo ,&data ,sizeof (TrigInInfoStruct));
            /*获取文本内容*/

            out<<"TrigInInfoStruct \n";
            out<<"{\n";

            int i = 0 ;
            for(i = 0 ; i< CH_TOTAL ; i++)
            {
                out<<"  trigIn["<<i<<"]"<<"\n";
                out<<"  {\n";
                int j = 0;
                out<<"  trigMode "<<g_trigInInfo.trigIn->trigMode;
                out<<" \n";
                out<<"  pattState "<<g_trigInInfo.trigIn->pattState;
                out<<" \n";
                out<<"  pattResponse "<<g_trigInInfo.trigIn->pattResponse;
                out<<" \n";
                out<<"  pattSMode "<<g_trigInInfo.trigIn->pattSMode;
                out<<" \n";
                out<<"  pattSPeriod "<<g_trigInInfo.trigIn->pattSPeriod;
                out<<" \n";

                for(j = 0; j<TRIGPIN_RESERVE ; j++)
                {
                    out<<"    levelState["<<j<<"] "<<g_trigInInfo.trigIn->levelState[j]<<"\n";
                    out<<"    levelResponse["<<j<<"] "<<g_trigInInfo.trigIn->levelResponse[j]<<"\n";
                    out<<"    levelSMode["<<j<<"] "<<g_trigInInfo.trigIn->levelSMode[j]<<"\n";
                    out<<"    type["<<j<<"] "<<g_trigInInfo.trigIn->type[j]<<"\n";
                    out<<"    levelSPeriod["<<j<<"] "<<g_trigInInfo.trigIn->levelSPeriod[j]<<"\n";
                }
                out<<"  }\n";
            }
            out<<"  crc "<<g_trigInInfo.crc<<" 0X" <<QByteArray().append (( char *)&g_trigInInfo.crc , 4).toHex ().toUpper ();
            out<<"\n";

            out<<"}\n";



            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"TrigInInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * trigIn = new QTreeWidgetItem;
            trigIn->setText (0, QString("trigIn"));
            trigIn->setText (3, "TrigInManageStruct[]");
            top->addChild (trigIn);

            for(i = 0 ; i< CH_TOTAL ; i++)
            {
                QTreeWidgetItem * trigIn_x = new QTreeWidgetItem;
                trigIn_x->setText (0, QString("[%1]").arg (i));
                trigIn_x->setText (3, "TrigInManageStruct");
                trigIn->addChild (trigIn_x);

                addtree_node (trigIn_x ,\
                              "trigMode" ,\
                              QString("%1").number (g_trigInInfo.trigIn[i].trigMode) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].trigMode ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (trigIn_x ,\
                              "pattState" ,\
                              QString("%1").number (g_trigInInfo.trigIn[i].pattState) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].pattState ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (trigIn_x ,\
                              "pattResponse" ,\
                              QString("%1").number (g_trigInInfo.trigIn[i].pattResponse) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].pattResponse ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (trigIn_x ,\
                              "pattSMode" ,\
                              QString("%1").number (g_trigInInfo.trigIn[i].pattSMode) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].pattSMode ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (trigIn_x ,\
                              "pattSPeriod" ,\
                              QString("%1").number (g_trigInInfo.trigIn[i].pattSPeriod) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].pattSPeriod ,4).toHex ().toUpper ().data ())\
                              ,"f32");
                int j = 0;

                QTreeWidgetItem * levelState = new QTreeWidgetItem;
                levelState->setText (0, "levelState");
                levelState->setText (3, "u8[]");
                trigIn_x->addChild (levelState);
                for(j = 0 ; j< TRIGPIN_RESERVE ; j++)
                {

                    addtree_node (levelState ,\
                                  QString("[%1]").arg (j),\
                                  QString("%1").number (g_trigInInfo.trigIn[i].levelState[j]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].levelState[j] ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
                }

                QTreeWidgetItem * levelResponse = new QTreeWidgetItem;
                levelResponse->setText (0, "levelResponse");
                levelResponse->setText (3, "u8[]");
                trigIn_x->addChild (levelResponse);
                for(j = 0 ; j< TRIGPIN_RESERVE ; j++)
                {

                    addtree_node (levelResponse ,\
                                  QString("[%1]").arg (j),\
                                  QString("%1").number (g_trigInInfo.trigIn[i].levelResponse[j]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].levelResponse[j] ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
                }

                QTreeWidgetItem * levelSMode = new QTreeWidgetItem;
                levelSMode->setText (0, "levelSMode");
                levelSMode->setText (3, "u8[]");
                trigIn_x->addChild (levelSMode);
                for(j = 0 ; j< TRIGPIN_RESERVE ; j++)
                {

                    addtree_node (levelSMode ,\
                                  QString("[%1]").arg (j),\
                                  QString("%1").number (g_trigInInfo.trigIn[i].levelSMode[j]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].levelSMode[j] ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
                }

                QTreeWidgetItem * type = new QTreeWidgetItem;
                type->setText (0, "type");
                type->setText (3, "u8[]");
                trigIn_x->addChild (type);
                for(j = 0 ; j< TRIGPIN_RESERVE ; j++)
                {

                    addtree_node (type ,\
                                  QString("[%1]").arg (j),\
                                  QString("%1").number (g_trigInInfo.trigIn[i].type[j]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].type[j] ,1).toHex ().toUpper ().data ())\
                                  ,"u8");
                }

                QTreeWidgetItem * levelSPeriod = new QTreeWidgetItem;
                levelSPeriod->setText (0, "levelSPeriod");
                levelSPeriod->setText (3, "f32[]");
                trigIn_x->addChild (levelSPeriod);
                for(j = 0 ; j< TRIGPIN_RESERVE ; j++)
                {

                    addtree_node (levelSPeriod ,\
                                  QString("[%1]").arg (j),\
                                  QString("%1").number (g_trigInInfo.trigIn[i].levelSPeriod[j]) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.trigIn[i].levelSPeriod[j] ,4).toHex ().toUpper ().data ())\
                                  ,"f32");
                }

            }
            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_trigInInfo.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_trigInInfo.crc ,4).toHex ().toUpper ().data ())\
                          ,"u32");


            g_trigInInfo;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "DigitalOut")
    {
        savePath += "/DigitalOutStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (DigitalOutStruct) )
        {
            memcpy (&g_digitalOut ,&data ,sizeof (DigitalOutStruct));
            /*获取文本内容*/

            out<<"DigitalOutStruct \n";
            out<<"{\n";

            int i = 0 ;
            for(i = 0 ; i< DIO_RESERVE ; i++)
            {
                out<<"  output["<<i<<"]"<<"\n";
                out<<"  {\n";

                out<<"   state "<<g_digitalOut.output->state;
                out<<" \n";
                out<<"   signal "<<g_digitalOut.output->signal;
                out<<" \n";
                out<<"   polarity "<<g_digitalOut.output->polarity;
                out<<" \n";

                out<<"   source "<<g_digitalOut.output->source;
                out<<" \n";
                out<<"   condition "<<g_digitalOut.output->condition;
                out<<" \n";
                out<<"   duty "<<g_digitalOut.output->duty;
                out<<" \n";
                out<<"   period "<<g_digitalOut.output->period;
                out<<" \n";

                out<<"  }\n";
            }
            out<<"  crc "<<g_digitalOut.crc<<" 0X" <<QByteArray().append (( char *)&g_digitalOut.crc , 4).toHex ().toUpper ();
            out<<"\n";

            out<<"}\n";



            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"DigitalOutStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * output = new QTreeWidgetItem;
            output->setText (0, QString("output"));
            output->setText (3, "DigitalOutManageStruct[]");
            top->addChild (output);

            for(i = 0 ; i< DIO_RESERVE ; i++)
            {
                QTreeWidgetItem * output_x = new QTreeWidgetItem;
                output_x->setText (0, QString("[%1]").arg (i));
                output_x->setText (3, "MotionManageStruct");
                output->addChild (output_x);

                addtree_node (output_x ,\
                              "state" ,\
                              QString("%1").number (g_digitalOut.output[i].state) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_digitalOut.output[i].state ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (output_x ,\
                              "signal" ,\
                              QString("%1").number (g_digitalOut.output[i].signal) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_digitalOut.output[i].signal ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (output_x ,\
                              "polarity" ,\
                              QString("%1").number (g_digitalOut.output[i].polarity) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_digitalOut.output[i].polarity ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (output_x ,\
                              "source" ,\
                              QString("%1").number (g_digitalOut.output[i].source) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_digitalOut.output[i].source ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (output_x ,\
                              "condition" ,\
                              QString("%1").number (g_digitalOut.output[i].condition) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_digitalOut.output[i].condition ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (output_x ,\
                              "duty" ,\
                              QString("%1").number (g_digitalOut.output[i].duty) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_digitalOut.output[i].duty ,2).toHex ().toUpper ().data ())\
                              ,"U16");
                addtree_node (output_x ,\
                              "period" ,\
                              QString("%1").number (g_digitalOut.output[i].period) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_digitalOut.output[i].period ,4).toHex ().toUpper ().data ())\
                              ,"U32");


            }
            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_digitalOut.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_digitalOut.crc ,4).toHex ().toUpper ().data ())\
                          ,"u32");


            g_digitalOut;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "IsolatorOut")
    {
        savePath += "/IsolatorOutStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (IsolatorOutStruct) )
        {
            memcpy (&g_isolatorOut ,&data ,sizeof (IsolatorOutStruct));
            /*获取文本内容*/
            out<<"IsolatorOutStruct \n";
            out<<"{\n";

            int i = 0 ;
            for(i = 0 ; i< YOUT_RESERVE ; i++)
            {
                out<<"  output["<<i<<"]"<<"\n";
                out<<"  {\n";
                int j = 0;
                out<<"   state "<<g_isolatorOut.output->state;
                out<<" \n";
                out<<"   source "<<g_isolatorOut.output->source;
                out<<" \n";
                out<<"   condition "<<g_isolatorOut.output->condition;
                out<<" \n";
                out<<"   response "<<g_isolatorOut.output->response;
                out<<" \n";
                out<<"  }\n";
            }
            out<<"  crc "<<g_isolatorOut.crc<<" 0X" <<QByteArray().append (( char *)&g_isolatorOut.crc , 4).toHex ().toUpper ();
            out<<"\n";
            out<<"}\n";

            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"IsolatorOutStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * output = new QTreeWidgetItem;
            output->setText (0, QString("output"));
            output->setText (3, "IsolatorOutManageStruct[]");
            top->addChild (output);

            for(i = 0 ; i< YOUT_RESERVE ; i++)
            {
                QTreeWidgetItem * output_x = new QTreeWidgetItem;
                output_x->setText (0, QString("[%1]").arg (i));
                output_x->setText (3, "IsolatorOutManageStruct");
                output->addChild (output_x);

                addtree_node (output_x ,\
                              "state" ,\
                              QString("%1").number (g_isolatorOut.output[i].state) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_isolatorOut.output[i].state ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (output_x ,\
                              "source" ,\
                              QString("%1").number (g_isolatorOut.output[i].source) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_isolatorOut.output[i].source ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (output_x ,\
                              "condition" ,\
                              QString("%1").number (g_isolatorOut.output[i].condition) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_isolatorOut.output[i].condition ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (output_x ,\
                              "response" ,\
                              QString("%1").number (g_isolatorOut.output[i].response) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_isolatorOut.output[i].response ,1).toHex ().toUpper ().data ())\
                              ,"U8");

            }
            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_isolatorOut.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_isolatorOut.crc ,4).toHex ().toUpper ().data ())\
                          ,"u32");

            g_isolatorOut;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }
    if(StructFileName == "SensorUart")
    {
        savePath += "/SensorUartStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (SensorUartStruct) )
        {
            memcpy (&g_sensorUart ,&data ,sizeof (SensorUartStruct));
            /*获取文本内容*/

            out<<"SensorUartStruct \n";
            out<<"{\n";

            int i = 0 ;
            for(i = 0 ; i< UARTNUM_RESERVE ; i++)
            {
                out<<"  uartIntfc["<<i<<"]"<<"\n";
                out<<"  {\n";
                int j = 0;
                out<<"   baud "<<g_sensorUart.uartIntfc->baud;
                out<<" \n";
                out<<"   wordLen "<<g_sensorUart.uartIntfc->wordLen;
                out<<" \n";
                out<<"   stopBit "<<g_sensorUart.uartIntfc->stopBit;
                out<<" \n";
                out<<"   parity "<<g_sensorUart.uartIntfc->parity;
                out<<" \n";
                out<<"   flowCtl "<<g_sensorUart.uartIntfc->flowCtl;
                out<<" \n";
                out<<"  }\n";
            }
            for(i = 0; i<UARTNUM_RESERVE ; i++ )
            {
                int j = 0 ;
                for(j = 0 ; j<SENSOR_RESERVE ; j++ )
                {
                    out<<"    sensor["<<i<<"]["<<j<<"]\n ";
                    out<<"    {\n";
                    out<< "      state "<<g_sensorUart.sensor[i][j].state;
                    out<<"\n";
                    out<< "      SOF "<<g_sensorUart.sensor[i][j].SOF;
                    out<<"\n";
                    out<< "      frameLen "<<g_sensorUart.sensor[i][j].frameLen;
                    out<<"\n";
                    out<< "      recvNum "<<g_sensorUart.sensor[i][j].recvNum;
                    out<<"\n";
                    out<< "      swTime "<<g_sensorUart.sensor[i][j].swTime;
                    out<<"\n";
                    out<<"    } \n";
                }
            }
            out<<"  crc "<<g_sensorUart.crc<<" 0X" <<QByteArray().append (( char *)&g_sensorUart.crc , 4).toHex ().toUpper ();
            out<<"\n";

            out<<"}\n";



            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"SensorUartStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * uartIntfc = new QTreeWidgetItem;
            uartIntfc->setText (0, QString("uartIntfc"));
            uartIntfc->setText (3, "UartIntfcStruct[]");
            top->addChild (uartIntfc);

            QTreeWidgetItem * sensor = new QTreeWidgetItem;
            sensor->setText (0, QString("sensor"));
            sensor->setText (3, "SensorManageStruct[][]");
            top->addChild (sensor);

            for(i = 0 ; i< UARTNUM_RESERVE ; i++)
            {
                QTreeWidgetItem * uartIntfc_x = new QTreeWidgetItem;
                uartIntfc_x->setText (0, QString("[%1]").arg (i));
                uartIntfc_x->setText (3, "UartIntfcStruct");
                uartIntfc->addChild (uartIntfc_x);

                addtree_node (uartIntfc_x ,\
                              "baud" ,\
                              QString("%1").number (g_sensorUart.uartIntfc[i].baud) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.uartIntfc[i].baud ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (uartIntfc_x ,\
                              "wordLen" ,\
                              QString("%1").number (g_sensorUart.uartIntfc[i].wordLen) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.uartIntfc[i].wordLen ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (uartIntfc_x ,\
                              "stopBit" ,\
                              QString("%1").number (g_sensorUart.uartIntfc[i].stopBit) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.uartIntfc[i].stopBit ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (uartIntfc_x ,\
                              "parity" ,\
                              QString("%1").number (g_sensorUart.uartIntfc[i].parity) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.uartIntfc[i].parity ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (uartIntfc_x ,\
                              "flowCtl" ,\
                              QString("%1").number (g_sensorUart.uartIntfc[i].flowCtl) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.uartIntfc[i].flowCtl ,1).toHex ().toUpper ().data ())\
                              ,"U8");

            }

            for(i = 0 ; i< UARTNUM_RESERVE ; i++)
            {
                QTreeWidgetItem * sensor_x = new QTreeWidgetItem;
                sensor_x->setText (0, QString("[%1]").arg (i));
                sensor_x->setText (3, "SensorManageStruct[]");
                sensor->addChild (sensor_x);

                int j = 0;
                for(j = 0 ; j< SENSOR_RESERVE ; j++)
                {
                    QTreeWidgetItem * sensor_x_x = new QTreeWidgetItem;
                    sensor_x_x->setText (0, QString("[%1]").arg (j));
                    sensor_x_x->setText (3, "SensorManageStruct");
                    sensor_x->addChild (sensor_x_x);
                    addtree_node (sensor_x_x ,\
                                  "state" ,\
                                  QString("%1").number (g_sensorUart.sensor[i][j].state) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.sensor[i][j].state ,1).toHex ().toUpper ().data ())\
                                  ,"U8");
                    addtree_node (sensor_x_x ,\
                                  "SOF" ,\
                                  QString("%1").number (g_sensorUart.sensor[i][j].SOF) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.sensor[i][j].SOF ,1).toHex ().toUpper ().data ())\
                                  ,"U8");
                    addtree_node (sensor_x_x ,\
                                  "frameLen" ,\
                                  QString("%1").number (g_sensorUart.sensor[i][j].frameLen) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.sensor[i][j].frameLen ,1).toHex ().toUpper ().data ())\
                                  ,"U8");
                    addtree_node (sensor_x_x ,\
                                  "recvNum" ,\
                                  QString("%1").number (g_sensorUart.sensor[i][j].recvNum) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.sensor[i][j].recvNum ,1).toHex ().toUpper ().data ())\
                                  ,"U8");
                    addtree_node (sensor_x_x ,\
                                  "swTime" ,\
                                  QString("%1").number (g_sensorUart.sensor[i][j].swTime) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.sensor[i][j].swTime ,4).toHex ().toUpper ().data ())\
                                  ,"U32");
                }

            }

            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_sensorUart.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_sensorUart.crc ,4).toHex ().toUpper ().data ())\
                          ,"u32");
            g_sensorUart;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }

    if(StructFileName == "DriverInfo")
    {
        savePath += "/DriverInfoStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (DriverInfoStruct) )
        {
            memcpy (&g_driverInfo ,&data ,sizeof (DriverInfoStruct));
            /*获取文本内容*/

            out<<"DriverInfoStruct \n";
            out<<"{\n";

            int i = 0 ;
            for(i = 0 ; i< CH_TOTAL ; i++)
            {
                out<<"  driver["<<i<<"]"<<"\n";
                out<<"  {\n";
                int j = 0;
                out<<"   state "<<g_driverInfo.driver->state;
                out<<" \n";
                out<<"   type "<<g_driverInfo.driver->type;
                out<<" \n";
                out<<"   curr "<<g_driverInfo.driver->curr;
                out<<" \n";
                out<<"   idleCurr "<<g_driverInfo.driver->idleCurr;
                out<<" \n";
                out<<"   tuningState "<<g_driverInfo.driver->tuningState;
                out<<" \n";
                out<<"   currRatio "<<g_driverInfo.driver->currRatio;
                out<<" \n";
                out<<"   currIncre "<<g_driverInfo.driver->currIncre;
                out<<" \n";

                out<<"   currDecre "<<g_driverInfo.driver->currDecre;
                out<<" \n";
                out<<"   sgThreshold "<<g_driverInfo.driver->sgThreshold;
                out<<" \n";
                out<<"   energEfficMax "<<g_driverInfo.driver->energEfficMax;
                out<<" \n";
                out<<"   energEfficOffset "<<g_driverInfo.driver->energEfficOffset;
                out<<" \n";
                out<<"   switchTime "<<g_driverInfo.driver->switchTime;
                out<<" \n";


                out<<"    DRVCTRL \n";
                out<<"          {\n";
                out<<"           stepDirMode\n";
                out<<"             {\n";
                out<<"               MRES "<<g_driverInfo.driver[i].DRVCTRL.stepDirMode.MRES;
                out<<"\n";
                out<<"               resv_bit4_7 "<<g_driverInfo.driver[i].DRVCTRL.stepDirMode.resv_bit4_7;
                out<<"\n";
                out<<"               DEDGE "<<g_driverInfo.driver[i].DRVCTRL.stepDirMode.DEDGE;
                out<<"\n";
                out<<"               INTPOL "<<g_driverInfo.driver[i].DRVCTRL.stepDirMode.INTPOL;
                out<<"\n";
                out<<"               resv_bit10_17 "<<g_driverInfo.driver[i].DRVCTRL.stepDirMode.resv_bit10_17;
                out<<"\n";
                out<<"               addr "<<g_driverInfo.driver[i].DRVCTRL.stepDirMode.addr;
                out<<"\n";
                out<<"               resv_bit20_31 "<<g_driverInfo.driver[i].DRVCTRL.stepDirMode.resv_bit20_31;
                out<<"             }\n";

                out<<"           spiMode\n";
                out<<"             {\n";
                out<<"               CB "<<g_driverInfo.driver[i].DRVCTRL.spiMode.CB;
                out<<"\n";
                out<<"               PHB "<<g_driverInfo.driver[i].DRVCTRL.spiMode.PHB;
                out<<"\n";
                out<<"               CA "<<g_driverInfo.driver[i].DRVCTRL.spiMode.CA;
                out<<"\n";
                out<<"               PHA "<<g_driverInfo.driver[i].DRVCTRL.spiMode.PHA;
                out<<"\n";
                out<<"               addr "<<g_driverInfo.driver[i].DRVCTRL.spiMode.addr;
                out<<"\n";
                out<<"               resv_bit20_31 "<<g_driverInfo.driver[i].DRVCTRL.spiMode.resv_bit20_31;
                out<<"\n";
                out<<"             }\n";

                out<<"            regValue "<<g_driverInfo.driver[i].DRVCTRL.regValue;
                out<<"\n";
                out<<"          }\n";

                out<<"    CHOPCONF \n";
                out<<"          {\n";
                out<<"           regBitFiled\n";
                out<<"             {\n";
                out<<"               TOFF "<<g_driverInfo.driver[i].CHOPCONF.regBitFiled.TOFF;
                out<<"\n";
                out<<"               HSTRT "<<g_driverInfo.driver[i].CHOPCONF.regBitFiled.HSTRT;
                out<<"\n";
                out<<"               HEND "<<g_driverInfo.driver[i].CHOPCONF.regBitFiled.HEND;
                out<<"\n";
                out<<"               HDEC "<<g_driverInfo.driver[i].CHOPCONF.regBitFiled.HDEC;
                out<<"\n";
                out<<"               RNDTF "<<g_driverInfo.driver[i].CHOPCONF.regBitFiled.RNDTF;
                out<<"\n";
                out<<"               CHM "<<g_driverInfo.driver[i].CHOPCONF.regBitFiled.CHM;
                out<<"\n";
                out<<"               TBL "<<g_driverInfo.driver[i].CHOPCONF.regBitFiled.TBL;
                out<<"\n";
                out<<"               addr "<<g_driverInfo.driver[i].CHOPCONF.regBitFiled.addr;
                out<<"\n";
                out<<"               resv_bit20_31 "<<g_driverInfo.driver[i].CHOPCONF.regBitFiled.resv_bit20_31;
                out<<"\n";
                out<<"             }\n";
                out<<"             regValue "<<g_driverInfo.driver[i].CHOPCONF.regValue;
                out<<"\n";

                out<<"          }\n";

                out<<"    SMARTEN \n";
                out<<"          {\n";
                out<<"           regBitFiled\n";
                out<<"             {\n";
                out<<"               SEMIN "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.SEMIN;
                out<<"\n";
                out<<"               resv_bit4 "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit4;
                out<<"\n";
                out<<"               SEUP "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.SEUP;
                out<<"\n";
                out<<"               resv_bit7 "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit7;
                out<<"\n";
                out<<"               SEMAX "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.SEMAX;
                out<<"\n";
                out<<"               resv_bit12 "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit12;
                out<<"\n";
                out<<"               SEDN "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.SEDN;
                out<<"\n";
                out<<"               SEIMIN "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.SEIMIN;
                out<<"\n";
                out<<"               resv_bit16 "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit16;
                out<<"\n";
                out<<"               addr "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.addr;
                out<<"\n";
                out<<"               resv_bit20_31 "<<g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit20_31;
                out<<"\n";
                out<<"             }\n";
                out<<"             regValue "<<g_driverInfo.driver[i].SMARTEN.regValue;
                out<<"\n";
                out<<"          }\n";

                out<<"    SGCSCONF \n";
                out<<"          {\n";
                out<<"           regBitFiled\n";
                out<<"             {\n";
                out<<"               CS "<<g_driverInfo.driver[i].SGCSCONF.regBitFiled.CS;
                out<<"\n";
                out<<"               resv_bit5_7 "<<g_driverInfo.driver[i].SGCSCONF.regBitFiled.resv_bit5_7;
                out<<"\n";
                out<<"               SGT "<<g_driverInfo.driver[i].SGCSCONF.regBitFiled.SGT;
                out<<"\n";
                out<<"               resv_bit15 "<<g_driverInfo.driver[i].SGCSCONF.regBitFiled.resv_bit15;
                out<<"\n";
                out<<"               SFILT "<<g_driverInfo.driver[i].SGCSCONF.regBitFiled.SFILT;
                out<<"\n";
                out<<"               addr "<<g_driverInfo.driver[i].SGCSCONF.regBitFiled.addr;
                out<<"\n";
                out<<"               resv_bit20_31 "<<g_driverInfo.driver[i].SGCSCONF.regBitFiled.resv_bit20_31;
                out<<"\n";
                out<<"             }\n";
                out<<"             regValue "<<g_driverInfo.driver[i].SGCSCONF.regValue;
                out<<"\n";
                out<<"          }\n";

                out<<"    DRVCONF \n";
                out<<"          {\n";
                out<<"           regBitFiled\n";
                out<<"             {\n";
                out<<"               resv_bit0_3 "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.resv_bit0_3;
                out<<"\n";
                out<<"               RDSEL "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.RDSEL;
                out<<"\n";
                out<<"               VSENSE "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.VSENSE;
                out<<"\n";
                out<<"               SDOFF "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.SDOFF;
                out<<"\n";
                out<<"               TS2G "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.TS2G;
                out<<"\n";
                out<<"               DISS2G "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.DISS2G;
                out<<"\n";
                out<<"               resv_bit11 "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.resv_bit11;
                out<<"\n";

                out<<"               SLPL "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.SLPL;
                out<<"\n";
                out<<"               SLPH "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.SLPH;
                out<<"\n";
                out<<"               TST "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.TST;
                out<<"\n";
                out<<"               addr "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.addr;
                out<<"\n";
                out<<"               resv_bit20_31 "<<g_driverInfo.driver[i].DRVCONF.regBitFiled.resv_bit20_31;
                out<<"\n";

                out<<"             }\n";
                out<<"             regValue "<<g_driverInfo.driver[i].DRVCONF.regValue;
                out<<"\n";

                out<<"          }\n";




                out<<"  }\n";
            }
            out<<"  crc "<<g_isolatorOut.crc<<" 0X" <<QByteArray().append (( char *)&g_isolatorOut.crc , 4).toHex ().toUpper ();
            out<<"\n";

            out<<"}\n";

            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"DriverInfoStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * driver = new QTreeWidgetItem;
            driver->setText (0, QString("driver"));
            driver->setText (3, "DriverManageStruct[]");
            top->addChild (driver);

            for(i = 0 ; i< CH_TOTAL ; i++)
            {
                QTreeWidgetItem * driver_x = new QTreeWidgetItem;
                driver_x->setText (0, QString("[%1]").arg (i));
                driver_x->setText (3, "DriverManageStruct");
                driver->addChild (driver_x);
                addtree_node (driver_x ,\
                              "state" ,\
                              QString("%1").number (g_driverInfo.driver[i].state) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].state ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (driver_x ,\
                              "type" ,\
                              QString("%1").number (g_driverInfo.driver[i].type) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].type ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (driver_x ,\
                              "curr" ,\
                              QString("%1").number (g_driverInfo.driver[i].curr) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].curr ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (driver_x ,\
                              "idleCurr" ,\
                              QString("%1").number (g_driverInfo.driver[i].idleCurr) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].idleCurr ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (driver_x ,\
                              "tuningState" ,\
                              QString("%1").number (g_driverInfo.driver[i].tuningState) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].tuningState ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (driver_x ,\
                              "currRatio" ,\
                              QString("%1").number (g_driverInfo.driver[i].currRatio) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].currRatio ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (driver_x ,\
                              "currIncre" ,\
                              QString("%1").number (g_driverInfo.driver[i].currIncre) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].currIncre ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (driver_x ,\
                              "currDecre" ,\
                              QString("%1").number (g_driverInfo.driver[i].currDecre) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].currDecre ,1).toHex ().toUpper ().data ())\
                              ,"U8");

                addtree_node (driver_x ,\
                              "sgThreshold" ,\
                              QString("%1").number (g_driverInfo.driver[i].sgThreshold) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].sgThreshold ,2).toHex ().toUpper ().data ())\
                              ,"s16");

                addtree_node (driver_x ,\
                              "energEfficMax" ,\
                              QString("%1").number (g_driverInfo.driver[i].energEfficMax) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].energEfficMax ,2).toHex ().toUpper ().data ())\
                              ,"u16");

                addtree_node (driver_x ,\
                              "energEfficOffset" ,\
                              QString("%1").number (g_driverInfo.driver[i].energEfficOffset) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].energEfficOffset ,2).toHex ().toUpper ().data ())\
                              ,"u16");

                addtree_node (driver_x ,\
                              "switchTime" ,\
                              QString("%1").number (g_driverInfo.driver[i].switchTime) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].switchTime ,4).toHex ().toUpper ().data ())\
                              ,"u32");


                QTreeWidgetItem * DRVCTRL = new QTreeWidgetItem;
                DRVCTRL->setText (0, QString("DRVCTRL"));
                DRVCTRL->setText (3, "DriverControlUnion");
                driver_x->addChild (DRVCTRL);

                QTreeWidgetItem * stepDirMode = new QTreeWidgetItem;
                stepDirMode->setText (0, QString("stepDirMode"));
                stepDirMode->setText (3, "DriverControlStepDirStruct");
                DRVCTRL->addChild (stepDirMode);
                addtree_node (stepDirMode ,\
                              "MRES" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.stepDirMode.MRES) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.stepDirMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (stepDirMode ,\
                              "resv_bit4_7" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.stepDirMode.resv_bit4_7) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.stepDirMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (stepDirMode ,\
                              "DEDGE" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.stepDirMode.DEDGE) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.stepDirMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (stepDirMode ,\
                              "INTPOL" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.stepDirMode.INTPOL) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.stepDirMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (stepDirMode ,\
                              "resv_bit10_17" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.stepDirMode.resv_bit10_17) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.stepDirMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (stepDirMode ,\
                              "addr" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.stepDirMode.addr) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.stepDirMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (stepDirMode ,\
                              "resv_bit20_31" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.stepDirMode.resv_bit20_31) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.stepDirMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                QTreeWidgetItem * spiMode = new QTreeWidgetItem;
                spiMode->setText (0, QString("spiMode"));
                spiMode->setText (3, "DriverControlSpiStruct");
                DRVCTRL->addChild (spiMode);
                addtree_node (spiMode ,\
                              "CB" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.spiMode.CB) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.spiMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (spiMode ,\
                              "PHB" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.spiMode.PHB) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.spiMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (spiMode ,\
                              "CA" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.spiMode.CA) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.spiMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (spiMode ,\
                              "PHA" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.spiMode.PHA) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.spiMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (spiMode ,\
                              "addr" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.spiMode.addr) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.spiMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (spiMode ,\
                              "resv_bit20_31" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.spiMode.resv_bit20_31) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.spiMode ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (DRVCTRL ,\
                              "regValue" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCTRL.regValue) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCTRL.regValue ,4).toHex ().toUpper ().data ())\
                              ,"u32");



                QTreeWidgetItem * CHOPCONF = new QTreeWidgetItem;
                CHOPCONF->setText (0, QString("CHOPCONF"));
                CHOPCONF->setText (3, "ChopConfigUnion");
                driver_x->addChild (CHOPCONF);
                QTreeWidgetItem * regBitFiled = new QTreeWidgetItem;
                regBitFiled->setText (0, QString("regBitFiled"));
                regBitFiled->setText (3, "ChopperConfigStruct");
                CHOPCONF->addChild (regBitFiled);
                addtree_node (regBitFiled ,\
                              "TOFF" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regBitFiled.TOFF) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled ,\
                              "HSTRT" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regBitFiled.HSTRT) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled ,\
                              "HEND" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regBitFiled.HEND) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled ,\
                              "HDEC" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regBitFiled.HDEC) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled ,\
                              "RNDTF" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regBitFiled.RNDTF) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled ,\
                              "CHM" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regBitFiled.CHM) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled ,\
                              "TBL" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regBitFiled.TBL) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled ,\
                              "addr" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regBitFiled.addr) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled ,\
                              "resv_bit20_31" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regBitFiled.resv_bit20_31) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (CHOPCONF ,\
                              "regValue" ,\
                              QString("%1").number (g_driverInfo.driver[i].CHOPCONF.regValue) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].CHOPCONF.regValue ,4).toHex ().toUpper ().data ())\
                              ,"u32");


                QTreeWidgetItem * SMARTEN = new QTreeWidgetItem;
                SMARTEN->setText (0, QString("SMARTEN"));
                SMARTEN->setText (3, "CoolStepCofingUnion");
                driver_x->addChild (SMARTEN);
                QTreeWidgetItem * regBitFiled2 = new QTreeWidgetItem;
                regBitFiled2->setText (0, QString("regBitFiled"));
                regBitFiled2->setText (3, "CoolStepCofingStruct");
                SMARTEN->addChild (regBitFiled2);
                addtree_node (regBitFiled2 ,\
                              "SEMIN" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.SEMIN) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "resv_bit4" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit4) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "SEUP" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.SEUP) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "resv_bit7" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit7) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "SEMAX" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.SEMAX) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "resv_bit12" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit12) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "SEDN" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.SEDN) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "SEIMIN" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.SEIMIN) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "resv_bit16" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit16) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "addr" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.addr) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled2 ,\
                              "resv_bit20_31" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regBitFiled.resv_bit20_31) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (SMARTEN ,\
                              "regValue" ,\
                              QString("%1").number (g_driverInfo.driver[i].SMARTEN.regValue) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SMARTEN.regValue ,4).toHex ().toUpper ().data ())\
                              ,"u32");

                QTreeWidgetItem * SGCSCONF = new QTreeWidgetItem;
                SGCSCONF->setText (0, QString("SGCSCONF"));
                SGCSCONF->setText (3, "StallGuard2ConfigUnion");
                driver_x->addChild (SGCSCONF);
                QTreeWidgetItem * regBitFiled3 = new QTreeWidgetItem;
                regBitFiled3->setText (0, QString("regBitFiled"));
                regBitFiled3->setText (3, "StallGuard2ConfigStruct");
                SGCSCONF->addChild (regBitFiled3);
                addtree_node (regBitFiled3 ,\
                              "CS" ,\
                              QString("%1").number (g_driverInfo.driver[i].SGCSCONF.regBitFiled.CS) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SGCSCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled3 ,\
                              "resv_bit5_7" ,\
                              QString("%1").number (g_driverInfo.driver[i].SGCSCONF.regBitFiled.resv_bit5_7) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SGCSCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled3 ,\
                              "SGT" ,\
                              QString("%1").number (g_driverInfo.driver[i].SGCSCONF.regBitFiled.SGT) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SGCSCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled3 ,\
                              "resv_bit15" ,\
                              QString("%1").number (g_driverInfo.driver[i].SGCSCONF.regBitFiled.resv_bit15) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SGCSCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled3 ,\
                              "SFILT" ,\
                              QString("%1").number (g_driverInfo.driver[i].SGCSCONF.regBitFiled.SFILT) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SGCSCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled3 ,\
                              "addr" ,\
                              QString("%1").number (g_driverInfo.driver[i].SGCSCONF.regBitFiled.addr) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SGCSCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled3 ,\
                              "resv_bit20_31" ,\
                              QString("%1").number (g_driverInfo.driver[i].SGCSCONF.regBitFiled.resv_bit20_31) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SGCSCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (SGCSCONF ,\
                              "regValue" ,\
                              QString("%1").number (g_driverInfo.driver[i].SGCSCONF.regValue) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].SGCSCONF.regValue ,4).toHex ().toUpper ().data ())\
                              ,"u32");

                QTreeWidgetItem * DRVCONF = new QTreeWidgetItem;
                DRVCONF->setText (0, QString("DRVCONF"));
                DRVCONF->setText (3, "DriverConfigUnion");
                driver_x->addChild (DRVCONF);
                QTreeWidgetItem * regBitFiled4 = new QTreeWidgetItem;
                regBitFiled4->setText (0, QString("regBitFiled"));
                regBitFiled4->setText (3, "DriverConfigStruct");
                DRVCONF->addChild (regBitFiled4);
                addtree_node (regBitFiled4 ,\
                              "resv_bit0_3" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.resv_bit0_3) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "RDSEL" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.RDSEL) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "VSENSE" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.VSENSE) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "SDOFF" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.SDOFF) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "TS2G" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.TS2G) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "DISS2G" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.DISS2G) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "resv_bit11" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.resv_bit11) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "SLPL" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.SLPL) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "SLPH" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.SLPH) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "TST" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.TST) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "addr" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.addr) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (regBitFiled4 ,\
                              "resv_bit20_31" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regBitFiled.resv_bit20_31) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regBitFiled ,4).toHex ().toUpper ().data ())\
                              ,"u32");
                addtree_node (DRVCONF ,\
                              "regValue" ,\
                              QString("%1").number (g_driverInfo.driver[i].DRVCONF.regValue) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.driver[i].DRVCONF.regValue ,4).toHex ().toUpper ().data ())\
                              ,"u32");


            }
            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_driverInfo.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_driverInfo.crc ,4).toHex ().toUpper ().data ())\
                          ,"u32");

            g_driverInfo;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }

    if(StructFileName == "SensorAlarm")
    {
        savePath += "/SensorAlarmStruct_Analysis.txt";
        struct_file.setFileName (savePath);
        struct_file.open (QIODevice::WriteOnly | QIODevice::Text);

        if(tmp.count ()-1 == sizeof (SensorAlarmStruct) )
        {
            memcpy (&g_sensorAlarm ,&data ,sizeof (SensorAlarmStruct));
            /*获取文本内容*/
            out.setFieldAlignment(QTextStream::AlignLeft);
            out<<"SensorAlarmStruct\n";
            out<<"{\n";
            int i = 0 ;
            for(i = 0 ; i <ABS_ENCODER_NUM; i++ )
            {
                out<<"  encAlarm ["<<i<<"]\n";
                out<<"   {\n";
                out.setFieldWidth(15);
                out<<"     state "<< g_sensorAlarm.encAlarm->state;
                out.setFieldWidth(0);
                out<<"\n";
                out.setFieldWidth(15);
                out<<"     zeroPost "<< g_sensorAlarm.encAlarm->zeroPost;
                out.setFieldWidth(0);
                out<<"\n";
                out.setFieldWidth(15);
                out<<"     zeroValue "<< g_sensorAlarm.encAlarm->zeroValue;
                out.setFieldWidth(0);
                out<<"\n";
                out.setFieldWidth(15);
                out<<"     upLimit "<< g_sensorAlarm.encAlarm->upLimit;
                out.setFieldWidth(0);
                out<<"\n";
                out.setFieldWidth(15);
                out<<"     dnLimit "<< g_sensorAlarm.encAlarm->dnLimit;
                out.setFieldWidth(0);
                out<<"\n";
                out.setFieldWidth(15);
                out.setFieldWidth(0);
                out<<"   }\n";
            }
            out<<"  encAlarmResponse "<<g_sensorAlarm.encAlarmResponse;
            out<<"\n";
            for(i = 0 ; i <DIST_SENSOR_NUM; i++ )
            {
                out<<"  distAlarm ["<<i<<"]\n";
                out<<"   {\n";
                out.setFieldWidth(15);
                out<<"     state "<< g_sensorAlarm.distAlarm->state;
                out.setFieldWidth(0);
                out<<"\n";
                out.setFieldWidth(15);
                out<<"     alarm1Dist "<< g_sensorAlarm.distAlarm->alarm1Dist;
                out.setFieldWidth(0);
                out<<"\n";
                out.setFieldWidth(15);
                out<<"     alarm2Dist "<< g_sensorAlarm.distAlarm->alarm2Dist;
                out.setFieldWidth(0);
                out<<"\n";
                out.setFieldWidth(15);
                out<<"     alarm3Dist "<< g_sensorAlarm.distAlarm->alarm3Dist;
                out.setFieldWidth(0);
                out<<"\n";
                out.setFieldWidth(15);
                out.setFieldWidth(0);
                out<<"   }\n";
            }

            out<<"}\n";
            out.setFieldWidth(15);
            out<<"  crc "<<g_sensorAlarm.crc;
            out<<"\n";



            QTreeWidgetItem * top= new QTreeWidgetItem;
            top->setText (0,"SensorAlarmStruct");
            ui->Struct_treeWidget->addTopLevelItem (top);

            QTreeWidgetItem * encAlarm = new QTreeWidgetItem;
            encAlarm->setText (0, QString("encAlarm"));
            encAlarm->setText (3, "AbsEncoderAlarmStruct[]");
            top->addChild (encAlarm);

            for(i = 0 ; i< ABS_ENCODER_NUM ; i++)
            {
                QTreeWidgetItem * encAlarm_x = new QTreeWidgetItem;
                encAlarm_x->setText (0, QString("[%1]").arg (i));
                encAlarm_x->setText (3, "AbsEncoderAlarmStruct");
                encAlarm->addChild (encAlarm_x);

                addtree_node (encAlarm_x ,\
                              "state" ,\
                              QString("%1").number (g_sensorAlarm.encAlarm[i].state) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.encAlarm[i].state ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (encAlarm_x ,\
                              "zeroPost" ,\
                              QString("%1").number (g_sensorAlarm.encAlarm[i].zeroPost) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.encAlarm[i].zeroPost ,1).toHex ().toUpper ().data ())\
                              ,"U8");
                addtree_node (encAlarm_x ,\
                              "zeroValue" ,\
                              QString("%1").number (g_sensorAlarm.encAlarm[i].zeroValue) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.encAlarm[i].zeroValue ,4).toHex ().toUpper ().data ())\
                              ,"U32");

                addtree_node (encAlarm_x ,\
                              "upLimit" ,\
                              QString("%1").number (g_sensorAlarm.encAlarm[i].upLimit) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.encAlarm[i].upLimit ,4).toHex ().toUpper ().data ())\
                              ,"U32");
                addtree_node (encAlarm_x ,\
                              "dnLimit" ,\
                              QString("%1").number (g_sensorAlarm.encAlarm[i].dnLimit) ,\
                              QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.encAlarm[i].dnLimit ,4).toHex ().toUpper ().data ())\
                              ,"U32");

            }

            addtree_node (top ,\
                          "encAlarmResponse" ,\
                          QString("%1").number (g_sensorAlarm.encAlarmResponse) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.encAlarmResponse ,1).toHex ().toUpper ().data ())\
                          ,"U8");



            QTreeWidgetItem * distAlarm = new QTreeWidgetItem;
            distAlarm->setText (0, QString("distAlarm"));
            distAlarm->setText (3, "DistSensorAlarmStruct[]");
            top->addChild (distAlarm);
            for(i = 0 ; i< DIST_SENSOR_NUM ; i++)
            {
                QTreeWidgetItem * distAlarm_x = new QTreeWidgetItem;
                distAlarm_x->setText (0, QString("[%1]").arg (i));
                distAlarm_x->setText (3, "DistSensorAlarmStruct[]");
                distAlarm->addChild (distAlarm_x);

                int j = 0;
                for(j = 0 ; j< SENSOR_RESERVE ; j++)
                {
                    QTreeWidgetItem * distAlarm_x_x = new QTreeWidgetItem;
                    distAlarm_x_x->setText (0, QString("[%1]").arg (j));
                    distAlarm_x_x->setText (3, "DistSensorAlarmStruct");
                    distAlarm_x->addChild (distAlarm_x_x);
                    addtree_node (distAlarm_x_x ,\
                                  "state" ,\
                                  QString("%1").number (g_sensorAlarm.distAlarm[i].state) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.distAlarm[i].state ,1).toHex ().toUpper ().data ())\
                                  ,"U8");
                    addtree_node (distAlarm_x_x ,\
                                  "alarm1Dist" ,\
                                  QString("%1").number (g_sensorAlarm.distAlarm[i].alarm1Dist) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.distAlarm[i].alarm1Dist ,2).toHex ().toUpper ().data ())\
                                  ,"U16");
                    addtree_node (distAlarm_x_x ,\
                                  "alarm2Dist" ,\
                                  QString("%1").number (g_sensorAlarm.distAlarm[i].alarm2Dist) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.distAlarm[i].alarm2Dist ,2).toHex ().toUpper ().data ())\
                                  ,"U16");
                    addtree_node (distAlarm_x_x ,\
                                  "alarm3Dist" ,\
                                  QString("%1").number (g_sensorAlarm.distAlarm[i].alarm3Dist) ,\
                                  QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.distAlarm[i].alarm3Dist ,2).toHex ().toUpper ().data ())\
                                  ,"U16");

                }

            }

            addtree_node (top ,\
                          "crc" ,\
                          QString("%1").number (g_sensorAlarm.crc) ,\
                          QString("0x%1").arg (QByteArray().append ((char*)&g_sensorAlarm.crc ,4).toHex ().toUpper ().data ())\
                          ,"u32");

            g_sensorAlarm;
        }
        else {
            /*结构体出错*/
        }
        /* 打开文本 解析处理工作*/
        return;
    }

}

void E2PROMMainWindow::on_Struct_Path_pushButton_clicked()
{
    QFileDialog filePath;
    QStringList file_name = QFileDialog::getOpenFileNames(NULL,"标题",".","*.TXT");
    if(file_name.count ()>0)
    {
        ui->Struct_Path_lineEdit->setText (file_name.at (0).split ("/").at (0));
    }
    else {
        return;
    }

    ui->struct_All_comboBox->clear ();
    ui->struct_All_comboBox->addItems (file_name);
    //Struct_FilePath = file_name;

}

void E2PROMMainWindow::addtree_node(QTreeWidgetItem  *parent ,QString name , QString dec_value ,QString hex_value ,QString type )
{
    QTreeWidgetItem * node= new QTreeWidgetItem;
    node->setText (0, name);
    node->setText (1, dec_value);
    node->setText (2, hex_value);
    node->setText (3, type);
    parent-> addChild (node);
}


void E2PROMMainWindow::on_struct_All_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug()<<"on_struct_All_comboBox_currentIndexChanged"<<arg1;
    analysisStruct(arg1);
}
/*刷更新*/
void E2PROMMainWindow::on_pushButton_clicked()
{
    //analysisStruct("E:/E2PROMTest/MotorInfo/MotorInfo/MotorInfo.TXT");
}

void E2PROMMainWindow::on_Struct_Path_lineEdit_textChanged(const QString &arg1)
{

}

void E2PROMMainWindow::on_comboBox_activated(const QString &arg1)
{
    StructFileName = ui->comboBox->currentText ();
}
