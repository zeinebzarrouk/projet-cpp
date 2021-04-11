#include "employe.h"
#include "employe.h"
#include "ui_employe.h"
#include "personnel.h"
#include "fonction.h"
#include <QMessageBox>

employe::employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employe)
{
    ui->setupUi(this);
    ui->tableView_employe->setModel(etmp.afficher());

      ui->tableView_fonction->setModel(ftmp.afficherFonct());

      //employe::makeplot();

}

employe::~employe()
{
    delete ui;
}

void employe::on_ajouter_fonction_clicked()
{

        int id=ui->id_fonction->text().toInt();
        int nbheure=ui->nb_heure->text().toInt();

    QString nom =ui->nom->text();
    QString diplome =ui->diplome->text();
    QString caract =ui->caract->toPlainText();


    if ((id!=0 && nbheure!=0 && nom!="" && diplome!="" && caract!="" ))
    {

    fonction f(  id , nom , caract,nbheure,diplome);
      bool test=f.ajouterFonct();
      if(test)
      {
       ui->tableView_employe->setModel(ftmp.afficherFonct());
          QMessageBox::information(nullptr,QObject::tr("ok!"),
                                   QObject::tr("fonction ajouté avec succès.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
      }
      else
          QMessageBox::information(nullptr,QObject::tr("not ok!"),
                                   QObject::tr("fonction non ajouté.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);

    }
}

void employe::on_modifier_fonction_clicked()
{
    int id=ui->text_idf->text().toInt();
int nbheure=ui->nb_heure->text().toInt();

QString nom =ui->nom->text();
QString diplome =ui->diplome->text();
QString caract =ui->text_caractf->toPlainText();


if ((id!=0  && nom!=""  && caract!="" ))
{

fonction f(  id , nom , caract,nbheure,diplome);
  bool test=f.modifierFonct(id,nom,caract);
  if(test)
  {
       ui->tableView_fonction->setModel(ftmp.afficherFonct());
      QMessageBox::information(nullptr,QObject::tr("updated!"),
                               QObject::tr("function update.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
  }
  else

      QMessageBox::information(nullptr,QObject::tr("updated!"),
                               QObject::tr("not update.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);

}

}

void employe::on_supprimer_fonction_clicked()
{
    int id=ui->idsupf->text().toInt();
int nbheure=ui->nb_heure->text().toInt();

QString nom =ui->nom->text();
QString diplome =ui->diplome->text();
QString caract =ui->caract->toPlainText();


if ((id!=0 ))
{

fonction f(  id , nom , caract,nbheure,diplome);
  bool test=f.supprimerFonct(id);
  if(test)
  {
       ui->tableView_fonction->setModel(ftmp.afficherFonct());
      QMessageBox::information(nullptr,QObject::tr("deleted!"),
                               QObject::tr("function delete.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
  }
  else

      QMessageBox::information(nullptr,QObject::tr("updated!"),
                               QObject::tr("not delete.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);

}

}

void employe::on_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    int salaire=ui->salaire->text().toInt();
    int tel=ui->tel->text().toInt();

QString nomPrenom =ui->nomPrenom->text();
QString login =ui->login->text();
QString email =ui->email->text();
QString adresse =ui->adresse->text();
QString grade =ui->grade->text();
QString cin =ui->cin->text();

if ((id!=0 && salaire!=0 && nomPrenom!="" && login!="" && email!="" && adresse!="" && grade!="" && tel!=0 && cin!="" ))
{

personnel e( nomPrenom , id , cin , adresse,tel,salaire,grade,email, login);
  bool test=e.ajouterEmpl();
  if(test)
  {
   ui->tableView_employe->setModel(etmp.afficher());
      QMessageBox::information(nullptr,QObject::tr("ok!"),
                               QObject::tr("employé ajouté avec succès.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
  }
  else
      QMessageBox::information(nullptr,QObject::tr("not ok!"),
                               QObject::tr("empoye non ajouté.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
}
}

void employe::on_modifier_clicked()
{
    int id=ui->text_id->text().toInt();
    int salaire=ui->text_salaire->text().toInt();
     QString grade=ui->text_grade->text();
     int tel=ui->tel->text().toInt();

 QString nomPrenom =ui->nomPrenom->text();
 QString login =ui->login->text();
 QString email =ui->email->text();
 QString adresse =ui->adresse->text();
 QString cin =ui->cin->text();


 if ((id!=0 && salaire!=0 && grade!=""))
 {

       personnel e( nomPrenom , id , cin , adresse,tel,salaire,grade,email, login);
     bool test=e.modifier(id,salaire,grade);
     if(test)
     {
          ui->tableView_employe->setModel(etmp.afficher());
         QMessageBox::information(nullptr,QObject::tr("updated!"),
                                  QObject::tr("employee update.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
     }
     else
     {
         QMessageBox::information(nullptr,QObject::tr("updated!"),
                                  QObject::tr("not update.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
      }
}
}

void employe::on_supprimer_employe_clicked()
{

        int id= ui->idSup->text().toInt();
        int salaire=ui->salaire->text().toInt();
         QString grade=ui->grade->text();
         int tel=ui->tel->text().toInt();

     QString nomPrenom =ui->nomPrenom->text();
     QString login =ui->login->text();
     QString email =ui->email->text();
     QString adresse =ui->adresse->text();
     QString cin =ui->cin->text();
     if((id!=0))
     {
        personnel etmp( nomPrenom , id , cin , adresse,tel,salaire,grade,email, login);
        bool test=etmp.supprimer(id);

        if(test)
        {
            ui->tableView_employe->setModel(etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok!"),
                                     QObject::tr("employee delete.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
        }

        else
            QMessageBox::information(nullptr,QObject::tr("not ok!"),
                                     QObject::tr("not delete.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);

    }



}

/*void employe::makeplot(){
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
   ui-> customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
   ui-> customPlot->xAxis->setLabel("x");
   ui-> customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
   ui-> customPlot->xAxis->setRange(-1, 1);
   ui-> customPlot->yAxis->setRange(0, 1);
   ui-> customPlot->replot();



}*/
