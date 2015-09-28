#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 * 58-09-28 Ekapop 1.0 set center screen
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QRect screenGeometry = QApplication::desktop()->screenGeometry();   //1.0
    int x = (screenGeometry.width()-w.width()) / 2;         //1.0
    int y = (screenGeometry.height()-w.height()) / 2;       //1.0
    w.move(x, y);       //1.0
    w.show();

    return a.exec();
}
