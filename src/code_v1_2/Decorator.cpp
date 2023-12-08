#include "Bestiole.h"
#include "Decorator.h"

Decorator::Decorator(const Bestiole & b) {
    this->bestiole = bestiole;
}

Decorator::~Decorator( void ) {

}

bool Decorator::jeTEntends(const Bestiole & b){
    return false;
}

void Decorator::action( Milieu & monMilieu) {
    this->bestiole->action(monMilieu);
}

void Decorator::draw( UImg & support ){
    this->bestiole->draw(support);
}

double Decorator::dist( const Bestiole & b ) {
    return this->bestiole->dist(b);
};

bool Decorator::jeTeVois( const Bestiole & b ) const {
    return this->bestiole->jeTeVois(b);
};

bool Decorator::detecter( const Bestiole & b ) {
    return this->bestiole->detecter(b);
};

void Decorator::initCoords( int xLim, int yLim ) {
    this->bestiole->initCoords(xLim, yLim);
};

