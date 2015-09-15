#include "frmopennow.h"
#include "ui_frmopennow.h"

frmOpenNow::frmOpenNow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmOpenNow)
{
    ui->setupUi(this);
    twc = new TimerWaterControl(QApplication::applicationDirPath());
}
void frmOpenNow::setControl(){
    on1 = twc->readSettingsOpenNow(flag.toInt());
    ui->txtDescription->setText(on1.description);
    ui->txtPort->setText(on1.port);

}

frmOpenNow::~frmOpenNow()
{
    delete ui;
}

void frmOpenNow::on_btnSave_clicked()
{
    on1.description = ui->txtDescription->text();
    on1.port = ui->txtPort->text();
    twc->writeSettingOpenNow(flag.toInt(),on1);
}
