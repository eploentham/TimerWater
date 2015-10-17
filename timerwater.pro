#-------------------------------------------------
#
# Project created by QtCreator 2015-08-28T18:45:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = timerwater
TEMPLATE = app

QT           += sql
QTPLUGIN += QSQLMYSQL
INCLUDEPATH += /usr/include/mysql
INCLUDEPATH += /opt/Qt/Tools/QtCreator/bin/plugins/sqldrivers
QMAKE_LIBDIR += /opt/Qt/Tools/QtCreator/bin/plugins/sqldrivers

SOURCES += main.cpp\
        mainwindow.cpp \
    frmtimer.cpp \
    frmsensor.cpp \
    frmtemp.cpp \
    dialog.cpp \
    frminitial.cpp \
    frmtimer1.cpp \
    frmroutepump.cpp \
    frmroute.cpp \
    frmsensor1.cpp \
    frmstartwork.cpp \
    timer.cpp \
    timer2.cpp \
    timerwatercontrol.cpp \
    frmopennow.cpp \
    opennow.cpp \
    frmcalendar.cpp \
    connectiondb.cpp \
    sensor.cpp \
    frmnodemcu.cpp

HEADERS  += mainwindow.h \
    frmtimer.h \
    frmsensor.h \
    frmtemp.h \
    dialog.h \
    frminitial.h \
    frmtimer1.h \
    frmroutepump.h \
    frmroute.h \
    frmsensor1.h \
    frmstartwork.h \
    timer.h \
    timer2.h \
    timerwatercontrol.h \
    frmopennow.h \
    opennow.h \
    frmcalendar.h \
    connectiondb.h \
    sensor.h \
    frmnodemcu.h

FORMS    += mainwindow.ui \
    frmtimer.ui \
    frmsensor.ui \
    frmtemp.ui \
    dialog.ui \
    frminitial.ui \
    frmtimer1.ui \
    frmroutepump.ui \
    frmroute.ui \
    frmsensor1.ui \
    frmstartwork.ui \
    frmopennow.ui \
    frmcalendar.ui \
    frmnodemcu.ui
