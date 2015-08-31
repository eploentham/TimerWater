#ifndef FRMTIMER1_H
#define FRMTIMER1_H

#include <QDialog>

namespace Ui {
class frmtimer1;
}

class frmtimer1 : public QDialog
{
    Q_OBJECT

public:
    explicit frmtimer1(QWidget *parent = 0);
    ~frmtimer1();

private:
    Ui::frmtimer1 *ui;
};

#endif // FRMTIMER1_H
