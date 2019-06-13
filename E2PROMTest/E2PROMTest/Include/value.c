
//2. 存储类变量
/*这两个是和BOOT共用的，所以存储地址和里面的成员变量不能随便修改!!!*/
BootInfoStruct    g_bootInfo;
CommIntfcStruct   g_commIntfc;
/*这两个是和BOOT共用的，所以存储地址和里面的成员变量不能随便修改!!!*/

/*PVT相关内容分为三部分************************/
//21. 规划相关参数(决定了波表的解算，波表停止减速以及失步等)；
PlanInfoStruct    g_planInfo;

//22. PVT点(因为占用内存比较大，多轴时放置在CCRAM中)
#ifdef PROJECT_GELGOOG
#pragma location = "PVTPOINT_SECTION"
#endif

PvtInfoStruct  pvtPointBuffer[CH_TOTAL];

//23. PVT管理参数(主要是解算过程中使用的中间变量，所以放置在g_systemState中)
/*PVT相关内容分为三部分************************/

DeviceInfoStruct  g_deviceInfo;
SystemInfoStruct  g_systemInfo;
MotorInfoStruct   g_motorInfo; 
MotionInfoStruct  g_motionInfo;
ReportInfoStruct  g_reportInfo;
TrigInInfoStruct  g_trigInInfo;
DigitalOutStruct  g_digitalOut;
IsolatorOutStruct g_isolatorOut;
SensorUartStruct  g_sensorUart;
DriverInfoStruct  g_driverInfo;

#ifdef PROJECT_QUBELEY
AnalogInfoStruct g_analogInfo;
#endif

#ifdef PROJECT_GELGOOG

#if GELGOOG_SINANJU
SensorAlarmStruct g_sensorAlarm;

#else

IsolatorInStruct  g_isolatorIn;
#endif

#endif