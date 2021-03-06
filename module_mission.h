#ifndef MODULE_MISSION_H
#define MODULE_MISSION_H

#include <QDialog>
#include "journaliste.h"
#include "mission.h"

namespace Ui {
class module_mission;
}

class module_mission : public QDialog
{
    Q_OBJECT

public:
    explicit module_mission(QWidget *parent = nullptr);
    ~module_mission();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();
    bool verifID();
    bool verifNOM();
     bool verifID1();
     bool verifNOM1();
     bool verifPRENOM();
     bool verifSPECIALITE();
     bool verifNUM();

private:
    Ui::module_mission *ui;
    journaliste tmpjournaliste;
    mission tmpmission;
    journalisteh tmph;
};

#endif // MODULE_MISSION_H
