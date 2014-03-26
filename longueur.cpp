#include "longueur.h"

Longueur::Longueur() : Unite()
{
}

Longueur::Longueur(int valeur, int echelle) : Unite(valeur, echelle) {

}

QString Longueur::toString() {
    return Unite::toString() + "m";
}
