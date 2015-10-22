#ifndef FRMNODEMCU_H
#define FRMNODEMCU_H

#include <QDialog>
#include <timerwatercontrol.h>
#include <QDebug>

namespace Ui {
class frmnodeMCU;
}

class frmnodeMCU : public QDialog
{
    Q_OBJECT

public:
    explicit frmnodeMCU(QWidget *parent = 0);
    ~frmnodeMCU();

private slots:
    void on_btnSave_clicked();

    void on_cbonodeMCU_currentIndexChanged(int index);

private:
    Ui::frmnodeMCU *ui;
    TimerWaterControl *twc;
    void writeSettingnodeMCU();
    void readSettingnodeMCU(int row);
    void genId();
};

#endif // FRMNODEMCU_H
