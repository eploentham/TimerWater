#ifndef FRMSENSOR1_H
#define FRMSENSOR1_H

#include <QDialog>
#include <timerwatercontrol.h>
#include <QDebug>
namespace Ui {
class frmsensor1;
}

class frmsensor1 : public QDialog
{
    Q_OBJECT

public:
    explicit frmsensor1(QWidget *parent = 0);
    ~frmsensor1();

private slots:
    void on_btnSave_clicked();

    void on_cboSensor_currentIndexChanged(int index);

    void on_cboTSensor_currentIndexChanged(int index);

    void on_chkStatusPumpnodeMCU_clicked(bool checked);

    void on_chkStatusFaucetnodeMCU_clicked(bool checked);

    void on_chkValueOnOff_clicked(bool checked);

private:
    Ui::frmsensor1 *ui;
    TimerWaterControl *twc;
    bool isNew, pageLoad;
    void writeSettings();
    void writeSettingSensor();
    void readSettingSensor(int row);
    void genId();
    void setChkOnOff(bool chk);
    void setgbTSensor(int row);
};

#endif // FRMSENSOR1_H
