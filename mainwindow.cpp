#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mission.h"
#include "journaliste.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabjournaliste->setModel(tmpjournaliste.afficher());
    ui->tabmission->setModel(tmpmission.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ajout journaliste
void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString adresse= ui->lineEdit_adresse->text();
    QString specialite= ui->lineEdit_prenom_2->text();
    int num = ui->lineEdit_num->text().toInt();



  journaliste e(id,nom,prenom,adresse,specialite,num);
  bool test=e.ajouter();
  if(test)
{

      ui->tabjournaliste->setModel(tmpjournaliste.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un journaliste"),
                  QObject::tr("journaliste ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un journaliste"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}





//supprimer journaliste
void MainWindow::on_pushButton_4_clicked()
{
    int id = ui->lineEdit_id_5->text().toInt();
    bool test=tmpjournaliste.supprimer(id);
    if(test)
    {ui->tabjournaliste->setModel(tmpjournaliste.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un journaliste"),
                    QObject::tr("journaliste supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Partenaire"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

//recherche journa
void MainWindow::on_pushButton_9_clicked()
{
    int id;

           id=ui->lineEdit_2->text().toInt();
       bool test= true;
       if(test==(true))
       {
          ui->tabjournaliste->setModel(tmpjournaliste.rechercher(id));
   }
}

//modif journa
void MainWindow::on_pushButton_3_clicked()
{
       int id= ui->lineEdit_nom_2->text().toInt();
       QString adresse=ui->lineEdit_nom_5->text();
       int num=ui->lineEdit_nom_4->text().toInt();


               bool test=tmpjournaliste. modifier(id,adresse,num);
                  if (test)
                  {ui->tabjournaliste->setModel(tmpjournaliste.afficher());//refresh
                      QMessageBox::information(nullptr, QObject::tr("Modifier un patient"),
                                  QObject::tr("patient modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                  }
                  else
                      QMessageBox::critical(nullptr, QObject::tr("Modifier un patient"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);






}


void MainWindow::on_pushButton_10_clicked()
{
    ui->tabjournaliste->setModel( tmpjournaliste.afficher_tri());
   // ui->tabjournaliste->setModel( tmpjournaliste.afficher_tri());


}


























//ajout journa

void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_id1->text().toInt();
    QString nom= ui->lineEdit_type->text();
    QString type= ui->lineEdit_nom_3->text();
    QString localisation= ui->lineEdit_nom_6->text();




  mission e(id,nom,type,localisation);
  bool test=e.ajouter();
  if(test)
{

      ui->tabmission->setModel(tmpmission.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un miss"),
                  QObject::tr("journaliste ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un miss"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_7_clicked()
{
    int id = ui->lineEdit_5->text().toInt();
    bool test=tmpmission.supprimer(id);
    if(test)
    {ui->tabmission->setModel(tmpmission.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un miss"),
                    QObject::tr("journaliste supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un miss"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_6_clicked()
{
    int id= ui->lineEdit_4->text().toInt();
    QString type=ui->lineEdit->text();
    QString localisation=ui->lineEdit_3->text();


            bool test=tmpmission. modifier(id,type,localisation);
               if (test)
               {ui->tabmission->setModel(tmpmission.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier un mission"),
                               QObject::tr("mission modifié.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Modifier un mission"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);






}


void MainWindow::on_pushButton_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabmission->model()->rowCount();
        const int columnCount = ui->tabmission->model()->columnCount();

        out <<  "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"

               //     "<align='right'> " << datefich << "</align>"
               "<center> <H1>GESTION MISSION </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabmission->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabmission->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabmission->isColumnHidden(column)) {
                    QString data = ui->tabmission->model()->data(ui->tabmission->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
               "</body>\n"
               "</html>\n";

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer (QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}
