/*********************************************************************************************
Copyright (C) 2016，北京镁伽机器人科技有限公司
文 件 名:  comStruct.h;
功能描述:  ;
函数列表:  ;
当前版本:  1.0.0;
版本改动:  ;
作    者:  CJ;
完成日期:  2017.01.10;
历史版本:  无;
*********************************************************************************************/
#ifndef __COM_STRUCT_H
#define __COM_STRUCT_H
#pragma execution_character_set("utf-8")


/******************************************包含文件*******************************************/
#include "project.h"
#include "comEnum.h"
#include "comDebug.h"
#include "bspTimer.h"
#include "comInterface.h"
#include "pvtAlgorithm.h"
#include "Include/chartdefine.h"


/***************************************常数和类型声明****************************************/
/*-------------流Buffer结构体-------------*/
typedef struct 
{
    bool bNotEmpty    :1;      //是否有数据
    bool bRewind      :1;      //是否回绕
    bool bAlmostFull  :1;      //是否快满了
    u8   reverse      :5;      //保留

    u8   frameCount;
    
    u16  bufferSize;
    u16  headOffset;
    u16  tailOffset;
    u16  dataTailOffset;       //有效数据的尾部
    u16  reserveMemorySize;    
    u8   *pBuffer;
    
}StreamBufferStruct;

/*-------------软定时器结构体-------------*/
typedef struct
{
  bool         bUsed;            //是否启用
  u16          period;           //定时时间
  u64          timeout;          //超时时间
  TimeOutFunc  pTimerOutFunc;    //超时回调函数
  
}SoftTimerStruct;

/*-------------急停减速结构体-------------*/
typedef struct
{
    u8 stopMode;        //紧急停止模式
    
    f32  distance;    //指定距离内停止，实际使用的时候要换算成步数
    f32  time;        //指定时间内停止
      
}StopDecelerationStruct;

/*-------------急停减速结构体-------------*/
typedef struct
{
    u8  lineState;
    u8  totalState;
    
    u8 lineResp;    //线间失步响应
    u8 totalResp;   //行程内失步响应
    
    u16  lineOutNum;     //线间失步数上限
    u32  totalOutNum;    //行程内失步数上限
      
}OutOfStepInfoStruct;

/*-----PVT信息结构体------*/
typedef struct
{
    bool bClear;      //数据是否被清除过
    bool bRewind;     //PVT点Buffer是否回绕
    
    u8 pointIndex;    //Buffer中下一个点的写入位置
    
    u16 tailPoint;     //Buffer中未计算的点数
    
    u16 pvtBufferSize;    //PVT点BUFFER的大小，上电初始化后不可修改
    
    PvtPointStruct *pvtPoint;    //PVT点数据

    //总共12个字节
      
}PvtManageStruct;

/*-----PVT信息结构体------*/
typedef struct
{
    PvtPointStruct mainPvtPoint[PVT_POINT_BUFFER_SIZE];    //PVT点数据
    
    PvtPointStruct smallPvtPoint[PVT_POINT_BUFFER_SIZE];    //PVT点数据
    
    PvtPointStruct presetPvtPoint[PRESET_RESERVE][PVT_POINT_BUFFER_SIZE];    //PVT点数据

    u32 crc;

    //总共12*32+12*32+12*8*32+4 = 3844个字节
      
}PvtInfoStruct;

/*-----规划管理结构体------*/
typedef struct
{
    u8    execMode;       //执行模式
    u8    planMode;       //规划模式
    u8  motionMode;     //运动模式
    u8  modifyDuty;     //LVT模式下时间的调整占比
    
    u8 endState;    //运行结束状态
    u8  validPoint;     //Buffer中有效点数
    u8  warnPoint;      //FIFO模式警告点数
    
    u32 cycleNum;       //循环模式的循环数

    u32 bufferTime;     //FIFO模式下的缓冲时间，单位ms
    
    StopDecelerationStruct stopDecelInfo;    //停止减速
    OutOfStepInfoStruct    outOfStepInfo;    //失步信息

    //总共40个字节
      
}PlanManageStruct;

/*--------规划信息结构体---------*/
typedef struct
{
    PlanManageStruct plan[CH_TOTAL][WTTYPE_RESERVE];

    u32 crc;    //40*CH_TOTAL*WTTYPE_RESERVE + 4个字节(单轴为404个，8轴为3204)
      
}PlanInfoStruct;

/*-------------电机输出数据结构体-------------*/
#if FPGA_CALC_PVT
typedef struct
{
    bool bLastFrame;   //是否是最后一帧数据
    bool bPrefetch;
    u8   toSendBlkSize;   //有效数据的块长度，SDIO配置用，最大是2^14=16384
    u8   noSendPoints;
    
    u16 validBytes;      //有效的字节长度，包括writeAddr的长度
    u16 toSendBytes;     //要发送的字节长度，包括writeAddr的长度
    
    u32 totalPoints;     //总发送的数据长度，表示的是PVT段数
    
    u32 writeAddr;                        //波表的写地址，由FUNC赋值并使用
    
    PvtSegmInfoStruct pvtSegmInfo[OUTPUT_DATA_BUFFER_SIZE];    //数据Buffer

    //长度等于1+1+|2|+2+2+4+4+6*9 = 70
      
}OutputDataStruct;

#else

