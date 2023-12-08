#ifndef DECOBEST
#define DECOBEST

#include "Bestiole.h"

using namespace std;

class Bestiole;

class Decorator: public Bestiole 
{

    protected :
    
    Bestiole*       bestiole;

    public :

    Decorator(const Bestiole & b);
    virtual ~Decorator();

    void action( Milieu & monMilieu);
    void draw( UImg & support );
    double dist( const Bestiole & b );
    bool jeTeVois( const Bestiole & b ) const;
    bool jeTEntends( const Bestiole & b );
    bool detecter( const Bestiole & b );
    void initCoords( int xLim, int yLim );
};

#endif