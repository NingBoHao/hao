#include "deviceinfohandle.h"

deviceInfoHandle::deviceInfoHandle()
{

}



/*设置CAN通讯的句柄*/
int deviceInfoHandle::setComm(CANcommuniction * setCan)
{
    if(canComm == nullptr)
    {
        canComm = setCan ;
    }
}
/*初始化设备信息*/
void deviceInfoHandle::initDeviceInfo(DeviceInfo *p_deviceInfo)
{
    deviceInfo = p_deviceInfo;
    SENDID = p_deviceInfo->receiveId;
    setComm(p_deviceInfo->canComm);
    updateProgressBar = p_deviceInfo->updateProgressBar;


}
DeviceInfo * deviceInfoHandle::getDeviceInfo()
{
    return deviceInfo;
}
/*设置SENDID */
void deviceInfoHandle::setSENDID(unsigned int p_sendId)
{
    SENDID = p_sendId;
}

int deviceInfoHandle::getCHANNUM()
{
    return  CHANNUM;
}

int deviceInfoHandle::setCHANNUM(int Ch)
{
    CHANNUM = Ch;
}
