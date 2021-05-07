#ifndef evenement_H
#define evenement_H
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QString>
#include<string>
#include<QDate>

#include <QTimer>

class evenement
{

private :
    QString nom,adresse ;
    int capacite,id;
    QDate date_debut, date_fin;

public:
    evenement() {};

    evenement(QString, QString, int,int, QDate, QDate);
    QString getNom(){return nom;}
    QDate getdate_debut(){return date_debut;}
    QDate getdate_fin(){return date_fin;}
    QString getAdresse(){return adresse;}
    int getcapacite(){return capacite;}
     int getId(){return id;}


    void  setNom(QString n){nom=n;}
     void  setdate_debut(QDate p){date_debut=p;}
     void setdate_fin(QDate d){ date_fin=d;}
     void  setAdresse(QString a){adresse=a;}
      void  setcapacite(int i){capacite=i;}
      void  setId(int o){id=o;}


      bool ajouter();
         QSqlQueryModel * afficher();
         bool modifier(int , QString, QDate, QDate , QString , int  );
         bool supprimer(int);

};
#endif // evenement_H
