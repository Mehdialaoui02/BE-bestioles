#ifndef _Camouflage_H_
#define _Camouflage_H_

#include <iostream>
#include <cmath>

#include "Decorator.h"
#include "IDecorator.h"

using namespace std;

class Decorator;

class Camouflage : public Decorator 
{

    private :
    static const long MAX_RAND = 1000000L;
    static const int MAX_CAMOUFLAGE = 1;
    static const int MIN_CAMOUFLAGE = 0;


    private :
    double camouflage;

    public :

    Camouflage(IDecorator* b);
    ~Camouflage();
};
#endif