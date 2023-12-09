#ifndef BESTIOLE_KAMIKAZE_H
#define BESTIOLE_KAMIKAZE_H

#include "Bestiole.h"
#include "Milieu.h"

class BestioleKamikaze : public Bestiole {
protected:
    int groupe;

public:
    BestioleKamikaze();                             // Constructeur par défaut
    BestioleKamikaze(const BestioleKamikaze &bg);   // Constructeur de copies
    ~BestioleKamikaze();                            // Destructeur

    void PlusProche(Milieu &monMilieu, int* xproche, int* yproche);
    void setDirection(Milieu &monMilieu);
    void action( Milieu & monMilieu ) override;

};

#endif // BESTIOLE_KAMIKAZE_H
