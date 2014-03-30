#include "temps.h"

Temps::Temps()
{
}

Temps::Temps(int valeur, int echelle) : Unite(valeur, echelle) {

}

QString Temps::toString() {
    QString e = "";
    switch (this->echelle) {
    case -3:
        e = "msec";
        break;
    case -2:
        e = "ccsec";
        break;
    case -1:
        e = "dsec";
        break;
    case 0:
        e = "sec";
        break;
    case 1:
        e = "min";
        break;
    case 2:
        e = "h";
        break;
    case 3:
        e = "j";
        break;
    default:
        break;
    }
    return QString::number(this->valeur) + " " + e;
}
