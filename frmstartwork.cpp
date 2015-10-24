#include "frmstartwork.h"
#include "ui_frmstartwork.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <frmopennow.h>
#include <QDesktopWidget>

frmStartWork::frmStartWork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmStartWork)
{
    ui->setupUi(this);

    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());

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
        twc->initGPIO(twc->tim1[i].Port);
        //}
    }
    ui->btnOpenNow1->setStyleSheet("background-color: rgb(255,125,100)");
    ui->btnOpenNow2->setStyleSheet("background-color: rgb(255,125,100)");
    ui->btnOpenNow3->setStyleSheet("background-color: rgb(255,125,100)");
    on1 = twc->readSettingsOpenNow(1);
    on2 = twc->readSettingsOpenNow(2);
    on3 = twc->readSettingsOpenNow(3);
    ui->btnOpenNow1->setText(on1.description+" "+on1.minute+" นาที");
    ui->btnOpenNow2->setText(on2.description+" "+on2.minute+" นาที");
    ui->btnOpenNow3->setText(on3.description+" "+on3.minute+" นาที");
    //timer1 = new QTimer(this);
    //connect(timer1, SIGNAL(timeout()), this, SLOT(onSetTimerWork()));

    //timer1->start(1000);
    Sensor ss1 = twc->readSettingSensor(1);
    Sensor ss2 = twc->readSettingSensor(2);
    Sensor ss3 = twc->readSettingSensor(3);
    Sensor ss4 = twc->readSettingSensor(4);
    ss1.Max1 != "" ? ui->pb1->setMaximum(ss1.Max1.toInt()):ui->pb1->setMaximum(100);
    ss2.Max1 != "" ? ui->pb2->setMaximum(ss2.Max1.toInt()):ui->pb2->setMaximum(100);
    ss1.Min1 != "" ? ui->pb1->setMinimum(ss1.Min1.toInt()):ui->pb1->setMinimum(0);
    ss2.Min1 != "" ? ui->pb2->setMinimum(ss2.Min1.toInt()):ui->pb1->setMinimum(0);
    //ui->pb1->setMaximum(ss1.Max1.toInt());
    //ui->pb2->setMaximum(ss2.Max1.toInt());

    onTimerWork();

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
    QString ss = QDateTime::currentDateTime().toString("ss");
    //qDebug() <<ss;
    if(ss=="00"){
        onTimerWork();
    }
    QString val = twc->readValueSensor(1);
    ui->pb1->setValue(val.toInt());
    qDebug()<<"Sensor1 value="+val;
    //}
}
void frmStartWork::onTimerWork(){
    //Timer chkON = twc->setTimerON(QDateTime::currentDateTime());
    //Timer chkOFF = twc->setTimerOFF(QDateTime::currentDateTime());
    QString chkON = twc->setTimerON(QDateTime::currentDateTime());
    QString chkOFF = twc->setTimerOFF(QDateTime::currentDateTime());
    //qDebug() <<ui->txtDate->text();
    if(chkON.indexOf("failed")){
        chkON = twc->setTimerON(QDateTime::currentDateTime());
    }
    //QString val = twc->readValueSensor(1);
    //ui->pb1->setValue(val.toInt());
    //qDebug()<<"Sensor1 value="+val;
    //if(chkON.Active=="1"){
        ui->txtCurWork1->setText(chkON);
    //    twc->openGPIO("30");
    //}
    //if(chkOFF.Active=="1"){
        ui->txtCurWork2->setText(chkOFF);
    //    twc->closeGPIO("30");
    //}
}

frmStartWork::~frmStartWork()
{
    delete ui;
}

void frmStartWork::on_btnOpenNow1_clicked()
{
    QString log1="";
    QString aa = ui->btnOpenNow1->styleSheet();
    //qDebug() << aa;
    if(aa.indexOf("255,125,100")>0){
        ui->btnOpenNow1->setStyleSheet("background-color: rgb(19,159,47)");
        log1= twc->openGPIO(on1.port);
    }else{
        //qDebug() << "aa";
        ui->btnOpenNow1->setStyleSheet("background-color: rgb(255,125,100)");
        log1 = twc->closeGPIO(on1.port);
    }
    qDebug() << log1;
}

void frmStartWork::on_btnOpenNow1c_clicked()
{
    frmOpenNow f;
    f.setControl(1);
    f.setModal(true);
    f.exec();
}

void frmStartWork::on_btnOpenNow2_clicked()
{
    if(ui->btnOpenNow2->styleSheet().indexOf("255,125,100")>0){
        ui->btnOpenNow2->setStyleSheet("background-color: rgb(19,159,47)");
    }else{
        //qDebug() << "aa";
        ui->btnOpenNow2->setStyleSheet("background-color: rgb(255,125,100)");
    }
}

void frmStartWork::on_btnOpenNow2c_clicked()
{
    frmOpenNow f;
    f.setControl(2);
    f.setModal(true);
    f.exec();
}

void frmStartWork::on_btnOpenNow3c_clicked()
{
    frmOpenNow f;
    f.setControl(3);
    f.setModal(true);
    f.exec();
}

void frmStartWork::on_btnOpenNow3_clicked()
{
    if(ui->btnOpenNow3->styleSheet().indexOf("255,125,100")>0){
        ui->btnOpenNow3->setStyleSheet("background-color: rgb(19,159,47)");
    }else{
        //qDebug() << "aa";
        ui->btnOpenNow3->setStyleSheet("background-color: rgb(255,125,100)");
    }
}
