#ifndef _Yeux_H_
#define _Yeux_H_

#include <iostream>
#include <cmath>

#include "Decorator.h"
#include "IDecorator.h"

using namespace std;

class Decorator;

class Yeux : public Decorator 
{

    private :
    static const long MAX_RAND = 1000000L;
    static const int MAX_DIST = 100;
    static const int MIN_DIST = 0;
    static const int MAX_ANGLE = 2 * M_PI;
    static const int MIN_ANGLE = 0;


    private :
    double rayon;
    double angle;


    public :

    Yeux(IDecorator* b);
    ~Yeux();

    bool jeTeVois(IDecorator* b);
};
#endif