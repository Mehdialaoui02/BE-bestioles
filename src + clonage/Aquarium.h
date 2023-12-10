#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>
#include <map>
#include <string>
#include "BestioleFactory.h"

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu       * flotte;

   int            delay;

public :
   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );

   Milieu & getMilieu( void ) { return *flotte; }

   void run( std::map<std::string, int> global_variables, std::map<std::string, std::shared_ptr<BestioleFactory>> factories );

};


#endif
