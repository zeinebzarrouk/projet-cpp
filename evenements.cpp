#include "evenements.h"

evenement::evenement(QString nom, QString adresse, int capacite,int id, QDate date_debut, QDate date_fin )
{
this->nom=nom;
    this->date_debut=date_debut;
    this->date_fin=date_fin;
    this->adresse=adresse;
    this->id=id;
    this->capacite=capacite;
}

bool evenement::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(capacite);

     query.prepare("INSERT INTO evenements (ID,CAPACITE, NOM, DATE_DEBUT,DATE_FIN,ADRESSE) "
                        "VALUES (:id, :capacite, :nom, :date_debut, :date_fin, :adresse)");
    query.bindValue(":id", res);
    query.bindValue(":capacite", res1);

    query.bindValue(":nom", nom);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":adresse", adresse);



    return    query.exec();

}

 QSqlQueryModel * evenement::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from evenements");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_debut "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_fin "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("capacite"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse "));


        return model;
    }
 bool evenement::modifier(int capacite, QString nom, QDate date_debut, QDate date_fin , QString adresse,int id)
 {
     QSqlQuery query;
     QString res= QString::number(id);
     QString res1= QString::number(capacite);

     query.prepare("update evenements set capacite=:capacite,nom=:nom,date_debut=:date_debut,date_fin=:date_fin, adresse=:adresse where id=:id");
     query.bindValue(":id", res);
     query.bindValue(":capacite",res1);
     query.bindValue(":nom",nom);
     query.bindValue(":date_debut",date_debut);
     query.bindValue(":date_fin",date_fin);
     query.bindValue(":adresse", adresse);
     return query.exec();
 }


 bool evenement::supprimer(int idd)
 {

     QSqlQuery query;
     QString res= QString::number(idd);
     query.prepare("Delete from evenements where ID = :id ");
     query.bindValue(":id", res);
     return    query.exec();
 }



