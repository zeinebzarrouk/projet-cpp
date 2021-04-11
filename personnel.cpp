#include "personnel.h"
#include <QSqlQuery>

personnel::personnel()
{
nomPrenom="";
          id=0;
          cin="";
          adresse="";
          tel=0;
          salaire=0;
          grade="";
          email="";
          login="";
}
personnel::personnel(QString nomPrenom ,int id ,QString cin ,QString adresse,int tel,int salaire,QString grade,QString email,QString login){
    this->nomPrenom=nomPrenom;
    this->id=id;
    this->cin=cin;
    this->adresse=adresse;
    this->tel=tel;
    this->salaire=salaire;
    this->grade=grade;
    this->email=email;
    this->login=login;
}

void personnel::set_id(int n){id=n;}
void personnel::set_nomPrenom(QString n){nomPrenom=n;}
void personnel::set_cin(QString n){cin=n;}
void personnel::set_adresse(QString n){adresse=n;}
void personnel::set_salaire(int n){salaire=n;}
void personnel::set_tel(int n){tel=n;}
void personnel::set_email(QString n){email=n;}
void personnel::set_grade(QString n){grade=n;}
                                   void personnel::set_login(QString n){login=n;}

                                   QString personnel::get_nomPrenom(){return nomPrenom;}
                                   QString personnel::get_cin(){return cin;}
QString personnel::get_adresse(){return adresse;}
QString personnel::get_grade(){return grade;}
QString personnel::get_email(){return email;}
QString personnel::get_login(){return login;}
int personnel::get_tel(){return tel;}
int personnel::get_id(){return id;}
int personnel::get_salaire(){return salaire;}


bool personnel::ajouterEmpl()
{
    QSqlQuery querry;
    QString res=QString::number(id);
      QString qes=QString::number(tel);
        QString ses=QString::number(salaire);
    querry.prepare ("INSERT INTO employe(NOMPRENOM,ID,N_CIN,ADRESSE, N_TEL, SALAIRE,GRADE, EMAIL, LOGIN)""VALUES(:nomPrenom,:id,:cin,:adresse,:tel,:salaire,:grade,:email,:login)");
    querry.bindValue(":id",res);
    querry.bindValue(":salaire",ses);
    querry.bindValue(":tel",qes);
    querry.bindValue(":grade",grade);
    querry.bindValue(":email",email);
    querry.bindValue(":login",login);
 querry.bindValue(":nomPrenom",nomPrenom);
 querry.bindValue(":n_cin",cin);
 querry.bindValue(":adresse",adresse);
    return querry.exec();

}

bool personnel::supprimer(int)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("DELETE FROM EMPLOYE WHERE ID=:id");
    query.bindValue(":id",res);
    return query.exec();

}


QSqlQueryModel * personnel::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("SELECT* FROM employe");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMPRENOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("N_CIN"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("N_TEL"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("GRADE"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("LOGIN"));

      return model;
}


bool personnel::modifier(int id, int salaire, QString grade)
{

    QSqlQuery query;
    QString res= QString::number(id);
    QString ses=QString::number(salaire);
    query.prepare("UPDATE employe SET ID=:id ,GRADE=:grade,SALAIRE=:salaire WHERE ID=:id ");
    query.bindValue(":id", res);
    query.bindValue(":salaire", ses);
    query.bindValue(":grade",grade);

    return    query.exec();
}
