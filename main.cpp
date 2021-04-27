#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QApplication>
#include <QSqlQuery>
#include "connection.h"


void test_requete(QString t,QString R,QString F)
{

    QSqlQuery requete;
    if(!requete.exec(t))
        qDebug()<< F ;
    else
        qDebug() << R ;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection C;
    bool test = C.createConnection();
    /*if(test)
     QMessageBox::information(nullptr,QObject::tr("database is open") , QObject::tr("connexion reussite !" "click ok to exit"),QMessageBox::Ok );
        //qDebug() << "connection réussite" << endl;
    else
        QMessageBox::critical(nullptr,QObject::tr("database is open") , QObject::tr("Database failure !" "click cancel to exit"),QMessageBox::Cancel );*/
    MainWindow w;




    /*QString tr = "CREATE TABLE historique ("
    "TYPE_OPERATION varchar2(20),"
    "ENTITE varchar2(20),"
    "DATEO varchar2(20),"
    "HEUREO varchar2(20));";*/








    //test_requete(tr,"requéte reussite","requéte echoué");



    //requete.exec("INSERT INTO CLIENTS VALUES (10,'SAMIR','REZGUI')");





    w.show();

    return a.exec();
}
