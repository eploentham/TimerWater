#ifndef TIMERWATERCONTROL_H
#define TIMERWATERCONTROL_H
#include <QList>
#include <QSettings>
#include <timer.h>
#include <opennow.h>
#include <sensor.h>
#include <nodemcu.h>
#include <textform.h>
class TimerWaterControl
{
public:
    Timer *tim;
    Sensor *sen;
    nodeMCU *mcu;
    TextForm tf;
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
    TextForm readSettingsTextForm();
    void writeSettingTextForm();

    //Sensor
    Sensor readSettingSensor(int row);
    void writeSettingSensor(int row, Sensor p);
    QString readValueSensor(int row);

    //nodeMCU
    nodeMCU readSettingnodeMCU(int row);
    void writeSettingnodeMCU(int row, nodeMCU p);
    GPIORaspi gpioR;
    struct GPIORaspi{
        QString GPIO2, GPIO3, GPIO4, GPIO17, GPIO27, GPIO22, GPIO10, GPIO09, GPIO11, GPIO5, GPIO6, GPIO19, GPIO26, GPIO14, GPIO15, GPIO18, GPIO23, GPIO24, GPIO25, GPIO8, GPIO7, GPIO12, GPIO16, GPIO20, GPIO21;
    };

private:
    QString fileIni;
    FILE *file;
    QString mapDay(QString day);
};
#endif // TIMERWATERCONTROL_H
