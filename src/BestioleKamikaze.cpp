#include "BestioleKamikaze.h"

BestioleKamikaze::BestioleKamikaze( void ) : Bestiole()
{
    this->identite = 3;
    std::cout << "const kamikaze d'identité " << identite << std::endl;

    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( 153 );
    couleur[ 1 ] = static_cast<int>( 64 );
    couleur[ 2 ] = static_cast<int>( 102 );
}

BestioleKamikaze::BestioleKamikaze( int frame_birth_, int frame_age_ ) : BestioleKamikaze()
{
    this->frame_birth = frame_birth_;
    this->frame_age = frame_age_;
}

BestioleKamikaze::~BestioleKamikaze( void )
{
    std::cout << "dest BestioleKamikaze" << std::endl;
    // delete [] couleur;
    // Bestiole::~Bestiole();
}