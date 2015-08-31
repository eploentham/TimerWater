#include "frmtimer1.h"
#include "ui_frmtimer1.h"

frmtimer1::frmtimer1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmtimer1)
{
    ui->setupUi(this);
    ui->cboProgram->addItem("Program 1");
    ui->cboProgram->addItem("Program 2");
    ui->cboProgram->addItem("Program 3");
    ui->cboProgram->addItem("Program 4");
    ui->cboProgram->addItem("Program 5");
    ui->cboProgram->addItem("Program 6");
    ui->cboProgram->addItem("Program 7");
    ui->cboProgram->addItem("Program 8");
    ui->cboProgram->addItem("Program 9");
    ui->cboProgram->addItem("Program 10");
    ui->cboProgram->addItem("Program 11");
    ui->cboProgram->addItem("Program 12");
    ui->cboProgram->addItem("Program 13");
    ui->cboProgram->addItem("Program 14");
    ui->cboProgram->addItem("Program 15");
    ui->cboProgram->addItem("Program 16");
    ui->cboProgram->addItem("Program 17");
    ui->cboProgram->addItem("Program 18");
    ui->cboProgram->addItem("Program 19");
    ui->cboProgram->addItem("Program 20");
}
void initail(){

}

frmtimer1::~frmtimer1()
{
    delete ui;
}
