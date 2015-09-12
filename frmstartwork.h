#ifndef FRMSTARTWORK_H
#define FRMSTARTWORK_H

#include <QDialog>
#include <timer.h>
namespace Ui {
class frmStartWork;
}

class frmStartWork : public QDialog
{
    Q_OBJECT

public:
    explicit frmStartWork(QWidget *parent = 0);
    ~frmStartWork();

private:
    Ui::frmStartWork *ui;
    QTimer *timer1;
    Timer *tim;
private slots:
    void onSetDateTime();
};

#endif // FRMSTARTWORK_H
