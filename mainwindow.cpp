#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <frmtimer.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnTimer_clicked()
{
    frmtimer *frm = new frmtimer(this);
    frm->show();
    //this->hide();
}
