#ifndef CONNECTION_H
#define CONNECTION_H
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QSqlError>
class ConnectionDB
{
public:
    ConnectionDB();
    QSqlDatabase db;
    bool openConnection();
    QSqlQuery selectData(QString sql);
};

#endif // CONNECTION_H
