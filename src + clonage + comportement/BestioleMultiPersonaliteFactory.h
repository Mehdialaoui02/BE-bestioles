#ifndef BESTIOLEMULTIPERSONALITEFACTORY
#define BESTIOLEMULTIPERSONALITEFACTORY

#include "Bestiole.h"
#include "BestioleFactory.h"

class BestioleMultiPersonaliteFactory : public BestioleFactory
{
public:
    std::shared_ptr<Bestiole> BestioleFactoryMethod( int frame_birth_ );
};

#endif