#include "frmnodemcu.h"
#include "ui_frmnodemcu.h"

frmNodeMCU::frmNodeMCU(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmNodeMCU)
{
    ui->setupUi(this);
}

frmNodeMCU::~frmNodeMCU()
{
    delete ui;
}
