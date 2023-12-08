#include "BestiolePrevoyante.h"

BestiolePrevoyante::BestiolePrevoyante( void ) : Bestiole()
{
    this->identite = 4;
    std::cout << "const prevoyante d'identité " << identite << std::endl;

    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( 40 );
    couleur[ 1 ] = static_cast<int>( 163 );
    couleur[ 2 ] = static_cast<int>( 116 );
}

BestiolePrevoyante::BestiolePrevoyante( int frame_birth_, int frame_age_ ) : BestiolePrevoyante()
{
    this->frame_birth = frame_birth_;
    this->frame_age = frame_age_;
}

BestiolePrevoyante::~BestiolePrevoyante( void )
{
    std::cout << "dest BestiolePrevoyante" << std::endl;
}