#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <memory>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

protected :
   int               identite;

   int               personalite;

   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   int               frame_birth;
   int               frame_age;
   int               collision_last_frame;

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;
   bool is_dead( int run_time );
   bool collision(std::shared_ptr<Bestiole> b);
   void after_collision(std::shared_ptr<Bestiole> b);
   int getCollisionLastFrame( void );
   void setCollisionLastFrame( int collision_last_frame_ );

   void initClonage( int frame_birth_, int x_, int y_, int xLim );

   int getIdentite( void );
   int getPersonalite( void ){return personalite;};
   int getX( void ){return x;};
   int getY( void ){return y;};

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );


};


#endif
