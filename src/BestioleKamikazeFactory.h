#ifndef BESTIOLEKAMIKAZEFACTORY
#define BESTIOLEKAMIKAZEFACTORY

#include "Bestiole.h"
#include "BestioleFactory.h"

class BestioleKamikazeFactory : public BestioleFactory
{
public:
    std::shared_ptr<Bestiole> BestioleFactoryMethod( int frame_birth_ );
};

#endif