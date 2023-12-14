#include "BestioleGregaireFactory.h"
#include "BestioleGregaire.h"

std::shared_ptr<Bestiole> BestioleGregaireFactory::BestioleFactoryMethod(int frame_birth_)
{
    int frame_age_ = 1000 + std::rand() % 501;
    return std::make_shared<BestioleGregaire>(frame_birth_, frame_age_);
}