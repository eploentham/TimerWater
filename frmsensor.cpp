#include "frmsensor.h"
#include "ui_frmsensor.h"

frmSensor::frmSensor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmSensor)
{
    ui->setupUi(this);
}

frmSensor::~frmSensor()
{
    delete ui;
}
