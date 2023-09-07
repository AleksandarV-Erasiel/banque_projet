#ifndef __FILEATTENTE_H
#define __FILEATTENTE_H
#include "Client.hpp"

class FileAttente
{
protected:
    /* data */
public:
    FileAttente(/* args */);
    ~FileAttente();
    int longueurMax();
    double longueurMoyenne();
    double tempsMoyenAttente();
    void ajouter(Client client);
    bool estVide();
    Client retirer();
};
#endif