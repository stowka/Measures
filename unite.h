#ifndef UNITE_H
#define UNITE_H

#include <QString>

class Unite
{
public:
    Unite();
    Unite(int valeur, int echelle);
    QString toString();
    int getValeur();
    void setValeur(int valeur);
    int getEchelle();
    void setEchelle(int echelle);

protected:
    int valeur;
    int echelle;
};

#endif // UNITE_H
