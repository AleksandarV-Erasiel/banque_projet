#include <iostream>
using namespace std;
#include "Banque.hpp"
#include "Arrivee.hpp"

int main() {
    double *caissiers = new double[3];
    caissiers[0] = 3.0;
    caissiers[1] = 4.0;
    caissiers[2] = 5.0;
    Banque banque(0, 60.0, 3, caissiers , 2.0);
    Arrivee arrivee(&banque, 4.0);
    banque.ajouter(arrivee);
    banque.lancer();
    //afficher resultats
    return 0;
}