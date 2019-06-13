#ifndef DEVICEINFOHANDLE_H
#define DEVICEINFOHANDLE_H
#include "cancommuniction.h "
#include "CmdStruct/cmdstruct.h"
#include "Global/deviceinfo.h"

class deviceInfoHandle
{
public:
    deviceInfoHandle();
    /*初始化设备信息*/
    void initDeviceInfo(DeviceInfo * p_deviceInfo);
    DeviceInfo * getDeviceInfo();
    int getCHANNUM();
    int setCHANNUM(int Ch);
protected:
    /*设置CAN通讯的句柄*/
    int setComm(CANcommuniction * setCan);
    /*设置SENDID */
    void setSENDID(unsigned int p_sendId);
    /*发送数据的句柄*/
    CANcommuniction * canComm = nullptr;
    /*设备名信息*/
    DeviceInfo * deviceInfo = nullptr;

    /*QProgressBar*/
    QProgressBar * updateProgressBar = nullptr;
    /*广播ID*/
    unsigned int BROADCASTID = 1;
    /*SENDID 发送ID*/
    unsigned int SENDID = 0;
    /*通道索引*/
    int CHANNUM=0;
};

#endif // DEVICEINFOHANDLE_H
