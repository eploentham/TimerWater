#ifndef TIMERWATERCONTROL_H
#define TIMERWATERCONTROL_H
#include <QList>
#include <timer.h>
class TimerWaterControl
{
public:
    Timer *tim;
    QList <Timer> tim1;
    Timer getTimerON(QDateTime dt);
    Timer getTimerOFF(QDateTime dt);
    TimerWaterControl(QString path);
    Timer readSettingsTimer(int row);
    void writeSettingsTimer(int row, Timer p);
    void refreshTim1Active();
private:
    QString fileIni;
    QString mapDay(QString day);
};
#endif // TIMERWATERCONTROL_H
