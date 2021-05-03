#include "mainwindow.h"
#include "connexion.h"
#include <QMessageBox>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    connexion c;
    bool test = c.setConnection();
    if(test)
        QMessageBox::information(nullptr,QObject::tr("database is open " ) , QObject::tr("connexion réussite" "click ok to exit"),QMessageBox::Ok);
        else
                QMessageBox::critical(nullptr,QObject::tr("database is open " ) , QObject::tr("connexion failed ! " "click cancel to exit"),QMessageBox::Cancel);

    w.show();
    return a.exec();
}
