#ifndef BESTIOLEPEUREUSE
#define BESTIOLEPEUREUSE

#include "Bestiole.h"

class BestiolePeureuse: public Bestiole
{
public:
    BestiolePeureuse( void );
    BestiolePeureuse( int frame_birth_, int frame_age_ );
    ~BestiolePeureuse( void );

};


#endif