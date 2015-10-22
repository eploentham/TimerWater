#ifndef NODEMCU_H
#define NODEMCU_H

#include <QString>
class nodeMCU
{
public:
    QString Id, Sensor1, Sensor2, Sensor3, Sensor4, Sensor5, SensorPort1, SensorPort2, SensorPort3, SensorPort4, SensorPort5, Description;
    QString Control1, Control2, Control3, Control4, Control5, ControlPort1, ControlPort2, ControlPort3, ControlPort4, ControlPort5;
    nodeMCU();
};

#endif // NODEMCU_H
