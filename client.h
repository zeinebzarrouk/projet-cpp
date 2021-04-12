#ifndef CLIENT_H
#define CLIENT_H
#include <QString>


class client
{
public:
    void setcin(QString n);
    void setprenom(QString n);
    void setnom(QString n);
    void setage(int n);
    QString get_cin();
    QString get_prenom();
    QString get_nom();
    int get_age();
    client();

private:
    QString cin,prenom,nom;
    int age;
};

#endif // CLIENT_H
