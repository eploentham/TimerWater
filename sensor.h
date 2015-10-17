#ifndef SENSOR_H
#define SENSOR_H

#include <QString>
class Sensor
{
public:
    Sensor();
    QString Id, TSensor, Description, Brand, Model, Min1, Max1, Active, PortPump, PortSensor, PortFaucet, IPnodeMCU,StatusPumpnodeMCU,StatusFaucetnodeMCU, IPPumpnodeMCU, IPFaucetnodeMCU;

};

#endif // SENSOR_H
