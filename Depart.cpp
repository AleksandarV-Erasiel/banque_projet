#include <iostream>
using namespace std;
#include "Sed.hpp"
#include "Depart.hpp"
#include "FileAttente.hpp"

Depart::Depart(Banque *sed, double heure, Caissier &caissier, Client &client) : Evenement(sed, heure) {
}

void Depart::traiter() {
    delete &_client;
    Banque* banque = (Banque*) _sed;
    if (banque->fileAttente()->estVide()) {
        _caissier.attendre();
    } else {
        Client &c = banque->fileAttente()->retirer();
        _caissier.servir(c);
    }
}