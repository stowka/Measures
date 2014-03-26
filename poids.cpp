#include "poids.h"
#include <iostream>

Poids::Poids()
{
}

Poids::Poids(int valeur, int echelle) : Unite(valeur, echelle) {

}

QString Poids::toString() {
    std::cout << "Poids::toString\n";
    return Unite::toString() + "g";
}
