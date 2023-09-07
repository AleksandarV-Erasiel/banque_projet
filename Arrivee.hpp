#ifndef __ARRIVEE_H
#define __ARRIVEE_H
#include "Evenement.hpp"
class Arrivee: public Evenement
{
protected:
    
public:
    Arrivee(Sed *sed, double heure);
    void traiter();
};
#endif