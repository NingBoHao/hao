/*********************************************************************************************
Copyright (C) 2016������þ٤�����˿Ƽ����޹�˾
�� �� ��:  pvtalgorithm.h;
��������:  ;
�����б�:  ;
��ǰ�汾:  1.0.0;
�汾�Ķ�:  ;
��    ��:  CJ;
�������:  2016.08.22;
��ʷ�汾:  ��;
*********************************************************************************************/
#ifndef __PVT_ALGORITHM_H
#define __PVT_ALGORITHM_H



/******************************************�����ļ�*******************************************/
#include "comDatatype.h"
#include "Include/chartdefine.h"
#pragma execution_character_set("utf-8")


/****************************************�ⲿ��������*****************************************/



/*******************************************�궨��********************************************/
#define    OUTPUT_PERIOD_MIN              7    //���������Сֵ

#define    SQUARE(num)                    (num * num)
#define    CUBE(num)                      (num * num * num)
#define    PVT_TARGET_REAL_OFFSET_P       0.02f                            //����PVTÿ���ٶ�ʱ��ʵ�ʲ�����Ŀ�경��֮��������
#define    PVT_TARGET_REAL_OFFSET_N       PVT_TARGET_REAL_OFFSET_P * -1    //����PVTÿ���ٶ�ʱ��ʵ�ʲ�����Ŀ�경��֮��������
#define    LVT_TARGET_REAL_OFFSET_P       0.0003f                          //����LVTÿ���ٶ�ʱ��ʵ��������Ŀ������֮��������
#define    LVT_TARGET_REAL_OFFSET_N       LVT_TARGET_REAL_OFFSET_P * -1    //����LVTÿ���ٶ�ʱ��ʵ��������Ŀ������֮��������

#define    PVT_ONE_POINT_CALC_TIMES_MAX    1000    //����һ��������������

#define    SCALE_MAGNIFICATION             1000

//PVT���������
#define    PVT_CALC_NO_ERROR               0
#define    PVT_CALC_ERROR_TYPE             1
#define    PVT_CALC_ERROR_LEN              2
#define    PVT_CALC_ERROR_INDEX            3

#define    PVT_CALC_SECTION_1              0
#define    PVT_CALC_SECTION_2              16
#define    PVT_CALC_SECTION_3              32

#define    PVT_CALC_LESS_LOWER_LIMIT       1
#define    PVT_CALC_GREAT_UPER_LIMIT       2
#define    PVT_CALC_TOO_MANY_CALC_TIMES    3
#define    PVT_CALC_SPEED_EQUAL_ZERO       4

#define    PVT_WAIT_TIME_THRESHOLD    2147483648L
#define    OUTPUT_VELOCITY_MAX        0.125f    //��λustep/Hz����Ӧ��΢��������8

//#if GELGOOG_AXIS_2
#define    FPGA_CALC_PVT      1
#define    DATA_USE_DOUBLE    1
//#endif



/***************************************��������������****************************************/
/*******************ö��*********************/
/*-----------PVT�滮ģʽö��-----------*/
typedef enum
{
    PLANMODE_CUBIC = 0,    //���ζ���ʽ��ֵ
    PLANMODE_TRAPEZOID,    //���β�ֵ
    PLANMODE_SCURVE,       //S����
    
}PlanModeEnum;

/*-------------PVTģʽö��-------------*/
typedef enum
{
    EXECMODE_NCYCLE = 0,
    EXECMODE_FIFO,
    
}ExecModeEnum;

/*-------------�˶���ʽö��--------------*/
typedef enum
{
    MTNMODE_PVT  = 0,     //PVTģʽ
    MTNMODE_LVT_CORR,     //LVT������ģʽ
    MTNMODE_LVT_NOCORR,   //LVT��������ģʽ
    
}MotionModeEnum;

