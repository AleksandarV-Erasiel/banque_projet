#include <iostream>
#include <fstream>

using namespace std;
#include "Banque.hpp"

int main(int argc, char* argv[]) {

    if (argc == 1) {
        cout << "ERREUR: Veuillez renseigner le fichier de configuration." << endl;
        return -1;
    }
    char* configFilePath = argv[1];

    ifstream configFile(configFilePath);

    if(configFile) {
        double t0, dureePrevue, tempsEntreArrivees;
        int nbCaissiers;
        double *caissiers = new double[nbCaissiers];

        configFile >> t0;
        if (configFile.tellg() < 0) {
            cout << "ERREUR: Le fichier de configuration n'est pas valide." << endl;
            exit(-1);
        }
        configFile >> dureePrevue;
        if (configFile.tellg() < 0) {
            cout << "ERREUR: Le fichier de configuration n'est pas valide." << endl;
            exit(-1);
        }
        configFile >> tempsEntreArrivees;
        if (configFile.tellg() < 0) {
            cout << "ERREUR: Le fichier de configuration n'est pas valide." << endl;
            exit(-1);
        }
        configFile >> nbCaissiers;
        double dureeTraitementCaissier;
        for (int i = 0; i < nbCaissiers; i++) {
            if (configFile.tellg() < 0) {
                cout << "ERREUR: Le fichier de configuration n'est pas valide." << endl;
                exit(-1);
            }
            configFile >> dureeTraitementCaissier;
            caissiers[i] = dureeTraitementCaissier;
        }

        configFile.close();

        Banque *banque = new Banque(0, 100.0, nbCaissiers, caissiers, 1);
        banque->lancer();
        cout << "Duree reelle: " << banque->dureeReelleCalculation() << endl;
        cout << "Longueur moyenne file: " << banque->fileAttente()->longueurMoyenne() << endl;
        cout << "Longueur max file: " << banque->fileAttente()->longueurMax() << endl;
        cout << "Nombre de clients servis: " << banque->nbClients() << endl;
        cout << "Temps d'attente moyen: " << banque->fileAttente()->tempsMoyenAttente() << endl;

        double** tauxOccupation = banque->tauxOccupationParCaissier();
        for (int i = 0; i < nbCaissiers; i++) { cout << "Taux d'occupation du caissier " << i + 1 << ": " << *tauxOccupation[i] << endl; }
        for (int i = 0; i < nbCaissiers; ++i) { delete tauxOccupation[i]; }
        delete[] tauxOccupation;

        delete banque;
        delete [] caissiers;
        return 0;
    } else {
        cout << "ERREUR: Impossible d'ouvrir le fichier de configuration." << endl;
        return -1;
    }
}