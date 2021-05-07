#include "journaliste.h"
#include <QDebug>
#include "connection.h"
#include <QSqlQuery>

journaliste::journaliste()
{   id=0;
    nom="";
    prenom="";
    adresse="";
    specialite="";
    num=0;

}
journaliste::journaliste(int id,QString nom,QString prenom,QString adresse,QString specialite,int num)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
     this->specialite=specialite;
     this->num=num;

}
int journaliste::getid(){return id;}
QString journaliste::getnom(){return  nom;}
QString journaliste::getprenom(){return  prenom;}
QString journaliste::getadresse(){return  adresse;}
QString journaliste::getspecialite(){return  specialite;}
int journaliste::getnum(){return num;}



bool journaliste::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO journaliste (ID, NOM, PRENOM, ADRESSE, SPECIALITE, NUM) "
                    "VALUES (:id, :nom, :prenom, :adresse, :specialite, :num)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":specialite", specialite);
query.bindValue(":num", num);


return    query.exec();
}

QSqlQueryModel * journaliste::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from journaliste");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Specialite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num"));

    return model;
}

bool journaliste::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from journaliste where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * journaliste::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from journaliste where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }
bool journaliste::modifier(int id,QString adresse,int num)
 {
     QSqlQuery query ;
     QString res_id = QString::number(id) ;

     query.prepare("update journaliste set id=:id, adresse=:adresse, num=:num where id=:id");

     query.bindValue(":id", res_id) ;
     query.bindValue(":adresse", adresse) ;
     query.bindValue(":num", num) ;

     return query.exec() ;

 }

QSqlQueryModel * journaliste::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from journaliste order by ID desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

    return model;
}
journalisteh::journalisteh()
{
nom="";
datee="";
fn="";
}
journalisteh::journalisteh(QString nom,QString datee,QString fn)
{
    this->nom=nom;
    this->datee=datee;
    this->fn=fn ;
}
QString journalisteh::get_datee(){return  datee;}
QString journalisteh::get_fn(){return  fn;}
QString journalisteh::get_nom(){return  nom;}
bool journalisteh::ajoutehis()
{
    QSqlQuery query;
    query.prepare("INSERT INTO historiquek (NOM, DATEE, FN) "
                  "VALUES (:nom, :datee, :fn)");
    query.bindValue(":nom", nom);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}
bool journalisteh::modifierhis()
{
    QSqlQuery query;
    query.prepare("UPDATE historiquek SET datee='"+datee+"',fn='"+fn+"' where nom='"+nom+"'  ;");
    query.bindValue(":nom",nom);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}
QSqlQueryModel * journalisteh::afficherhis()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from historiquek");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("fonction "));
        return model;

}

