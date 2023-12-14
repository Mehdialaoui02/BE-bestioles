#ifndef BESTIOLEMULTIPERSONALITE
#define BESTIOLEMULTIPERSONALITE

#include "Bestiole.h"
#include "Milieu.h"

class BestioleMultiPersonalite: public Bestiole
{
protected:
    int comportement;
    int step;
    std::shared_ptr<Bestiole> CurrentBestiole;

public:
    BestioleMultiPersonalite( void );
    BestioleMultiPersonalite( int frame_birth_, int frame_age_ );
    ~BestioleMultiPersonalite( void );

    void setComportement( void );       //  de la méthode action
    void setDirection( Milieu &milieu, int run_time, int comportement_cooldown );
    void action( Milieu & monMilieu, int run_time, int comportement_cooldown ) override;
};


#endif