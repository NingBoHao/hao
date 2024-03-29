/*********************************************************************************************
Copyright (C) 2016，北京镁伽机器人科技有限公司
文 件 名:  comDebug.h;
功能描述:  ;
函数列表:  ;
当前版本:  1.0.0;
版本改动:  ;
作    者:  CJ;
完成日期:  2016.08.25;
历史版本:  无;
*********************************************************************************************/
#ifndef __COM_DEBUG_H
#define __COM_DEBUG_H
#include "Include/chartdefine.h"
#pragma execution_character_set("utf-8")

/******************************************包含文件*******************************************/
#include "project.h"



/*******************************************宏定义********************************************/ 
#define   DEBUG_MODE             0
#define   JTAG_MODE              0
#define   DEBUG_MOTOR            0
#define   DEBUG_CAN_TEST         1
#define   SUPPORT_CAN_NMT        1

#define   FOR_FPGA_DEBUG         0
#define   DRIVE_FROM_ARM         0
#define   SDIO_CRC_ERROR_ENABLE  0

#define   TUNING_SUPPORT         0
#define   SDIO_TX_RX_TEST        0

#if  GELGOOG_SINANJU
#define   MRV_SUPPORT            0
#define   FPGA_READ_ABSENC       0
#define   FPGA_READ_DIST         0
#endif

//#if GELGOOG_AXIS_2
#define   FPGA_CALC_PVT          1
#define   DATA_USE_DOUBLE        1
#define   FPGA_ENHANCED_TEST     0
//#endif



/******************************************全局变量*******************************************/
 


/******************************************函数声明*******************************************/



#endif
/*****************************************END OF FILE****************************************/
