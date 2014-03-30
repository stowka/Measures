#include <QString>
#include <iostream>
#include "unite.h"

Unite::Unite(int valeur, int echelle)
{
    this->valeur = valeur;
    this->echelle = echelle;
}

Unite::Unite()
{
    this->valeur = 0;
    this->echelle = 0;
}

int Unite::getValeur() {
    return this->valeur;
}

int Unite::getEchelle() {
    return this->echelle;
}

void Unite::setValeur(int valeur) {
    this->valeur = valeur;
}

void Unite::setEchelle(int echelle) {
    if (echelle > 3 || echelle < -3)
        this->echelle = 0;
    else
        this->echelle = echelle;
}

QString Unite::toString() {
    QString e = "";
    switch (this->echelle) {
    case -3:
        e = "m";
        break;
    case -2:
        e = "c";
        break;
    case -1:
        e = "d";
        break;
    case 1:
        e = "da";
        break;
    case 2:
        e = "h";
        break;
    case 3:
        e = "k";
        break;
    default:
        break;
    }
    return QString::number(this->valeur) + " " + e;
}
