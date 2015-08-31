#include "frmroute.h"
#include "ui_frmroute.h"

frmroute::frmroute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmroute)
{
    ui->setupUi(this);
    ui->cboRoute->addItem("เส้นทาง 1");
    ui->cboRoute->addItem("เส้นทาง 2");
    ui->cboRoute->addItem("เส้นทาง 3");
    ui->cboRoute->addItem("เส้นทาง 4");
    ui->cboRoute->addItem("เส้นทาง 5");
    ui->cboRoute->addItem("เส้นทาง 6");
}

frmroute::~frmroute()
{
    delete ui;
}
