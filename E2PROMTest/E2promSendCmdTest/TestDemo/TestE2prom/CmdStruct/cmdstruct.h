#ifndef CMDSTRUCT_H
#define CMDSTRUCT_H
#include "cancommuniction.h"


/*需要增加 添加枚举参数类型的重载函数的 方便直接调取使用ComBox的索引传递参数*/
namespace myCMD {

struct GetCmd_Arr 
{
    char cmdData[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    void clear()
    {
        int i= 0;
        for(i = 0 ;i<10;i++)
        {
            cmdData[i] = -1;
        }
    }
    void printfData()
    {
        int i= 0;
        for(i = 0 ;i<10;i++)
        {
            qDebug("%d ",cmdData[i]);
        }
    }
    /*转换数据为可以直接发送的数据格式*/
    QList<char > TranData()
    {
        QList<char > CmdData;
        CmdData.clear();
        int i =0;
        for(i = 0; i<10; i++)
        {
            if (cmdData[i] != -1)
            {
                CmdData.append (cmdData[i]);
            }
        }
        return CmdData;
    }

};
typedef enum LINK_INTFC_Enum0
{
    LINK_INTFC_Enum0_NONE,
    LINK_INTFC_Enum0_CAN,
    LINK_INTFC_Enum0_RS232,
}LINK_INTFC_Enum0;



struct LINK_INTFC
{
    int LINK_mainNUM = 1;
    char INTFC_subNUM = 0;
    LINK_INTFC_Enum0  ENUM0_0;

