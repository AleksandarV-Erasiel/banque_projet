#ifndef __DEPART_H
#define __DEPART_H
#include "Caissier.hpp"
#include "Client.hpp"
#include "Evenement.hpp"
#include "Banque.hpp"
class Depart: public Evenement
{
protected:
    Caissier *_caissier;
    Client *_client;
public:
    Depart(Banque *sed, double heure, Caissier &caissier, Client &client);
    void traiter();
};
#endif