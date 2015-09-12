#ifndef TIMER_H
#define TIMER_H
#include <QString>

class Timer
{    
public:
    QString monday, tueday,wednesday, thurday, friday, saturday, sunday, Active, TimeStart, TimeEmd, RainonON, RainrelayON;
    Timer(QString path);
    void readSettingsTimer(int row);
private :
    QString fileIni;
};

#endif // TIMER_H
