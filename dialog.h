#ifndef DIALOG_H
#define DIALOG_H
#define ADDRESS 0x04
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <fcntl.h>
//#include <linux/i2c-dev.h>
#include <QThread>
#include <QDialog>
#include <connectiondb.h>
//#include <QSqlQuery>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Dialog *ui;
    ConnectionDB conn;
};

#endif // DIALOG_H
