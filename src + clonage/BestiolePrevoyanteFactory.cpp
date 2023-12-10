#include "BestiolePrevoyanteFactory.h"
#include "BestiolePrevoyante.h"

std::shared_ptr<Bestiole> BestiolePrevoyanteFactory::BestioleFactoryMethod(int frame_birth_)
{
    int frame_age_ = 1000 + std::rand() % 501;
    return std::make_shared<BestiolePrevoyante>(frame_birth_, frame_age_);
}