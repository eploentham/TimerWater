#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <frmtimer1.h>
#include <frminitial.h>
#include <dialog.h>
#include <frmroute.h>
#include <frmsensor1.h>
#include <frmroute.h>
#include <frmstartwork.h>
#include <QDebug>
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    twc = new TimerWaterControl(QApplication::applicationDirPath());
    this->setWindowTitle("Last Update 58-10-06");
    //mainWindow->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnTimer_clicked()
{
    qDebug() <<"0000";
    //frmtimer frm = new frmtimer(this);
    frmtimer1 f;
    //qDebug() <<"aaaa";
    //f.setTWC(twc);
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

void MainWindow::on_btnStartWork_clicked()
{
    frmStartWork f;
    f.setModal(true);
    f.exec();
}

void MainWindow::on_pushButton_5_clicked()
{

}
