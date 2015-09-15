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
    TimerWaterControl(QString path);
    Timer readSettingsTimer(int row);
    void writeSettingsTimer(int row, Timer p);
    OpenNow readSettingsOpenNow(int row);
    void writeSettingOpenNow(int row, OpenNow p);
    void refreshTim1Active();
    void openGPIO(QString port);
    void closeGPIO(QString port);
private:
    QString fileIni;
    FILE *file;
    QString mapDay(QString day);
};
#endif // TIMERWATERCONTROL_H
