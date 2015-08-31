#include "frminitial.h"
#include "ui_frminitial.h"

frminitial::frminitial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frminitial)
{
    ui->setupUi(this);
}

frminitial::~frminitial()
{
    delete ui;
}
