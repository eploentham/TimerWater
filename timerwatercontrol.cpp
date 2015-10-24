#include "timerwatercontrol.h"
#include <QDebug>
#include <QFile>
#include <QStringList>
#include <QTextStream>
/**
 * @brief TimerWaterControl::TimerWaterControl
 * @param path
 * 58-09-28  Ekapop 1.0 add Method setTimerON,setTimerOFF
 * 58-09-29  Ekapop 1.1 add Method Test git
 */
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
OpenNow TimerWaterControl::readSettingsOpenNow(int row){
    QSettings ss(fileIni, QSettings::IniFormat);
    OpenNow tim;
    ss.beginGroup("OpenNow"+QString::number(row));
    tim.description = ss.value("description").toString();
    tim.port = ss.value("port").toString();
    tim.minute = ss.value("minute").toString();
    ss.endGroup();
    return tim;
}
void TimerWaterControl::writeSettingOpenNow(int row, OpenNow p){
    QSettings ss(fileIni, QSettings::IniFormat);
    ss.beginGroup("OpenNow"+QString::number(row));

    ss.setValue("description",p.description);
    ss.setValue("port",p.port);
    ss.setValue("minute", p.minute);

    ss.endGroup();
    qDebug() << "writeSettingOpenNow "+QString::number(row);
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
    tim.Port = ss.value("port").toString();
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
    ss.setValue("rainnoON",p.RainonON);

    ss.setValue("rainrelayON",p.RainrelayON);
    ss.setValue("timestart",p.TimeStart);
    ss.setValue("timeend",p.TimeEnd);
    ss.setValue("triggertime",p.TriggerTime);

    ss.setValue("triggerport",p.TriggerPort);
    ss.setValue("timeperiod",p.TimePeriod);
    ss.setValue("port",p.Port);
    //ss.setValue("timeend",p.timeend);
    qDebug() << "triggerport "+p.TriggerPort;
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
    //qDebug() << "day "+day;
    //qDebug() << "time "+time;

    QTime start, end;
    for(int i=0;i<tim1.size();i++){
        QString map = "";
        start.setHMS(tim1[i].TimeStart.mid(0,2).toInt(),tim1[i].TimeStart.mid(3,2).toInt(),tim1[i].TimeStart.mid(6,2).toInt());
        end.setHMS(tim1[i].TimeEnd.mid(0,2).toInt(),tim1[i].TimeEnd.mid(3,2).toInt(),tim1[i].TimeEnd.mid(6,2).toInt());
        if(day=="1" && tim1[i].monday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            //qDebug() << "start "+start.toString()+" end "+end.toString()+" cur "+cur.toString()+" time "+time;
            chk=tim1[i];
        }else if(day=="2" && tim1[i].tuesday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            chk=tim1[i];
        }
        else if(day=="3" && tim1[i].wednesday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            chk=tim1[i];
        }else if(day=="4" && tim1[i].thursday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            chk=tim1[i];
        }
        else if(day=="5" && tim1[i].friday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            chk=tim1[i];
        }else if(day=="6" && tim1[i].saturday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            chk=tim1[i];
        }
        else if(day=="7" && tim1[i].sunday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            chk=tim1[i];
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
    //qDebug() << "day "+day;
    //qDebug() << "time "+time;
    QTime start, end;
    for(int i=0;i<tim1.size();i++){
        QString map = "";
        start.setHMS(tim1[i].TimeStart.mid(0,2).toInt(),tim1[i].TimeStart.mid(3,2).toInt(),tim1[i].TimeStart.mid(6,2).toInt());
        end.setHMS(tim1[i].TimeEnd.mid(0,2).toInt(),tim1[i].TimeEnd.mid(3,2).toInt(),tim1[i].TimeEnd.mid(6,2).toInt());
        //qDebug() << "start "+start.toString()+" end "+end.toString()+" dt.time() "+dt.time().toString();
        if(day=="1" && tim1[i].monday=="on" && tim1[i].TimeEnd==time){
            qDebug() <<"888888"+QString::number(i)+tim1[i].Port;
            chk=tim1[i];
            //}
        }else if(day=="2" && tim1[i].tuesday=="on"){
            if(tim1[i].TimeEnd==time){
                chk=tim1[i];
            }
        }
        else if(day=="3" && tim1[i].wednesday=="on"){
            if(tim1[i].TimeEnd==time){
                chk=tim1[i];
            }
        }else if(day=="4" && tim1[i].thursday=="on"){
            if(tim1[i].TimeEnd==time){
                chk=tim1[i];
            }
        }
        else if(day=="5"){
            if(tim1[i].friday=="on"){
                if(tim1[i].TimeEnd==time){
                    chk=tim1[i];
                }
            }
        }else if(day=="6"){
            if(tim1[i].saturday=="on"){
                if(tim1[i].TimeEnd==time){
                    chk=tim1[i];
                }
            }
        }
        else if(day=="7"){
            qDebug() << "5555 day "+day+" sunday "+tim1[i].sunday;
            if(tim1[i].sunday=="on"){
                qDebug() << "5555 time "+time + "  tim1[i].TimeEnd "+tim1[i].TimeEnd;
                if(tim1[i].TimeEnd==time){
                    qDebug() << "999999";
                    chk=tim1[i];
                }
            }
        }
    }
    return chk;
}
QString TimerWaterControl::setTimerON(QDateTime dt){
    //bool chk=false;
    QString chk="";
    QString day = QString::number(dt.date().dayOfWeek());
    //QString time = dt.time().toString();
    //time = time.mid(0,5);
    //qDebug() << "day "+day;
    //qDebug() << "time "+time;

    QTime start, end;
    for(int i=0;i<tim1.size();i++){
        QString map = "";
        start.setHMS(tim1[i].TimeStart.mid(0,2).toInt(),tim1[i].TimeStart.mid(3,2).toInt(),tim1[i].TimeStart.mid(6,2).toInt());
        end.setHMS(tim1[i].TimeEnd.mid(0,2).toInt(),tim1[i].TimeEnd.mid(3,2).toInt(),tim1[i].TimeEnd.mid(6,2).toInt());
        if(day=="1" && tim1[i].monday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            //qDebug() << "start "+start.toString()+" end "+end.toString();
            //chk=tim1[i];
            chk = openGPIO(tim1[i].Port);
        }else if(day=="2" && tim1[i].tuesday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            //chk=tim1[i];
            chk = openGPIO(tim1[i].Port);
        }
        else if(day=="3" && tim1[i].wednesday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            //chk=tim1[i];
            chk = openGPIO(tim1[i].Port);
        }else if(day=="4" && tim1[i].thursday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            //chk=tim1[i];
            chk = openGPIO(tim1[i].Port);
        }
        else if(day=="5" && tim1[i].friday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            //chk=tim1[i];
            chk = openGPIO(tim1[i].Port);
        }else if(day=="6" && tim1[i].saturday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            //chk=tim1[i];
            chk = openGPIO(tim1[i].Port);
        }
        else if(day=="7" && tim1[i].sunday=="on" && (dt.time().operator >=(start) && (dt.time().operator <(end)))){
            //chk=tim1[i];
            chk = openGPIO(tim1[i].Port);
        }
    }
    //chk=="ok" ?log1= "openGPIO on":log1="openGPIO failed";
    qDebug() << "setTimerON "+start.toString()+" end "+end.toString()+ chk;
    return chk;
}
QString TimerWaterControl::setTimerOFF(QDateTime dt){
    //bool chk=false;
    QString chk;
    QString day = QString::number(dt.date().dayOfWeek());
    QString time = dt.time().toString();
    QTime start, end;
    for(int i=0;i<tim1.size();i++){
        QString map = "";
        start.setHMS(tim1[i].TimeStart.mid(0,2).toInt(),tim1[i].TimeStart.mid(3,2).toInt(),tim1[i].TimeStart.mid(6,2).toInt());
        end.setHMS(tim1[i].TimeEnd.mid(0,2).toInt(),tim1[i].TimeEnd.mid(3,2).toInt(),tim1[i].TimeEnd.mid(6,2).toInt());
        //qDebug() << "start "+start.toString()+" end "+end.toString()+" dt.time() "+dt.time().toString();
        if(day=="1" && tim1[i].monday=="on" && tim1[i].TimeEnd==time){
            chk = closeGPIO(tim1[i].Port);
        }else if(day=="2" && tim1[i].tuesday=="on"&&(tim1[i].TimeEnd==time)){
            chk = closeGPIO(tim1[i].Port);
        }else if(day=="3" && tim1[i].wednesday=="on"&&(tim1[i].TimeEnd==time)){
            chk = closeGPIO(tim1[i].Port);
        }else if(day=="4" && tim1[i].thursday=="on"&&(tim1[i].TimeEnd==time)){
            chk = closeGPIO(tim1[i].Port);
        }else if(day=="5"&&(tim1[i].friday=="on")&&(tim1[i].TimeEnd==time)){
            chk = closeGPIO(tim1[i].Port);
        }else if(day=="6"&&(tim1[i].saturday=="on")&&(tim1[i].TimeEnd==time)){
            chk = closeGPIO(tim1[i].Port);
        }else if(day=="7"&&(tim1[i].sunday=="on")&&(tim1[i].TimeEnd==time)){
            chk = closeGPIO(tim1[i].Port);
        }
    }
    //chk=="ok" ?log1= "closeGPIO on":log1="closeGPIO failed";
    qDebug() << "setTimerOFF "+start.toString()+" end "+end.toString()+ chk;
    return chk;
}
void TimerWaterControl::initGPIO(QString port){
    QString path="/sys/class/gpio/gpio";
    //QString valu=path+port+"/value";
    QString direc=path+port+"/direction";
    char* port1 = new char[port.length() + 1];
    strcpy(port1, port.toLatin1().constData());
    file = fopen("/sys/class/gpio/export","w");
    if(file==NULL){
        qDebug() << "Export file to activate GPIO failed";
    }else{
        fwrite(port1,1,2,file);//echo port > Export
        fclose(file);

        char* direc1 = new char[direc.length() + 1];
        strcpy(direc1, direc.toLatin1().constData());
        file = fopen(direc1,"w");
        if(file==NULL){
            qDebug() << "Write direction to activate GPIO failed " +path;
        }else{
            fwrite("out",1,2,file);//echo out > Direction
            fclose(file);

        }
    }
    file = NULL;
}

QString TimerWaterControl::openGPIO(QString port)
{
    QString chk="OK";
    QString aa="/sys/class/gpio/gpio"+port+"/value";
    QByteArray ba = aa.toLatin1();
    const char *c_str2 = ba.data();
    file=fopen(c_str2,"rb+");

    if(file==NULL){
        qDebug() << "Write value ON failed";
        chk=" openGPIO "+port+" failed";
    }else{
        fwrite("1",1,1,file);
        fclose(file);
        chk=" openGPIO "+port+" ok";
    }
    return chk;
}
QString TimerWaterControl::closeGPIO(QString port)
{
    QString chk="";
    QString aa="/sys/class/gpio/gpio"+port+"/value";
    QByteArray ba = aa.toLatin1();
    const char *c_str2 = ba.data();
    file=fopen(c_str2,"rb+");
    if(file==NULL){
        qDebug() << "Write value OFF failed";
        chk=" closeGPIO "+port+" failed";
    }else{
        fwrite("0",1,1,file);
        fclose(file);
        chk=" closeGPIO "+port+" ok";
    }
    return chk;
}
Sensor TimerWaterControl::readSettingSensor(int row)
{
    QSettings ss(fileIni, QSettings::IniFormat);
    Sensor sen;
    //QSettings ss(fileIni, QSettings::IniFormat);
    //qDebug() << "readSettingsTimer "+QString::number(row);
    ss.beginGroup("Sensor"+QString::number(row));

    ss.value("active").toString()=="on" ? sen.Active="1":sen.Active="0";

    sen.Brand = ss.value("brand").toString();
    sen.Description = ss.value("description").toString();
    sen.Id = ss.value("id").toString();
    sen.Max1 = ss.value("max").toString();
    sen.Min1 = ss.value("min").toString();
    sen.Model = ss.value("model").toString();
    sen.TSensor = ss.value("tsensor").toString();
    sen.PortFaucet = ss.value("portfaucet").toString();
    sen.PortPump = ss.value("portpump").toString();
    sen.PortSensor = ss.value("portsensor").toString();
    sen.IPnodeMCU = ss.value("ipnodemcu").toString();

    ss.value("statuspumpnodemcu").toString()=="on" ? sen.StatusPumpnodeMCU="1":sen.StatusPumpnodeMCU="0";
    ss.value("statusfaucetnodemcu").toString()=="on" ? sen.StatusFaucetnodeMCU="1":sen.StatusFaucetnodeMCU="0";
    sen.IPFaucetnodeMCU = ss.value("ipfaucetnodemcu").toString();
    sen.IPPumpnodeMCU = ss.value("ippumpnodemcu").toString();

    ss.endGroup();
    return sen;
}

void TimerWaterControl::writeSettingSensor(int row, Sensor p)
{
    QSettings ss(fileIni, QSettings::IniFormat);
    ss.beginGroup("Sensor"+QString::number(row));

    ss.setValue("description",p.Description);
    ss.setValue("active",p.Active);

    ss.setValue("brand",p.Brand);
    ss.setValue("id",p.Id);
    ss.setValue("max",p.Max1);
    ss.setValue("min",p.Min1);

    ss.setValue("model",p.Model);
    ss.setValue("tsensor",p.TSensor);
    ss.setValue("portfaucet",p.PortFaucet);
    ss.setValue("portpump",p.PortPump);
    ss.setValue("portsensor",p.PortSensor);
    ss.setValue("ipnodemcu",p.IPnodeMCU);

    ss.setValue("statusfaucetnodemcu",p.StatusFaucetnodeMCU);
    ss.setValue("statuspumpnodemcu",p.StatusPumpnodeMCU);
    ss.setValue("ipfaucetnodemcu",p.IPFaucetnodeMCU);
    ss.setValue("ippumpnodemcu",p.IPPumpnodeMCU);

    qDebug() << "writeSettingSensor ";
    ss.endGroup();
}

QString TimerWaterControl::readValueSensor(int row)
{
    QString ss;
    QFile file("/usr/lib/cgi-bin/Sensor"+QString::number(row)+".io");
    if(!file.open(QIODevice::ReadOnly)) {
        //QMessageBox::information(0, "error", file.errorString());
        qDebug()<<"Error read file";
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        ss= fields[1];
    }

    file.close();
    return ss;
}
nodeMCU TimerWaterControl::readSettingnodeMCU(int row)
{
    QSettings ss(fileIni, QSettings::IniFormat);
    nodeMCU mcu;
    //QSettings ss(fileIni, QSettings::IniFormat);
    //qDebug() << "readSettingsTimer "+QString::number(row);
    ss.beginGroup("nodemcu"+QString::number(row));

    //ss.value("active").toString()=="on" ? sen.Active="1":sen.Active="0";

    mcu.Control1 = ss.value("control1").toString();
    mcu.Control2 = ss.value("control2").toString();
    mcu.Control3 = ss.value("control3").toString();
    mcu.Control4 = ss.value("control4").toString();
    mcu.Control5 = ss.value("control5").toString();
    mcu.ControlPort1 = ss.value("controlport1").toString();
    mcu.ControlPort2 = ss.value("controlport2").toString();
    mcu.ControlPort3 = ss.value("controlport3").toString();
    mcu.ControlPort4 = ss.value("controlport4").toString();
    mcu.ControlPort5 = ss.value("controlport5").toString();
    mcu.Id = ss.value("id").toString();
    mcu.Sensor1 = ss.value("sensor1").toString();
    mcu.Sensor2 = ss.value("sensor2").toString();
    mcu.Sensor3 = ss.value("sensor3").toString();
    mcu.Sensor4 = ss.value("sensor4").toString();
    mcu.Sensor5 = ss.value("sensor5").toString();
    mcu.SensorPort1 = ss.value("sensorport1").toString();
    mcu.SensorPort2 = ss.value("sensorport2").toString();
    mcu.SensorPort3 = ss.value("sensorport3").toString();
    mcu.SensorPort4 = ss.value("sensorport4").toString();
    mcu.SensorPort5 = ss.value("sensorport5").toString();
    mcu.Description = ss.value("description").toString();

    ss.endGroup();
    return mcu;
}
void TimerWaterControl::writeSettingnodeMCU(int row, nodeMCU p)
{
    QSettings ss(fileIni, QSettings::IniFormat);
    ss.beginGroup("nodemcu"+QString::number(row));

    ss.setValue("control1",p.Control1);
    ss.setValue("control2",p.Control2);
    ss.setValue("control3",p.Control3);
    ss.setValue("control4",p.Control4);
    ss.setValue("control5",p.Control5);
    ss.setValue("id",p.Id);
    ss.setValue("controlport1",p.ControlPort1);
    ss.setValue("controlport2",p.ControlPort2);
    ss.setValue("controlport3",p.ControlPort3);
    ss.setValue("controlport4",p.ControlPort4);
    ss.setValue("controlport5",p.ControlPort5);

    ss.setValue("sensor1",p.Sensor1);
    ss.setValue("sensor2",p.Sensor2);
    ss.setValue("sensor3",p.Sensor3);
    ss.setValue("sensor4",p.Sensor4);
    ss.setValue("sensor5",p.Sensor5);
    ss.setValue("sensorport1",p.SensorPort1);
    ss.setValue("sensorport2",p.SensorPort2);
    ss.setValue("sensorport3",p.SensorPort3);
    ss.setValue("sensorport4",p.SensorPort4);
    ss.setValue("sensorport5",p.SensorPort5);
    ss.setValue("description",p.Description);

    qDebug() << "writeSettingnodeMCU ";
    ss.endGroup();
}
