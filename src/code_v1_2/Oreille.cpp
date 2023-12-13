#include "Bestiole.h"
#include "Decorator.h"
#include "Oreille.h"

#include <cstdlib>
#include <cmath>

Oreille::Oreille(IDecorator* b): Decorator(b) {
    rayon = MIN_DIST + (MAX_DIST - MIN_DIST) * (double(random() % MAX_RAND)) / MAX_RAND;
    std::cout<<"rayon d'ouie :"<<rayon<<endl;
}

Oreille::~Oreille(){
    delete this->bestiole;
}

/*  Méthode de bestiole modifée par la feature oreille
    On vérifie d'abord si la bestiole est entendu avant
    de faire le test de détection via détecter*/

bool Oreille::jeTEntends(IDecorator* b){
    
    double dist;
    dist = this->bestiole->dist(b);

    this->rayon = 50;
    if (dist <= rayon) {
        std::cout<<"entendu avec les oreilles"<<endl;
        return (this->bestiole->detecter(b));
    }
    return false;
}