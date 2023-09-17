#ifndef __CLIENT_H
#define __CLIENT_H

class Client
{
protected:
    double _heureArrivee;
public:
    Client(double heureArrivee);
    double heureArrivee() const;
};
#endif