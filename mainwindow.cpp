#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "articles.h"
#include "modifier.h"
#include "modifier2.h"
#include <QDebug>
#include <iostream>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QApplication>
#include <QSqlQuery>
#include <QtWidgets>
#include<QtPrintSupport/QPrinter>
#include <QSystemTrayIcon>

#include<QPdfWriter>

#include <QPainter>

#include<QFileDialog>

#include<QTextDocument>

#include <QTextEdit>

#include <QtSql/QSqlQueryModel>

#include<QtPrintSupport/QPrinter>

#include <QVector2D>

#include <QVector>

#include <QSqlQuery>

#include<QDesktopServices>

#include <QMessageBox>

#include<QUrl>

#include <QPixmap>

#include <QTabWidget>

#include <QValidator>

#include <QPrintDialog>

#include<QtSql/QSqlQuery>

#include<QVariant>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Tab_Article->setModel(af.afficher(get_a()));
    ui->Tab_Emissions->setModel(ef.afficher(get_e()));
      ui->Tab_historique->setModel(afficher_historique());




    connect(ui->pushButton_20, SIGNAL(clicked()),this, SLOT(sendMail2()));
    connect(ui->pushButton_13, SIGNAL(clicked()),this, SLOT(sendMail()));
    //connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(browse()));
    connect(ui->pushButton_21, SIGNAL(clicked()), this, SLOT(browse2()));


}
QSqlQueryModel* MainWindow::afficher_historique()
{
    QSqlQueryModel* model_historique = new QSqlQueryModel();
     model_historique->setQuery("SELECT* FROM HISTORIQUE");
     model_historique->setHeaderData(0, Qt::Horizontal , QObject::tr("Type de l'operation"));
     model_historique->setHeaderData(1, Qt::Horizontal , QObject::tr("Entité"));
     model_historique->setHeaderData(2, Qt::Horizontal , QObject::tr("Date de l'operation"));
     model_historique->setHeaderData(3, Qt::Horizontal , QObject::tr("Heure de l'operation"));
     return model_historique;
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::get_a(){return a;}
void MainWindow::set_a(int n){a = n;}
int MainWindow::get_e(){return e;}
void MainWindow::set_e(int n){e = n;}



void MainWindow::on_pushButton_2_clicked()
{
    Articles a;



    a.set_nom_auteur(ui->lineEdit_auteur->text());
    a.set_nom_article(ui->lineEdit_narticle->text());
    a.set_id(ui->lineEdit_id->text());
    a.set_type(ui->lineEdit_type->text());
    a.ajouter();


    ui->lineEdit_auteur->setText("");
    ui->lineEdit_narticle->setText("");
    ui->lineEdit_id->setText("");
    ui->lineEdit_type->setText("");
     ui->Tab_Article->setModel(af.afficher(get_a()));
     ui->Tab_historique->setModel(afficher_historique());



}


void MainWindow::on_pushButton_clicked()
{
    Articles A1;A1.set_id(ui->lineEdit_idS->text());
    A1.supprimer(A1.get_id());
    ui->Tab_Article->setModel(af.afficher(get_a()));
    ui->Tab_historique->setModel(afficher_historique());


}

void MainWindow::on_pushButton_3_clicked()
{
    QString id = ui->lineEdit_idS->text();
    bool ba;
  modifier m;
 ba = m.check_id(id);
 if(ba)
 {

 m.setModal(true);
 m.exec();
 ui->Tab_historique->setModel(afficher_historique());
 ui->Tab_Article->setModel(af.afficher(get_a()));
 ui->Tab_Emissions->setModel(ef.afficher(get_e()));

 }

}

void MainWindow::on_pushButton_5_clicked()
{
    emissions a;


    QString ageS="",tr="";
    a.set_nom_emision(ui->lineEdit_nome->text());
    a.set_nom_presentateur(ui->lineEdit_nomp->text());
    a.set_id(ui->lineEdit_idE->text());
    a.ajouter();
    //ageS = ui->lineEdit_4->text();
    //a.setage(ageS.toInt());


    ui->lineEdit_nome->setText("");
    ui->lineEdit_nomp->setText("");
    ui->lineEdit_idE->setText("");
     ui->Tab_Emissions->setModel(ef.afficher(get_e()));
     ui->Tab_historique->setModel(afficher_historique());


}

void MainWindow::on_pushButton_4_clicked()
{
    emissions E1;E1.set_id(ui->lineEdit_idSE->text());
    E1.supprimer(E1.get_id());
    ui->Tab_Emissions->setModel(ef.afficher(get_e()));
    ui->Tab_historique->setModel(afficher_historique());
}

void MainWindow::on_pushButton_6_clicked()
{
    QString id = ui->lineEdit_idSE->text();
    bool ba;
  modifier2 m;
 ba = m.check_id(id);
 if(ba)
 {

     m.setModal(true);
     m.exec();
     ui->Tab_historique->setModel(afficher_historique());
     ui->Tab_Emissions->setModel(ef.afficher(get_e()));


 }
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->Tab_Article->setModel(af.afficher(get_a()));
    ui->Tab_Emissions->setModel(ef.afficher(get_e()));
}

void MainWindow::on_pushButton_8_clicked()
{
set_e(0);
ui->Tab_Article->setModel(af.afficher(get_a()));
ui->Tab_Emissions->setModel(ef.afficher(get_e()));
}

void MainWindow::on_pushButton_10_clicked()
{
    set_a(0);
    ui->Tab_Article->setModel(af.afficher(get_a()));
    ui->Tab_Emissions->setModel(ef.afficher(get_e()));
}

void MainWindow::on_pushButton_11_clicked()
{
    set_a(1);
    ui->Tab_Article->setModel(af.afficher(get_a()));
    ui->Tab_Emissions->setModel(ef.afficher(get_e()));
}

void MainWindow::on_pushButton_12_clicked()
{
    set_e(1);
    ui->Tab_Article->setModel(af.afficher(get_a()));
    ui->Tab_Emissions->setModel(ef.afficher(get_e()));
}
void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->lineEdit_type_3->setText( fileListString );

}
void MainWindow::browse2()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->lineEdit_type_8->setText( fileListString );
}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("sofiene.fenniche1@gmail.com", "besbes13", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("sofiene.fenniche1@gmail.com", ui->lineEdit_type_2->text() ,"QT TEST ","L'envoye d'un mail ", files );
    else
        smtp->sendMail("sofiene.fenniche1@gmail.com",ui->lineEdit_type_2->text(), "QT TEST","eaeara");
}
void MainWindow::sendMail2()
{
    Smtp* smtp = new Smtp("sofiene.fenniche1@gmail.com", "besbes13", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("sofiene.fenniche1@gmail.com", ui->lineEdit_type_9->text() ,"QT TEST ","L'envoye d'un mail ", files );
    else
        smtp->sendMail("sofiene.fenniche1@gmail.com",ui->lineEdit_type_9->text(), "QT TEST","eaeara");
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void MainWindow::on_pushButton_13_clicked()
{

}

void MainWindow::on_pushButton_14_clicked()
{
    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->Tab_Article->model()->rowCount();
                        const int columnCount = ui->Tab_Article->model()->columnCount();


                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                           //     "<align='right'> " << datefich << "</align>"
                            "<center> <H1>Liste des articles </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->Tab_Article->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->Tab_Article->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->Tab_Article->isColumnHidden(column)) {
                                    QString data = ui->Tab_Article->model()->data(ui->Tab_Article->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_15_clicked()
{

}

void MainWindow::on_pushButton_22_clicked()
{
    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->Tab_Emissions->model()->rowCount();
                        const int columnCount = ui->Tab_Emissions->model()->columnCount();


                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                           //     "<align='right'> " << datefich << "</align>"
                            "<center> <H1>Liste des emissions </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->Tab_Emissions->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->Tab_Emissions->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->Tab_Emissions->isColumnHidden(column)) {
                                    QString data = ui->Tab_Emissions->model()->data(ui->Tab_Emissions->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_21_clicked()
{

}

void MainWindow::on_lineEdit_auteur_2_textChanged(const QString &arg1)
{

}

void MainWindow::on_pushButton_9_clicked()
{
    ui->Tab_Article->setModel(af.afficher(get_a()));
    ui->Tab_Emissions->setModel(ef.afficher(get_e()));
    ui->Tab_historique->setModel(afficher_historique());
}

void MainWindow::on_pushButton_16_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Voulez vous vraiment faire une réinisialisation de l'hitorique , les données seront perdus");
    //msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Yes)
    {

        msgBox.setText("Voulez-vous sauvegarder l'historique dans un fichier pdf avant le reset ? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int sav = msgBox.exec();
        if(sav == QMessageBox::Yes)
        {
            QString strStream;
                                QTextStream out(&strStream);

                                const int rowCount = ui->Tab_historique->model()->rowCount();
                                const int columnCount = ui->Tab_historique->model()->columnCount();


                                out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("strTitle")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"

                                   //     "<align='right'> " << datefich << "</align>"
                                    "<center> <H1>Historique des operation </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                // headers
                                out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->Tab_historique->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->Tab_historique->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";

                                // data table
                                for (int row = 0; row < rowCount; row++) {
                                    out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                    for (int column = 0; column < columnCount; column++) {
                                        if (!ui->Tab_historique->isColumnHidden(column)) {
                                            QString data = ui->Tab_historique->model()->data(ui->Tab_historique->model()->index(row, column)).toString().simplified();
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

        QSqlQuery requete;
        requete.exec("DELETE FROM HISTORIQUE;");
        QMessageBox::information(nullptr,QObject::tr("Reset") , QObject::tr("Reset effectué avec succés"),QMessageBox::Ok );
        ui->Tab_historique->setModel(afficher_historique());

    }
}

void MainWindow::on_pushButton_17_clicked()
{
    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->Tab_historique->model()->rowCount();
                        const int columnCount = ui->Tab_historique->model()->columnCount();


                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                           //     "<align='right'> " << datefich << "</align>"
                            "<center> <H1>Historique des operation </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->Tab_historique->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->Tab_historique->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->Tab_historique->isColumnHidden(column)) {
                                    QString data = ui->Tab_historique->model()->data(ui->Tab_historique->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_lineEdit_type_2_cursorPositionChanged(int arg1, int arg2)
{

}
