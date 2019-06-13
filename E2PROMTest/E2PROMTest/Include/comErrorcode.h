/*********************************************************************************************
Copyright (C) 2016，北京镁伽机器人科技有限公司
文 件 名:  comErrorcode.h;
功能描述:  ;
函数列表:  ;
当前版本:  1.0.0;
版本改动:  ;
作    者:  CJ;
完成日期:  2016.08.25;
历史版本:  无;
*********************************************************************************************/
#ifndef __COM_ERROR_CODE_H
#define __COM_ERROR_CODE_H
#pragma execution_character_set("utf-8")
#include "Include/chartdefine.h"

/*******************************************宏定义********************************************/
#define    ERROR_CODE_INDEX_PARA_VERIFY     0    //命令错误在错误码数组中的下标
#define    ERROR_CODE_INDEX_PVT_CALC        1    //PVT错误在错误码数组中的下标
#define    ERROR_CODE_INDEX_INTFACE         2    //接口错误在错误码数组中的下标
#define    ERROR_CODE_INDEX_FPGA            3    //FPGA错误在错误码数组中的下标
#define    ERROR_CODE_INDEX_MOTION          4    //运行过程中出现问题
#define    ERROR_CODE_INDEX_SYSTEM          5    //系统本身出现错误
#define    ERROR_CODE_INDEX_RESERVE         6    //保留

/**********************************参数验证***********************************/
#define    PARA_VERIFY_NO_ERROR            0
#define    PARA_VERIFY_ERROR_TYPE          1
#define    PARA_VERIFY_ERROR_LEN           2
#define    PARA_VERIFY_ERROR_INDEX         3
#define    PARA_VERIFY_LESS_LOWER_LIMIT    4
#define    PARA_VERIFY_GREAT_UPER_LIMIT    5
#define    PARA_VERIFY_OUT_RANGE           6   //参数在枚举之外  cp 20170517
#define    PARA_VERIFY_ERROR_STATE         7

/**********************************PVT解算***********************************/
#define    PVT_CALC_DDR_INSUFF_SPACE       1    //DDR的空间不足

/**********************************测试错误***********************************/
#define    ENGINMODE_TEST_ERROR            1

/**********************************FPGA错误***********************************/
#define    FPGA_VERIFY_NO_ERROR            0
#define    FPGA_DDR_VERIFY_ERROR           1
#define    FPGA_DDR_TEST_ERROR             2
#define    FPGA_WAVE_TABLE_NOCONFIG        3

/********************************运行异常事件*********************************/
#define    OUT_OF_STEP_EVENT               0
#define    TRIGGER_STOP_EVENT              1

/******************************系统存储数据错误*******************************/

#define    EEPROM_SYSTEM_INFO_ERROR         0
#define    EEPROM_INTEFACE_INFO_ERROR       1
#define    EEPROM_MOTOR_INFO_ERROR          2
#define    EEPROM_MOTION_INFO_ERROR         3
#define    EEPROM_TRIT_IN_INFO_ERROR        4
#define    EEPROM_REPORT_INFO_ERROR         5
#define    EEPROM_TRIG_OUT_INFO_ERROR       6
#define    EEPROM_ISOL_OUT_INFO_ERROR       7
#define    EEPROM_SENSOR_UART_INFO_ERROR    8
#define    EEPROM_DRIVER_INFO_ERROR         9
#define    EEPROM_SENSOR_ALARM_ERROR       10
#define    EEPROM_MOTION_PLAY_ERROR        11

/******************************************全局变量*******************************************/
 


/******************************************函数声明*******************************************/



#endif
/*****************************************END OF FILE****************************************/
