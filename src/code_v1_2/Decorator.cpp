#include "Bestiole.h"
#include "Decorator.h"
#include "IDecorator.h"

Decorator::Decorator(IDecorator* bestiole){
    this->bestiole = bestiole;
}

Decorator::~Decorator( void ) {

}

bool Decorator::jeTEntends(IDecorator* bestiole){
    return this->bestiole->jeTEntends(bestiole);
}

void Decorator::action( Milieu & monMilieu) {
    this->bestiole->action(monMilieu);
}

void Decorator::draw( UImg & support ){
    this->bestiole->draw(support);
}

double Decorator::dist(IDecorator* bestiole ) {
    return this->bestiole->dist(bestiole);
};

bool Decorator::jeTeVois(IDecorator* bestiole) {
    return this->bestiole->jeTeVois(bestiole);
};

bool Decorator::detecter(IDecorator* bestiole) {
    return this->bestiole->detecter(bestiole);
};

void Decorator::initCoords( int xLim, int yLim ) {
    this->bestiole->initCoords(xLim, yLim);
};