/*------------�����������ö��------------*/
typedef enum
{
    OUTPDATA_FORWARD = 2,    //������������
    OUTPDATA_REVERSE,        //������������
    OUTPDATA_WAIT,           //�ȴ�ʱ��
    
}OutpDataTypeEnum;

/*------------Buffer��������ö��------------*/
typedef enum
{
    BUFFOPERT_WRITE = 0,    //��˳��д��
    BUFFOPERT_FORCESEND,    //ǿ�Ʒ���
    BUFFOPERT_SYNCSEND,     //Ϊ��ͬ�����еķ���
    
}BufferOperateEnum;

#if FPGA_CALC_PVT
/*----------------PVT�׶�ö��---------------*/
typedef enum
{
    PVTDIR_FORWARD = 0,     //����
    PVTDIR_REVERSE,         //����
    
}PvtDirEnum;

/*----------------PVT�׶�ö��---------------*/
typedef enum
{
    PVTSEGM_WAIT = 0,    //�ȴ�ʱ��
    PVTSEGM_UNIF = 5,    //���ٶ�
    PVTSEGM_ACC,         //���ٶ�
    PVTSEGM_DEC,         //���ٶ�
    
}PvtSegmEnum;

typedef struct
{
    u16 pvtDir          :1;    //����
    u16 segmIndex       :3;    //�׶�
    
    u16 pvtIndex        :10;   //PVT����
    
    u32 resv_bit14_31   :18;
    
}PvtSegmStruct;

typedef  union
{
    PvtSegmStruct segmBitFiled;

    u32 segmValue;
    
}PvtSegmUnion;

typedef struct
{
    PvtSegmUnion pvtSegment;
    
    u32 motionCount;      //΢����

#if DATA_USE_DOUBLE
    f64 squareBdiv2A;     //(b / 2a)^2
    f64 coeffCdivA;       //c / a 
    f64 coeffBdiv2A;      //b / 2a
    f64 startSpeedInv;    //1 / v0
    
#else

    f32 squareBdiv2A;     //(b / 2a)^2
    f32 coeffCdivA;       //c / a 
    f32 coeffBdiv2A;      //b / 2a
    f32 startSpeedInv;    //1 / v0
#endif    
    
}PvtSegmInfoStruct;
#endif

/*******************ö��*********************/

#if FPGA_CALC_PVT
typedef void (*OutpBufferFillFunc)(u8 chanNum, 
                                   BufferOperateEnum bufferOperate, 
                                   PvtSegmInfoStruct pvtSegmInfo, 
                                   void *pPvtCalcData, 
                                   void *pContext);

#else

typedef void (*OutpBufferFillFunc)(u8 chanNum, 
                                   OutpDataTypeEnum datatype, 
                                   u32 outpData, 
                                   BufferOperateEnum bufferOperate,
                                   void *pPvtCalcData,
                                   void *pContext);
#endif


/******************�ṹ��********************/
/*-------------PVT��ṹ��-------------*/
typedef struct
{
    f32 position;    //λ��
    f32 speed;       //�ٶ�
    f32 time;        //ʱ��
    u16 accScale;    //����ռ��
    u16 decScale;    //����ռ��
      
}PvtPointStruct;

/*-------------λ��ת����Ϣ�ṹ��-----------*/
typedef struct
{
    f32 posnToStep;      //λ�õ�������ת��ϵ��
    f32 posnToLine;      //λ�õ�������������ת��ϵ�� 
    f32 lineSteps;       //�߼䲽
    u32 lineMult;        //�����ı���
    
}PosnConvertInfoStruct;

