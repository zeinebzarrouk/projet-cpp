#include "connection.h"
#include "QSqlDatabase"
Connection::Connection()
{

}

bool Connection::createConnection()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A");
    db.setUserName("sofiene");
    db.setPassword("besbes13");

    if(db.open())
        test=true;

    return test;
}
