#ifndef _Oreille_H_
#define _Oreille_H_

#include <iostream>
#include "Decorator.h"

using namespace std;

class Decorator;

class Oreille : public Decorator 
{

    private :
    static const long MAX_RAND = 1000000L;
    static const int MAX_VUE = 100;
    static const int MIN_VUE = 0;
    static const int MIN_DETECTION = 0;
    static const int MAX_DETECTION = 0;

    private :
    double rayon;
 
    public :

    Oreille(const Bestiole & b);
    ~Oreille();

    bool jeTEntends(const Bestiole & b);
    double dist(const Bestiole & b);
    bool detecter(const Bestiole & b);
    void action( Milieu & monMilieu);
    void draw( UImg & support );
    bool jeTeVois( const Bestiole & b ) const;
    void initCoords( int xLim, int yLim );
};
#endif