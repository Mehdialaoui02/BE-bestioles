#include "Bestiole.h"
#include "Decorator.h"
#include "Yeux.h"

#include <cstdlib>
#include <cmath>

Yeux::Yeux(IDecorator* b): Decorator(b) {
    rayon = MIN_DIST + (MAX_DIST - MIN_DIST) * (random() % MAX_RAND) / MAX_RAND;
    angle = MIN_ANGLE + (MAX_ANGLE - MIN_ANGLE) * (random() % MAX_RAND) / MAX_RAND;
}

Yeux::~Yeux(){
    delete this->bestiole;
}

bool Yeux::jeTeVois(IDecorator* b) {
        
    double dist;
    double cos;

    dist = this->bestiole->dist(b);
    cos = (this->bestiole->getX() - b->getX())/dist;

    if (dist > rayon) {
        return false;
    }

    else if (acos(cos) - this->bestiole->getOrientation() < angle/2) {
        return this->bestiole->detecter(b);
    }

    return false;
};