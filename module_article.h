#ifndef MODULE_ARTICLE_H
#define MODULE_ARTICLE_H

#include <QDialog>
#include "articles.h"
#include "emissions.h"
#include "smtp.h"
//#include "menu.h"
#include <QFileDialog>

namespace Ui {
class module_article;
}

class module_article : public QDialog
{
    Q_OBJECT

public:
    explicit module_article(QWidget *parent = nullptr);
    int get_a();
    int get_e();
    void set_a(int n);
    void set_e(int n);
    void actualiser_tab();
    bool check_id(QString id);
    bool check_idE(QString id);
    ~module_article();
private slots:
    void sendMail();
    QSqlQueryModel* afficher_historique();
    void sendMail2();
    void mailSent(QString);
    void browse();
    void browse2();
    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::module_article *ui;
    //menu menu;
    int a,e;
   Articles af;
   emissions ef;
   QStringList files;
};

#endif // MODULE_ARTICLE_H
