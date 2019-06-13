#-------------------------------------------------
#
# Project created by QtCreator 2019-04-30T13:44:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = E2PROMTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        e2prommainwindow.cpp \

HEADERS += \
        e2prommainwindow.h \
    Include/bspTimer.h \
    Include/comCmd.h \
    Include/comDatatype.h \
    Include/comDebug.h \
    Include/comEnum.h \
    Include/comErrorcode.h \
    Include/comInterface.h \
    Include/comMemoryMap.h \
    Include/comStruct.h \
    Include/project.h \
    Include/pvtAlgorithm.h \
    Include/chartdefine.h \
    Include/bspCan.h \
    Include/bspUart.h

FORMS += \
        e2prommainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
