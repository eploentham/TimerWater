#ifndef FRMSENSOR_H
#define FRMSENSOR_H

#include <QMainWindow>

namespace Ui {
class frmSensor;
}

class frmSensor : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmSensor(QWidget *parent = 0);
    ~frmSensor();

private:
    Ui::frmSensor *ui;
};

#endif // FRMSENSOR_H
