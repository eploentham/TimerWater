#ifndef CONNECTION_H
#define CONNECTION_H
#include <QDebug>
//#include <QtSql>


class ConnectionDB
{
public:
    ConnectionDB();
    QSqlDatabase db;
    bool openConnection();
    QSqlQuery selectData(QString sql);
};

#endif // CONNECTION_H
