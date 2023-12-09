#ifndef BESTIOLE_PREVOYANTE_H
#define BESTIOLE_PREVOYANTE_H

#include "Bestiole.h"
#include "Milieu.h"

class BestiolePrevoyante : public Bestiole {
private:
    int groupe;

public:
    BestiolePrevoyante();                             // Constructeur par défaut
    BestiolePrevoyante(const BestiolePrevoyante &bg);   // Constructeur de copies
    ~BestiolePrevoyante();                            // Destructeur

    void rejoindreGroupe(int groupe);               // Méthode spécifique à la version Peureuse
    void setDirection(Milieu &milieu);
    void action(Milieu &milieu) override;
};

#endif // BESTIOLE_PREVOYANTE_H
