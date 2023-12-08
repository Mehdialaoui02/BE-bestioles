#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>

using namespace std;


class Milieu;


class Bestiole
{

protected :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

protected :
   int               identite;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

protected :
   int               x, y;

protected :
   virtual void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   virtual void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   std::pair<int, int> getCoords(void) const { return {x,y}; };
   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   // Getter and Setter for identite
   int getIdentite() const { return identite; }
   void setIdentite(int newIdentite) { identite = newIdentite; }

   // Getter and Setter for cumulX
   double getCumulX() const { return cumulX; }
   void setCumulX(double newCumulX) { cumulX = newCumulX; }

   // Getter and Setter for cumulY
   double getCumulY() const { return cumulY; }
   void setCumulY(double newCumulY) { cumulY = newCumulY; }

   // Getter and Setter for orientation
   double getOrientation() const { return orientation; }
   void setOrientation(double newOrientation) { orientation = newOrientation; }

   // Getter and Setter for vitesse
   double getVitesse() const { return vitesse; }
   void setVitesse(double newVitesse) { vitesse = newVitesse; }

   // Getter and Setter for couleur
   T* getCouleur() const { return couleur; }
   void setCouleur(T* newCouleur) { couleur = newCouleur; }

   // Getter and Setter for x
   int getX() const { return x; }
   void setX(int newX) { x = newX; }

   // Getter and Setter for y
   int getY() const { return y; }
   void setY(int newY) { y = newY; }

   static double getAffSize() { return AFF_SIZE; }

   // Getter for MAX_VITESSE
   static double getMaxVitesse() { return MAX_VITESSE; }

   // Getter for LIMITE_VUE
   static double getLimiteVue() { return LIMITE_VUE; }

   // Getter for next
   static int getNext() { return next; }
   
};


#endif
