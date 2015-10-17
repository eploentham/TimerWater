#ifndef FRMNODEMCU_H
#define FRMNODEMCU_H

#include <QDialog>

namespace Ui {
class frmNodeMCU;
}

class frmNodeMCU : public QDialog
{
    Q_OBJECT

public:
    explicit frmNodeMCU(QWidget *parent = 0);
    ~frmNodeMCU();

private:
    Ui::frmNodeMCU *ui;
};

#endif // FRMNODEMCU_H
