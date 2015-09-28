#include "frmopennow.h"
#include "ui_frmopennow.h"
#include <QDesktopWidget>


frmOpenNow::frmOpenNow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmOpenNow)
{
    ui->setupUi(this);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());
    //flag = f;
    twc = new TimerWaterControl(QApplication::applicationDirPath());
    //setControl(1);
}
void frmOpenNow::setControl(int f){
    flag = f;
    on1 = twc->readSettingsOpenNow(flag);
    ui->txtDescription->setText(on1.description);
    ui->txtPort->setText(on1.port);
    ui->spinBoxMinute->setValue(on1.minute.toInt());
}

frmOpenNow::~frmOpenNow()
{
    delete ui;
}

void frmOpenNow::on_btnSave_clicked()
{
    on1.description = ui->txtDescription->text();
    on1.port = ui->txtPort->text();
    on1.minute = QString::number(ui->spinBoxMinute->value());
    twc->writeSettingOpenNow(flag,on1);
}
