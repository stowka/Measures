#ifndef TEMPS_H
#define TEMPS_H

#include <unite.h>

class Temps : public Unite
{
public:
    Temps();
    Temps(int valeur, int echelle);
    QString toString();
};

#endif // TEMPS_H
