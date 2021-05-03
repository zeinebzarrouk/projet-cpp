#include "participants.h"

participants::participants(QString nom,QString prenom,QString adresse,int id,int age )
{
this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->id=id;
    this->age=age;
}

bool participants::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(age);

     query.prepare("INSERT INTO participants (ID,age, NOM, PRENOM,ADRESSE) "
                        "VALUES (:id, :age, :nom, :prenom, :adresse)");
    query.bindValue(":id", res);
    query.bindValue(":age", res1);

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);



    return    query.exec();

}

 QSqlQueryModel * participants::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from participants");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse "));

        return model;
    }
 bool participants::modifier(int id,int age ,QString nom, QString prenom,QString adresse )
 {
     QSqlQuery query;
     QString res= QString::number(id);
     QString res1= QString::number(age);

     query.prepare("update participants set age=:age,nom=:nom,prenom=:prenom, adresse=:adresse where id=:id");
     query.bindValue(":id", res);
     query.bindValue(":age",res1 );
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":adresse", adresse);
     return query.exec();
 }


 bool participants::supprimer(int idd)
 {

     QSqlQuery query;
     QString res= QString::number(idd);
     query.prepare("Delete from participants where ID = :id ");
     query.bindValue(":id", res);
     return    query.exec();
 }


 int participants::stati()
 {
     QSqlQuery query;
     int count=0 ;
     QSqlQuery requete("select * from participants where AGE BETWEEN '18' AND '35' ") ;
     while(requete.next())

     {
             count++ ;
     }

 return(count);
 }
 int participants::stati1()
 {
     QSqlQuery query;
     int count=0 ;
     QSqlQuery requete("select * from participants where age BETWEEN '35' AND '65'") ;
     while(requete.next())

     {
             count++ ;
     }

 return(count);
 }

 int participants::nb_total()
 {
     QSqlQuery query;
     int count=0 ;
     QSqlQuery requete("select * from participants") ;
     while(requete.next())

     {
             count++ ;
     }

 return(count);
 }


 QSqlQueryModel* participants::trie()
 {
     QSqlQueryModel* model = new QSqlQueryModel();

         model->setQuery("select *from participants ORDER BY ID asc");

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("AGE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr(" NOM"));

          model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));


     return model;
 }

 QSqlQueryModel* participants::trie2()
 {
     QSqlQueryModel* model = new QSqlQueryModel();

         model->setQuery("select *from participants ORDER BY ID desc");

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("AGE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr(" NOM"));

          model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));


     return model;
 }


 QSqlQueryModel * participants::chercher_emp(const QString &aux)
 {
     QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("select * from participants where ((id ) LIKE '%"+aux+"%')");
     model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Vertical,QObject::tr("AGE"));
     model->setHeaderData(3,Qt::Vertical,QObject::tr("PRENOM"));
     model->setHeaderData(4,Qt::Vertical,QObject::tr("NOM"));
     model->setHeaderData(2,Qt::Vertical,QObject::tr("ADRESSE"));

     return model;
 }


 QSqlQueryModel * participants::chercher_emp1(const QString &aux)
 {
     QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("select * from participants where ((age ) LIKE '%"+aux+"%')");
     model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Vertical,QObject::tr("AGE"));
     model->setHeaderData(3,Qt::Vertical,QObject::tr("PRENOM"));
     model->setHeaderData(4,Qt::Vertical,QObject::tr("NOM"));
     model->setHeaderData(2,Qt::Vertical,QObject::tr("ADRESSE"));

     return model;
 }

 QSqlQueryModel * participants::chercher_emp2(const QString &aux)
 {
     QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("select * from participants where ((nom ) LIKE '%"+aux+"%')");
     model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Vertical,QObject::tr("AGE"));
     model->setHeaderData(3,Qt::Vertical,QObject::tr("PRENOM"));
     model->setHeaderData(4,Qt::Vertical,QObject::tr("NOM"));
     model->setHeaderData(2,Qt::Vertical,QObject::tr("ADRESSE"));

     return model;
 }










