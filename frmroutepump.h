#ifndef FRMROUTEPUMP_H
#define FRMROUTEPUMP_H

#include <QDialog>

namespace Ui {
class frmroutepump;
}

class frmroutepump : public QDialog
{
    Q_OBJECT

public:
    explicit frmroutepump(QWidget *parent = 0);
    ~frmroutepump();

private:
    Ui::frmroutepump *ui;
};

#endif // FRMROUTEPUMP_H
