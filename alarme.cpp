#include "alarme.h"

Alarme::Alarme()
{

}
QString Alarme::get_datea(){ return datea;}
QString Alarme::get_heurea(){ return heurea;}
QString Alarme::get_nom_alarme(){return nom_alarme;}


void Alarme::set_datea(QString n) {datea = n;}
void Alarme::set_heurea(QString n) {heurea = n;}
void Alarme::set_nom_alarme(QString n) {nom_alarme = n;}
QSqlQueryModel* Alarme::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();




        model->setQuery("SELECT* FROM ALARME");



    model->setHeaderData(0, Qt::Horizontal , QObject::tr("Date"));
    model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom alarme"));
     model->setHeaderData(2, Qt::Horizontal , QObject::tr("Heure"));
    model->setHeaderData(3, Qt::Horizontal , QObject::tr("Minute"));



    return model;
}
int Alarme::ajouter(QString temp,QString date,QString nom_alarme)
{
    QSqlQuery requete;
//

int row_count = 0;
bool test;
  requete.prepare("SELECT COUNT(*) FROM ALARME WHERE NOM_ALARME=?");
  requete.addBindValue(nom_alarme);
  test = requete.exec();
  if(requete.first())
      row_count = requete.value(0).toInt();
  qDebug() << row_count;
  if(test==false)
  {
      //meme pas exec
      qDebug() << "Erreur d'ajout d'alarme" ;
      QMessageBox::critical(nullptr,QObject::tr("Alarme") , QObject::tr("Erreur d'ajout d'alarme"),QMessageBox::Ok );
      return false;
  }
  else if(test == true && row_count!=0)
  {
      //deja existante
      qDebug() << "alarme deja existante !" ;
      QMessageBox::critical(nullptr,QObject::tr("Alarme") , QObject::tr("Alarme deja existante !"),QMessageBox::Ok );
      return false;
  }
  else
  {
     requete.clear();
      requete.prepare("INSERT INTO ALARME( "
  "DATEA,"
  "NOM_ALARME,"
  "HEUREA,"
  "MINUTEA)"
  "VALUES (?,?,?,?);");
      QStringList spl = temp.split(":");
      requete.addBindValue(date);
      requete.addBindValue(nom_alarme);
      requete.addBindValue(spl[0].toInt());
      requete.addBindValue(spl[1].toInt());
  requete.exec();
QMessageBox::information(nullptr,QObject::tr("Alarme") , QObject::tr("Alarme ajoué avec succés !"),QMessageBox::Ok );


       return true;





  }
}
int Alarme::supprimer(QString nom)
{

    QSqlQuery requete;



  int row_count = 0;
  bool test;
    requete.prepare("SELECT COUNT(*) FROM ALARME WHERE NOM_ALARME=?");
    requete.addBindValue(nom);
    test = requete.exec();
    if(requete.first())
        row_count = requete.value(0).toInt();
    qDebug() << row_count;
    if(test == true && row_count !=0)
    {

      requete.clear();
      requete.prepare("DELETE FROM ALARME WHERE NOM_ALARME=?");
      requete.addBindValue(nom);
      requete.exec();
      qDebug() << "Suppression effectué avec succés" ;
       QMessageBox::information(nullptr,QObject::tr("Alarme") , QObject::tr("Alarme supprimé avec succés !"),QMessageBox::Ok );
      return 1;

    }
    else if(test == true && row_count==0)
    {
        qDebug() << nom << " n'existe pas et donc ne peux pas etre supprime";
        QMessageBox::critical(nullptr,QObject::tr("Alarme") , QObject::tr("nom d'alarme inexistant"),QMessageBox::Cancel );
        return 0;
    }
    else
    {
        qDebug() << "erreur de suppresion";
        QMessageBox::critical(nullptr,QObject::tr("Suppresion") , QObject::tr("Erreur de suppresion"),QMessageBox::Cancel );
        return 0;
    }
}

QString Alarme::comparaison()

{
    //QString tempActuelle = QDateTime::currentDateTime().toString("hh:mm");
    int heureActuelle = QDateTime::currentDateTime().time().hour();
    int minuteActuelle = QDateTime::currentDateTime().time().minute();
    QString dateActuelle = QDateTime::currentDateTime().toString("dd/MM/yyyy");
    QString test= "";
    /*qDebug() << heureActuelle;
    qDebug() << minuteActuelle;
    if(dateActuelle == "04/06/2021")
    qDebug() << dateActuelle;*/
    //QStringList list1 =  dateActuelle.split("/");

     /*int test1 = list1[0].toInt();
     int test2 = list1[1].toInt();
     int test3 = list1[2].toInt();*/
     QSqlQuery requete;

     requete.prepare("SELECT NOM_ALARME from ALARME WHERE HEUREA=? AND MINUTEA=?");

     requete.addBindValue(heureActuelle);
     requete.addBindValue(minuteActuelle);
     if(requete.exec())
     {
        //qDebug() << tempActuelle;
         while(requete.next())
             test = requete.value(0).toString();

     }
     else
         qDebug() << "erreur ";





    return test;

}
