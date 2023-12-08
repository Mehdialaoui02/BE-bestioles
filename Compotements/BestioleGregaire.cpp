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

double BestioleGregaire::CalculeDirection(Milieu &monMilieu) {
    const std::vector<std::unique_ptr<Bestiole>> &bestioles = monMilieu.getBestioles();
    int i = 0;

    // Variables for calculating average direction
    double sumOrientation = 0.0;
    int countVisible = 0;

    for (const std::unique_ptr<Bestiole> &bPtr : bestioles) {
        const Bestiole &b = *bPtr; // Dereference the smart pointer

        if (this->jeTeVois(b)) {
            
            // Accumulate orientation for visible Bestioles
            sumOrientation += b.getOrientation();
            countVisible++;
        }
    }

    // Calculate average direction
    double avgDirection = (countVisible > 0) ? (sumOrientation / countVisible) : 0.0;
    std::cout << "Average Direction: " << avgDirection << std::endl;

    return avgDirection;
}




// void BestioleGregaire::bouge(int xLim, int yLim) {
//     // Implementation of bouge in BestioleGregaire
//     std::cout << "Je bouge" << std::endl;
// }

void BestioleGregaire::action(Milieu &monMilieu) {
    //bouge(CalculeDirection(&monMilieu),CalculeDirection(&monMilieu));
    double newDir;
    newDir = CalculeDirection(monMilieu);
    setOrientation(newDir);
    bouge(monMilieu.getWidth(),monMilieu.getHeight());
}

