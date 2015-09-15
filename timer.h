#ifndef TIMER_H
#define TIMER_H
#include <QString>
#include <QSettings>
#include <QDateTime>
class Timer
{    
public:
    QString monday, tuesday, wednesday, thursday, friday, saturday, sunday, Active, TimeStart, TimeEnd, RainonON, RainrelayON, TriggerTime, TriggerPort, TimePeriod, Description, Port;
    //QSettings ss;

    Timer();

    //Timer clone();
    //Timer getTimerON(QDateTime dt);
    //QVector <Timer> tim1;
    //void refreshTim1Active();
private :
    QString fileIni;
    //QString mapDay(QString day);
};

#endif // TIMER_H
