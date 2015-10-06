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
    qDebug() << "on_pushButton_clicked";
    QString port1 = ui->txtPort->text();
    char* port = new char[port1.length() + 1];
    strcpy(port, port1.toLatin1().constData());
    QString aa = "/sys/class/gpio/gpio"+ui->txtPort->text()+"/value";   //1.0 Ekapop port +1
    QString path="/sys/class/gpio/gpio";

    file = fopen("/sys/class/gpio/export","w");
    if(file==NULL){
        qDebug() << "Export file to activate GPIO failed";
    }else{
        fwrite(port,1,2,file);
        fclose(file);

        path = path+port+"/direction";
        char* a = new char[path.length() + 1];
        strcpy(a, path.toLatin1().constData());
        file = fopen(a,"w");
        if(file==NULL){
            qDebug() << "Write direction to activate GPIO failed " +path;
        }else{
            fwrite("out",1,3,file);
            fclose(file);
        }
    }


    char* p = new char[aa.length() + 1];    //1.0 Ekapop port   +1

    strcpy(p, aa.toLatin1().constData());   //1.0 Ekapop port   +1
    file=fopen(p,"rb+");//1.0 Ekapop port   +1
    if(file==NULL){
        qDebug() << "Write value LED on failed";
    }else{
        fwrite("1",1,1,file);
        fclose(file);
        qDebug() << "Write value LED on success";
    }
    file=NULL;
}

void Dialog::on_pushButton_2_clicked()
{
    qDebug() << "on_pushButton_2_clicked";
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
        qDebug() << "Write value LED off success";
    }
}

void Dialog::on_pushButton_3_clicked()
{
    static const char* devName = "/dev/i2c-1";

    //if ((file = fopen(devName, O_RDWR)) < 0) {
    if ((file = fopen(devName, "rb+")) < 0) {
        fprintf(stderr, "I2C: Failed to access %d\n", devName);
        exit(1);
    }
    //if (ioctl(file, I2C_SLAVE, ADDRESS) < 0) {
    //    std::open(...)
    //    fprintf(stderr, "I2C: Failed to acquire bus access/talk to slave 0x%x\n", ADDRESS);
    //    exit(1);
   // }

    int arg;

      //for (arg = 1; arg < argc; arg++) {
        int val=2;
        unsigned char cmd[16];

        //if (0 == sscanf(argv[arg], "%d", &val)) {
        //  fprintf(stderr, "Invalid parameter %d \"%s\"\n", arg, argv[arg]);
        //  exit(1);
        //}

        printf("Sending %d\n", val);

        cmd[0] = val;
        if (fwrite(cmd,1, 1,file) == 1) {

          // As we are not talking to direct hardware but a microcontroller we
          // need to wait a short while so that it can respond.
          //
          // 1ms seems to be enough but it depends on what workload it has
          //QObject.thread()-> Sleep(10000);
          //thread()->sleep(10000);
          char buf[1];
          if (fread(buf, 1, 1,file) == 1) {
            int temp = (int) buf[0];

            printf("Received %d\n", temp);
          }
        }

        // Now wait else you could crash the arduino by sending requests too fast
        //thread()->sleep(10000);
      //}

      fclose(file);

}
