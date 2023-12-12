#ifndef DECOBEST
#define DECOBEST

#include "Bestiole.h"
#include "Milieu.h"
#include "IDecorator.h"

using namespace std;

class Decorator: public IDecorator 
{

    protected :
    
    IDecorator*       bestiole;

    public :

    Decorator(IDecorator* bestiole);
    virtual ~Decorator();

    void action( Milieu & monMilieu);
    void draw( UImg & support );
    double dist( IDecorator* bestiole );
    bool jeTeVois( IDecorator* bestiole );
    bool jeTEntends( IDecorator* bestiole );
    bool detecter( IDecorator* bestiole );
    void initCoords( int xLim, int yLim );

    int getX(){return this->bestiole->getX();}
    int getY(){return this->bestiole->getY();}
    double getOrientation(){return this->bestiole->getOrientation();};
    double getCamouflage(){return this->bestiole->getCamouflage();};
    void setCamouflage(double new_camouflage){this->bestiole->setCamouflage(new_camouflage);};
    double getVitesse(){return this->bestiole->getVitesse();};
    void setVitesse(double new_vitesse){this->bestiole->setVitesse(new_vitesse);};
};

#endif