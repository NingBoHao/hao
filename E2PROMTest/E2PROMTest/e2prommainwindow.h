#ifndef E2PROMMAINWINDOW_H
#define E2PROMMAINWINDOW_H

#include <QMainWindow>
#include "Include/comStruct.h"
#include <ctype.h>
#include <typeinfo>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QTreeWidgetItem>
namespace Ui {
class E2PROMMainWindow;
}

class E2PROMMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit E2PROMMainWindow(QWidget *parent = nullptr);
    ~E2PROMMainWindow();
    void analysisStruct(QString StructFileNamePath);
    void addtree_node(QTreeWidgetItem  *parent ,QString name , QString dec_value ,QString hex_value ,QString type );

private slots:
    void on_Struct_Path_pushButton_clicked();

    void on_struct_All_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_Struct_Path_lineEdit_textChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::E2PROMMainWindow *ui;

    BootInfoStruct    g_bootInfo;
    CommIntfcStruct   g_commIntfc;
    PlanInfoStruct    g_planInfo;
    #ifdef PROJECT_GELGOOG
    #pragma location = "PVTPOINT_SECTION"
    #endif
    PvtInfoStruct  pvtPointBuffer[CH_TOTAL];
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


    QString Struct_FilePath;
    QString Struct_CurrentFileName;



    QString StructFileName ;


};

#endif // E2PROMMAINWINDOW_H
