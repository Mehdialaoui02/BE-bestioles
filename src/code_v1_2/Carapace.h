#ifndef _Carapace_H_
#define _Carapace_H_

#include <iostream>
#include <cmath>

#include "Decorator.h"
#include "IDecorator.h"

using namespace std;

class Decorator;

class Carapace : public Decorator 
{

    private :
    static const long MAX_RAND = 1000000L;
    static const int MAX_VIT = 1;
    static const int MIN_VIT = 0;

    private :
    double coeff_vit;

    public :

    Carapace(IDecorator* b);
    ~Carapace();
};
#endif