typedef struct
{
    bool bLastFrame;   //是否是最后一帧数据
    bool bSendEmpty;   //是否发送空数据，true--发送空数据，数据长度固定为3

    u8  toSendBlkSize;   //有效数据的块长度，SDIO配置用，最大是2^14=16384
    u8  emptyBlkSize;    //空数据的块长度，SDIO配置用
    
    u16 lastSendBytes;   //上次发送的字节长度
    u16 noSendPoints;    //未发送的数据长度，表示的是波表点数
    
    u16 validPoints;     //本次发送中有效波表点数
    u16 validBytes;      //有效的字节长度，包括writeAddr的长度
    
    u16 validEmpPoints;  //本次发送中有效空波表点数
    u16 validEmpBytes;   //有效的空字节长度，包括writeAddr的长度

    u16 toSendPoints;    //要发送的波表点数
    u16 toSendBytes;     //要发送的字节长度，包括writeAddr的长度
    
    u16 emptyPoints;     //要发送的空波表点数
    u16 emptyBytes;      //要发送的空字节长度，包括emptyDataAddr的长度
    
    u32 totalPoints;     //总发送的数据长度，表示的是波表点数
    
    u32 minPeriod;       //最小的周期值，也就是最大的速度
    
    u32 writeAddr;                        //波表的写地址，由FUNC赋值并使用
    u32 data[OUTPUT_DATA_BUFFER_SIZE];    //数据Buffer

    u32 emptyDataAddr;                          //空数据的地址，由FUNC赋值并使用
    u32 emptyData[OUTPUT_EMPTY_BUFFER_SIZE];    //空数据Buffer，数据用于为0

    //长度等于(9 + OUTPUT_DATA_BUFFER_SIZE + 4(1 + OUTPUT_EMPTY_BUFFER_SIZE)) * 4(F32) = 4144
      
}OutputDataStruct;
#endif

/*-------------电机信息结构体-------------*/
typedef struct
{
    u8 motorType;          //类型
    u8 stepAngel;          //步距角
    u8 microSteps;         //微步数
    u8 motorSize;          //电机尺寸
    
    u8   encoderState;      //编码器状态
    u8  encoderType;       //编码器类型
    u8  encoderChanNum;    //编码器通道数
    u8 encoderMult;       //编码器信号倍乘
    
    u8  posnUnit;    //系统运行过程中使用的单位，PVT和StopDecel使用    CJ 2017.06.29 Add
    u8  motorVolt;             //电机电压
    u8  motorCurr;             //电机电流，单位0.1mA，只用于显示
    u8  feedbackRatio;         //编码器反馈比例
    
    u16 gearRatioNum;       //减速比分子
    u16 gearRatioDen;       //减速比分母
    
    f32 lead;               //直线运动时的导程，单位mm/cycle
    
    f32 peakSpeed;          //最大运行速度
    f32 peakAcc;            //最大运行加速度    CJ 2017.05.24 Add
    
    f32 backlash;           //反向间隙
    
    u32 encoderLineNum;     //编码器线数
    //总共36个字节
    
}MotorManageStruct;

/*-------------电机信息结构体-------------*/
typedef struct
{
    MotorManageStruct motor[CH_TOTAL];

    u32 crc;    //36*CH_TOTAL + 4个字节(单轴为40个，8轴为292)
    
}MotorInfoStruct;

/*-------------急停配置结构体-------------*/
typedef struct
{
    StopModeEnum stopMode;    //紧急停止模式
    
    u32  stopSteps;    //指定步数内停止
    f32  stopTime;     //指定时间内停止
    
    u32  emergPeriod;    //停止周期，周期值大于此值后就认为可以直接停止了
    u32  minPeriod;      //最小周期值，其实就是最大速度
      
}StopConfigStruct;

/*-------------运行信息结构体-------------*/
typedef struct
{
    u8  stateReport;      //状态上报方式
    u8     initPostUnit;     //初始位置使用的单位，由传感器输出值的单位决定
    u8    initIOPin;        //作为初始位的IO管脚
    u8  offsetState;

    u8 reserve;    //运行反向的开关删除了，这里放个保留的保证之前的结构体对齐
    
    u8  startSrc;         //启动源
    u8  startType;        //接收ID类型
    
    f32  maxSpeed;
    f32  minSpeed;
    f32  maxPosn;
    f32  minPosn;
    f32  maxTorque;
    f32  minTorque;
    f32  maxAcc;       //最大最小加速度    CJ 2017.05.24 Add
    f32  minAcc;
    u32  origin;
    
    //总共11*4=44个字节
      
}MotionManageStruct;

/*-------------运行信息结构体-------------*/
typedef struct
{
    MotionManageStruct motion[CH_TOTAL];
    
    u32 crc;    //44*CH_TOTAL + 4个字节(单轴为76个，8轴为580)
      
}MotionInfoStruct;

/*-------------上报器信息结构体-------------*/
typedef struct
{
    u8 state[REPTTYPE_RESERVE];
    u32             period[REPTTYPE_RESERVE];    //上报周期

    //总共100字节
    
}ReportManageStruct;

/*-------------上报器信息结构体-------------*/
typedef struct
{
    ReportManageStruct report[CH_TOTAL];
    
    u32 crc;    //100*CH_TOTAL + 4个字节(单轴为104个，8轴为804)
    
}ReportInfoStruct;

/*-------------OTP信息结构体-------------*/
typedef struct
{
    u8   state;
    u8  response;
    u16               threshold;
    u32               period;
    
}OtpInfoStruct;

/*------------数字传感器结构体-----------*/
typedef struct
{
    u8   trigMode;
    
    u8   pattState;    //码型触发时的状态
    u8  pattResponse;
    u8  pattSMode;
    
    f32               pattSPeriod;
    
    u8   levelState[TRIGPIN_RESERVE];    //电平触发时的状态
    u8  levelResponse[TRIGPIN_RESERVE];
    u8  levelSMode[TRIGPIN_RESERVE];
    
    u8    type[TRIGPIN_RESERVE];    //两种触发模式共用
    
    f32               levelSPeriod[TRIGPIN_RESERVE]; 

    //总共48(单轴)/24(多轴)个字节
    
}TrigInManageStruct;

/*------------数字传感器结构体-----------*/
typedef struct
{
    TrigInManageStruct trigIn[CH_TOTAL];
    
    u32 crc;    //单轴为48+4=52个，8轴为24*8+4=196
    
}TrigInInfoStruct;

/*------------数字传感器结构体-----------*/
typedef struct
{
    u8  state;
    u8    signal;
    u8  polarity;
    u8      source;
    u8     condition;
    u16              duty;
    u32              period;    

    //总共12字节
    
}DigitalOutManageStruct;

/*------------数字传感器结构体-----------*/
typedef struct
{
    DigitalOutManageStruct output[DIO_RESERVE]; 
    
    u32 crc;    //单轴为2*12+4=28个，8轴为4*12+4=52
    
}DigitalOutStruct;

#ifdef PROJECT_QUBELEY
/*-----------模拟传感器结构体------------*/
typedef struct
{
    SensorStateEnum   state;
    ResponseTypeEnum  responseH;    //CJ 2017.05.18 Modify
    ResponseTypeEnum  responseL;    //CJ 2017.05.18 Modify
    
    u16 adcCodeH;
    u16 adcCodeL;
    
    f32 thresholdH;
    f32 thresholdL;   
    
    u32 crc;//前面是16个字节，加CRC总共20个字节
    
}AnalogInfoStruct;
#endif

/*-----------空间坐标结构体------------*/
typedef struct
{
    float xAxis;
    float yAxis;
    float zAxis;
    
}CoordinateStruct;

/*-----------角度传感器码值结构体------------*/
typedef struct
{
    u16  xCode;
    u16  yCode;
    u16  zCode;
    
}SensorCodeStruct;

/*----------传感器数据结构体---------*///包含了上报器和角度传感器的上报数据，把数据和设置参数分离，统一管理数据
typedef struct
{
    u32 reporterData[CH_TOTAL][REPTTYPE_RESERVE];    //上报器数据

    u32 temperature;
    
}SensorDataStruct;


/*-------------参数上限结构体-------------*/
typedef struct
{
    u8  snUartFrameLen;
    u8  snUartRecvNum;
    u8  feedbackRatio;
    u8  fanDuty;

    s8  sgLimit;
    
    s16 otpThr;
    s16 canGroup;
    
    s16 motorGearRatio;
    s16 motorVolt;
    s16 motorCurr;

    u16 alarmDist;
    u16 ledFlickerFreq;
    
    s32 canSendId;
    s32 canReceiveId;
    s32 canGroupId;    
    s32 canRadioId;

    s32 pvtStartPoint;
    s32 pvtEndPoint;
    u32 pvtNcycles;
    s32 pvtWarnPoint;
    f32 motorPeakSpeed;
    f32 motorPeakAcc;
    f32 motorLead;
    f32 motorBacklash;
    u32 encoderLineNum;
    
    f32 pvtPosn;
    f32 pvtSpeed;
    f32 pvtTime;

    f32 stopTime;
    f32 stopDistance;
    f32 endSpeed;
    
    f32 initPostValue;
    f32 inchingTimeValue;
    f32 inchingDisValue;
    
    f32 motionMaxSpeed;
    f32 motionMaxPosn;
    f32 motionMaxTorque;
    f32 motionMaxAcc;

    s32 outOfStepNum;

    u32 reportPeriod;
    f32 trigInPeriod;
    u32 trigOutPeriod;
    u16 trigOutDuty;
    
    f32 snUartSwTime;
    
    f32 asensorThr;

    u32 fpgaPwmClock;    //CJ 2017.04.12 Add
    
    u16 lineOutNum;    //占比不做验证了，丢步的上限需要验证
    
    u32 switchTime;

#if FPGA_READ_ABSENC 
    s32 absEncValue;
#else
    u32 absEncValue;
#endif

    u32 bufferTime;
    
}UpLimitStruct;

/*-------------参数下限结构体-------------*/
typedef struct
{
    u8  snUartFrameLen;
    u8  snUartRecvNum;
    u8  feedbackRatio;

    s8  sgLimit;
    
    s16 otpThr;
    s16 canGroup;
    
    s16 motorGearRatio;
    s16 motorVolt;
    s16 motorCurr;

    u16 alarmDist;
    u16 ledFlickerFreq;
    
    s32 canSendId;
    s32 canReceiveId;
    s32 canGroupId;    
    s32 canRadioId;

    s32 pvtStartPoint;
    s32 pvtEndPoint;
    u32 pvtNcycles;
    s32 pvtWarnPoint;
    f32 motorPeakSpeed;
    f32 motorPeakAcc;
    f32 motorLead;
    f32 motorBacklash;
    u32 encoderLineNum;
    
    f32 pvtPosn;
    f32 pvtSpeed;
    f32 pvtTime;

    f32 stopTime;
    f32 stopDistance;
    f32 endSpeed;
    
    f32 initPostValue;
    f32 inchingTimeValue;
    f32 inchingDisValue;
    
    f32 motionMinSpeed;
    f32 motionMinPosn;
    f32 motionMinTorque;
    f32 motionMinAcc;

    s32 outOfStepNum;

    u32 reportPeriod;
    f32 trigInPeriod;
    u32 trigOutPeriod;
    u16 trigOutDuty;
    
    f32 snUartSwTime;
    
    f32 asensorThr;

    u32 fpgaPwmClock;    //CJ 2017.04.12 Add
    
    u16 speedScale;
    
    u32 switchTime;

#if FPGA_READ_ABSENC 
    s32 absEncValue;
#else
    u32 absEncValue;
#endif

    u32 bufferTime;
    
}DownLimitStruct;

/*-----------参数上下限结构体-------------*/
typedef struct
{
    UpLimitStruct   upLimit;
    DownLimitStruct downLimit;
    
}ParaLimitStruct;

typedef struct
{
    u8  majorType;    //产品主类型
    u8  minorType;    //产品子类型
    u8  hardVer;      //硬件版本号
    
    u8  majorVer;     //逻辑主版本号
    u8  minorVer;     //次版本号
    u8  buildVer;     //修订版本号
    
}FpgaVersionStruct;

typedef union
{
    u8  verArray[FPGA_VER_LEN];

    FpgaVersionStruct verStruct;
    
}FpgaVersionUnion;

/*-------------设备信息存储结构体-----------*/
typedef struct
{
    u8 sDevcModel;    //子型号
    
    u8 deviceSn[DEVICE_SN_LEN];       //序列号

    u32 crc;    //总共1+19+4=24个字节
    
}DeviceInfoStorageStruct;

