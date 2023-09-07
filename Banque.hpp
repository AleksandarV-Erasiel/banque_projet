#ifndef __BANQUE_H
#define __BANQUE_H
#include "Caissier.hpp"

class Banque
{
protected:
    /* data */
public:
    Banque(/* args */);
    ~Banque();
    double dureePrevue();
    int nbCaissiers();
    double tempsEntreArrivees();
    double dureeReelle();
    int nbClients();
    Caissier unCaissierLibre();
};
#endif