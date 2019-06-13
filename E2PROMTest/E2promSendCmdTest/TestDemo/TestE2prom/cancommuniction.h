/*CAN通讯用的功能类：还需要扩展更新函数API*/

#ifndef CANCOMMUNICTION_H
#define CANCOMMUNICTION_H
#include <iostream>
#include <cstdio>
#include <list>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QTreeWidget>
#include <QStringListModel>
#include <QStringList>
#include <QListView>
#include <QLibrary>
#include <QThread>
#include <QDir>
#include <QThread>
#include <QMessageBox>
#include <windows.h>
#include <QTimer>
#include <QListWidget>
#include <QTime>
#include <QMutex>
#include <string>

#define NoBack  0
#define Back    1
#define Sucess  1
#define fail    0

/*******************************
 * CAN错误信息的结构体
 *
*********************************/
typedef struct _ERR_INFO {
UINT ErrCode;
BYTE Passive_ErrData[3];
BYTE ArLost_ErrData;
} ERR_INFO;

/*******************************
 * CAN帧结构体成员
 *
*********************************/
typedef struct VCI_CAN_OBJ
{
         /*Can ID*/
         uint ID;
         /*时间标识*/
         uint TimeStamp;
         /*是否使用时间标识*/
         char TimeFlag;
         /*发送标志。保留，未用*/
         char SendType;
         /*是否是远程帧*/
         char RemoteFlag;
         /*是否是扩展帧*/
         char ExternFlag;
         /*数据长度*/
         char DataLen;
         /*数据*/
         char Data[8];
         /*保留位*/
         char Reserved[3];

}CAN_OBJ;

/*******************************
 * 初始化CAN的配置参数结构体
 *
*********************************/
typedef struct VCI_INIT_CONFIG
{
         uint AccCode;
         uint AccMask;
         /**/
         uint Baud;
         /*0或1接收所有帧。2标准帧滤波，3是扩展帧滤波*/
         char Filter;
         /*波特率参数，具体配置，请查看二次开发库函数说明书*/
         char Timing0;
         char Timing1;
         /*模式，0表示正常模式，1表示只听模式 2自测模式*/
         char Mode;
}CAN_INIT_CONFIG;

/*******************************
 * 加载CAN库函数时候的枚举值，判定使用的是那个类型的通讯产品
 *
*********************************/
typedef enum CanType//预留出0 表示没有
{
    MRH_U = 0,
    USBCAN1 = 3,
    USBCAN2 = 4,
    MRH_E = 6,
    MRH_T = 8,
}CANTYPE ;

/*******************************
 *
 * USB CAN 分析仪的信息
 *
*********************************/
typedef   struct VCI_BOARD_INFO
    {
         ushort hw_Version;
         ushort fw_Version;
         ushort dr_Version;
         ushort in_Version;
         ushort irq_Num;
         byte can_Num;
         //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 20)]
         byte str_Serial_Num[20];
         //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
         byte str_hw_Type[40];
         //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
         byte Reserved[4];
    }VCI_BOARD_INFO;

/*******************************
 *
 *
*********************************/
typedef struct VCI_BOARD_INFO1
    {
         ushort hw_Version;
         ushort fw_Version;
         ushort dr_Version;
         ushort in_Version;
         ushort irq_Num;
         byte can_Num;
         byte Reserved;
         //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
         byte str_Serial_Num[8];
         //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
         byte str_hw_Type[16];
         //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
         byte str_Usb_Serial[16];
    }VCI_BOARD_INFO1;


/*******************************
 * 定义库函数对应的函数类型
 *
*********************************/
typedef  uint ( _stdcall * CloseCan )( uint DeviceType,  uint DeviceInd );
typedef  uint ( _stdcall * OpenCan )( uint DeviceType,  uint DeviceInd, uint Reserved);
typedef  uint ( _stdcall * StartCan )( uint DeviceType,  uint DeviceInd, uint CANInd);
typedef  uint ( _stdcall * InitCan )( uint DeviceType,  uint DeviceInd, uint CANInd,  CAN_INIT_CONFIG *can_config );
typedef  uint ( _stdcall * Transmit )( uint DeviceType,  uint DeviceInd, uint CANInd,  VCI_CAN_OBJ *pSend, uint Len );
typedef  uint ( _stdcall * Receive )( uint DeviceType,  uint DeviceInd, uint CANInd,  VCI_CAN_OBJ *pReceive, uint Len, int WaitTime );
typedef  uint ( _stdcall * FindDevice)(uint DeviceType, char *Receive,int ReceiveLen);//MTH-T
typedef  uint ( _stdcall * ReadBoardInfo)(uint DeviceType, uint DeviceInd, VCI_BOARD_INFO *pInfo);
typedef  uint ( _stdcall * GetReceiveNum)(uint DeviceType, uint DeviceInd, uint CANInd);
typedef  uint ( _stdcall * ClearBuffer)(uint DeviceType, uint DeviceInd, uint CANInd);
typedef  uint ( _stdcall * ResetCan)(uint DeviceType, uint DeviceInd, uint CANInd);

