#ifndef __CLIENT_H
#define __CLIENT_H

/**
 * @brief La classe Client représente un client de la banque.
 */
class Client
{
protected:
    double _heureArrivee;

public:
    /**
     * @brief Constructeur de la classe Client.
     * @param heureArrivee L'heure à laquelle le client est arrivé.
     */
    Client(double heureArrivee);

    /**
     * @brief Récupère l'heure d'arrivée du client.
     * @return L'heure d'arrivée du client.
     */
    double heureArrivee() const;
};

#endif
