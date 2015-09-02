#include "frmsensor1.h"
#include "ui_frmsensor1.h"

frmsensor1::frmsensor1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmsensor1)
{
    ui->setupUi(this);
}

frmsensor1::~frmsensor1()
{
    delete ui;
}
