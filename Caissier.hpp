#ifndef __CAISSIER_H
#define __CAISSIER_H
#include "Client.hpp"

class Banque;
class Caissier
{
protected:
    Banque *_banque;
    double _tempsMoyenService;
    int _nbClients;
    double _tempsServiceTotal;
    bool _estLibre;
public:
    Caissier(Banque *banque, double tempsMoyenService);
    double tempsMoyenService();
    int nbClients();
    double tauxOccupation();
    bool estLibre();
    void servir(Client client);
    void attendre();
};
#endif