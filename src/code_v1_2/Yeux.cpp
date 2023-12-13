#include "Bestiole.h"
#include "Decorator.h"
#include "Yeux.h"

#include <cstdlib>
#include <cmath>

Yeux::Yeux(IDecorator* b): Decorator(b) {
    rayon = MIN_DIST + (MAX_DIST - MIN_DIST) * (double(random() % MAX_RAND)) / MAX_RAND;
    std::cout<<"rayon de vue :"<<rayon<<endl;
    angle = MIN_ANGLE + (MAX_ANGLE - MIN_ANGLE) * (double(random() % MAX_RAND)) / MAX_RAND;
    std::cout<<"anglede vue :"<<angle<<endl;
}

Yeux::~Yeux(){
    delete this->bestiole;
}

bool Yeux::jeTeVois(IDecorator* b) {
        
    double dist;
    double cos;
    double sin;
    double angle_b;
    double ecart_angulaire;

    dist = this->bestiole->dist(b);
    cos = (this->bestiole->getX() - b->getX())/dist;
    sin = (this->bestiole->getY() - b->getY())/dist;

    if (sin < 0) {
        angle_b = 2*M_PI - acos(cos);
    }
    else {
        angle_b = acos(cos);
    }
    
    ecart_angulaire = abs(angle_b-this->bestiole->getOrientation());  

    if (dist > rayon) {
        return false;
    }

    else if (ecart_angulaire < angle/2 || ecart_angulaire > M_PI * 2 - angle/2) {
        std::cout<<"vu avec les yeux"<<endl;
        return this->bestiole->detecter(b);
    }

    return false;
};