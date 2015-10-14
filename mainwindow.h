#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <timerwatercontrol.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnTimer_clicked();

    void on_btnSensor_clicked();

    void on_btnRoute_clicked();

    void on_pushButton_4_clicked();

    void on_btnStartWork_clicked();

    void on_pushButton_5_clicked();

    void on_btnCalendar_clicked();

private:
    Ui::MainWindow *ui;
    TimerWaterControl *twc;
};

#endif // MAINWINDOW_H
