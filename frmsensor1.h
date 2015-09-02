#ifndef FRMSENSOR1_H
#define FRMSENSOR1_H

#include <QDialog>

namespace Ui {
class frmsensor1;
}

class frmsensor1 : public QDialog
{
    Q_OBJECT

public:
    explicit frmsensor1(QWidget *parent = 0);
    ~frmsensor1();

private:
    Ui::frmsensor1 *ui;
    void writeSettings();
};

#endif // FRMSENSOR1_H
