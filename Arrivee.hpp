#ifndef __ARRIVEE_H
#define __ARRIVEE_H
#include "Evenement.hpp"
class Arrivee: public Evenement
{
protected:
    
public:
    Arrivee(double heure);
    void traiter();
};
#endif