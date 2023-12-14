#include "Aquarium.h"

#include "Milieu.h"



Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}


void Aquarium::run( std::map<std::string, int> global_variables, std::map<std::string, std::shared_ptr<BestioleFactory>> factories )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {
      global_variables["run_time"] += 1;
      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) 
      {
         int frame_birth = global_variables["run_time"];
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         bool cooldown = (global_variables["run_time"] - global_variables["key_pushed_time"] >= global_variables["key_cooldown"]);
         if (cooldown)
         {
            global_variables["key_pushed_time"] = global_variables["run_time"];
         }
         else
         {
            cout << "key cooldown, please wait...\n";
         }
         if ((key() == 65456) && cooldown)
         {
            flotte->addMember(factories["peureuse"]->BestioleFactoryMethod(frame_birth));
            std::cout << CYAN << "Bestiole peureuse est apparue!" << RESET << std::endl;
         }
         if (key() == 65457 && cooldown)
         {
            flotte->addMember(factories["kamikaze"]->BestioleFactoryMethod(frame_birth));
            std::cout << RED << "Bestiole kamikaze est apparue!" << RESET << std::endl;
         }
         if (key() == 65458 && cooldown)
         {
            flotte->addMember(factories["prevoyante"]->BestioleFactoryMethod(frame_birth));
            std::cout << GREEN << "Bestiole prevoyante est apparue!" << RESET << std::endl;
         }
         if (key() == 65459 && cooldown)
         {
            flotte->addMember(factories["gregaire"]->BestioleFactoryMethod(frame_birth));
            std::cout << YELLOW << "Bestiole grégaire est apparue!" << RESET << std::endl;
         }
         if (key() == 65460 && cooldown)
         {
            flotte->addMember(factories["multipersonalite"]->BestioleFactoryMethod(frame_birth));
            std::cout << MAGENTA << "Bestiole multi personalité est apparue!" << RESET << std::endl;
         }
         if (key() == 65461 && cooldown)
         {
            flotte->killBestiole(1);
         }
         if (key() == 65462 && cooldown)
         {
            flotte->killBestiole(2);
         }
         if (key() == 65463 && cooldown)
         {
            flotte->killBestiole(3);
         }
         if (key() == 65464 && cooldown)
         {
            flotte->killBestiole(4);
         }
         if (key() == 65465 && cooldown)
         {
            flotte->killBestiole(5);
         }
         if ( is_keyESC() ) close();
      }

      flotte->step(global_variables, factories);
      display( *flotte );

      wait( delay );

   } // while

}
