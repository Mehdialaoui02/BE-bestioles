#ifndef BESTIOLEGREGAIREFACTORY
#define BESTIOLEGREGAIREFACTORY

#include "Bestiole.h"
#include "BestioleFactory.h"

class BestioleGregaireFactory : public BestioleFactory
{
public:
    std::shared_ptr<Bestiole> BestioleFactoryMethod( int frame_birth_ );
};

#endif