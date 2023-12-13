#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Decorator.h"
#include "Oreille.h"
#include "Nageoire.h"
#include "Carapace.h"
#include "Camouflage.h"
#include "Yeux.h"

#include <iostream>

using namespace std;


int main()
{

    Aquarium ecosysteme( 640, 480, 30 );

    Bestiole* b1 = new Bestiole();
    Bestiole* b2 = new Bestiole();
    Bestiole* b3 = new Bestiole();
    Bestiole* b4 = new Bestiole();
    Bestiole* b5 = new Bestiole();

    Oreille* o = new Oreille(b1);
    Yeux* y = new Yeux(b5);

    std::cout<<"Test nageoire :"<<endl;
    std::cout<<"vitesse sans nageoire :"<<b2->getVitesse()<<endl;
    Nageoire* n = new Nageoire(b2);
    std::cout<<"vitesse avec nageoire :"<<n->getVitesse()<<endl;

    std::cout<<"Test carapace :"<<endl;
    std::cout<<"vitesse sans carapace :"<<b3->getVitesse()<<endl;
    Carapace* c1 = new Carapace(b3);
    std::cout<<"vitesse avec carapace :"<<c1->getVitesse()<<endl;

    std::cout<<"Test camouflage :"<<endl;
    std::cout<<"camouflage sans camouflage :"<<b4->getCamouflage()<<endl;
    Camouflage* c2 = new Camouflage(b4);
    std::cout<<"camouflage avec camouflage :"<<c2->getCamouflage()<<endl;


    ecosysteme.getMilieu().addMember(o);
    ecosysteme.getMilieu().addMember(y);
    ecosysteme.run();
   

    return 0;

}
