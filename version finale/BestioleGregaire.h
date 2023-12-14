#ifndef BESTIOLEGREGAIRE
#define BESTIOLEGREGAIRE

#include "Bestiole.h"
#include "Milieu.h"

class BestioleGregaire: public Bestiole
{
public:
    BestioleGregaire( void );
    BestioleGregaire( int frame_birth_, int frame_age_ );
    ~BestioleGregaire( void );

    void setDirection(Milieu &monMilieu);       //  de la méthode action
    void action( Milieu & monMilieu, int run_time, int comportement_cooldown ) override;
};


#endif