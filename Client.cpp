#include "Client.hpp"

Client::Client(double heureArrivee) {
    _heureArrivee = heureArrivee;
}

double Client::heureArrivee() const { return _heureArrivee; }