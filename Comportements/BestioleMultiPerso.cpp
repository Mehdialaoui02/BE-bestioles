#include "BestioleMultiPerso.h"
#include "BestioleGregaire.h"
#include "BestioleKamikaze.h"
#include "BestiolePeureuse.h"
#include "BestiolePrevoyante.h"

#include <iostream>  // Include any other necessary headers

BestioleMultiPerso::BestioleMultiPerso() : comportement(1), groupe(0), step(0), CurrentBestiole(std::unique_ptr<Bestiole>(new Bestiole())) {
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

    cout << "OriginalX : " << originalX << " OriginalY : " << originalY << endl;
    switch (comportement) {
    case 0:
        CurrentBestiole.reset(new BestioleGregaire());
        cout << "Gregaire" << endl;
        break;

    case 1:
        CurrentBestiole.reset(new BestioleKamikaze());
        cout << "Kamikaze" << endl;
        break;

    case 2:
        CurrentBestiole.reset(new BestiolePeureuse());
        cout << "Peureuse" << endl;
        break;

    case 3:
        CurrentBestiole.reset(new BestiolePrevoyante());
        cout << "Prevoyante" << endl;
        break;

    default:
        CurrentBestiole.reset(new BestioleGregaire());
    }

    CurrentBestiole->setX(originalX);
    CurrentBestiole->setY(originalY);
}

void BestioleMultiPerso::setDirection(Milieu &monMilieu) {

    int originalX = getX();
    int originalY = getY();

    cout << "avant :" << CurrentBestiole->getOrientation() << endl;
    CurrentBestiole->action(monMilieu);
    cout << "apres ;" << CurrentBestiole->getOrientation() << endl;

    setOrientation(CurrentBestiole->getOrientation());

    CurrentBestiole->setX(originalX);
    CurrentBestiole->setY(originalY);
}

void BestioleMultiPerso::action( Milieu & monMilieu ) {
    step++;
    int originalX = getX();
    int originalY = getY();
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

    CurrentBestiole->setX(originalX);
    CurrentBestiole->setY(originalY);
}
