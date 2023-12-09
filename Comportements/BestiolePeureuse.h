#ifndef BESTIOLE_PEUREUSE_H
#define BESTIOLE_PEUREUSE_H

#include "Bestiole.h"
#include "Milieu.h"

class BestiolePeureuse : public Bestiole {
private:
    int groupe;

public:
    BestiolePeureuse();                             // Constructeur par défaut
    BestiolePeureuse(const BestiolePeureuse &bg);   // Constructeur de copies
    ~BestiolePeureuse();                            // Destructeur

    void rejoindreGroupe(int groupe);               // Méthode spécifique à la version Peureuse
    void CalculeDirection(Milieu &monMilieu) ;       //  de la méthode action
    void Changedir(Milieu &milieu);
    void action(Milieu &milieu) override;
};

#endif // BESTIOLE_PEUREUSE_H
