#ifndef __DEPART_H
#define __DEPART_H

#include "Caissier.hpp"
#include "Client.hpp"
#include "Evenement.hpp"
#include "Banque.hpp"

/**
 * @brief La classe Depart représente un événement de départ d'un client d'une caisse.
 */
class Depart : public Evenement
{
protected:
    Caissier *_caissier; /**< Le caissier qui a servi le client. */
    Client *_client;    /**< Le client qui s'est fait servir. */

public:
    /**
     * @brief Constructeur de la classe Depart.
     * @param sed Un pointeur vers la banque associée à l'événement.
     * @param heure L'heure à laquelle l'événement de départ se produit.
     * @param caissier Le caissier qui a servi le client..
     * @param client Le client qui s'est fait servir.
     */
    Depart(Banque *sed, double heure, Caissier &caissier, Client &client);

    /**
     * @brief Traite l'événement de départ.
     */
    void traiter();
};

#endif
