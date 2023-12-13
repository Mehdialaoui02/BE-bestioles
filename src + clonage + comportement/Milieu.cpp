#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include <cmath>


int birth_time = 0;


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

bool int_not_in_vector(std::vector<int> my_vector, int element)
{
   for (size_t i=0; i < my_vector.size(); i++)
   {
      if (my_vector[i] == element)
      {
         return false;
      }
   }
   return true;
}

void Milieu::step( std::map<std::string, int> global_variables, std::map<std::string, std::shared_ptr<BestioleFactory>> factories )
{
   // birth_time += 1;
   double proba_pop = std::rand() % global_variables["spontaneous_birth_proba"];

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   int nb_dead_bestioles = 0;
   std::vector<std::shared_ptr<Bestiole>> maj_bestioles;
   std::vector<std::shared_ptr<Bestiole>> maj_bestioles_collision;
   std::vector<std::shared_ptr<Bestiole>> maj_bestioles_clonage;
   
   std::map<int, std::string> factory_translation;
   factory_translation[1] = "gregaire";
   factory_translation[2] = "peureuse";
   factory_translation[3] = "kamikaze";
   factory_translation[4] = "prevoyante";
   factory_translation[5] = "multipersonalite";

// COMPORTEMENT BASIQUE DES BESTIOLES
   for ( const auto& element : listeBestioles )
   {
      element->action( *this, global_variables["run_time"], global_variables["comportement_cooldown"] );
      element->draw( *this );

      if (element->is_dead(global_variables["run_time"]))
      {
         nb_dead_bestioles += 1;
      }

      // CLONAGE PART 1
      size_t n = listeBestioles.size();
      int rand_max_fit = static_cast<int>(n * global_variables["clonage_rand_max"]);
      double clonage_coin_flip = std::rand() % rand_max_fit;
      if (clonage_coin_flip == 0)
      {
         cout << BOLD << CYAN << "une bestiole vient de se cloner!" << RESET << endl;
         maj_bestioles_clonage.push_back(factories[factory_translation[element->getPersonalite()]]->BestioleFactoryMethod(global_variables["run_time"]));
         maj_bestioles_clonage.back()->initClonage(global_variables["run_time"], element->getX(), element->getY(), getWidth());
      }
   } // for

// MORT DES BESTIOLES PAR AGE
   if (nb_dead_bestioles > 0)
   {
      for ( const auto& element : listeBestioles )
      {
         if (!element->is_dead(global_variables["run_time"]))
         {
            maj_bestioles.push_back(element);
         }
         else
         {
            cout << BOLD << RED << "une bestiole vient de mourir!" << RESET << endl;
         }
      }
      listeBestioles = maj_bestioles;
   }

// GESTION DE LA COLLISION
   std::vector<int> bestiole_dead_collision_index;
   for (size_t i = 0; i < listeBestioles.size(); i++)
   {
      for (size_t j = i+1; j < listeBestioles.size(); j++)
      {
         int collision_last_frame_ =  listeBestioles[i]->getCollisionLastFrame();
         if (listeBestioles[i]->collision(listeBestioles[j]) && (global_variables["run_time"] - collision_last_frame_) > global_variables["collision_cool_down"])
         {
            listeBestioles[i]->setCollisionLastFrame(global_variables["run_time"]);
            double coin_flip_i = std::rand() % global_variables["collision_rand_max"];
            double coin_flip_j = std::rand() % global_variables["collision_rand_max"];
            bool deces = false;
            if (coin_flip_i < global_variables["collision_threashold"])
            {
               if (int_not_in_vector(bestiole_dead_collision_index, i))
               {
                  bestiole_dead_collision_index.push_back(i);
               }
               deces = true;
            }
            if (coin_flip_j < global_variables["collision_threashold"])
            {
               if (int_not_in_vector(bestiole_dead_collision_index, j))
               {
                  bestiole_dead_collision_index.push_back(j);
               }
               deces = true;
            }
            if (!deces)
            {
               listeBestioles[i]->after_collision(listeBestioles[j]);
            }
         }
      }
   }

   if (bestiole_dead_collision_index.size() != 0)
   {
      for (size_t i = 0; i < listeBestioles.size(); i++)
      {
         if (int_not_in_vector(bestiole_dead_collision_index, i))
         {
            maj_bestioles_collision.push_back(listeBestioles[i]);
         }
         else
         {
            cout << BOLD << RED << "une bestiole vient de mourir par collision!" << RESET << endl;
         }
      }
      listeBestioles = maj_bestioles_collision;
   }

// CLONAGE MAJ
   for (size_t i=0; i<maj_bestioles_clonage.size(); i++)
   {
      listeBestioles.push_back(maj_bestioles_clonage[i]);
   }

// NAISSANCE SPONTANEE
   if (proba_pop == 0)
   {
      cout << MAGENTA << "une bestiole est apparue spontanément!" << RESET << std::endl;
      double local_coin_flip = std::rand() % 100;
      if (local_coin_flip < global_variables["proba_cumsum_peureuse"])
      {
         addMember( factories["peureuse"]->BestioleFactoryMethod(global_variables["run_time"]) );
         cout << CYAN << "(peureuse) birth = " << global_variables["run_time"] << RESET << endl;
      }
      else if (local_coin_flip < global_variables["proba_cumsum_kamikaze"])
      {
         addMember( factories["kamikaze"]->BestioleFactoryMethod(global_variables["run_time"]) );
         cout << RED << "(kamikaze) birth = " << global_variables["run_time"] << RESET << endl;
      }
      else if (local_coin_flip < global_variables["proba_cumsum_prevoyante"])
      {
         addMember( factories["prevoyante"]->BestioleFactoryMethod(global_variables["run_time"]) );
         cout << GREEN << "(prevoyante) birth = " << global_variables["run_time"] << RESET << endl;
      }
      else if (local_coin_flip < global_variables["proba_cumsum_gregaire"])
      {
         addMember( factories["gregaire"]->BestioleFactoryMethod(global_variables["run_time"]) );
         cout << YELLOW << "(grégaire) birth = " << global_variables["run_time"] << RESET << endl;
      }
      else
      {
         addMember( factories["multipersonalite"]->BestioleFactoryMethod(global_variables["run_time"]) );
         cout << MAGENTA << "(multi personalité) birth = " << global_variables["run_time"] << RESET << endl;
      }
   }
}


int Milieu::nbVoisins( const std::shared_ptr<Bestiole> b )
{

   int         nb = 0;


   for ( const auto& element : listeBestioles )
      if ( !(b == element) && b->jeTeVois(*element) )
         ++nb;

   return nb;

}

void Milieu::killBestiole(int identite)
{
   std::map<int, std::string> bestiole_type;
   bestiole_type[1] = "grégaire";
   bestiole_type[2] = "peureuse";
   bestiole_type[3] = "kamikaze";
   bestiole_type[4] = "prévoyante";
   bestiole_type[5] = "multi personalité";

   int kill_count = 0;
   std::vector<std::shared_ptr<Bestiole>> maj_bestioles;
   for ( const auto& element : listeBestioles )
   {
      if (element->getIdentite() == identite && kill_count == 0)
      {
         kill_count += 1;
      }
      else
      {
         maj_bestioles.push_back(element);
      }
   }
   if (kill_count > 0)
   {
      cout << BOLD << RED << "une bestiole vient de mourir!" << RESET << endl;
   }
   else
   {
      cout << BOLD << RED << "pas de bestioles de type " << bestiole_type[identite] << " à tuer!" << RESET << endl;
   }
   listeBestioles = maj_bestioles;
}