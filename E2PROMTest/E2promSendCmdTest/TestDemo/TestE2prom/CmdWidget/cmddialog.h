#ifndef CMDDIALOG_H
#define CMDDIALOG_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QComboBox>
#include <QLabel>
#include <QStringList>
#include "xlsxdocument.h"
#include <QValidator>
#include <QString>

#include "cancommuniction.h"
#include "Global/deviceinfo.h"
namespace Ui {
class cmdDialog;
}

class cmdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit cmdDialog(QWidget *parent = nullptr);
    void initCmdDialog();
    ~cmdDialog();

public slots:
    void on_MainCmdchanged(int indexOffset);
    void on_SubCmdchanged(int indexOffset);

    /*选取完命令索引后获取命令数据*/
    void GetCmdData();
    void floatText(const QString & text);

    int setComm(CANcommuniction * setCan);

    /*初始化设备信息*/
    void initDeviceInfo(DeviceInfo* p_deviceInfo);
    /*设置SENDID */
    void setSENDID(unsigned int p_sendId);
signals:
    void signals_CmdData(QList<char > CmdData);
private slots:
    void on_sendPushButton_clicked();
    /*发送命令数据*/
    void sendCmdData();


private:
    Ui::cmdDialog *ui;
    QComboBox mainCmd;
    QComboBox subCmd;
    QLabel mainLable;
    QLabel subLable;

    QList<QLabel * > Lable;
    QList<QLineEdit * > LineEdit;
    QList<QComboBox * > ENUM;

    QXlsx::Document *xlsx;

    int mainCmdIndex;
    int mainCmdCount;

    QString currentMainStr;
    int currentMainCmdNum;
    int subCmdIndex;
    int subCmdCount;

    QString currentSubStr;
    int currentSubCmdNum;

    char cmdData[10];

    /*通讯用的CAN句柄*/
    CANcommuniction * can = nullptr;

    /*广播ID*/
    unsigned int BROADCASTID = 1;
    /*SENDID 发送ID*/
    unsigned int SENDID = 1;
    /*设备信息信息*/
    DeviceInfo * deviceInfo;

};

#endif // CMDDIALOG_H
