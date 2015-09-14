#ifndef FRMSTARTWORK_H
#define FRMSTARTWORK_H

#include <QDialog>
#include <timer.h>
#include <timerwatercontrol.h>
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
    //QVector <Timer> tim1;
private slots:
    void onSetDateTime();
    void onSetTimerWork();
    void on_btnOpenDirect1_clicked();
    void on_btnOpenDirect2_clicked();
    void on_btnOpenDirect3_clicked();
};

#endif // FRMSTARTWORK_H
