#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Decorator.h"
#include "Oreille.h"

#include <iostream>

using namespace std;


int main()
{

    Aquarium ecosysteme( 640, 480, 30 );

    ecosysteme.getMilieu().addMember(Oreille(Bestiole()));
    ecosysteme.getMilieu().addMember(Oreille(Bestiole()));
    ecosysteme.getMilieu().addMember(Oreille(Bestiole()));
    ecosysteme.run();
   

    return 0;

}
