#include "Bestiole.h"
#include "Decorator.h"
#include "Camouflage.h"

#include <cstdlib>
#include <cmath>

Camouflage::Camouflage(IDecorator* b): Decorator(b) {
    camouflage = MIN_CAMOUFLAGE + (MAX_CAMOUFLAGE - MIN_CAMOUFLAGE) * (double(random() % MAX_RAND)) / MAX_RAND;
    this->bestiole->setCamouflage(camouflage);
}

Camouflage::~Camouflage(){
    delete this->bestiole;
}