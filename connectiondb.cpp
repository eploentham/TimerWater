#include "connectiondb.h"


ConnectionDB::ConnectionDB()
{


}

bool ConnectionDB::openConnection()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("172.25.4.69");
    db.setDatabaseName("testtimerwater");
    db.setUserName("root");
    db.setPassword("Ekartc2c5");
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
        qDebug() <<"Database Error"+db.lastError().text();
        return false;
    }
    return true;
    //bool ok = db.open();
}

QSqlQuery ConnectionDB::selectData(QString sql)
{
    if(db.openConnection()){

    }
}