typedef struct
{
    bool           bQueryReady;    //�Ƿ��ѯFPGA Ready״̬
    bool           bReportCalcEnd; //�Ƿ��ϱ��˼������״̬��FIFOģʽ��ʹ�� CJ 2017.03.28 Add
    
    PlanModeEnum   pvtPlanMode;   //PVT�滮ģʽ
    ExecModeEnum   pvtExecMode;   //PVTִ��ģʽ
    
    MotionModeEnum   motionMode;     //�˶�ģʽ

    OutpDataTypeEnum lastStepDir;    //��һ���ķ���

    u16 lastPoint;      //�ϴν����PVT��ı��

#if FPGA_CALC_PVT
    u32 pvtCount;
    u32 minPeriod;       //��С������ֵ��Ҳ���������ٶ�
#endif

    u32 fpgaPwmClock;      //FPGA PWMʱ��
    f32 fpgaClockOffset;   //FPGA PWMʱ��ƫ��

#if DATA_USE_DOUBLE
    u32 startPosn;      //һ��PVT����ʼλ��
    f64 startSpeed;     //һ��PVT����ʼ�ٶ�
    f64 startTime;      //һ��PVT����ʼʱ��
    u32 endPosn;        //һ��PVT�Ľ���λ��
    f64 endSpeed;       //һ��PVT�Ľ����ٶ�
    f64 motionTime;     //һ��PVT������ʱ��
    u32 motionStep;     //һ��PVT�����о���(΢����/����)
        
    f64 invsePosition;  //�ϴη���ʱ��λ�� 
    f64 waitPosition;   //�ϴεȴ�ʱ��λ��  
    f64 waitStepError;  //��Ϊ�ƶ����벻��һ������Ϊ�ȴ�ʱ��Ĳ������
    
    u32 targetStep;     //Ŀ�경��
    f64 lastStepSpeed;  //��һ�����ٶȣ�ʵ�ʼ�¼����ʱ��
    f64 maxOffset;      //��Ŀ�경����������ֵ
    f64 minOffset;      //��Ŀ�경����������ֵ

    f64 posnToStep;     //λ�õ�������ת��ϵ��
    f64 lineSteps;      //�߼䲽
    f64 lineStepsInv;   //�߼䲽����

    f64 errorTime;      //�������뵼�µ��ۼ����
    
#else

    u32 startPosn;      //һ��PVT����ʼλ��
    f32 startSpeed;     //һ��PVT����ʼ�ٶ�
    f32 startTime;      //һ��PVT����ʼʱ��
    u32 endPosn;        //һ��PVT�Ľ���λ��
    f32 endSpeed;       //һ��PVT�Ľ����ٶ�
    f32 motionTime;     //һ��PVT������ʱ��
    u32 motionStep;     //һ��PVT�����о���(΢����/����)
        
    f32 invsePosition;  //�ϴη���ʱ��λ�� 
    f32 waitPosition;   //�ϴεȴ�ʱ��λ��  
    f32 waitStepError;  //��Ϊ�ƶ����벻��һ������Ϊ�ȴ�ʱ��Ĳ������
    
    u32 targetStep;     //Ŀ�경��
    f32 lastStepSpeed;  //��һ�����ٶȣ�ʵ�ʼ�¼����ʱ��
    f32 maxOffset;      //��Ŀ�경����������ֵ
    f32 minOffset;      //��Ŀ�경����������ֵ

    f32 posnToStep;     //λ�õ�������ת��ϵ��
    f32 lineSteps;      //�߼䲽
    f32 lineStepsInv;   //�߼䲽����

    f32 errorTime;      //�������뵼�µ��ۼ����
#endif

    PvtPointStruct startPoint;     //���μ��������PVT��
    PvtPointStruct endPoint;       //���μ��������PVT��

    OutpBufferFillFunc  outpBufferFill;
    
    void *pContext;    //������ָ�룬��λ��ʹ��

    u64 bufferTime;    //FIFOģʽ�µĻ���ʱ�䣬������20MHz

    u64 timeCount;     //ͳ����

}PvtCalcStruct;
/******************�ṹ��********************/



/******************************************��������*******************************************/



/******************************************��������*******************************************/
u8 pvtSegmentCalc(PvtCalcStruct *pPvtCalcData, u8 chanNum);



/*****************************************ͷ�ļ�����******************************************/
#endif
/*******************************************�ļ�β********************************************/
