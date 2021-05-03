#include "evenement.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
Evenement::Evenement()
{

}

int Evenement::getid(){return id;}
QString Evenement::getnom_event(){return nom_event;}
QString Evenement::getdatedebut_event(){return datedebut_event;}
QString Evenement::getdatefin_event(){return datefin_event;}
int Evenement::getduree(){return duree;}
int Evenement::getcapacite(){return capacite;}

void Evenement::setid(int id ){this->id=id;}
void Evenement::setnom_event(QString nom_event){this->nom_event=nom_event;}
void Evenement::setdatedebut_event(QString datedebut_event){this->datedebut_event=datedebut_event;}
void Evenement::setdatefin_event(QString datefin_event){this->datefin_event=datefin_event;}
void Evenement::setduree(int duree){this->duree=duree;}
void Evenement::setcapacite(int capacite){this->capacite=capacite;}



bool Evenement::ajouter()
{

    QSqlQuery query;

    QString id_string=QString::number(id);
    QString duree_string=QString::number(duree);
    QString capacite_string=QString::number(capacite);
    query.prepare("INSERT INTO evenement (id, nom evenement, date debut, date fin, capacite, duree) "
                  "VALUES (:id, :nom_event, :datedebut_event,datefin_event,capacite,duree)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom evenement", nom_event);
    query.bindValue(":date debut", datedebut_event);
    query.bindValue(":date fin", datefin_event);
    query.bindValue(":capacite", capacite_string);
    query.bindValue(":duree", duree_string);
    return query.exec();


}


QSqlQueryModel * Evenement::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM evenement");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date debut"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date fin"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("capacite"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree"));

return model;
}

bool Evenement::supprimer(int id)
{

    QSqlQuery query;

    QString id_string=QString::number(id);
    QString duree_string=QString::number(duree);
    QString capacite_string=QString::number(capacite);
    query.prepare("DELETE FROM evenement (id, nom evenement, date debut, date fin, capacite, duree) "
                  "VALUES (:id, :nom_event, :datedebut_event,datefin_event,capacite,duree)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom evenement", nom_event);
    query.bindValue(":date debut", datedebut_event);
    query.bindValue(":date fin", datefin_event);
    query.bindValue(":capacite", capacite_string);
    query.bindValue(":duree", duree_string);
    return query.exec();


}
