#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<std::unique_ptr<Bestiole>> listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };
   const std::vector<std::unique_ptr<Bestiole>>& getBestioles(void) const { return listeBestioles; }

   void step( void );

   void addMember(std::unique_ptr<Bestiole> b) {
    listeBestioles.push_back(std::move(b));  // Use std::move for transferring ownership
    listeBestioles.back()->initCoords(width, height);  // Dereference the pointer before calling initCoords
}
   int nbVoisins( const Bestiole & b );

};


#endif
