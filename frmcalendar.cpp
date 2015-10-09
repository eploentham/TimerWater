#include "frmcalendar.h"
#include "ui_frmcalendar.h"

frmCalendar::frmCalendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmCalendar)
{
    ui->setupUi(this);
}

frmCalendar::~frmCalendar()
{
    delete ui;
}
