#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <vector>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static const double     LIMITE_OUIE;

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

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   virtual ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   virtual void action( Milieu & monMilieu);
   virtual void draw( UImg & support );

   virtual double dist( const Bestiole & b );
   virtual bool jeTeVois( const Bestiole & b ) const;
   virtual bool jeTEntends( const Bestiole & b );
   virtual bool detecter( const Bestiole & b );

   virtual void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
