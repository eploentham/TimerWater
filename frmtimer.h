#ifndef FRMTIMER_H
#define FRMTIMER_H

#include <QMainWindow>

namespace Ui {
class frmtimer;
}

class frmtimer : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmtimer(QWidget *parent = 0);
    ~frmtimer();

private:
    Ui::frmtimer *ui;
};

#endif // FRMTIMER_H
