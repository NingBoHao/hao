/********************************************************************************
** Form generated from reading UI file 'cmddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMDDIALOG_H
#define UI_CMDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_cmdDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *sendPushButton;

    void setupUi(QDialog *cmdDialog)
    {
        if (cmdDialog->objectName().isEmpty())
            cmdDialog->setObjectName(QString::fromUtf8("cmdDialog"));
        cmdDialog->resize(419, 457);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmdDialog->sizePolicy().hasHeightForWidth());
        cmdDialog->setSizePolicy(sizePolicy);
        cmdDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(cmdDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        sendPushButton = new QPushButton(cmdDialog);
        sendPushButton->setObjectName(QString::fromUtf8("sendPushButton"));

        verticalLayout->addWidget(sendPushButton);


        retranslateUi(cmdDialog);

        QMetaObject::connectSlotsByName(cmdDialog);
    } // setupUi

    void retranslateUi(QDialog *cmdDialog)
    {
        cmdDialog->setWindowTitle(QApplication::translate("cmdDialog", "Dialog", nullptr));
        sendPushButton->setText(QApplication::translate("cmdDialog", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cmdDialog: public Ui_cmdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMDDIALOG_H
