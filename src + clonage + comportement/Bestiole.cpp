#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.; //8.
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;


Bestiole::Bestiole( void )
{

   identite = ++next;
   personalite = 0;
   collision_last_frame = 0;
   comportement_last_frame = 0;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   personalite = b.personalite;
   collision_last_frame = b.collision_last_frame;
   comportement_last_frame = b.comportement_last_frame;
   frame_age = b.frame_age;

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
   // x = xLim / 2;
   // y = yLim / 2;

}


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
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}


void Bestiole::action( Milieu & monMilieu, int run_time, int comportement_cooldown )
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


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

bool Bestiole::is_dead( int run_time )
{
   return (run_time - this->frame_birth >= this->frame_age);
}

int Bestiole::getIdentite( void )
{
   return this->identite;
}

bool Bestiole::collision(std::shared_ptr<Bestiole> b)
{
   double         xt_1 = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt_1 = y - sin( orientation )*AFF_SIZE/2.1;

   double         xt_2 = b->x + cos( b->orientation )*AFF_SIZE/2.1;
   double         yt_2 = b->y - sin( b->orientation )*AFF_SIZE/2.1;

   double diameter = AFF_SIZE;

   return (xt_1 - xt_2) * (xt_1 - xt_2) + (yt_1 - yt_2) * (yt_1 - yt_2) <= diameter * diameter;
}

void Bestiole::after_collision(std::shared_ptr<Bestiole> b)
{
   if (std::abs(orientation - b->orientation) < M_PI / 4.)
   {
      if (vitesse > b->vitesse)
      {
         orientation = 2 * M_PI - orientation;
      }
      else
      {
         b->orientation = 2 * M_PI - b->orientation;
      }
   }
   else
   {
      double orientation_loc = orientation;
      orientation = b->orientation;
      b->orientation = orientation_loc;
   }
}

int Bestiole::getCollisionLastFrame( void )
{
   return this->collision_last_frame;
}

void Bestiole::setCollisionLastFrame( int collision_last_frame_ )
{
   this->collision_last_frame = collision_last_frame_;
}

void Bestiole::initClonage( int frame_birth_, int x_, int y_, int xLim )
{
   x = (x_ + AFF_SIZE < xLim) ? x_ + AFF_SIZE : x_ - AFF_SIZE;   
   y = y_;

   orientation = static_cast<double>( std::rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( std::rand() )/RAND_MAX*MAX_VITESSE;

   frame_birth = frame_birth_;
   collision_last_frame = 0;

}