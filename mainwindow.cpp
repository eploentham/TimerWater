#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <frmtimer.h>
#include <frminitial.h>
#include <dialog.h>

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
    frminitial f;
    f.setModal(true);
    f.exec();

}

void MainWindow::on_btnSensor_clicked()
{
    Dialog dis;
    dis.show();
}
