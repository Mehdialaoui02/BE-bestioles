#include "BestiolePeureuse.h"

BestiolePeureuse::BestiolePeureuse( void ) : Bestiole()
{
    this->personalite = 2;
    
    std::cout << "const peureuse d'identité " << identite << std::endl;
    // T    p_color[] = { (T)73, (T)180, (T)204 };
    // this->couleur = p_color;
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( 73 );
    couleur[ 1 ] = static_cast<int>( 180 );
    couleur[ 2 ] = static_cast<int>( 204 );
}

BestiolePeureuse::BestiolePeureuse( int frame_birth_, int frame_age_ ) : BestiolePeureuse()
{
    this->frame_birth = frame_birth_;
    this->frame_age = frame_age_;
}

BestiolePeureuse::~BestiolePeureuse( void )
{
    std::cout << "dest BestiolePeureuse" << std::endl;
    // delete [] couleur;
    // Bestiole::~Bestiole();
}