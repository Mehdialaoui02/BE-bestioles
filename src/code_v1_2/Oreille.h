#ifndef _Oreille_H_
#define _Oreille_H_

#include <iostream>
#include "Decorator.h"
#include "IDecorator.h"

using namespace std;

class Decorator;

class Oreille : public Decorator 
{

    private :
    static const long MAX_RAND = 1000000L;
    static const int MAX_DIST = 100;
    static const int MIN_DIST = 0;

    private :
    double rayon;
 
    public :

    Oreille(IDecorator* b);
    ~Oreille();

    bool jeTEntends(IDecorator* b);
};
#endif