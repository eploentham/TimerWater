#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QDebug>
//#include <../../lib/BlackLib/v3_0/BlackGPIO/BlackGPIO.h>
/**
 * @brief file
 * 58-09-29 1.0 Ekapop port
 */

FILE *file;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    file = fopen("/sys/class/gpio/export","w");
    if(file==NULL){
        qDebug() << "Export file to activate GPIO failed";
    }else{
        fwrite("30",1,2,file);
        fclose(file);

        file = fopen("/sys/class/gpio/direction","w");
        if(file==NULL){
            qDebug() << "Write direction to activate GPIO failed";
        }else{
            fwrite("out",1,3,file);
            fclose(file);
        }
    }

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QString aa = "/sys/class/gpio/gpio"+ui->txtPort->text()+"/value";   //1.0 Ekapop port +1
    char* p = new char[aa.length() + 1];    //1.0 Ekapop port   +1

    strcpy(p, aa.toLatin1().constData());   //1.0 Ekapop port   +1
    file=fopen(p,"rb+");//1.0 Ekapop port   +1
    if(file==NULL){
        qDebug() << "Write value LED on failed";
    }else{
        fwrite("1",1,1,file);
        fclose(file);
    }
}

void Dialog::on_pushButton_2_clicked()
{
    //file=fopen("sys/class/gpio/gpio30/value","rb+");
    QString aa = "/sys/class/gpio/gpio"+ui->txtPort->text()+"/value";   //1.0 Ekapop port   +1
    char* p = new char[aa.length() + 1];    //1.0 Ekapop port   +1

    strcpy(p, aa.toLatin1().constData());   //1.0 Ekapop port   +1
    file=fopen(p,"rb+");//1.0 Ekapop port
    if(file==NULL){
        qDebug() << "Write value LED off failed";
    }else{
        fwrite("0",1,1,file);
        fclose(file);
    }
}

void Dialog::on_pushButton_3_clicked()
{
    static const char *devName = "/dev/i2c-1";

    if ((file = fopen(devName, O_RDWR)) < 0) {
        fprintf(stderr, "I2C: Failed to access %d\n", devName);
        exit(1);
    }
    if (ioctl(file, I2C_SLAVE, ADDRESS) < 0) {
        fprintf(stderr, "I2C: Failed to acquire bus access/talk to slave 0x%x\n", A$
        exit(1);
    }

}
