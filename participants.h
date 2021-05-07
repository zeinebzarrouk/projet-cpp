#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QString>
#include<string>

class participants
{

private :
    QString nom,prenom,adresse ;
    int id,age ;



public:
    participants() {};

    participants(QString, QString, QString, int, int);
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getAdresse(){return adresse;}
    int getId(){return id;}
    int getAge(){return age;}

    void setNom(QString n){nom=n;}
     void setPrenom(QString p){prenom=p;}
     void setAdresse(QString a){adresse=a;}
      void setId(int i){id=i;}
      void setAge(int g){age=g;}

      bool ajouter();
         QSqlQueryModel * afficher();
         bool modifier(int, int , QString ,QString , QString );
         bool supprimer(int);

         int stati();
             int stati1();
             int stati2();
             int nb_total();

             QSqlQueryModel* trie();
                 QSqlQueryModel* trier(const QString, const QString);
                 QSqlQueryModel* trie2();

                 QSqlQueryModel *chercher_emp(const QString &aux);
                   QSqlQueryModel *chercher_emp1(const QString &aux);
                   QSqlQueryModel *chercher_emp2(const QString &aux);


};

#endif // PARTICIPANTS_H
