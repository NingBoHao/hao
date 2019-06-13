#ifndef DEVICEINFO_H
#define DEVICEINFO_H
#include <QString>
#include "cancommuniction.h"
#include <QProgressBar>

/*设备信息结构体 设备的名字 MRQ_C/M/MC  以及设备的ID*/
typedef struct DeviceInfo
{
    QString deviceInfo  ;
    int deviceId  ;
    int receiveId ;
    uint deviceNumber ;
    uint device_hsahValue ;
    uint device_CHANUM_Count = 0;

    uint device_GROUP;
    uint device_GROUPID1;
    uint device_GROUPID2;
    uint *device_CHANUM_GROUP1 = nullptr ;
    uint *device_CHANUM_GROUP2 = nullptr ;
    unsigned int device_BROADCASTID = 1;
    /*发送数据的句柄*/
    CANcommuniction * canComm = nullptr;
    /*QProgressBar*/
    QProgressBar * updateProgressBar = nullptr;
}DeviceInfo;


typedef  struct PVTConfig{
    int MOTIONMODE;
    int PLANMODE;
    bool speedHold = false;
    bool FifoMode = false;
} PVTConfig;


typedef struct statuFind{
    int runStatu = -1 ;
    int runUnit = -1 ;
}statuFind;


typedef enum deviceCHANUMCount
{
    MRQ_C23S_CH_count = 1,
    MRQ_C23D_CH_count = 1,
    MRQ_M2304_CH_count = 4,
    MRQ_MV_CH_count = 5,
    MRQ_MC_CH_count = 10,
}deviceCHANUMCount ;


#endif // DEVICEINFO_H
