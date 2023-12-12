#ifndef _Nageoire_H_
#define _Nageoire_H_

#include <iostream>
#include <cmath>

#include "Decorator.h"
#include "IDecorator.h"

using namespace std;

class Decorator;

class Nageoire : public Decorator 
{

    private :
    static const long MAX_RAND = 1000000L;
    static const int MAX_VIT = 100;
    static const int MIN_VIT = 1;

    private :
    double coeff_vit;

    public :

    Nageoire(IDecorator* b);
    ~Nageoire();
};
#endif