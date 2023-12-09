#include "Milieu.h"
#include "BestiolePeureuse.h"
#include <iostream>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

BestiolePeureuse::BestiolePeureuse() : Bestiole(), groupe(2) {
    couleur[ 0 ] = 200;
    couleur[ 1 ] = 200;
    couleur[ 2 ] = 200;
}

BestiolePeureuse::BestiolePeureuse(const BestiolePeureuse &bg) : Bestiole(bg), groupe(bg.groupe) {
    couleur = new T[ 3 ];
    couleur[ 0 ] = 200;
    couleur[ 1 ] = 200;
    couleur[ 2 ] = 200;
}

BestiolePeureuse::~BestiolePeureuse() {
}


void BestiolePeureuse::setDirection(Milieu &monMilieu) {
    const std::vector<std::unique_ptr<Bestiole>> &bestioles = monMilieu.getBestioles();

    int countVisible = 0;
    for (const std::unique_ptr<Bestiole> &bPtr : bestioles) {
        const Bestiole &b = *bPtr; // Dereference the smart pointer
        if (this->jeTeVois(b)) {
            countVisible++;
        }
    }
    if (countVisible >= 3) {
        std::cout << "should change" << orientation << std::endl;
        setOrientation(getOrientation() - M_PI);
        std::cout << "changed" << orientation << std::endl;
    }

}
 
    void BestiolePeureuse::action(Milieu &monMilieu) {
        setDirection(monMilieu);
        bouge(monMilieu.getWidth(),monMilieu.getHeight());
    }   





