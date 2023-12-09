#include "BestioleMultiPerso.h"
#include "BestioleGregaire.h"
#include "BestioleKamikaze.h"
#include "BestiolePeureuse.h"
#include "BestiolePrevoyante.h"

#include <iostream>  // Include any other necessary headers

BestioleMultiPerso::BestioleMultiPerso() : comportement(0), groupe(0), step(0), CurrentBestiole(std::unique_ptr<Bestiole>(new Bestiole())) {
}

BestioleMultiPerso::BestioleMultiPerso(const BestioleMultiPerso &bmp) : Bestiole(bmp), groupe(bmp.groupe),
 comportement(bmp.comportement), step(bmp.step) {
}

BestioleMultiPerso::~BestioleMultiPerso() {
}

void BestioleMultiPerso::setComportement() {

    // Store the current position before changing behavior
        int originalX = getX();
        int originalY = getY();

    switch (comportement) {
    case 0:
        CurrentBestiole = std::unique_ptr<Bestiole>(new BestioleGregaire());
        cout << "Gregaire" << endl;
        break;

    case 1:
        CurrentBestiole = std::unique_ptr<Bestiole>(new BestioleKamikaze());
        cout << "Kamikaze" << endl;
        break;

    case 2:
        CurrentBestiole = std::unique_ptr<Bestiole>(new BestiolePeureuse());
        cout << "Peureuse" << endl;
        break;

    case 3:
        CurrentBestiole = std::unique_ptr<Bestiole>(new BestiolePrevoyante());
        cout << "Prevoyante" << endl;
        break;

    default:
        CurrentBestiole = std::unique_ptr<Bestiole>(new BestioleGregaire());
    }

    setX(originalX);
    setY(originalY);
}

void BestioleMultiPerso::setDirection(Milieu &monMilieu) {
    CurrentBestiole->action(monMilieu);
    setOrientation(CurrentBestiole->getOrientation());
}

void BestioleMultiPerso::action(Milieu &monMilieu) {
    step++;
    if (step == 150) {
        setComportement();
        couleur = CurrentBestiole->getCouleur();
        vitesse = 7;
        if (comportement < 3) {
            comportement++;
        } else {
            comportement = 0;
        }
        step = 0;
    }
    setDirection(monMilieu);
    bouge(monMilieu.getWidth(), monMilieu.getHeight());
    cout << getX() << endl;
}
