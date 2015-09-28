#ifndef FRMSTARTWORK_H
#define FRMSTARTWORK_H

#include <QDialog>
#include <timer.h>
#include <timerwatercontrol.h>
#include <opennow.h>
namespace Ui {
class frmStartWork;
}

class frmStartWork : public QDialog
{
    Q_OBJECT

public:
    explicit frmStartWork(QWidget *parent = 0);
    ~frmStartWork();

private:
    Ui::frmStartWork *ui;
    //QTimer *timer1;
    QTimer *timerwork;
    Timer *tim;
    TimerWaterControl *twc;
    OpenNow on1, on2,on3;
    //QVector <Timer> tim1;
private slots:
    void onSetDateTime();
    void onSetTimerWork();
    void onTimerWork();
    void on_btnOpenNow1_clicked();
    void on_btnOpenNow1c_clicked();    
    void on_btnOpenNow2_clicked();
    void on_btnOpenNow2c_clicked();
    void on_btnOpenNow3c_clicked();
    void on_btnOpenNow3_clicked();
};

#endif // FRMSTARTWORK_H
