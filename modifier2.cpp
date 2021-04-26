#include "modifier2.h"
#include "ui_modifier2.h"
#include "emissions.h"

modifier2::modifier2(QWidget *parent) :
     QDialog(parent),
    ui(new Ui::modifier2)
{
    ui->setupUi(this);
}

modifier2::~modifier2()
{
    delete ui;
}
bool modifier2::check_id(QString id)
{
    QSqlQuery requete;

    //requete.prepare("DELETE FROM ARTICLES WHERE ID=?");
   // requete.prepare("SELECT ID FROM ARTICLES WHERE ID=?");


  //requete.addBindValue(id);
  int row_count = 0;
  bool test;
    requete.prepare("SELECT COUNT(*) FROM EMISSIONS WHERE ID=?");
    requete.addBindValue(id);
    test = requete.exec();
    if(requete.first())
        row_count = requete.value(0).toInt();
    qDebug() << row_count;
    if(test == true && row_count !=0)
    {


      //qDebug() << "l'id mawjouda" ;
      //QMessageBox::information(nullptr,QObject::tr("Suppresion") , QObject::tr("id mawjoud!"),QMessageBox::Ok );
      ui->label_12->setText(id);
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
        QMessageBox::critical(nullptr,QObject::tr("Suppresion") , QObject::tr("Erreur de recherche"),QMessageBox::Cancel );
    }
}

void modifier2::on_pushButton_clicked()
{
    QString id,nome,nomp,type;
     emissions a;
    id = ui->label_12->text();
    nome = ui->lineEdit_nome->text();
    nomp = ui->lineEdit_nomp->text();
    // MainWindow()
    qDebug() << id;
    a.update(id,nome,nomp);


}
