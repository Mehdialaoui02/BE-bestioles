#include "BestioleMultiPersonalite.h"

#include "BestiolePeureuseFactory.h"
#include "BestioleGregaireFactory.h"
#include "BestioleKamikazeFactory.h"
#include "BestiolePrevoyanteFactory.h"


BestioleMultiPersonalite::BestioleMultiPersonalite( void ) : Bestiole()
{
    BestioleGregaireFactory gregaire_factory;
    
    this->step = 0;
    this->comportement = 0;
    this->personalite = 5;
    
    CurrentBestiole = gregaire_factory.BestioleFactoryMethod(0);
    
    std::cout << "const multi personalité d'identité " << identite << std::endl;

    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( 100 );
    couleur[ 1 ] = static_cast<int>( 45 );
    couleur[ 2 ] = static_cast<int>( 173 );
}

BestioleMultiPersonalite::BestioleMultiPersonalite( int frame_birth_, int frame_age_ ) : BestioleMultiPersonalite()
{
    this->frame_birth = frame_birth_;
    this->frame_age = frame_age_;
}

BestioleMultiPersonalite::~BestioleMultiPersonalite( void )
{
    std::cout << "dest BestioleMultiPersonalite" << std::endl;
}

void BestioleMultiPersonalite::setComportement( void )
{
    // Store the current position before changing behavior
    int originalX = x;
    int originalY = y;
    BestioleGregaireFactory gregaire_factory;
    BestiolePeureuseFactory peureuse_factory;
    BestioleKamikazeFactory kamikaze_factory;
    BestiolePrevoyanteFactory prevoyante_factory;

    switch (comportement) 
    {
    case 0:
        CurrentBestiole = gregaire_factory.BestioleFactoryMethod(0);
        break;

    case 1:
        CurrentBestiole = kamikaze_factory.BestioleFactoryMethod(0);
        break;

    case 2:
        CurrentBestiole = peureuse_factory.BestioleFactoryMethod(0);
        break;

    case 3:
        CurrentBestiole = prevoyante_factory.BestioleFactoryMethod(0);
        break;

    default:
        CurrentBestiole = gregaire_factory.BestioleFactoryMethod(0);
    }

    CurrentBestiole->setX(originalX);
    CurrentBestiole->setY(originalY);
}

void BestioleMultiPersonalite::setDirection( Milieu & monMilieu, int run_time, int comportement_cooldown )
{
    // int originalX = x;
    // int originalY = y;

    CurrentBestiole->action(monMilieu, run_time, comportement_cooldown);

    orientation = CurrentBestiole->getOrientation();

    x = CurrentBestiole->getX();
    y = CurrentBestiole->getY();
    // CurrentBestiole->setX(originalX);
    // CurrentBestiole->setY(originalY);
}

void BestioleMultiPersonalite::action( Milieu & monMilieu, int run_time, int comportement_cooldown )
{
    step++;
    // int originalX = x;
    // int originalY = y;
    if (step == 150) 
    {
        std::cout << "Une bestiole change de personalité!\n";
        setComportement();
        
        T* bestiole_couleur = CurrentBestiole->getCouleur();
        couleur [ 0 ] = bestiole_couleur [ 0 ];
        couleur [ 1 ] = bestiole_couleur [ 1 ];
        couleur [ 2 ] = bestiole_couleur [ 2 ];

        vitesse = 7;

        if (comportement < 3) 
        {
            comportement++;
        } 
        else 
        {
            comportement = 0;
        }

        step = 0;
    }

    setDirection(monMilieu, run_time, comportement_cooldown);
    // bouge(monMilieu.getWidth(), monMilieu.getHeight());

    // CurrentBestiole->setX(originalX);
    // CurrentBestiole->setY(originalY);
}