#ifndef LONGUEUR_H
#define LONGUEUR_H

#include <unite.h>

class Longueur : public Unite
{
public:
    Longueur();
    Longueur(int valeur, int echelle);
    QString toString();
};

#endif // LONGUEUR_H
