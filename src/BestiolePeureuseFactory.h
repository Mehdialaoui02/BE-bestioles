#ifndef BESTIOLEPEUREUSEFACTORY
#define BESTIOLEPEUREUSEFACTORY

#include "Bestiole.h"
#include "BestioleFactory.h"

class BestiolePeureuseFactory : public BestioleFactory
{
public:
    std::shared_ptr<Bestiole> BestioleFactoryMethod( int frame_birth_ );
};

#endif