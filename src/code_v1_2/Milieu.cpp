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
   

   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      //cout << "action : addr Bestiole : "<< &it << endl;
      it->action( *this );
      //cout << "end action"<< endl;
      //cout << "draw : addr Bestiole : "<< &it << endl;
      it->draw( *this );
      //cout << "end draw"<< endl;
      it->autoClone( *this );
      //cout << "end clone"<< endl;

   } // for

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

// void Milieu::autoClonage()
// {  

// int rdNb;

//    for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
//    {
//       rdNb = static_cast<int>( static_cast<double>( std::rand() )) % 1000 + 1;
//       if (rdNb == 1) {
//          //cout << "Auto clonage de Bestiole " << endl;
//          this->addMember(Bestiole()); // Appel du Copy construcor de Bestiole et ajout dans le milieu 
//       }
//    }

// }

  void Milieu::autoClonage(const Bestiole & b) 
  {
      listeBestioles.push_back(b);
      //listeBestioles.back().initCoords(width, height);
      //cout << "Liste Bestiole : "<< &listeBestioles << "\n" <<endl;   
  }