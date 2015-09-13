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
    twc = new TimerWaterControl(QApplication::applicationDirPath());
    //ui->tvTimer.setSortingEnabled(True);
    //tim = new Timer(QApplication::applicationDirPath());
    //qDebug()<<twc->tim1.size();
    QString tmp;
    for(int i=0;i<twc->tim1.size();i++){
        //twc->tim1[i].Active;
        //qDebug()<<"bbb" +QString::number(i);
        tmp = "Program"+QString::number(i)+" Monday="+twc->tim1[i].monday+" Tueday="+twc->tim1[i].tuesday+" Wednesday="+twc->tim1[i].wednesday+" Thurday="+twc->tim1[i].thursday+
                " Friday="+twc->tim1[i].friday+" Saturday="+twc->tim1[i].saturday+" Sunday="+twc->tim1[i].sunday+" Start Time="+twc->tim1[i].TimeStart+" End Time="+twc->tim1[i].TimeEnd;
        //qDebug()<<"ccc" +QString::number(i);
        //if(twc->tim1[i].Active=="1"){
            //tim1[i]=tim->clone();
            ui->lvTimer->addItem(tmp);
        //}
    }


    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(onSetDateTime()));
    timer1->setInterval(1000);
    timer1->start();

    timerwork = new QTimer(this);
    connect(timer1, SIGNAL(timeout1()), this, SLOT(onSetTimerWork()));
    timerwork->setInterval(60000);
    timerwork->start();
}
void frmStartWork::onSetDateTime(){
    //qDebug() << "fileIni";
    ui->txtDate->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"));

}
void frmStartWork::onSetTimerWork(){
    Timer chkON = twc->getTimerON(QDateTime::currentDateTime());
    Timer chkOFF = twc->getTimerOFF(QDateTime::currentDateTime());
    if(chkON.Active=="1"){
        ui->txtCurWork1->setText("555555555");
    }
}

frmStartWork::~frmStartWork()
{
    delete ui;
}
