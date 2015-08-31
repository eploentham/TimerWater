#-------------------------------------------------
#
# Project created by QtCreator 2015-08-28T18:45:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = timerwater
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frmtimer.cpp \
    frmsensor.cpp \
    frmtemp.cpp \
    dialog.cpp \
    frminitial.cpp

HEADERS  += mainwindow.h \
    frmtimer.h \
    frmsensor.h \
    frmtemp.h \
    dialog.h \
    frminitial.h

FORMS    += mainwindow.ui \
    frmtimer.ui \
    frmsensor.ui \
    frmtemp.ui \
    dialog.ui \
    frminitial.ui
