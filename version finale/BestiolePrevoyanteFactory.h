#ifndef BESTIOLEPREVOYANTEFACTORY
#define BESTIOLEPREVOYANTEFACTORY

#include "Bestiole.h"
#include "BestioleFactory.h"

class BestiolePrevoyanteFactory : public BestioleFactory
{
public:
    std::shared_ptr<Bestiole> BestioleFactoryMethod( int frame_birth_ );
};

#endif