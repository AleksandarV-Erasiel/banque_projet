#ifndef __EVENEMENT_H
#define __EVENEMENT_H

class Sed;
class Evenement
{
protected:
    Sed *_sed;
    double _heure;
public:
    Evenement(Sed *sed, double heure);
    virtual ~Evenement();
    virtual void traiter();
    double heure();
    bool operator<(const Evenement& e) const;
};
#endif