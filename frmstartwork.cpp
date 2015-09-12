#include "frmstartwork.h"
#include "ui_frmstartwork.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>

frmStartWork::frmStartWork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmStartWork)
{
    ui->setupUi(this);
    ui->txtDate->setText("");

    //ui->tvTimer.setSortingEnabled(True);
    tim = new Timer(QApplication::applicationDirPath());
    for(int i=1;i<=20;i++){
        tim->readSettingsTimer(i);
        qDebug() << tim->Active;
        if(tim->Active=="1"){
            ui->lvTimer->addItem("Program1 Monday="+tim->monday+" Tueday "+tim->tueday+" Wednesday "+tim->wednesday+" Thurday "+tim->thurday+" Friday "+tim->friday+" Saturday "+tim->saturday+" Sunday "+tim->sunday);
        }
    }


    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(onSetDateTime()));
    timer1->setInterval(1000);
    timer1->start();
}
void frmStartWork::onSetDateTime(){
    //qDebug() << "fileIni";
    ui->txtDate->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"));
}

frmStartWork::~frmStartWork()
{
    delete ui;
}
