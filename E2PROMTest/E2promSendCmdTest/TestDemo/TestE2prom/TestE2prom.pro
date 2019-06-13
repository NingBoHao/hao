#-------------------------------------------------
#
# Project created by QtCreator 2019-05-13T13:16:51
#
#-------------------------------------------------

QT       += core gui #xlsx

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestE2prom
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
DESTDIR  = $$PWD
SOURCES += \
        main.cpp \
        teste2promwidget.cpp \
    cancommuniction.cpp \
    CmdWidget/cmddialog.cpp \
    Global/deviceinfohandle.cpp

HEADERS += \
        teste2promwidget.h \
    cancommuniction.h \
    CmdWidget/cmddialog.h \
    Global/deviceinfo.h \
    Global/deviceinfohandle.h \
    CmdStruct/cmdstruct.h

FORMS += \
        teste2promwidget.ui \
    CmdWidget/cmddialog.ui
include(./Qtxlsx/src/xlsx/qtxlsx.pri)
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
