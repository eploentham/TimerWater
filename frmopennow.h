#ifndef FRMOPENNOW_H
#define FRMOPENNOW_H

#include <QDialog>
#include <frmopennow.h>
#include <timerwatercontrol.h>
namespace Ui {
class frmOpenNow;
}

class frmOpenNow : public QDialog
{
    Q_OBJECT

public:
    QString flag;
    void setControl();
    explicit frmOpenNow(QWidget *parent = 0);
    ~frmOpenNow();

private slots:
    void on_btnSave_clicked();

private:
    Ui::frmOpenNow *ui;
    TimerWaterControl *twc;
    OpenNow on1;
};

#endif // FRMOPENNOW_H
