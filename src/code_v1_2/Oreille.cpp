#include "Bestiole.h"
#include "Decorator.h"
#include "Oreille.h"

#include <cstdlib>
#include <cmath>

Oreille::Oreille(const Bestiole & b): Decorator(b) {
    rayon = MIN_VUE + (MAX_VUE - MIN_VUE) * (random() % MAX_RAND) / MAX_RAND;
    detection = MIN_DETECTION + (MAX_DETECTION - MIN_DETECTION) * (random() % MAX_RAND) / MAX_RAND;
}

Oreille::~Oreille(){
    delete this->bestiole;
}

/*Méthode appliquant le principe de récursivitié*/
double Oreille::dist(const Bestiole & b) {
    return this->bestiole->dist(b);
}

/*Méthode appliquant le principe de récursivité*/
bool Oreille::detecter(const Bestiole & b) {
    return this->bestiole->detecter(b);
}

/*Méthode basique de bestiole modifée par la feature oreille*/
bool Oreille::jeTEntends(const Bestiole & b){
    
    double dist;
    cout << "troouvé" << endl;
    dist = this->bestiole->dist(b);

    this->rayon = 1000;
    
    if (dist <= rayon) {
        
        return (this->bestiole->detecter(b));
    }

    return false;
}

void Oreille::action( Milieu & monMilieu) {
    this->bestiole->action(monMilieu);
}

void Oreille::draw( UImg & support ){
    this->bestiole->draw(support);
}


bool Oreille::jeTeVois( const Bestiole & b ) const {
    return this->bestiole->jeTeVois(b);
};


void Oreille::initCoords( int xLim, int yLim ) {
    this->bestiole->initCoords(xLim, yLim);
};