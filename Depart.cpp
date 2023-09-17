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
    Banque* banque = (Banque*) _sed;
    cout << "test1" << endl;
    cout << _client->heureArrivee() << endl;
    cout << "test2" << endl;
    if (banque->fileAttente()->estVide()) {
        cout << "File Attente vide - Caissier Attendre" << endl;
        _caissier->attendre();
    } else {
        cout << "File Attente non vide - Servir Client" << endl;
        Client &c = banque->fileAttente()->retirer();
        _caissier->servir(c);
    }
}