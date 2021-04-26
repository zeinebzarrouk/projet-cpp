#include "articles.h"
#include "ui_Modifier.h"
#include "ui_mainwindow.h"
#include <QObject>
Articles::Articles()
{

}
QString Articles::get_nom_article(){return nom_articles;}
QString Articles::get_nom_auteur(){ return nom_auteur;}
QString Articles::get_type(){ return type;}
QString Articles::get_id(){return id;}


void Articles::set_nom_article(QString n) {nom_articles = n;}
void Articles::set_nom_auteur(QString n) {nom_auteur = n;}
void Articles::set_type(QString n) {type = n;}
void Articles::set_id(QString n){id = n;}
void Articles::ajouter()
{
    QSqlQuery requete;
    requete.prepare("INSERT INTO Articles( "
"NOM_AUTEUR,"
"NOM_ARTICLE,"
"ID,"
"TYPE)"
"VALUES (?,?,?,?);");

    requete.addBindValue(nom_auteur);
    requete.addBindValue(nom_articles);
    requete.addBindValue(id);
    requete.addBindValue(type);
 if(!requete.exec())
 {
     qDebug() << "Erreur ajout d'article" ;
     QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Erreur d'ajout d'article"),QMessageBox::Ok );
 }

 else
 {
    qDebug() << "Article ajouter avec sucées !";
     QMessageBox::information(nullptr,QObject::tr("Ajout") , QObject::tr("L'ajout de l'article a été effectué avec succés!"),QMessageBox::Ok );
 }


}
bool Articles::update(QString id,QString nom,QString auteur,QString type)
{
QSqlQuery req;
req.prepare("UPDATE ARTICLES SET NOM_AUTEUR=? where ID=?");
req.addBindValue(auteur);
req.addBindValue(id);
req.exec();
req.clear();
req.prepare("UPDATE ARTICLES SET NOM_ARTICLE=? where ID=?");
req.addBindValue(nom);
req.addBindValue(id);
req.exec();
req.clear();
req.prepare("UPDATE ARTICLES SET TYPE=? where ID=?");
req.addBindValue(type);
req.addBindValue(id);
req.exec();
req.clear();



}

QSqlQueryModel* Articles::afficher(int a)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    switch(a)
    {
    case 0:
        model->setQuery("SELECT* FROM ARTICLES ORDER BY NOM_ARTICLE");
        break;
    case 1:
        model->setQuery("SELECT* FROM ARTICLES ORDER BY NOM_AUTEUR");
        break;

    default:
        model->setQuery("SELECT* FROM ARTICLES");
        break;
    }

    model->setHeaderData(0, Qt::Horizontal , QObject::tr("nom de l'auteur"));
    model->setHeaderData(1, Qt::Horizontal , QObject::tr("nom de l'article"));
    model->setHeaderData(2, Qt::Horizontal , QObject::tr("Id de l'article"));
    model->setHeaderData(3, Qt::Horizontal , QObject::tr("type"));

    return model;
}

void Articles::supprimer(QString id)
{
    QSqlQuery requete;

    //requete.prepare("DELETE FROM ARTICLES WHERE ID=?");
   // requete.prepare("SELECT ID FROM ARTICLES WHERE ID=?");


  //requete.addBindValue(id);
  int row_count = 0;
  bool test;
    requete.prepare("SELECT COUNT(*) FROM ARTICLES WHERE ID=?");
    requete.addBindValue(id);
    test = requete.exec();
    if(requete.first())
        row_count = requete.value(0).toInt();
    qDebug() << row_count;
    if(test == true && row_count !=0)
    {
      requete.clear();
      requete.prepare("DELETE FROM ARTICLES WHERE ID=?");
      requete.addBindValue(id);
      requete.exec();
      qDebug() << "Suppression effectué avec succés" ;
      QMessageBox::information(nullptr,QObject::tr("Suppresion") , QObject::tr("Suppression effectué avec succés!"),QMessageBox::Ok );

    }
    else if(test == true && row_count==0)
    {
        qDebug() << id << " n'existe pas et donc ne peux pas etre supprime";
        QMessageBox::critical(nullptr,QObject::tr("Suppresion") , QObject::tr("Identifiant inexistant"),QMessageBox::Cancel );
    }
    else
    {
        qDebug() << "erreur de suppresion";
        QMessageBox::critical(nullptr,QObject::tr("Suppresion") , QObject::tr("Erreur de suppresion"),QMessageBox::Cancel );
    }

  //qDebug() << test;



}
