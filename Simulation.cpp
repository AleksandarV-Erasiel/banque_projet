#include <iostream>
using namespace std;
#include "Banque.hpp"

int main() {
    cout << "Simulation lancee" << endl;
    int nbCaissiers = 3;
    int clientsTotaux = 0;
    double *caissiers = new double[nbCaissiers];
    caissiers[0] = 10.0;
    caissiers[1] = 12.0;
    caissiers[2] = 15.0;
    Banque *banque = new Banque(0, 60.0, nbCaissiers, caissiers , 3.0);
    banque->lancer();
    //afficher resultats
    cout << "Duree reelle: " << banque->dureeReelle() << endl;
    cout << "Longueur max file: " << banque->fileAttente()->longueurMoyenne() << endl;
    cout << "Longueur max file: " << banque->fileAttente()->longueurMax() << endl;
    cout << "Nombre de clients servis: " << banque->nbClients() << endl;
    cout << "Temps d'attente moyen: " << banque->fileAttente()->tempsMoyenAttente() << endl;
    double** tauxOccupation = banque->tauxOccupationParCaissier();

    for (int i = 0; i < nbCaissiers; i++) { cout << "Taux d'occupation du caissier " << i << ": " << *tauxOccupation[i] << endl; }
    for (int i = 0; i < nbCaissiers; ++i) { delete tauxOccupation[i]; }
    delete[] tauxOccupation;

    delete banque;
    delete [] caissiers;
    return 0;
}