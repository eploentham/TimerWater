#ifndef FRMTIMER1_H
#define FRMTIMER1_H

#include <QDialog>
#include <timerwatercontrol.h>

namespace Ui {
class frmtimer1;
}

class frmtimer1 : public QDialog
{
    Q_OBJECT

public:
    explicit frmtimer1(QWidget *parent = 0);
    ~frmtimer1();
    //void setTWC(TimerWaterControl *twc);

private slots:
    void on_btnSave_clicked();

    void on_cboProgram_currentIndexChanged(int index);

    void on_spinBoxPeriod_valueChanged(int arg1);

private:
    Ui::frmtimer1 *ui;
    QString fileIni;

    void writeSettingsTimer();
    void readSettingsTimer(int row);
    TimerWaterControl *twc;
};

#endif // FRMTIMER1_H
