#include "BestiolePeureuseFactory.h"
#include "BestiolePeureuse.h"

std::shared_ptr<Bestiole> BestiolePeureuseFactory::BestioleFactoryMethod(int frame_birth_)
{
    int frame_age_ = 1000 + std::rand() % 501;
    return std::make_shared<BestiolePeureuse>(frame_birth_, frame_age_);
}