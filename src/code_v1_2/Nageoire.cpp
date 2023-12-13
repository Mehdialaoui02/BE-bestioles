#include "Bestiole.h"
#include "Decorator.h"
#include "Nageoire.h"

#include <cstdlib>
#include <cmath>

Nageoire::Nageoire(IDecorator* b): Decorator(b) {
    coeff_vit = MIN_VIT + (MAX_VIT - MIN_VIT) * (double(random() % MAX_RAND)) / MAX_RAND;
    this->bestiole->setVitesse(this->bestiole->getVitesse()*coeff_vit);
}

Nageoire::~Nageoire(){
    delete this->bestiole;
}