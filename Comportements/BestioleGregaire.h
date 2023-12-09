#ifndef BESTIOLE_GREGAIRE_H
#define BESTIOLE_GREGAIRE_H

#include "Bestiole.h"
#include "Milieu.h"

class BestioleGregaire : public Bestiole {
protected:
    int groupe;

public:
    BestioleGregaire();                             // Constructeur par défaut
    BestioleGregaire(const BestioleGregaire &bg);   // Constructeur de copies
    ~BestioleGregaire();                            // Destructeur

    void setDirection(Milieu &monMilieu);       //  de la méthode action
    void action(Milieu & monMilieu) override;

};

#endif // BESTIOLE_GREGAIRE_H
