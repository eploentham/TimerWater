#include "frmroute.h"
#include "ui_frmroute.h"

frmroute::frmroute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmroute)
{
    ui->setupUi(this);
    //ui->cboRoute->addItem("เส้นทาง 1"); //version 4.8 can't run thai language
    ui->cboRoute->addItem("Route 1");
    ui->cboRoute->addItem("Route 2");
    ui->cboRoute->addItem("Route 3");
    ui->cboRoute->addItem("Route 4");
    ui->cboRoute->addItem("Route 5");
    ui->cboRoute->addItem("Route 6");
}

frmroute::~frmroute()
{
    delete ui;
}