    struct LINK_INTFC* Add_ENUM0_0( LINK_INTFC_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (LINK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (INTFC_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct LINK_INTFC_QUE
{
    int LINK_mainNUM = 1;
    char INTFC_QUE_subNUM = 1;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (LINK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (INTFC_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct LINK_DEVICEINFO_QUE
{
    int LINK_mainNUM = 1;
    char DEVICEINFO_QUE_subNUM = 2;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (LINK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DEVICEINFO_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct link
{
    int  LINK_NUM = 1;
    struct LINK_INTFC  INTFC;
    struct LINK_INTFC_QUE  INTFC_QUE;
    struct LINK_DEVICEINFO_QUE  DEVICEINFO_QUE;

}link;

typedef enum SYSTEM_WORKMODE_Enum0
{
    SYSTEM_WORKMODE_Enum0_NORMAL,
    SYSTEM_WORKMODE_Enum0_NONE,
}SYSTEM_WORKMODE_Enum0;



struct SYSTEM_WORKMODE
{
    int SYSTEM_mainNUM = 2;
    char WORKMODE_subNUM = 0;
    SYSTEM_WORKMODE_Enum0  ENUM0_0;

    struct SYSTEM_WORKMODE* Add_ENUM0_0( SYSTEM_WORKMODE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (WORKMODE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct SYSTEM_WORKMODE_QUE
{
    int SYSTEM_mainNUM = 2;
    char WORKMODE_QUE_subNUM = 1;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (WORKMODE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SYSTEM_POWERON_Enum0
{
    SYSTEM_POWERON_Enum0_DEFAULT,
    SYSTEM_POWERON_Enum0_LAST,
}SYSTEM_POWERON_Enum0;



struct SYSTEM_POWERON
{
    int SYSTEM_mainNUM = 2;
    char POWERON_subNUM = 2;
    SYSTEM_POWERON_Enum0  ENUM0_0;

    struct SYSTEM_POWERON* Add_ENUM0_0( SYSTEM_POWERON_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (POWERON_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct SYSTEM_POWERON_QUE
{
    int SYSTEM_mainNUM = 2;
    char POWERON_QUE_subNUM = 3;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (POWERON_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct SYSTEM_SN_QUE
{
    int SYSTEM_mainNUM = 2;
    char SN_QUE_subNUM = 4;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SN_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct SYSTEM_TYPE_QUE
{
    int SYSTEM_mainNUM = 2;
    char TYPE_QUE_subNUM = 5;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct SYSTEM_SOFTVER_QUE
{
    int SYSTEM_mainNUM = 2;
    char SOFTVER_QUE_subNUM = 6;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SOFTVER_QUE_subNUM );
        return cmdData ;
    }

};


struct SYSTEM_FPGAVER_QUE
{
    int SYSTEM_mainNUM = 2;
    char FPGAVER_QUE_subNUM = 7;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FPGAVER_QUE_subNUM );
        return cmdData ;
    }

};


struct SYSTEM_HARDVER_QUE
{
    int SYSTEM_mainNUM = 2;
    char HARDVER_QUE_subNUM = 8;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (HARDVER_QUE_subNUM );
        return cmdData ;
    }

};


struct SYSTEM_BOOTVER_QUE
{
    int SYSTEM_mainNUM = 2;
    char BOOTVER_QUE_subNUM = 9;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BOOTVER_QUE_subNUM );
        return cmdData ;
    }

};


struct SYSTEM_EVENTCODE_QUE
{
    int SYSTEM_mainNUM = 2;
    char EVENTCODE_QUE_subNUM = 10;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (EVENTCODE_QUE_subNUM );
        return cmdData ;
    }

};


struct SYSTEM_DIOSTATE_QUE
{
    int SYSTEM_mainNUM = 2;
    char DIOSTATE_QUE_subNUM = 11;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DIOSTATE_QUE_subNUM );
        return cmdData ;
    }
    unsigned short analysis_U16_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SYSTEM_REVMOTION_Enum0
{
    SYSTEM_REVMOTION_Enum0_OFF,
    SYSTEM_REVMOTION_Enum0_ON,
}SYSTEM_REVMOTION_Enum0;



struct SYSTEM_REVMOTION
{
    int SYSTEM_mainNUM = 2;
    char REVMOTION_subNUM = 12;
    SYSTEM_REVMOTION_Enum0  ENUM0_0;

    struct SYSTEM_REVMOTION* Add_ENUM0_0( SYSTEM_REVMOTION_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (REVMOTION_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct SYSTEM_REVMOTION_QUE
{
    int SYSTEM_mainNUM = 2;
    char REVMOTION_QUE_subNUM = 13;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (REVMOTION_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct SYSTEM_FANPARA
{
    int SYSTEM_mainNUM = 2;
    char FANPARA_subNUM = 14;
    unsigned char  U8_0_0;
    unsigned int  U32_0_1;

    struct SYSTEM_FANPARA* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct SYSTEM_FANPARA* Add_U32_0_1( unsigned int param )
    {
        U32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FANPARA_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU32_0_1 = (char *) &U32_0_1 ;
        cmdData.cmdData[3] = *( ptrU32_0_1++);
        cmdData.cmdData[4] = *( ptrU32_0_1++);
        cmdData.cmdData[5] = *( ptrU32_0_1++);
        cmdData.cmdData[6] = *( ptrU32_0_1++);
        return cmdData ;
    }

};


struct SYSTEM_FANPARA_QUE
{
    int SYSTEM_mainNUM = 2;
    char FANPARA_QUE_subNUM = 15;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FANPARA_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SYSTEM_ARMLEDPARA_Enum0
{
    SYSTEM_ARMLEDPARA_Enum0_BASE,
    SYSTEM_ARMLEDPARA_Enum0_BIGARM,
    SYSTEM_ARMLEDPARA_Enum0_SMALLARM,
    SYSTEM_ARMLEDPARA_Enum0_WRIST,
}SYSTEM_ARMLEDPARA_Enum0;



struct SYSTEM_ARMLEDPARA
{
    int SYSTEM_mainNUM = 2;
    char ARMLEDPARA_subNUM = 16;
    SYSTEM_ARMLEDPARA_Enum0  ENUM0_0;
    unsigned char  U8_0_1;
    unsigned int  U32_0_2;

    struct SYSTEM_ARMLEDPARA* Add_ENUM0_0( SYSTEM_ARMLEDPARA_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SYSTEM_ARMLEDPARA* Add_U8_0_1( unsigned char param )
    {
        U8_0_1 = param ;
        return this ;
    }

    struct SYSTEM_ARMLEDPARA* Add_U32_0_2( unsigned int param )
    {
        U32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ARMLEDPARA_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU8_0_1 = (char *) &U8_0_1 ;
        cmdData.cmdData[3] = *( ptrU8_0_1++);
        char * ptrU32_0_2 = (char *) &U32_0_2 ;
        cmdData.cmdData[4] = *( ptrU32_0_2++);
        cmdData.cmdData[5] = *( ptrU32_0_2++);
        cmdData.cmdData[6] = *( ptrU32_0_2++);
        cmdData.cmdData[7] = *( ptrU32_0_2++);
        return cmdData ;
    }

};
typedef enum SYSTEM_ARMLEDPARA_QUE_Enum0
{
    SYSTEM_ARMLEDPARA_QUE_Enum0_BASE,
    SYSTEM_ARMLEDPARA_QUE_Enum0_BIGARM,
    SYSTEM_ARMLEDPARA_QUE_Enum0_SMALLARM,
    SYSTEM_ARMLEDPARA_QUE_Enum0_WRIST,
}SYSTEM_ARMLEDPARA_QUE_Enum0;



struct SYSTEM_ARMLEDPARA_QUE
{
    int SYSTEM_mainNUM = 2;
    char ARMLEDPARA_QUE_subNUM = 17;
    SYSTEM_ARMLEDPARA_QUE_Enum0  ENUM0_0;

    struct SYSTEM_ARMLEDPARA_QUE* Add_ENUM0_0( SYSTEM_ARMLEDPARA_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ARMLEDPARA_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SYSTEM_ARMLEDSTATE_Enum0
{
    SYSTEM_ARMLEDSTATE_Enum0_OFF,
    SYSTEM_ARMLEDSTATE_Enum0_ON,
}SYSTEM_ARMLEDSTATE_Enum0;



struct SYSTEM_ARMLEDSTATE
{
    int SYSTEM_mainNUM = 2;
    char ARMLEDSTATE_subNUM = 18;
    SYSTEM_ARMLEDSTATE_Enum0  ENUM0_0;
    unsigned short  U16_0_1;

    struct SYSTEM_ARMLEDSTATE* Add_ENUM0_0( SYSTEM_ARMLEDSTATE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SYSTEM_ARMLEDSTATE* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ARMLEDSTATE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        return cmdData ;
    }

};


struct SYSTEM_ARMLEDSTATE_QUE
{
    int SYSTEM_mainNUM = 2;
    char ARMLEDSTATE_QUE_subNUM = 19;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SYSTEM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ARMLEDSTATE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct system
{
    int  SYSTEM_NUM = 2;
    struct SYSTEM_WORKMODE  WORKMODE;
    struct SYSTEM_WORKMODE_QUE  WORKMODE_QUE;
    struct SYSTEM_POWERON  POWERON;
    struct SYSTEM_POWERON_QUE  POWERON_QUE;
    struct SYSTEM_SN_QUE  SN_QUE;
    struct SYSTEM_TYPE_QUE  TYPE_QUE;
    struct SYSTEM_SOFTVER_QUE  SOFTVER_QUE;
    struct SYSTEM_FPGAVER_QUE  FPGAVER_QUE;
    struct SYSTEM_HARDVER_QUE  HARDVER_QUE;
    struct SYSTEM_BOOTVER_QUE  BOOTVER_QUE;
    struct SYSTEM_EVENTCODE_QUE  EVENTCODE_QUE;
    struct SYSTEM_DIOSTATE_QUE  DIOSTATE_QUE;
    struct SYSTEM_REVMOTION  REVMOTION;
    struct SYSTEM_REVMOTION_QUE  REVMOTION_QUE;
    struct SYSTEM_FANPARA  FANPARA;
    struct SYSTEM_FANPARA_QUE  FANPARA_QUE;
    struct SYSTEM_ARMLEDPARA  ARMLEDPARA;
    struct SYSTEM_ARMLEDPARA_QUE  ARMLEDPARA_QUE;
    struct SYSTEM_ARMLEDSTATE  ARMLEDSTATE;
    struct SYSTEM_ARMLEDSTATE_QUE  ARMLEDSTATE_QUE;

}system;

typedef enum RS232_BAUD_Enum0
{
    RS232_BAUD_Enum0_4800,
    RS232_BAUD_Enum0_7200,
    RS232_BAUD_Enum0_9600,
    RS232_BAUD_Enum0_14400,
    RS232_BAUD_Enum0_19200,
    RS232_BAUD_Enum0_38400,
    RS232_BAUD_Enum0_57600,
    RS232_BAUD_Enum0_115200,
    RS232_BAUD_Enum0_128000,
}RS232_BAUD_Enum0;



struct RS232_BAUD
{
    int RS232_mainNUM = 3;
    char BAUD_subNUM = 0;
    RS232_BAUD_Enum0  ENUM0_0;

    struct RS232_BAUD* Add_ENUM0_0( RS232_BAUD_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }
    /*重载函数*/
    struct RS232_BAUD* Add_ENUM0_0( int indext )
    {
        ENUM0_0 = (RS232_BAUD_Enum0)indext ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BAUD_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct RS232_BAUD_QUE
{
    int RS232_mainNUM = 3;
    char BAUD_QUE_subNUM = 1;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BAUD_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum RS232_WORDLEN_Enum0
{
    RS232_WORDLEN_Enum0_8,
    RS232_WORDLEN_Enum0_9,
}RS232_WORDLEN_Enum0;



struct RS232_WORDLEN
{
    int RS232_mainNUM = 3;
    char WORDLEN_subNUM = 2;
    RS232_WORDLEN_Enum0  ENUM0_0;

    struct RS232_WORDLEN* Add_ENUM0_0( RS232_WORDLEN_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (WORDLEN_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct RS232_WORDLEN_QUE
{
    int RS232_mainNUM = 3;
    char WORDLEN_QUE_subNUM = 3;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (WORDLEN_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum RS232_FLOWCTL_Enum0
{
    RS232_FLOWCTL_Enum0_NONE,
    RS232_FLOWCTL_Enum0_RTS,
    RS232_FLOWCTL_Enum0_CTS,
    RS232_FLOWCTL_Enum0_RTS_CTS,
}RS232_FLOWCTL_Enum0;



struct RS232_FLOWCTL
{
    int RS232_mainNUM = 3;
    char FLOWCTL_subNUM = 4;
    RS232_FLOWCTL_Enum0  ENUM0_0;

    struct RS232_FLOWCTL* Add_ENUM0_0( RS232_FLOWCTL_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FLOWCTL_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct RS232_FLOWCTL_QUE
{
    int RS232_mainNUM = 3;
    char FLOWCTL_QUE_subNUM = 5;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FLOWCTL_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum RS232_PARITY_Enum0
{
    RS232_PARITY_Enum0_NONE,
    RS232_PARITY_Enum0_EVEN,
    RS232_PARITY_Enum0_ODD,
}RS232_PARITY_Enum0;



struct RS232_PARITY
{
    int RS232_mainNUM = 3;
    char PARITY_subNUM = 6;
    RS232_PARITY_Enum0  ENUM0_0;

    struct RS232_PARITY* Add_ENUM0_0( RS232_PARITY_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PARITY_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct RS232_PARITY_QUE
{
    int RS232_mainNUM = 3;
    char PARITY_QUE_subNUM = 7;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PARITY_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum RS232_STOPBIT_Enum0
{
    RS232_STOPBIT_Enum0_1,
    RS232_STOPBIT_Enum0_0d5,
    RS232_STOPBIT_Enum0_2,
    RS232_STOPBIT_Enum0_1d5,
}RS232_STOPBIT_Enum0;



struct RS232_STOPBIT
{
    int RS232_mainNUM = 3;
    char STOPBIT_subNUM = 8;
    RS232_STOPBIT_Enum0  ENUM0_0;

    struct RS232_STOPBIT* Add_ENUM0_0( RS232_STOPBIT_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPBIT_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct RS232_STOPBIT_QUE
{
    int RS232_mainNUM = 3;
    char STOPBIT_QUE_subNUM = 9;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPBIT_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct RS232_APPLYPARA
{
    int RS232_mainNUM = 3;
    char APPLYPARA_subNUM = 10;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (RS232_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (APPLYPARA_subNUM );
        return cmdData ;
    }

};

/*****************************************************/
typedef struct rs232
{
    int  RS232_NUM = 3;
    struct RS232_BAUD  BAUD;
    struct RS232_BAUD_QUE  BAUD_QUE;
    struct RS232_WORDLEN  WORDLEN;
    struct RS232_WORDLEN_QUE  WORDLEN_QUE;
    struct RS232_FLOWCTL  FLOWCTL;
    struct RS232_FLOWCTL_QUE  FLOWCTL_QUE;
    struct RS232_PARITY  PARITY;
    struct RS232_PARITY_QUE  PARITY_QUE;
    struct RS232_STOPBIT  STOPBIT;
    struct RS232_STOPBIT_QUE  STOPBIT_QUE;
    struct RS232_APPLYPARA  APPLYPARA;

}rs232;

typedef enum CAN_TYPE_Enum0
{
    CAN_TYPE_Enum0_A,
    CAN_TYPE_Enum0_B,
}CAN_TYPE_Enum0;



struct CAN_TYPE
{
    int CAN_mainNUM = 4;
    char TYPE_subNUM = 0;
    CAN_TYPE_Enum0  ENUM0_0;

    struct CAN_TYPE* Add_ENUM0_0( CAN_TYPE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct CAN_TYPE_QUE
{
    int CAN_mainNUM = 4;
    char TYPE_QUE_subNUM = 1;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum CAN_BAUD_Enum0
{
    CAN_BAUD_Enum0_1000,
    CAN_BAUD_Enum0_500,
    CAN_BAUD_Enum0_250,
    CAN_BAUD_Enum0_125,
    CAN_BAUD_Enum0_100,
    CAN_BAUD_Enum0_50,
    CAN_BAUD_Enum0_20,
    CAN_BAUD_Enum0_10,
}CAN_BAUD_Enum0;



struct CAN_BAUD
{
    int CAN_mainNUM = 4;
    char BAUD_subNUM = 2;
    CAN_BAUD_Enum0  ENUM0_0;

    struct CAN_BAUD* Add_ENUM0_0( CAN_BAUD_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BAUD_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct CAN_BAUD_QUE
{
    int CAN_mainNUM = 4;
    char BAUD_QUE_subNUM = 3;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BAUD_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_GROUP
{
    int CAN_mainNUM = 4;
    char GROUP_subNUM = 4;
    unsigned char  U8_0_0;

    struct CAN_GROUP* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GROUP_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }

};


struct CAN_GROUP_QUE
{
    int CAN_mainNUM = 4;
    char GROUP_QUE_subNUM = 5;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GROUP_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_SENDID
{
    int CAN_mainNUM = 4;
    char SENDID_subNUM = 6;
    unsigned int  U32_0_0;

    struct CAN_SENDID* Add_U32_0_0( unsigned int param )
    {
        U32_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SENDID_subNUM );
        char * ptrU32_0_0 = (char *) &U32_0_0 ;
        cmdData.cmdData[2] = *( ptrU32_0_0++);
        cmdData.cmdData[3] = *( ptrU32_0_0++);
        cmdData.cmdData[4] = *( ptrU32_0_0++);
        cmdData.cmdData[5] = *( ptrU32_0_0++);
        return cmdData ;
    }

};


struct CAN_SENDID_QUE
{
    int CAN_mainNUM = 4;
    char SENDID_QUE_subNUM = 7;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SENDID_QUE_subNUM );
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_RECEIVEID
{
    int CAN_mainNUM = 4;
    char RECEIVEID_subNUM = 8;
    unsigned int  U32_0_0;

    struct CAN_RECEIVEID* Add_U32_0_0( unsigned int param )
    {
        U32_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RECEIVEID_subNUM );
        char * ptrU32_0_0 = (char *) &U32_0_0 ;
        cmdData.cmdData[2] = *( ptrU32_0_0++);
        cmdData.cmdData[3] = *( ptrU32_0_0++);
        cmdData.cmdData[4] = *( ptrU32_0_0++);
        cmdData.cmdData[5] = *( ptrU32_0_0++);
        return cmdData ;
    }

};


struct CAN_RECEIVEID_QUE
{
    int CAN_mainNUM = 4;
    char RECEIVEID_QUE_subNUM = 9;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RECEIVEID_QUE_subNUM );
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_GROUPID1
{
    int CAN_mainNUM = 4;
    char GROUPID1_subNUM = 10;
    unsigned int  U32_0_0;

    struct CAN_GROUPID1* Add_U32_0_0( unsigned int param )
    {
        U32_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GROUPID1_subNUM );
        char * ptrU32_0_0 = (char *) &U32_0_0 ;
        cmdData.cmdData[2] = *( ptrU32_0_0++);
        cmdData.cmdData[3] = *( ptrU32_0_0++);
        cmdData.cmdData[4] = *( ptrU32_0_0++);
        cmdData.cmdData[5] = *( ptrU32_0_0++);
        return cmdData ;
    }

};


struct CAN_GROUPID1_QUE
{
    int CAN_mainNUM = 4;
    char GROUPID1_QUE_subNUM = 11;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GROUPID1_QUE_subNUM );
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_GROUPID2
{
    int CAN_mainNUM = 4;
    char GROUPID2_subNUM = 12;
    unsigned int  U32_0_0;

    struct CAN_GROUPID2* Add_U32_0_0( unsigned int param )
    {
        U32_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GROUPID2_subNUM );
        char * ptrU32_0_0 = (char *) &U32_0_0 ;
        cmdData.cmdData[2] = *( ptrU32_0_0++);
        cmdData.cmdData[3] = *( ptrU32_0_0++);
        cmdData.cmdData[4] = *( ptrU32_0_0++);
        cmdData.cmdData[5] = *( ptrU32_0_0++);
        return cmdData ;
    }

};


struct CAN_GROUPID2_QUE
{
    int CAN_mainNUM = 4;
    char GROUPID2_QUE_subNUM = 13;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GROUPID2_QUE_subNUM );
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_BROADCASTID
{
    int CAN_mainNUM = 4;
    char BROADCASTID_subNUM = 14;
    unsigned int  U32_0_0;

    struct CAN_BROADCASTID* Add_U32_0_0( unsigned int param )
    {
        U32_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BROADCASTID_subNUM );
        char * ptrU32_0_0 = (char *) &U32_0_0 ;
        cmdData.cmdData[2] = *( ptrU32_0_0++);
        cmdData.cmdData[3] = *( ptrU32_0_0++);
        cmdData.cmdData[4] = *( ptrU32_0_0++);
        cmdData.cmdData[5] = *( ptrU32_0_0++);
        return cmdData ;
    }

};


struct CAN_BROADCASTID_QUE
{
    int CAN_mainNUM = 4;
    char BROADCASTID_QUE_subNUM = 15;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BROADCASTID_QUE_subNUM );
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_APPLYPARA
{
    int CAN_mainNUM = 4;
    char APPLYPARA_subNUM = 16;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (APPLYPARA_subNUM );
        return cmdData ;
    }

};
typedef enum CAN_NETMANAGELED_Enum0
{
    CAN_NETMANAGELED_Enum0_OFF,
    CAN_NETMANAGELED_Enum0_ON,
}CAN_NETMANAGELED_Enum0;



struct CAN_NETMANAGELED
{
    int CAN_mainNUM = 4;
    char NETMANAGELED_subNUM = 17;
    CAN_NETMANAGELED_Enum0  ENUM0_0;

    struct CAN_NETMANAGELED* Add_ENUM0_0( CAN_NETMANAGELED_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGELED_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};
typedef enum CAN_NETMANAGESTATE_Enum0
{
    CAN_NETMANAGESTATE_Enum0_IDLE,
    CAN_NETMANAGESTATE_Enum0_HASH,
    CAN_NETMANAGESTATE_Enum0_SIGNATURE,
}CAN_NETMANAGESTATE_Enum0;



struct CAN_NETMANAGESTATE
{
    int CAN_mainNUM = 4;
    char NETMANAGESTATE_subNUM = 18;
    CAN_NETMANAGESTATE_Enum0  ENUM0_0;

    struct CAN_NETMANAGESTATE* Add_ENUM0_0( CAN_NETMANAGESTATE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGESTATE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct CAN_NETMANAGESTATE_QUE
{
    int CAN_mainNUM = 4;
    char NETMANAGESTATE_QUE_subNUM = 19;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGESTATE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum CAN_NETMANAGEID_Enum0
{
    CAN_NETMANAGEID_Enum0_NONE,
    CAN_NETMANAGEID_Enum0_SENDID,
    CAN_NETMANAGEID_Enum0_RECEIVEID,
}CAN_NETMANAGEID_Enum0;



struct CAN_NETMANAGEID
{
    int CAN_mainNUM = 4;
    char NETMANAGEID_subNUM = 20;
    CAN_NETMANAGEID_Enum0  ENUM0_0;
    unsigned int  U32_0_1;

    struct CAN_NETMANAGEID* Add_ENUM0_0( CAN_NETMANAGEID_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct CAN_NETMANAGEID* Add_U32_0_1( unsigned int param )
    {
        U32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGEID_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU32_0_1 = (char *) &U32_0_1 ;
        cmdData.cmdData[3] = *( ptrU32_0_1++);
        cmdData.cmdData[4] = *( ptrU32_0_1++);
        cmdData.cmdData[5] = *( ptrU32_0_1++);
        cmdData.cmdData[6] = *( ptrU32_0_1++);
        return cmdData ;
    }

};
typedef enum CAN_NETMANAGEID_QUE_Enum0
{
    CAN_NETMANAGEID_QUE_Enum0_,
}CAN_NETMANAGEID_QUE_Enum0;



struct CAN_NETMANAGEID_QUE
{
    int CAN_mainNUM = 4;
    char NETMANAGEID_QUE_subNUM = 21;
    CAN_NETMANAGEID_QUE_Enum0  ENUM0_0;

    struct CAN_NETMANAGEID_QUE* Add_ENUM0_0( CAN_NETMANAGEID_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGEID_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_NETMANAGEHASH
{
    int CAN_mainNUM = 4;
    char NETMANAGEHASH_subNUM = 22;
    unsigned int  U32_0_0;

    struct CAN_NETMANAGEHASH* Add_U32_0_0( unsigned int param )
    {
        U32_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGEHASH_subNUM );
        char * ptrU32_0_0 = (char *) &U32_0_0 ;
        cmdData.cmdData[2] = *( ptrU32_0_0++);
        cmdData.cmdData[3] = *( ptrU32_0_0++);
        cmdData.cmdData[4] = *( ptrU32_0_0++);
        cmdData.cmdData[5] = *( ptrU32_0_0++);
        return cmdData ;
    }

};


struct CAN_NETMANAGEHASH_QUE
{
    int CAN_mainNUM = 4;
    char NETMANAGEHASH_QUE_subNUM = 23;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGEHASH_QUE_subNUM );
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_NETMANAGESIGNATURE
{
    int CAN_mainNUM = 4;
    char NETMANAGESIGNATURE_subNUM = 24;
    unsigned char  U8_0_0;
    unsigned short  CHAR5_0_1;

    struct CAN_NETMANAGESIGNATURE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct CAN_NETMANAGESIGNATURE* Add_CHAR5_0_1( char param )
    {
        CHAR5_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGESIGNATURE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrCHAR5_0_1 = (char *) &CHAR5_0_1 ;
        cmdData.cmdData[3] = *( ptrCHAR5_0_1++);
        return cmdData ;
    }

};


struct CAN_NETMANAGESIGNATURE_QUE
{
    int CAN_mainNUM = 4;
    char NETMANAGESIGNATURE_QUE_subNUM = 25;
    unsigned char  U8_0_0;

    struct CAN_NETMANAGESIGNATURE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGESIGNATURE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CAN_NETMANAGESIGNATURESIZE_QUE
{
    int CAN_mainNUM = 4;
    char NETMANAGESIGNATURESIZE_QUE_subNUM = 26;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (NETMANAGESIGNATURESIZE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct can
{
    int  CAN_NUM = 4;
    struct CAN_TYPE  TYPE;
    struct CAN_TYPE_QUE  TYPE_QUE;
    struct CAN_BAUD  BAUD;
    struct CAN_BAUD_QUE  BAUD_QUE;
    struct CAN_GROUP  GROUP;
    struct CAN_GROUP_QUE  GROUP_QUE;
    struct CAN_SENDID  SENDID;
    struct CAN_SENDID_QUE  SENDID_QUE;
    struct CAN_RECEIVEID  RECEIVEID;
    struct CAN_RECEIVEID_QUE  RECEIVEID_QUE;
    struct CAN_GROUPID1  GROUPID1;
    struct CAN_GROUPID1_QUE  GROUPID1_QUE;
    struct CAN_GROUPID2  GROUPID2;
    struct CAN_GROUPID2_QUE  GROUPID2_QUE;
    struct CAN_BROADCASTID  BROADCASTID;
    struct CAN_BROADCASTID_QUE  BROADCASTID_QUE;
    struct CAN_APPLYPARA  APPLYPARA;
    struct CAN_NETMANAGELED  NETMANAGELED;
    struct CAN_NETMANAGESTATE  NETMANAGESTATE;
    struct CAN_NETMANAGESTATE_QUE  NETMANAGESTATE_QUE;
    struct CAN_NETMANAGEID  NETMANAGEID;
    struct CAN_NETMANAGEID_QUE  NETMANAGEID_QUE;
    struct CAN_NETMANAGEHASH  NETMANAGEHASH;
    struct CAN_NETMANAGEHASH_QUE  NETMANAGEHASH_QUE;
    struct CAN_NETMANAGESIGNATURE  NETMANAGESIGNATURE;
    struct CAN_NETMANAGESIGNATURE_QUE  NETMANAGESIGNATURE_QUE;
    struct CAN_NETMANAGESIGNATURESIZE_QUE  NETMANAGESIGNATURESIZE_QUE;

}can;



struct CLOCK_FREQUENCY
{
    int CLOCK_mainNUM = 5;
    char FREQUENCY_subNUM = 0;
    unsigned int  U32_0_0;

    struct CLOCK_FREQUENCY* Add_U32_0_0( unsigned int param )
    {
        U32_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CLOCK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FREQUENCY_subNUM );
        char * ptrU32_0_0 = (char *) &U32_0_0 ;
        cmdData.cmdData[2] = *( ptrU32_0_0++);
        cmdData.cmdData[3] = *( ptrU32_0_0++);
        cmdData.cmdData[4] = *( ptrU32_0_0++);
        cmdData.cmdData[5] = *( ptrU32_0_0++);
        return cmdData ;
    }

};


struct CLOCK_FREQUENCY_QUE
{
    int CLOCK_mainNUM = 5;
    char FREQUENCY_QUE_subNUM = 1;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CLOCK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FREQUENCY_QUE_subNUM );
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum CLOCK_SYNCREGISTER_Enum0
{
    CLOCK_SYNCREGISTER_Enum0_OFF,
    CLOCK_SYNCREGISTER_Enum0_ON,
}CLOCK_SYNCREGISTER_Enum0;



struct CLOCK_SYNCREGISTER
{
    int CLOCK_mainNUM = 5;
    char SYNCREGISTER_subNUM = 2;
    CLOCK_SYNCREGISTER_Enum0  ENUM0_0;

    struct CLOCK_SYNCREGISTER* Add_ENUM0_0( CLOCK_SYNCREGISTER_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CLOCK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SYNCREGISTER_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct CLOCK_SYNCREGISTER_QUE
{
    int CLOCK_mainNUM = 5;
    char SYNCREGISTER_QUE_subNUM = 3;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CLOCK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SYNCREGISTER_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum CLOCK_STARTTYPE_Enum0
{
    CLOCK_STARTTYPE_Enum0_RADIOID,
    CLOCK_STARTTYPE_Enum0_RECEIVEID,
    CLOCK_STARTTYPE_Enum0_GROUPID1,
    CLOCK_STARTTYPE_Enum0_GROUPID2,
}CLOCK_STARTTYPE_Enum0;



struct CLOCK_STARTTYPE
{
    int CLOCK_mainNUM = 5;
    char STARTTYPE_subNUM = 4;
    CLOCK_STARTTYPE_Enum0  ENUM0_0;

    struct CLOCK_STARTTYPE* Add_ENUM0_0( CLOCK_STARTTYPE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CLOCK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STARTTYPE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct CLOCK_STARTTYPE_QUE
{
    int CLOCK_mainNUM = 5;
    char STARTTYPE_QUE_subNUM = 5;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CLOCK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STARTTYPE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum CLOCK_SYNCSTATE_Enum0
{
    CLOCK_SYNCSTATE_Enum0_END,
    CLOCK_SYNCSTATE_Enum0_START,
}CLOCK_SYNCSTATE_Enum0;



struct CLOCK_SYNCSTATE
{
    int CLOCK_mainNUM = 5;
    char SYNCSTATE_subNUM = 6;
    CLOCK_SYNCSTATE_Enum0  ENUM0_0;

    struct CLOCK_SYNCSTATE* Add_ENUM0_0( CLOCK_SYNCSTATE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CLOCK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SYNCSTATE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct CLOCK_SYNCSTATE_QUE
{
    int CLOCK_mainNUM = 5;
    char SYNCSTATE_QUE_subNUM = 7;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CLOCK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SYNCSTATE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct CLOCK_COUNT_QUE
{
    int CLOCK_mainNUM = 5;
    char COUNT_QUE_subNUM = 8;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (CLOCK_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (COUNT_QUE_subNUM );
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct clock
{
    int  CLOCK_NUM = 5;
    struct CLOCK_FREQUENCY  FREQUENCY;
    struct CLOCK_FREQUENCY_QUE  FREQUENCY_QUE;
    struct CLOCK_SYNCREGISTER  SYNCREGISTER;
    struct CLOCK_SYNCREGISTER_QUE  SYNCREGISTER_QUE;
    struct CLOCK_STARTTYPE  STARTTYPE;
    struct CLOCK_STARTTYPE_QUE  STARTTYPE_QUE;
    struct CLOCK_SYNCSTATE  SYNCSTATE;
    struct CLOCK_SYNCSTATE_QUE  SYNCSTATE_QUE;
    struct CLOCK_COUNT_QUE  COUNT_QUE;

}clock;

typedef enum MOTION_SWITCH_Enum0
{
    MOTION_SWITCH_Enum0_RESET,
    MOTION_SWITCH_Enum0_STOP,
    MOTION_SWITCH_Enum0_RUN,
    MOTION_SWITCH_Enum0_PREPARE,
    MOTION_SWITCH_Enum0_EMERGSTOP,
}MOTION_SWITCH_Enum0;

typedef enum MOTION_SWITCH_Enum1
{
    MOTION_SWITCH_Enum1_MAIN,
    MOTION_SWITCH_Enum1_SMALL,
    MOTION_SWITCH_Enum1_P1,
    MOTION_SWITCH_Enum1_P2,
    MOTION_SWITCH_Enum1_P3,
    MOTION_SWITCH_Enum1_P4,
    MOTION_SWITCH_Enum1_P5,
    MOTION_SWITCH_Enum1_P6,
    MOTION_SWITCH_Enum1_P7,
    MOTION_SWITCH_Enum1_P8,
}MOTION_SWITCH_Enum1;



struct MOTION_SWITCH
{
    int MOTION_mainNUM = 21;
    char SWITCH_subNUM = 0;
    unsigned char  U8_0_0;
    MOTION_SWITCH_Enum0  ENUM0_1;
    MOTION_SWITCH_Enum1  ENUM1_2;

    struct MOTION_SWITCH* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_SWITCH* Add_ENUM0_1( MOTION_SWITCH_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTION_SWITCH* Add_ENUM1_2( MOTION_SWITCH_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SWITCH_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTION_STATE_QUE_Enum0
{
    MOTION_STATE_QUE_Enum0_MAIN,
    MOTION_STATE_QUE_Enum0_SMALL,
    MOTION_STATE_QUE_Enum0_P1,
    MOTION_STATE_QUE_Enum0_P2,
    MOTION_STATE_QUE_Enum0_P3,
    MOTION_STATE_QUE_Enum0_P4,
    MOTION_STATE_QUE_Enum0_P5,
    MOTION_STATE_QUE_Enum0_P6,
    MOTION_STATE_QUE_Enum0_P7,
    MOTION_STATE_QUE_Enum0_P8,
}MOTION_STATE_QUE_Enum0;



struct MOTION_STATE_QUE
{
    int MOTION_mainNUM = 21;
    char STATE_QUE_subNUM = 1;
    unsigned char  U8_0_0;
    MOTION_STATE_QUE_Enum0  ENUM0_1;

    struct MOTION_STATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_STATE_QUE* Add_ENUM0_1( MOTION_STATE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTION_STATEREPORT_Enum0
{
    MOTION_STATEREPORT_Enum0_ACTIVE,
    MOTION_STATEREPORT_Enum0_QUERY,
}MOTION_STATEREPORT_Enum0;



struct MOTION_STATEREPORT
{
    int MOTION_mainNUM = 21;
    char STATEREPORT_subNUM = 2;
    unsigned char  U8_0_0;
    MOTION_STATEREPORT_Enum0  ENUM0_1;

    struct MOTION_STATEREPORT* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_STATEREPORT* Add_ENUM0_1( MOTION_STATEREPORT_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATEREPORT_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct MOTION_STATEREPORT_QUE
{
    int MOTION_mainNUM = 21;
    char STATEREPORT_QUE_subNUM = 3;
    unsigned char  U8_0_0;

    struct MOTION_STATEREPORT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATEREPORT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTION_STARTSOURCE_Enum0
{
    MOTION_STARTSOURCE_Enum0_SOFTWARE,
    MOTION_STARTSOURCE_Enum0_DIGITALIO,
    MOTION_STARTSOURCE_Enum0_CAN,
    MOTION_STARTSOURCE_Enum0_ALL,
}MOTION_STARTSOURCE_Enum0;



struct MOTION_STARTSOURCE
{
    int MOTION_mainNUM = 21;
    char STARTSOURCE_subNUM = 4;
    unsigned char  U8_0_0;
    MOTION_STARTSOURCE_Enum0  ENUM0_1;

    struct MOTION_STARTSOURCE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_STARTSOURCE* Add_ENUM0_1( MOTION_STARTSOURCE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STARTSOURCE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct MOTION_STARTSOURCE_QUE
{
    int MOTION_mainNUM = 21;
    char STARTSOURCE_QUE_subNUM = 5;
    unsigned char  U8_0_0;

    struct MOTION_STARTSOURCE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STARTSOURCE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTION_STARTTYPE_Enum0
{
    MOTION_STARTTYPE_Enum0_RADIOID,
    MOTION_STARTTYPE_Enum0_RECEIVEID,
    MOTION_STARTTYPE_Enum0_GROUPID1,
    MOTION_STARTTYPE_Enum0_GROUPID2,
}MOTION_STARTTYPE_Enum0;



struct MOTION_STARTTYPE
{
    int MOTION_mainNUM = 21;
    char STARTTYPE_subNUM = 6;
    unsigned char  U8_0_0;
    MOTION_STARTTYPE_Enum0  ENUM0_1;

    struct MOTION_STARTTYPE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_STARTTYPE* Add_ENUM0_1( MOTION_STARTTYPE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STARTTYPE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct MOTION_STARTTYPE_QUE
{
    int MOTION_mainNUM = 21;
    char STARTTYPE_QUE_subNUM = 7;
    unsigned char  U8_0_0;

    struct MOTION_STARTTYPE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STARTTYPE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_MAXSPEED
{
    int MOTION_mainNUM = 21;
    char MAXSPEED_subNUM = 8;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTION_MAXSPEED* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_MAXSPEED* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MAXSPEED_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTION_MAXSPEED_QUE
{
    int MOTION_mainNUM = 21;
    char MAXSPEED_QUE_subNUM = 9;
    unsigned char  U8_0_0;

    struct MOTION_MAXSPEED_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MAXSPEED_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_MINSPEED
{
    int MOTION_mainNUM = 21;
    char MINSPEED_subNUM = 10;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTION_MINSPEED* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_MINSPEED* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINSPEED_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTION_MINSPEED_QUE
{
    int MOTION_mainNUM = 21;
    char MINSPEED_QUE_subNUM = 11;
    unsigned char  U8_0_0;

    struct MOTION_MINSPEED_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINSPEED_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_MAXPOSITION
{
    int MOTION_mainNUM = 21;
    char MAXPOSITION_subNUM = 12;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTION_MAXPOSITION* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_MAXPOSITION* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MAXPOSITION_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTION_MAXPOSITION_QUE
{
    int MOTION_mainNUM = 21;
    char MAXPOSITION_QUE_subNUM = 13;
    unsigned char  U8_0_0;

    struct MOTION_MAXPOSITION_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MAXPOSITION_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_MINPOSITION
{
    int MOTION_mainNUM = 21;
    char MINPOSITION_subNUM = 14;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTION_MINPOSITION* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_MINPOSITION* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINPOSITION_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTION_MINPOSITION_QUE
{
    int MOTION_mainNUM = 21;
    char MINPOSITION_QUE_subNUM = 15;
    unsigned char  U8_0_0;

    struct MOTION_MINPOSITION_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINPOSITION_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_MAXTORQUE
{
    int MOTION_mainNUM = 21;
    char MAXTORQUE_subNUM = 16;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTION_MAXTORQUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_MAXTORQUE* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MAXTORQUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTION_MAXTORQUE_QUE
{
    int MOTION_mainNUM = 21;
    char MAXTORQUE_QUE_subNUM = 17;
    unsigned char  U8_0_0;

    struct MOTION_MAXTORQUE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MAXTORQUE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_MINTORQUE
{
    int MOTION_mainNUM = 21;
    char MINTORQUE_subNUM = 18;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTION_MINTORQUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_MINTORQUE* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINTORQUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTION_MINTORQUE_QUE
{
    int MOTION_mainNUM = 21;
    char MINTORQUE_QUE_subNUM = 19;
    unsigned char  U8_0_0;

    struct MOTION_MINTORQUE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINTORQUE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_MAXACCELERATION
{
    int MOTION_mainNUM = 21;
    char MAXACCELERATION_subNUM = 20;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTION_MAXACCELERATION* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_MAXACCELERATION* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MAXACCELERATION_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTION_MAXACCELERATION_QUE
{
    int MOTION_mainNUM = 21;
    char MAXACCELERATION_QUE_subNUM = 21;
    unsigned char  U8_0_0;

    struct MOTION_MAXACCELERATION_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MAXACCELERATION_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_MINACCELERATION
{
    int MOTION_mainNUM = 21;
    char MINACCELERATION_subNUM = 22;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTION_MINACCELERATION* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_MINACCELERATION* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINACCELERATION_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTION_MINACCELERATION_QUE
{
    int MOTION_mainNUM = 21;
    char MINACCELERATION_QUE_subNUM = 23;
    unsigned char  U8_0_0;

    struct MOTION_MINACCELERATION_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINACCELERATION_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_ORIGIN
{
    int MOTION_mainNUM = 21;
    char ORIGIN_subNUM = 24;
    unsigned char  U8_0_0;

    struct MOTION_ORIGIN* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ORIGIN_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }

};


struct MOTION_ORIGIN_QUE
{
    int MOTION_mainNUM = 21;
    char ORIGIN_QUE_subNUM = 25;
    unsigned char  U8_0_0;

    struct MOTION_ORIGIN_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ORIGIN_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_GOORIGIN
{
    int MOTION_mainNUM = 21;
    char GOORIGIN_subNUM = 26;
    unsigned char  U8_0_0;

    struct MOTION_GOORIGIN* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GOORIGIN_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }

};
typedef enum MOTION_OFFSETSTATE_Enum0
{
    MOTION_OFFSETSTATE_Enum0_OFF,
    MOTION_OFFSETSTATE_Enum0_ON,
}MOTION_OFFSETSTATE_Enum0;



struct MOTION_OFFSETSTATE
{
    int MOTION_mainNUM = 21;
    char OFFSETSTATE_subNUM = 27;
    unsigned char  U8_0_0;
    MOTION_OFFSETSTATE_Enum0  ENUM0_1;

    struct MOTION_OFFSETSTATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTION_OFFSETSTATE* Add_ENUM0_1( MOTION_OFFSETSTATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OFFSETSTATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct MOTION_OFFSETSTATE_QUE
{
    int MOTION_mainNUM = 21;
    char OFFSETSTATE_QUE_subNUM = 28;
    unsigned char  U8_0_0;

    struct MOTION_OFFSETSTATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OFFSETSTATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_OFFSET
{
    int MOTION_mainNUM = 21;
    char OFFSET_subNUM = 29;
    unsigned char  U8_0_0;

    struct MOTION_OFFSET* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OFFSET_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }

};


struct MOTION_COUNTCIRCLE_QUE
{
    int MOTION_mainNUM = 21;
    char COUNTCIRCLE_QUE_subNUM = 30;
    unsigned char  U8_0_0;

    struct MOTION_COUNTCIRCLE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (COUNTCIRCLE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    short analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            short * shortValue = (short *)tmp; 
            return * shortValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_ABCOUNT_QUE
{
    int MOTION_mainNUM = 21;
    char ABCOUNT_QUE_subNUM = 31;
    unsigned char  U8_0_0;

    struct MOTION_ABCOUNT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ABCOUNT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            int * intValue = (int *)tmp ;
            return * intValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_ABCOUNTCLEAR
{
    int MOTION_mainNUM = 21;
    char ABCOUNTCLEAR_subNUM = 32;
    unsigned char  U8_0_0;

    struct MOTION_ABCOUNTCLEAR* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ABCOUNTCLEAR_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }

};


struct MOTION_RUNTIMEL_QUE
{
    int MOTION_mainNUM = 21;
    char RUNTIMEL_QUE_subNUM = 33;
    unsigned char  U8_0_0;

    struct MOTION_RUNTIMEL_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RUNTIMEL_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTION_RUNTIMEH_QUE
{
    int MOTION_mainNUM = 21;
    char RUNTIMEH_QUE_subNUM = 34;
    unsigned char  U8_0_0;

    struct MOTION_RUNTIMEH_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RUNTIMEH_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct motion
{
    int  MOTION_NUM = 21;
    struct MOTION_SWITCH  SWITCH;
    struct MOTION_STATE_QUE  STATE_QUE;
    struct MOTION_STATEREPORT  STATEREPORT;
    struct MOTION_STATEREPORT_QUE  STATEREPORT_QUE;
    struct MOTION_STARTSOURCE  STARTSOURCE;
    struct MOTION_STARTSOURCE_QUE  STARTSOURCE_QUE;
    struct MOTION_STARTTYPE  STARTTYPE;
    struct MOTION_STARTTYPE_QUE  STARTTYPE_QUE;
    struct MOTION_MAXSPEED  MAXSPEED;
    struct MOTION_MAXSPEED_QUE  MAXSPEED_QUE;
    struct MOTION_MINSPEED  MINSPEED;
    struct MOTION_MINSPEED_QUE  MINSPEED_QUE;
    struct MOTION_MAXPOSITION  MAXPOSITION;
    struct MOTION_MAXPOSITION_QUE  MAXPOSITION_QUE;
    struct MOTION_MINPOSITION  MINPOSITION;
    struct MOTION_MINPOSITION_QUE  MINPOSITION_QUE;
    struct MOTION_MAXTORQUE  MAXTORQUE;
    struct MOTION_MAXTORQUE_QUE  MAXTORQUE_QUE;
    struct MOTION_MINTORQUE  MINTORQUE;
    struct MOTION_MINTORQUE_QUE  MINTORQUE_QUE;
    struct MOTION_MAXACCELERATION  MAXACCELERATION;
    struct MOTION_MAXACCELERATION_QUE  MAXACCELERATION_QUE;
    struct MOTION_MINACCELERATION  MINACCELERATION;
    struct MOTION_MINACCELERATION_QUE  MINACCELERATION_QUE;
    struct MOTION_ORIGIN  ORIGIN;
    struct MOTION_ORIGIN_QUE  ORIGIN_QUE;
    struct MOTION_GOORIGIN  GOORIGIN;
    struct MOTION_OFFSETSTATE  OFFSETSTATE;
    struct MOTION_OFFSETSTATE_QUE  OFFSETSTATE_QUE;
    struct MOTION_OFFSET  OFFSET;
    struct MOTION_COUNTCIRCLE_QUE  COUNTCIRCLE_QUE;
    struct MOTION_ABCOUNT_QUE  ABCOUNT_QUE;
    struct MOTION_ABCOUNTCLEAR  ABCOUNTCLEAR;
    struct MOTION_RUNTIMEL_QUE  RUNTIMEL_QUE;
    struct MOTION_RUNTIMEH_QUE  RUNTIMEH_QUE;

}motion;

typedef enum IDENTITY_GROUP_Enum0
{
    IDENTITY_GROUP_Enum0_GROUP1,
    IDENTITY_GROUP_Enum0_GROUP2,
}IDENTITY_GROUP_Enum0;



struct IDENTITY_GROUP
{
    int IDENTITY_mainNUM = 22;
    char GROUP_subNUM = 0;
    unsigned char  U8_0_0;
    IDENTITY_GROUP_Enum0  ENUM0_1;
    unsigned char  U8_1_2;

    struct IDENTITY_GROUP* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct IDENTITY_GROUP* Add_ENUM0_1( IDENTITY_GROUP_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct IDENTITY_GROUP* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (IDENTITY_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GROUP_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        return cmdData ;
    }

};
typedef enum IDENTITY_GROUP_QUE_Enum0
{
    IDENTITY_GROUP_QUE_Enum0_GROUP1,
    IDENTITY_GROUP_QUE_Enum0_GROUP2,
}IDENTITY_GROUP_QUE_Enum0;



struct IDENTITY_GROUP_QUE
{
    int IDENTITY_mainNUM = 22;
    char GROUP_QUE_subNUM = 1;
    unsigned char  U8_0_0;
    IDENTITY_GROUP_QUE_Enum0  ENUM0_1;

    struct IDENTITY_GROUP_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct IDENTITY_GROUP_QUE* Add_ENUM0_1( IDENTITY_GROUP_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (IDENTITY_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GROUP_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_1_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum IDENTITY_DISTDEVICE_Enum0
{
    IDENTITY_DISTDEVICE_Enum0_OFF,
    IDENTITY_DISTDEVICE_Enum0_ON,
}IDENTITY_DISTDEVICE_Enum0;



struct IDENTITY_DISTDEVICE
{
    int IDENTITY_mainNUM = 22;
    char DISTDEVICE_subNUM = 2;
    IDENTITY_DISTDEVICE_Enum0  ENUM0_0;

    struct IDENTITY_DISTDEVICE* Add_ENUM0_0( IDENTITY_DISTDEVICE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (IDENTITY_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DISTDEVICE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct IDENTITY_DISTDEVICE_QUE
{
    int IDENTITY_mainNUM = 22;
    char DISTDEVICE_QUE_subNUM = 3;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (IDENTITY_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DISTDEVICE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum IDENTITY_LABEL_Enum0
{
    IDENTITY_LABEL_Enum0_SINANJU,
    IDENTITY_LABEL_Enum0_MEGATRON,
    IDENTITY_LABEL_Enum0_GOUF,
}IDENTITY_LABEL_Enum0;

typedef enum IDENTITY_LABEL_Enum1
{
    IDENTITY_LABEL_Enum1_S1,
    IDENTITY_LABEL_Enum1_S2,
    IDENTITY_LABEL_Enum1_S3,
    IDENTITY_LABEL_Enum1_S4,
}IDENTITY_LABEL_Enum1;



struct IDENTITY_LABEL
{
    int IDENTITY_mainNUM = 22;
    char LABEL_subNUM = 4;
    unsigned char  U8_0_0;
    IDENTITY_LABEL_Enum0  ENUM0_1;
    IDENTITY_LABEL_Enum1  ENUM1_2;

    struct IDENTITY_LABEL* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct IDENTITY_LABEL* Add_ENUM0_1( IDENTITY_LABEL_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct IDENTITY_LABEL* Add_ENUM1_2( IDENTITY_LABEL_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (IDENTITY_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LABEL_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};


struct IDENTITY_LABEL_QUE
{
    int IDENTITY_mainNUM = 22;
    char LABEL_QUE_subNUM = 5;
    unsigned char  U8_0_0;

    struct IDENTITY_LABEL_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (IDENTITY_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LABEL_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct identity
{
    int  IDENTITY_NUM = 22;
    struct IDENTITY_GROUP  GROUP;
    struct IDENTITY_GROUP_QUE  GROUP_QUE;
    struct IDENTITY_DISTDEVICE  DISTDEVICE;
    struct IDENTITY_DISTDEVICE_QUE  DISTDEVICE_QUE;
    struct IDENTITY_LABEL  LABEL;
    struct IDENTITY_LABEL_QUE  LABEL_QUE;

}identity;

typedef enum MOTOR_STEPANGLE_Enum0
{
    MOTOR_STEPANGLE_Enum0_1d8,
    MOTOR_STEPANGLE_Enum0_0d9,
    MOTOR_STEPANGLE_Enum0_15,
    MOTOR_STEPANGLE_Enum0_7d5,
}MOTOR_STEPANGLE_Enum0;



struct MOTOR_STEPANGLE
{
    int MOTOR_mainNUM = 51;
    char STEPANGLE_subNUM = 0;
    unsigned char  U8_0_0;
    MOTOR_STEPANGLE_Enum0  ENUM0_1;

    struct MOTOR_STEPANGLE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_STEPANGLE* Add_ENUM0_1( MOTOR_STEPANGLE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STEPANGLE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct MOTOR_STEPANGLE_QUE
{
    int MOTOR_mainNUM = 51;
    char STEPANGLE_QUE_subNUM = 1;
    unsigned char  U8_0_0;

    struct MOTOR_STEPANGLE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STEPANGLE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTOR_TYPE_Enum0
{
    MOTOR_TYPE_Enum0_ROTARY,
    MOTOR_TYPE_Enum0_LINEAR,
}MOTOR_TYPE_Enum0;



struct MOTOR_TYPE
{
    int MOTOR_mainNUM = 51;
    char TYPE_subNUM = 2;
    unsigned char  U8_0_0;
    MOTOR_TYPE_Enum0  ENUM0_1;

    struct MOTOR_TYPE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_TYPE* Add_ENUM0_1( MOTOR_TYPE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct MOTOR_TYPE_QUE
{
    int MOTOR_mainNUM = 51;
    char TYPE_QUE_subNUM = 3;
    unsigned char  U8_0_0;

    struct MOTOR_TYPE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTOR_POSITIONUNIT_Enum0
{
    MOTOR_POSITIONUNIT_Enum0_ANGLE,
    MOTOR_POSITIONUNIT_Enum0_RADIAN,
    MOTOR_POSITIONUNIT_Enum0_MILLIMETER,
}MOTOR_POSITIONUNIT_Enum0;



struct MOTOR_POSITIONUNIT
{
    int MOTOR_mainNUM = 51;
    char POSITIONUNIT_subNUM = 4;
    unsigned char  U8_0_0;
    MOTOR_POSITIONUNIT_Enum0  ENUM0_1;

    struct MOTOR_POSITIONUNIT* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_POSITIONUNIT* Add_ENUM0_1( MOTOR_POSITIONUNIT_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (POSITIONUNIT_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct MOTOR_POSITIONUNIT_QUE
{
    int MOTOR_mainNUM = 51;
    char POSITIONUNIT_QUE_subNUM = 5;
    unsigned char  U8_0_0;

    struct MOTOR_POSITIONUNIT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (POSITIONUNIT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTOR_GEARRATIONUM
{
    int MOTOR_mainNUM = 51;
    char GEARRATIONUM_subNUM = 6;
    unsigned char  U8_0_0;
    unsigned short  U16_0_1;

    struct MOTOR_GEARRATIONUM* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_GEARRATIONUM* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GEARRATIONUM_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        return cmdData ;
    }

};


struct MOTOR_GEARRATIONUM_QUE
{
    int MOTOR_mainNUM = 51;
    char GEARRATIONUM_QUE_subNUM = 7;
    unsigned char  U8_0_0;

    struct MOTOR_GEARRATIONUM_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GEARRATIONUM_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTOR_GEARRATIODEN
{
    int MOTOR_mainNUM = 51;
    char GEARRATIODEN_subNUM = 8;
    unsigned char  U8_0_0;
    unsigned short  U16_0_1;

    struct MOTOR_GEARRATIODEN* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_GEARRATIODEN* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GEARRATIODEN_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        return cmdData ;
    }

};


struct MOTOR_GEARRATIODEN_QUE
{
    int MOTOR_mainNUM = 51;
    char GEARRATIODEN_QUE_subNUM = 9;
    unsigned char  U8_0_0;

    struct MOTOR_GEARRATIODEN_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (GEARRATIODEN_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTOR_LEAD
{
    int MOTOR_mainNUM = 51;
    char LEAD_subNUM = 10;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTOR_LEAD* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_LEAD* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEAD_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTOR_LEAD_QUE
{
    int MOTOR_mainNUM = 51;
    char LEAD_QUE_subNUM = 11;
    unsigned char  U8_0_0;

    struct MOTOR_LEAD_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEAD_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTOR_PEAKSPEED
{
    int MOTOR_mainNUM = 51;
    char PEAKSPEED_subNUM = 12;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTOR_PEAKSPEED* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_PEAKSPEED* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PEAKSPEED_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTOR_PEAKSPEED_QUE
{
    int MOTOR_mainNUM = 51;
    char PEAKSPEED_QUE_subNUM = 13;
    unsigned char  U8_0_0;

    struct MOTOR_PEAKSPEED_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PEAKSPEED_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTOR_PEAKACCELERATION
{
    int MOTOR_mainNUM = 51;
    char PEAKACCELERATION_subNUM = 14;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTOR_PEAKACCELERATION* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_PEAKACCELERATION* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PEAKACCELERATION_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTOR_PEAKACCELERATION_QUE
{
    int MOTOR_mainNUM = 51;
    char PEAKACCELERATION_QUE_subNUM = 15;
    unsigned char  U8_0_0;

    struct MOTOR_PEAKACCELERATION_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PEAKACCELERATION_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTOR_SIZE_Enum0
{
    MOTOR_SIZE_Enum0_8,
    MOTOR_SIZE_Enum0_11,
    MOTOR_SIZE_Enum0_14,
    MOTOR_SIZE_Enum0_17,
    MOTOR_SIZE_Enum0_23,
    MOTOR_SIZE_Enum0_24,
}MOTOR_SIZE_Enum0;



struct MOTOR_SIZE
{
    int MOTOR_mainNUM = 51;
    char SIZE_subNUM = 16;
    unsigned char  U8_0_0;
    MOTOR_SIZE_Enum0  ENUM0_1;

    struct MOTOR_SIZE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_SIZE* Add_ENUM0_1( MOTOR_SIZE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SIZE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct MOTOR_SIZE_QUE
{
    int MOTOR_mainNUM = 51;
    char SIZE_QUE_subNUM = 17;
    unsigned char  U8_0_0;

    struct MOTOR_SIZE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SIZE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTOR_VOLTAGE
{
    int MOTOR_mainNUM = 51;
    char VOLTAGE_subNUM = 18;
    unsigned char  U8_0_0;
    unsigned char  U8_1_1;

    struct MOTOR_VOLTAGE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_VOLTAGE* Add_U8_1_1( unsigned char param )
    {
        U8_1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (VOLTAGE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU8_1_1 = (char *) &U8_1_1 ;
        cmdData.cmdData[3] = *( ptrU8_1_1++);
        return cmdData ;
    }

};


struct MOTOR_VOLTAGE_QUE
{
    int MOTOR_mainNUM = 51;
    char VOLTAGE_QUE_subNUM = 19;
    unsigned char  U8_0_0;

    struct MOTOR_VOLTAGE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (VOLTAGE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_1_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTOR_CURRENT
{
    int MOTOR_mainNUM = 51;
    char CURRENT_subNUM = 20;
    unsigned char  U8_0_0;
    unsigned char  U8_1_1;

    struct MOTOR_CURRENT* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_CURRENT* Add_U8_1_1( unsigned char param )
    {
        U8_1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CURRENT_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU8_1_1 = (char *) &U8_1_1 ;
        cmdData.cmdData[3] = *( ptrU8_1_1++);
        return cmdData ;
    }

};


struct MOTOR_CURRENT_QUE
{
    int MOTOR_mainNUM = 51;
    char CURRENT_QUE_subNUM = 21;
    unsigned char  U8_0_0;

    struct MOTOR_CURRENT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CURRENT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_1_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTOR_BACKLASH
{
    int MOTOR_mainNUM = 51;
    char BACKLASH_subNUM = 22;
    unsigned char  U8_0_0;
    float  F32_0_1;

    struct MOTOR_BACKLASH* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTOR_BACKLASH* Add_F32_0_1( float param )
    {
        F32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BACKLASH_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrF32_0_1 = (char *) &F32_0_1 ;
        cmdData.cmdData[3] = *( ptrF32_0_1++);
        cmdData.cmdData[4] = *( ptrF32_0_1++);
        cmdData.cmdData[5] = *( ptrF32_0_1++);
        cmdData.cmdData[6] = *( ptrF32_0_1++);
        return cmdData ;
    }

};


struct MOTOR_BACKLASH_QUE
{
    int MOTOR_mainNUM = 51;
    char BACKLASH_QUE_subNUM = 23;
    unsigned char  U8_0_0;

    struct MOTOR_BACKLASH_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BACKLASH_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct MOTOR_BACKLASHTEST
{
    int MOTOR_mainNUM = 51;
    char BACKLASHTEST_subNUM = 24;
    unsigned char  U8_0_0;

    struct MOTOR_BACKLASHTEST* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BACKLASHTEST_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }

};


struct MOTOR_BACKLASHTEST_QUE
{
    int MOTOR_mainNUM = 51;
    char BACKLASHTEST_QUE_subNUM = 25;
    unsigned char  U8_0_0;

    struct MOTOR_BACKLASHTEST_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTOR_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BACKLASHTEST_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct motor
{
    int  MOTOR_NUM = 51;
    struct MOTOR_STEPANGLE  STEPANGLE;
    struct MOTOR_STEPANGLE_QUE  STEPANGLE_QUE;
    struct MOTOR_TYPE  TYPE;
    struct MOTOR_TYPE_QUE  TYPE_QUE;
    struct MOTOR_POSITIONUNIT  POSITIONUNIT;
    struct MOTOR_POSITIONUNIT_QUE  POSITIONUNIT_QUE;
    struct MOTOR_GEARRATIONUM  GEARRATIONUM;
    struct MOTOR_GEARRATIONUM_QUE  GEARRATIONUM_QUE;
    struct MOTOR_GEARRATIODEN  GEARRATIODEN;
    struct MOTOR_GEARRATIODEN_QUE  GEARRATIODEN_QUE;
    struct MOTOR_LEAD  LEAD;
    struct MOTOR_LEAD_QUE  LEAD_QUE;
    struct MOTOR_PEAKSPEED  PEAKSPEED;
    struct MOTOR_PEAKSPEED_QUE  PEAKSPEED_QUE;
    struct MOTOR_PEAKACCELERATION  PEAKACCELERATION;
    struct MOTOR_PEAKACCELERATION_QUE  PEAKACCELERATION_QUE;
    struct MOTOR_SIZE  SIZE;
    struct MOTOR_SIZE_QUE  SIZE_QUE;
    struct MOTOR_VOLTAGE  VOLTAGE;
    struct MOTOR_VOLTAGE_QUE  VOLTAGE_QUE;
    struct MOTOR_CURRENT  CURRENT;
    struct MOTOR_CURRENT_QUE  CURRENT_QUE;
    struct MOTOR_BACKLASH  BACKLASH;
    struct MOTOR_BACKLASH_QUE  BACKLASH_QUE;
    struct MOTOR_BACKLASHTEST  BACKLASHTEST;
    struct MOTOR_BACKLASHTEST_QUE  BACKLASHTEST_QUE;

}motor;



struct ENCODER_LINENUM
{
    int ENCODER_mainNUM = 52;
    char LINENUM_subNUM = 0;
    unsigned char  U8_0_0;
    unsigned int  U32_0_1;

    struct ENCODER_LINENUM* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct ENCODER_LINENUM* Add_U32_0_1( unsigned int param )
    {
        U32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LINENUM_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU32_0_1 = (char *) &U32_0_1 ;
        cmdData.cmdData[3] = *( ptrU32_0_1++);
        cmdData.cmdData[4] = *( ptrU32_0_1++);
        cmdData.cmdData[5] = *( ptrU32_0_1++);
        cmdData.cmdData[6] = *( ptrU32_0_1++);
        return cmdData ;
    }

};


struct ENCODER_LINENUM_QUE
{
    int ENCODER_mainNUM = 52;
    char LINENUM_QUE_subNUM = 1;
    unsigned char  U8_0_0;

    struct ENCODER_LINENUM_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LINENUM_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ENCODER_CHANNELNUM_Enum0
{
    ENCODER_CHANNELNUM_Enum0_1,
    ENCODER_CHANNELNUM_Enum0_3,
}ENCODER_CHANNELNUM_Enum0;



struct ENCODER_CHANNELNUM
{
    int ENCODER_mainNUM = 52;
    char CHANNELNUM_subNUM = 2;
    unsigned char  U8_0_0;
    ENCODER_CHANNELNUM_Enum0  ENUM0_1;

    struct ENCODER_CHANNELNUM* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct ENCODER_CHANNELNUM* Add_ENUM0_1( ENCODER_CHANNELNUM_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CHANNELNUM_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct ENCODER_CHANNELNUM_QUE
{
    int ENCODER_mainNUM = 52;
    char CHANNELNUM_QUE_subNUM = 3;
    unsigned char  U8_0_0;

    struct ENCODER_CHANNELNUM_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CHANNELNUM_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ENCODER_TYPE_Enum0
{
    ENCODER_TYPE_Enum0_INCREMENTAL,
    ENCODER_TYPE_Enum0_ABSOLUTE,
}ENCODER_TYPE_Enum0;



struct ENCODER_TYPE
{
    int ENCODER_mainNUM = 52;
    char TYPE_subNUM = 4;
    unsigned char  U8_0_0;
    ENCODER_TYPE_Enum0  ENUM0_1;

    struct ENCODER_TYPE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct ENCODER_TYPE* Add_ENUM0_1( ENCODER_TYPE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct ENCODER_TYPE_QUE
{
    int ENCODER_mainNUM = 52;
    char TYPE_QUE_subNUM = 5;
    unsigned char  U8_0_0;

    struct ENCODER_TYPE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ENCODER_MULTIPLE_Enum0
{
    ENCODER_MULTIPLE_Enum0_SINGLE,
    ENCODER_MULTIPLE_Enum0_DOUBLE,
    ENCODER_MULTIPLE_Enum0_QUADRUPLE,
}ENCODER_MULTIPLE_Enum0;



struct ENCODER_MULTIPLE
{
    int ENCODER_mainNUM = 52;
    char MULTIPLE_subNUM = 6;
    unsigned char  U8_0_0;
    ENCODER_MULTIPLE_Enum0  ENUM0_1;

    struct ENCODER_MULTIPLE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct ENCODER_MULTIPLE* Add_ENUM0_1( ENCODER_MULTIPLE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MULTIPLE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct ENCODER_MULTIPLE_QUE
{
    int ENCODER_mainNUM = 52;
    char MULTIPLE_QUE_subNUM = 7;
    unsigned char  U8_0_0;

    struct ENCODER_MULTIPLE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MULTIPLE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ENCODER_STATE_Enum0
{
    ENCODER_STATE_Enum0_NONE,
    ENCODER_STATE_Enum0_OFF,
    ENCODER_STATE_Enum0_ON,
}ENCODER_STATE_Enum0;



struct ENCODER_STATE
{
    int ENCODER_mainNUM = 52;
    char STATE_subNUM = 8;
    unsigned char  U8_0_0;
    ENCODER_STATE_Enum0  ENUM0_1;

    struct ENCODER_STATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct ENCODER_STATE* Add_ENUM0_1( ENCODER_STATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct ENCODER_STATE_QUE
{
    int ENCODER_mainNUM = 52;
    char STATE_QUE_subNUM = 9;
    unsigned char  U8_0_0;

    struct ENCODER_STATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct ENCODER_FEEDBACKRATIO
{
    int ENCODER_mainNUM = 52;
    char FEEDBACKRATIO_subNUM = 10;
    unsigned char  U8_0_0;
    unsigned char  U8_1_1;

    struct ENCODER_FEEDBACKRATIO* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct ENCODER_FEEDBACKRATIO* Add_U8_1_1( unsigned char param )
    {
        U8_1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FEEDBACKRATIO_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU8_1_1 = (char *) &U8_1_1 ;
        cmdData.cmdData[3] = *( ptrU8_1_1++);
        return cmdData ;
    }

};


struct ENCODER_FEEDBACKRATIO_QUE
{
    int ENCODER_mainNUM = 52;
    char FEEDBACKRATIO_QUE_subNUM = 11;
    unsigned char  U8_0_0;

    struct ENCODER_FEEDBACKRATIO_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ENCODER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FEEDBACKRATIO_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_1_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct encoder
{
    int  ENCODER_NUM = 52;
    struct ENCODER_LINENUM  LINENUM;
    struct ENCODER_LINENUM_QUE  LINENUM_QUE;
    struct ENCODER_CHANNELNUM  CHANNELNUM;
    struct ENCODER_CHANNELNUM_QUE  CHANNELNUM_QUE;
    struct ENCODER_TYPE  TYPE;
    struct ENCODER_TYPE_QUE  TYPE_QUE;
    struct ENCODER_MULTIPLE  MULTIPLE;
    struct ENCODER_MULTIPLE_QUE  MULTIPLE_QUE;
    struct ENCODER_STATE  STATE;
    struct ENCODER_STATE_QUE  STATE_QUE;
    struct ENCODER_FEEDBACKRATIO  FEEDBACKRATIO;
    struct ENCODER_FEEDBACKRATIO_QUE  FEEDBACKRATIO_QUE;

}encoder;

typedef enum MOTIONPLAN_PVTCONFIG_Enum0
{
    MOTIONPLAN_PVTCONFIG_Enum0_MAIN,
    MOTIONPLAN_PVTCONFIG_Enum0_SMALL,
    MOTIONPLAN_PVTCONFIG_Enum0_P1,
    MOTIONPLAN_PVTCONFIG_Enum0_P2,
    MOTIONPLAN_PVTCONFIG_Enum0_P3,
    MOTIONPLAN_PVTCONFIG_Enum0_P4,
    MOTIONPLAN_PVTCONFIG_Enum0_P5,
    MOTIONPLAN_PVTCONFIG_Enum0_P6,
    MOTIONPLAN_PVTCONFIG_Enum0_P7,
    MOTIONPLAN_PVTCONFIG_Enum0_P8,
}MOTIONPLAN_PVTCONFIG_Enum0;

typedef enum MOTIONPLAN_PVTCONFIG_Enum1
{
    MOTIONPLAN_PVTCONFIG_Enum1_END,
    MOTIONPLAN_PVTCONFIG_Enum1_CLEAR,
}MOTIONPLAN_PVTCONFIG_Enum1;



struct MOTIONPLAN_PVTCONFIG
{
    int MOTIONPLAN_mainNUM = 53;
    char PVTCONFIG_subNUM = 0;
    unsigned char  U8_0_0;
    MOTIONPLAN_PVTCONFIG_Enum0  ENUM0_1;
    MOTIONPLAN_PVTCONFIG_Enum1  ENUM1_2;

    struct MOTIONPLAN_PVTCONFIG* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_PVTCONFIG* Add_ENUM0_1( MOTIONPLAN_PVTCONFIG_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_PVTCONFIG* Add_ENUM1_2( MOTIONPLAN_PVTCONFIG_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PVTCONFIG_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_PVTCONFIG_QUE_Enum0
{
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_MAIN,
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_SMALL,
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_P1,
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_P2,
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_P3,
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_P4,
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_P5,
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_P6,
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_P7,
    MOTIONPLAN_PVTCONFIG_QUE_Enum0_P8,
}MOTIONPLAN_PVTCONFIG_QUE_Enum0;



struct MOTIONPLAN_PVTCONFIG_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char PVTCONFIG_QUE_subNUM = 1;
    unsigned char  U8_0_0;
    MOTIONPLAN_PVTCONFIG_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_PVTCONFIG_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_PVTCONFIG_QUE* Add_ENUM0_1( MOTIONPLAN_PVTCONFIG_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PVTCONFIG_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_PRESETSTATE_Enum0
{
    MOTIONPLAN_PRESETSTATE_Enum0_RESERVE0,
    MOTIONPLAN_PRESETSTATE_Enum0_RESERVE1,
    MOTIONPLAN_PRESETSTATE_Enum0_P1,
    MOTIONPLAN_PRESETSTATE_Enum0_P2,
    MOTIONPLAN_PRESETSTATE_Enum0_P3,
    MOTIONPLAN_PRESETSTATE_Enum0_P4,
    MOTIONPLAN_PRESETSTATE_Enum0_P5,
    MOTIONPLAN_PRESETSTATE_Enum0_P6,
    MOTIONPLAN_PRESETSTATE_Enum0_P7,
    MOTIONPLAN_PRESETSTATE_Enum0_P8,
}MOTIONPLAN_PRESETSTATE_Enum0;

typedef enum MOTIONPLAN_PRESETSTATE_Enum1
{
    MOTIONPLAN_PRESETSTATE_Enum1_OFF,
    MOTIONPLAN_PRESETSTATE_Enum1_ON,
    MOTIONPLAN_PRESETSTATE_Enum1_CALC,
}MOTIONPLAN_PRESETSTATE_Enum1;



struct MOTIONPLAN_PRESETSTATE
{
    int MOTIONPLAN_mainNUM = 53;
    char PRESETSTATE_subNUM = 2;
    unsigned char  U8_0_0;
    MOTIONPLAN_PRESETSTATE_Enum0  ENUM0_1;
    MOTIONPLAN_PRESETSTATE_Enum1  ENUM1_2;

    struct MOTIONPLAN_PRESETSTATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_PRESETSTATE* Add_ENUM0_1( MOTIONPLAN_PRESETSTATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_PRESETSTATE* Add_ENUM1_2( MOTIONPLAN_PRESETSTATE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PRESETSTATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_PRESETSTATE_QUE_Enum0
{
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_RESERVE0,
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_RESERVE1,
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_P1,
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_P2,
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_P3,
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_P4,
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_P5,
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_P6,
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_P7,
    MOTIONPLAN_PRESETSTATE_QUE_Enum0_P8,
}MOTIONPLAN_PRESETSTATE_QUE_Enum0;



struct MOTIONPLAN_PRESETSTATE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char PRESETSTATE_QUE_subNUM = 3;
    unsigned char  U8_0_0;
    MOTIONPLAN_PRESETSTATE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_PRESETSTATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_PRESETSTATE_QUE* Add_ENUM0_1( MOTIONPLAN_PRESETSTATE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PRESETSTATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_EXECUTEMODE_Enum0
{
    MOTIONPLAN_EXECUTEMODE_Enum0_MAIN,
    MOTIONPLAN_EXECUTEMODE_Enum0_SMALL,
    MOTIONPLAN_EXECUTEMODE_Enum0_P1,
    MOTIONPLAN_EXECUTEMODE_Enum0_P2,
    MOTIONPLAN_EXECUTEMODE_Enum0_P3,
    MOTIONPLAN_EXECUTEMODE_Enum0_P4,
    MOTIONPLAN_EXECUTEMODE_Enum0_P5,
    MOTIONPLAN_EXECUTEMODE_Enum0_P6,
    MOTIONPLAN_EXECUTEMODE_Enum0_P7,
    MOTIONPLAN_EXECUTEMODE_Enum0_P8,
}MOTIONPLAN_EXECUTEMODE_Enum0;

typedef enum MOTIONPLAN_EXECUTEMODE_Enum1
{
    MOTIONPLAN_EXECUTEMODE_Enum1_CYCLE,
    MOTIONPLAN_EXECUTEMODE_Enum1_FIFO,
}MOTIONPLAN_EXECUTEMODE_Enum1;



struct MOTIONPLAN_EXECUTEMODE
{
    int MOTIONPLAN_mainNUM = 53;
    char EXECUTEMODE_subNUM = 4;
    unsigned char  U8_0_0;
    MOTIONPLAN_EXECUTEMODE_Enum0  ENUM0_1;
    MOTIONPLAN_EXECUTEMODE_Enum1  ENUM1_2;

    struct MOTIONPLAN_EXECUTEMODE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_EXECUTEMODE* Add_ENUM0_1( MOTIONPLAN_EXECUTEMODE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_EXECUTEMODE* Add_ENUM1_2( MOTIONPLAN_EXECUTEMODE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (EXECUTEMODE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_EXECUTEMODE_QUE_Enum0
{
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_MAIN,
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_SMALL,
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_P1,
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_P2,
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_P3,
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_P4,
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_P5,
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_P6,
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_P7,
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0_P8,
}MOTIONPLAN_EXECUTEMODE_QUE_Enum0;



struct MOTIONPLAN_EXECUTEMODE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char EXECUTEMODE_QUE_subNUM = 5;
    unsigned char  U8_0_0;
    MOTIONPLAN_EXECUTEMODE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_EXECUTEMODE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_EXECUTEMODE_QUE* Add_ENUM0_1( MOTIONPLAN_EXECUTEMODE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (EXECUTEMODE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_PLANMODE_Enum0
{
    MOTIONPLAN_PLANMODE_Enum0_MAIN,
    MOTIONPLAN_PLANMODE_Enum0_SMALL,
    MOTIONPLAN_PLANMODE_Enum0_P1,
    MOTIONPLAN_PLANMODE_Enum0_P2,
    MOTIONPLAN_PLANMODE_Enum0_P3,
    MOTIONPLAN_PLANMODE_Enum0_P4,
    MOTIONPLAN_PLANMODE_Enum0_P5,
    MOTIONPLAN_PLANMODE_Enum0_P6,
    MOTIONPLAN_PLANMODE_Enum0_P7,
    MOTIONPLAN_PLANMODE_Enum0_P8,
}MOTIONPLAN_PLANMODE_Enum0;

typedef enum MOTIONPLAN_PLANMODE_Enum1
{
    MOTIONPLAN_PLANMODE_Enum1_CUBICPOLY,
    MOTIONPLAN_PLANMODE_Enum1_TRAPEZOID,
    MOTIONPLAN_PLANMODE_Enum1_SCURVE,
}MOTIONPLAN_PLANMODE_Enum1;



struct MOTIONPLAN_PLANMODE
{
    int MOTIONPLAN_mainNUM = 53;
    char PLANMODE_subNUM = 6;
    unsigned char  U8_0_0;
    MOTIONPLAN_PLANMODE_Enum0  ENUM0_1;
    MOTIONPLAN_PLANMODE_Enum1  ENUM1_2;

    struct MOTIONPLAN_PLANMODE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_PLANMODE* Add_ENUM0_1( MOTIONPLAN_PLANMODE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_PLANMODE* Add_ENUM1_2( MOTIONPLAN_PLANMODE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PLANMODE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_PLANMODE_QUE_Enum0
{
    MOTIONPLAN_PLANMODE_QUE_Enum0_MAIN,
    MOTIONPLAN_PLANMODE_QUE_Enum0_SMALL,
    MOTIONPLAN_PLANMODE_QUE_Enum0_P1,
    MOTIONPLAN_PLANMODE_QUE_Enum0_P2,
    MOTIONPLAN_PLANMODE_QUE_Enum0_P3,
    MOTIONPLAN_PLANMODE_QUE_Enum0_P4,
    MOTIONPLAN_PLANMODE_QUE_Enum0_P5,
    MOTIONPLAN_PLANMODE_QUE_Enum0_P6,
    MOTIONPLAN_PLANMODE_QUE_Enum0_P7,
    MOTIONPLAN_PLANMODE_QUE_Enum0_P8,
}MOTIONPLAN_PLANMODE_QUE_Enum0;



struct MOTIONPLAN_PLANMODE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char PLANMODE_QUE_subNUM = 7;
    unsigned char  U8_0_0;
    MOTIONPLAN_PLANMODE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_PLANMODE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_PLANMODE_QUE* Add_ENUM0_1( MOTIONPLAN_PLANMODE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PLANMODE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_MOTIONMODE_Enum0
{
    MOTIONPLAN_MOTIONMODE_Enum0_MAIN,
    MOTIONPLAN_MOTIONMODE_Enum0_SMALL,
    MOTIONPLAN_MOTIONMODE_Enum0_P1,
    MOTIONPLAN_MOTIONMODE_Enum0_P2,
    MOTIONPLAN_MOTIONMODE_Enum0_P3,
    MOTIONPLAN_MOTIONMODE_Enum0_P4,
    MOTIONPLAN_MOTIONMODE_Enum0_P5,
    MOTIONPLAN_MOTIONMODE_Enum0_P6,
    MOTIONPLAN_MOTIONMODE_Enum0_P7,
    MOTIONPLAN_MOTIONMODE_Enum0_P8,
}MOTIONPLAN_MOTIONMODE_Enum0;

typedef enum MOTIONPLAN_MOTIONMODE_Enum1
{
    MOTIONPLAN_MOTIONMODE_Enum1_PVT,
    MOTIONPLAN_MOTIONMODE_Enum1_LVT_CORRECT,
    MOTIONPLAN_MOTIONMODE_Enum1_LVT_NOCORRECT,
}MOTIONPLAN_MOTIONMODE_Enum1;



struct MOTIONPLAN_MOTIONMODE
{
    int MOTIONPLAN_mainNUM = 53;
    char MOTIONMODE_subNUM = 8;
    unsigned char  U8_0_0;
    MOTIONPLAN_MOTIONMODE_Enum0  ENUM0_1;
    MOTIONPLAN_MOTIONMODE_Enum1  ENUM1_2;

    struct MOTIONPLAN_MOTIONMODE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_MOTIONMODE* Add_ENUM0_1( MOTIONPLAN_MOTIONMODE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_MOTIONMODE* Add_ENUM1_2( MOTIONPLAN_MOTIONMODE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MOTIONMODE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_MOTIONMODE_QUE_Enum0
{
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_MAIN,
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_SMALL,
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_P1,
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_P2,
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_P3,
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_P4,
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_P5,
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_P6,
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_P7,
    MOTIONPLAN_MOTIONMODE_QUE_Enum0_P8,
}MOTIONPLAN_MOTIONMODE_QUE_Enum0;



struct MOTIONPLAN_MOTIONMODE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char MOTIONMODE_QUE_subNUM = 9;
    unsigned char  U8_0_0;
    MOTIONPLAN_MOTIONMODE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_MOTIONMODE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_MOTIONMODE_QUE* Add_ENUM0_1( MOTIONPLAN_MOTIONMODE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MOTIONMODE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_MODIFYDUTY_Enum0
{
    MOTIONPLAN_MODIFYDUTY_Enum0_MAIN,
    MOTIONPLAN_MODIFYDUTY_Enum0_SMALL,
    MOTIONPLAN_MODIFYDUTY_Enum0_P1,
    MOTIONPLAN_MODIFYDUTY_Enum0_P2,
    MOTIONPLAN_MODIFYDUTY_Enum0_P3,
    MOTIONPLAN_MODIFYDUTY_Enum0_P4,
    MOTIONPLAN_MODIFYDUTY_Enum0_P5,
    MOTIONPLAN_MODIFYDUTY_Enum0_P6,
    MOTIONPLAN_MODIFYDUTY_Enum0_P7,
    MOTIONPLAN_MODIFYDUTY_Enum0_P8,
}MOTIONPLAN_MODIFYDUTY_Enum0;

typedef enum MOTIONPLAN_MODIFYDUTY_Enum1
{
    MOTIONPLAN_MODIFYDUTY_Enum1_1f4,
    MOTIONPLAN_MODIFYDUTY_Enum1_1f8,
    MOTIONPLAN_MODIFYDUTY_Enum1_1f16,
    MOTIONPLAN_MODIFYDUTY_Enum1_1f32,
}MOTIONPLAN_MODIFYDUTY_Enum1;



struct MOTIONPLAN_MODIFYDUTY
{
    int MOTIONPLAN_mainNUM = 53;
    char MODIFYDUTY_subNUM = 10;
    unsigned char  U8_0_0;
    MOTIONPLAN_MODIFYDUTY_Enum0  ENUM0_1;
    MOTIONPLAN_MODIFYDUTY_Enum1  ENUM1_2;

    struct MOTIONPLAN_MODIFYDUTY* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_MODIFYDUTY* Add_ENUM0_1( MOTIONPLAN_MODIFYDUTY_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_MODIFYDUTY* Add_ENUM1_2( MOTIONPLAN_MODIFYDUTY_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MODIFYDUTY_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_MODIFYDUTY_QUE_Enum0
{
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_MAIN,
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_SMALL,
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_P1,
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_P2,
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_P3,
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_P4,
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_P5,
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_P6,
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_P7,
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0_P8,
}MOTIONPLAN_MODIFYDUTY_QUE_Enum0;



struct MOTIONPLAN_MODIFYDUTY_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char MODIFYDUTY_QUE_subNUM = 11;
    unsigned char  U8_0_0;
    MOTIONPLAN_MODIFYDUTY_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_MODIFYDUTY_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_MODIFYDUTY_QUE* Add_ENUM0_1( MOTIONPLAN_MODIFYDUTY_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MODIFYDUTY_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_REMAINPOINT_QUE_Enum0
{
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_MAIN,
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_SMALL,
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_P1,
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_P2,
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_P3,
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_P4,
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_P5,
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_P6,
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_P7,
    MOTIONPLAN_REMAINPOINT_QUE_Enum0_P8,
}MOTIONPLAN_REMAINPOINT_QUE_Enum0;



struct MOTIONPLAN_REMAINPOINT_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char REMAINPOINT_QUE_subNUM = 12;
    unsigned char  U8_0_0;
    MOTIONPLAN_REMAINPOINT_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_REMAINPOINT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_REMAINPOINT_QUE* Add_ENUM0_1( MOTIONPLAN_REMAINPOINT_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (REMAINPOINT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_CYCLENUM_Enum0
{
    MOTIONPLAN_CYCLENUM_Enum0_MAIN,
    MOTIONPLAN_CYCLENUM_Enum0_SMALL,
    MOTIONPLAN_CYCLENUM_Enum0_P1,
    MOTIONPLAN_CYCLENUM_Enum0_P2,
    MOTIONPLAN_CYCLENUM_Enum0_P3,
    MOTIONPLAN_CYCLENUM_Enum0_P4,
    MOTIONPLAN_CYCLENUM_Enum0_P5,
    MOTIONPLAN_CYCLENUM_Enum0_P6,
    MOTIONPLAN_CYCLENUM_Enum0_P7,
    MOTIONPLAN_CYCLENUM_Enum0_P8,
}MOTIONPLAN_CYCLENUM_Enum0;



struct MOTIONPLAN_CYCLENUM
{
    int MOTIONPLAN_mainNUM = 53;
    char CYCLENUM_subNUM = 13;
    unsigned char  U8_0_0;
    MOTIONPLAN_CYCLENUM_Enum0  ENUM0_1;
    unsigned int  U32_0_2;

    struct MOTIONPLAN_CYCLENUM* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_CYCLENUM* Add_ENUM0_1( MOTIONPLAN_CYCLENUM_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_CYCLENUM* Add_U32_0_2( unsigned int param )
    {
        U32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CYCLENUM_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU32_0_2 = (char *) &U32_0_2 ;
        cmdData.cmdData[4] = *( ptrU32_0_2++);
        cmdData.cmdData[5] = *( ptrU32_0_2++);
        cmdData.cmdData[6] = *( ptrU32_0_2++);
        cmdData.cmdData[7] = *( ptrU32_0_2++);
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_CYCLENUM_QUE_Enum0
{
    MOTIONPLAN_CYCLENUM_QUE_Enum0_MAIN,
    MOTIONPLAN_CYCLENUM_QUE_Enum0_SMALL,
    MOTIONPLAN_CYCLENUM_QUE_Enum0_P1,
    MOTIONPLAN_CYCLENUM_QUE_Enum0_P2,
    MOTIONPLAN_CYCLENUM_QUE_Enum0_P3,
    MOTIONPLAN_CYCLENUM_QUE_Enum0_P4,
    MOTIONPLAN_CYCLENUM_QUE_Enum0_P5,
    MOTIONPLAN_CYCLENUM_QUE_Enum0_P6,
    MOTIONPLAN_CYCLENUM_QUE_Enum0_P7,
    MOTIONPLAN_CYCLENUM_QUE_Enum0_P8,
}MOTIONPLAN_CYCLENUM_QUE_Enum0;



struct MOTIONPLAN_CYCLENUM_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char CYCLENUM_QUE_subNUM = 14;
    unsigned char  U8_0_0;
    MOTIONPLAN_CYCLENUM_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_CYCLENUM_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_CYCLENUM_QUE* Add_ENUM0_1( MOTIONPLAN_CYCLENUM_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CYCLENUM_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_WARNPOINT_Enum0
{
    MOTIONPLAN_WARNPOINT_Enum0_MAIN,
    MOTIONPLAN_WARNPOINT_Enum0_SMALL,
    MOTIONPLAN_WARNPOINT_Enum0_P1,
    MOTIONPLAN_WARNPOINT_Enum0_P2,
    MOTIONPLAN_WARNPOINT_Enum0_P3,
    MOTIONPLAN_WARNPOINT_Enum0_P4,
    MOTIONPLAN_WARNPOINT_Enum0_P5,
    MOTIONPLAN_WARNPOINT_Enum0_P6,
    MOTIONPLAN_WARNPOINT_Enum0_P7,
    MOTIONPLAN_WARNPOINT_Enum0_P8,
}MOTIONPLAN_WARNPOINT_Enum0;



struct MOTIONPLAN_WARNPOINT
{
    int MOTIONPLAN_mainNUM = 53;
    char WARNPOINT_subNUM = 15;
    unsigned char  U8_0_0;
    MOTIONPLAN_WARNPOINT_Enum0  ENUM0_1;
    unsigned char  U8_1_2;

    struct MOTIONPLAN_WARNPOINT* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_WARNPOINT* Add_ENUM0_1( MOTIONPLAN_WARNPOINT_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_WARNPOINT* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (WARNPOINT_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_WARNPOINT_QUE_Enum0
{
    MOTIONPLAN_WARNPOINT_QUE_Enum0_MAIN,
    MOTIONPLAN_WARNPOINT_QUE_Enum0_SMALL,
    MOTIONPLAN_WARNPOINT_QUE_Enum0_P1,
    MOTIONPLAN_WARNPOINT_QUE_Enum0_P2,
    MOTIONPLAN_WARNPOINT_QUE_Enum0_P3,
    MOTIONPLAN_WARNPOINT_QUE_Enum0_P4,
    MOTIONPLAN_WARNPOINT_QUE_Enum0_P5,
    MOTIONPLAN_WARNPOINT_QUE_Enum0_P6,
    MOTIONPLAN_WARNPOINT_QUE_Enum0_P7,
    MOTIONPLAN_WARNPOINT_QUE_Enum0_P8,
}MOTIONPLAN_WARNPOINT_QUE_Enum0;



struct MOTIONPLAN_WARNPOINT_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char WARNPOINT_QUE_subNUM = 16;
    unsigned char  U8_0_0;
    MOTIONPLAN_WARNPOINT_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_WARNPOINT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_WARNPOINT_QUE* Add_ENUM0_1( MOTIONPLAN_WARNPOINT_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (WARNPOINT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_1_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_ENDSTATE_Enum0
{
    MOTIONPLAN_ENDSTATE_Enum0_MAIN,
    MOTIONPLAN_ENDSTATE_Enum0_SMALL,
    MOTIONPLAN_ENDSTATE_Enum0_P1,
    MOTIONPLAN_ENDSTATE_Enum0_P2,
    MOTIONPLAN_ENDSTATE_Enum0_P3,
    MOTIONPLAN_ENDSTATE_Enum0_P4,
    MOTIONPLAN_ENDSTATE_Enum0_P5,
    MOTIONPLAN_ENDSTATE_Enum0_P6,
    MOTIONPLAN_ENDSTATE_Enum0_P7,
    MOTIONPLAN_ENDSTATE_Enum0_P8,
}MOTIONPLAN_ENDSTATE_Enum0;

typedef enum MOTIONPLAN_ENDSTATE_Enum1
{
    MOTIONPLAN_ENDSTATE_Enum1_STOP,
    MOTIONPLAN_ENDSTATE_Enum1_HOLD,
}MOTIONPLAN_ENDSTATE_Enum1;



struct MOTIONPLAN_ENDSTATE
{
    int MOTIONPLAN_mainNUM = 53;
    char ENDSTATE_subNUM = 17;
    unsigned char  U8_0_0;
    MOTIONPLAN_ENDSTATE_Enum0  ENUM0_1;
    MOTIONPLAN_ENDSTATE_Enum1  ENUM1_2;

    struct MOTIONPLAN_ENDSTATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_ENDSTATE* Add_ENUM0_1( MOTIONPLAN_ENDSTATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_ENDSTATE* Add_ENUM1_2( MOTIONPLAN_ENDSTATE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ENDSTATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_ENDSTATE_QUE_Enum0
{
    MOTIONPLAN_ENDSTATE_QUE_Enum0_MAIN,
    MOTIONPLAN_ENDSTATE_QUE_Enum0_SMALL,
    MOTIONPLAN_ENDSTATE_QUE_Enum0_P1,
    MOTIONPLAN_ENDSTATE_QUE_Enum0_P2,
    MOTIONPLAN_ENDSTATE_QUE_Enum0_P3,
    MOTIONPLAN_ENDSTATE_QUE_Enum0_P4,
    MOTIONPLAN_ENDSTATE_QUE_Enum0_P5,
    MOTIONPLAN_ENDSTATE_QUE_Enum0_P6,
    MOTIONPLAN_ENDSTATE_QUE_Enum0_P7,
    MOTIONPLAN_ENDSTATE_QUE_Enum0_P8,
}MOTIONPLAN_ENDSTATE_QUE_Enum0;



struct MOTIONPLAN_ENDSTATE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char ENDSTATE_QUE_subNUM = 18;
    unsigned char  U8_0_0;
    MOTIONPLAN_ENDSTATE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_ENDSTATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_ENDSTATE_QUE* Add_ENUM0_1( MOTIONPLAN_ENDSTATE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ENDSTATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_BUFFERSIZE_QUE_Enum0
{
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_MAIN,
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_SMALL,
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_P1,
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_P2,
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_P3,
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_P4,
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_P5,
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_P6,
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_P7,
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0_P8,
}MOTIONPLAN_BUFFERSIZE_QUE_Enum0;



struct MOTIONPLAN_BUFFERSIZE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char BUFFERSIZE_QUE_subNUM = 19;
    unsigned char  U8_0_0;
    MOTIONPLAN_BUFFERSIZE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_BUFFERSIZE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_BUFFERSIZE_QUE* Add_ENUM0_1( MOTIONPLAN_BUFFERSIZE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BUFFERSIZE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_STOPMODE_Enum0
{
    MOTIONPLAN_STOPMODE_Enum0_MAIN,
    MOTIONPLAN_STOPMODE_Enum0_SMALL,
    MOTIONPLAN_STOPMODE_Enum0_P1,
    MOTIONPLAN_STOPMODE_Enum0_P2,
    MOTIONPLAN_STOPMODE_Enum0_P3,
    MOTIONPLAN_STOPMODE_Enum0_P4,
    MOTIONPLAN_STOPMODE_Enum0_P5,
    MOTIONPLAN_STOPMODE_Enum0_P6,
    MOTIONPLAN_STOPMODE_Enum0_P7,
    MOTIONPLAN_STOPMODE_Enum0_P8,
}MOTIONPLAN_STOPMODE_Enum0;

typedef enum MOTIONPLAN_STOPMODE_Enum1
{
    MOTIONPLAN_STOPMODE_Enum1_IMMEDIATE,
    MOTIONPLAN_STOPMODE_Enum1_DISTANCE,
}MOTIONPLAN_STOPMODE_Enum1;



struct MOTIONPLAN_STOPMODE
{
    int MOTIONPLAN_mainNUM = 53;
    char STOPMODE_subNUM = 20;
    unsigned char  U8_0_0;
    MOTIONPLAN_STOPMODE_Enum0  ENUM0_1;
    MOTIONPLAN_STOPMODE_Enum1  ENUM1_2;

    struct MOTIONPLAN_STOPMODE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_STOPMODE* Add_ENUM0_1( MOTIONPLAN_STOPMODE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_STOPMODE* Add_ENUM1_2( MOTIONPLAN_STOPMODE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPMODE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_STOPMODE_QUE_Enum0
{
    MOTIONPLAN_STOPMODE_QUE_Enum0_MAIN,
    MOTIONPLAN_STOPMODE_QUE_Enum0_SMALL,
    MOTIONPLAN_STOPMODE_QUE_Enum0_P1,
    MOTIONPLAN_STOPMODE_QUE_Enum0_P2,
    MOTIONPLAN_STOPMODE_QUE_Enum0_P3,
    MOTIONPLAN_STOPMODE_QUE_Enum0_P4,
    MOTIONPLAN_STOPMODE_QUE_Enum0_P5,
    MOTIONPLAN_STOPMODE_QUE_Enum0_P6,
    MOTIONPLAN_STOPMODE_QUE_Enum0_P7,
    MOTIONPLAN_STOPMODE_QUE_Enum0_P8,
}MOTIONPLAN_STOPMODE_QUE_Enum0;



struct MOTIONPLAN_STOPMODE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char STOPMODE_QUE_subNUM = 21;
    unsigned char  U8_0_0;
    MOTIONPLAN_STOPMODE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_STOPMODE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_STOPMODE_QUE* Add_ENUM0_1( MOTIONPLAN_STOPMODE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPMODE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_STOPDISTANCE_Enum0
{
    MOTIONPLAN_STOPDISTANCE_Enum0_MAIN,
    MOTIONPLAN_STOPDISTANCE_Enum0_SMALL,
    MOTIONPLAN_STOPDISTANCE_Enum0_P1,
    MOTIONPLAN_STOPDISTANCE_Enum0_P2,
    MOTIONPLAN_STOPDISTANCE_Enum0_P3,
    MOTIONPLAN_STOPDISTANCE_Enum0_P4,
    MOTIONPLAN_STOPDISTANCE_Enum0_P5,
    MOTIONPLAN_STOPDISTANCE_Enum0_P6,
    MOTIONPLAN_STOPDISTANCE_Enum0_P7,
    MOTIONPLAN_STOPDISTANCE_Enum0_P8,
}MOTIONPLAN_STOPDISTANCE_Enum0;



struct MOTIONPLAN_STOPDISTANCE
{
    int MOTIONPLAN_mainNUM = 53;
    char STOPDISTANCE_subNUM = 22;
    unsigned char  U8_0_0;
    MOTIONPLAN_STOPDISTANCE_Enum0  ENUM0_1;
    float  F32_0_2;

    struct MOTIONPLAN_STOPDISTANCE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_STOPDISTANCE* Add_ENUM0_1( MOTIONPLAN_STOPDISTANCE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_STOPDISTANCE* Add_F32_0_2( float param )
    {
        F32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPDISTANCE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrF32_0_2 = (char *) &F32_0_2 ;
        cmdData.cmdData[4] = *( ptrF32_0_2++);
        cmdData.cmdData[5] = *( ptrF32_0_2++);
        cmdData.cmdData[6] = *( ptrF32_0_2++);
        cmdData.cmdData[7] = *( ptrF32_0_2++);
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_STOPDISTANCE_QUE_Enum0
{
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_MAIN,
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_SMALL,
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_P1,
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_P2,
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_P3,
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_P4,
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_P5,
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_P6,
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_P7,
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0_P8,
}MOTIONPLAN_STOPDISTANCE_QUE_Enum0;



struct MOTIONPLAN_STOPDISTANCE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char STOPDISTANCE_QUE_subNUM = 23;
    unsigned char  U8_0_0;
    MOTIONPLAN_STOPDISTANCE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_STOPDISTANCE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_STOPDISTANCE_QUE* Add_ENUM0_1( MOTIONPLAN_STOPDISTANCE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPDISTANCE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_STOPTIME_Enum0
{
    MOTIONPLAN_STOPTIME_Enum0_MAIN,
    MOTIONPLAN_STOPTIME_Enum0_SMALL,
    MOTIONPLAN_STOPTIME_Enum0_P1,
    MOTIONPLAN_STOPTIME_Enum0_P2,
    MOTIONPLAN_STOPTIME_Enum0_P3,
    MOTIONPLAN_STOPTIME_Enum0_P4,
    MOTIONPLAN_STOPTIME_Enum0_P5,
    MOTIONPLAN_STOPTIME_Enum0_P6,
    MOTIONPLAN_STOPTIME_Enum0_P7,
    MOTIONPLAN_STOPTIME_Enum0_P8,
}MOTIONPLAN_STOPTIME_Enum0;



struct MOTIONPLAN_STOPTIME
{
    int MOTIONPLAN_mainNUM = 53;
    char STOPTIME_subNUM = 24;
    unsigned char  U8_0_0;
    MOTIONPLAN_STOPTIME_Enum0  ENUM0_1;
    float  F32_0_2;

    struct MOTIONPLAN_STOPTIME* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_STOPTIME* Add_ENUM0_1( MOTIONPLAN_STOPTIME_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_STOPTIME* Add_F32_0_2( float param )
    {
        F32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPTIME_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrF32_0_2 = (char *) &F32_0_2 ;
        cmdData.cmdData[4] = *( ptrF32_0_2++);
        cmdData.cmdData[5] = *( ptrF32_0_2++);
        cmdData.cmdData[6] = *( ptrF32_0_2++);
        cmdData.cmdData[7] = *( ptrF32_0_2++);
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_STOPTIME_QUE_Enum0
{
    MOTIONPLAN_STOPTIME_QUE_Enum0_MAIN,
    MOTIONPLAN_STOPTIME_QUE_Enum0_SMALL,
    MOTIONPLAN_STOPTIME_QUE_Enum0_P1,
    MOTIONPLAN_STOPTIME_QUE_Enum0_P2,
    MOTIONPLAN_STOPTIME_QUE_Enum0_P3,
    MOTIONPLAN_STOPTIME_QUE_Enum0_P4,
    MOTIONPLAN_STOPTIME_QUE_Enum0_P5,
    MOTIONPLAN_STOPTIME_QUE_Enum0_P6,
    MOTIONPLAN_STOPTIME_QUE_Enum0_P7,
    MOTIONPLAN_STOPTIME_QUE_Enum0_P8,
}MOTIONPLAN_STOPTIME_QUE_Enum0;



struct MOTIONPLAN_STOPTIME_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char STOPTIME_QUE_subNUM = 25;
    unsigned char  U8_0_0;
    MOTIONPLAN_STOPTIME_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_STOPTIME_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_STOPTIME_QUE* Add_ENUM0_1( MOTIONPLAN_STOPTIME_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPTIME_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_OOSLINESTATE_Enum0
{
    MOTIONPLAN_OOSLINESTATE_Enum0_MAIN,
    MOTIONPLAN_OOSLINESTATE_Enum0_SMALL,
    MOTIONPLAN_OOSLINESTATE_Enum0_P1,
    MOTIONPLAN_OOSLINESTATE_Enum0_P2,
    MOTIONPLAN_OOSLINESTATE_Enum0_P3,
    MOTIONPLAN_OOSLINESTATE_Enum0_P4,
    MOTIONPLAN_OOSLINESTATE_Enum0_P5,
    MOTIONPLAN_OOSLINESTATE_Enum0_P6,
    MOTIONPLAN_OOSLINESTATE_Enum0_P7,
    MOTIONPLAN_OOSLINESTATE_Enum0_P8,
}MOTIONPLAN_OOSLINESTATE_Enum0;

typedef enum MOTIONPLAN_OOSLINESTATE_Enum1
{
    MOTIONPLAN_OOSLINESTATE_Enum1_OFF,
    MOTIONPLAN_OOSLINESTATE_Enum1_ON,
}MOTIONPLAN_OOSLINESTATE_Enum1;



struct MOTIONPLAN_OOSLINESTATE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSLINESTATE_subNUM = 26;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSLINESTATE_Enum0  ENUM0_1;
    MOTIONPLAN_OOSLINESTATE_Enum1  ENUM1_2;

    struct MOTIONPLAN_OOSLINESTATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSLINESTATE* Add_ENUM0_1( MOTIONPLAN_OOSLINESTATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSLINESTATE* Add_ENUM1_2( MOTIONPLAN_OOSLINESTATE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSLINESTATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_OOSLINESTATE_QUE_Enum0
{
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_MAIN,
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_SMALL,
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_P1,
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_P2,
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_P3,
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_P4,
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_P5,
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_P6,
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_P7,
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0_P8,
}MOTIONPLAN_OOSLINESTATE_QUE_Enum0;



struct MOTIONPLAN_OOSLINESTATE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSLINESTATE_QUE_subNUM = 27;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSLINESTATE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_OOSLINESTATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSLINESTATE_QUE* Add_ENUM0_1( MOTIONPLAN_OOSLINESTATE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSLINESTATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_OOSLINEOUTNUM_Enum0
{
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_MAIN,
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_SMALL,
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_P1,
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_P2,
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_P3,
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_P4,
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_P5,
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_P6,
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_P7,
    MOTIONPLAN_OOSLINEOUTNUM_Enum0_P8,
}MOTIONPLAN_OOSLINEOUTNUM_Enum0;



struct MOTIONPLAN_OOSLINEOUTNUM
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSLINEOUTNUM_subNUM = 28;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSLINEOUTNUM_Enum0  ENUM0_1;
    unsigned short  U16_0_2;

    struct MOTIONPLAN_OOSLINEOUTNUM* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSLINEOUTNUM* Add_ENUM0_1( MOTIONPLAN_OOSLINEOUTNUM_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSLINEOUTNUM* Add_U16_0_2( unsigned short param )
    {
        U16_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSLINEOUTNUM_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU16_0_2 = (char *) &U16_0_2 ;
        cmdData.cmdData[4] = *( ptrU16_0_2++);
        cmdData.cmdData[5] = *( ptrU16_0_2++);
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0
{
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_MAIN,
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_SMALL,
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_P1,
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_P2,
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_P3,
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_P4,
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_P5,
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_P6,
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_P7,
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0_P8,
}MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0;



struct MOTIONPLAN_OOSLINEOUTNUM_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSLINEOUTNUM_QUE_subNUM = 29;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_OOSLINEOUTNUM_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSLINEOUTNUM_QUE* Add_ENUM0_1( MOTIONPLAN_OOSLINEOUTNUM_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSLINEOUTNUM_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_OOSLINERESPONSE_Enum0
{
    MOTIONPLAN_OOSLINERESPONSE_Enum0_MAIN,
    MOTIONPLAN_OOSLINERESPONSE_Enum0_SMALL,
    MOTIONPLAN_OOSLINERESPONSE_Enum0_P1,
    MOTIONPLAN_OOSLINERESPONSE_Enum0_P2,
    MOTIONPLAN_OOSLINERESPONSE_Enum0_P3,
    MOTIONPLAN_OOSLINERESPONSE_Enum0_P4,
    MOTIONPLAN_OOSLINERESPONSE_Enum0_P5,
    MOTIONPLAN_OOSLINERESPONSE_Enum0_P6,
    MOTIONPLAN_OOSLINERESPONSE_Enum0_P7,
    MOTIONPLAN_OOSLINERESPONSE_Enum0_P8,
}MOTIONPLAN_OOSLINERESPONSE_Enum0;

typedef enum MOTIONPLAN_OOSLINERESPONSE_Enum1
{
    MOTIONPLAN_OOSLINERESPONSE_Enum1_NONE,
    MOTIONPLAN_OOSLINERESPONSE_Enum1_ALARM,
    MOTIONPLAN_OOSLINERESPONSE_Enum1_STOP,
    MOTIONPLAN_OOSLINERESPONSE_Enum1_ALARM_STOP,
}MOTIONPLAN_OOSLINERESPONSE_Enum1;



struct MOTIONPLAN_OOSLINERESPONSE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSLINERESPONSE_subNUM = 30;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSLINERESPONSE_Enum0  ENUM0_1;
    MOTIONPLAN_OOSLINERESPONSE_Enum1  ENUM1_2;

    struct MOTIONPLAN_OOSLINERESPONSE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSLINERESPONSE* Add_ENUM0_1( MOTIONPLAN_OOSLINERESPONSE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSLINERESPONSE* Add_ENUM1_2( MOTIONPLAN_OOSLINERESPONSE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSLINERESPONSE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0
{
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_MAIN,
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_SMALL,
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_P1,
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_P2,
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_P3,
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_P4,
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_P5,
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_P6,
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_P7,
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0_P8,
}MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0;



struct MOTIONPLAN_OOSLINERESPONSE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSLINERESPONSE_QUE_subNUM = 31;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_OOSLINERESPONSE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSLINERESPONSE_QUE* Add_ENUM0_1( MOTIONPLAN_OOSLINERESPONSE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSLINERESPONSE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_OOSTOTALSTATE_Enum0
{
    MOTIONPLAN_OOSTOTALSTATE_Enum0_MAIN,
    MOTIONPLAN_OOSTOTALSTATE_Enum0_SMALL,
    MOTIONPLAN_OOSTOTALSTATE_Enum0_P1,
    MOTIONPLAN_OOSTOTALSTATE_Enum0_P2,
    MOTIONPLAN_OOSTOTALSTATE_Enum0_P3,
    MOTIONPLAN_OOSTOTALSTATE_Enum0_P4,
    MOTIONPLAN_OOSTOTALSTATE_Enum0_P5,
    MOTIONPLAN_OOSTOTALSTATE_Enum0_P6,
    MOTIONPLAN_OOSTOTALSTATE_Enum0_P7,
    MOTIONPLAN_OOSTOTALSTATE_Enum0_P8,
}MOTIONPLAN_OOSTOTALSTATE_Enum0;

typedef enum MOTIONPLAN_OOSTOTALSTATE_Enum1
{
    MOTIONPLAN_OOSTOTALSTATE_Enum1_OFF,
    MOTIONPLAN_OOSTOTALSTATE_Enum1_ON,
}MOTIONPLAN_OOSTOTALSTATE_Enum1;



struct MOTIONPLAN_OOSTOTALSTATE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSTOTALSTATE_subNUM = 32;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSTOTALSTATE_Enum0  ENUM0_1;
    MOTIONPLAN_OOSTOTALSTATE_Enum1  ENUM1_2;

    struct MOTIONPLAN_OOSTOTALSTATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSTOTALSTATE* Add_ENUM0_1( MOTIONPLAN_OOSTOTALSTATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSTOTALSTATE* Add_ENUM1_2( MOTIONPLAN_OOSTOTALSTATE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSTOTALSTATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0
{
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_MAIN,
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_SMALL,
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_P1,
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_P2,
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_P3,
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_P4,
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_P5,
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_P6,
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_P7,
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0_P8,
}MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0;



struct MOTIONPLAN_OOSTOTALSTATE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSTOTALSTATE_QUE_subNUM = 33;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_OOSTOTALSTATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSTOTALSTATE_QUE* Add_ENUM0_1( MOTIONPLAN_OOSTOTALSTATE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSTOTALSTATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_OOSTOTALOUTNUM_Enum0
{
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_MAIN,
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_SMALL,
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_P1,
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_P2,
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_P3,
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_P4,
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_P5,
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_P6,
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_P7,
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0_P8,
}MOTIONPLAN_OOSTOTALOUTNUM_Enum0;



struct MOTIONPLAN_OOSTOTALOUTNUM
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSTOTALOUTNUM_subNUM = 34;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSTOTALOUTNUM_Enum0  ENUM0_1;
    unsigned int  U32_0_2;

    struct MOTIONPLAN_OOSTOTALOUTNUM* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSTOTALOUTNUM* Add_ENUM0_1( MOTIONPLAN_OOSTOTALOUTNUM_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSTOTALOUTNUM* Add_U32_0_2( unsigned int param )
    {
        U32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSTOTALOUTNUM_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU32_0_2 = (char *) &U32_0_2 ;
        cmdData.cmdData[4] = *( ptrU32_0_2++);
        cmdData.cmdData[5] = *( ptrU32_0_2++);
        cmdData.cmdData[6] = *( ptrU32_0_2++);
        cmdData.cmdData[7] = *( ptrU32_0_2++);
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0
{
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_MAIN,
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_SMALL,
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_P1,
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_P2,
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_P3,
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_P4,
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_P5,
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_P6,
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_P7,
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0_P8,
}MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0;



struct MOTIONPLAN_OOSTOTALOUTNUM_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSTOTALOUTNUM_QUE_subNUM = 35;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_OOSTOTALOUTNUM_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSTOTALOUTNUM_QUE* Add_ENUM0_1( MOTIONPLAN_OOSTOTALOUTNUM_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSTOTALOUTNUM_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_OOSTOTALRESPONSE_Enum0
{
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_MAIN,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_SMALL,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_P1,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_P2,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_P3,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_P4,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_P5,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_P6,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_P7,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0_P8,
}MOTIONPLAN_OOSTOTALRESPONSE_Enum0;

typedef enum MOTIONPLAN_OOSTOTALRESPONSE_Enum1
{
    MOTIONPLAN_OOSTOTALRESPONSE_Enum1_NONE,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum1_ALARM,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum1_STOP,
    MOTIONPLAN_OOSTOTALRESPONSE_Enum1_ALARM_STOP,
}MOTIONPLAN_OOSTOTALRESPONSE_Enum1;



struct MOTIONPLAN_OOSTOTALRESPONSE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSTOTALRESPONSE_subNUM = 36;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSTOTALRESPONSE_Enum0  ENUM0_1;
    MOTIONPLAN_OOSTOTALRESPONSE_Enum1  ENUM1_2;

    struct MOTIONPLAN_OOSTOTALRESPONSE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSTOTALRESPONSE* Add_ENUM0_1( MOTIONPLAN_OOSTOTALRESPONSE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSTOTALRESPONSE* Add_ENUM1_2( MOTIONPLAN_OOSTOTALRESPONSE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSTOTALRESPONSE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0
{
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_MAIN,
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_SMALL,
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_P1,
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_P2,
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_P3,
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_P4,
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_P5,
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_P6,
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_P7,
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0_P8,
}MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0;



struct MOTIONPLAN_OOSTOTALRESPONSE_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char OOSTOTALRESPONSE_QUE_subNUM = 37;
    unsigned char  U8_0_0;
    MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_OOSTOTALRESPONSE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_OOSTOTALRESPONSE_QUE* Add_ENUM0_1( MOTIONPLAN_OOSTOTALRESPONSE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (OOSTOTALRESPONSE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum MOTIONPLAN_FIFOBUFFERTIME_Enum0
{
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_MAIN,
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_SMALL,
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_P1,
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_P2,
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_P3,
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_P4,
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_P5,
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_P6,
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_P7,
    MOTIONPLAN_FIFOBUFFERTIME_Enum0_P8,
}MOTIONPLAN_FIFOBUFFERTIME_Enum0;



struct MOTIONPLAN_FIFOBUFFERTIME
{
    int MOTIONPLAN_mainNUM = 53;
    char FIFOBUFFERTIME_subNUM = 38;
    unsigned char  U8_0_0;
    MOTIONPLAN_FIFOBUFFERTIME_Enum0  ENUM0_1;
    unsigned int  U32_0_2;

    struct MOTIONPLAN_FIFOBUFFERTIME* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_FIFOBUFFERTIME* Add_ENUM0_1( MOTIONPLAN_FIFOBUFFERTIME_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct MOTIONPLAN_FIFOBUFFERTIME* Add_U32_0_2( unsigned int param )
    {
        U32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FIFOBUFFERTIME_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU32_0_2 = (char *) &U32_0_2 ;
        cmdData.cmdData[4] = *( ptrU32_0_2++);
        cmdData.cmdData[5] = *( ptrU32_0_2++);
        cmdData.cmdData[6] = *( ptrU32_0_2++);
        cmdData.cmdData[7] = *( ptrU32_0_2++);
        return cmdData ;
    }

};
typedef enum MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0
{
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_MAIN,
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_SMALL,
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_P1,
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_P2,
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_P3,
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_P4,
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_P5,
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_P6,
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_P7,
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0_P8,
}MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0;



struct MOTIONPLAN_FIFOBUFFERTIME_QUE
{
    int MOTIONPLAN_mainNUM = 53;
    char FIFOBUFFERTIME_QUE_subNUM = 39;
    unsigned char  U8_0_0;
    MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0  ENUM0_1;

    struct MOTIONPLAN_FIFOBUFFERTIME_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct MOTIONPLAN_FIFOBUFFERTIME_QUE* Add_ENUM0_1( MOTIONPLAN_FIFOBUFFERTIME_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (MOTIONPLAN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FIFOBUFFERTIME_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct motionplan
{
    int  MOTIONPLAN_NUM = 53;
    struct MOTIONPLAN_PVTCONFIG  PVTCONFIG;
    struct MOTIONPLAN_PVTCONFIG_QUE  PVTCONFIG_QUE;
    struct MOTIONPLAN_PRESETSTATE  PRESETSTATE;
    struct MOTIONPLAN_PRESETSTATE_QUE  PRESETSTATE_QUE;
    struct MOTIONPLAN_EXECUTEMODE  EXECUTEMODE;
    struct MOTIONPLAN_EXECUTEMODE_QUE  EXECUTEMODE_QUE;
    struct MOTIONPLAN_PLANMODE  PLANMODE;
    struct MOTIONPLAN_PLANMODE_QUE  PLANMODE_QUE;
    struct MOTIONPLAN_MOTIONMODE  MOTIONMODE;
    struct MOTIONPLAN_MOTIONMODE_QUE  MOTIONMODE_QUE;
    struct MOTIONPLAN_MODIFYDUTY  MODIFYDUTY;
    struct MOTIONPLAN_MODIFYDUTY_QUE  MODIFYDUTY_QUE;
    struct MOTIONPLAN_REMAINPOINT_QUE  REMAINPOINT_QUE;
    struct MOTIONPLAN_CYCLENUM  CYCLENUM;
    struct MOTIONPLAN_CYCLENUM_QUE  CYCLENUM_QUE;
    struct MOTIONPLAN_WARNPOINT  WARNPOINT;
    struct MOTIONPLAN_WARNPOINT_QUE  WARNPOINT_QUE;
    struct MOTIONPLAN_ENDSTATE  ENDSTATE;
    struct MOTIONPLAN_ENDSTATE_QUE  ENDSTATE_QUE;
    struct MOTIONPLAN_BUFFERSIZE_QUE  BUFFERSIZE_QUE;
    struct MOTIONPLAN_STOPMODE  STOPMODE;
    struct MOTIONPLAN_STOPMODE_QUE  STOPMODE_QUE;
    struct MOTIONPLAN_STOPDISTANCE  STOPDISTANCE;
    struct MOTIONPLAN_STOPDISTANCE_QUE  STOPDISTANCE_QUE;
    struct MOTIONPLAN_STOPTIME  STOPTIME;
    struct MOTIONPLAN_STOPTIME_QUE  STOPTIME_QUE;
    struct MOTIONPLAN_OOSLINESTATE  OOSLINESTATE;
    struct MOTIONPLAN_OOSLINESTATE_QUE  OOSLINESTATE_QUE;
    struct MOTIONPLAN_OOSLINEOUTNUM  OOSLINEOUTNUM;
    struct MOTIONPLAN_OOSLINEOUTNUM_QUE  OOSLINEOUTNUM_QUE;
    struct MOTIONPLAN_OOSLINERESPONSE  OOSLINERESPONSE;
    struct MOTIONPLAN_OOSLINERESPONSE_QUE  OOSLINERESPONSE_QUE;
    struct MOTIONPLAN_OOSTOTALSTATE  OOSTOTALSTATE;
    struct MOTIONPLAN_OOSTOTALSTATE_QUE  OOSTOTALSTATE_QUE;
    struct MOTIONPLAN_OOSTOTALOUTNUM  OOSTOTALOUTNUM;
    struct MOTIONPLAN_OOSTOTALOUTNUM_QUE  OOSTOTALOUTNUM_QUE;
    struct MOTIONPLAN_OOSTOTALRESPONSE  OOSTOTALRESPONSE;
    struct MOTIONPLAN_OOSTOTALRESPONSE_QUE  OOSTOTALRESPONSE_QUE;
    struct MOTIONPLAN_FIFOBUFFERTIME  FIFOBUFFERTIME;
    struct MOTIONPLAN_FIFOBUFFERTIME_QUE  FIFOBUFFERTIME_QUE;

}motionplan;

typedef enum POSITION_POSITION_Enum0
{
    POSITION_POSITION_Enum0_MAIN,
    POSITION_POSITION_Enum0_SMALL,
    POSITION_POSITION_Enum0_P1,
    POSITION_POSITION_Enum0_P2,
    POSITION_POSITION_Enum0_P3,
    POSITION_POSITION_Enum0_P4,
    POSITION_POSITION_Enum0_P5,
    POSITION_POSITION_Enum0_P6,
    POSITION_POSITION_Enum0_P7,
    POSITION_POSITION_Enum0_P8,
}POSITION_POSITION_Enum0;



struct POSITION_POSITION
{
    int POSITION_mainNUM = 54;
    char POSITION_subNUM = -1;
    unsigned char  U8_0_0;
    POSITION_POSITION_Enum0  ENUM0_1;
    unsigned char  U8_1_2;
    float  F32_0_3;

    struct POSITION_POSITION* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct POSITION_POSITION* Add_ENUM0_1( POSITION_POSITION_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct POSITION_POSITION* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct POSITION_POSITION* Add_F32_0_3( float param )
    {
        F32_0_3 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (POSITION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (POSITION_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        char * ptrF32_0_3 = (char *) &F32_0_3 ;
        cmdData.cmdData[5] = *( ptrF32_0_3++);
        cmdData.cmdData[6] = *( ptrF32_0_3++);
        cmdData.cmdData[7] = *( ptrF32_0_3++);
        cmdData.cmdData[8] = *( ptrF32_0_3++);
        return cmdData ;
    }

};

/*****************************************************/
typedef struct position
{
    int  POSITION_NUM = 54;
    struct POSITION_POSITION  POSITION;

}position;

typedef enum POSITION_POSITION_QUE_Enum0
{
    POSITION_POSITION_QUE_Enum0_MAIN,
    POSITION_POSITION_QUE_Enum0_SMALL,
    POSITION_POSITION_QUE_Enum0_P1,
    POSITION_POSITION_QUE_Enum0_P2,
    POSITION_POSITION_QUE_Enum0_P3,
    POSITION_POSITION_QUE_Enum0_P4,
    POSITION_POSITION_QUE_Enum0_P5,
    POSITION_POSITION_QUE_Enum0_P6,
    POSITION_POSITION_QUE_Enum0_P7,
    POSITION_POSITION_QUE_Enum0_P8,
}POSITION_POSITION_QUE_Enum0;



struct POSITION_POSITION_QUE
{
    int POSITION_mainNUM = 55;
    char POSITION_QUE_subNUM = -1;
    unsigned char  U8_0_0;
    POSITION_POSITION_QUE_Enum0  ENUM0_1;
    unsigned char  U8_1_2;

    struct POSITION_POSITION_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct POSITION_POSITION_QUE* Add_ENUM0_1( POSITION_POSITION_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct POSITION_POSITION_QUE* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (POSITION_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (POSITION_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        return cmdData ;
    }

};

/*****************************************************/
typedef struct position_que
{
    int  POSITION_QUE_NUM = 55;
    struct POSITION_POSITION_QUE  POSITION_QUE;

}position_que;

typedef enum VELOCITY_VELOCITY_Enum0
{
    VELOCITY_VELOCITY_Enum0_MAIN,
    VELOCITY_VELOCITY_Enum0_SMALL,
    VELOCITY_VELOCITY_Enum0_P1,
    VELOCITY_VELOCITY_Enum0_P2,
    VELOCITY_VELOCITY_Enum0_P3,
    VELOCITY_VELOCITY_Enum0_P4,
    VELOCITY_VELOCITY_Enum0_P5,
    VELOCITY_VELOCITY_Enum0_P6,
    VELOCITY_VELOCITY_Enum0_P7,
    VELOCITY_VELOCITY_Enum0_P8,
}VELOCITY_VELOCITY_Enum0;



struct VELOCITY_VELOCITY
{
    int VELOCITY_mainNUM = 56;
    char VELOCITY_subNUM = -1;
    unsigned char  U8_0_0;
    VELOCITY_VELOCITY_Enum0  ENUM0_1;
    unsigned char  U8_1_2;
    float  F32_0_3;

    struct VELOCITY_VELOCITY* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct VELOCITY_VELOCITY* Add_ENUM0_1( VELOCITY_VELOCITY_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct VELOCITY_VELOCITY* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct VELOCITY_VELOCITY* Add_F32_0_3( float param )
    {
        F32_0_3 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (VELOCITY_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (VELOCITY_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        char * ptrF32_0_3 = (char *) &F32_0_3 ;
        cmdData.cmdData[5] = *( ptrF32_0_3++);
        cmdData.cmdData[6] = *( ptrF32_0_3++);
        cmdData.cmdData[7] = *( ptrF32_0_3++);
        cmdData.cmdData[8] = *( ptrF32_0_3++);
        return cmdData ;
    }

};

/*****************************************************/
typedef struct velocity
{
    int  VELOCITY_NUM = 56;
    struct VELOCITY_VELOCITY  VELOCITY;

}velocity;

typedef enum VELOCITY_VELOCITY_QUE_Enum0
{
    VELOCITY_VELOCITY_QUE_Enum0_MAIN,
    VELOCITY_VELOCITY_QUE_Enum0_SMALL,
    VELOCITY_VELOCITY_QUE_Enum0_P1,
    VELOCITY_VELOCITY_QUE_Enum0_P2,
    VELOCITY_VELOCITY_QUE_Enum0_P3,
    VELOCITY_VELOCITY_QUE_Enum0_P4,
    VELOCITY_VELOCITY_QUE_Enum0_P5,
    VELOCITY_VELOCITY_QUE_Enum0_P6,
    VELOCITY_VELOCITY_QUE_Enum0_P7,
    VELOCITY_VELOCITY_QUE_Enum0_P8,
}VELOCITY_VELOCITY_QUE_Enum0;



struct VELOCITY_VELOCITY_QUE
{
    int VELOCITY_mainNUM = 57;
    char VELOCITY_QUE_subNUM = -1;
    unsigned char  U8_0_0;
    VELOCITY_VELOCITY_QUE_Enum0  ENUM0_1;
    unsigned char  U8_1_2;

    struct VELOCITY_VELOCITY_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct VELOCITY_VELOCITY_QUE* Add_ENUM0_1( VELOCITY_VELOCITY_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct VELOCITY_VELOCITY_QUE* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (VELOCITY_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (VELOCITY_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        return cmdData ;
    }

};

/*****************************************************/
typedef struct velocity_que
{
    int  VELOCITY_QUE_NUM = 57;
    struct VELOCITY_VELOCITY_QUE  VELOCITY_QUE;

}velocity_que;

typedef enum TIME_TIME_Enum0
{
    TIME_TIME_Enum0_MAIN,
    TIME_TIME_Enum0_SMALL,
    TIME_TIME_Enum0_P1,
    TIME_TIME_Enum0_P2,
    TIME_TIME_Enum0_P3,
    TIME_TIME_Enum0_P4,
    TIME_TIME_Enum0_P5,
    TIME_TIME_Enum0_P6,
    TIME_TIME_Enum0_P7,
    TIME_TIME_Enum0_P8,
}TIME_TIME_Enum0;



struct TIME_TIME
{
    int TIME_mainNUM = 58;
    char TIME_subNUM = -1;
    unsigned char  U8_0_0;
    TIME_TIME_Enum0  ENUM0_1;
    unsigned char  U8_1_2;
    float  F32_0_3;

    struct TIME_TIME* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TIME_TIME* Add_ENUM0_1( TIME_TIME_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TIME_TIME* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct TIME_TIME* Add_F32_0_3( float param )
    {
        F32_0_3 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TIME_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TIME_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        char * ptrF32_0_3 = (char *) &F32_0_3 ;
        cmdData.cmdData[5] = *( ptrF32_0_3++);
        cmdData.cmdData[6] = *( ptrF32_0_3++);
        cmdData.cmdData[7] = *( ptrF32_0_3++);
        cmdData.cmdData[8] = *( ptrF32_0_3++);
        return cmdData ;
    }

};

/*****************************************************/
typedef struct time
{
    int  TIME_NUM = 58;
    struct TIME_TIME  TIME;

}time;

typedef enum TIME_TIME_QUE_Enum0
{
    TIME_TIME_QUE_Enum0_MAIN,
    TIME_TIME_QUE_Enum0_SMALL,
    TIME_TIME_QUE_Enum0_P1,
    TIME_TIME_QUE_Enum0_P2,
    TIME_TIME_QUE_Enum0_P3,
    TIME_TIME_QUE_Enum0_P4,
    TIME_TIME_QUE_Enum0_P5,
    TIME_TIME_QUE_Enum0_P6,
    TIME_TIME_QUE_Enum0_P7,
    TIME_TIME_QUE_Enum0_P8,
}TIME_TIME_QUE_Enum0;



struct TIME_TIME_QUE
{
    int TIME_mainNUM = 59;
    char TIME_QUE_subNUM = -1;
    unsigned char  U8_0_0;
    TIME_TIME_QUE_Enum0  ENUM0_1;
    unsigned char  U8_1_2;

    struct TIME_TIME_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TIME_TIME_QUE* Add_ENUM0_1( TIME_TIME_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TIME_TIME_QUE* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TIME_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TIME_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        return cmdData ;
    }

};

/*****************************************************/
typedef struct time_que
{
    int  TIME_QUE_NUM = 59;
    struct TIME_TIME_QUE  TIME_QUE;

}time_que;

typedef enum TIMESCALE_TIMESCALE_Enum0
{
    TIMESCALE_TIMESCALE_Enum0_MAIN,
    TIMESCALE_TIMESCALE_Enum0_SMALL,
    TIMESCALE_TIMESCALE_Enum0_P1,
    TIMESCALE_TIMESCALE_Enum0_P2,
    TIMESCALE_TIMESCALE_Enum0_P3,
    TIMESCALE_TIMESCALE_Enum0_P4,
    TIMESCALE_TIMESCALE_Enum0_P5,
    TIMESCALE_TIMESCALE_Enum0_P6,
    TIMESCALE_TIMESCALE_Enum0_P7,
    TIMESCALE_TIMESCALE_Enum0_P8,
}TIMESCALE_TIMESCALE_Enum0;



struct TIMESCALE_TIMESCALE
{
    int TIMESCALE_mainNUM = 60;
    char TIMESCALE_subNUM = -1;
    unsigned char  U8_0_0;
    TIMESCALE_TIMESCALE_Enum0  ENUM0_1;
    unsigned char  U8_1_2;
    unsigned short  U16_0_3;
    unsigned short  U16_1_4;

    struct TIMESCALE_TIMESCALE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TIMESCALE_TIMESCALE* Add_ENUM0_1( TIMESCALE_TIMESCALE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TIMESCALE_TIMESCALE* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct TIMESCALE_TIMESCALE* Add_U16_0_3( unsigned short param )
    {
        U16_0_3 = param ;
        return this ;
    }

    struct TIMESCALE_TIMESCALE* Add_U16_1_4( unsigned short param )
    {
        U16_1_4 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TIMESCALE_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TIMESCALE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        char * ptrU16_0_3 = (char *) &U16_0_3 ;
        cmdData.cmdData[5] = *( ptrU16_0_3++);
        cmdData.cmdData[6] = *( ptrU16_0_3++);
        char * ptrU16_1_4 = (char *) &U16_1_4 ;
        cmdData.cmdData[7] = *( ptrU16_1_4++);
        cmdData.cmdData[8] = *( ptrU16_1_4++);
        return cmdData ;
    }

};

/*****************************************************/
typedef struct timescale
{
    int  TIMESCALE_NUM = 60;
    struct TIMESCALE_TIMESCALE  TIMESCALE;

}timescale;

typedef enum TIMESCALE_TIMESCALE_QUE_Enum0
{
    TIMESCALE_TIMESCALE_QUE_Enum0_MAIN,
    TIMESCALE_TIMESCALE_QUE_Enum0_SMALL,
    TIMESCALE_TIMESCALE_QUE_Enum0_P1,
    TIMESCALE_TIMESCALE_QUE_Enum0_P2,
    TIMESCALE_TIMESCALE_QUE_Enum0_P3,
    TIMESCALE_TIMESCALE_QUE_Enum0_P4,
    TIMESCALE_TIMESCALE_QUE_Enum0_P5,
    TIMESCALE_TIMESCALE_QUE_Enum0_P6,
    TIMESCALE_TIMESCALE_QUE_Enum0_P7,
    TIMESCALE_TIMESCALE_QUE_Enum0_P8,
}TIMESCALE_TIMESCALE_QUE_Enum0;



struct TIMESCALE_TIMESCALE_QUE
{
    int TIMESCALE_mainNUM = 61;
    char TIMESCALE_QUE_subNUM = -1;
    unsigned char  U8_0_0;
    TIMESCALE_TIMESCALE_QUE_Enum0  ENUM0_1;
    unsigned char  U8_1_2;

    struct TIMESCALE_TIMESCALE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TIMESCALE_TIMESCALE_QUE* Add_ENUM0_1( TIMESCALE_TIMESCALE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TIMESCALE_TIMESCALE_QUE* Add_U8_1_2( unsigned char param )
    {
        U8_1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TIMESCALE_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TIMESCALE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU8_1_2 = (char *) &U8_1_2 ;
        cmdData.cmdData[4] = *( ptrU8_1_2++);
        return cmdData ;
    }

};

/*****************************************************/
typedef struct timescale_que
{
    int  TIMESCALE_QUE_NUM = 61;
    struct TIMESCALE_TIMESCALE_QUE  TIMESCALE_QUE;

}timescale_que;

typedef enum REPORT_STATE_Enum0
{
    REPORT_STATE_Enum0_TORQUE,
    REPORT_STATE_Enum0_CYCLE,
    REPORT_STATE_Enum0_SGALL,
    REPORT_STATE_Enum0_SGSE,
    REPORT_STATE_Enum0_DIST,
    REPORT_STATE_Enum0_ABSENC,
}REPORT_STATE_Enum0;

typedef enum REPORT_STATE_Enum1
{
    REPORT_STATE_Enum1_OFF,
    REPORT_STATE_Enum1_ON,
}REPORT_STATE_Enum1;



struct REPORT_STATE
{
    int REPORT_mainNUM = 70;
    char STATE_subNUM = 0;
    unsigned char  U8_0_0;
    REPORT_STATE_Enum0  ENUM0_1;
    REPORT_STATE_Enum1  ENUM1_2;

    struct REPORT_STATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct REPORT_STATE* Add_ENUM0_1( REPORT_STATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct REPORT_STATE* Add_ENUM1_2( REPORT_STATE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (REPORT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum REPORT_STATE_QUE_Enum0
{
    REPORT_STATE_QUE_Enum0_TORQUE,
    REPORT_STATE_QUE_Enum0_CYCLE,
    REPORT_STATE_QUE_Enum0_SGALL,
    REPORT_STATE_QUE_Enum0_SGSE,
    REPORT_STATE_QUE_Enum0_DIST,
    REPORT_STATE_QUE_Enum0_ABSENC,
}REPORT_STATE_QUE_Enum0;



struct REPORT_STATE_QUE
{
    int REPORT_mainNUM = 70;
    char STATE_QUE_subNUM = 1;
    unsigned char  U8_0_0;
    REPORT_STATE_QUE_Enum0  ENUM0_1;

    struct REPORT_STATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct REPORT_STATE_QUE* Add_ENUM0_1( REPORT_STATE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (REPORT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum REPORT_PERIOD_Enum0
{
    REPORT_PERIOD_Enum0_TORQUE,
    REPORT_PERIOD_Enum0_CYCLE,
    REPORT_PERIOD_Enum0_SGALL,
    REPORT_PERIOD_Enum0_SGSE,
    REPORT_PERIOD_Enum0_DIST,
    REPORT_PERIOD_Enum0_ABSENC,
}REPORT_PERIOD_Enum0;



struct REPORT_PERIOD
{
    int REPORT_mainNUM = 70;
    char PERIOD_subNUM = 2;
    unsigned char  U8_0_0;
    REPORT_PERIOD_Enum0  ENUM0_1;
    unsigned int  U32_0_2;

    struct REPORT_PERIOD* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct REPORT_PERIOD* Add_ENUM0_1( REPORT_PERIOD_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct REPORT_PERIOD* Add_U32_0_2( unsigned int param )
    {
        U32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (REPORT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PERIOD_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU32_0_2 = (char *) &U32_0_2 ;
        cmdData.cmdData[4] = *( ptrU32_0_2++);
        cmdData.cmdData[5] = *( ptrU32_0_2++);
        cmdData.cmdData[6] = *( ptrU32_0_2++);
        cmdData.cmdData[7] = *( ptrU32_0_2++);
        return cmdData ;
    }

};
typedef enum REPORT_PERIOD_QUE_Enum0
{
    REPORT_PERIOD_QUE_Enum0_TORQUE,
    REPORT_PERIOD_QUE_Enum0_CYCLE,
    REPORT_PERIOD_QUE_Enum0_SGALL,
    REPORT_PERIOD_QUE_Enum0_SGSE,
    REPORT_PERIOD_QUE_Enum0_DIST,
    REPORT_PERIOD_QUE_Enum0_ABSENC,
}REPORT_PERIOD_QUE_Enum0;



struct REPORT_PERIOD_QUE
{
    int REPORT_mainNUM = 70;
    char PERIOD_QUE_subNUM = 3;
    unsigned char  U8_0_0;
    REPORT_PERIOD_QUE_Enum0  ENUM0_1;

    struct REPORT_PERIOD_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct REPORT_PERIOD_QUE* Add_ENUM0_1( REPORT_PERIOD_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (REPORT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PERIOD_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum REPORT_DATA_QUE_Enum0
{
    REPORT_DATA_QUE_Enum0_TORQUE,
    REPORT_DATA_QUE_Enum0_CYCLE,
    REPORT_DATA_QUE_Enum0_SGALL,
    REPORT_DATA_QUE_Enum0_SGSE,
    REPORT_DATA_QUE_Enum0_DIST,
    REPORT_DATA_QUE_Enum0_ABSENC,
}REPORT_DATA_QUE_Enum0;



struct REPORT_DATA_QUE
{
    int REPORT_mainNUM = 70;
    char DATA_QUE_subNUM = 4;
    unsigned char  U8_0_0;
    REPORT_DATA_QUE_Enum0  ENUM0_1;

    struct REPORT_DATA_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct REPORT_DATA_QUE* Add_ENUM0_1( REPORT_DATA_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (REPORT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DATA_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct report
{
    int  REPORT_NUM = 70;
    struct REPORT_STATE  STATE;
    struct REPORT_STATE_QUE  STATE_QUE;
    struct REPORT_PERIOD  PERIOD;
    struct REPORT_PERIOD_QUE  PERIOD_QUE;
    struct REPORT_DATA_QUE  DATA_QUE;

}report;

typedef enum TRIGGER_MODE_Enum0
{
    TRIGGER_MODE_Enum0_PATTERN,
    TRIGGER_MODE_Enum0_LEVEL,
}TRIGGER_MODE_Enum0;



struct TRIGGER_MODE
{
    int TRIGGER_mainNUM = 71;
    char MODE_subNUM = 0;
    unsigned char  U8_0_0;
    TRIGGER_MODE_Enum0  ENUM0_1;

    struct TRIGGER_MODE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_MODE* Add_ENUM0_1( TRIGGER_MODE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MODE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct TRIGGER_MODE_QUE
{
    int TRIGGER_mainNUM = 71;
    char MODE_QUE_subNUM = 1;
    unsigned char  U8_0_0;

    struct TRIGGER_MODE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MODE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TRIGGER_PATTSTATE_Enum0
{
    TRIGGER_PATTSTATE_Enum0_OFF,
    TRIGGER_PATTSTATE_Enum0_ON,
}TRIGGER_PATTSTATE_Enum0;



struct TRIGGER_PATTSTATE
{
    int TRIGGER_mainNUM = 71;
    char PATTSTATE_subNUM = 2;
    unsigned char  U8_0_0;
    TRIGGER_PATTSTATE_Enum0  ENUM0_1;

    struct TRIGGER_PATTSTATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_PATTSTATE* Add_ENUM0_1( TRIGGER_PATTSTATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTSTATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct TRIGGER_PATTSTATE_QUE
{
    int TRIGGER_mainNUM = 71;
    char PATTSTATE_QUE_subNUM = 3;
    unsigned char  U8_0_0;

    struct TRIGGER_PATTSTATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTSTATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TRIGGER_PATTERN_Enum0
{
    TRIGGER_PATTERN_Enum0_X,
    TRIGGER_PATTERN_Enum0_L,
    TRIGGER_PATTERN_Enum0_R,
    TRIGGER_PATTERN_Enum0_F,
    TRIGGER_PATTERN_Enum0_H,
}TRIGGER_PATTERN_Enum0;

typedef enum TRIGGER_PATTERN_Enum1
{
    TRIGGER_PATTERN_Enum1_X,
    TRIGGER_PATTERN_Enum1_L,
    TRIGGER_PATTERN_Enum1_R,
    TRIGGER_PATTERN_Enum1_F,
    TRIGGER_PATTERN_Enum1_H,
}TRIGGER_PATTERN_Enum1;



struct TRIGGER_PATTERN
{
    int TRIGGER_mainNUM = 71;
    char PATTERN_subNUM = 4;
    unsigned char  U8_0_0;
    TRIGGER_PATTERN_Enum0  ENUM0_1;
    TRIGGER_PATTERN_Enum1  ENUM1_2;

    struct TRIGGER_PATTERN* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_PATTERN* Add_ENUM0_1( TRIGGER_PATTERN_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TRIGGER_PATTERN* Add_ENUM1_2( TRIGGER_PATTERN_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTERN_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};


struct TRIGGER_PATTERN_QUE
{
    int TRIGGER_mainNUM = 71;
    char PATTERN_QUE_subNUM = 5;
    unsigned char  U8_0_0;

    struct TRIGGER_PATTERN_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTERN_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TRIGGER_PATTRESP_Enum0
{
    TRIGGER_PATTRESP_Enum0_NONE,
    TRIGGER_PATTRESP_Enum0_ALARM,
    TRIGGER_PATTRESP_Enum0_STOP,
    TRIGGER_PATTRESP_Enum0_ALARM_STOP,
}TRIGGER_PATTRESP_Enum0;



struct TRIGGER_PATTRESP
{
    int TRIGGER_mainNUM = 71;
    char PATTRESP_subNUM = 6;
    unsigned char  U8_0_0;
    TRIGGER_PATTRESP_Enum0  ENUM0_1;

    struct TRIGGER_PATTRESP* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_PATTRESP* Add_ENUM0_1( TRIGGER_PATTRESP_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTRESP_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct TRIGGER_PATTRESP_QUE
{
    int TRIGGER_mainNUM = 71;
    char PATTRESP_QUE_subNUM = 7;
    unsigned char  U8_0_0;

    struct TRIGGER_PATTRESP_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTRESP_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TRIGGER_PATTSMODE_Enum0
{
    TRIGGER_PATTSMODE_Enum0_CONTINUED,
    TRIGGER_PATTSMODE_Enum0_INTERVAL,
    TRIGGER_PATTSMODE_Enum0_SINGLE,
}TRIGGER_PATTSMODE_Enum0;



struct TRIGGER_PATTSMODE
{
    int TRIGGER_mainNUM = 71;
    char PATTSMODE_subNUM = 8;
    unsigned char  U8_0_0;
    TRIGGER_PATTSMODE_Enum0  ENUM0_1;

    struct TRIGGER_PATTSMODE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_PATTSMODE* Add_ENUM0_1( TRIGGER_PATTSMODE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTSMODE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct TRIGGER_PATTSMODE_QUE
{
    int TRIGGER_mainNUM = 71;
    char PATTSMODE_QUE_subNUM = 9;
    unsigned char  U8_0_0;

    struct TRIGGER_PATTSMODE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTSMODE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct TRIGGER_PATTSPERIOD
{
    int TRIGGER_mainNUM = 71;
    char PATTSPERIOD_subNUM = 10;
    unsigned char  U8_0_0;
    unsigned int  U32_0_1;

    struct TRIGGER_PATTSPERIOD* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_PATTSPERIOD* Add_U32_0_1( unsigned int param )
    {
        U32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTSPERIOD_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU32_0_1 = (char *) &U32_0_1 ;
        cmdData.cmdData[3] = *( ptrU32_0_1++);
        cmdData.cmdData[4] = *( ptrU32_0_1++);
        cmdData.cmdData[5] = *( ptrU32_0_1++);
        cmdData.cmdData[6] = *( ptrU32_0_1++);
        return cmdData ;
    }

};


struct TRIGGER_PATTSPERIOD_QUE
{
    int TRIGGER_mainNUM = 71;
    char PATTSPERIOD_QUE_subNUM = 11;
    unsigned char  U8_0_0;

    struct TRIGGER_PATTSPERIOD_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PATTSPERIOD_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TRIGGER_LEVELSTATE_Enum0
{
    TRIGGER_LEVELSTATE_Enum0_TRIGL,
    TRIGGER_LEVELSTATE_Enum0_TRIGR,
}TRIGGER_LEVELSTATE_Enum0;

typedef enum TRIGGER_LEVELSTATE_Enum1
{
    TRIGGER_LEVELSTATE_Enum1_OFF,
    TRIGGER_LEVELSTATE_Enum1_ON,
}TRIGGER_LEVELSTATE_Enum1;



struct TRIGGER_LEVELSTATE
{
    int TRIGGER_mainNUM = 71;
    char LEVELSTATE_subNUM = 12;
    unsigned char  U8_0_0;
    TRIGGER_LEVELSTATE_Enum0  ENUM0_1;
    TRIGGER_LEVELSTATE_Enum1  ENUM1_2;

    struct TRIGGER_LEVELSTATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELSTATE* Add_ENUM0_1( TRIGGER_LEVELSTATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TRIGGER_LEVELSTATE* Add_ENUM1_2( TRIGGER_LEVELSTATE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELSTATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum TRIGGER_LEVELSTATE_QUE_Enum0
{
    TRIGGER_LEVELSTATE_QUE_Enum0_TRIGL,
    TRIGGER_LEVELSTATE_QUE_Enum0_TRIGR,
}TRIGGER_LEVELSTATE_QUE_Enum0;



struct TRIGGER_LEVELSTATE_QUE
{
    int TRIGGER_mainNUM = 71;
    char LEVELSTATE_QUE_subNUM = 13;
    unsigned char  U8_0_0;
    TRIGGER_LEVELSTATE_QUE_Enum0  ENUM0_1;

    struct TRIGGER_LEVELSTATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELSTATE_QUE* Add_ENUM0_1( TRIGGER_LEVELSTATE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELSTATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TRIGGER_LEVELTYPE_Enum0
{
    TRIGGER_LEVELTYPE_Enum0_TRIGL,
    TRIGGER_LEVELTYPE_Enum0_TRIGR,
}TRIGGER_LEVELTYPE_Enum0;

typedef enum TRIGGER_LEVELTYPE_Enum1
{
    TRIGGER_LEVELTYPE_Enum1_RESERVE,
    TRIGGER_LEVELTYPE_Enum1_LOW,
    TRIGGER_LEVELTYPE_Enum1_RISE,
    TRIGGER_LEVELTYPE_Enum1_FALL,
    TRIGGER_LEVELTYPE_Enum1_HIGH,
}TRIGGER_LEVELTYPE_Enum1;



struct TRIGGER_LEVELTYPE
{
    int TRIGGER_mainNUM = 71;
    char LEVELTYPE_subNUM = 14;
    unsigned char  U8_0_0;
    TRIGGER_LEVELTYPE_Enum0  ENUM0_1;
    TRIGGER_LEVELTYPE_Enum1  ENUM1_2;

    struct TRIGGER_LEVELTYPE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELTYPE* Add_ENUM0_1( TRIGGER_LEVELTYPE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TRIGGER_LEVELTYPE* Add_ENUM1_2( TRIGGER_LEVELTYPE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELTYPE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum TRIGGER_LEVELTYPE_QUE_Enum0
{
    TRIGGER_LEVELTYPE_QUE_Enum0_TRIGL,
    TRIGGER_LEVELTYPE_QUE_Enum0_TRIGR,
}TRIGGER_LEVELTYPE_QUE_Enum0;



struct TRIGGER_LEVELTYPE_QUE
{
    int TRIGGER_mainNUM = 71;
    char LEVELTYPE_QUE_subNUM = 15;
    unsigned char  U8_0_0;
    TRIGGER_LEVELTYPE_QUE_Enum0  ENUM0_1;

    struct TRIGGER_LEVELTYPE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELTYPE_QUE* Add_ENUM0_1( TRIGGER_LEVELTYPE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELTYPE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TRIGGER_LEVELRESP_Enum0
{
    TRIGGER_LEVELRESP_Enum0_TRIGL,
    TRIGGER_LEVELRESP_Enum0_TRIGR,
}TRIGGER_LEVELRESP_Enum0;

typedef enum TRIGGER_LEVELRESP_Enum1
{
    TRIGGER_LEVELRESP_Enum1_NONE,
    TRIGGER_LEVELRESP_Enum1_ALARM,
    TRIGGER_LEVELRESP_Enum1_STOP,
    TRIGGER_LEVELRESP_Enum1_ALARM_STOP,
}TRIGGER_LEVELRESP_Enum1;



struct TRIGGER_LEVELRESP
{
    int TRIGGER_mainNUM = 71;
    char LEVELRESP_subNUM = 16;
    unsigned char  U8_0_0;
    TRIGGER_LEVELRESP_Enum0  ENUM0_1;
    TRIGGER_LEVELRESP_Enum1  ENUM1_2;

    struct TRIGGER_LEVELRESP* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELRESP* Add_ENUM0_1( TRIGGER_LEVELRESP_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TRIGGER_LEVELRESP* Add_ENUM1_2( TRIGGER_LEVELRESP_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELRESP_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum TRIGGER_LEVELRESP_QUE_Enum0
{
    TRIGGER_LEVELRESP_QUE_Enum0_TRIGL,
    TRIGGER_LEVELRESP_QUE_Enum0_TRIGR,
}TRIGGER_LEVELRESP_QUE_Enum0;



struct TRIGGER_LEVELRESP_QUE
{
    int TRIGGER_mainNUM = 71;
    char LEVELRESP_QUE_subNUM = 17;
    unsigned char  U8_0_0;
    TRIGGER_LEVELRESP_QUE_Enum0  ENUM0_1;

    struct TRIGGER_LEVELRESP_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELRESP_QUE* Add_ENUM0_1( TRIGGER_LEVELRESP_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELRESP_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TRIGGER_LEVELSMODE_Enum0
{
    TRIGGER_LEVELSMODE_Enum0_TRIGL,
    TRIGGER_LEVELSMODE_Enum0_TRIGR,
}TRIGGER_LEVELSMODE_Enum0;

typedef enum TRIGGER_LEVELSMODE_Enum1
{
    TRIGGER_LEVELSMODE_Enum1_CONTINUED,
    TRIGGER_LEVELSMODE_Enum1_INTERVAL,
    TRIGGER_LEVELSMODE_Enum1_SINGLE,
}TRIGGER_LEVELSMODE_Enum1;



struct TRIGGER_LEVELSMODE
{
    int TRIGGER_mainNUM = 71;
    char LEVELSMODE_subNUM = 18;
    unsigned char  U8_0_0;
    TRIGGER_LEVELSMODE_Enum0  ENUM0_1;
    TRIGGER_LEVELSMODE_Enum1  ENUM1_2;

    struct TRIGGER_LEVELSMODE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELSMODE* Add_ENUM0_1( TRIGGER_LEVELSMODE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TRIGGER_LEVELSMODE* Add_ENUM1_2( TRIGGER_LEVELSMODE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELSMODE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};
typedef enum TRIGGER_LEVELSMODE_QUE_Enum0
{
    TRIGGER_LEVELSMODE_QUE_Enum0_TRIGL,
    TRIGGER_LEVELSMODE_QUE_Enum0_TRIGR,
}TRIGGER_LEVELSMODE_QUE_Enum0;



struct TRIGGER_LEVELSMODE_QUE
{
    int TRIGGER_mainNUM = 71;
    char LEVELSMODE_QUE_subNUM = 19;
    unsigned char  U8_0_0;
    TRIGGER_LEVELSMODE_QUE_Enum0  ENUM0_1;

    struct TRIGGER_LEVELSMODE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELSMODE_QUE* Add_ENUM0_1( TRIGGER_LEVELSMODE_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELSMODE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TRIGGER_LEVELSPERIOD_Enum0
{
    TRIGGER_LEVELSPERIOD_Enum0_TRIGL,
    TRIGGER_LEVELSPERIOD_Enum0_TRIGR,
}TRIGGER_LEVELSPERIOD_Enum0;



struct TRIGGER_LEVELSPERIOD
{
    int TRIGGER_mainNUM = 71;
    char LEVELSPERIOD_subNUM = 20;
    unsigned char  U8_0_0;
    TRIGGER_LEVELSPERIOD_Enum0  ENUM0_1;
    float  F32_0_2;

    struct TRIGGER_LEVELSPERIOD* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELSPERIOD* Add_ENUM0_1( TRIGGER_LEVELSPERIOD_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TRIGGER_LEVELSPERIOD* Add_F32_0_2( float param )
    {
        F32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELSPERIOD_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrF32_0_2 = (char *) &F32_0_2 ;
        cmdData.cmdData[4] = *( ptrF32_0_2++);
        cmdData.cmdData[5] = *( ptrF32_0_2++);
        cmdData.cmdData[6] = *( ptrF32_0_2++);
        cmdData.cmdData[7] = *( ptrF32_0_2++);
        return cmdData ;
    }

};
typedef enum TRIGGER_LEVELSPERIOD_QUE_Enum0
{
    TRIGGER_LEVELSPERIOD_QUE_Enum0_TRIGL,
    TRIGGER_LEVELSPERIOD_QUE_Enum0_TRIGR,
}TRIGGER_LEVELSPERIOD_QUE_Enum0;



struct TRIGGER_LEVELSPERIOD_QUE
{
    int TRIGGER_mainNUM = 71;
    char LEVELSPERIOD_QUE_subNUM = 21;
    unsigned char  U8_0_0;
    TRIGGER_LEVELSPERIOD_QUE_Enum0  ENUM0_1;

    struct TRIGGER_LEVELSPERIOD_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TRIGGER_LEVELSPERIOD_QUE* Add_ENUM0_1( TRIGGER_LEVELSPERIOD_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TRIGGER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (LEVELSPERIOD_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    float analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            float * floatValue = (float *)tmp; 
            return * floatValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct trigger
{
    int  TRIGGER_NUM = 71;
    struct TRIGGER_MODE  MODE;
    struct TRIGGER_MODE_QUE  MODE_QUE;
    struct TRIGGER_PATTSTATE  PATTSTATE;
    struct TRIGGER_PATTSTATE_QUE  PATTSTATE_QUE;
    struct TRIGGER_PATTERN  PATTERN;
    struct TRIGGER_PATTERN_QUE  PATTERN_QUE;
    struct TRIGGER_PATTRESP  PATTRESP;
    struct TRIGGER_PATTRESP_QUE  PATTRESP_QUE;
    struct TRIGGER_PATTSMODE  PATTSMODE;
    struct TRIGGER_PATTSMODE_QUE  PATTSMODE_QUE;
    struct TRIGGER_PATTSPERIOD  PATTSPERIOD;
    struct TRIGGER_PATTSPERIOD_QUE  PATTSPERIOD_QUE;
    struct TRIGGER_LEVELSTATE  LEVELSTATE;
    struct TRIGGER_LEVELSTATE_QUE  LEVELSTATE_QUE;
    struct TRIGGER_LEVELTYPE  LEVELTYPE;
    struct TRIGGER_LEVELTYPE_QUE  LEVELTYPE_QUE;
    struct TRIGGER_LEVELRESP  LEVELRESP;
    struct TRIGGER_LEVELRESP_QUE  LEVELRESP_QUE;
    struct TRIGGER_LEVELSMODE  LEVELSMODE;
    struct TRIGGER_LEVELSMODE_QUE  LEVELSMODE_QUE;
    struct TRIGGER_LEVELSPERIOD  LEVELSPERIOD;
    struct TRIGGER_LEVELSPERIOD_QUE  LEVELSPERIOD_QUE;

}trigger;



struct DRIVER_TYPE_QUE
{
    int DRIVER_mainNUM = 72;
    char TYPE_QUE_subNUM = 0;
    unsigned char  U8_0_0;

    struct DRIVER_TYPE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DRIVER_STATEREG_QUE_Enum0
{
    DRIVER_STATEREG_QUE_Enum0_R0,
    DRIVER_STATEREG_QUE_Enum0_R1,
    DRIVER_STATEREG_QUE_Enum0_R2,
}DRIVER_STATEREG_QUE_Enum0;



struct DRIVER_STATEREG_QUE
{
    int DRIVER_mainNUM = 72;
    char STATEREG_QUE_subNUM = 1;
    unsigned char  U8_0_0;
    DRIVER_STATEREG_QUE_Enum0  ENUM0_1;

    struct DRIVER_STATEREG_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_STATEREG_QUE* Add_ENUM0_1( DRIVER_STATEREG_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATEREG_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct DRIVER_CURRENT
{
    int DRIVER_mainNUM = 72;
    char CURRENT_subNUM = 2;
    unsigned char  U8_0_0;
    unsigned char  U8_1_1;

    struct DRIVER_CURRENT* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_CURRENT* Add_U8_1_1( unsigned char param )
    {
        U8_1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CURRENT_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU8_1_1 = (char *) &U8_1_1 ;
        cmdData.cmdData[3] = *( ptrU8_1_1++);
        return cmdData ;
    }

};


struct DRIVER_CURRENT_QUE
{
    int DRIVER_mainNUM = 72;
    char CURRENT_QUE_subNUM = 3;
    unsigned char  U8_0_0;

    struct DRIVER_CURRENT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CURRENT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_1_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DRIVER_MICROSTEPS_Enum0
{
    DRIVER_MICROSTEPS_Enum0_RESERVE0,
    DRIVER_MICROSTEPS_Enum0_RESERVE1,
    DRIVER_MICROSTEPS_Enum0_64,
    DRIVER_MICROSTEPS_Enum0_32,
    DRIVER_MICROSTEPS_Enum0_16,
    DRIVER_MICROSTEPS_Enum0_8,
    DRIVER_MICROSTEPS_Enum0_4,
    DRIVER_MICROSTEPS_Enum0_2,
    DRIVER_MICROSTEPS_Enum0_1,
}DRIVER_MICROSTEPS_Enum0;



struct DRIVER_MICROSTEPS
{
    int DRIVER_mainNUM = 72;
    char MICROSTEPS_subNUM = 4;
    unsigned char  U8_0_0;
    DRIVER_MICROSTEPS_Enum0  ENUM0_1;

    struct DRIVER_MICROSTEPS* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_MICROSTEPS* Add_ENUM0_1( DRIVER_MICROSTEPS_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MICROSTEPS_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct DRIVER_MICROSTEPS_QUE
{
    int DRIVER_mainNUM = 72;
    char MICROSTEPS_QUE_subNUM = 5;
    unsigned char  U8_0_0;

    struct DRIVER_MICROSTEPS_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MICROSTEPS_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DRIVER_STATE_Enum0
{
    DRIVER_STATE_Enum0_OFF,
    DRIVER_STATE_Enum0_ON,
}DRIVER_STATE_Enum0;



struct DRIVER_STATE
{
    int DRIVER_mainNUM = 72;
    char STATE_subNUM = 6;
    unsigned char  U8_0_0;
    DRIVER_STATE_Enum0  ENUM0_1;

    struct DRIVER_STATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_STATE* Add_ENUM0_1( DRIVER_STATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct DRIVER_STATE_QUE
{
    int DRIVER_mainNUM = 72;
    char STATE_QUE_subNUM = 7;
    unsigned char  U8_0_0;

    struct DRIVER_STATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DRIVER_SGLIMIT_Enum0
{
    DRIVER_SGLIMIT_Enum0_UPLIMIT,
    DRIVER_SGLIMIT_Enum0_DOWNLIMIT,
}DRIVER_SGLIMIT_Enum0;



struct DRIVER_SGLIMIT
{
    int DRIVER_mainNUM = 72;
    char SGLIMIT_subNUM = 8;
    unsigned char  U8_0_0;
    DRIVER_SGLIMIT_Enum0  ENUM0_1;
    char  S8_0_2;

    struct DRIVER_SGLIMIT* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_SGLIMIT* Add_ENUM0_1( DRIVER_SGLIMIT_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct DRIVER_SGLIMIT* Add_S8_0_2( char param )
    {
        S8_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SGLIMIT_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrS8_0_2 = (char *) &S8_0_2 ;
        cmdData.cmdData[4] = *( ptrS8_0_2++);
        return cmdData ;
    }

};


struct DRIVER_SGLIMIT_QUE
{
    int DRIVER_mainNUM = 72;
    char SGLIMIT_QUE_subNUM = 9;
    unsigned char  U8_0_0;

    struct DRIVER_SGLIMIT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SGLIMIT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    char analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            char * charValue = (char *)tmp; 
            return * charValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DRIVER_SGPARASET_Enum0
{
    DRIVER_SGPARASET_Enum0_SG0,
    DRIVER_SGPARASET_Enum0_SGT,
    DRIVER_SGPARASET_Enum0_SEMAX,
    DRIVER_SGPARASET_Enum0_SEMIN,
}DRIVER_SGPARASET_Enum0;



struct DRIVER_SGPARASET
{
    int DRIVER_mainNUM = 72;
    char SGPARASET_subNUM = 10;
    unsigned char  U8_0_0;
    DRIVER_SGPARASET_Enum0  ENUM0_1;
    short  S16_0_2;

    struct DRIVER_SGPARASET* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_SGPARASET* Add_ENUM0_1( DRIVER_SGPARASET_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct DRIVER_SGPARASET* Add_S16_0_2( short param )
    {
        S16_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SGPARASET_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrS16_0_2 = (char *) &S16_0_2 ;
        cmdData.cmdData[4] = *( ptrS16_0_2++);
        return cmdData ;
    }

};
typedef enum DRIVER_SGPARASET_QUE_Enum0
{
    DRIVER_SGPARASET_QUE_Enum0_SG0,
    DRIVER_SGPARASET_QUE_Enum0_SGT,
    DRIVER_SGPARASET_QUE_Enum0_SEMAX,
    DRIVER_SGPARASET_QUE_Enum0_SEMIN,
}DRIVER_SGPARASET_QUE_Enum0;



struct DRIVER_SGPARASET_QUE
{
    int DRIVER_mainNUM = 72;
    char SGPARASET_QUE_subNUM = 11;
    unsigned char  U8_0_0;
    DRIVER_SGPARASET_QUE_Enum0  ENUM0_1;

    struct DRIVER_SGPARASET_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_SGPARASET_QUE* Add_ENUM0_1( DRIVER_SGPARASET_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SGPARASET_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    short analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            short * shortValue = (short *)tmp; 
            return * shortValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct DRIVER_IDLECURRENT
{
    int DRIVER_mainNUM = 72;
    char IDLECURRENT_subNUM = 12;
    unsigned char  U8_0_0;
    unsigned char  U8_1_1;

    struct DRIVER_IDLECURRENT* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_IDLECURRENT* Add_U8_1_1( unsigned char param )
    {
        U8_1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (IDLECURRENT_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU8_1_1 = (char *) &U8_1_1 ;
        cmdData.cmdData[3] = *( ptrU8_1_1++);
        return cmdData ;
    }

};


struct DRIVER_IDLECURRENT_QUE
{
    int DRIVER_mainNUM = 72;
    char IDLECURRENT_QUE_subNUM = 13;
    unsigned char  U8_0_0;

    struct DRIVER_IDLECURRENT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (IDLECURRENT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_1_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct DRIVER_SWITCHTIME
{
    int DRIVER_mainNUM = 72;
    char SWITCHTIME_subNUM = 14;
    unsigned char  U8_0_0;
    unsigned int  U32_0_1;

    struct DRIVER_SWITCHTIME* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_SWITCHTIME* Add_U32_0_1( unsigned int param )
    {
        U32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SWITCHTIME_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU32_0_1 = (char *) &U32_0_1 ;
        cmdData.cmdData[3] = *( ptrU32_0_1++);
        cmdData.cmdData[4] = *( ptrU32_0_1++);
        cmdData.cmdData[5] = *( ptrU32_0_1++);
        cmdData.cmdData[6] = *( ptrU32_0_1++);
        return cmdData ;
    }

};


struct DRIVER_SWITCHTIME_QUE
{
    int DRIVER_mainNUM = 72;
    char SWITCHTIME_QUE_subNUM = 15;
    unsigned char  U8_0_0;

    struct DRIVER_SWITCHTIME_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SWITCHTIME_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DRIVER_MINICURRRATIO_Enum0
{
    DRIVER_MINICURRRATIO_Enum0_1f2,
    DRIVER_MINICURRRATIO_Enum0_1f4,
}DRIVER_MINICURRRATIO_Enum0;



struct DRIVER_MINICURRRATIO
{
    int DRIVER_mainNUM = 72;
    char MINICURRRATIO_subNUM = 16;
    unsigned char  U8_0_0;
    DRIVER_MINICURRRATIO_Enum0  ENUM0_1;

    struct DRIVER_MINICURRRATIO* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_MINICURRRATIO* Add_ENUM0_1( DRIVER_MINICURRRATIO_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINICURRRATIO_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct DRIVER_MINICURRRATIO_QUE
{
    int DRIVER_mainNUM = 72;
    char MINICURRRATIO_QUE_subNUM = 17;
    unsigned char  U8_0_0;

    struct DRIVER_MINICURRRATIO_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINICURRRATIO_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DRIVER_REGCONFIG_Enum0
{
    DRIVER_REGCONFIG_Enum0_DRVCTRL,
    DRIVER_REGCONFIG_Enum0_CHOPCONF,
    DRIVER_REGCONFIG_Enum0_SMARTEN,
    DRIVER_REGCONFIG_Enum0_SGCSCONF,
    DRIVER_REGCONFIG_Enum0_DRVCONF,
}DRIVER_REGCONFIG_Enum0;



struct DRIVER_REGCONFIG
{
    int DRIVER_mainNUM = 72;
    char REGCONFIG_subNUM = 18;
    unsigned char  U8_0_0;
    DRIVER_REGCONFIG_Enum0  ENUM0_1;
    unsigned int  U32_0_2;

    struct DRIVER_REGCONFIG* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_REGCONFIG* Add_ENUM0_1( DRIVER_REGCONFIG_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct DRIVER_REGCONFIG* Add_U32_0_2( unsigned int param )
    {
        U32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (REGCONFIG_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        char * ptrU32_0_2 = (char *) &U32_0_2 ;
        cmdData.cmdData[4] = *( ptrU32_0_2++);
        cmdData.cmdData[5] = *( ptrU32_0_2++);
        cmdData.cmdData[6] = *( ptrU32_0_2++);
        cmdData.cmdData[7] = *( ptrU32_0_2++);
        return cmdData ;
    }

};
typedef enum DRIVER_REGCONFIG_QUE_Enum0
{
    DRIVER_REGCONFIG_QUE_Enum0_DRVCTRL,
    DRIVER_REGCONFIG_QUE_Enum0_CHOPCONF,
    DRIVER_REGCONFIG_QUE_Enum0_SMARTEN,
    DRIVER_REGCONFIG_QUE_Enum0_SGCSCONF,
    DRIVER_REGCONFIG_QUE_Enum0_DRVCONF,
}DRIVER_REGCONFIG_QUE_Enum0;



struct DRIVER_REGCONFIG_QUE
{
    int DRIVER_mainNUM = 72;
    char REGCONFIG_QUE_subNUM = 19;
    unsigned char  U8_0_0;
    DRIVER_REGCONFIG_QUE_Enum0  ENUM0_1;

    struct DRIVER_REGCONFIG_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct DRIVER_REGCONFIG_QUE* Add_ENUM0_1( DRIVER_REGCONFIG_QUE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (REGCONFIG_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct driver
{
    int  DRIVER_NUM = 72;
    struct DRIVER_TYPE_QUE  TYPE_QUE;
    struct DRIVER_STATEREG_QUE  STATEREG_QUE;
    struct DRIVER_CURRENT  CURRENT;
    struct DRIVER_CURRENT_QUE  CURRENT_QUE;
    struct DRIVER_MICROSTEPS  MICROSTEPS;
    struct DRIVER_MICROSTEPS_QUE  MICROSTEPS_QUE;
    struct DRIVER_STATE  STATE;
    struct DRIVER_STATE_QUE  STATE_QUE;
    struct DRIVER_SGLIMIT  SGLIMIT;
    struct DRIVER_SGLIMIT_QUE  SGLIMIT_QUE;
    struct DRIVER_SGPARASET  SGPARASET;
    struct DRIVER_SGPARASET_QUE  SGPARASET_QUE;
    struct DRIVER_IDLECURRENT  IDLECURRENT;
    struct DRIVER_IDLECURRENT_QUE  IDLECURRENT_QUE;
    struct DRIVER_SWITCHTIME  SWITCHTIME;
    struct DRIVER_SWITCHTIME_QUE  SWITCHTIME_QUE;
    struct DRIVER_MINICURRRATIO  MINICURRRATIO;
    struct DRIVER_MINICURRRATIO_QUE  MINICURRRATIO_QUE;
    struct DRIVER_REGCONFIG  REGCONFIG;
    struct DRIVER_REGCONFIG_QUE  REGCONFIG_QUE;

}driver;

typedef enum DIGITALOUTPUT_STATE_Enum0
{
    DIGITALOUTPUT_STATE_Enum0_DO1,
    DIGITALOUTPUT_STATE_Enum0_DO2,
    DIGITALOUTPUT_STATE_Enum0_DO3,
    DIGITALOUTPUT_STATE_Enum0_DO4,
}DIGITALOUTPUT_STATE_Enum0;

typedef enum DIGITALOUTPUT_STATE_Enum1
{
    DIGITALOUTPUT_STATE_Enum1_DISABLE,
    DIGITALOUTPUT_STATE_Enum1_ENABLE,
}DIGITALOUTPUT_STATE_Enum1;



struct DIGITALOUTPUT_STATE
{
    int DIGITALOUTPUT_mainNUM = 73;
    char STATE_subNUM = 0;
    DIGITALOUTPUT_STATE_Enum0  ENUM0_0;
    DIGITALOUTPUT_STATE_Enum1  ENUM1_1;

    struct DIGITALOUTPUT_STATE* Add_ENUM0_0( DIGITALOUTPUT_STATE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DIGITALOUTPUT_STATE* Add_ENUM1_1( DIGITALOUTPUT_STATE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum DIGITALOUTPUT_STATE_QUE_Enum0
{
    DIGITALOUTPUT_STATE_QUE_Enum0_DO1,
    DIGITALOUTPUT_STATE_QUE_Enum0_DO2,
    DIGITALOUTPUT_STATE_QUE_Enum0_DO3,
    DIGITALOUTPUT_STATE_QUE_Enum0_DO4,
}DIGITALOUTPUT_STATE_QUE_Enum0;



struct DIGITALOUTPUT_STATE_QUE
{
    int DIGITALOUTPUT_mainNUM = 73;
    char STATE_QUE_subNUM = 1;
    DIGITALOUTPUT_STATE_QUE_Enum0  ENUM0_0;

    struct DIGITALOUTPUT_STATE_QUE* Add_ENUM0_0( DIGITALOUTPUT_STATE_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DIGITALOUTPUT_SIGNAL_Enum0
{
    DIGITALOUTPUT_SIGNAL_Enum0_DO1,
    DIGITALOUTPUT_SIGNAL_Enum0_DO2,
    DIGITALOUTPUT_SIGNAL_Enum0_DO3,
    DIGITALOUTPUT_SIGNAL_Enum0_DO4,
}DIGITALOUTPUT_SIGNAL_Enum0;

typedef enum DIGITALOUTPUT_SIGNAL_Enum1
{
    DIGITALOUTPUT_SIGNAL_Enum1_LEVEL,
    DIGITALOUTPUT_SIGNAL_Enum1_NONE,
}DIGITALOUTPUT_SIGNAL_Enum1;



struct DIGITALOUTPUT_SIGNAL
{
    int DIGITALOUTPUT_mainNUM = 73;
    char SIGNAL_subNUM = 2;
    DIGITALOUTPUT_SIGNAL_Enum0  ENUM0_0;
    DIGITALOUTPUT_SIGNAL_Enum1  ENUM1_1;

    struct DIGITALOUTPUT_SIGNAL* Add_ENUM0_0( DIGITALOUTPUT_SIGNAL_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DIGITALOUTPUT_SIGNAL* Add_ENUM1_1( DIGITALOUTPUT_SIGNAL_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SIGNAL_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum DIGITALOUTPUT_SIGNAL_QUE_Enum0
{
    DIGITALOUTPUT_SIGNAL_QUE_Enum0_DO1,
    DIGITALOUTPUT_SIGNAL_QUE_Enum0_DO2,
    DIGITALOUTPUT_SIGNAL_QUE_Enum0_DO3,
    DIGITALOUTPUT_SIGNAL_QUE_Enum0_DO4,
}DIGITALOUTPUT_SIGNAL_QUE_Enum0;



struct DIGITALOUTPUT_SIGNAL_QUE
{
    int DIGITALOUTPUT_mainNUM = 73;
    char SIGNAL_QUE_subNUM = 3;
    DIGITALOUTPUT_SIGNAL_QUE_Enum0  ENUM0_0;

    struct DIGITALOUTPUT_SIGNAL_QUE* Add_ENUM0_0( DIGITALOUTPUT_SIGNAL_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SIGNAL_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DIGITALOUTPUT_POLARITY_Enum0
{
    DIGITALOUTPUT_POLARITY_Enum0_DO1,
    DIGITALOUTPUT_POLARITY_Enum0_DO2,
    DIGITALOUTPUT_POLARITY_Enum0_DO3,
    DIGITALOUTPUT_POLARITY_Enum0_DO4,
}DIGITALOUTPUT_POLARITY_Enum0;

typedef enum DIGITALOUTPUT_POLARITY_Enum1
{
    DIGITALOUTPUT_POLARITY_Enum1_POSITIVE,
    DIGITALOUTPUT_POLARITY_Enum1_NEGATIVE,
}DIGITALOUTPUT_POLARITY_Enum1;



struct DIGITALOUTPUT_POLARITY
{
    int DIGITALOUTPUT_mainNUM = 73;
    char POLARITY_subNUM = 4;
    DIGITALOUTPUT_POLARITY_Enum0  ENUM0_0;
    DIGITALOUTPUT_POLARITY_Enum1  ENUM1_1;

    struct DIGITALOUTPUT_POLARITY* Add_ENUM0_0( DIGITALOUTPUT_POLARITY_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DIGITALOUTPUT_POLARITY* Add_ENUM1_1( DIGITALOUTPUT_POLARITY_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (POLARITY_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum DIGITALOUTPUT_POLARITY_QUE_Enum0
{
    DIGITALOUTPUT_POLARITY_QUE_Enum0_DO1,
    DIGITALOUTPUT_POLARITY_QUE_Enum0_DO2,
    DIGITALOUTPUT_POLARITY_QUE_Enum0_DO3,
    DIGITALOUTPUT_POLARITY_QUE_Enum0_DO4,
}DIGITALOUTPUT_POLARITY_QUE_Enum0;



struct DIGITALOUTPUT_POLARITY_QUE
{
    int DIGITALOUTPUT_mainNUM = 73;
    char POLARITY_QUE_subNUM = 5;
    DIGITALOUTPUT_POLARITY_QUE_Enum0  ENUM0_0;

    struct DIGITALOUTPUT_POLARITY_QUE* Add_ENUM0_0( DIGITALOUTPUT_POLARITY_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (POLARITY_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DIGITALOUTPUT_SOURCE_Enum0
{
    DIGITALOUTPUT_SOURCE_Enum0_DO1,
    DIGITALOUTPUT_SOURCE_Enum0_DO2,
    DIGITALOUTPUT_SOURCE_Enum0_DO3,
    DIGITALOUTPUT_SOURCE_Enum0_DO4,
}DIGITALOUTPUT_SOURCE_Enum0;



struct DIGITALOUTPUT_SOURCE
{
    int DIGITALOUTPUT_mainNUM = 73;
    char SOURCE_subNUM = 6;
    DIGITALOUTPUT_SOURCE_Enum0  ENUM0_0;
    unsigned char  U8_0_1;

    struct DIGITALOUTPUT_SOURCE* Add_ENUM0_0( DIGITALOUTPUT_SOURCE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DIGITALOUTPUT_SOURCE* Add_U8_0_1( unsigned char param )
    {
        U8_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SOURCE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU8_0_1 = (char *) &U8_0_1 ;
        cmdData.cmdData[3] = *( ptrU8_0_1++);
        return cmdData ;
    }

};
typedef enum DIGITALOUTPUT_SOURCE_QUE_Enum0
{
    DIGITALOUTPUT_SOURCE_QUE_Enum0_DO1,
    DIGITALOUTPUT_SOURCE_QUE_Enum0_DO2,
    DIGITALOUTPUT_SOURCE_QUE_Enum0_DO3,
    DIGITALOUTPUT_SOURCE_QUE_Enum0_DO4,
}DIGITALOUTPUT_SOURCE_QUE_Enum0;



struct DIGITALOUTPUT_SOURCE_QUE
{
    int DIGITALOUTPUT_mainNUM = 73;
    char SOURCE_QUE_subNUM = 7;
    DIGITALOUTPUT_SOURCE_QUE_Enum0  ENUM0_0;

    struct DIGITALOUTPUT_SOURCE_QUE* Add_ENUM0_0( DIGITALOUTPUT_SOURCE_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SOURCE_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DIGITALOUTPUT_CONDITION_Enum0
{
    DIGITALOUTPUT_CONDITION_Enum0_DO1,
    DIGITALOUTPUT_CONDITION_Enum0_DO2,
    DIGITALOUTPUT_CONDITION_Enum0_DO3,
    DIGITALOUTPUT_CONDITION_Enum0_DO4,
}DIGITALOUTPUT_CONDITION_Enum0;

typedef enum DIGITALOUTPUT_CONDITION_Enum1
{
    DIGITALOUTPUT_CONDITION_Enum1_AUTO,
    DIGITALOUTPUT_CONDITION_Enum1_NONE,
}DIGITALOUTPUT_CONDITION_Enum1;



struct DIGITALOUTPUT_CONDITION
{
    int DIGITALOUTPUT_mainNUM = 73;
    char CONDITION_subNUM = 8;
    DIGITALOUTPUT_CONDITION_Enum0  ENUM0_0;
    DIGITALOUTPUT_CONDITION_Enum1  ENUM1_1;

    struct DIGITALOUTPUT_CONDITION* Add_ENUM0_0( DIGITALOUTPUT_CONDITION_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DIGITALOUTPUT_CONDITION* Add_ENUM1_1( DIGITALOUTPUT_CONDITION_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CONDITION_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum DIGITALOUTPUT_CONDITION_QUE_Enum0
{
    DIGITALOUTPUT_CONDITION_QUE_Enum0_DO1,
    DIGITALOUTPUT_CONDITION_QUE_Enum0_DO2,
    DIGITALOUTPUT_CONDITION_QUE_Enum0_DO3,
    DIGITALOUTPUT_CONDITION_QUE_Enum0_DO4,
}DIGITALOUTPUT_CONDITION_QUE_Enum0;



struct DIGITALOUTPUT_CONDITION_QUE
{
    int DIGITALOUTPUT_mainNUM = 73;
    char CONDITION_QUE_subNUM = 9;
    DIGITALOUTPUT_CONDITION_QUE_Enum0  ENUM0_0;

    struct DIGITALOUTPUT_CONDITION_QUE* Add_ENUM0_0( DIGITALOUTPUT_CONDITION_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CONDITION_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DIGITALOUTPUT_PERIOD_Enum0
{
    DIGITALOUTPUT_PERIOD_Enum0_DO1,
    DIGITALOUTPUT_PERIOD_Enum0_DO2,
    DIGITALOUTPUT_PERIOD_Enum0_DO3,
    DIGITALOUTPUT_PERIOD_Enum0_DO4,
}DIGITALOUTPUT_PERIOD_Enum0;



struct DIGITALOUTPUT_PERIOD
{
    int DIGITALOUTPUT_mainNUM = 73;
    char PERIOD_subNUM = 10;
    DIGITALOUTPUT_PERIOD_Enum0  ENUM0_0;
    unsigned int  U32_0_1;

    struct DIGITALOUTPUT_PERIOD* Add_ENUM0_0( DIGITALOUTPUT_PERIOD_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DIGITALOUTPUT_PERIOD* Add_U32_0_1( unsigned int param )
    {
        U32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PERIOD_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU32_0_1 = (char *) &U32_0_1 ;
        cmdData.cmdData[3] = *( ptrU32_0_1++);
        cmdData.cmdData[4] = *( ptrU32_0_1++);
        cmdData.cmdData[5] = *( ptrU32_0_1++);
        cmdData.cmdData[6] = *( ptrU32_0_1++);
        return cmdData ;
    }

};
typedef enum DIGITALOUTPUT_PERIOD_QUE_Enum0
{
    DIGITALOUTPUT_PERIOD_QUE_Enum0_DO1,
    DIGITALOUTPUT_PERIOD_QUE_Enum0_DO2,
    DIGITALOUTPUT_PERIOD_QUE_Enum0_DO3,
    DIGITALOUTPUT_PERIOD_QUE_Enum0_DO4,
}DIGITALOUTPUT_PERIOD_QUE_Enum0;



struct DIGITALOUTPUT_PERIOD_QUE
{
    int DIGITALOUTPUT_mainNUM = 73;
    char PERIOD_QUE_subNUM = 11;
    DIGITALOUTPUT_PERIOD_QUE_Enum0  ENUM0_0;

    struct DIGITALOUTPUT_PERIOD_QUE* Add_ENUM0_0( DIGITALOUTPUT_PERIOD_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PERIOD_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DIGITALOUTPUT_DUTY_Enum0
{
    DIGITALOUTPUT_DUTY_Enum0_DO1,
    DIGITALOUTPUT_DUTY_Enum0_DO2,
    DIGITALOUTPUT_DUTY_Enum0_DO3,
    DIGITALOUTPUT_DUTY_Enum0_DO4,
}DIGITALOUTPUT_DUTY_Enum0;



struct DIGITALOUTPUT_DUTY
{
    int DIGITALOUTPUT_mainNUM = 73;
    char DUTY_subNUM = 12;
    DIGITALOUTPUT_DUTY_Enum0  ENUM0_0;
    unsigned short  U16_0_1;

    struct DIGITALOUTPUT_DUTY* Add_ENUM0_0( DIGITALOUTPUT_DUTY_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DIGITALOUTPUT_DUTY* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DUTY_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        return cmdData ;
    }

};
typedef enum DIGITALOUTPUT_DUTY_QUE_Enum0
{
    DIGITALOUTPUT_DUTY_QUE_Enum0_DO1,
    DIGITALOUTPUT_DUTY_QUE_Enum0_DO2,
    DIGITALOUTPUT_DUTY_QUE_Enum0_DO3,
    DIGITALOUTPUT_DUTY_QUE_Enum0_DO4,
}DIGITALOUTPUT_DUTY_QUE_Enum0;



struct DIGITALOUTPUT_DUTY_QUE
{
    int DIGITALOUTPUT_mainNUM = 73;
    char DUTY_QUE_subNUM = 13;
    DIGITALOUTPUT_DUTY_QUE_Enum0  ENUM0_0;

    struct DIGITALOUTPUT_DUTY_QUE* Add_ENUM0_0( DIGITALOUTPUT_DUTY_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DIGITALOUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DUTY_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct digitaloutput
{
    int  DIGITALOUTPUT_NUM = 73;
    struct DIGITALOUTPUT_STATE  STATE;
    struct DIGITALOUTPUT_STATE_QUE  STATE_QUE;
    struct DIGITALOUTPUT_SIGNAL  SIGNAL;
    struct DIGITALOUTPUT_SIGNAL_QUE  SIGNAL_QUE;
    struct DIGITALOUTPUT_POLARITY  POLARITY;
    struct DIGITALOUTPUT_POLARITY_QUE  POLARITY_QUE;
    struct DIGITALOUTPUT_SOURCE  SOURCE;
    struct DIGITALOUTPUT_SOURCE_QUE  SOURCE_QUE;
    struct DIGITALOUTPUT_CONDITION  CONDITION;
    struct DIGITALOUTPUT_CONDITION_QUE  CONDITION_QUE;
    struct DIGITALOUTPUT_PERIOD  PERIOD;
    struct DIGITALOUTPUT_PERIOD_QUE  PERIOD_QUE;
    struct DIGITALOUTPUT_DUTY  DUTY;
    struct DIGITALOUTPUT_DUTY_QUE  DUTY_QUE;

}digitaloutput;

typedef enum ISOLATOROUTPUT_STATE_Enum0
{
    ISOLATOROUTPUT_STATE_Enum0_YO1,
    ISOLATOROUTPUT_STATE_Enum0_YO2,
}ISOLATOROUTPUT_STATE_Enum0;

typedef enum ISOLATOROUTPUT_STATE_Enum1
{
    ISOLATOROUTPUT_STATE_Enum1_DISABLE,
    ISOLATOROUTPUT_STATE_Enum1_ENABLE,
}ISOLATOROUTPUT_STATE_Enum1;



struct ISOLATOROUTPUT_STATE
{
    int ISOLATOROUTPUT_mainNUM = 74;
    char STATE_subNUM = 0;
    ISOLATOROUTPUT_STATE_Enum0  ENUM0_0;
    ISOLATOROUTPUT_STATE_Enum1  ENUM1_1;

    struct ISOLATOROUTPUT_STATE* Add_ENUM0_0( ISOLATOROUTPUT_STATE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct ISOLATOROUTPUT_STATE* Add_ENUM1_1( ISOLATOROUTPUT_STATE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATOROUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum ISOLATOROUTPUT_STATE_QUE_Enum0
{
    ISOLATOROUTPUT_STATE_QUE_Enum0_YO1,
    ISOLATOROUTPUT_STATE_QUE_Enum0_YO2,
}ISOLATOROUTPUT_STATE_QUE_Enum0;



struct ISOLATOROUTPUT_STATE_QUE
{
    int ISOLATOROUTPUT_mainNUM = 74;
    char STATE_QUE_subNUM = 1;
    ISOLATOROUTPUT_STATE_QUE_Enum0  ENUM0_0;

    struct ISOLATOROUTPUT_STATE_QUE* Add_ENUM0_0( ISOLATOROUTPUT_STATE_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATOROUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ISOLATOROUTPUT_SOURCE_Enum0
{
    ISOLATOROUTPUT_SOURCE_Enum0_YO1,
    ISOLATOROUTPUT_SOURCE_Enum0_YO2,
}ISOLATOROUTPUT_SOURCE_Enum0;



struct ISOLATOROUTPUT_SOURCE
{
    int ISOLATOROUTPUT_mainNUM = 74;
    char SOURCE_subNUM = 2;
    ISOLATOROUTPUT_SOURCE_Enum0  ENUM0_0;
    unsigned char  U8_0_1;

    struct ISOLATOROUTPUT_SOURCE* Add_ENUM0_0( ISOLATOROUTPUT_SOURCE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct ISOLATOROUTPUT_SOURCE* Add_U8_0_1( unsigned char param )
    {
        U8_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATOROUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SOURCE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU8_0_1 = (char *) &U8_0_1 ;
        cmdData.cmdData[3] = *( ptrU8_0_1++);
        return cmdData ;
    }

};
typedef enum ISOLATOROUTPUT_SOURCE_QUE_Enum0
{
    ISOLATOROUTPUT_SOURCE_QUE_Enum0_YO1,
    ISOLATOROUTPUT_SOURCE_QUE_Enum0_YO2,
}ISOLATOROUTPUT_SOURCE_QUE_Enum0;



struct ISOLATOROUTPUT_SOURCE_QUE
{
    int ISOLATOROUTPUT_mainNUM = 74;
    char SOURCE_QUE_subNUM = 3;
    ISOLATOROUTPUT_SOURCE_QUE_Enum0  ENUM0_0;

    struct ISOLATOROUTPUT_SOURCE_QUE* Add_ENUM0_0( ISOLATOROUTPUT_SOURCE_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATOROUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SOURCE_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ISOLATOROUTPUT_CONDITION_Enum0
{
    ISOLATOROUTPUT_CONDITION_Enum0_YO1,
    ISOLATOROUTPUT_CONDITION_Enum0_YO2,
}ISOLATOROUTPUT_CONDITION_Enum0;

typedef enum ISOLATOROUTPUT_CONDITION_Enum1
{
    ISOLATOROUTPUT_CONDITION_Enum1_AUTO,
    ISOLATOROUTPUT_CONDITION_Enum1_NONE,
}ISOLATOROUTPUT_CONDITION_Enum1;



struct ISOLATOROUTPUT_CONDITION
{
    int ISOLATOROUTPUT_mainNUM = 74;
    char CONDITION_subNUM = 4;
    ISOLATOROUTPUT_CONDITION_Enum0  ENUM0_0;
    ISOLATOROUTPUT_CONDITION_Enum1  ENUM1_1;

    struct ISOLATOROUTPUT_CONDITION* Add_ENUM0_0( ISOLATOROUTPUT_CONDITION_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct ISOLATOROUTPUT_CONDITION* Add_ENUM1_1( ISOLATOROUTPUT_CONDITION_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATOROUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CONDITION_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum ISOLATOROUTPUT_CONDITION_QUE_Enum0
{
    ISOLATOROUTPUT_CONDITION_QUE_Enum0_YO1,
    ISOLATOROUTPUT_CONDITION_QUE_Enum0_YO2,
}ISOLATOROUTPUT_CONDITION_QUE_Enum0;



struct ISOLATOROUTPUT_CONDITION_QUE
{
    int ISOLATOROUTPUT_mainNUM = 74;
    char CONDITION_QUE_subNUM = 5;
    ISOLATOROUTPUT_CONDITION_QUE_Enum0  ENUM0_0;

    struct ISOLATOROUTPUT_CONDITION_QUE* Add_ENUM0_0( ISOLATOROUTPUT_CONDITION_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATOROUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CONDITION_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ISOLATOROUTPUT_RESPONSE_Enum0
{
    ISOLATOROUTPUT_RESPONSE_Enum0_YO1,
    ISOLATOROUTPUT_RESPONSE_Enum0_YO2,
}ISOLATOROUTPUT_RESPONSE_Enum0;

typedef enum ISOLATOROUTPUT_RESPONSE_Enum1
{
    ISOLATOROUTPUT_RESPONSE_Enum1_TURNON,
    ISOLATOROUTPUT_RESPONSE_Enum1_CUTOFF,
}ISOLATOROUTPUT_RESPONSE_Enum1;



struct ISOLATOROUTPUT_RESPONSE
{
    int ISOLATOROUTPUT_mainNUM = 74;
    char RESPONSE_subNUM = 6;
    ISOLATOROUTPUT_RESPONSE_Enum0  ENUM0_0;
    ISOLATOROUTPUT_RESPONSE_Enum1  ENUM1_1;

    struct ISOLATOROUTPUT_RESPONSE* Add_ENUM0_0( ISOLATOROUTPUT_RESPONSE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct ISOLATOROUTPUT_RESPONSE* Add_ENUM1_1( ISOLATOROUTPUT_RESPONSE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATOROUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RESPONSE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum ISOLATOROUTPUT_RESPONSE_QUE_Enum0
{
    ISOLATOROUTPUT_RESPONSE_QUE_Enum0_YO1,
    ISOLATOROUTPUT_RESPONSE_QUE_Enum0_YO2,
}ISOLATOROUTPUT_RESPONSE_QUE_Enum0;



struct ISOLATOROUTPUT_RESPONSE_QUE
{
    int ISOLATOROUTPUT_mainNUM = 74;
    char RESPONSE_QUE_subNUM = 7;
    ISOLATOROUTPUT_RESPONSE_QUE_Enum0  ENUM0_0;

    struct ISOLATOROUTPUT_RESPONSE_QUE* Add_ENUM0_0( ISOLATOROUTPUT_RESPONSE_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATOROUTPUT_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RESPONSE_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct isolatoroutput
{
    int  ISOLATOROUTPUT_NUM = 74;
    struct ISOLATOROUTPUT_STATE  STATE;
    struct ISOLATOROUTPUT_STATE_QUE  STATE_QUE;
    struct ISOLATOROUTPUT_SOURCE  SOURCE;
    struct ISOLATOROUTPUT_SOURCE_QUE  SOURCE_QUE;
    struct ISOLATOROUTPUT_CONDITION  CONDITION;
    struct ISOLATOROUTPUT_CONDITION_QUE  CONDITION_QUE;
    struct ISOLATOROUTPUT_RESPONSE  RESPONSE;
    struct ISOLATOROUTPUT_RESPONSE_QUE  RESPONSE_QUE;

}isolatoroutput;

typedef enum SENSORUART_BAUD_Enum0
{
    SENSORUART_BAUD_Enum0_UART1,
    SENSORUART_BAUD_Enum0_UART2,
}SENSORUART_BAUD_Enum0;

typedef enum SENSORUART_BAUD_Enum1
{
    SENSORUART_BAUD_Enum1_4800,
    SENSORUART_BAUD_Enum1_7200,
    SENSORUART_BAUD_Enum1_9600,
    SENSORUART_BAUD_Enum1_14400,
    SENSORUART_BAUD_Enum1_19200,
    SENSORUART_BAUD_Enum1_38400,
    SENSORUART_BAUD_Enum1_57600,
    SENSORUART_BAUD_Enum1_115200,
    SENSORUART_BAUD_Enum1_128000,
    SENSORUART_BAUD_Enum1_2000000,
    SENSORUART_BAUD_Enum1_2500000,
}SENSORUART_BAUD_Enum1;



struct SENSORUART_BAUD
{
    int SENSORUART_mainNUM = 75;
    char BAUD_subNUM = 0;
    SENSORUART_BAUD_Enum0  ENUM0_0;
    SENSORUART_BAUD_Enum1  ENUM1_1;

    struct SENSORUART_BAUD* Add_ENUM0_0( SENSORUART_BAUD_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_BAUD* Add_ENUM1_1( SENSORUART_BAUD_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BAUD_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum SENSORUART_BAUD_QUE_Enum0
{
    SENSORUART_BAUD_QUE_Enum0_UART1,
    SENSORUART_BAUD_QUE_Enum0_UART2,
}SENSORUART_BAUD_QUE_Enum0;



struct SENSORUART_BAUD_QUE
{
    int SENSORUART_mainNUM = 75;
    char BAUD_QUE_subNUM = 1;
    SENSORUART_BAUD_QUE_Enum0  ENUM0_0;

    struct SENSORUART_BAUD_QUE* Add_ENUM0_0( SENSORUART_BAUD_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (BAUD_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_WORDLEN_Enum0
{
    SENSORUART_WORDLEN_Enum0_UART1,
    SENSORUART_WORDLEN_Enum0_UART2,
}SENSORUART_WORDLEN_Enum0;

typedef enum SENSORUART_WORDLEN_Enum1
{
    SENSORUART_WORDLEN_Enum1_8,
    SENSORUART_WORDLEN_Enum1_9,
}SENSORUART_WORDLEN_Enum1;



struct SENSORUART_WORDLEN
{
    int SENSORUART_mainNUM = 75;
    char WORDLEN_subNUM = 2;
    SENSORUART_WORDLEN_Enum0  ENUM0_0;
    SENSORUART_WORDLEN_Enum1  ENUM1_1;

    struct SENSORUART_WORDLEN* Add_ENUM0_0( SENSORUART_WORDLEN_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_WORDLEN* Add_ENUM1_1( SENSORUART_WORDLEN_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (WORDLEN_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum SENSORUART_WORDLEN_QUE_Enum0
{
    SENSORUART_WORDLEN_QUE_Enum0_UART1,
    SENSORUART_WORDLEN_QUE_Enum0_UART2,
}SENSORUART_WORDLEN_QUE_Enum0;



struct SENSORUART_WORDLEN_QUE
{
    int SENSORUART_mainNUM = 75;
    char WORDLEN_QUE_subNUM = 3;
    SENSORUART_WORDLEN_QUE_Enum0  ENUM0_0;

    struct SENSORUART_WORDLEN_QUE* Add_ENUM0_0( SENSORUART_WORDLEN_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (WORDLEN_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_FLOWCTL_Enum0
{
    SENSORUART_FLOWCTL_Enum0_UART1,
    SENSORUART_FLOWCTL_Enum0_UART2,
}SENSORUART_FLOWCTL_Enum0;

typedef enum SENSORUART_FLOWCTL_Enum1
{
    SENSORUART_FLOWCTL_Enum1_NONE,
    SENSORUART_FLOWCTL_Enum1_RTS,
    SENSORUART_FLOWCTL_Enum1_CTS,
    SENSORUART_FLOWCTL_Enum1_RTS_CTS,
}SENSORUART_FLOWCTL_Enum1;



struct SENSORUART_FLOWCTL
{
    int SENSORUART_mainNUM = 75;
    char FLOWCTL_subNUM = 4;
    SENSORUART_FLOWCTL_Enum0  ENUM0_0;
    SENSORUART_FLOWCTL_Enum1  ENUM1_1;

    struct SENSORUART_FLOWCTL* Add_ENUM0_0( SENSORUART_FLOWCTL_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_FLOWCTL* Add_ENUM1_1( SENSORUART_FLOWCTL_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FLOWCTL_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum SENSORUART_FLOWCTL_QUE_Enum0
{
    SENSORUART_FLOWCTL_QUE_Enum0_UART1,
    SENSORUART_FLOWCTL_QUE_Enum0_UART2,
}SENSORUART_FLOWCTL_QUE_Enum0;



struct SENSORUART_FLOWCTL_QUE
{
    int SENSORUART_mainNUM = 75;
    char FLOWCTL_QUE_subNUM = 5;
    SENSORUART_FLOWCTL_QUE_Enum0  ENUM0_0;

    struct SENSORUART_FLOWCTL_QUE* Add_ENUM0_0( SENSORUART_FLOWCTL_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FLOWCTL_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_PARITY_Enum0
{
    SENSORUART_PARITY_Enum0_UART1,
    SENSORUART_PARITY_Enum0_UART2,
}SENSORUART_PARITY_Enum0;

typedef enum SENSORUART_PARITY_Enum1
{
    SENSORUART_PARITY_Enum1_NONE,
    SENSORUART_PARITY_Enum1_EVEN,
    SENSORUART_PARITY_Enum1_ODD,
}SENSORUART_PARITY_Enum1;



struct SENSORUART_PARITY
{
    int SENSORUART_mainNUM = 75;
    char PARITY_subNUM = 6;
    SENSORUART_PARITY_Enum0  ENUM0_0;
    SENSORUART_PARITY_Enum1  ENUM1_1;

    struct SENSORUART_PARITY* Add_ENUM0_0( SENSORUART_PARITY_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_PARITY* Add_ENUM1_1( SENSORUART_PARITY_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PARITY_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum SENSORUART_PARITY_QUE_Enum0
{
    SENSORUART_PARITY_QUE_Enum0_UART1,
    SENSORUART_PARITY_QUE_Enum0_UART2,
}SENSORUART_PARITY_QUE_Enum0;



struct SENSORUART_PARITY_QUE
{
    int SENSORUART_mainNUM = 75;
    char PARITY_QUE_subNUM = 7;
    SENSORUART_PARITY_QUE_Enum0  ENUM0_0;

    struct SENSORUART_PARITY_QUE* Add_ENUM0_0( SENSORUART_PARITY_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (PARITY_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_STOPBIT_Enum0
{
    SENSORUART_STOPBIT_Enum0_UART1,
    SENSORUART_STOPBIT_Enum0_UART2,
}SENSORUART_STOPBIT_Enum0;

typedef enum SENSORUART_STOPBIT_Enum1
{
    SENSORUART_STOPBIT_Enum1_1,
    SENSORUART_STOPBIT_Enum1_0d5,
    SENSORUART_STOPBIT_Enum1_2,
    SENSORUART_STOPBIT_Enum1_1d5,
}SENSORUART_STOPBIT_Enum1;



struct SENSORUART_STOPBIT
{
    int SENSORUART_mainNUM = 75;
    char STOPBIT_subNUM = 8;
    SENSORUART_STOPBIT_Enum0  ENUM0_0;
    SENSORUART_STOPBIT_Enum1  ENUM1_1;

    struct SENSORUART_STOPBIT* Add_ENUM0_0( SENSORUART_STOPBIT_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_STOPBIT* Add_ENUM1_1( SENSORUART_STOPBIT_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPBIT_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum SENSORUART_STOPBIT_QUE_Enum0
{
    SENSORUART_STOPBIT_QUE_Enum0_UART1,
    SENSORUART_STOPBIT_QUE_Enum0_UART2,
}SENSORUART_STOPBIT_QUE_Enum0;



struct SENSORUART_STOPBIT_QUE
{
    int SENSORUART_mainNUM = 75;
    char STOPBIT_QUE_subNUM = 9;
    SENSORUART_STOPBIT_QUE_Enum0  ENUM0_0;

    struct SENSORUART_STOPBIT_QUE* Add_ENUM0_0( SENSORUART_STOPBIT_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STOPBIT_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_APPLYPARA_Enum0
{
    SENSORUART_APPLYPARA_Enum0_UART1,
    SENSORUART_APPLYPARA_Enum0_UART2,
}SENSORUART_APPLYPARA_Enum0;



struct SENSORUART_APPLYPARA
{
    int SENSORUART_mainNUM = 75;
    char APPLYPARA_subNUM = 10;
    SENSORUART_APPLYPARA_Enum0  ENUM0_0;

    struct SENSORUART_APPLYPARA* Add_ENUM0_0( SENSORUART_APPLYPARA_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (APPLYPARA_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};
typedef enum SENSORUART_STATE_Enum0
{
    SENSORUART_STATE_Enum0_UART1,
    SENSORUART_STATE_Enum0_UART2,
}SENSORUART_STATE_Enum0;

typedef enum SENSORUART_STATE_Enum1
{
    SENSORUART_STATE_Enum1_S1,
    SENSORUART_STATE_Enum1_S2,
    SENSORUART_STATE_Enum1_S3,
    SENSORUART_STATE_Enum1_S4,
}SENSORUART_STATE_Enum1;

typedef enum SENSORUART_STATE_Enum2
{
    SENSORUART_STATE_Enum2_OFF,
    SENSORUART_STATE_Enum2_ON,
}SENSORUART_STATE_Enum2;



struct SENSORUART_STATE
{
    int SENSORUART_mainNUM = 75;
    char STATE_subNUM = 11;
    SENSORUART_STATE_Enum0  ENUM0_0;
    SENSORUART_STATE_Enum1  ENUM1_1;
    SENSORUART_STATE_Enum2  ENUM2_2;

    struct SENSORUART_STATE* Add_ENUM0_0( SENSORUART_STATE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_STATE* Add_ENUM1_1( SENSORUART_STATE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct SENSORUART_STATE* Add_ENUM2_2( SENSORUART_STATE_Enum2 param )
    {
        ENUM2_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        cmdData.cmdData[4] = ENUM2_2;
        return cmdData ;
    }

};
typedef enum SENSORUART_STATE_QUE_Enum0
{
    SENSORUART_STATE_QUE_Enum0_UART1,
    SENSORUART_STATE_QUE_Enum0_UART2,
}SENSORUART_STATE_QUE_Enum0;

typedef enum SENSORUART_STATE_QUE_Enum1
{
    SENSORUART_STATE_QUE_Enum1_S1,
    SENSORUART_STATE_QUE_Enum1_S2,
    SENSORUART_STATE_QUE_Enum1_S3,
    SENSORUART_STATE_QUE_Enum1_S4,
}SENSORUART_STATE_QUE_Enum1;



struct SENSORUART_STATE_QUE
{
    int SENSORUART_mainNUM = 75;
    char STATE_QUE_subNUM = 12;
    SENSORUART_STATE_QUE_Enum0  ENUM0_0;
    SENSORUART_STATE_QUE_Enum1  ENUM1_1;

    struct SENSORUART_STATE_QUE* Add_ENUM0_0( SENSORUART_STATE_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_STATE_QUE* Add_ENUM1_1( SENSORUART_STATE_QUE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM2_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_SOF_Enum0
{
    SENSORUART_SOF_Enum0_UART1,
    SENSORUART_SOF_Enum0_UART2,
}SENSORUART_SOF_Enum0;

typedef enum SENSORUART_SOF_Enum1
{
    SENSORUART_SOF_Enum1_S1,
    SENSORUART_SOF_Enum1_S2,
    SENSORUART_SOF_Enum1_S3,
    SENSORUART_SOF_Enum1_S4,
}SENSORUART_SOF_Enum1;



struct SENSORUART_SOF
{
    int SENSORUART_mainNUM = 75;
    char SOF_subNUM = 13;
    SENSORUART_SOF_Enum0  ENUM0_0;
    SENSORUART_SOF_Enum1  ENUM1_1;
    unsigned char  U8_0_2;

    struct SENSORUART_SOF* Add_ENUM0_0( SENSORUART_SOF_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_SOF* Add_ENUM1_1( SENSORUART_SOF_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct SENSORUART_SOF* Add_U8_0_2( unsigned char param )
    {
        U8_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SOF_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        char * ptrU8_0_2 = (char *) &U8_0_2 ;
        cmdData.cmdData[4] = *( ptrU8_0_2++);
        return cmdData ;
    }

};
typedef enum SENSORUART_SOF_QUE_Enum0
{
    SENSORUART_SOF_QUE_Enum0_UART1,
    SENSORUART_SOF_QUE_Enum0_UART2,
}SENSORUART_SOF_QUE_Enum0;

typedef enum SENSORUART_SOF_QUE_Enum1
{
    SENSORUART_SOF_QUE_Enum1_S1,
    SENSORUART_SOF_QUE_Enum1_S2,
    SENSORUART_SOF_QUE_Enum1_S3,
    SENSORUART_SOF_QUE_Enum1_S4,
}SENSORUART_SOF_QUE_Enum1;



struct SENSORUART_SOF_QUE
{
    int SENSORUART_mainNUM = 75;
    char SOF_QUE_subNUM = 14;
    SENSORUART_SOF_QUE_Enum0  ENUM0_0;
    SENSORUART_SOF_QUE_Enum1  ENUM1_1;

    struct SENSORUART_SOF_QUE* Add_ENUM0_0( SENSORUART_SOF_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_SOF_QUE* Add_ENUM1_1( SENSORUART_SOF_QUE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SOF_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_FRAMELEN_Enum0
{
    SENSORUART_FRAMELEN_Enum0_UART1,
    SENSORUART_FRAMELEN_Enum0_UART2,
}SENSORUART_FRAMELEN_Enum0;

typedef enum SENSORUART_FRAMELEN_Enum1
{
    SENSORUART_FRAMELEN_Enum1_S1,
    SENSORUART_FRAMELEN_Enum1_S2,
    SENSORUART_FRAMELEN_Enum1_S3,
    SENSORUART_FRAMELEN_Enum1_S4,
}SENSORUART_FRAMELEN_Enum1;



struct SENSORUART_FRAMELEN
{
    int SENSORUART_mainNUM = 75;
    char FRAMELEN_subNUM = 15;
    SENSORUART_FRAMELEN_Enum0  ENUM0_0;
    SENSORUART_FRAMELEN_Enum1  ENUM1_1;
    unsigned char  U8_0_2;

    struct SENSORUART_FRAMELEN* Add_ENUM0_0( SENSORUART_FRAMELEN_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_FRAMELEN* Add_ENUM1_1( SENSORUART_FRAMELEN_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct SENSORUART_FRAMELEN* Add_U8_0_2( unsigned char param )
    {
        U8_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FRAMELEN_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        char * ptrU8_0_2 = (char *) &U8_0_2 ;
        cmdData.cmdData[4] = *( ptrU8_0_2++);
        return cmdData ;
    }

};
typedef enum SENSORUART_FRAMELEN_QUE_Enum0
{
    SENSORUART_FRAMELEN_QUE_Enum0_UART1,
    SENSORUART_FRAMELEN_QUE_Enum0_UART2,
}SENSORUART_FRAMELEN_QUE_Enum0;

typedef enum SENSORUART_FRAMELEN_QUE_Enum1
{
    SENSORUART_FRAMELEN_QUE_Enum1_S1,
    SENSORUART_FRAMELEN_QUE_Enum1_S2,
    SENSORUART_FRAMELEN_QUE_Enum1_S3,
    SENSORUART_FRAMELEN_QUE_Enum1_S4,
}SENSORUART_FRAMELEN_QUE_Enum1;



struct SENSORUART_FRAMELEN_QUE
{
    int SENSORUART_mainNUM = 75;
    char FRAMELEN_QUE_subNUM = 16;
    SENSORUART_FRAMELEN_QUE_Enum0  ENUM0_0;
    SENSORUART_FRAMELEN_QUE_Enum1  ENUM1_1;

    struct SENSORUART_FRAMELEN_QUE* Add_ENUM0_0( SENSORUART_FRAMELEN_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_FRAMELEN_QUE* Add_ENUM1_1( SENSORUART_FRAMELEN_QUE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (FRAMELEN_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_RECEIVENUM_Enum0
{
    SENSORUART_RECEIVENUM_Enum0_UART1,
    SENSORUART_RECEIVENUM_Enum0_UART2,
}SENSORUART_RECEIVENUM_Enum0;

typedef enum SENSORUART_RECEIVENUM_Enum1
{
    SENSORUART_RECEIVENUM_Enum1_S1,
    SENSORUART_RECEIVENUM_Enum1_S2,
    SENSORUART_RECEIVENUM_Enum1_S3,
    SENSORUART_RECEIVENUM_Enum1_S4,
}SENSORUART_RECEIVENUM_Enum1;



struct SENSORUART_RECEIVENUM
{
    int SENSORUART_mainNUM = 75;
    char RECEIVENUM_subNUM = 17;
    SENSORUART_RECEIVENUM_Enum0  ENUM0_0;
    SENSORUART_RECEIVENUM_Enum1  ENUM1_1;
    unsigned char  U8_0_2;

    struct SENSORUART_RECEIVENUM* Add_ENUM0_0( SENSORUART_RECEIVENUM_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_RECEIVENUM* Add_ENUM1_1( SENSORUART_RECEIVENUM_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct SENSORUART_RECEIVENUM* Add_U8_0_2( unsigned char param )
    {
        U8_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RECEIVENUM_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        char * ptrU8_0_2 = (char *) &U8_0_2 ;
        cmdData.cmdData[4] = *( ptrU8_0_2++);
        return cmdData ;
    }

};
typedef enum SENSORUART_RECEIVENUM_QUE_Enum0
{
    SENSORUART_RECEIVENUM_QUE_Enum0_UART1,
    SENSORUART_RECEIVENUM_QUE_Enum0_UART2,
}SENSORUART_RECEIVENUM_QUE_Enum0;

typedef enum SENSORUART_RECEIVENUM_QUE_Enum1
{
    SENSORUART_RECEIVENUM_QUE_Enum1_S1,
    SENSORUART_RECEIVENUM_QUE_Enum1_S2,
    SENSORUART_RECEIVENUM_QUE_Enum1_S3,
    SENSORUART_RECEIVENUM_QUE_Enum1_S4,
}SENSORUART_RECEIVENUM_QUE_Enum1;



struct SENSORUART_RECEIVENUM_QUE
{
    int SENSORUART_mainNUM = 75;
    char RECEIVENUM_QUE_subNUM = 18;
    SENSORUART_RECEIVENUM_QUE_Enum0  ENUM0_0;
    SENSORUART_RECEIVENUM_QUE_Enum1  ENUM1_1;

    struct SENSORUART_RECEIVENUM_QUE* Add_ENUM0_0( SENSORUART_RECEIVENUM_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_RECEIVENUM_QUE* Add_ENUM1_1( SENSORUART_RECEIVENUM_QUE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RECEIVENUM_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_SWITCHTIME_Enum0
{
    SENSORUART_SWITCHTIME_Enum0_UART1,
    SENSORUART_SWITCHTIME_Enum0_UART2,
}SENSORUART_SWITCHTIME_Enum0;

typedef enum SENSORUART_SWITCHTIME_Enum1
{
    SENSORUART_SWITCHTIME_Enum1_S1,
    SENSORUART_SWITCHTIME_Enum1_S2,
    SENSORUART_SWITCHTIME_Enum1_S3,
    SENSORUART_SWITCHTIME_Enum1_S4,
}SENSORUART_SWITCHTIME_Enum1;



struct SENSORUART_SWITCHTIME
{
    int SENSORUART_mainNUM = 75;
    char SWITCHTIME_subNUM = 19;
    SENSORUART_SWITCHTIME_Enum0  ENUM0_0;
    SENSORUART_SWITCHTIME_Enum1  ENUM1_1;
    unsigned int  U32_0_2;

    struct SENSORUART_SWITCHTIME* Add_ENUM0_0( SENSORUART_SWITCHTIME_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_SWITCHTIME* Add_ENUM1_1( SENSORUART_SWITCHTIME_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct SENSORUART_SWITCHTIME* Add_U32_0_2( unsigned int param )
    {
        U32_0_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SWITCHTIME_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        char * ptrU32_0_2 = (char *) &U32_0_2 ;
        cmdData.cmdData[4] = *( ptrU32_0_2++);
        cmdData.cmdData[5] = *( ptrU32_0_2++);
        cmdData.cmdData[6] = *( ptrU32_0_2++);
        cmdData.cmdData[7] = *( ptrU32_0_2++);
        return cmdData ;
    }

};
typedef enum SENSORUART_SWITCHTIME_QUE_Enum0
{
    SENSORUART_SWITCHTIME_QUE_Enum0_UART1,
    SENSORUART_SWITCHTIME_QUE_Enum0_UART2,
}SENSORUART_SWITCHTIME_QUE_Enum0;

typedef enum SENSORUART_SWITCHTIME_QUE_Enum1
{
    SENSORUART_SWITCHTIME_QUE_Enum1_S1,
    SENSORUART_SWITCHTIME_QUE_Enum1_S2,
    SENSORUART_SWITCHTIME_QUE_Enum1_S3,
    SENSORUART_SWITCHTIME_QUE_Enum1_S4,
}SENSORUART_SWITCHTIME_QUE_Enum1;



struct SENSORUART_SWITCHTIME_QUE
{
    int SENSORUART_mainNUM = 75;
    char SWITCHTIME_QUE_subNUM = 20;
    SENSORUART_SWITCHTIME_QUE_Enum0  ENUM0_0;
    SENSORUART_SWITCHTIME_QUE_Enum1  ENUM1_1;

    struct SENSORUART_SWITCHTIME_QUE* Add_ENUM0_0( SENSORUART_SWITCHTIME_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_SWITCHTIME_QUE* Add_ENUM1_1( SENSORUART_SWITCHTIME_QUE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SWITCHTIME_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum SENSORUART_DATA_QUE_Enum0
{
    SENSORUART_DATA_QUE_Enum0_UART1,
    SENSORUART_DATA_QUE_Enum0_UART2,
}SENSORUART_DATA_QUE_Enum0;

typedef enum SENSORUART_DATA_QUE_Enum1
{
    SENSORUART_DATA_QUE_Enum1_S1,
    SENSORUART_DATA_QUE_Enum1_S2,
    SENSORUART_DATA_QUE_Enum1_S3,
    SENSORUART_DATA_QUE_Enum1_S4,
}SENSORUART_DATA_QUE_Enum1;



struct SENSORUART_DATA_QUE
{
    int SENSORUART_mainNUM = 75;
    char DATA_QUE_subNUM = 21;
    SENSORUART_DATA_QUE_Enum0  ENUM0_0;
    SENSORUART_DATA_QUE_Enum1  ENUM1_1;

    struct SENSORUART_DATA_QUE* Add_ENUM0_0( SENSORUART_DATA_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct SENSORUART_DATA_QUE* Add_ENUM1_1( SENSORUART_DATA_QUE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (SENSORUART_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DATA_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct sensoruart
{
    int  SENSORUART_NUM = 75;
    struct SENSORUART_BAUD  BAUD;
    struct SENSORUART_BAUD_QUE  BAUD_QUE;
    struct SENSORUART_WORDLEN  WORDLEN;
    struct SENSORUART_WORDLEN_QUE  WORDLEN_QUE;
    struct SENSORUART_FLOWCTL  FLOWCTL;
    struct SENSORUART_FLOWCTL_QUE  FLOWCTL_QUE;
    struct SENSORUART_PARITY  PARITY;
    struct SENSORUART_PARITY_QUE  PARITY_QUE;
    struct SENSORUART_STOPBIT  STOPBIT;
    struct SENSORUART_STOPBIT_QUE  STOPBIT_QUE;
    struct SENSORUART_APPLYPARA  APPLYPARA;
    struct SENSORUART_STATE  STATE;
    struct SENSORUART_STATE_QUE  STATE_QUE;
    struct SENSORUART_SOF  SOF;
    struct SENSORUART_SOF_QUE  SOF_QUE;
    struct SENSORUART_FRAMELEN  FRAMELEN;
    struct SENSORUART_FRAMELEN_QUE  FRAMELEN_QUE;
    struct SENSORUART_RECEIVENUM  RECEIVENUM;
    struct SENSORUART_RECEIVENUM_QUE  RECEIVENUM_QUE;
    struct SENSORUART_SWITCHTIME  SWITCHTIME;
    struct SENSORUART_SWITCHTIME_QUE  SWITCHTIME_QUE;
    struct SENSORUART_DATA_QUE  DATA_QUE;

}sensoruart;

typedef enum TUNING_STATE_Enum0
{
    TUNING_STATE_Enum0_OFF,
    TUNING_STATE_Enum0_ON,
}TUNING_STATE_Enum0;



struct TUNING_STATE
{
    int TUNING_mainNUM = 76;
    char STATE_subNUM = 0;
    unsigned char  U8_0_0;
    TUNING_STATE_Enum0  ENUM0_1;

    struct TUNING_STATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TUNING_STATE* Add_ENUM0_1( TUNING_STATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TUNING_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct TUNING_STATE_QUE
{
    int TUNING_mainNUM = 76;
    char STATE_QUE_subNUM = 1;
    unsigned char  U8_0_0;

    struct TUNING_STATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TUNING_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TUNING_MINICURRRATIO_Enum0
{
    TUNING_MINICURRRATIO_Enum0_1f2,
    TUNING_MINICURRRATIO_Enum0_1f4,
}TUNING_MINICURRRATIO_Enum0;



struct TUNING_MINICURRRATIO
{
    int TUNING_mainNUM = 76;
    char MINICURRRATIO_subNUM = 2;
    unsigned char  U8_0_0;
    TUNING_MINICURRRATIO_Enum0  ENUM0_1;

    struct TUNING_MINICURRRATIO* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TUNING_MINICURRRATIO* Add_ENUM0_1( TUNING_MINICURRRATIO_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TUNING_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINICURRRATIO_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct TUNING_MINICURRRATIO_QUE
{
    int TUNING_mainNUM = 76;
    char MINICURRRATIO_QUE_subNUM = 3;
    unsigned char  U8_0_0;

    struct TUNING_MINICURRRATIO_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TUNING_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MINICURRRATIO_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct TUNING_ENERGYEFFIC
{
    int TUNING_mainNUM = 76;
    char ENERGYEFFIC_subNUM = 4;
    unsigned char  U8_0_0;
    unsigned short  U16_0_1;
    unsigned short  U16_1_2;

    struct TUNING_ENERGYEFFIC* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TUNING_ENERGYEFFIC* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct TUNING_ENERGYEFFIC* Add_U16_1_2( unsigned short param )
    {
        U16_1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TUNING_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ENERGYEFFIC_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        char * ptrU16_1_2 = (char *) &U16_1_2 ;
        cmdData.cmdData[5] = *( ptrU16_1_2++);
        cmdData.cmdData[6] = *( ptrU16_1_2++);
        return cmdData ;
    }

};


struct TUNING_ENERGYEFFIC_QUE
{
    int TUNING_mainNUM = 76;
    char ENERGYEFFIC_QUE_subNUM = 5;
    unsigned char  U8_0_0;

    struct TUNING_ENERGYEFFIC_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TUNING_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ENERGYEFFIC_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_1_2 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[5]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum TUNING_CURRREGULATE_Enum0
{
    TUNING_CURRREGULATE_Enum0_1,
    TUNING_CURRREGULATE_Enum0_2,
    TUNING_CURRREGULATE_Enum0_4,
    TUNING_CURRREGULATE_Enum0_8,
}TUNING_CURRREGULATE_Enum0;

typedef enum TUNING_CURRREGULATE_Enum1
{
    TUNING_CURRREGULATE_Enum1_32,
    TUNING_CURRREGULATE_Enum1_8,
    TUNING_CURRREGULATE_Enum1_2,
    TUNING_CURRREGULATE_Enum1_1,
}TUNING_CURRREGULATE_Enum1;



struct TUNING_CURRREGULATE
{
    int TUNING_mainNUM = 76;
    char CURRREGULATE_subNUM = 6;
    unsigned char  U8_0_0;
    TUNING_CURRREGULATE_Enum0  ENUM0_1;
    TUNING_CURRREGULATE_Enum1  ENUM1_2;

    struct TUNING_CURRREGULATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct TUNING_CURRREGULATE* Add_ENUM0_1( TUNING_CURRREGULATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct TUNING_CURRREGULATE* Add_ENUM1_2( TUNING_CURRREGULATE_Enum1 param )
    {
        ENUM1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TUNING_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CURRREGULATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        cmdData.cmdData[4] = ENUM1_2;
        return cmdData ;
    }

};


struct TUNING_CURRREGULATE_QUE
{
    int TUNING_mainNUM = 76;
    char CURRREGULATE_QUE_subNUM = 7;
    unsigned char  U8_0_0;

    struct TUNING_CURRREGULATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (TUNING_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CURRREGULATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_2 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[4]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct tuning
{
    int  TUNING_NUM = 76;
    struct TUNING_STATE  STATE;
    struct TUNING_STATE_QUE  STATE_QUE;
    struct TUNING_MINICURRRATIO  MINICURRRATIO;
    struct TUNING_MINICURRRATIO_QUE  MINICURRRATIO_QUE;
    struct TUNING_ENERGYEFFIC  ENERGYEFFIC;
    struct TUNING_ENERGYEFFIC_QUE  ENERGYEFFIC_QUE;
    struct TUNING_CURRREGULATE  CURRREGULATE;
    struct TUNING_CURRREGULATE_QUE  CURRREGULATE_QUE;

}tuning;

typedef enum ISOLATORIN_STATE_Enum0
{
    ISOLATORIN_STATE_Enum0_OFF,
    ISOLATORIN_STATE_Enum0_ON,
}ISOLATORIN_STATE_Enum0;



struct ISOLATORIN_STATE
{
    int ISOLATORIN_mainNUM = 92;
    char STATE_subNUM = 0;
    ISOLATORIN_STATE_Enum0  ENUM0_0;

    struct ISOLATORIN_STATE* Add_ENUM0_0( ISOLATORIN_STATE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct ISOLATORIN_STATE_QUE
{
    int ISOLATORIN_mainNUM = 92;
    char STATE_QUE_subNUM = 1;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ISOLATORIN_TYPE_Enum0
{
    ISOLATORIN_TYPE_Enum0_RESERVE,
    ISOLATORIN_TYPE_Enum0_LOW,
    ISOLATORIN_TYPE_Enum0_RISE,
    ISOLATORIN_TYPE_Enum0_FALL,
    ISOLATORIN_TYPE_Enum0_HIGH,
}ISOLATORIN_TYPE_Enum0;



struct ISOLATORIN_TYPE
{
    int ISOLATORIN_mainNUM = 92;
    char TYPE_subNUM = 2;
    ISOLATORIN_TYPE_Enum0  ENUM0_0;

    struct ISOLATORIN_TYPE* Add_ENUM0_0( ISOLATORIN_TYPE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct ISOLATORIN_TYPE_QUE
{
    int ISOLATORIN_mainNUM = 92;
    char TYPE_QUE_subNUM = 3;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ISOLATORIN_RESPONSE_Enum0
{
    ISOLATORIN_RESPONSE_Enum0_NONE,
    ISOLATORIN_RESPONSE_Enum0_ALARM,
    ISOLATORIN_RESPONSE_Enum0_STOP,
    ISOLATORIN_RESPONSE_Enum0_ALARM_STOP,
}ISOLATORIN_RESPONSE_Enum0;



struct ISOLATORIN_RESPONSE
{
    int ISOLATORIN_mainNUM = 92;
    char RESPONSE_subNUM = 4;
    ISOLATORIN_RESPONSE_Enum0  ENUM0_0;

    struct ISOLATORIN_RESPONSE* Add_ENUM0_0( ISOLATORIN_RESPONSE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RESPONSE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct ISOLATORIN_RESPONSE_QUE
{
    int ISOLATORIN_mainNUM = 92;
    char RESPONSE_QUE_subNUM = 5;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RESPONSE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct ISOLATORIN_RESPCHAN
{
    int ISOLATORIN_mainNUM = 92;
    char RESPCHAN_subNUM = 6;
    unsigned char  U8_0_0;

    struct ISOLATORIN_RESPCHAN* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RESPCHAN_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }

};


struct ISOLATORIN_RESPCHAN_QUE
{
    int ISOLATORIN_mainNUM = 92;
    char RESPCHAN_QUE_subNUM = 7;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RESPCHAN_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ISOLATORIN_SMODE_Enum0
{
    ISOLATORIN_SMODE_Enum0_CONTINUED,
    ISOLATORIN_SMODE_Enum0_INTERVAL,
    ISOLATORIN_SMODE_Enum0_SINGLE,
}ISOLATORIN_SMODE_Enum0;



struct ISOLATORIN_SMODE
{
    int ISOLATORIN_mainNUM = 92;
    char SMODE_subNUM = 8;
    ISOLATORIN_SMODE_Enum0  ENUM0_0;

    struct ISOLATORIN_SMODE* Add_ENUM0_0( ISOLATORIN_SMODE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SMODE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct ISOLATORIN_SMODE_QUE
{
    int ISOLATORIN_mainNUM = 92;
    char SMODE_QUE_subNUM = 9;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SMODE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct ISOLATORIN_SPERIOD
{
    int ISOLATORIN_mainNUM = 92;
    char SPERIOD_subNUM = 10;
    unsigned int  U32_0_0;

    struct ISOLATORIN_SPERIOD* Add_U32_0_0( unsigned int param )
    {
        U32_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SPERIOD_subNUM );
        char * ptrU32_0_0 = (char *) &U32_0_0 ;
        cmdData.cmdData[2] = *( ptrU32_0_0++);
        cmdData.cmdData[3] = *( ptrU32_0_0++);
        cmdData.cmdData[4] = *( ptrU32_0_0++);
        cmdData.cmdData[5] = *( ptrU32_0_0++);
        return cmdData ;
    }

};


struct ISOLATORIN_SPERIOD_QUE
{
    int ISOLATORIN_mainNUM = 92;
    char SPERIOD_QUE_subNUM = 11;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ISOLATORIN_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SPERIOD_QUE_subNUM );
        return cmdData ;
    }
    unsigned int analysis_U32_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct isolatorin
{
    int  ISOLATORIN_NUM = 92;
    struct ISOLATORIN_STATE  STATE;
    struct ISOLATORIN_STATE_QUE  STATE_QUE;
    struct ISOLATORIN_TYPE  TYPE;
    struct ISOLATORIN_TYPE_QUE  TYPE_QUE;
    struct ISOLATORIN_RESPONSE  RESPONSE;
    struct ISOLATORIN_RESPONSE_QUE  RESPONSE_QUE;
    struct ISOLATORIN_RESPCHAN  RESPCHAN;
    struct ISOLATORIN_RESPCHAN_QUE  RESPCHAN_QUE;
    struct ISOLATORIN_SMODE  SMODE;
    struct ISOLATORIN_SMODE_QUE  SMODE_QUE;
    struct ISOLATORIN_SPERIOD  SPERIOD;
    struct ISOLATORIN_SPERIOD_QUE  SPERIOD_QUE;

}isolatorin;

typedef enum ABSENCALARM_STATE_Enum0
{
    ABSENCALARM_STATE_Enum0_S1,
    ABSENCALARM_STATE_Enum0_S2,
    ABSENCALARM_STATE_Enum0_S3,
    ABSENCALARM_STATE_Enum0_S4,
}ABSENCALARM_STATE_Enum0;

typedef enum ABSENCALARM_STATE_Enum1
{
    ABSENCALARM_STATE_Enum1_OFF,
    ABSENCALARM_STATE_Enum1_ON,
}ABSENCALARM_STATE_Enum1;



struct ABSENCALARM_STATE
{
    int ABSENCALARM_mainNUM = 93;
    char STATE_subNUM = 0;
    ABSENCALARM_STATE_Enum0  ENUM0_0;
    ABSENCALARM_STATE_Enum1  ENUM1_1;

    struct ABSENCALARM_STATE* Add_ENUM0_0( ABSENCALARM_STATE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct ABSENCALARM_STATE* Add_ENUM1_1( ABSENCALARM_STATE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum ABSENCALARM_STATE_QUE_Enum0
{
    ABSENCALARM_STATE_QUE_Enum0_S1,
    ABSENCALARM_STATE_QUE_Enum0_S2,
    ABSENCALARM_STATE_QUE_Enum0_S3,
    ABSENCALARM_STATE_QUE_Enum0_S4,
}ABSENCALARM_STATE_QUE_Enum0;



struct ABSENCALARM_STATE_QUE
{
    int ABSENCALARM_mainNUM = 93;
    char STATE_QUE_subNUM = 1;
    ABSENCALARM_STATE_QUE_Enum0  ENUM0_0;

    struct ABSENCALARM_STATE_QUE* Add_ENUM0_0( ABSENCALARM_STATE_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ABSENCALARM_UPLIMIT_Enum0
{
    ABSENCALARM_UPLIMIT_Enum0_S1,
    ABSENCALARM_UPLIMIT_Enum0_S2,
    ABSENCALARM_UPLIMIT_Enum0_S3,
    ABSENCALARM_UPLIMIT_Enum0_S4,
}ABSENCALARM_UPLIMIT_Enum0;



struct ABSENCALARM_UPLIMIT
{
    int ABSENCALARM_mainNUM = 93;
    char UPLIMIT_subNUM = 2;
    ABSENCALARM_UPLIMIT_Enum0  ENUM0_0;
    unsigned int  U32_0_1;

    struct ABSENCALARM_UPLIMIT* Add_ENUM0_0( ABSENCALARM_UPLIMIT_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct ABSENCALARM_UPLIMIT* Add_U32_0_1( unsigned int param )
    {
        U32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (UPLIMIT_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU32_0_1 = (char *) &U32_0_1 ;
        cmdData.cmdData[3] = *( ptrU32_0_1++);
        cmdData.cmdData[4] = *( ptrU32_0_1++);
        cmdData.cmdData[5] = *( ptrU32_0_1++);
        cmdData.cmdData[6] = *( ptrU32_0_1++);
        return cmdData ;
    }

};
typedef enum ABSENCALARM_UPLIMIT_QUE_Enum0
{
    ABSENCALARM_UPLIMIT_QUE_Enum0_S1,
    ABSENCALARM_UPLIMIT_QUE_Enum0_S2,
    ABSENCALARM_UPLIMIT_QUE_Enum0_S3,
    ABSENCALARM_UPLIMIT_QUE_Enum0_S4,
}ABSENCALARM_UPLIMIT_QUE_Enum0;



struct ABSENCALARM_UPLIMIT_QUE
{
    int ABSENCALARM_mainNUM = 93;
    char UPLIMIT_QUE_subNUM = 3;
    ABSENCALARM_UPLIMIT_QUE_Enum0  ENUM0_0;

    struct ABSENCALARM_UPLIMIT_QUE* Add_ENUM0_0( ABSENCALARM_UPLIMIT_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (UPLIMIT_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ABSENCALARM_DOWNLIMIT_Enum0
{
    ABSENCALARM_DOWNLIMIT_Enum0_S1,
    ABSENCALARM_DOWNLIMIT_Enum0_S2,
    ABSENCALARM_DOWNLIMIT_Enum0_S3,
    ABSENCALARM_DOWNLIMIT_Enum0_S4,
}ABSENCALARM_DOWNLIMIT_Enum0;



struct ABSENCALARM_DOWNLIMIT
{
    int ABSENCALARM_mainNUM = 93;
    char DOWNLIMIT_subNUM = 4;
    ABSENCALARM_DOWNLIMIT_Enum0  ENUM0_0;
    unsigned int  U32_0_1;

    struct ABSENCALARM_DOWNLIMIT* Add_ENUM0_0( ABSENCALARM_DOWNLIMIT_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct ABSENCALARM_DOWNLIMIT* Add_U32_0_1( unsigned int param )
    {
        U32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DOWNLIMIT_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU32_0_1 = (char *) &U32_0_1 ;
        cmdData.cmdData[3] = *( ptrU32_0_1++);
        cmdData.cmdData[4] = *( ptrU32_0_1++);
        cmdData.cmdData[5] = *( ptrU32_0_1++);
        cmdData.cmdData[6] = *( ptrU32_0_1++);
        return cmdData ;
    }

};
typedef enum ABSENCALARM_DOWNLIMIT_QUE_Enum0
{
    ABSENCALARM_DOWNLIMIT_QUE_Enum0_S1,
    ABSENCALARM_DOWNLIMIT_QUE_Enum0_S2,
    ABSENCALARM_DOWNLIMIT_QUE_Enum0_S3,
    ABSENCALARM_DOWNLIMIT_QUE_Enum0_S4,
}ABSENCALARM_DOWNLIMIT_QUE_Enum0;



struct ABSENCALARM_DOWNLIMIT_QUE
{
    int ABSENCALARM_mainNUM = 93;
    char DOWNLIMIT_QUE_subNUM = 5;
    ABSENCALARM_DOWNLIMIT_QUE_Enum0  ENUM0_0;

    struct ABSENCALARM_DOWNLIMIT_QUE* Add_ENUM0_0( ABSENCALARM_DOWNLIMIT_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (DOWNLIMIT_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ABSENCALARM_ZEROVALUE_Enum0
{
    ABSENCALARM_ZEROVALUE_Enum0_S1,
    ABSENCALARM_ZEROVALUE_Enum0_S2,
    ABSENCALARM_ZEROVALUE_Enum0_S3,
    ABSENCALARM_ZEROVALUE_Enum0_S4,
}ABSENCALARM_ZEROVALUE_Enum0;



struct ABSENCALARM_ZEROVALUE
{
    int ABSENCALARM_mainNUM = 93;
    char ZEROVALUE_subNUM = 6;
    ABSENCALARM_ZEROVALUE_Enum0  ENUM0_0;
    unsigned int  U32_0_1;

    struct ABSENCALARM_ZEROVALUE* Add_ENUM0_0( ABSENCALARM_ZEROVALUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct ABSENCALARM_ZEROVALUE* Add_U32_0_1( unsigned int param )
    {
        U32_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ZEROVALUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU32_0_1 = (char *) &U32_0_1 ;
        cmdData.cmdData[3] = *( ptrU32_0_1++);
        cmdData.cmdData[4] = *( ptrU32_0_1++);
        cmdData.cmdData[5] = *( ptrU32_0_1++);
        cmdData.cmdData[6] = *( ptrU32_0_1++);
        return cmdData ;
    }

};
typedef enum ABSENCALARM_ZEROVALUE_QUE_Enum0
{
    ABSENCALARM_ZEROVALUE_QUE_Enum0_S1,
    ABSENCALARM_ZEROVALUE_QUE_Enum0_S2,
    ABSENCALARM_ZEROVALUE_QUE_Enum0_S3,
    ABSENCALARM_ZEROVALUE_QUE_Enum0_S4,
}ABSENCALARM_ZEROVALUE_QUE_Enum0;



struct ABSENCALARM_ZEROVALUE_QUE
{
    int ABSENCALARM_mainNUM = 93;
    char ZEROVALUE_QUE_subNUM = 7;
    ABSENCALARM_ZEROVALUE_QUE_Enum0  ENUM0_0;

    struct ABSENCALARM_ZEROVALUE_QUE* Add_ENUM0_0( ABSENCALARM_ZEROVALUE_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ZEROVALUE_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned int analysis_U32_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned int * uintValue = (unsigned int *)tmp; 
            return * uintValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ABSENCALARM_ZEROPOSITION_Enum0
{
    ABSENCALARM_ZEROPOSITION_Enum0_S1,
    ABSENCALARM_ZEROPOSITION_Enum0_S2,
    ABSENCALARM_ZEROPOSITION_Enum0_S3,
    ABSENCALARM_ZEROPOSITION_Enum0_S4,
}ABSENCALARM_ZEROPOSITION_Enum0;

typedef enum ABSENCALARM_ZEROPOSITION_Enum1
{
    ABSENCALARM_ZEROPOSITION_Enum1_EXIS,
    ABSENCALARM_ZEROPOSITION_Enum1_NONE,
}ABSENCALARM_ZEROPOSITION_Enum1;



struct ABSENCALARM_ZEROPOSITION
{
    int ABSENCALARM_mainNUM = 93;
    char ZEROPOSITION_subNUM = 8;
    ABSENCALARM_ZEROPOSITION_Enum0  ENUM0_0;
    ABSENCALARM_ZEROPOSITION_Enum1  ENUM1_1;

    struct ABSENCALARM_ZEROPOSITION* Add_ENUM0_0( ABSENCALARM_ZEROPOSITION_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct ABSENCALARM_ZEROPOSITION* Add_ENUM1_1( ABSENCALARM_ZEROPOSITION_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ZEROPOSITION_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum ABSENCALARM_ZEROPOSITION_QUE_Enum0
{
    ABSENCALARM_ZEROPOSITION_QUE_Enum0_S1,
    ABSENCALARM_ZEROPOSITION_QUE_Enum0_S2,
    ABSENCALARM_ZEROPOSITION_QUE_Enum0_S3,
    ABSENCALARM_ZEROPOSITION_QUE_Enum0_S4,
}ABSENCALARM_ZEROPOSITION_QUE_Enum0;



struct ABSENCALARM_ZEROPOSITION_QUE
{
    int ABSENCALARM_mainNUM = 93;
    char ZEROPOSITION_QUE_subNUM = 9;
    ABSENCALARM_ZEROPOSITION_QUE_Enum0  ENUM0_0;

    struct ABSENCALARM_ZEROPOSITION_QUE* Add_ENUM0_0( ABSENCALARM_ZEROPOSITION_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ZEROPOSITION_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum ABSENCALARM_RESPONSE_Enum0
{
    ABSENCALARM_RESPONSE_Enum0_NONE,
    ABSENCALARM_RESPONSE_Enum0_ALARM,
    ABSENCALARM_RESPONSE_Enum0_STOP,
    ABSENCALARM_RESPONSE_Enum0_ALARM_STOP,
}ABSENCALARM_RESPONSE_Enum0;



struct ABSENCALARM_RESPONSE
{
    int ABSENCALARM_mainNUM = 93;
    char RESPONSE_subNUM = 10;
    ABSENCALARM_RESPONSE_Enum0  ENUM0_0;

    struct ABSENCALARM_RESPONSE* Add_ENUM0_0( ABSENCALARM_RESPONSE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RESPONSE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct ABSENCALARM_RESPONSE_QUE
{
    int ABSENCALARM_mainNUM = 93;
    char RESPONSE_QUE_subNUM = 11;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (ABSENCALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (RESPONSE_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct absencalarm
{
    int  ABSENCALARM_NUM = 93;
    struct ABSENCALARM_STATE  STATE;
    struct ABSENCALARM_STATE_QUE  STATE_QUE;
    struct ABSENCALARM_UPLIMIT  UPLIMIT;
    struct ABSENCALARM_UPLIMIT_QUE  UPLIMIT_QUE;
    struct ABSENCALARM_DOWNLIMIT  DOWNLIMIT;
    struct ABSENCALARM_DOWNLIMIT_QUE  DOWNLIMIT_QUE;
    struct ABSENCALARM_ZEROVALUE  ZEROVALUE;
    struct ABSENCALARM_ZEROVALUE_QUE  ZEROVALUE_QUE;
    struct ABSENCALARM_ZEROPOSITION  ZEROPOSITION;
    struct ABSENCALARM_ZEROPOSITION_QUE  ZEROPOSITION_QUE;
    struct ABSENCALARM_RESPONSE  RESPONSE;
    struct ABSENCALARM_RESPONSE_QUE  RESPONSE_QUE;

}absencalarm;

typedef enum DISTANCEALARM_STATE_Enum0
{
    DISTANCEALARM_STATE_Enum0_S1,
    DISTANCEALARM_STATE_Enum0_S2,
    DISTANCEALARM_STATE_Enum0_S3,
    DISTANCEALARM_STATE_Enum0_S4,
}DISTANCEALARM_STATE_Enum0;

typedef enum DISTANCEALARM_STATE_Enum1
{
    DISTANCEALARM_STATE_Enum1_OFF,
    DISTANCEALARM_STATE_Enum1_ON,
}DISTANCEALARM_STATE_Enum1;



struct DISTANCEALARM_STATE
{
    int DISTANCEALARM_mainNUM = 94;
    char STATE_subNUM = 0;
    DISTANCEALARM_STATE_Enum0  ENUM0_0;
    DISTANCEALARM_STATE_Enum1  ENUM1_1;

    struct DISTANCEALARM_STATE* Add_ENUM0_0( DISTANCEALARM_STATE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DISTANCEALARM_STATE* Add_ENUM1_1( DISTANCEALARM_STATE_Enum1 param )
    {
        ENUM1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DISTANCEALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        cmdData.cmdData[3] = ENUM1_1;
        return cmdData ;
    }

};
typedef enum DISTANCEALARM_STATE_QUE_Enum0
{
    DISTANCEALARM_STATE_QUE_Enum0_S1,
    DISTANCEALARM_STATE_QUE_Enum0_S2,
    DISTANCEALARM_STATE_QUE_Enum0_S3,
    DISTANCEALARM_STATE_QUE_Enum0_S4,
}DISTANCEALARM_STATE_QUE_Enum0;



struct DISTANCEALARM_STATE_QUE
{
    int DISTANCEALARM_mainNUM = 94;
    char STATE_QUE_subNUM = 1;
    DISTANCEALARM_STATE_QUE_Enum0  ENUM0_0;

    struct DISTANCEALARM_STATE_QUE* Add_ENUM0_0( DISTANCEALARM_STATE_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DISTANCEALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM1_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DISTANCEALARM_ALARM1DIST_Enum0
{
    DISTANCEALARM_ALARM1DIST_Enum0_S1,
    DISTANCEALARM_ALARM1DIST_Enum0_S2,
    DISTANCEALARM_ALARM1DIST_Enum0_S3,
    DISTANCEALARM_ALARM1DIST_Enum0_S4,
}DISTANCEALARM_ALARM1DIST_Enum0;



struct DISTANCEALARM_ALARM1DIST
{
    int DISTANCEALARM_mainNUM = 94;
    char ALARM1DIST_subNUM = 2;
    DISTANCEALARM_ALARM1DIST_Enum0  ENUM0_0;
    unsigned short  U16_0_1;

    struct DISTANCEALARM_ALARM1DIST* Add_ENUM0_0( DISTANCEALARM_ALARM1DIST_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DISTANCEALARM_ALARM1DIST* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DISTANCEALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ALARM1DIST_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        return cmdData ;
    }

};
typedef enum DISTANCEALARM_ALARM1DIST_QUE_Enum0
{
    DISTANCEALARM_ALARM1DIST_QUE_Enum0_S1,
    DISTANCEALARM_ALARM1DIST_QUE_Enum0_S2,
    DISTANCEALARM_ALARM1DIST_QUE_Enum0_S3,
    DISTANCEALARM_ALARM1DIST_QUE_Enum0_S4,
}DISTANCEALARM_ALARM1DIST_QUE_Enum0;



struct DISTANCEALARM_ALARM1DIST_QUE
{
    int DISTANCEALARM_mainNUM = 94;
    char ALARM1DIST_QUE_subNUM = 3;
    DISTANCEALARM_ALARM1DIST_QUE_Enum0  ENUM0_0;

    struct DISTANCEALARM_ALARM1DIST_QUE* Add_ENUM0_0( DISTANCEALARM_ALARM1DIST_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DISTANCEALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ALARM1DIST_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DISTANCEALARM_ALARM2DIST_Enum0
{
    DISTANCEALARM_ALARM2DIST_Enum0_S1,
    DISTANCEALARM_ALARM2DIST_Enum0_S2,
    DISTANCEALARM_ALARM2DIST_Enum0_S3,
    DISTANCEALARM_ALARM2DIST_Enum0_S4,
}DISTANCEALARM_ALARM2DIST_Enum0;



struct DISTANCEALARM_ALARM2DIST
{
    int DISTANCEALARM_mainNUM = 94;
    char ALARM2DIST_subNUM = 4;
    DISTANCEALARM_ALARM2DIST_Enum0  ENUM0_0;
    unsigned short  U16_0_1;

    struct DISTANCEALARM_ALARM2DIST* Add_ENUM0_0( DISTANCEALARM_ALARM2DIST_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DISTANCEALARM_ALARM2DIST* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DISTANCEALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ALARM2DIST_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        return cmdData ;
    }

};
typedef enum DISTANCEALARM_ALARM2DIST_QUE_Enum0
{
    DISTANCEALARM_ALARM2DIST_QUE_Enum0_S1,
    DISTANCEALARM_ALARM2DIST_QUE_Enum0_S2,
    DISTANCEALARM_ALARM2DIST_QUE_Enum0_S3,
    DISTANCEALARM_ALARM2DIST_QUE_Enum0_S4,
}DISTANCEALARM_ALARM2DIST_QUE_Enum0;



struct DISTANCEALARM_ALARM2DIST_QUE
{
    int DISTANCEALARM_mainNUM = 94;
    char ALARM2DIST_QUE_subNUM = 5;
    DISTANCEALARM_ALARM2DIST_QUE_Enum0  ENUM0_0;

    struct DISTANCEALARM_ALARM2DIST_QUE* Add_ENUM0_0( DISTANCEALARM_ALARM2DIST_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DISTANCEALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ALARM2DIST_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum DISTANCEALARM_ALARM3DIST_Enum0
{
    DISTANCEALARM_ALARM3DIST_Enum0_S1,
    DISTANCEALARM_ALARM3DIST_Enum0_S2,
    DISTANCEALARM_ALARM3DIST_Enum0_S3,
    DISTANCEALARM_ALARM3DIST_Enum0_S4,
}DISTANCEALARM_ALARM3DIST_Enum0;



struct DISTANCEALARM_ALARM3DIST
{
    int DISTANCEALARM_mainNUM = 94;
    char ALARM3DIST_subNUM = 6;
    DISTANCEALARM_ALARM3DIST_Enum0  ENUM0_0;
    unsigned short  U16_0_1;

    struct DISTANCEALARM_ALARM3DIST* Add_ENUM0_0( DISTANCEALARM_ALARM3DIST_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct DISTANCEALARM_ALARM3DIST* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DISTANCEALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ALARM3DIST_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        return cmdData ;
    }

};
typedef enum DISTANCEALARM_ALARM3DIST_QUE_Enum0
{
    DISTANCEALARM_ALARM3DIST_QUE_Enum0_S1,
    DISTANCEALARM_ALARM3DIST_QUE_Enum0_S2,
    DISTANCEALARM_ALARM3DIST_QUE_Enum0_S3,
    DISTANCEALARM_ALARM3DIST_QUE_Enum0_S4,
}DISTANCEALARM_ALARM3DIST_QUE_Enum0;



struct DISTANCEALARM_ALARM3DIST_QUE
{
    int DISTANCEALARM_mainNUM = 94;
    char ALARM3DIST_QUE_subNUM = 7;
    DISTANCEALARM_ALARM3DIST_QUE_Enum0  ENUM0_0;

    struct DISTANCEALARM_ALARM3DIST_QUE* Add_ENUM0_0( DISTANCEALARM_ALARM3DIST_QUE_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (DISTANCEALARM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ALARM3DIST_QUE_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct distancealarm
{
    int  DISTANCEALARM_NUM = 94;
    struct DISTANCEALARM_STATE  STATE;
    struct DISTANCEALARM_STATE_QUE  STATE_QUE;
    struct DISTANCEALARM_ALARM1DIST  ALARM1DIST;
    struct DISTANCEALARM_ALARM1DIST_QUE  ALARM1DIST_QUE;
    struct DISTANCEALARM_ALARM2DIST  ALARM2DIST;
    struct DISTANCEALARM_ALARM2DIST_QUE  ALARM2DIST_QUE;
    struct DISTANCEALARM_ALARM3DIST  ALARM3DIST;
    struct DISTANCEALARM_ALARM3DIST_QUE  ALARM3DIST_QUE;

}distancealarm;



struct NEWDRIVER_TYPE_QUE
{
    int NEWDRIVER_mainNUM = 95;
    char TYPE_QUE_subNUM = 0;
    unsigned char  U8_0_0;

    struct NEWDRIVER_TYPE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (NEWDRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (TYPE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct NEWDRIVER_CURRENT
{
    int NEWDRIVER_mainNUM = 95;
    char CURRENT_subNUM = 1;
    unsigned char  U8_0_0;

    struct NEWDRIVER_CURRENT* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (NEWDRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CURRENT_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }

};


struct NEWDRIVER_CURRENT_QUE
{
    int NEWDRIVER_mainNUM = 95;
    char CURRENT_QUE_subNUM = 2;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (NEWDRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (CURRENT_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum NEWDRIVER_MICROSTEPS_Enum0
{
    NEWDRIVER_MICROSTEPS_Enum0_RESERVE0,
    NEWDRIVER_MICROSTEPS_Enum0_RESERVE1,
    NEWDRIVER_MICROSTEPS_Enum0_RESERVE2,
    NEWDRIVER_MICROSTEPS_Enum0_32,
    NEWDRIVER_MICROSTEPS_Enum0_16,
    NEWDRIVER_MICROSTEPS_Enum0_8,
    NEWDRIVER_MICROSTEPS_Enum0_4,
    NEWDRIVER_MICROSTEPS_Enum0_2,
    NEWDRIVER_MICROSTEPS_Enum0_1,
}NEWDRIVER_MICROSTEPS_Enum0;



struct NEWDRIVER_MICROSTEPS
{
    int NEWDRIVER_mainNUM = 95;
    char MICROSTEPS_subNUM = 3;
    NEWDRIVER_MICROSTEPS_Enum0  ENUM0_0;

    struct NEWDRIVER_MICROSTEPS* Add_ENUM0_0( NEWDRIVER_MICROSTEPS_Enum0 param )
    {
        ENUM0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (NEWDRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MICROSTEPS_subNUM );
        cmdData.cmdData[2] = ENUM0_0;
        return cmdData ;
    }

};


struct NEWDRIVER_MICROSTEPS_QUE
{
    int NEWDRIVER_mainNUM = 95;
    char MICROSTEPS_QUE_subNUM = 4;

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (NEWDRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MICROSTEPS_QUE_subNUM );
        return cmdData ;
    }
    unsigned char analysis_ENUM0_0 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};
typedef enum NEWDRIVER_STATE_Enum0
{
    NEWDRIVER_STATE_Enum0_OFF,
    NEWDRIVER_STATE_Enum0_ON,
}NEWDRIVER_STATE_Enum0;



struct NEWDRIVER_STATE
{
    int NEWDRIVER_mainNUM = 95;
    char STATE_subNUM = 5;
    unsigned char  U8_0_0;
    NEWDRIVER_STATE_Enum0  ENUM0_1;

    struct NEWDRIVER_STATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct NEWDRIVER_STATE* Add_ENUM0_1( NEWDRIVER_STATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (NEWDRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct NEWDRIVER_STATE_QUE
{
    int NEWDRIVER_mainNUM = 95;
    char STATE_QUE_subNUM = 6;
    unsigned char  U8_0_0;

    struct NEWDRIVER_STATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (NEWDRIVER_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (STATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};

/*****************************************************/
typedef struct newdriver
{
    int  NEWDRIVER_NUM = 95;
    struct NEWDRIVER_TYPE_QUE  TYPE_QUE;
    struct NEWDRIVER_CURRENT  CURRENT;
    struct NEWDRIVER_CURRENT_QUE  CURRENT_QUE;
    struct NEWDRIVER_MICROSTEPS  MICROSTEPS;
    struct NEWDRIVER_MICROSTEPS_QUE  MICROSTEPS_QUE;
    struct NEWDRIVER_STATE  STATE;
    struct NEWDRIVER_STATE_QUE  STATE_QUE;

}newdriver;

typedef enum PDM_SAMPLESTATE_Enum0
{
    PDM_SAMPLESTATE_Enum0_END,
    PDM_SAMPLESTATE_Enum0_START,
}PDM_SAMPLESTATE_Enum0;



struct PDM_SAMPLESTATE
{
    int PDM_mainNUM = 96;
    char SAMPLESTATE_subNUM = 0;
    unsigned char  U8_0_0;
    PDM_SAMPLESTATE_Enum0  ENUM0_1;

    struct PDM_SAMPLESTATE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct PDM_SAMPLESTATE* Add_ENUM0_1( PDM_SAMPLESTATE_Enum0 param )
    {
        ENUM0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (PDM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SAMPLESTATE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        cmdData.cmdData[3] = ENUM0_1;
        return cmdData ;
    }

};


struct PDM_SAMPLESTATE_QUE
{
    int PDM_mainNUM = 96;
    char SAMPLESTATE_QUE_subNUM = 1;
    unsigned char  U8_0_0;

    struct PDM_SAMPLESTATE_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (PDM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (SAMPLESTATE_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_ENUM0_1 ( CAN_OBJ * ReturnValue ) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * enumValue = (unsigned char *)tmp; 
            return * enumValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct PDM_ENCDIV
{
    int PDM_mainNUM = 96;
    char ENCDIV_subNUM = 2;
    unsigned char  U8_0_0;
    unsigned char  U8_1_1;

    struct PDM_ENCDIV* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct PDM_ENCDIV* Add_U8_1_1( unsigned char param )
    {
        U8_1_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (PDM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ENCDIV_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU8_1_1 = (char *) &U8_1_1 ;
        cmdData.cmdData[3] = *( ptrU8_1_1++);
        return cmdData ;
    }

};


struct PDM_ENCDIV_QUE
{
    int PDM_mainNUM = 96;
    char ENCDIV_QUE_subNUM = 3;
    unsigned char  U8_0_0;

    struct PDM_ENCDIV_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (PDM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (ENCDIV_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned char analysis_U8_1_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct PDM_MICSTEPCOUNT_QUE
{
    int PDM_mainNUM = 96;
    char MICSTEPCOUNT_QUE_subNUM = 4;
    unsigned char  U8_0_0;
    unsigned short  U16_0_1;

    struct PDM_MICSTEPCOUNT_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct PDM_MICSTEPCOUNT_QUE* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (PDM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MICSTEPCOUNT_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        return cmdData ;
    }
    unsigned char analysis_U8_0_0 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[2]);
            unsigned char * ucharValue = (unsigned char *)tmp; 
            return * ucharValue;
        }
        else 
        {
            return 0;
        }
    } 

    unsigned short analysis_U16_0_1 (CAN_OBJ * ReturnValue) 
    { 
        if (ReturnValue != nullptr )
        {
            char * tmp = &(ReturnValue->Data[3]);
            unsigned short * ushortValue = (unsigned short *)tmp; 
            return * ushortValue;
        }
        else 
        {
            return 0;
        }
    } 


};


struct PDM_MICSTEPDATA_QUE
{
    int PDM_mainNUM = 96;
    char MICSTEPDATA_QUE_subNUM = 5;
    unsigned char  U8_0_0;
    unsigned short  U16_0_1;
    unsigned short  U16_1_2;

    struct PDM_MICSTEPDATA_QUE* Add_U8_0_0( unsigned char param )
    {
        U8_0_0 = param ;
        return this ;
    }

    struct PDM_MICSTEPDATA_QUE* Add_U16_0_1( unsigned short param )
    {
        U16_0_1 = param ;
        return this ;
    }

    struct PDM_MICSTEPDATA_QUE* Add_U16_1_2( unsigned short param )
    {
        U16_1_2 = param ;
        return this ;
    }

    struct GetCmd_Arr  GetCmdData()
    {
        struct GetCmd_Arr  cmdData;
        cmdData.cmdData[0] = static_cast<unsigned char > (PDM_mainNUM );
        cmdData.cmdData[1] = static_cast<char > (MICSTEPDATA_QUE_subNUM );
        char * ptrU8_0_0 = (char *) &U8_0_0 ;
        cmdData.cmdData[2] = *( ptrU8_0_0++);
        char * ptrU16_0_1 = (char *) &U16_0_1 ;
        cmdData.cmdData[3] = *( ptrU16_0_1++);
        cmdData.cmdData[4] = *( ptrU16_0_1++);
        char * ptrU16_1_2 = (char *) &U16_1_2 ;
        cmdData.cmdData[5] = *( ptrU16_1_2++);
        cmdData.cmdData[6] = *( ptrU16_1_2++);
        return cmdData ;
    }

};

/*****************************************************/
typedef struct pdm
{
    int  PDM_NUM = 96;
    struct PDM_SAMPLESTATE  SAMPLESTATE;
    struct PDM_SAMPLESTATE_QUE  SAMPLESTATE_QUE;
    struct PDM_ENCDIV  ENCDIV;
    struct PDM_ENCDIV_QUE  ENCDIV_QUE;
    struct PDM_MICSTEPCOUNT_QUE  MICSTEPCOUNT_QUE;
    struct PDM_MICSTEPDATA_QUE  MICSTEPDATA_QUE;

}pdm;




/*****************************************************/
typedef struct  Cmd
{
    link  LINK;
    system  SYSTEM;
    rs232  RS232;
    can  CAN;
    clock  CLOCK;
    motion  MOTION;
    identity  IDENTITY;
    motor  MOTOR;
    encoder  ENCODER;
    motionplan  MOTIONPLAN;
    position  POSITION;
    position_que  POSITION_QUE;
    velocity  VELOCITY;
    velocity_que  VELOCITY_QUE;
    time  TIME;
    time_que  TIME_QUE;
    timescale  TIMESCALE;
    timescale_que  TIMESCALE_QUE;
    report  REPORT;
    trigger  TRIGGER;
    driver  DRIVER;
    digitaloutput  DIGITALOUTPUT;
    isolatoroutput  ISOLATOROUTPUT;
    sensoruart  SENSORUART;
    tuning  TUNING;
    isolatorin  ISOLATORIN;
    absencalarm  ABSENCALARM;
    distancealarm  DISTANCEALARM;
    newdriver  NEWDRIVER;
    pdm  PDM;
} Cmd ;

}
#endif 
