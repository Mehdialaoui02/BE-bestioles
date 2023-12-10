#include "BestioleKamikazeFactory.h"
#include "BestioleKamikaze.h"

std::shared_ptr<Bestiole> BestioleKamikazeFactory::BestioleFactoryMethod(int frame_birth_)
{
    int frame_age_ = 1000 + std::rand() % 501;
    return std::make_shared<BestioleKamikaze>(frame_birth_, frame_age_);
}