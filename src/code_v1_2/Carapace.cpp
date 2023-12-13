#include "Bestiole.h"
#include "Decorator.h"
#include "Carapace.h"

#include <cstdlib>
#include <cmath>

Carapace::Carapace(IDecorator* b): Decorator(b) {
    coeff_vit = MIN_VIT + (MAX_VIT - MIN_VIT) * (double(random() % MAX_RAND)) / MAX_RAND;
    this->bestiole->setVitesse(this->bestiole->getVitesse()*coeff_vit);
}

Carapace::~Carapace(){
    delete this->bestiole;
}