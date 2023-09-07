#ifndef __CAISSIER_H
#define __CAISSIER_H
#include "Client.hpp"

class Caissier
{
protected:
    /* data */
public:
    Caissier(/* args */);
    double tempsMoyenService();
    int nbClients();
    double tauxOccupation();
    bool estLibre();
    void servir(Client client);
    void attendre();
};
#endif