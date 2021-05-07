#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Evenement
{
public:
    Evenement();
    Evenement(int,QString,QString,QString,int,int);
    int getid();
    QString getnom_event();
    QString getdatedebut_event();
    QString getdatefin_event();
    int getduree();
    int getcapacite();
    void setid(int);
    void setnom_event(QString);
    void setdatedebut_event(QString);
    void setdatefin_event(QString);
    void setduree(int);
    void setcapacite(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);

private:
   int id;
   QString nom_event;
   QString datedebut_event;
   QString datefin_event;
   int duree;
   int capacite;


};

#endif // EVENEMENT_H
