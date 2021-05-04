#ifndef FONCTION_H
#define FONCTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fonction
{
private:
    QString nom,caract,diplome;
    int id,nbheure;
public:
    fonction();
    fonction(int,QString,QString,int,QString);
    ~fonction(){};
    QString get_nom();
    QString get_caract();
   int get_nbheure();
   int get_id();
    QString get_diplome();
    void set_nom(QString n);
    void set_caract(QString n);
    void set_nbheure(int n);
    void set_diplome(QString n);
    void set_id(int id);
    //fonctions liés au crud
    bool ajouterFonct();
    QSqlQueryModel *afficherFonct();
    bool supprimerFonct(int);
    bool modifierFonct(int,QString,QString);
};

#endif // FONCTION_H


