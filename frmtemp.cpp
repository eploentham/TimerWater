#include "frmtemp.h"
#include "ui_frmtemp.h"

frmtemp::frmtemp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmtemp)
{
    ui->setupUi(this);
}

frmtemp::~frmtemp()
{
    delete ui;
}
