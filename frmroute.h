#ifndef FRMROUTE_H
#define FRMROUTE_H

#include <QDialog>

namespace Ui {
class frmroute;
}

class frmroute : public QDialog
{
    Q_OBJECT

public:
    explicit frmroute(QWidget *parent = 0);
    ~frmroute();

private:
    Ui::frmroute *ui;
};

#endif // FRMROUTE_H
