#include "BestioleGregaire.h"

BestioleGregaire::BestioleGregaire( void ) : Bestiole()
{
    this->personalite = 1;
    std::cout << "const gregaire d'identité " << identite << std::endl;
    // T    p_color[] = { (T)50, (T)50, (T)50 };
    // this->couleur = p_color;
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( 204 );
    couleur[ 1 ] = static_cast<int>( 180 );
    couleur[ 2 ] = static_cast<int>( 73 );
}

BestioleGregaire::BestioleGregaire( int frame_birth_, int frame_age_ ) : BestioleGregaire()
{
    this->frame_birth = frame_birth_;
    this->frame_age = frame_age_;
}

BestioleGregaire::~BestioleGregaire( void )
{
    std::cout << "dest BestioleGregaire" << std::endl;
    // Bestiole::~Bestiole();
}

void BestioleGregaire::setDirection( Milieu &monMilieu )
{
    const std::vector<std::shared_ptr<Bestiole>> &bestioles = monMilieu.getBestioles();

    // Variables for calculating average direction
    double sumX = 0;
    double sumY = 0;
    int size = 0;
    double newOrient;

    for (const std::shared_ptr<Bestiole> &bPtr : bestioles) {
        Bestiole &b = *bPtr; // Dereference the smart pointer
        if (this != &b && this->jeTeVois(b)) {
            // Accumulate orientation for visible Bestioles
            sumX += b.getX();
            sumY += b.getY();
            size++;
        }
    }

    if (size != 0) {
        newOrient = 2 * M_PI - atan2((sumY / size - getY()), (sumX / size - getX()));
        orientation = newOrient;
    }
}

void BestioleGregaire::action( Milieu & monMilieu, int run_time, int comportement_cooldown )
{
    bool cd_exceeded = run_time - comportement_last_frame > comportement_cooldown;
    
    if (cd_exceeded)
    {
        comportement_last_frame = run_time;
        setDirection(monMilieu);
    }
    bouge(monMilieu.getWidth(),monMilieu.getHeight());
}