#ifndef __FILEATTENTE_H
#define __FILEATTENTE_H
#include "Client.hpp"
#include "Banque.hpp"
#include <queue>
using namespace std;

class Banque;

/**
 * @brief La classe FileAttente représente la file d'attente des clients dans la banque.
 */
class FileAttente
{
protected:
    Banque *_banque;          /**< Un pointeur vers la banque associée à la file d'attente. */
    queue<Client> _clients;  /**< La file d'attente des clients. */
    int _longueurMax;        /**< La longueur maximale de la file d'attente. */
    double _longueurMoyenne; /**< La longueur moyenne de la file d'attente. */
    double _tempsMoyenAttente; /**< Le temps moyen d'attente des clients dans la file. */

public:
    /**
     * @brief Constructeur de la classe FileAttente.
     * @param banque Un pointeur vers la banque associée à la file d'attente.
     */
    FileAttente(Banque *banque);

    /**
     * @brief Obtient la longueur maximale de la file d'attente.
     * @return La longueur maximale de la file d'attente.
     */
    int longueurMax();

    /**
     * @brief Obtient la longueur moyenne de la file d'attente.
     * @return La longueur moyenne de la file d'attente.
     */
    double longueurMoyenne();

    /**
     * @brief Obtient le temps moyen d'attente des clients dans la file.
     * @return Le temps moyen d'attente des clients dans la file.
     */
    double tempsMoyenAttente();

    /**
     * @brief Ajoute un client à la file d'attente.
     * @param client Le client à ajouter.
     */
    void ajouter(Client& client);

    /**
     * @brief Vérifie si la file d'attente est vide.
     * @return Vrai si la file d'attente est vide, sinon faux.
     */
    bool estVide();

    /**
     * @brief Retire un client de la file d'attente.
     * @return Une référence au client retiré.
     */
    Client& retirer();

    /**
     * @brief Obtient une copie de la file d'attente (pour les besoins de la simulation).
     * @return Une copie de la file d'attente.
     */
    queue<Client> clientsQueue();

    /**
     * @brief Affiche la liste des clients dans la file d'attente.
     */
    void afficherListeClients();
};

#endif
