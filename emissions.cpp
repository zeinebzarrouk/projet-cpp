#include "emissions.h"

emissions::emissions()
{

}
QString emissions::get_nom_emision(){return nom_emision;}
QString emissions::get_nom_presentateur(){ return nom_presentateur;}
QString emissions::get_id(){return id;}


void emissions::set_nom_emision(QString n) {nom_emision = n;}
void emissions::set_nom_presentateur(QString n) {nom_presentateur = n;}
void emissions::set_id(QString n){id = n;}
void emissions::ajouter()
{
    QSqlQuery requete;
    requete.prepare("INSERT INTO EMISSIONS( "
"NOM_EMISSION,"
"NOM_PRESENTATEUR,"
"ID)"
"VALUES (?,?,?);");

    requete.addBindValue(nom_emision);
    requete.addBindValue(nom_presentateur);
    requete.addBindValue(id);
 if(!requete.exec())
 {
     qDebug() << "Erreur ajout d'emission" ;
     QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Erreur d'ajout d'emission"),QMessageBox::Ok );
 }

 else
 {
    qDebug() << "Article ajouter avec sucées !";
     QMessageBox::information(nullptr,QObject::tr("Ajout") , QObject::tr("L'ajout de l'emission a été effectué avec succés!"),QMessageBox::Ok );
 }


}
bool emissions::update(QString id,QString nom_emision,QString nom_presentateur)
{
QSqlQuery req;
req.prepare("UPDATE EMISSIONS SET NOM_EMISSION=? where ID=?");
req.addBindValue(nom_emision);
req.addBindValue(id);
req.exec();
req.clear();
req.prepare("UPDATE EMISSIONS SET NOM_PRESENTATEUR=? where ID=?");
req.addBindValue(nom_presentateur);
req.addBindValue(id);
req.exec();
req.clear();



}
QSqlQueryModel* emissions::afficher(int a)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    switch(a)
    {
    case 0:
        model->setQuery("SELECT* FROM EMISSIONS ORDER BY NOM_EMISSION");
        break;
    case 1:
        model->setQuery("SELECT* FROM EMISSIONS ORDER BY NOM_PRESENTATEUR");
        break;
    default:
        model->setQuery("SELECT* FROM EMISSIONS");
        break;
    }
    model->setHeaderData(0, Qt::Horizontal , QObject::tr("Nom de l'emission"));
    model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom du presentateur"));
    model->setHeaderData(2, Qt::Horizontal , QObject::tr("Id de l'emissions"));

    return model;
}
void emissions::supprimer(QString id)
{
    QSqlQuery requete;

    //requete.prepare("DELETE FROM ARTICLES WHERE ID=?");
   // requete.prepare("SELECT ID FROM ARTICLES WHERE ID=?");


  //requete.addBindValue(id);
  int row_count = 0;
  bool test;
    requete.prepare("SELECT COUNT(*) FROM EMISSIONS WHERE ID=?");
    requete.addBindValue(id);
    test = requete.exec();
    if(requete.first())
        row_count = requete.value(0).toInt();
    qDebug() << row_count;
    if(test == true && row_count !=0)
    {
      requete.clear();
      requete.prepare("DELETE FROM EMISSIONS WHERE ID=?");
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
