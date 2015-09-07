#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <frmtimer1.h>
#include <frminitial.h>
#include <dialog.h>
#include <frmroute.h>
#include <frmsensor1.h>
#include <frmroute.h>
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
    //frmtimer frm = new frmtimer(this);
    frmtimer1 f;
    f.setModal(true);
    f.exec();
}

void MainWindow::on_btnSensor_clicked()
{
    frmsensor1 f;
    f.setModal(true);
    f.exec();
}

void MainWindow::on_btnRoute_clicked()
{
    frmroute f;
    f.setModal(true);
    f.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    Dialog f;
    f.setModal(true);
    f.exec();
}
