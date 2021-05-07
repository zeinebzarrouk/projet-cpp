#ifndef CONNEXION_H
#define CONNEXION_H
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>

class connexion
{
public:
    connexion();
    bool setConnection();
};

#endif // CONNEXION_H
