/********************************************************************************
** Form generated from reading UI file 'e2prommainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_E2PROMMAINWINDOW_H
#define UI_E2PROMMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_E2PROMMainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *Struct_Path_lineEdit;
    QPushButton *Struct_Path_pushButton;
    QHBoxLayout *horizontalLayout;
    QComboBox *struct_All_comboBox;
    QPushButton *pushButton;
    QLabel *label;
    QComboBox *comboBox;
    QTreeWidget *Struct_treeWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *E2PROMMainWindow)
    {
        if (E2PROMMainWindow->objectName().isEmpty())
            E2PROMMainWindow->setObjectName(QString::fromUtf8("E2PROMMainWindow"));
        E2PROMMainWindow->resize(622, 521);
        centralWidget = new QWidget(E2PROMMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Struct_Path_lineEdit = new QLineEdit(centralWidget);
        Struct_Path_lineEdit->setObjectName(QString::fromUtf8("Struct_Path_lineEdit"));

        verticalLayout->addWidget(Struct_Path_lineEdit);

        Struct_Path_pushButton = new QPushButton(centralWidget);
        Struct_Path_pushButton->setObjectName(QString::fromUtf8("Struct_Path_pushButton"));

        verticalLayout->addWidget(Struct_Path_pushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        struct_All_comboBox = new QComboBox(centralWidget);
        struct_All_comboBox->setObjectName(QString::fromUtf8("struct_All_comboBox"));

        horizontalLayout->addWidget(struct_All_comboBox);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        Struct_treeWidget = new QTreeWidget(centralWidget);
        Struct_treeWidget->setObjectName(QString::fromUtf8("Struct_treeWidget"));

        verticalLayout->addWidget(Struct_treeWidget);

        E2PROMMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(E2PROMMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 622, 23));
        E2PROMMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(E2PROMMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        E2PROMMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(E2PROMMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        E2PROMMainWindow->setStatusBar(statusBar);

        retranslateUi(E2PROMMainWindow);

        QMetaObject::connectSlotsByName(E2PROMMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *E2PROMMainWindow)
    {
        E2PROMMainWindow->setWindowTitle(QApplication::translate("E2PROMMainWindow", "E2PROMMainWindow", nullptr));
        Struct_Path_pushButton->setText(QApplication::translate("E2PROMMainWindow", "\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
        pushButton->setText(QApplication::translate("E2PROMMainWindow", "\345\210\267\346\226\260", nullptr));
        label->setText(QApplication::translate("E2PROMMainWindow", "\347\273\223\346\236\204\344\275\223\347\261\273\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class E2PROMMainWindow: public Ui_E2PROMMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_E2PROMMAINWINDOW_H
