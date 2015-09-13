#include "timerwatercontrol.h"
#include <QDebug>
#include <QSettings>
TimerWaterControl::TimerWaterControl(QString path)
{
    fileIni = path + "/timerwater.ini";
    refreshTim1Active();
}

QString TimerWaterControl::mapDay(QString day){
    if(day=="1")        return "monday";
    else if(day=="2")        return "tuesday";
    else if(day=="3")        return "wednesday";
    else if(day=="4")        return "thursday";
    else if(day=="5")        return "friday";
    else if(day=="6")        return "saturday";
    else if(day=="7")        return "sunday";
    else        return "";
}
Timer TimerWaterControl::readSettingsTimer(int row){
    QSettings ss(fileIni, QSettings::IniFormat);
    Timer tim;
    //QSettings ss(fileIni, QSettings::IniFormat);
    //qDebug() << "readSettingsTimer "+QString::number(row);
    ss.beginGroup("Timer"+QString::number(row));

    ss.value("monday").toString()=="on" ? tim.monday="on":tim.monday="off";
    ss.value("tueday").toString()=="on" ? tim.tuesday="on":tim.tuesday="off";
    ss.value("wednesday").toString()=="on" ? tim.wednesday="on":tim.wednesday="off";
    ss.value("thurday").toString()=="on" ? tim.thursday="on":tim.thursday="off";
    ss.value("friday").toString()=="on" ? tim.friday="on":tim.friday="off";
    ss.value("saturday").toString()=="on" ? tim.saturday="on":tim.saturday="off";
    ss.value("sunday").toString()=="on" ? tim.sunday="on":tim.sunday="off";
    ss.value("active").toString()=="on" ? tim.Active="1":tim.Active="0";
    ss.value("rainnoON").toString()=="on" ? tim.RainonON="on":tim.RainonON="off";
    ss.value("rainrelayON").toString()=="on" ? tim.RainrelayON="on":tim.RainrelayON="off";

    tim.TimeStart = ss.value("timestart").toString();
    tim.TimeEnd = ss.value("timeend").toString();
    tim.TriggerTime = ss.value("triggertime").toString();
    tim.TriggerPort = ss.value("triggerport").toString();
    tim.TimePeriod = ss.value("timeperiod").toString();
    tim.Description = ss.value("description").toString();
    ss.endGroup();
    return tim;
}
void TimerWaterControl::writeSettingsTimer(int row, Timer p){
    QSettings ss(fileIni, QSettings::IniFormat);
    ss.beginGroup("Timer"+QString::number(row));

    ss.setValue("description",p.Description);
    ss.setValue("active",p.Active);
    ss.setValue("monday",p.monday);
    ss.setValue("tueday",p.tuesday);
    ss.setValue("wednesday",p.wednesday);

    ss.setValue("thurday",p.thursday);
    ss.setValue("friday",p.friday);
    ss.setValue("saturday",p.saturday);
    ss.setValue("sunday",p.sunday);
    ss.setValue("RainonON",p.RainonON);

    ss.setValue("RainrelayON",p.RainrelayON);
    ss.setValue("timestart",p.TimeStart);
    ss.setValue("timeend",p.TimeEnd);
    ss.setValue("triggertime",p.TriggerTime);

    ss.setValue("triggerport",p.TriggerPort);
    ss.setValue("timeperiod",p.TimePeriod);
    //ss.setValue("timeend",p.timeend);
    //ss.setValue("timeend",p.timeend);

    ss.endGroup();
}
void TimerWaterControl::refreshTim1Active(){
    tim1.clear();
    for(int i=1;i<=20;i++){
        Timer tim = readSettingsTimer(i);
        if(tim.Active=="1"){
            tim1.append(tim);
            //Debug() << "refreshTim1Active "+tim.Active+QString::number(i);

            //qDebug() << "refreshTim1Active append"+tim.Active;
        }
    }
}
Timer TimerWaterControl::getTimerON(QDateTime dt){
    //bool chk=false;
    Timer chk;
    QString day = QString::number(dt.date().dayOfWeek());
    QString time = dt.time().toString();
    //time = time.mid(0,5);
    qDebug() << "day "+day;
    qDebug() << "time "+time;
    for(int i=0;i<tim1.size();i++){
        QString map = "";
        if(day=="1" && tim1[i].monday=="on"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }else if(day=="2" && tim1[i].tuesday=="on"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }
        else if(day=="3" && tim1[i].wednesday=="on"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }else if(day=="4" && tim1[i].thursday=="on"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }
        else if(day=="5" && tim1[i].friday=="on"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }else if(day=="6" && tim1[i].saturday=="on"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }
        else if(day=="7" && tim1[i].sunday=="on"){
            qDebug() << "5555 day "+day+" sunday "+tim1[i].sunday;
                qDebug() << "5555 time "+time + "  tim1[i].TimeStart "+tim1[i].TimeStart;
                if(tim1[i].TimeStart==time){
                    qDebug() << "999999";
                    chk=tim1[i];
                }
        }
    }
    return chk;
}
Timer TimerWaterControl::getTimerOFF(QDateTime dt){
    //bool chk=false;
    Timer chk;
    QString day = QString::number(dt.date().dayOfWeek());
    QString time = dt.time().toString();
    //time = time.mid(0,5);
    qDebug() << "day "+day;
    qDebug() << "time "+time;
    for(int i=0;i<tim1.size();i++){
        QString map = "";
        if(day=="1" && tim1[i].monday=="off"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }else if(day=="2" && tim1[i].tuesday=="off"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }
        else if(day=="3" && tim1[i].wednesday=="off"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }else if(day=="4" && tim1[i].thursday=="off"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
        }
        else if(day=="5"){
            if(tim1[i].friday=="off"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
            }
        }else if(day=="6"){
            if(tim1[i].saturday=="off"){
                if(tim1[i].TimeStart==time){
                    chk=tim1[i];
                }
            }
        }
        else if(day=="7"){
            qDebug() << "5555 day "+day+" sunday "+tim1[i].sunday;
            if(tim1[i].sunday=="off"){
                qDebug() << "5555 time "+time + "  tim1[i].TimeStart "+tim1[i].TimeStart;
                if(tim1[i].TimeStart==time){
                    qDebug() << "999999";
                    chk=tim1[i];
                }
            }
        }
    }
    return chk;
}
