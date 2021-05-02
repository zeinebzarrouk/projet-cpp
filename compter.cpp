#include "personnel.h"

int comptedirecteur(){

    //c'est un exemple
    QString genre = "homme";
    QSqlQueryModel *nbr = new QSqlQueryModel();

    nbr->setQuery("SELECT * FROM employe WHERE  sexe LIKE '"+genre+"%'");

    return nbr->rowCount();

}
