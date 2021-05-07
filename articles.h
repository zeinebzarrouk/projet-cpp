#ifndef ARTICLES_H
#define ARTICLES_H

#include <QString>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
class Articles
{
public:
    Articles();
    QString get_nom_auteur();
    QString get_nom_article();
    QString get_type();
    QString get_id();
    void set_nom_auteur(QString n);
    void set_nom_article(QString n);
    void set_type(QString n);
    void set_id(QString n);
    bool ajouter();
    QSqlQueryModel* afficher(int a);
    int supprimer(QString id);
    bool update(QString id,QString nom,QString auteur,QString type);
    int controle_saisieA(QString id,QString nom,QString auteur,QString type);


private:
    QString nom_articles,nom_auteur,type,id;

};

#endif // ARTICLES_H
