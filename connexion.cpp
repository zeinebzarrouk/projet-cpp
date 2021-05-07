#include "connexion.h"
#include <QtSql/QSqlDatabase>
connexion::connexion()
{

}

bool connexion::setConnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A");
    db.setUserName("zeineb");
    db.setPassword("zeineb123");

    if (db.open())
    test=true;





        return  test;
}
