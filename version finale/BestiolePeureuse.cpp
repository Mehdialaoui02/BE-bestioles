#include "BestiolePeureuse.h"

BestiolePeureuse::BestiolePeureuse( void ) : Bestiole()
{
    this->personalite = 2;
    DoubleVitesse = false;
    
    std::cout << "const peureuse d'identité " << identite << std::endl;
    // T    p_color[] = { (T)73, (T)180, (T)204 };
    // this->couleur = p_color;
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( 73 );
    couleur[ 1 ] = static_cast<int>( 180 );
    couleur[ 2 ] = static_cast<int>( 204 );
}

BestiolePeureuse::BestiolePeureuse( int frame_birth_, int frame_age_ ) : BestiolePeureuse()
{
    this->frame_birth = frame_birth_;
    this->frame_age = frame_age_;
}

BestiolePeureuse::~BestiolePeureuse( void )
{
    std::cout << "dest BestiolePeureuse" << std::endl;
    // delete [] couleur;
    // Bestiole::~Bestiole();
}


void BestiolePeureuse::set_direction( Milieu & monMilieu )
{
    const std::vector<std::shared_ptr<Bestiole>> &bestioles = monMilieu.getBestioles();
    
    int countVisible = 0;
    for (const std::shared_ptr<Bestiole> &bPtr : bestioles) 
    {
        const Bestiole &b = *bPtr; // Dereference the smart pointer
        if (this->jeTeVois(b)) 
        {
            countVisible++;
        }
    }

    if (countVisible >= 2) 
    {
        orientation = orientation - M_PI;
        DoubleVitesse = true;
        vitesse *= 2;
    }
}

void BestiolePeureuse::action( Milieu & monMilieu, int run_time, int comportement_cooldown ) 
{
    bool cd_exceeded = run_time - comportement_last_frame > comportement_cooldown;
    
    if (DoubleVitesse && cd_exceeded) 
    {
        vitesse = vitesse/2;
        DoubleVitesse = false;
    }

    if (cd_exceeded)
    {
        comportement_last_frame = run_time;
        set_direction(monMilieu);
    }

    bouge(monMilieu.getWidth(),monMilieu.getHeight());
}