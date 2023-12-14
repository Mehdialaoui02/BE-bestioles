#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>


#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define BOLD "\033[1m"

#define NAGEOIRE_RAND_MAX 25 // 1/25 chance d'avoir une nageoire
#define COEF_NAGEOIRE_MAX 2 // multiplie d'une à deux fois vitesse

#define CARAPACE_RAND_MAX 3 // 1/3 chance d'avoir une carapace
#define COEF_CARAPACE_MAX 25 // multiplie d'un à 25 fois le random max gérant la collision

#define VUE_COEF_MIN 0.5
#define OUIE_COEF_MIN 0.5

#define VUE_ANGLE_MAX M_PI
#define VUE_ANGLE_COEF_MIN 1/12

#define CAMOUFLAGE_MIN 0.1
#define CAMOUFLAGE_MAX 1

#define PROBA_SANS_OREILLES 30 //    1 / 30
#define PROBA_SANS_YEUX 30 //        idem
#define PROBA_CAMOUFLAGE 5 // 1/5 d'avoir un camouflage



const double      Bestiole::AFF_SIZE = 8.; //8.
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 60.; // vue effective = coef_vue * limite, coef dans [VUE_COEF_MIN, 1]
const double      Bestiole::LIMITE_OUIE = 45.; // ouie effective = coef_ouie * limite, coef dans [OUIE_COEF_MIN, 1]

int               Bestiole::next = 0;


Bestiole::Bestiole( void )
{

   identite = ++next;
   personalite = 0;
   collision_last_frame = 0;
   comportement_last_frame = 0;
   
   //init capteurs
   coef_carapace = 1;
   yeux_detection = 0;
   oreille_detection = 0;
   yeux_distance_coef = VUE_COEF_MIN;
   yeux_angle = VUE_ANGLE_COEF_MIN * VUE_ANGLE_MAX;
   oreille_distance_coef = OUIE_COEF_MIN;
   camouflage_coef = 0;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;


// PARTIE CAPTEURS

   int nageoire_coin_flip = rand() % NAGEOIRE_RAND_MAX;
   if (nageoire_coin_flip == 0) // alors on donne une nageoire
   {
      double coef_nageoire = (static_cast<double>( rand() )/RAND_MAX) * (COEF_NAGEOIRE_MAX - 1) + 1;
      vitesse = coef_nageoire * vitesse;
      std::cout << BOLD << YELLOW << "nageoire de coef " << coef_nageoire << " donnée!" << RESET << std::endl;
   }

   int carapace_coin_flip = rand() % CARAPACE_RAND_MAX;
   if (carapace_coin_flip == 0) // alors on donne une carapace
   {
      coef_carapace = rand() % COEF_CARAPACE_MAX + 1;
      std::cout << BOLD << YELLOW << "carapace de coef " << coef_carapace << " donnée!" << RESET << std::endl;
   }
   
   int yeux_coin_flip = rand() % PROBA_SANS_YEUX;
   if (yeux_coin_flip > 0) // alors on a des yeux
   {
      yeux_detection = static_cast<double>(rand()) / RAND_MAX;
      yeux_distance_coef = (static_cast<double>(rand()) / RAND_MAX) * (1 - VUE_COEF_MIN) + VUE_COEF_MIN;
      
      double yeux_angle_coef = (static_cast<double>(rand()) / RAND_MAX) *  (1 - VUE_ANGLE_COEF_MIN) + VUE_ANGLE_COEF_MIN;
      yeux_angle = yeux_angle_coef * VUE_ANGLE_MAX;
   }

   int oreille_coin_flip = rand() % PROBA_SANS_OREILLES;
   if (oreille_coin_flip > 0) // alors on a des oreilles
   {
      oreille_detection = static_cast<double>(rand()) / RAND_MAX;
      oreille_distance_coef = (static_cast<double>(rand()) / RAND_MAX) * (1 - OUIE_COEF_MIN) + OUIE_COEF_MIN;
   }

   int camouflage_coin_flip = rand() % PROBA_CAMOUFLAGE;
   if (camouflage_coin_flip == 0)
   {
      camouflage_coef = (static_cast<double>(rand()) / RAND_MAX) * (CAMOUFLAGE_MAX - CAMOUFLAGE_MIN) + CAMOUFLAGE_MIN;
   }


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

   double camouflage_other = b.camouflage_coef;
   if (oreille_detection > camouflage_other)
   {
      return ( dist <= oreille_distance_coef * LIMITE_OUIE );
   }
   if (yeux_detection > camouflage_other)
   {
      double angle_other = 0;
      double delta_y = b.y - y;
      if (delta_y == 0)
      {
         angle_other = M_PI / 2;
      }
      else
      {
         angle_other = std::acos((b.x - x) / delta_y);
      }
      return (dist <= yeux_distance_coef * LIMITE_VUE) && (std::abs(angle_other - orientation) <= (yeux_angle/2));
   }
   return false;

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