#include "mission.h"
#include <QDebug>
#include "connection.h"
#include <QSqlQuery>

mission::mission()
{   id=0;
    nom="";
    type="";
    localisation="";

}
mission::mission(int id,QString nom,QString type,QString localisation)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->localisation=localisation;

}
int mission::getid(){return id;}
QString mission::getnom(){return  nom;}
QString mission::gettype(){return  type;}
QString mission::getlocalisation(){return  localisation;}


bool mission::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO mission (ID, NOM, TYPE, LOCALISATION) "
                    "VALUES (:id, :nom, :type, :localisation)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":localisation", localisation);


return    query.exec();
}

QSqlQueryModel * mission::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from mission");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Localisation"));

    return model;
}

bool mission::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from mission where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool mission::modifier(int id,QString type,QString localisation)
 {
     QSqlQuery query ;
     QString res_id = QString::number(id) ;

     query.prepare("update mission set id=:id, type=:type, localisation=:localisation where id=:id");

     query.bindValue(":id", res_id) ;
     query.bindValue(":type", type) ;
     query.bindValue(":localisation", localisation) ;

     return query.exec() ;

 }
QSqlQueryModel * mission::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from mission where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }
