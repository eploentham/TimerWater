#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QDebug>
//#include <../../lib/BlackLib/v3_0/BlackGPIO/BlackGPIO.h>
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
    file=fopen("/sys/class/gpio/gpio30/value","rb+");
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
    file=fopen("/sys/class/gpio/gpio30/value","rb+");
    if(file==NULL){
        qDebug() << "Write value LED off failed";
    }else{
        fwrite("0",1,1,file);
        fclose(file);
    }
}
