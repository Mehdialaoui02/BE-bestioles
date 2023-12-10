#include "BestioleGregaire.h"

BestioleGregaire::BestioleGregaire( void ) : Bestiole()
{
    this->personalite = 1;
    std::cout << "const gregaire d'identité " << identite << std::endl;
    // T    p_color[] = { (T)50, (T)50, (T)50 };
    // this->couleur = p_color;
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( 204 );
    couleur[ 1 ] = static_cast<int>( 180 );
    couleur[ 2 ] = static_cast<int>( 73 );
}

BestioleGregaire::BestioleGregaire( int frame_birth_, int frame_age_ ) : BestioleGregaire()
{
    this->frame_birth = frame_birth_;
    this->frame_age = frame_age_;
}

BestioleGregaire::~BestioleGregaire( void )
{
    std::cout << "dest BestioleGregaire" << std::endl;
    // Bestiole::~Bestiole();
}