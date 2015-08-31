#ifndef FRMINITIAL_H
#define FRMINITIAL_H

#include <QDialog>

namespace Ui {
class frminitial;
}

class frminitial : public QDialog
{
    Q_OBJECT

public:
    explicit frminitial(QWidget *parent = 0);
    ~frminitial();

private:
    Ui::frminitial *ui;
};

#endif // FRMINITIAL_H
