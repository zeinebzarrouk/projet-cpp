#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QApplication>
#include <QSqlQuery>
#include "connection.h"
#include "modifier.h"

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
    if(test)
     QMessageBox::information(nullptr,QObject::tr("database is open") , QObject::tr("connexion reussite !" "click ok to exit"),QMessageBox::Ok );
        //qDebug() << "connection réussite" << endl;
    else
        QMessageBox::critical(nullptr,QObject::tr("database is open") , QObject::tr("Database failure !" "click cancel to exit"),QMessageBox::Cancel );
    MainWindow w;




    /*QString tr = "CREATE TABLE emissions ("
    "NOM_EMISSION varchar2(20),"
    "NOM_PRESENTATEUR varchar2(20),"
    "ID varchar2(20));";*/








    //test_requete(tr,"requéte reussite","requéte echoué");



    //requete.exec("INSERT INTO CLIENTS VALUES (10,'SAMIR','REZGUI')");





    w.show();

    return a.exec();
}
