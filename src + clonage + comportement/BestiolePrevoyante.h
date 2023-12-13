#ifndef BESTIOLEPREVOYANTE
#define BESTIOLEPREVOYANTE

#include "Bestiole.h"
#include "Milieu.h"

class BestiolePrevoyante: public Bestiole
{
public:
    BestiolePrevoyante( void );
    BestiolePrevoyante( int frame_birth_, int frame_age_ );
    ~BestiolePrevoyante( void );

    void setDirection( Milieu &milieu );
    void action( Milieu & monMilieu, int run_time, int comportement_cooldown ) override;
};


#endif