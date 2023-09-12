#include <algorithm>
#include <iostream>
using namespace std;
#include "Sed.hpp"
#include "Evenement.hpp"

Sed::Sed(double t0) {
    _heure = t0;
}

void Sed::ajouter(Evenement &e) {
    _evenements.push_back(&e);
    // _evenements.insert(&e);
}

void Sed::lancer() {
    while (!_evenements.empty()) {
        cout << "!_evenements.empty() : " << !_evenements.empty() << endl;

        sort(_evenements.begin(), _evenements.end(), [](const Evenement* a, const Evenement* b) {
            return a->heure() < b->heure();
        });

        cout << "Order:" << endl;

        for (const Evenement* evenement : _evenements) {
            cout << evenement->heure() << " ";
        }
        cout << endl;
        Evenement* e1 = *_evenements.begin();
        double t1 = e1->heure();
        _heure = t1;
        e1->traiter();
        _evenements.erase(_evenements.begin());
        delete e1;
    }
}

double Sed::heure() {
    return _heure;
}