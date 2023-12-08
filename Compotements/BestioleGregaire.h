#ifndef BESTIOLE_GREGAIRE_H
#define BESTIOLE_GREGAIRE_H

#include "Bestiole.h"
#include "Milieu.h"

class BestioleGregaire : public Bestiole {
private:
    int groupe;

public:
    BestioleGregaire();                             // Constructeur par défaut
    BestioleGregaire(const BestioleGregaire &bg);   // Constructeur de copies
    ~BestioleGregaire();                            // Destructeur

    void rejoindreGroupe(int groupe);               // Méthode spécifique à la version gregaire
    double CalculeDirection(Milieu &monMilieu) ;       //  de la méthode action
    void bouge(int xLim, int yLim) override; 
    void action(Milieu & monMilieu) override;

};

#endif // BESTIOLE_GREGAIRE_H
