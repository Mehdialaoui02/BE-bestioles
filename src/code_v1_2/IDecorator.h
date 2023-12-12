#ifndef _IDECORATOR_H_
#define _IDECORATOR_H_


#include "UImg.h"
#include "Milieu.h"

#include <iostream>
#include <vector>

class Milieu;

class IDecorator
{
    public:
        virtual void bouge( int xLim, int yLim );
        virtual void action( Milieu & monMilieu);
        virtual void draw( UImg & support );
        virtual double dist( IDecorator* b );
        virtual void initCoords( int xLim, int yLim );

        virtual bool jeTeVois( IDecorator* b );
        virtual bool jeTEntends( IDecorator* b );
        virtual bool detecter( IDecorator* b );

        virtual int getX(){return 0;};
        virtual int getY(){return 0;};
        virtual double getOrientation(){return 0;};
        virtual double getCamouflage(){return 0;};
        virtual void setCamouflage(double new_camouflage){};
        virtual double getVitesse(){return 0;};
        virtual void setVitesse(double new_vitesse){};
};


#endif