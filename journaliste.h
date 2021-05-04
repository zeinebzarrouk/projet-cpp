#ifndef JOURNALISTE_H
#define JOURNALISTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class journaliste
{
public:
    journaliste();
    journaliste(int,QString,QString,QString,QString,int);
    int getid();
    int getnum();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QString getspecialite();

    void setnom (QString);
    void setprenom(QString);
    void setspecialite(QString);
    void setadresse(QString);
    void setnum(int);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    //bool modifier(int,QString,QString,QString,QString,QString,int);
    bool modifier(int,QString,int);
    QSqlQueryModel * rechercher(int);
    QSqlQueryModel * afficher_tri();



private:
    int id,num;
    QString nom,prenom,specialite,adresse;
};


#endif // JOURNALISTE_H
