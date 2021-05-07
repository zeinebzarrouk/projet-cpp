#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"

#include <QMainWindow>
#include "publicite.h"
#include "connection.h"
#include <QString>
#include "QMediaPlaylist"
#include <QMediaPlayer>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrinterInfo>
#include "smtp.h"
//#include <QSound>
//#include "notification.h"
#include "publicite.h"
#include "promotion.h"
#include "notification.h"
//#include "notification1.h"
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>

#include <QTimer>
QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_pb_ajouter_mortadha_clicked();




    QString ConvertirTime();
    void on_Publicite_affichage_activated(const QModelIndex &index);






    void on_Promotion_affichage_activated(const QModelIndex &index);

    void on_pb_ajouter_clicked();

    void refresh_mortadha();



    void on_recherche_Publicite_textChanged();



    void on_tri_croissant_publicite_clicked();

    void on_tri_deccroissant_publicite_clicked();



    void on_stat_publicite_clicked();

    void on_pdf_publicite_clicked();

 //   void on_send_mail_mortadha_clicked();
    //void mailSent_mortadha(QString ); mortadha
    void on_stat_publicite_2_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();


    void on_stat_promotion_2_clicked();

   // void on_pb_ajouter_pr_mortadha_2_clicked();
    void on_pb_ajouter_mortadha_2_clicked();

    void on_pb_ajouter_mortadha_3_clicked();

    void on_supprimer23_clicked();

    void on_modifier_2_clicked();


private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_24_clicked();

    void on_modifier_promo_clicked();

    void on_supprimer_promo_clicked();

    void on_tri_croissant_promo_clicked();

    void on_tri_decroissant_promo_clicked();


    void on_promo_recherche_returnPressed();

    void on_radioButton_10_clicked();

    void on_pub_ajouter_clicked();

    void on_pub_modifier_clicked();

    void on_pub_supprimer_clicked();

    void on_tri_croissant_publicite_2_clicked();

    void on_tri_deccroissant_publicite_2_clicked();

    void on_recherche_Publicite_2_returnPressed();

    void on_pdf_publicite_2_clicked();





    void on_send_clicked();

    void on_excel_clicked();

private:
    Ui::MainWindow *ui;
    Smtp* smtp;
    QString msg;
    QString mail;
    Publicite tmp_publicite;
    Promotion tmp_promotion;
     Notification N ;
    QMediaPlayer *musicAdd =new QMediaPlayer();
};

#endif // MAINWINDOW_H