/*-------------设备信息结构体-----------*/
typedef struct
{
    DeviceInfoStorageStruct storageInfo;    //子型号和序列号，存储在FLASH或者EEPROM中

    u8 mDevcModel;    //主型号，固定为MDMODEL_MRQ
    u8  sDevcModel;    //子型号，端口读到的值

    FpgaVersionUnion fpga;

    u8 software[SOFTWARE_VER_LEN];    //分支版本号+大版本号+小版本号+编译版本号, 编译版本号不对外
    u8 hardware[HARDWARE_VER_LEN];
    u8 boot[BOOT_VER_LEN];
    
    u8 driverBoardDn[DRVBOARD_VER_LEN];    //下板的硬件版本号
    u8 driverBoardUp[DRVBOARD_VER_LEN];    //上板的硬件版本号
    
}DeviceInfoStruct;

/*-------------系统信息结构体-----------*/
typedef struct
{    
    u8  workMode;
    u8  powerOn;
    
    u8 revMotion;    //反向运行，实际用来区分新旧机械版本    CJ 2018.12.27 Modify
    
    u8 group[CH_TOTAL][GROUP_NUM];    //默认129，用户可设置，范围130-255

    u8 mainLabel[CH_TOTAL];    //主标签
    u8  subLabel[CH_TOTAL];     //子标签

#if GELGOOG_SINANJU
    u8  fanDuty;
    u8  armLedDuty[ARMLED_RESERVE];
    
    u32 fanFrequency;
    u32 armLedFreq[ARMLED_RESERVE];
#endif

    OtpInfoStruct otpInfo;    //OTP信息，8字节

    f32 fpgaClockOffset;         //FPGA输出PWM的时钟和标准时钟的误差

    u32 crc;    //总共(单轴24个字节，GELGOOG 52个字节，SINANJU 64个字节)
    
}SystemInfoStruct;

/*-------------FPGA中断源结构体-------------*/
typedef struct
{
    u16 posState1 :1;    //限位开关状态
    u16 posState2 :1;    //
    u16 posState3 :1;    //
    u16 posState4 :1;    //
    u16 posState5 :1;    //
    u16 posState6 :1;    //
    u16 posState7 :1;    //
    u16 posState8 :1;    //
    
    u16 posState9  :1;    //
    u16 posState10 :1;    //
    u16 posState11 :1;    //
    u16 posState12 :1;    //
    u16 posState13 :1;    //
    u16 posState14 :1;    //
    u16 posState15 :1;    //
    u16 posState16 :1;    //
    
}DioRefStateStruct;

typedef union
{
    DioRefStateStruct dioRefState;

    u16 dioRefStateValue;
    
}DioRefStateUnion;

/*-------------定时器管理结构体-------------*/
typedef struct
{
    //系统相关
    SensorStateEnum dioRefRead;
    SensorStateEnum ledManage;

    //通道相关
    SensorStateEnum motionState[CH_TOTAL];
    SensorStateEnum motionMonitor[CH_TOTAL];
    SensorStateEnum lineOutOfStep[CH_TOTAL];
    SensorStateEnum driverMonitor[CH_TOTAL]; 
    //u8 report[CH_TOTAL][REPTTYPE_RESERVE];    //暂时先不支持
    SensorStateEnum driverCurr[CH_TOTAL];
    
    //Gelgoog独有
    SensorStateEnum isolatorIn;
    
    //Qubeley独有
    SensorStateEnum otp;
    SensorStateEnum analogIn;
    
}SoftTimerStateStruct;

typedef struct
{
    //系统相关
    SensorStateEnum sampleState;
    u8    chanNum;
    u8    encDiv;

    u16   readOffset;
    u16   readLen;

    u16   mstepCount;

    void *mstepData; 
    
}PdmInfoStruct;

/*-------------系统状态结构体-----------*/
typedef struct
{
    EnginModeEnum    EnginMode;       //工程模式
    u8               chanNum;         //系统支持的通道数
    u8               doutNum;         //系统支持的数字输出路数
    u8               youtNum;         //系统支持的隔离输出路数
    
    SysStateEnum     systemState;     //当前系统模式
    DistingStateEnum distState;       //识别状态
    
    ClockSyncStateEnum clockSyncState;   //时钟同步的状态
    ClockSyncRegEnum   clockSyncReg;     //时钟同步寄存器的状态
    ReceiveTypeEnum    clockSyncType;    //时钟同步时接收ID类型
    
    LevelStatusEnum    levelStatus;

    SensorStateEnum    dioRefRead;       //DIOREF状态读取开关
    
    WaveTableTypeEnum  calcQueue[CH_TOTAL][PVT_CALC_QUEUE_SIZE];    //解算队列
    u8                 calcIndex[CH_TOTAL];                         //解算队列当前解算索引
    u8                 tailIndex[CH_TOTAL];                         //解算队列队尾索引
        
    
    u8                 eventCode[EVENT_CODE_LEN];    //错误代码

#if FPGA_CALC_PVT
    bool bWriteAllow[CH_TOTAL];    //是否可写PVT到FPGA中
    bool bPending[CH_TOTAL];       //是否把线程挂起了
#endif

#if MRV_SUPPORT 
    ChanStateEnum      chanState[CH_TOTAL + MRV_CH_TOTAL_NUM];        //通道状态
    ChanStateEnum      lastChanState[CH_TOTAL + MRV_CH_TOTAL_NUM];    //上次通道状态
    
    WaveTableTypeEnum  calcWaveTable[CH_TOTAL + MRV_CH_TOTAL_NUM];    //当前解算的波表
    WaveTableTypeEnum  outpWaveTable[CH_TOTAL + MRV_CH_TOTAL_NUM];    //当前输出的波表
    
    u8 bStateSwitch[CH_TOTAL + MRV_CH_TOTAL_NUM][WTTYPE_RESERVE];     //状态切换检测
    
#else
        
    ChanStateEnum      chanState[CH_TOTAL];        //通道状态
    ChanStateEnum      lastChanState[CH_TOTAL];    //上次通道状态
    
    WaveTableTypeEnum  calcWaveTable[CH_TOTAL];    //当前解算的波表
    WaveTableTypeEnum  outpWaveTable[CH_TOTAL];    //当前输出的波表
    
    u8 bStateSwitch[CH_TOTAL][WTTYPE_RESERVE];     //状态切换
#endif

#if GELGOOG_SINANJU
    DistAlarmEnum  sysDistAlarm;
    DistAlarmEnum  chDistAlarm[DIST_SENSOR_NUM];

    SensorStateEnum absEncLimit[ABS_ENCODER_NUM];
    
    SensorStateEnum ledFlickerState;
    u16             ledFlickerFreq;
    
    PdmInfoStruct pdmInfo[CH_TOTAL];
#endif

    u16 eventValue;

    s16  circleNum[CH_TOTAL];
    
    s32  abCount[CH_TOTAL];
    s32  lastAbCount[CH_TOTAL];
    
    u32  cycleNumCount[CH_TOTAL];
    
    u32  clockCount;        //时钟同步计数
    u32  currSteps;         //电机当前所在位置，用相对于0位的步数记录

    u32  pvtCalcTaskSem;        //初始化时给PVTCALC任务的信号量数量

    PosnConvertInfoStruct posnConvertInfo[CH_TOTAL];
    
    ConfigStateEnum configState[CH_TOTAL][WTTYPE_RESERVE];   //PVT参数的配置状态
    PvtManageStruct pvtManage[CH_TOTAL][WTTYPE_RESERVE];

    SoftTimerStateStruct softTimer;
    
}SystemStateStruct;


