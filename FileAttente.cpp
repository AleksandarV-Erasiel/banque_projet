#include "FileAttente.hpp"
#include "Banque.hpp"

FileAttente::FileAttente(Banque *banque) {
    _banque = banque;
    _longueurMax = 0;
    _longueurMoyenne = -1, _tempsMoyenAttente = -1;
}

int FileAttente::longueurMax() {
    return _longueurMax;
}

double FileAttente::longueurMoyenne() {
    return _longueurMoyenne;
}

double FileAttente::tempsMoyenAttente() {
    return _tempsMoyenAttente;
}

void FileAttente::ajouter(Client &client) {
    _clients.push(client);
}

bool FileAttente::estVide() {
    return _clients.empty();
}

Client &FileAttente::retirer() {
    Client &c = _clients.front();
    if (_longueurMax < _clients.size()) _longueurMax = (int) _clients.size();
    if (_longueurMoyenne == -1) _longueurMoyenne = (int) _clients.size();
    else {
        _longueurMoyenne += (int) _clients.size();
        _longueurMoyenne /= 2;
    }
    if (_tempsMoyenAttente == -1) _tempsMoyenAttente = _banque->heure() - c.heureArrivee();
    else {
        _tempsMoyenAttente += _banque->heure() - c.heureArrivee();
        _tempsMoyenAttente /= 2;
    }
    _clients.pop();
    return c;
}
