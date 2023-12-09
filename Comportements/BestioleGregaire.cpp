#include "Milieu.h"
#include "BestioleGregaire.h"
#include <iostream>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif


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
    double sumX = 0;
    double sumY = 0;
    int size = 0;
    double newOrient;

    for (const std::unique_ptr<Bestiole> &bPtr : bestioles) {
        const Bestiole &b = *bPtr; // Dereference the smart pointer
        if (this != &b && this->jeTeVois(b)) {
            // Accumulate orientation for visible Bestioles
            cout << "Visible Bestiole at Y: " << b.getY() << endl;
            sumX += b.getX();
            sumY += b.getY();
            size++;
        }
    }

    if (size != 0) {
        newOrient = 2 * M_PI - atan2((sumY / size - getY()), (sumX / size - getX()));
        cout << "Sum of Y: " << sumY << endl;
        cout << "New Orientation: " << newOrient << endl;
        setOrientation(newOrient);
    } else {
        cout << "No visible Bestioles." << endl;
    }
}



void BestioleGregaire::action(Milieu &monMilieu) {
    setDirection(monMilieu);
    bouge(monMilieu.getWidth(),monMilieu.getHeight());
}

