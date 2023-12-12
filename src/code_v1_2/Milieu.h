#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "IDecorator.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class IDecorator;

class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<IDecorator>   listeBestioles;
   std::vector<IDecorator*>  listePtrBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember(IDecorator* bestiole);   
   int nbVoisins(IDecorator* bestiole);

};


#endif
