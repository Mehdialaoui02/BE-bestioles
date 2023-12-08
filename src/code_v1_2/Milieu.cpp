#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <memory>


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
   for ( std::vector<std::shared_ptr<Bestiole>>::iterator it = listePtrBestioles.begin() ; it != listePtrBestioles.end() ; ++it )
   {
         for ( std::vector<Bestiole>::iterator it2 = listeBestioles.begin() ; it2 != listeBestioles.end() ; ++it2 )
      {
         /*(*it)->jeTEntends(*it2);*/
       }

      (*it)->action( *this );
      (*it)->draw( *this );

   }

}

void Milieu::addMember( const Bestiole & b ) {
   { 
      auto sp1 = make_shared<Bestiole>(b);

      listeBestioles.push_back(b); 
      /*listePtrBestioles.push_back(sp1);*/

      (listeBestioles.back()).initCoords(width, height); 
      }
} 


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}
