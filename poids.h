#ifndef POIDS_H
#define POIDS_H

#include <unite.h>

class Poids : public Unite
{
public:
    Poids();
    Poids(int valeur, int echelle);
    QString toString();
};

#endif // POIDS_H
