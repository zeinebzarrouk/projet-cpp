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
    int row_count = 0;
    bool test;
      requete.prepare("SELECT COUNT(*) FROM EMISSIONS WHERE ID=?");
      requete.addBindValue(id);
      test = requete.exec();
      if(requete.first())
          row_count = requete.value(0).toInt();
      qDebug() << row_count;
      if(test==false)
      {
          //meme pas exec
          qDebug() << "Erreur ajout d'emission" ;
          QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Erreur d'ajout d'emission"),QMessageBox::Ok );
      }
      else if(test == true && row_count!=0)
      {
          //deja existante
          qDebug() << "Identifiant deja existant !" ;
          QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Identifiant deja existant !"),QMessageBox::Ok );
      }
      else
      {
       if(controle_saisieE(nom_emision,nom_presentateur,id) == -1)
       {
           requete.clear();
           requete.prepare("INSERT INTO emissions( "
       "NOM_EMISSION,"
       "NOM_PRESENTATEUR,"
       "ID)"
       "VALUES (?,?,?);");

           requete.addBindValue(nom_emision);
           requete.addBindValue(nom_presentateur);
           requete.addBindValue(id);
           if(!requete.exec())
               qDebug() << "Erreur ajout d'emission";


           QString date_operation = QDateTime::currentDateTime().toString("dd/MM/yyyy");
           QString heure_operation = QDateTime::currentDateTime().toString("hh:mm:ss");
           requete.clear();
           requete.prepare("INSERT INTO historique( "
       "TYPE_OPERATION,"
       "ENTITE,"
       "DATEO,"
       "HEUREO)"
       "VALUES ('Ajout','emission',?,?);");
           requete.addBindValue(date_operation);
           requete.addBindValue(heure_operation);
           if(!requete.exec())
               qDebug() << "Erreur ajout historique";
           qDebug() << "emission ajouter avec sucées !";
            QMessageBox::information(nullptr,QObject::tr("Ajout") , QObject::tr("L'ajout de l'emission a été effectué avec succés!"),QMessageBox::Ok );

       }
      }






}

int emissions::controle_saisieE(QString nom_emision,QString nom_presentateur,QString id)
{
if(id == "" && nom_emision == "" && nom_presentateur == "")
{
    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Tout les champ sont vide !"),QMessageBox::Ok );
    return 0;
}
else
{
    if(id == "" || nom_emision == "" || nom_presentateur == "")
    {
         QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Il y a un/des champ/s qui sont vide !"),QMessageBox::Ok );
         return 0;
    }
    else
    {
        if(id.length() > 20 || nom_emision.length() > 20 || nom_presentateur.length() > 20 )
        {
             QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs ne doit pas depassé 20 caractére"),QMessageBox::Ok );
             return 0;
        }
        else if(id.length() < 3 || nom_emision.length() < 3 || nom_presentateur.length() < 3)
        {

            QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs doit etre supérieur a 3 caractére"),QMessageBox::Ok );
            return 0;
        }
        int i;
        int j;
        QString caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?0123456789";
        for(i=0;i<nom_presentateur.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(nom_presentateur[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas de chiffre ni de caractéres spéciaux dans le champ ""Nom presentateur"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=nom_presentateur.length();
                    return 0;
                }
            }
        }
        caraspec = "~""#'{([-|`_\^@)]=+}$£¤¨*!§:/;";
        for(i=0;i<nom_emision.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(nom_emision[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("pas de caractéres spéciaux dans le champ ""Nom emission"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=nom_emision.length();
                    return 0;
                }
            }
        }
        caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?";
                for(i=0;i<id.length();i++)
                {
                    for(j=0;j<caraspec.length();j++)
                    {
                        if(id[i] == caraspec[j] )
                        {
                            QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas de caractéres spéciaux dans le champ ""ID"""),QMessageBox::Ok );

                            j=caraspec.length();
                            i=id.length();
                            return 0;
                        }
                    }
                }





    }
}
return -1;
}
bool emissions::update(QString id,QString nom_emision,QString nom_presentateur)
{
QSqlQuery req;
if(controle_saisieE(nom_emision,nom_presentateur,id) == -1)
{
    QString date_operation = QDateTime::currentDateTime().toString("dd/MM/yyyy");
    QString heure_operation = QDateTime::currentDateTime().toString("hh:mm:ss");
    req.prepare("INSERT INTO historique( "
"TYPE_OPERATION,"
"ENTITE,"
"DATEO,"
"HEUREO)"
"VALUES ('Modification','Emissions',?,?);");
    req.addBindValue(date_operation);
    req.addBindValue(heure_operation);
    req.exec();
    req.clear();
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
QMessageBox::information(nullptr,QObject::tr("Modification") , QObject::tr("L'emission a bien été modifier !"),QMessageBox::Ok );
return true;
}
return false;



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
        QString date_operation = QDateTime::currentDateTime().toString("dd/MM/yyyy");
        QString heure_operation = QDateTime::currentDateTime().toString("hh:mm:ss");
        requete.prepare("INSERT INTO historique( "
    "TYPE_OPERATION,"
    "ENTITE,"
    "DATEO,"
    "HEUREO)"
    "VALUES ('Suppression','Emissionss',?,?);");
        requete.addBindValue(date_operation);
        requete.addBindValue(heure_operation);
        requete.exec();
        requete.clear();
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
