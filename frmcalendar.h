#ifndef FRMCALENDAR_H
#define FRMCALENDAR_H

#include <QDialog>

namespace Ui {
class frmCalendar;
}

class frmCalendar : public QDialog
{
    Q_OBJECT

public:
    explicit frmCalendar(QWidget *parent = 0);
    ~frmCalendar();

private:
    Ui::frmCalendar *ui;
};

#endif // FRMCALENDAR_H