/*--------通道配置位图结构体-------*/
typedef struct
{
    u8 bWaveTableData :1;    //波表数据
    u8 bPrepare       :1;    //进行运动准备
    u8 bStop          :1;    //停止
    u8 bEmergStop     :1;    //紧急停止 
    u8 bQryReady      :1;    //查询FPGA的Ready状态
    u8 bCycleQry      :1;    //查询循环次数 
    u8 bEncoder       :1;    //编码器
    u8 bOutOfStep     :1;    //设置失步
    
    u8 bTrigIn        :1;    //设置触发输入
    u8 bStartSrc      :1;    //设置启动源
    
    u8 reserve1       :1;    //暂时保留
    
    u8 bReportTorque  :1;    //xyzheng 上报力矩 
    u8 bMicroStep     :1;    //电机细分配置
    u8 bCurrent       :1;    //电流配置
    u8 bDriverState   :1;    //驱动状态配置
    u8 bDriverQuery   :1;    //查询驱动状态
    
    u8 bDrvCtrl       :1;    //设置DRVCTRL寄存器
    u8 bChopConfig    :1;    //设置CHOPCONF寄存器
    u8 bSmarten       :1;    //设置SMARTEN寄存器
    u8 bSgcsConfig    :1;    //设置SGCSCONF寄存器
    u8 bDrvConfig     :1;    //设置DRVCONF寄存器
    u8 bMotnMode      :1;    //
    u8 bModifyDuty    :1;    //
    u8 bLineMult      :1;    //
    
    u8 bBlReset       :1;    //
    u8 bPdmSample     :1;    //
    u8 bPdmDataRead   :1;    //
    u8 bAbsEncLimit   :1;    //

    u8 reserve        :4;    //预留
    
}ChanCfgBmpStruct;


/*--------系统配置位图结构体-------*/
typedef struct
{
    u8 bRun           :1;    //开始输出
    u8 bDebugMotor    :1;    //电机调试  xyzheng
    u8 bClockReg      :1;    //设置时钟同步寄存器
    u8 bClockCount    :1;    //读取时钟同步计数值    CJ 2017.04.11 Add  
    u8 bAnalogIn      :1;    //模拟输入 
    u8 bQryTemp       :1;    //查询温度
    u8 bDigitalOut1   :1;    //配置数字输出1
    u8 bDigitalOut2   :1;    //配置数字输出2
    
    u8 bDigitalIO3    :1;    //配置数字IO3
    u8 bDigitalIO4    :1;    //配置数字IO4
    u8 bIsolatorOut1  :1;    //配置隔离输出1
    u8 bIsolatorOut2  :1;    //配置隔离输出2
    u8 bSensorUart1   :1;    //配置传感器UART1
    u8 bSensorUart2   :1;    //配置传感器UART2
    u8 bIsolatorIn    :1;    //配置隔离输入
    u8 bDriverMode    :1;    //10轴的驱动细分
    
    u8 bDriverCurr    :1;    //10轴的驱动电流

    //取消反向运行功能    CJ 2018.12.27 DELETE

    u8 reserve        :7;    //预留
    
}SystemCfgBmpStruct;


typedef struct 
{
    u8   u8BootFlag;    //是否需要进入升级模式  1Byte
    u8   u8AppFlag;     //应用程序是否运行OK  1Byte  APP_IMAGE_OK--0xA5代表APP是可以运行的
    u8   u8TryCount;    //APP可以进行多次尝试(暂定3次)，只有连续多次尝试都不能运行后才认为APP无法使用 CJ 2017.05.19 Add
    
    u8   au8BootVer[BOOT_VER_LEN];/*软件版本号-> 高8位：主版本号;低8位：次版本号.  2Bytes */
    u32  u32AppBaseAddr;   //应用程序在flash中的地址   4Bytes
    u32  u32FpgaBaseAddr;  //FPGA在flash中的地址  4bytes
    
    u8   resv[20];    //前面是16个字节，预留20个字节，加CRC总共40个字节
    u32  crc;
    
}BootInfoStruct;


//Boot程序文件的Flash信息
typedef struct 
{
    u32  u32BaseAddr;
    u32  u32TotalSize;    
    u8   au8MD5CheckBuf[16];    
    u8   au8Version[6];
    
}FlashStruct;


