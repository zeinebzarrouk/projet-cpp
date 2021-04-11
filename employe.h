#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "personnel.h"
#include "fonction.h"
#include <QDialog>
#include <QDialog>

namespace Ui {
class employe;
}

class employe : public QDialog
{
    Q_OBJECT

public:
    explicit employe(QWidget *parent = nullptr);
    ~employe();

private slots:
    void on_ajouter_fonction_clicked();

    void on_modifier_fonction_clicked();

    void on_supprimer_fonction_clicked();

    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_employe_clicked();

    void makeplot();
private:
    Ui::employe *ui;
    personnel etmp;
      fonction ftmp;
};

#endif // EMPLOYE_H
