#ifndef TIMERWATERCONTROL_H
#define TIMERWATERCONTROL_H
#include <QList>
#include <timer.h>
#include <opennow.h>
class TimerWaterControl
{
public:
    Timer *tim;
    QList <Timer> tim1;
    Timer getTimerON(QDateTime dt);
    Timer getTimerOFF(QDateTime dt);
    QString setTimerON(QDateTime dt);
    QString setTimerOFF(QDateTime dt);
    TimerWaterControl(QString path);
    Timer readSettingsTimer(int row);
    void writeSettingsTimer(int row, Timer p);
    OpenNow readSettingsOpenNow(int row);
    void writeSettingOpenNow(int row, OpenNow p);
    void refreshTim1Active();
    QString openGPIO(QString port);
    QString closeGPIO(QString port);
    void initGPIO(QString port);
    void uninitGPIO(QString port);
private:
    QString fileIni;
    FILE *file;
    QString mapDay(QString day);
};
#endif // TIMERWATERCONTROL_H
