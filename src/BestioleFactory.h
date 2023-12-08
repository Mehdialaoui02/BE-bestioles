#ifndef BESTIOLEFACTORY
#define BESTIOLEFACTORY

#include <iostream>
#include <memory>

#include "Bestiole.h"


class BestioleFactory
{
public:
    virtual std::shared_ptr<Bestiole> BestioleFactoryMethod( int frame_birth_ ) = 0;
};

#endif