#ifndef BESTIOLEPEUREUSE
#define BESTIOLEPEUREUSE

#include "Bestiole.h"

#include "Milieu.h"

class BestiolePeureuse: public Bestiole
{
protected:
    bool DoubleVitesse;

public:
    BestiolePeureuse( void );
    BestiolePeureuse( int frame_birth_, int frame_age_ );
    ~BestiolePeureuse( void );

    void set_direction( Milieu & monMilieu );
    void action( Milieu & monMilieu, int run_time, int comportement_cooldown ) override;
};


#endif