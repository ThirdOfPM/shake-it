#-------------------------------------------------
#
# Project created by QtCreator 2018-04-02T09:51:34
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shake-it
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


SOURCES += \
        main.cpp \
        mainscreen.cpp \
    regscreen.cpp \
    logscreen.cpp \
    adminscreen.cpp \
    onlinescreen.cpp \
    adminlogdialog.cpp \
    mapwidget.cpp \
    user.cpp \
    onlineuser.cpp \
    message.cpp \
    messagewidget.cpp \
    scrolablemessageslayout.cpp

HEADERS += \
        mainscreen.h \
    regscreen.h \
    logscreen.h \
    adminscreen.h \
    onlinescreen.h \
    adminlogdialog.h \
    mapwidget.h \
    user.h \
    onlineuser.h \
    message.h \
    messagewidget.h \
    scrolablemessageslayout.h

FORMS += \
        mainscreen.ui \
    regscreen.ui \
    logscreen.ui \
    adminscreen.ui \
    onlinescreen.ui \
    adminlogdialog.ui \
    mapwidget.ui \
    messagewidget.ui \
    scrolablemessageslayout.ui
