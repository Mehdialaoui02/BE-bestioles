#ifndef BESTIOLE_MULTIPERSO_H
#define BESTIOLE_MULTIPERSO_H

#include "Bestiole.h"
#include "Milieu.h"

class BestioleMultiPerso : public Bestiole {

protected:
    int groupe;
    int comportement;
    int step;
    std::unique_ptr<Bestiole> CurrentBestiole;
public:
    BestioleMultiPerso();                             // Constructeur par défaut
    BestioleMultiPerso(const BestioleMultiPerso &bg);   // Constructeur de copies
    ~BestioleMultiPerso();                            // Destructeur

    void setComportement();       //  de la méthode action
    void setDirection(Milieu &monMilieu);       //  de la méthode action
    void action( Milieu & monMilieu ) override;

};

#endif // BESTIOLE_MultiPerso_H
