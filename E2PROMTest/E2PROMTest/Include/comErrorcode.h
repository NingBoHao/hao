/*********************************************************************************************
Copyright (C) 2016������þ٤�����˿Ƽ����޹�˾
�� �� ��:  comErrorcode.h;
��������:  ;
�����б�:  ;
��ǰ�汾:  1.0.0;
�汾�Ķ�:  ;
��    ��:  CJ;
�������:  2016.08.25;
��ʷ�汾:  ��;
*********************************************************************************************/
#ifndef __COM_ERROR_CODE_H
#define __COM_ERROR_CODE_H
#pragma execution_character_set("utf-8")
#include "Include/chartdefine.h"

/*******************************************�궨��********************************************/
#define    ERROR_CODE_INDEX_PARA_VERIFY     0    //��������ڴ����������е��±�
#define    ERROR_CODE_INDEX_PVT_CALC        1    //PVT�����ڴ����������е��±�
#define    ERROR_CODE_INDEX_INTFACE         2    //�ӿڴ����ڴ����������е��±�
#define    ERROR_CODE_INDEX_FPGA            3    //FPGA�����ڴ����������е��±�
#define    ERROR_CODE_INDEX_MOTION          4    //���й����г�������
#define    ERROR_CODE_INDEX_SYSTEM          5    //ϵͳ������ִ���
#define    ERROR_CODE_INDEX_RESERVE         6    //����

/**********************************������֤***********************************/
#define    PARA_VERIFY_NO_ERROR            0
#define    PARA_VERIFY_ERROR_TYPE          1
#define    PARA_VERIFY_ERROR_LEN           2
#define    PARA_VERIFY_ERROR_INDEX         3
#define    PARA_VERIFY_LESS_LOWER_LIMIT    4
#define    PARA_VERIFY_GREAT_UPER_LIMIT    5
#define    PARA_VERIFY_OUT_RANGE           6   //������ö��֮��  cp 20170517
#define    PARA_VERIFY_ERROR_STATE         7

/**********************************PVT����***********************************/
#define    PVT_CALC_DDR_INSUFF_SPACE       1    //DDR�Ŀռ䲻��

/**********************************���Դ���***********************************/
#define    ENGINMODE_TEST_ERROR            1

/**********************************FPGA����***********************************/
#define    FPGA_VERIFY_NO_ERROR            0
#define    FPGA_DDR_VERIFY_ERROR           1
#define    FPGA_DDR_TEST_ERROR             2
#define    FPGA_WAVE_TABLE_NOCONFIG        3

/********************************�����쳣�¼�*********************************/
#define    OUT_OF_STEP_EVENT               0
#define    TRIGGER_STOP_EVENT              1

/******************************ϵͳ�洢���ݴ���*******************************/

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

/******************************************ȫ�ֱ���*******************************************/
 


/******************************************��������*******************************************/



#endif
/*****************************************END OF FILE****************************************/
