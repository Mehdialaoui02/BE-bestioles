#include "BestioleKamikaze.h"
#include <cmath>

BestioleKamikaze::BestioleKamikaze( void ) : Bestiole()
{
    this->personalite = 3;
    std::cout << "const kamikaze d'identité " << identite << std::endl;

    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( 153 );
    couleur[ 1 ] = static_cast<int>( 64 );
    couleur[ 2 ] = static_cast<int>( 102 );
}

BestioleKamikaze::BestioleKamikaze( int frame_birth_, int frame_age_ ) : BestioleKamikaze()
{
    this->frame_birth = frame_birth_;
    this->frame_age = frame_age_;
}

BestioleKamikaze::~BestioleKamikaze( void )
{
    std::cout << "dest BestioleKamikaze" << std::endl;
    // delete [] couleur;
    // Bestiole::~Bestiole();
}

void BestioleKamikaze::PlusProche(Milieu &monMilieu, int* xproche, int* yproche)
{
    const std::vector<std::shared_ptr<Bestiole>> &bestioles = monMilieu.getBestioles();
    *xproche = -1;
    *yproche = -1;

    double distanceMin = 100000;

    for (const std::shared_ptr<Bestiole> &bPtr : bestioles) 
    {
        // calculer la distance entre b et chaque autre bestiole
        Bestiole &b = *bPtr; // Dereference the smart pointer
        double distance = std::sqrt(std::pow(x - b.getX(), 2) + std::pow(y - b.getY(), 2));
        
        if (this != &b && this->jeTeVois(b)) 
        {
            if (distance < distanceMin && distance != 0) 
            {
                distanceMin = distance;
                *xproche = b.getX(); 
                *yproche = b.getY();
            }
        }
    }
}

void BestioleKamikaze::setDirection( Milieu & monMilieu )
{
    // Obtenir la bestiole la plus proche
    int xproche;
    int yproche;
    this->PlusProche(monMilieu,&xproche,&yproche);

    // couleur[ 0 ] = static_cast<int>( 40 );
    // couleur[ 1 ] = static_cast<int>( 163 );
    // couleur[ 2 ] = static_cast<int>( 116 );

    double newOrient;
    if (xproche != -1 || yproche != -1) 
    {
        if (xproche - x == 0) 
        {
            newOrient = 0;
        } 
        
        else 
        {
            newOrient = - std::atan2((yproche - y) , (xproche - x));
            orientation = newOrient;
        }
    }
}

void BestioleKamikaze::action( Milieu & monMilieu, int run_time, int comportement_cooldown )
{
    bool cd_exceeded = run_time - comportement_last_frame > comportement_cooldown / 10;

    if (cd_exceeded)
    {
        comportement_last_frame = run_time;
        this->setDirection(monMilieu);
    }
    bouge(monMilieu.getWidth(),monMilieu.getHeight());
}