#ifndef TIMER2_H
#define TIMER2_H
#include <QString>

class Timer2
{

public:
    QString monday, tueday,wednesday, thurday, friday, saturday, sunday;
    Timer2(QString path);
    void readSettingsTimer(int row);
private :

    QString fileIni;
};

#endif // TIMER2_H
