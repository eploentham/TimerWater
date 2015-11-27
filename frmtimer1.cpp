#include "frmtimer1.h"
#include "ui_frmtimer1.h"
#include <QMessageBox>
#include <QDebug>
#include <QSettings>

frmtimer1::frmtimer1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmtimer1)
{
    ui->setupUi(this);
    twc = new TimerWaterControl(QApplication::applicationDirPath());
    ui->cboProgram->addItem("Program 1", QVariant(1));
    ui->cboProgram->addItem("Program 2", QVariant(2));
    ui->cboProgram->addItem("Program 3", QVariant(3));
    ui->cboProgram->addItem("Program 4", QVariant(4));
    ui->cboProgram->addItem("Program 5", QVariant(5));
    ui->cboProgram->addItem("Program 6", QVariant(6));
    ui->cboProgram->addItem("Program 7", QVariant(7));
    ui->cboProgram->addItem("Program 8", QVariant(8));
    ui->cboProgram->addItem("Program 9", QVariant(9));
    ui->cboProgram->addItem("Program 10", QVariant(10));
    ui->cboProgram->addItem("Program 11", QVariant(11));
    ui->cboProgram->addItem("Program 12", QVariant(12));
    ui->cboProgram->addItem("Program 13", QVariant(13));
    ui->cboProgram->addItem("Program 14", QVariant(14));
    ui->cboProgram->addItem("Program 15", QVariant(15));
    ui->cboProgram->addItem("Program 16", QVariant(16));
    ui->cboProgram->addItem("Program 17", QVariant(17));
    ui->cboProgram->addItem("Program 18", QVariant(18));
    ui->cboProgram->addItem("Program 19", QVariant(19));
    ui->cboProgram->addItem("Program 20", QVariant(20));
    fileIni = QApplication::applicationDirPath() + "/timerwater.ini";
    qDebug() << fileIni;
    readSettingsTimer(1);
}
void initail(){

}
//void frmtimer1::setTWC(TimerWaterControl *c){
//    qDebug() <<"aaaa";
//    twc = c;
//}

