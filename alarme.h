#ifndef ALARME_H
#define ALARME_H
#include <QString>
#include <QSqlQueryModel>
#include <QDateTime>
#include <QDebug>
#include <QSqlQuery>
#include "QMessageBox"
class Alarme
{
public:
    Alarme();
    QString get_datea();
    QString get_heurea();
    QString get_nom_alarme();
    void set_datea(QString n);
    void set_heurea(QString n);
    void set_nom_alarme(QString n);
    QSqlQueryModel* afficher();
    QString comparaison();
    int ajouter(QString temp,QString date,QString nom_alarme);
    int supprimer(QString nom);
private:
QString datea,heurea,nom_alarme;

};

#endif // ALARME_H
