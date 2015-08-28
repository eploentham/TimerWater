#ifndef FRMTEMP_H
#define FRMTEMP_H

#include <QMainWindow>

namespace Ui {
class frmtemp;
}

class frmtemp : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmtemp(QWidget *parent = 0);
    ~frmtemp();

private:
    Ui::frmtemp *ui;
};

#endif // FRMTEMP_H
