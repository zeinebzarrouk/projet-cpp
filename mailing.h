#ifndef MAILING_H
#define MAILING_H
#

#include <QDialog>

namespace Ui {
class mailing;
}

class mailing : public QDialog
{
    Q_OBJECT

public:
    explicit mailing(QWidget *parent = nullptr);
    ~mailing();

private slots:

    void sendMail();
    void mailSent(QString);
private:
    Ui::mailing *ui;

};

#endif // MAILING_H
