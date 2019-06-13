/********************************************************************************
** Form generated from reading UI file 'teste2promwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTE2PROMWIDGET_H
#define UI_TESTE2PROMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestE2promWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *SetCmd_lineEdit;
    QPushButton *SetCmdSelectpushButton;
    QPushButton *StartpushButton;
    QSpinBox *Cmd_find_spliter_spinBox;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *QueCmdSelectpushButton;
    QLineEdit *FindCmd_lineEdit;
    QLabel *label_5;
    QPushButton *StoppushButton;
    QSpinBox *Cmd_find_spliter_Add_spinBox;
    QLabel *label;
    QSpinBox *Cmd_find_Timer_spinBox;
    QPushButton *pushButton;

    void setupUi(QWidget *TestE2promWidget)
    {
        if (TestE2promWidget->objectName().isEmpty())
            TestE2promWidget->setObjectName(QString::fromUtf8("TestE2promWidget"));
        TestE2promWidget->resize(622, 127);
        verticalLayout = new QVBoxLayout(TestE2promWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(TestE2promWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        SetCmd_lineEdit = new QLineEdit(TestE2promWidget);
        SetCmd_lineEdit->setObjectName(QString::fromUtf8("SetCmd_lineEdit"));

        gridLayout->addWidget(SetCmd_lineEdit, 0, 1, 1, 3);

        SetCmdSelectpushButton = new QPushButton(TestE2promWidget);
        SetCmdSelectpushButton->setObjectName(QString::fromUtf8("SetCmdSelectpushButton"));

        gridLayout->addWidget(SetCmdSelectpushButton, 0, 4, 1, 2);

        StartpushButton = new QPushButton(TestE2promWidget);
        StartpushButton->setObjectName(QString::fromUtf8("StartpushButton"));

        gridLayout->addWidget(StartpushButton, 4, 0, 1, 2);

        Cmd_find_spliter_spinBox = new QSpinBox(TestE2promWidget);
        Cmd_find_spliter_spinBox->setObjectName(QString::fromUtf8("Cmd_find_spliter_spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cmd_find_spliter_spinBox->sizePolicy().hasHeightForWidth());
        Cmd_find_spliter_spinBox->setSizePolicy(sizePolicy);
        Cmd_find_spliter_spinBox->setMaximum(999999999);
        Cmd_find_spliter_spinBox->setValue(1);

        gridLayout->addWidget(Cmd_find_spliter_spinBox, 0, 7, 1, 1);

        label_2 = new QLabel(TestE2promWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 0, 6, 1, 1);

        label_3 = new QLabel(TestE2promWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_3, 0, 8, 1, 1);

        QueCmdSelectpushButton = new QPushButton(TestE2promWidget);
        QueCmdSelectpushButton->setObjectName(QString::fromUtf8("QueCmdSelectpushButton"));

        gridLayout->addWidget(QueCmdSelectpushButton, 1, 4, 1, 2);

        FindCmd_lineEdit = new QLineEdit(TestE2promWidget);
        FindCmd_lineEdit->setObjectName(QString::fromUtf8("FindCmd_lineEdit"));

        gridLayout->addWidget(FindCmd_lineEdit, 1, 1, 1, 3);

        label_5 = new QLabel(TestE2promWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        StoppushButton = new QPushButton(TestE2promWidget);
        StoppushButton->setObjectName(QString::fromUtf8("StoppushButton"));

        gridLayout->addWidget(StoppushButton, 4, 2, 1, 2);

        Cmd_find_spliter_Add_spinBox = new QSpinBox(TestE2promWidget);
        Cmd_find_spliter_Add_spinBox->setObjectName(QString::fromUtf8("Cmd_find_spliter_Add_spinBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Cmd_find_spliter_Add_spinBox->sizePolicy().hasHeightForWidth());
        Cmd_find_spliter_Add_spinBox->setSizePolicy(sizePolicy2);
        Cmd_find_spliter_Add_spinBox->setMaximum(999999999);
        Cmd_find_spliter_Add_spinBox->setValue(1);

        gridLayout->addWidget(Cmd_find_spliter_Add_spinBox, 0, 9, 1, 1);

        label = new QLabel(TestE2promWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 1, 6, 1, 1);

        Cmd_find_Timer_spinBox = new QSpinBox(TestE2promWidget);
        Cmd_find_Timer_spinBox->setObjectName(QString::fromUtf8("Cmd_find_Timer_spinBox"));
        sizePolicy2.setHeightForWidth(Cmd_find_Timer_spinBox->sizePolicy().hasHeightForWidth());
        Cmd_find_Timer_spinBox->setSizePolicy(sizePolicy2);
        Cmd_find_Timer_spinBox->setMaximum(99999999);
        Cmd_find_Timer_spinBox->setValue(1);

        gridLayout->addWidget(Cmd_find_Timer_spinBox, 1, 7, 1, 1);

        pushButton = new QPushButton(TestE2promWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 4, 9, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(TestE2promWidget);

        QMetaObject::connectSlotsByName(TestE2promWidget);
    } // setupUi

    void retranslateUi(QWidget *TestE2promWidget)
    {
        TestE2promWidget->setWindowTitle(QApplication::translate("TestE2promWidget", "TestE2promWidget", nullptr));
        label_4->setText(QApplication::translate("TestE2promWidget", "\345\221\275\344\273\244\350\256\276\347\275\256", nullptr));
        SetCmdSelectpushButton->setText(QApplication::translate("TestE2promWidget", "SetCmdSelect", nullptr));
        StartpushButton->setText(QApplication::translate("TestE2promWidget", "\345\220\257\345\212\250", nullptr));
        label_2->setText(QApplication::translate("TestE2promWidget", "\345\221\275\344\273\244\346\237\245\350\256\276\347\275\256\351\227\264\351\232\224ms", nullptr));
        label_3->setText(QApplication::translate("TestE2promWidget", "\351\227\264\351\232\224\345\242\236\351\225\277\351\207\217ms", nullptr));
        QueCmdSelectpushButton->setText(QApplication::translate("TestE2promWidget", "QueCmdSelect", nullptr));
        label_5->setText(QApplication::translate("TestE2promWidget", "\345\221\275\344\273\244\346\237\245\350\257\242", nullptr));
        StoppushButton->setText(QApplication::translate("TestE2promWidget", "\345\201\234\346\255\242", nullptr));
        label->setText(QApplication::translate("TestE2promWidget", "\345\221\275\344\273\244\346\237\245\350\257\242\345\221\250\346\234\237ms", nullptr));
        pushButton->setText(QApplication::translate("TestE2promWidget", "\350\277\236\346\216\245\346\210\220\345\212\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestE2promWidget: public Ui_TestE2promWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTE2PROMWIDGET_H
