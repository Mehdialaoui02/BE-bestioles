#include "Bestiole.h"
#include "IDecorator.h"
#include "Milieu.h"

#include <cstdlib>
#include <cmath>
#include <vector>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;

int               Bestiole::next = 0;


Bestiole::Bestiole( void )
{
   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   identite = ++next;  

   x = 0;
   y = 0;
   detection = 0;
   camouflage = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   /* valeur test, à définir de manière aléatoire plus tard : */
   camouflage = 0;
   detection = 1;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}

Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

}


Bestiole::~Bestiole( void )
{

   delete[] couleur;

   cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{
   x = rand() % xLim;
   y = rand() % yLim;
}

/*Prend en entrée un angle et retourne sa valeur dans l'intervalle [0 ; 2pi]*/
double Bestiole::orientation_intervalle(double angle) {
   double res = angle;
   while (res>2 * M_PI || res<0) {
      if (res>2 * M_PI) {
         res = res - 2*M_PI;
      }
      else {
         res = res + 2*M_PI;
      }
   }
   return res;
}

/*Méthode modifiée par la feature Nageoires et Carapaces*/
void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = orientation_intervalle(M_PI - orientation);
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = orientation_intervalle(-orientation);
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }
}


void Bestiole::action( Milieu & monMilieu)
{  
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );
}


void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}

/*Renvoie la distance entre deux bestioles*/
double Bestiole::dist(IDecorator* bestiole)
{

   double dist;

   dist = std::sqrt( (x-bestiole->getX())*(x-bestiole->getX()) + (y-bestiole->getY())*(y-bestiole->getY()));  
   return(dist);
}

/*Renvoie true si la détection est meilleure que le camouflage, false sinon*/
bool Bestiole::detecter(IDecorator* bestiole)
{
   return (bestiole->getCamouflage() <= detection);
}

/*Méthode modifiée par la feature Yeux*/
bool Bestiole::jeTeVois(IDecorator* bestiole)
{
   return false;
}

/*Méthode modifiée par la feature Oreille*/
bool Bestiole::jeTEntends(IDecorator* bestiole)
{
   return false;
}