#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <../../lib/BlackLib/v3_0/BlackGPIO/BlackGPIO.h>
using namespace BlackLib;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    BlackGPIO gpi(GPIO_30, output, SecureMode);
    //myGpio.getValue();

    //BlackLib::BlackGPIO myGpioPtr = new BlackLib::BlackGPIO(BlackLib::GPIO_40, BlackLib::input);
}
