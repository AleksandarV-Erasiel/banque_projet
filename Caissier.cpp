#include <random>
#include "Caissier.hpp"
#include "Banque.hpp"
#include "FileAttente.hpp"
#include "Depart.hpp"

Caissier::Caissier(Banque *banque, double tempsMoyenService) {
    _banque = banque;
    _tempsMoyenService = tempsMoyenService;
    _tempsServiceTotal = 0;
    _nbClients = 0;
    _estLibre = true;
}

double Caissier::tempsMoyenService() {
    return _tempsMoyenService;
}

int Caissier::nbClients() {
    return _nbClients;
}

double Caissier::tauxOccupation() {
    return _tempsMoyenService / _banque->dureeReelle();
}

bool Caissier::estLibre() {
    return _estLibre;
}

void Caissier::servir(Client &client) {
    double ecartTypePercentage = 10;
    double ecartType = (_tempsMoyenService/100) * ecartTypePercentage;
    random_device rd;
    mt19937 generator(rd());
    normal_distribution<double> distribution(_tempsMoyenService, ecartType);
    double tempsService = distribution(generator);

    _nbClients++;
    _estLibre = false;
    _tempsServiceTotal += tempsService;

    Depart *depart = new Depart(_banque, _banque->heure() + tempsService, *this, client);
    _banque->ajouter(*depart);
}

void Caissier::attendre() {
    _estLibre = true;
}
