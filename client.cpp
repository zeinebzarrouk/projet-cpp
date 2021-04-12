#include "client.h"

client::client()
{

}
QString client::get_cin(){return cin;}
QString client::get_prenom(){ return prenom;}
QString client::get_nom() {return nom;}
int client::get_age(){return age;}


void client::setcin(QString n) {cin = n;}
void client::setprenom(QString n) {prenom = n;}
void client::setnom(QString n) {nom = n;}
void client::setage(int n){age = n;}


