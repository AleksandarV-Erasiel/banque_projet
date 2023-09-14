#include <iostream>
using namespace std;
#include "Sed.hpp"
#include "Depart.hpp"
#include "FileAttente.hpp"

Depart::Depart(Banque *sed, double heure, Caissier &caissier, Client &client) : Evenement(sed, heure) {
    _caissier = &caissier;
    _client = &client;
}

void Depart::traiter() {
    delete _client;
    Banque* banque = (Banque*) _sed;
    banque->fileAttente()->afficherListeClients();
    if (banque->fileAttente()->estVide()) {
        cout << "FileAttente vide - Attendre" << endl;
        _caissier->attendre();
    } else {
        cout << "FileAttente non vide - Prendre client" << endl;
        banque->fileAttente()->afficherListeClients();
        Client &c = banque->fileAttente()->retirer();
        banque->fileAttente()->afficherListeClients();
        _caissier->servir(c);
    }
}