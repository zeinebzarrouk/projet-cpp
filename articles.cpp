#include "articles.h"
#include "ui_Modifier.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QDateTime>
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
    int row_count = 0;
    bool test;
      requete.prepare("SELECT COUNT(*) FROM ARTICLES WHERE ID=?");
      requete.addBindValue(id);
      test = requete.exec();
      if(requete.first())
          row_count = requete.value(0).toInt();
      qDebug() << row_count;
      if(test==false)
      {
          //meme pas exec
          qDebug() << "Erreur ajout d'article" ;
          QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Erreur d'ajout d'article"),QMessageBox::Ok );
      }
      else if(test == true && row_count!=0)
      {
          //deja existante
          qDebug() << "Identifiant deja existant !" ;
          QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Identifiant deja existant !"),QMessageBox::Ok );
      }
      else
      {
       if(controle_saisieA(id,nom_articles,nom_auteur,type) == -1)
       {
           requete.clear();
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
               qDebug() << "Erreur ajout article";


           QString date_operation = QDateTime::currentDateTime().toString("dd/MM/yyyy");
           QString heure_operation = QDateTime::currentDateTime().toString("hh:mm:ss");
           requete.clear();
           requete.prepare("INSERT INTO historique( "
       "TYPE_OPERATION,"
       "ENTITE,"
       "DATEO,"
       "HEUREO)"
       "VALUES ('Ajout','Articles',?,?);");
           requete.addBindValue(date_operation);
           requete.addBindValue(heure_operation);
           if(!requete.exec())
               qDebug() << "Erreur ajout historique";
           qDebug() << "Article ajouter avec sucées !";
            QMessageBox::information(nullptr,QObject::tr("Ajout") , QObject::tr("L'ajout de l'article a été effectué avec succés!"),QMessageBox::Ok );

       }
      }











}
int Articles::controle_saisieA(QString id,QString nom,QString auteur,QString type)
{
if(id == "" && nom == "" && auteur == "" && type == "" )
{
    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Tout les champ sont vide !"),QMessageBox::Ok );
    return 0;
}
else
{
    if(id == "" || nom == "" || auteur == "" || type == "" )
    {
         QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Il y a un/des champ/s qui sont vide !"),QMessageBox::Ok );
         return 0;
    }
    else
    {
        if(id.length() > 20 || nom.length() > 20 || auteur.length() > 20 || type.length() > 20 )
        {
             QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs ne doit pas depassé 20 caractére"),QMessageBox::Ok );
             return 0;
        }
        else if(id.length() < 3 || nom.length() < 3 || auteur.length() < 3)
        {

            QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("La taille des champs doit etre supérieur a 3 caractére"),QMessageBox::Ok );
            return 0;
        }
        int i;
        int j;
        QString caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?0123456789";
        for(i=0;i<auteur.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(auteur[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas de chiffre ni de caractéres spéciaux dans le champ ""Nom auteur"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=auteur.length();
                    return 0;
                }
            }
        }
        caraspec = "~""#'{([-|`_\^@)]=+}$£¤¨*!§:/;";
        for(i=0;i<nom.length();i++)
        {
            for(j=0;j<caraspec.length();j++)
            {
                if(nom[i] == caraspec[j] )
                {
                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("pas de caractéres spéciaux dans le champ ""Nom articles"""),QMessageBox::Ok );

                    j=caraspec.length();
                    i=auteur.length();
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
                caraspec = "&~""#'{([-|`_\^@)]=+}$£¤¨%*!§:/;?";
                        for(i=0;i<type.length();i++)
                        {
                            for(j=0;j<caraspec.length();j++)
                            {
                                if(type[i] == caraspec[j] )
                                {
                                    QMessageBox::critical(nullptr,QObject::tr("Ajout") , QObject::tr("Pas caractéres spéciaux dans le champ ""Type"""),QMessageBox::Ok );

                                    j=caraspec.length();
                                    i=type.length();
                                    return 0;
                                }
                            }
                        }




    }
}
return -1;

}
bool Articles::update(QString id,QString nom,QString auteur,QString type)
{
QSqlQuery req;
if(controle_saisieA(id,nom,auteur,type)== -1)
{
    QString date_operation = QDateTime::currentDateTime().toString("dd/MM/yyyy");
    QString heure_operation = QDateTime::currentDateTime().toString("hh:mm:ss");
    req.prepare("INSERT INTO historique( "
"TYPE_OPERATION,"
"ENTITE,"
"DATEO,"
"HEUREO)"
"VALUES ('modification','Articles',?,?);");
    req.addBindValue(date_operation);
    req.addBindValue(heure_operation);
    req.exec();
    req.clear();
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
QMessageBox::information(nullptr,QObject::tr("Modification") , QObject::tr("L'article a bien été modifier !"),QMessageBox::Ok );
return true;
}
return false;



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
        QString date_operation = QDateTime::currentDateTime().toString("dd/MM/yyyy");
        QString heure_operation = QDateTime::currentDateTime().toString("hh:mm:ss");
        requete.prepare("INSERT INTO historique( "
    "TYPE_OPERATION,"
    "ENTITE,"
    "DATEO,"
    "HEUREO)"
    "VALUES ('Suppression','Articles',?,?);");
        requete.addBindValue(date_operation);
        requete.addBindValue(heure_operation);
        requete.exec();
        requete.clear();
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
