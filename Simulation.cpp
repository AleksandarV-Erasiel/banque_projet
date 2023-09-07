#include <iostream>
using namespace std;
#include "Banque.hpp"

int main() {
    cout << "Simulation lancee" << endl;
    double *caissiers = new double[3];
    caissiers[0] = 3.0;
    caissiers[1] = 4.0;
    caissiers[2] = 5.0;
    Banque *banque = new Banque(0, 60.0, 3, caissiers , 2.0);
    banque->lancer();
    //afficher resultats
    delete banque;
    delete [] caissiers;
    return 0;
}