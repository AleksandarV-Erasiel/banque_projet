#include <iostream>
#include <random>
using namespace std;
#include "Sed.hpp"
#include "Arrivee.hpp"
#include "Client.hpp"
#include "Caissier.hpp"
#include "FileAttente.hpp"

Arrivee::Arrivee(Banque *sed, double heure): Evenement(sed, heure) {
}

void Arrivee::traiter() {
    Banque* banque = (Banque*) _sed;
    Client *c = new Client(_heure);
    Caissier *cs = banque->unCaissierLibre();

    cout << "banque->heure() " << banque->heure() << endl;

    if (cs != NULL && banque->fileAttente()->estVide() && banque->heure() >= cs->dureeOccupee()) {
        cs->servir(*c);
        cout << "Client servi immediatement servi" << endl;
    } else {
        cout << "banque->heure() " << banque->heure() << endl;
        banque->fileAttente()->afficherListeClients();
        banque->fileAttente()->ajouter(*c);
        cout << "banque->heure() " << banque->heure() << endl;
        cout << "Client ajoute a la file d'attente" << endl;
        banque->fileAttente()->afficherListeClients();
    }

    cout << "banque->heure() " << banque->heure() << endl;

    cout << "banque->fileAttente->estVide() "<< banque->fileAttente()->estVide() << endl;

    double ecartTypePercentage = 1;
    double ecartType = (banque->tempsEntreArrivees()/100) * ecartTypePercentage;
    random_device rd;
    mt19937 generator(rd());
    normal_distribution<double> distribution(banque->tempsEntreArrivees(), ecartType);
    double hpa = distribution(generator);

    cout << "banque->heure() " << banque->heure() << endl;
    cout << "hpa " << hpa << endl;
    cout << "banque->dureePrevue() " << banque->dureePrevue() << endl;

    cout << "banque->heure() + hpa <= banque->dureePrevue() " << banque->heure() + hpa << " <= " << banque->dureePrevue() << endl;
    if (banque->heure() + hpa <= banque->dureePrevue()) {
        Arrivee *a = new Arrivee(banque, banque->heure() + hpa);
        banque->ajouter(*a);
    }
    banque->fileAttente()->afficherListeClients();
}