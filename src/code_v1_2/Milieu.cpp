#include "Milieu.h"

#include <cstdlib>
#include <cmath>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   std::vector<Bestiole> tempClonage; //Liste de bestioles à cloner 

   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      it->action( *this );
      it->draw( *this );

      int rdNb = static_cast<int>( static_cast<double>( std::rand() )) % 1000 + 1;
      if (rdNb == 1) {
           cout << "Auto clonage de Bestiole n°"<< it->getIdentite() << endl;
           tempClonage.push_back(*it); // Appel du Copy construcor de Bestiole et ajout dans le milieu
           
      }

   } 
   listeBestioles.insert(listeBestioles.end(), tempClonage.begin(), tempClonage.end()); //concatenation de la liste de bestioles a cloner dans la liste des bestioles dans le milieu 


}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}

 void Milieu::addMember(const Bestiole & b) 
  {
      cout << "addMember" << endl;
      listeBestioles.push_back(b); 
      cout << "pushed back" << endl; 
      listeBestioles.back().initCoords(width, height); 
  }
