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

private slots:
    void on_btnSave_clicked();

    void on_cboProgram_currentIndexChanged(int index);

private:
    Ui::frmtimer1 *ui;
    QString fileIni;
    void writeSettingsTimer();
    void readSettingsTimer();
};

#endif // FRMTIMER1_H
