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
    ui->btnOpenDirect1->setStyleSheet("background-color: rgb(255,125,100)");
    ui->btnOpenDirect2->setStyleSheet("background-color: rgb(255,125,100)");
    ui->btnOpenDirect3->setStyleSheet("background-color: rgb(255,125,100)");

    //timer1 = new QTimer(this);
    //connect(timer1, SIGNAL(timeout()), this, SLOT(onSetTimerWork()));

    //timer1->start(1000);

    timerwork = new QTimer(this);
    connect(timerwork, SIGNAL(timeout()), this, SLOT(onSetTimerWork()));
    //timerwork->setInterval(1000);
    timerwork->start(1000);
}
void frmStartWork::onSetDateTime(){
    //qDebug() << "fileIni";
    //ui->txtDate->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"));

}
void frmStartWork::onSetTimerWork(){

        //qDebug() <<"3333";
    ui->txtDate->setText(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"));
    //qDebug() <<ui->txtDate->text().mid(ui->txtDate->text().length()-2);
    //if(ui->txtDate->text().mid(ui->txtDate->text().length()-2)="00"){

    //}
    Timer chkON = twc->getTimerON(QDateTime::currentDateTime());
    Timer chkOFF = twc->getTimerOFF(QDateTime::currentDateTime());
    qDebug() <<ui->txtDate->text();
    if(chkON.Active=="1"){
        ui->txtCurWork1->setText("Start "+ chkON.Port);
        twc->openGPIO("30");
    }
    if(chkOFF.Active=="1"){
        ui->txtCurWork1->setText("End "+chkOFF.Port);
        twc->closeGPIO("30");
    }
}

frmStartWork::~frmStartWork()
{
    delete ui;
}

void frmStartWork::on_btnOpenDirect1_clicked()
{
    QString aa = ui->btnOpenDirect1->styleSheet();
    //qDebug() << aa;
    if(aa.indexOf("255,125,100")>0){
        ui->btnOpenDirect1->setStyleSheet("background-color: rgb(19,159,47)");
    }else{
        //qDebug() << "aa";
        ui->btnOpenDirect1->setStyleSheet("background-color: rgb(255,125,100)");
    }
}

void frmStartWork::on_btnOpenDirect2_clicked()
{
    if(ui->btnOpenDirect2->styleSheet().indexOf("255,125,100")>0){
        ui->btnOpenDirect2->setStyleSheet("background-color: rgb(19,159,47)");
    }else{
        //qDebug() << "aa";
        ui->btnOpenDirect2->setStyleSheet("background-color: rgb(255,125,100)");
    }
}

void frmStartWork::on_btnOpenDirect3_clicked()
{
    if(ui->btnOpenDirect3->styleSheet().indexOf("255,125,100")>0){
        ui->btnOpenDirect3->setStyleSheet("background-color: rgb(19,159,47)");
    }else{
        //qDebug() << "aa";
        ui->btnOpenDirect3->setStyleSheet("background-color: rgb(255,125,100)");
    }
}
