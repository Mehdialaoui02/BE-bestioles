#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "IDecorator.h"
#include "UImg.h"

#include <iostream>
#include <vector>

using namespace std;
 

class Milieu;


class Bestiole: public IDecorator
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;

   static int              next;

protected :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   double            camouflage;
   double            detection;

   T               * couleur;

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   virtual ~Bestiole( void );                      // Destructeur

   //IDecorator :
   void action( Milieu & monMilieu);
   void draw( UImg & support );
   void bouge( int xLim, int yLim );

   double dist(IDecorator* bestiole);
   bool jeTeVois(IDecorator* bestiole);
   bool jeTEntends(IDecorator* bestiole);
   bool detecter(IDecorator* bestiole);
   void initCoords( int xLim, int yLim );
   
   double orientation_intervalle(double angle);
   int getX(){return x;};
   int getY(){return y;};
   double getOrientation(){return orientation;};
   double getCamouflage(){return camouflage;};
   void setCamouflage(double new_camouflage){camouflage = new_camouflage;};
   double getVitesse(){return vitesse;};
   void setVitesse(double new_vitesse){vitesse = new_vitesse;};

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
};


#endif