#include "Milieu.h"
#include "BestioleGregaire.h"
#include <iostream>

BestioleGregaire::BestioleGregaire() : Bestiole(), groupe(0) {
}

BestioleGregaire::BestioleGregaire(const BestioleGregaire &bg) : Bestiole(bg), groupe(bg.groupe) {
}

BestioleGregaire::~BestioleGregaire() {
}


void BestioleGregaire::rejoindreGroupe(int groupe) {
    // Implémentation de la méthode spécifique à la version gregaire ici
    this->groupe = groupe;
}

void BestioleGregaire::setDirection(Milieu &monMilieu) {
    const std::vector<std::unique_ptr<Bestiole>> &bestioles = monMilieu.getBestioles();

    // Variables for calculating average direction
    double sumOrientation = 0;

    for (const std::unique_ptr<Bestiole> &bPtr : bestioles) {
        const Bestiole &b = *bPtr; // Dereference the smart pointer
        if (this->jeTeVois(b)) {
            // Accumulate orientation for visible Bestioles
            sumOrientation += b.getOrientation();
        }
    }

    cout << sumOrientation / (bestioles.size()) << endl;
    if (bestioles.size() != 0 and getX() < monMilieu.getWidth()/2) {
        setOrientation(sumOrientation / (bestioles.size()));
    }

}


void BestioleGregaire::action(Milieu &monMilieu) {
    setDirection(monMilieu);
    bouge(monMilieu.getWidth(),monMilieu.getHeight());
}

