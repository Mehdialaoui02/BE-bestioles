#include "BestiolePrevoyante.h"
#include <iostream>  

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

BestiolePrevoyante::BestiolePrevoyante() : groupe(3) {
}

BestiolePrevoyante::BestiolePrevoyante(const BestiolePrevoyante &bp) : Bestiole(bp), groupe(bp.groupe) {
}

BestiolePrevoyante::~BestiolePrevoyante() {
}

// Method to join a group
void BestiolePrevoyante::rejoindreGroupe(int newGroupe) {
    groupe = newGroupe;
}

void BestiolePrevoyante::setDirection(Milieu &milieu) {
    const std::vector<std::unique_ptr<Bestiole>> &bestioles = milieu.getBestioles();

    // Variables for calculating average direction
    double sumX = 0;
    double sumY = 0;
    int size = 0;
    double newOrient;

    for (const std::unique_ptr<Bestiole> &bPtr : bestioles) {
        const Bestiole &b = *bPtr; // Dereference the smart pointer
        if (this != &b && this->jeTeVois(b)) {
            sumX += b.getX();
            sumY += b.getY();
            size++;
        }
    }

    if (size != 0) {
        if (atan2((sumY / size - getY()), (sumX / size - getX())) != 0) {
        newOrient =  M_PI - atan2((sumY / size - getY()), (sumX / size - getX()));
        setOrientation(newOrient);
        
    } else {
        setOrientation(2*M_PI + atan2((milieu.getHeight()/2 - getY()), (milieu.getWidth()/2 - getX())));
    }
}
}

void BestiolePrevoyante::action(Milieu &milieu) {
    setDirection(milieu);
    bouge(milieu.getWidth(), milieu.getHeight());
}
