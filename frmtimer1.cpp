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
    readSettingsTimer();
}
void initail(){

}
void frmtimer1::writeSettingsTimer()
{
    QSettings ss(fileIni, QSettings::IniFormat);
    //ss.setValue("text", "Hello World");
    qDebug()<<ui->cboProgram->currentData();
    //QString prog = (ui->cboProgram->itemData()) ? m_pEdit->text() : "";
    ss.beginGroup("Timer"+ui->cboProgram->currentData().toString());
    ss.setValue("Description", ui->txtDescription->text());
    QString monday = (ui->chkMonday->isChecked()) ? "on" : "off";
    ss.setValue("monday", monday);
    QString tueday = (ui->chkTueday->isChecked()) ? "on" : "off";
    ss.setValue("tueday", tueday);
    QString wednesday = (ui->chkWebnesday->isChecked()) ? "on" : "off";
    ss.setValue("wednesday", wednesday);
    QString thurday = (ui->chkThurday->isChecked()) ? "on" : "off";
    ss.setValue("thurday", thurday);
    QString friday = (ui->chkFriday->isChecked()) ? "on" : "off";
    ss.setValue("friday", friday);
    QString saturday = (ui->chkSaturday->isChecked()) ? "on" : "off";
    ss.setValue("saturday", saturday);
    QString sunday = (ui->chkSunday->isChecked()) ? "on" : "off";
    ss.setValue("sunday", sunday);

    //QString port = (ui->txtPort->text()) ? "on" : "off";
    ss.setValue("port", ui->txtPort->text());

    //QString timestart = (ui->timeEditStart->text()) ? "on" : "off";
    ss.setValue("timestart", ui->timeEditStart->time().toString());
    //QString timeend = (ui->timeEditEnd->isChecked()) ? "on" : "off";
    ss.setValue("timeend", ui->timeEditEnd->time().toString());

    QString active = (ui->chkactive->isChecked()) ? "on" : "off";
    ss.setValue("active", active);
    QString rainnoON = (ui->chkRainnoON->isChecked()) ? "on" : "off";
    ss.setValue("rainnoON", rainnoON);
    QString rainrelayON = (ui->chkRainrelayON->isChecked()) ? "on" : "off";
    ss.setValue("rainrelayON", rainrelayON);

    ss.endGroup();
}
void frmtimer1::readSettingsTimer(){
    QSettings ss(fileIni, QSettings::IniFormat);
    ss.beginGroup("Timer"+ui->cboProgram->currentData().toString());
    ss.value("monday").toString()=="on" ? ui->chkMonday->setChecked(true):ui->chkMonday->setChecked(false);
    ss.value("tueday").toString()=="on" ? ui->chkTueday->setChecked(true):ui->chkTueday->setChecked(false);
    ss.value("wednesday").toString()=="on" ? ui->chkWebnesday->setChecked(true):ui->chkWebnesday->setChecked(false);
    ss.value("thurday").toString()=="on" ? ui->chkThurday->setChecked(true):ui->chkThurday->setChecked(false);
    ss.value("friday").toString()=="on" ? ui->chkFriday->setChecked(true):ui->chkFriday->setChecked(false);
    ss.value("saturday").toString()=="on" ? ui->chkSaturday->setChecked(true):ui->chkSaturday->setChecked(false);
    ss.value("sunday").toString()=="on" ? ui->chkSunday->setChecked(true):ui->chkSunday->setChecked(false);

    ss.endGroup();
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
    readSettingsTimer();
}
