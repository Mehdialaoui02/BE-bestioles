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
   for ( IDecorator* bptr1 : listePtrBestioles )
   {
         for ( IDecorator* bptr2 : listePtrBestioles)
      {
         if (!(bptr1==bptr2)) {
            bptr1->jeTEntends(bptr2);
         }
       }

      bptr1->action( *this );
      bptr1->draw( *this );

   }

}

void Milieu::addMember(IDecorator* bestiole) {
   { 

      listeBestioles.push_back(*bestiole); 
      listePtrBestioles.push_back(bestiole);

      (listeBestioles.back()).initCoords(width, height);
      }
} 


int Milieu::nbVoisins(IDecorator* bestiole)
{

   int         nb = 0;

   for ( std::vector<IDecorator*>::iterator it = listePtrBestioles.begin() ; it != listePtrBestioles.end() ; ++it )
      if ( !(bestiole == *it) && (*bestiole).jeTeVois(*it) )
         ++nb;

   return nb;

}
