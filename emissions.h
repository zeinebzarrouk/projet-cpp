#ifndef EMISSIONS_H
#define EMISSIONS_H


#include <QString>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
class emissions
{
public:
    emissions();
    QString get_nom_emision();
    QString get_nom_presentateur();
    QString get_id();
    void set_nom_emision(QString n);
    void set_nom_presentateur(QString n);
    void set_id(QString n);
    void ajouter();
    QSqlQueryModel* afficher(int a);
    void supprimer(QString id);
    bool update(QString id,QString nom_emision,QString nom_presentateur);
    int controle_saisieE(QString nom_emision,QString nom_presentateur,QString id);
private:
    QString nom_emision,nom_presentateur,id;
};

#endif // EMISSIONS_H
