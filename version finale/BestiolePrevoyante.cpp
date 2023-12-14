#include "BestiolePrevoyante.h"

BestiolePrevoyante::BestiolePrevoyante( void ) : Bestiole()
{
    this->personalite = 4;
    std::cout << "const prevoyante d'identité " << identite << std::endl;

    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( 40 );
    couleur[ 1 ] = static_cast<int>( 163 );
    couleur[ 2 ] = static_cast<int>( 116 );
}

BestiolePrevoyante::BestiolePrevoyante( int frame_birth_, int frame_age_ ) : BestiolePrevoyante()
{
    this->frame_birth = frame_birth_;
    this->frame_age = frame_age_;
}

BestiolePrevoyante::~BestiolePrevoyante( void )
{
    std::cout << "dest BestiolePrevoyante" << std::endl;
}

void BestiolePrevoyante::setDirection( Milieu & milieu )
{
    const std::vector<std::shared_ptr<Bestiole>> &bestioles = milieu.getBestioles();

    // Variables for calculating average direction
    double sumX = 0;
    double sumY = 0;
    int size = 0;
    double newOrient;

    for (const std::shared_ptr<Bestiole> &bPtr : bestioles) 
    {
        Bestiole &b = *bPtr; // Dereference the smart pointer
        
        if (this != &b && this->jeTeVois(b)) 
        {
            sumX += b.getX();
            sumY += b.getY();
            size++;
        }
    }

    if (size != 0) 
    {

        if (atan2((sumY / size - getY()), (sumX / size - getX())) != 0) 
        {
            newOrient =  M_PI - atan2((sumY / size - y), (sumX / size - x));
            orientation = newOrient;
        } 

        else 
        {
            orientation = 2*M_PI + atan2((milieu.getHeight()/2 - y), (milieu.getWidth()/2 - x));
        }
    }
}

void BestiolePrevoyante::action( Milieu & monMilieu, int run_time, int comportement_cooldown )
{
    setDirection(monMilieu);
    bouge(monMilieu.getWidth(), monMilieu.getHeight());
}