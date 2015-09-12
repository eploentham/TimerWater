#include "timer.h"
#include <QSettings>
#include <QDebug>
Timer::Timer(QString path)
{
    //monday="";
    monday="";
    tueday="";
    wednesday="";
    thurday="";
    friday="";
    saturday="";
    sunday="";
    Active="";
    TimeStart="";
    TimeEmd="";
    RainonON="";
    RainrelayON="";
    fileIni = path + "/timerwater.ini";


}

void Timer::readSettingsTimer(int row){
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
    ss.value("active").toString()=="on" ? Active="1":Active="0";
    ss.value("rainnoON").toString()=="on" ? RainonON="on":RainonON="off";
    ss.value("rainrelayON").toString()=="on" ? RainrelayON="on":RainrelayON="off";
    ss.value("timestart").toString()=="on" ? TimeStart="0":TimeStart="0";
    ss.value("timeend").toString()=="on" ? TimeEmd="0":TimeEmd="0";

    ss.endGroup();
}
