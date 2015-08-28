#include "frmtimer.h"
#include "ui_frmtimer.h"
#include <QDebug>
//QMainWindow a;
frmtimer::frmtimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmtimer)
{
    ui->setupUi(this);
    ui->cboProgram->addItem("โปรแกรม 1");
    ui->cboProgram->addItem("โปรแกรม 2");
    ui->cboProgram->addItem("โปรแกรม 3");
    ui->cboProgram->addItem("โปรแกรม 4");
    ui->cboProgram->addItem("โปรแกรม 5");
    ui->cboProgram->addItem("โปรแกรม 6");
    ui->cboProgram->addItem("โปรแกรม 7");
    ui->cboProgram->addItem("โปรแกรม 8");
    ui->cboProgram->addItem("โปรแกรม 9");
    ui->cboProgram->addItem("โปรแกรม 10");
    ui->cboProgram->addItem("โปรแกรม 11");
    ui->cboProgram->addItem("โปรแกรม 12");
    ui->cboProgram->addItem("โปรแกรม 13");
    ui->cboProgram->addItem("โปรแกรม 14");
    ui->cboProgram->addItem("โปรแกรม 15");

}
void initConfig(){
    //ui->cboProgram->addItem("โปรแกรม 1");
}
void someFunction() {
   qDebug() << "pressed";
}
frmtimer::~frmtimer()
{
    delete ui;

}