/*-------------波表结构体-------------*/
typedef struct
{
    bool bEndIntEnable;    //结束中断的使能
    bool bCycleQuery;      //查询循环数
    
    MotionStateEnum     lastState;       //波表上次状态
    MotionStateEnum     waveState;       //波表当前状态
    WaveWorkModeEnum    waveWorkMode;    //波表工作模式

    u32 startAddr;       //波表起始地址
    u32 totalSize;       //波表大小，是4Bytes整数倍

    u32 writableAddr;    //可写地址，是4Bytes整数倍
    u32 writableSize;    //可写的波表点数

    f32 lineSteps;       //线间步，配给寄存器的值
    u32 lineMult;        //线数的倍乘

    StopConfigStruct stopConfigInfo;    //波表的急停减速信息
      
}WaveTableStruct;

/*------------隔离输出结构体-----------*/
typedef struct
{
    u8  state;
    u8      source;
    u8     condition;
    u8  response;

    //总共4字节
    
}IsolatorOutManageStruct;

/*------------隔离输出结构体-----------*/
typedef struct
{
    IsolatorOutManageStruct output[YOUT_RESERVE]; 
    
    u32 crc;    //2*4+4=12个
    
}IsolatorOutStruct;

/*------------传感器结构体-----------*/
typedef struct
{
    u8  state;       //状态
    u8               SOF;         //帧头
    u8               frameLen;    //帧长度
    u8               recvNum;     //一个周期内接收帧数
    u32              swTime;      //切换时间(Qubeley其实是周期)

    //总共8字节
    
}SensorManageStruct;

/*-----------传感器UART口结构体-------------*/
typedef struct
{
    UartIntfcStruct    uartIntfc[UARTNUM_RESERVE];   //5*2=12个字节
    SensorManageStruct sensor[UARTNUM_RESERVE][SENSOR_RESERVE];      //单轴8*2=16个字节，多轴8*2*4=64个字节
    
    u32 crc;    //单轴12+16+4=36个字节，多轴16+64+4=80个字节
    
}SensorUartStruct;

/*------------隔离输入结构体-----------*/
typedef struct
{
    IntfcStateEnum    state;       //电平触发时的状态
    ResponseTypeEnum  response;
    ChannelEnum       respChan;
    SamplingModeEnum  sMode;
    
    TrigInTypeEnum    type;
    
    u32 sPeriod; 

    u32 crc;    //总共16个字节
  
}IsolatorInStruct;


/*--------事件源位图结构体-------*/
typedef struct
{
#if MRV_SUPPORT 
    u8 bStateMonitor[CH_TOTAL + MRV_CH_TOTAL_NUM];       //状态切换检测
#else
    u8 bStateMonitor[CH_TOTAL];       //状态切换检测
#endif

    
    u8 bSenUart[UARTNUM_RESERVE][SENSOR_RESERVE];    //传感器Uart接收完成
    
#if GELGOOG_SINANJU

#if FPGA_READ_DIST
    u8 bDistSen;      //测距传感器
    
#else

    u8 bDistSen[DIST_SENSOR_NUM];      //测距传感器
#endif

#if FPGA_READ_ABSENC
    u8 bAbsEncoder;   //绝对值编码器

#else

    u8 bAbsEncoder[ABS_ENCODER_NUM];   //绝对值编码器
#endif

#endif

    u8 bDriverCurr[CH_TOTAL];       //电流切换

    u8 bDriverFault;

    u8 bFpgaInt;        //从FPGA来的中断
    u8 bAnalogInInt;    //模拟输入中断
    u8 bDeviceId;       //设备识别
    u8 bXInMatch;       //XIN匹配
    
    u8 distAlarmLed;

#if !GELGOOG_AXIS_10
    u8 drvStateRead[CH_TOTAL];    //驱动状态读取
#endif

    u8 backLashRead[CH_TOTAL];    //反向间隙读取

    
}EventSrcBmpStruct;


#if 0
#endif


/*------------TMC2660和TMC262的报警状态-----------*/
typedef struct
{
    u8 bStall  :1;    //stallguard状态, 为1表示达到堵转阈值 SG_TST会被拉高
    u8 bOTDown :1;    //1表示 温度达到150  发生芯片关闭保护
    u8 bOTWarn :1;    //1表示 温度达到100  发生过温报警
    u8 bS2GA   :1;    //1表示 A路高端mosfet发生接地短路
    u8 bS2GB   :1;    //1表示 B路高端mosfet发生接地短路
    u8 bOLA    :1;    //1表示 A路负载开路  应是电机没接或者线圈断了
    u8 bOLB    :1;    //1表示 B路负载开路  应是电机没接或者线圈断了
    u8 bSTST   :1;    //1表示 处于停止状态,在过去的一段时间内没有接收到步进触发信号
    
}DriverWarnStruct;

/*------------TMC2660/262 DRVCTRL寄存器SPI模式-----------*/
typedef struct
{
    u32 CB   :8;    //B相电流值索引
    u32 PHB  :1;    //B相电流方向
    u32 CA   :8;    //A相电流值索引
    u32 PHA  :1;    //A相电流方向
    
    u32 addr :2;    //寄存器地址
    
    u32 resv_bit20_31 :12;
    
}DriverControlSpiStruct;

/*------------TMC2660/262 DRVCTRL寄存器STEP/DIR模式-----------*/
typedef struct 
{
    u32 MRES          :4;    //细分设置
    u32 resv_bit4_7   :4;
    
    u32 DEDGE         :1;    //边沿模式
    u32 INTPOL        :1;    //内部插值控制 0:禁用内部插值,1:使能内部插值
    u32 resv_bit10_17 :8;
    
    u32 addr          :2;    //寄存器地址
    
    u32 resv_bit20_31 :12;
    
}DriverControlStepDirStruct;

/*------------TMC2660/262 DRVCTRL寄存器联合体-----------*/
typedef union
{
    DriverControlStepDirStruct stepDirMode;
    DriverControlSpiStruct     spiMode;
    
    u32 regValue;
    
}DriverControlUnion;

/*------------TMC2660/262 CHOPCONF寄存器-----------*/
typedef struct
{
    u32 TOFF          :4;
    u32 HSTRT         :3;
    u32 HEND          :4;
    u32 HDEC          :2;
    u32 RNDTF         :1;
    u32 CHM           :1;    //斩波模式设置,0:扩展周期模式;1:传统的恒定快速衰减时间
    u32 TBL           :2;    //消隐时间
    
    u32 addr          :3;    //寄存器地址
    
    u32 resv_bit20_31 :12;
    
}ChopperConfigStruct;

