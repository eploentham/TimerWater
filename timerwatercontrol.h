#ifndef TIMERWATERCONTROL_H
#define TIMERWATERCONTROL_H
#include <QList>
#include <QSettings>
#include <timer.h>
#include <opennow.h>
#include <sensor.h>
class TimerWaterControl
{
public:
    Timer *tim;
    Sensor *sen;
    QList <Timer> tim1;
    QList <Sensor> sen1;

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

    //Sensor
    Sensor readSettingSensor(int row);
    void writeSettingSensor(int row, Sensor p);

private:
    QString fileIni;
    FILE *file;
    QString mapDay(QString day);
};
#endif // TIMERWATERCONTROL_H
