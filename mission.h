#ifndef MISSION_H
#define MISSION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class mission
{
public:
    mission();
    mission(int,QString,QString,QString);
    int getid();
    QString getnom();
    QString gettype();
    QString getlocalisation();

    void setnom (QString);
    void setlocalisation(QString);
    void settype(QString);



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    //bool modifier(int,QString,QString,QString,QString,QString,int);

    QSqlQueryModel * rechercher(int);
    bool modifier(int,QString,QString);




private:
    int id;
    QString nom,type,localisation;
};

#endif // MISSION_H
