#include "timer2.h"
#include <QSettings>
#include <QDebug>
Timer2::Timer2(QString path)
{
    monday="";
    tueday="";
    wednesday="";
    thurday="";
    friday="";
    saturday="";
    sunday="";
    fileIni = path + "/timerwater.ini";
}
void Timer2::readSettingsTimer(int row){
    QSettings ss(fileIni, QSettings::IniFormat);
    //QSettings ss(fileIni, QSettings::IniFormat);
    qDebug()<<row;
    ss.beginGroup("Timer"+QString::number(row));
    ss.value("monday").toString()=="on" ? monday="on":monday="off";
    ss.value("tueday").toString()=="on" ? tueday="on":tueday="off";
    ss.value("wednesday").toString()=="on" ? wednesday="on":wednesday="off";
    ss.value("thurday").toString()=="on" ? thurday="on":thurday="off";
    ss.value("friday").toString()=="on" ? friday="on":friday="off";
    ss.value("saturday").toString()=="on" ? saturday="on":saturday="off";
    ss.value("sunday").toString()=="on" ? sunday="on":sunday="off";

    ss.endGroup();
}