void frmtimer1::writeSettingsTimer()
{
    //QSettings ss(fileIni, QSettings::IniFormat);

    qDebug()<<ui->cboProgram->currentIndex();

    //ss.beginGroup("Timer"+QString::number(ui->cboProgram->currentIndex()+1));//version 4.8 beaglebone black
    //ss.setValue("Description", ui->txtDescription->text());
    //QString monday = (ui->chkMonday->isChecked()) ? "on" : "off";
    //ss.setValue("monday", monday);
    //QString tueday = (ui->chkTueday->isChecked()) ? "on" : "off";
    //ss.setValue("tueday", tueday);
    //QString wednesday = (ui->chkWebnesday->isChecked()) ? "on" : "off";
    //ss.setValue("wednesday", wednesday);
    //QString thurday = (ui->chkThurday->isChecked()) ? "on" : "off";
    //ss.setValue("thurday", thurday);
    //QString friday = (ui->chkFriday->isChecked()) ? "on" : "off";
    //ss.setValue("friday", friday);
    //QString saturday = (ui->chkSaturday->isChecked()) ? "on" : "off";
    //ss.setValue("saturday", saturday);
    //QString sunday = (ui->chkSunday->isChecked()) ? "on" : "off";
    //ss.setValue("sunday", sunday);

    //ss.setValue("port", ui->txtPort->text());


    //ss.setValue("timestart", ui->timeEditStart->time().toString());
    //ss.setValue("timeend", ui->timeEditEnd->time().toString());

    //QString active = (ui->chkactive->isChecked()) ? "on" : "off";
    //ss.setValue("active", active);
    //QString rainnoON = (ui->chkRainnoON->isChecked()) ? "on" : "off";
    //ss.setValue("rainnoON", rainnoON);
    //QString rainrelayON = (ui->chkRainrelayON->isChecked()) ? "on" : "off";
    //ss.setValue("rainrelayON", rainrelayON);

    //ss.endGroup();
    Timer tim;
    ui->chkactive->isChecked() ? tim.Active="on":tim.Active="off";
    ui->chkMonday->isChecked() ? tim.monday="on":tim.monday="off";
    ui->chkTueday->isChecked() ? tim.tuesday="on":tim.tuesday="off";
    ui->chkWebnesday->isChecked() ? tim.wednesday="on":tim.wednesday="off";
    ui->chkThurday->isChecked() ? tim.thursday="on":tim.thursday="off";
    ui->chkFriday->isChecked() ? tim.friday="on":tim.friday="off";
    ui->chkSaturday->isChecked() ? tim.saturday="on":tim.saturday="off";
    ui->chkSunday->isChecked() ? tim.sunday="on":tim.sunday="off";
    ui->chkRainnoON->isChecked() ? tim.RainonON="on":tim.RainonON="off";
    ui->chkRainrelayON->isChecked() ? tim.RainrelayON="on":tim.RainrelayON="off";
    tim.TimeStart = ui->timeEditStart->time().toString();
    tim.TimeEnd = ui->timeEditEnd->time().toString();
    tim.Port = ui->txtPort->text();
    tim.TimePeriod = QString::number(ui->spinBoxPeriod->value());
    tim.TriggerTime = QString::number(ui->spinBoxTrigerTime->value());
    tim.TriggerPort = ui->txtTrigerPort->text();
    tim.Description = ui->txtDescription->text();
    twc->writeSettingsTimer((ui->cboProgram->currentIndex()+1),tim);

}
void frmtimer1::readSettingsTimer(int row){
    //QSettings ss(fileIni, QSettings::IniFormat);
    //qDebug()<<tim.Active;
    //ss.beginGroup("Timer"+QString::number(row));
    //ss.value("monday").toString()=="on" ? ui->chkMonday->setChecked(true):ui->chkMonday->setChecked(false);
    //ss.value("tueday").toString()=="on" ? ui->chkTueday->setChecked(true):ui->chkTueday->setChecked(false);
    //ss.value("wednesday").toString()=="on" ? ui->chkWebnesday->setChecked(true):ui->chkWebnesday->setChecked(false);
    //ss.value("thurday").toString()=="on" ? ui->chkThurday->setChecked(true):ui->chkThurday->setChecked(false);
    //ss.value("friday").toString()=="on" ? ui->chkFriday->setChecked(true):ui->chkFriday->setChecked(false);
    //ss.value("saturday").toString()=="on" ? ui->chkSaturday->setChecked(true):ui->chkSaturday->setChecked(false);
    //ss.value("sunday").toString()=="on" ? ui->chkSunday->setChecked(true):ui->chkSunday->setChecked(false);
    //ss.endGroup();
    Timer tim;
    tim = twc->readSettingsTimer(row);
    qDebug()<<"active "+tim.Active;
    tim.monday=="on" ? ui->chkMonday->setChecked(true):ui->chkMonday->setChecked(false);
    tim.tuesday=="on" ? ui->chkTueday->setChecked(true):ui->chkTueday->setChecked(false);
    tim.wednesday=="on" ? ui->chkWebnesday->setChecked(true):ui->chkWebnesday->setChecked(false);
    tim.thursday=="on" ? ui->chkThurday->setChecked(true):ui->chkThurday->setChecked(false);
    tim.friday=="on" ? ui->chkFriday->setChecked(true):ui->chkFriday->setChecked(false);
    tim.saturday=="on" ? ui->chkSaturday->setChecked(true):ui->chkSaturday->setChecked(false);
    tim.sunday=="on" ? ui->chkSunday->setChecked(true):ui->chkSunday->setChecked(false);
    tim.Active=="1" ? ui->chkactive->setChecked(true):ui->chkactive->setChecked(false);
    tim.Active=="0" ? ui->chkUnActive->setChecked(true):ui->chkUnActive->setChecked(false);
    tim.RainonON=="on" ? ui->chkRainnoON->setChecked(true):ui->chkRainnoON->setChecked(false);
    tim.RainrelayON=="on" ? ui->chkRainrelayON->setChecked(true):ui->chkRainrelayON->setChecked(false);
    ui->timeEditStart->setTime(QTime::fromString(tim.TimeStart));
    ui->timeEditEnd->setTime(QTime::fromString(tim.TimeEnd));
    ui->txtPort->setText(tim.Port);
    ui->spinBoxPeriod->setValue(tim.TimePeriod.toInt());
    ui->spinBoxTrigerTime->setValue(tim.TriggerTime.toInt());
    ui->txtTrigerPort->setText(tim.TriggerPort);
    ui->txtDescription->setText(tim.Description);

    //qDebug() << "tim.monday"+tim.monday;
}

frmtimer1::~frmtimer1()
{
    delete ui;
}

void frmtimer1::on_btnSave_clicked()
{
    //QMessageBox msg;
    //msg.setText(QApplication::applicationDirPath());
    //msg.exec();
    writeSettingsTimer();
}

void frmtimer1::on_cboProgram_currentIndexChanged(int index)
{
    readSettingsTimer(index+1);
}

void frmtimer1::on_spinBoxPeriod_valueChanged(int arg1)
{
    QTime dtS;
    dtS = ui->timeEditStart->time();
    dtS.addSecs(arg1*60);
    ui->timeEditEnd->setTime(dtS);
}
