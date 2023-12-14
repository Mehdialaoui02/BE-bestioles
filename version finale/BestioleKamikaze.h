#ifndef BESTIOLEKAMIKAZE
#define BESTIOLEKAMIKAZE

#include "Bestiole.h"
#include "Milieu.h"

class BestioleKamikaze: public Bestiole
{
public:
    BestioleKamikaze( void );
    BestioleKamikaze( int frame_birth_, int frame_age_ );
    ~BestioleKamikaze( void );

    void PlusProche(Milieu &monMilieu, int* xproche, int* yproche);
    void setDirection( Milieu & monMilieu );
    void action( Milieu & monMilieu, int run_time, int comportement_cooldown ) override;

};


#endif