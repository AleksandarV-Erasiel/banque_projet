#ifndef __DEPART_H
#define __DEPART_H
#include "Caissier.hpp"
#include "Client.hpp"
class Depart
{
protected:
    Caissier _caissier;
    Client _client;
public:
    Depart(double heure, Caissier caissier, Client client);
    void traiter();
};
#endif