/*------------TMC2660/262 CHOPCONF寄存器联合体-----------*/
typedef union
{
   ChopperConfigStruct regBitFiled;
    
    u32 regValue;
    
}ChopConfigUnion;

/*------------TMC2660/262 SMARTEN寄存器-----------*/
typedef struct
{
    u32 SEMIN         :4;    //当SG小于SEMIN时,调整电流
    u32 resv_bit4     :1;
    u32 SEUP          :2;    //电流增加比例因子
    u32 resv_bit7     :1;
    u32 SEMAX         :4;    //当SG高于SEMAX时,调整电流
    u32 resv_bit12    :1;
    u32 SEDN          :2;    //电流减小比例因子
    u32 SEIMIN        :1;    //最低电流缩放比例限制
    u32 resv_bit16    :1;
    
    u32 addr          :3;    //寄存器地址
    
    u32 resv_bit20_31 :12;

}CoolStepCofingStruct;

/*------------TMC2660/262 SMARTEN寄存器联合体-----------*/
typedef union
{
    CoolStepCofingStruct regBitFiled;
    
    u32 regValue;
    
}CoolStepCofingUnion;

/*------------TMC2660/262 SGCSCONF寄存器-----------*/
typedef struct
{
    u32 CS            :5;    //电流缩放比例
    u32 resv_bit5_7   :3;
    u32 SGT           :7;    //电机失速指示阈值 stall guard threshold
    u32 resv_bit15    :1;
    u32 SFILT         :1;    //是否进行滤波
    
    u32 addr          :3;    //寄存器地址
    
    u32 resv_bit20_31 :12;
    
}StallGuard2ConfigStruct;

/*------------TMC2660/262 SGCSCONF寄存器联合体-----------*/
typedef union
{
    StallGuard2ConfigStruct regBitFiled;
    
    u32 regValue;
    
}StallGuard2ConfigUnion;

/*------------TMC2660/262 DRVCONF寄存器-----------*/
typedef struct
{
    u32 resv_bit0_3   :4;
    u32 RDSEL         :2;    //回读寄存器选择
    u32 VSENSE        :1;
    u32 SDOFF         :1;    //关闭STEP/DIR接口
    u32 TS2G          :2;    //接地短路检测时间
    u32 DISS2G        :1;    //接地短路保护使能
    u32 resv_bit11    :1;
    u32 SLPL          :2;
    u32 SLPH          :2;
    u32 TST           :1;    //测试
    
    u32 addr          :3;    //寄存器地址
    
    u32 resv_bit20_31 :12;

}DriverConfigStruct;

/*------------TMC2660/262 DRVCONF寄存器联合体-----------*/
typedef union
{
    DriverConfigStruct regBitFiled;
    
    u32 regValue;
    
}DriverConfigUnion;

/*------------TMC2660和TMC262的报警状态-----------*/
typedef struct 
{
    SensorStateEnum state;
    u8              warning;
    u32             period;
    
    /*
    1.SG数据正常          否则  bit0 = 1
    2.S2GA S2GB都为0    否则  bit1 = 1
    3.OTPW OT 都为0     否则  bit2 = 1
    4.微步数据正常          否则  bit3 = 1
    */

}TMCMonitorParaStruct;

/*------------SG能效曲线报警阈值-----------*/
typedef struct 
{
    f32 UpperLimit;
    f32 LowerLimit;

}TMCSGLimitStruct;

/*------------SG相关的几个参数  准备以后只向用户开放这几个-----------*/
typedef struct
{
    u32 SGT;
    u32 SEMIN;
    u32 SEMAX;
    u32 SG0;
    
}TMCSGParaStruct;

/*------------驱动管理结构体-----------*/
typedef struct
{
    u8  state;
    u8   type;
    u8               curr;         //驱动电流，单位0.1mA
    u8               idleCurr;     //空闲电流，单位0.1mA

    u8  tuningState;
    u8    currRatio;
    
    u8    currIncre;
    u8    currDecre;
    
    s16 sgThreshold;
    u16 energEfficMax;
    u16 energEfficOffset;    //上限减偏移就是下限

    u32 switchTime;    //驱动电流到空闲电流的切换时间
        
    //DRVCTRL : Driver Control Register
    DriverControlUnion DRVCTRL;
    
    //CHOPCONF: Chopper Configuration Register
    ChopConfigUnion CHOPCONF;
    
    //SMARTEN : coolStep Configuration Register
    CoolStepCofingUnion SMARTEN;
    
    //SGCSCONF: stallGuard2 Configuration Register
    StallGuard2ConfigUnion SGCSCONF;
    
    //DRVCONF : Driver Configuration Register
    DriverConfigUnion DRVCONF;

    //总共40字节
    
}DriverManageStruct;

/*------------驱动信息结构体-----------*/
typedef struct
{
#if !GELGOOG_AXIS_10
    DriverManageStruct driver[CH_TOTAL]; 

#else
    SensorStateEnum  state[CH_TOTAL]; 
    DriverTypeEnum   type[CH_TOTAL];
    
    MicroStepEnum    microStep;
    u8               curr;
#endif

    u32 crc;    //单轴为40+4=44个，8轴为8*40+4=324，10轴28个字节
    
}DriverInfoStruct;

/*------------TMC2660/262 回读寄存器-----------*/
typedef struct
{
    u32 SG   :1;
    u32 OT   :1;
    u32 OTPW :1;
    u32 S2GA :1;
    u32 S2GB :1;
    u32 OLA  :1;
    u32 OLB  :1;
    u32 STST :1;
    
    u32 resv_bit8_9 :2;
    
    u32 MSTEP :10;
    
    u32 resv_bit20_31 :12;

}DriverReadRespZeroStruct;

