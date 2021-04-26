#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "articles.h"
#include "emissions.h"
#include "smtp.h"
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    int get_a();
    int get_e();
    void set_a(int n);
    void set_e(int n);
    void actualiser_tab();

    //QString get_id();
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

        void sendMail();
        QSqlQueryModel* afficher_historique();
        void sendMail2();
        void mailSent(QString);
        void browse();
        void browse2();

        void on_pushButton_14_clicked();

        void on_pushButton_15_clicked();

        void on_pushButton_22_clicked();

        void on_pushButton_21_clicked();

        void on_lineEdit_auteur_2_textChanged(const QString &arg1);

        void on_pushButton_9_clicked();

        void on_pushButton_16_clicked();

        void on_pushButton_17_clicked();

        void on_lineEdit_type_2_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    int a,e;
   Articles af;
   emissions ef;
   QStringList files;

};
#endif // MAINWINDOW_H
