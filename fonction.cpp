#include "fonction.h"

fonction::fonction()
{
        nom="";
        caract="";
        nbheure=0 ;
        diplome="";
        id=0;

}
fonction::fonction(int id,QString nom,QString caract,int nbheure,QString diplome){
    this->id=id;
    this->nom=nom;
    this->caract=caract;
    this->nbheure=nbheure;
    this->diplome=diplome;
}

void fonction::set_nom(QString n){nom=n;}
void fonction::set_nbheure(int n){nbheure=n;}
void fonction::set_caract(QString n){caract=n;}
void fonction::set_diplome(QString n){diplome=n;}
void fonction::set_id(int n){id=n;}


QString fonction::get_nom(){return nom;}
int fonction::get_nbheure(){return nbheure;}
QString fonction::get_caract(){return caract;}
QString fonction::get_diplome(){return diplome;}
int fonction::get_id(){return id;}


bool fonction::ajouterFonct()
{
    QSqlQuery querry;
    QString res=QString::number(id);

    querry.prepare ("INSERT INTO fonction(ID,NOM,CARACT,NBHEURE, DIPLOME)""VALUES(:id,:nom,:caract,:nbheure,:diplome)");
    querry.bindValue(":id",res);
    querry.bindValue(":nom",nom);
    querry.bindValue(":caract",caract);
    querry.bindValue(":nbheure",nbheure);
    querry.bindValue(":diplome",diplome);

    return querry.exec();

}

bool fonction::supprimerFonct(int)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("DELETE FROM fonction WHERE ID=:id");
    query.bindValue(":id",res);
    return query.exec();

}


QSqlQueryModel * fonction::afficherFonct()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("SELECT* FROM fonction");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("CARACT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("NBHEURE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DIPLOME"));


      return model;
}


bool fonction::modifierFonct(int id,QString nom,QString caract)
{

    QSqlQuery query;
    QString res= QString::number(id);

    query.prepare("UPDATE fonction SET ID=:id ,NOM=:nom,CARACT=:caract WHERE ID=:id ");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":caract",caract);

    return    query.exec();
}












