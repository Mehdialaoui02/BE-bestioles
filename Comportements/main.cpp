#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "BestioleGregaire.h"
#include "BestiolePeureuse.h"
#include "BestioleKamikaze.h"

#include <iostream>

using namespace std;


int main() {
    Aquarium ecosysteme(640, 480, 30);

    // Create instances using std::unique_ptr with new
    for (int i = 1; i <= 5; ++i) {
        ecosysteme.getMilieu().addMember(std::unique_ptr<Bestiole>(new Bestiole()));
    }

    // auto bestiole1 = std::unique_ptr<BestiolePeureuse>(new BestiolePeureuse());
    // ecosysteme.getMilieu().addMember(std::move(bestiole1));

    // auto bestiole2 = std::unique_ptr<BestioleKamikaze>(new BestioleKamikaze());
    // ecosysteme.getMilieu().addMember(std::move(bestiole2));

    auto bestiole3 = std::unique_ptr<BestioleGregaire>(new BestioleGregaire());
    ecosysteme.getMilieu().addMember(std::move(bestiole3));

    // Run the simulation
    ecosysteme.run();

    return 0;
}


