#include "frmroutepump.h"
#include "ui_frmroutepump.h"

frmroutepump::frmroutepump(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmroutepump)
{
    ui->setupUi(this);
}

frmroutepump::~frmroutepump()
{
    delete ui;
}

void frmroutepump::on_btnSave_clicked()
{

}