typedef uint (_stdcall * ReadErrInfo)(uint DevType, uint DevIndex, uint CANind , ERR_INFO * pInfo);

/*MRH特殊*/
typedef  int ( _stdcall * CanWrite)(uint DeviceType, uint DeviceInd, byte Send[], uint Len);
typedef  int ( _stdcall * CanRead)(uint DeviceType, uint DeviceInd, byte Receive[], uint Len, int WaitTime);
typedef  uint ( _stdcall * ConnectDevice)(uint DevType, uint DevIndex);
typedef  uint ( _stdcall * UsbDeviceReset)(uint DevType, uint DevIndex, uint Reserved);
typedef  uint ( _stdcall * FindUsbDevice)( VCI_BOARD_INFO1 *pInfo);

class CANcommuniction: public QObject//,public QThread
{
    Q_OBJECT
public:
    CANcommuniction();
    ~CANcommuniction();
    void run();
private:

    /*关闭Close CAN设备的函数指针*/
    CloseCan closecan;

    /*关闭Open CAN设备的函数指针*/
    OpenCan opencan;

    //关闭Start CAN设备的函数指针
    StartCan startcan;

    /*CAN设备发送数据的函数指针*/
    Transmit send = nullptr;

    /*CAN设备接收数据的函数指针*/
    Receive receive;

    /*CAN设备初始化的函数指针*/
    InitCan initcan;

    ResetCan resetCan;

    FindDevice finddevice;

    /*获取板子信息*/
    ReadBoardInfo readboardinfo;

    /*获取得到接收的数量*/
    GetReceiveNum getReceiveNum;

    ClearBuffer clearBuffer;

    ReadErrInfo readErrInfo;

    /*MRH 特有的*/
    CanWrite CANwrite;

    CanRead CANread;

    ConnectDevice connectDevice;

    UsbDeviceReset usbDeviceReset;

    FindUsbDevice findUsbDevice;

    /*CANLIB库句柄类型*/
    CANTYPE CanType;

    /*CANLIB库句柄*/
    QLibrary Canlib;

public:
    /*封装CAN设备发送命令的函数*/
    int SendData(uint id,char main, char sub, QList< char > param , int channel=-1 , int index=-1);
    int SendData(uint id, QList<char> param );
    //int SendData(uint id,unsigned char main, unsigned char sub, QList<unsigned char> param , int channel=-1 , int index=-1);
    unsigned int getNum();

    /*封装CAN设备接收数据的函数*/
    CAN_OBJ receivedata();

    /*用于线程接收回传的CAN数据*/
    CAN_OBJ receivedata(uint DeviceType ,uint DeviceInd ,uint CANInd );
    /*没有定时器的接收函数*/
    //    CAN_OBJ receivedata(void * NG);

    /**/
    static CAN_OBJ receivedata(void *  m_this );
    static int SendData(uint id, QList< char> param ,void * m_this);
    /*PVT数据专用的发送的数据的函数*/
    int  SendPvtData(uint id,char main, QList<char> param , int channel , int index);

    /*判定是否加载库函数成功*/
    bool isLoadCanLibSucess();

    /*重载封装CAN设备的接收数据的函数*/
    CAN_OBJ receivedata( int delayCount);

    /*加载CANLIB的函数*/
    int OpenCanLib(CANTYPE CanType);
    /*打开CAN设备*/
    int OpenCAN(uint DeviceType,uint DeviceInd);

    /*配置CAN的通讯参数，以及启动CAN设备*/
    int StartCANDevice (uint DeviceType,uint DeviceInd, uint CANInd,CAN_INIT_CONFIG *config );
    /*默认的配置参数*/
    int StartCANDevice (uint DeviceType,uint DeviceInd, uint CANInd);

    /*关闭CANLIB的函数*/
    int CloseCanLib();
    /*关闭CAN*/
    void closeCan();

    /*设置消息发送的打印窗口*/
    void setPrintfWidget(QListWidget * printfWidget );

    /*清理clearReceiveBuffer*/
    void clearReceiveBuffer();
    /*获取CAN板子的信息*/
    VCI_BOARD_INFO getCAN_BOARD_INFO();
    /*获取板子的错误信息*/
    ERR_INFO getCanERR_INFO();

public slots:
    /*定时器的溢出的处理槽函数*/
    void timeouthandle();
signals:
    void messgInfo(QString messg);

public:
    /*判定是否建立和驱动器之间的连接标志*/
    bool isCanLink;
    int sendId = 1;
    int receiveId ;
    static QMutex m_lock;
private:
    /*时间溢出*/
    QTimer timeout;
    /*时间溢出标志*/
    bool timeOutFlag = false ;
    QListWidget * printWidget= nullptr;
    /*长时间接收不到数据 是否屏蔽提示窗使能*/
    bool TipWidget = true;

    /*CAN分析仪的板子信息*/
    VCI_BOARD_INFO CAN_BOARD_INFO;

    uint DeviceType = USBCAN2 ;
    uint DeviceInd  = 0;
    uint CANInd = 0 ;

};

//QMutex  CANcommuniction::m_lock ;




#endif // CANCOMMUNICTION_H
