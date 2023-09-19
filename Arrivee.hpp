#ifndef __ARRIVEE_H
#define __ARRIVEE_H
#include "Evenement.hpp"
#include "Banque.hpp"

/**
 * @brief La classe Arrivee représente l'événement d'arrivée dans la simulation de la banque
 * 
 * Cette classe hérité d'Evenement et défini le comportement d'une événement d'arrivée dans la simulation
 */
class Arrivee: public Evenement
{
public:
    /**
     * @brief Construit un nouvel objet d'arrivée
     * 
     * @param sed Un pointeur vers l'objet Banque
     * @param heure L'heure à laquelle l'événément d'arrivée se déroule
     */
    Arrivee(Banque *sed, double heure);

    /**
     * @brief Traîte l'événement d'arrivée
     * 
     * Cette procédure gère l'événement d'arrivée, ce qui inclut la vérification de la disponibilité d'un caissier
     * Si le caissier libre est trouvé le client est servi sinon le client est ajouté à la file d'attente
     */
    void traiter();
};
#endif