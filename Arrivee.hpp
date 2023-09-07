#ifndef __ARRIVEE_H
#define __ARRIVEE_H
#include "Evenement.hpp"
#include "Banque.hpp"
class Arrivee: public Evenement
{
public:
    Arrivee(Banque *sed, double heure);
    void traiter();
};
#endif