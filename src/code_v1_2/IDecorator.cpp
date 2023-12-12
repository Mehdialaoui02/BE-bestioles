#include "IDecorator.h"
#include "Milieu.h"

#include <cstdlib>
#include <cmath>
#include <vector>

void IDecorator::initCoords( int xLim, int yLim ){}


void IDecorator::bouge( int xLim, int yLim ){}


void IDecorator::action( Milieu & monMilieu){}


void IDecorator::draw( UImg & support ){}

double IDecorator::dist(IDecorator* bestiole){return 0;}

bool IDecorator::detecter(IDecorator* bestiole){return false;}

bool IDecorator::jeTeVois(IDecorator* bestiole){return false;}

bool IDecorator::jeTEntends(IDecorator* bestiole){return false;}