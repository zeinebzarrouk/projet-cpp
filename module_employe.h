#ifndef MODULE_EMPLOYE_H
#define MODULE_EMPLOYE_H

#include "personnel.h"
#include "fonction.h"
#include <QDialog>


#include <QWidget>

namespace Ui {
class employe;
}

class employe : public QDialog
{
    Q_OBJECT

public:
    bool verifNOM_PRENOM();
    bool verifID();
    bool verifEMAIL();
     bool verifCIN();
      bool verifADRESSE();
       bool verifTEL();

    explicit employe(QWidget *parent = nullptr);
    ~employe();

private slots:
    void on_ajouter_fonction_clicked();

    void on_modifier_fonction_clicked();

    void on_supprimer_fonction_clicked();

    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_employe_clicked();

    //void makeplot();
    void on_tri_id_clicked();

    void on_tri_grade_clicked();

    void on_tri_nom_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    //void on_pushButton_clicked();

     void StatsPerso();
     void on_mailing_list_clicked();

     void on_imprimer_clicked();

private:
    Ui::employe *ui;
    personnel etmp;
      fonction ftmp;


};

#endif // MODULE_EMPLOYE_H
