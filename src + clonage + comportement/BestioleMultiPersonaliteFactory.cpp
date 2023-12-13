#include "BestioleMultiPersonaliteFactory.h"
#include "BestioleMultiPersonalite.h"

std::shared_ptr<Bestiole> BestioleMultiPersonaliteFactory::BestioleFactoryMethod(int frame_birth_)
{
    int frame_age_ = 1000 + std::rand() % 501;
    return std::make_shared<BestioleMultiPersonalite>(frame_birth_, frame_age_);
}