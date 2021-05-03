#include "connexion.h"
#include <QtSql/QSqlDatabase>
connexion::connexion()
{

}

bool connexion::setConnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2A");//inserer le nom de la source de données ODBC
    db.setUserName("zeineb");//inserer nom de l'utilisateur
    db.setPassword("zeineb123");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;





        return  test;
}