/*------------TMC2660/262 回读寄存器-----------*/
typedef struct
{
    u32 SG   :1;
    u32 OT   :1;
    u32 OTPW :1;
    u32 S2GA :1;
    u32 S2GB :1;
    u32 OLA  :1;
    u32 OLB  :1;
    u32 STST :1;
    
    u32 resv_bit8_9 :2;
    
    u32 SGALL :10;
    
    u32 resv_bit20_31 :12;

}DriverReadRespOneStruct;

/*------------TMC2660/262 回读寄存器-----------*/
typedef struct
{
    u32 SG   :1;
    u32 OT   :1;
    u32 OTPW :1;
    u32 S2GA :1;
    u32 S2GB :1;
    u32 OLA  :1;
    u32 OLB  :1;
    u32 STST :1;
    
    u32 resv_bit8_9 :2;
    
    u32 SE  :5;
    u32 SGH :5;
    
    u32 resv_bit20_31 :12;

}DriverReadRespTwoStruct;


/*------------驱动回读寄存器联合体-----------*/
typedef union
{
    DriverReadRespZeroStruct readResp0; 
    DriverReadRespOneStruct  readResp1; 
    DriverReadRespTwoStruct  readResp2;
    
    u32 regValue;
    
}DriverReadRespUnion;


/*------------驱动监控结构体-----------*/
typedef struct
{
    SensorStateEnum energyState; 
    SensorStateEnum sgAllState; 
    SensorStateEnum sgseState; 

    u8  csValue;

    u32 * energyValue;
    u32 * sgAllValue; 
    u32 * sgseValue; 
    
}DriverMonitorStruct;

/*------------角度传感器数据结构体-----------*/
typedef struct 
{
    u8  head;    //包头标识符 固定为0x55
    
    AngleSensorDataTypeEnum dataType;    //包数据类型 取值:0x51,0x52,0x53
    
    u16 xAxis;       //三个轴数据和温度
    u16 yAxis;
    u16 zAxis;
    u16 temp;
    
    u8  sum;
    
}AngleSensorFrameStruct;

/*------------测距传感器数据结构体-----------*/
typedef struct 
{
    u8  SOF1;        //帧头，           固定为0x5A
    u8  SOF2;        //帧头，           固定为0x5A
    u8  dataType;    //本帧数据类型，固定为0x15
    u8  dataNum;     //数据量，          固定为0x03
    
    u8  dataH;
    u8  dataL;

    u8  model;    //0x03-一般测量;0x02-高精度测量;0x01-快速测量;0x00-长距离测量
    
    u8  sum;      //校验和
    
}DistanceSensorFrameStruct;

/*------------绝对值编码器数据结构体-----------*/
typedef struct 
{
    u8  SOF1;     //帧头，固定为0x1A
    u8  SOF2;     //帧头，固定为0x1A
    
    u8  state;    //本帧数据状态
    
    u8  abs0;     //单圈位置信息低8位
    u8  abs1;     //单圈位置信息中8位
    u8  abs2;     //单圈位置信息高8位
    
    u8  enid;     //固定为0x11
    
    u8  abm0;     //多圈信息低8位
    u8  abm1;     //多圈信息中8位
    u8  abm2;     //多圈信息高8位

    u8  almc;     //报警位
    
    u8  crc;      //校验和
    
}AbsEncoderFrameStruct;

#if GELGOOG_SINANJU
/*------------绝对值编码器Alarm结构体-----------*/
typedef struct
{
    u8  state;       //状态
    u8  zeroPost;    //零点位置是否存在
    u32              zeroValue;   //零位对应的编码器读数

#if FPGA_READ_ABSENC
    s32              upLimit;     //上限
    s32              dnLimit;     //下限
    
#else

    u32              upLimit;     //上限
    u32              dnLimit;     //下限
#endif

    //总共16字节
    
}AbsEncoderAlarmStruct;

/*------------测距传感器Alarm结构体-----------*/
typedef struct
{
    u8  state;          //状态
    u16              alarm1Dist;     //当检测到距离小于此值时开始通过总线发送警报
    u16              alarm2Dist;     //当检测到距离小于此值时开始减速停止并发送警报
    u16              alarm3Dist;     //当检测到距离小于此值时立即停止并发送警报
    
    //总8个字节
    
}DistSensorAlarmStruct;

/*-----------传感器Alarm结构体-------------*/
typedef struct
{
    AbsEncoderAlarmStruct encAlarm[ABS_ENCODER_NUM];
    u8      encAlarmResponse;
    
    DistSensorAlarmStruct distAlarm[DIST_SENSOR_NUM];
    
    u32 crc;    //16*4+4+8*4+4=104
    
}SensorAlarmStruct;
#endif

/*-------------调试信息结构体-----------*/
typedef struct
{
    //接收到的
    u32 pvtPosnCount[CH_TOTAL];
    u32 pvtVelcCount[CH_TOTAL];
    u32 pvtTimeCount[CH_TOTAL];
    
    //通过验证的
    u32 vefyPosnCount[CH_TOTAL];
    u32 vefyVelcCount[CH_TOTAL];
    u32 vefyTimeCount[CH_TOTAL];
    
    //解算完成的
    u32 calcPvtCount[CH_TOTAL];
    u32 chanRunTimeOut[CH_TOTAL];
    u32 chanRunTimeCount[CH_TOTAL];
    

    u16 ITFPGACount[CH_TOTAL];
    u16 FPGAResetCount[CH_TOTAL];
    u16 FPGAPrefetchCount[CH_TOTAL];
    u16 FPGARunCount[CH_TOTAL];
    u16 FPGARunAllCount;  
    

    u64 calcTime[CH_TOTAL];    //解算后的运行时间统计

    u64 runTime[CH_TOTAL];     //实际运行时间统计

    u16 debugValue[8][5];
    
}DebugInfoStruct;

#if MRV_SUPPORT
/*--------通道配置位图结构体-------*/
typedef struct
{
    u8 bPrepare       :1;    //进行运动准备
    u8 bStop          :1;    //停止
    u8 bEmergStop     :1;    //紧急停止
    
    u8 reserve        :5;    //预留
    
}MrvChanCfgBmpStruct;
#endif



#endif
/*****************************************END OF FILE****************************************/
