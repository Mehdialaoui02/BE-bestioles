#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "BestioleFactory.h"

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD "\033[1m"

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<std::shared_ptr<Bestiole>>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( std::map<std::string, int> global_variables, std::map<std::string, std::shared_ptr<BestioleFactory>> factories );

   void addMember( const std::shared_ptr<Bestiole>  b ) { listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height);}
   // void addMember( const std::unique_ptr<Bestiole>  b ) { b->initCoords(width, height); listeBestioles.push_back(std::move(b)); } ou mettre const std::unique_ptr<Bestiole> && b et mettre le move lors de l'appel
   int nbVoisins( const std::shared_ptr<Bestiole> b );

   void killBestiole(int identite);


};


#endif
