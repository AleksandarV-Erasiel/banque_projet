#include <algorithm>
#include <iostream>
using namespace std;
#include "Sed.hpp"
#include "Evenement.hpp"
#include "Arrivee.hpp"
#include "Depart.hpp"

Sed::Sed(double t0) {
    _heure = t0;
}

void Sed::ajouter(Evenement &e) {
    _evenements.push_back(&e);

    sort(_evenements.begin(), _evenements.end(), [](const Evenement* a, const Evenement* b) {
        return a->heure() < b->heure();
    });
}

void Sed::lancer() {
    while (!_evenements.empty()) {
        // TODO: remove all of these Banque, FA,... used for debug
        cout << "Echeancier:" << endl;
        for (const Evenement* evenement : _evenements) {
            cout << evenement->heure();
            
            const Arrivee* arrivee = dynamic_cast<const Arrivee*>(evenement);
            const Depart* depart = dynamic_cast<const Depart*>(evenement);
            
            if (arrivee) {
                cout << "(A) ";
            } else if (depart) {
                cout << "(D) ";
            }
        }
        cout << endl << endl;

        Evenement* e1 = *_evenements.begin();
        double t1 = e1->heure();
        _heure = t1;
        e1->traiter();
        // TODO: maybe seg fault from here ? :thinking:
        _evenements.erase(_evenements.begin());
        delete e1;

        cout << endl << "==================================================================================================================" << endl;
    }
}

double Sed::heure() {
    return _heure;
}