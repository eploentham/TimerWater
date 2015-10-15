#include "frmsensor1.h"
#include "ui_frmsensor1.h"

frmsensor1::frmsensor1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmsensor1)
{
    ui->setupUi(this);
    ui->cboSensor->addItem("Sensor 1", QVariant(1));
    ui->cboSensor->addItem("Sensor 2", QVariant(2));
    ui->cboSensor->addItem("Sensor 3", QVariant(3));
    ui->cboSensor->addItem("Sensor 4", QVariant(4));
    ui->cboSensor->addItem("Sensor 5", QVariant(5));
    ui->cboSensor->addItem("Sensor 6", QVariant(6));
    ui->cboSensor->addItem("Sensor 7", QVariant(7));
    ui->cboSensor->addItem("Sensor 8", QVariant(8));
    ui->cboSensor->addItem("Sensor 9", QVariant(9));
    ui->cboSensor->addItem("Sensor 10", QVariant(10));
    ui->cboSensor->addItem("Sensor 11", QVariant(11));
    ui->cboSensor->addItem("Sensor 12", QVariant(12));
    ui->cboSensor->addItem("Sensor 13", QVariant(13));
    ui->cboSensor->addItem("Sensor 14", QVariant(14));
    ui->cboSensor->addItem("Sensor 15", QVariant(15));
    ui->cboSensor->addItem("Sensor 16", QVariant(16));
    ui->cboSensor->addItem("Sensor 17", QVariant(17));
    ui->cboSensor->addItem("Sensor 18", QVariant(18));
    ui->cboSensor->addItem("Sensor 19", QVariant(19));
    ui->cboSensor->addItem("Sensor 20", QVariant(20));
}

frmsensor1::~frmsensor1()
{
    delete ui;
}
