#include "modifier.h"
#include "ui_Modifier.h"
#include "articles.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)

{
    ui->setupUi(this);


}

modifier::~modifier()
{
    delete ui;
}

bool modifier::check_id(QString id)
{
    QSqlQuery requete;

    //requete.prepare("DELETE FROM ARTICLES WHERE ID=?");
   // requete.prepare("SELECT ID FROM ARTICLES WHERE ID=?");


  //requete.addBindValue(id);
  int row_count = 0;
  bool test;
    requete.prepare("SELECT COUNT(*) FROM ARTICLES WHERE ID=?");
    requete.addBindValue(id);
    test = requete.exec();
    if(requete.first())
        row_count = requete.value(0).toInt();
    qDebug() << row_count;
    if(test == true && row_count !=0)
    {


      qDebug() << "l'id mawjouda" ;
      QMessageBox::information(nullptr,QObject::tr("Suppresion") , QObject::tr("id mawjoud!"),QMessageBox::Ok );
      ui->label_13->setText(id);
      return  true;

    }
    else if(test == true && row_count==0)
    {
        qDebug() << id << " id inexistante ";
        QMessageBox::critical(nullptr,QObject::tr("Suppresion") , QObject::tr("Identifiant inexistant"),QMessageBox::Cancel );
        return  false;
    }
    else
    {
        qDebug() << "erreur de suppresion";
        QMessageBox::critical(nullptr,QObject::tr("Suppresion") , QObject::tr("Erreur de suppresion"),QMessageBox::Cancel );
    }
}



void modifier::on_pushButton_clicked()
{
    QString id,auteur,n_article,type;
     MainWindow we;
     Articles a;
    id = ui->label_13->text();
    auteur = ui->lineEdit_auteur->text();
    n_article = ui->lineEdit_narticle->text();
    type = ui->lineEdit_type->text();
    // MainWindow()
    qDebug() << id;
    a.update(id,n_article,auteur,type);
    QMessageBox::information(nullptr,QObject::tr("Modification") , QObject::tr("L'article a bien été modifier !"),QMessageBox::Ok );
   // ui->lineEdit_id->setText(id);









     //QMessageBox::information(nullptr,QObject::tr("Suppresion") , QObject::tr("id mawjoud!"),QMessageBox::Ok );
}
