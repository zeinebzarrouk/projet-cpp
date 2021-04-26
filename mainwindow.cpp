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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Tab_Article->setModel(af.afficher(get_a()));
    ui->Tab_Emissions->setModel(ef.afficher(get_e()));

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


    QString ageS="",tr="";
    a.set_nom_auteur(ui->lineEdit_auteur->text());
    a.set_nom_article(ui->lineEdit_narticle->text());
    a.set_id(ui->lineEdit_id->text());
    a.set_type(ui->lineEdit_type->text());
    a.ajouter();
    //ageS = ui->lineEdit_4->text();
    //a.setage(ageS.toInt());


    ui->lineEdit_auteur->setText("");
    ui->lineEdit_narticle->setText("");
    ui->lineEdit_id->setText("");
    ui->lineEdit_type->setText("");
     ui->Tab_Article->setModel(af.afficher(get_a()));



}


void MainWindow::on_pushButton_clicked()
{
    Articles A1;A1.set_id(ui->lineEdit_idS->text());
    A1.supprimer(A1.get_id());
    ui->Tab_Article->setModel(af.afficher(get_a()));


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


}

void MainWindow::on_pushButton_4_clicked()
{
    emissions E1;E1.set_id(ui->lineEdit_idSE->text());
    E1.supprimer(E1.get_id());
    ui->Tab_Emissions->setModel(ef.afficher(get_e()));
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
