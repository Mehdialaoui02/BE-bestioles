#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "BestiolePeureuse.h"
#include "BestioleGregaire.h"
#include "BestioleKamikaze.h"
#include "BestiolePrevoyante.h"
#include "BestioleMultiPersonalite.h"

#include "BestiolePeureuseFactory.h"
#include "BestioleGregaireFactory.h"
#include "BestioleKamikazeFactory.h"
#include "BestiolePrevoyanteFactory.h"
#include "BestioleMultiPersonaliteFactory.h"

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

#define NB_BESTIOLES 100

using namespace std;


std::vector<std::string> split(const std::string& input, const std::string& delimiter) 
{
    std::regex regex(delimiter);
    std::sregex_token_iterator it(input.begin(), input.end(), regex, -1);
    std::sregex_token_iterator end;

    return {it, end};
}


void create_aquarium(Milieu& my_milieu, std::map<std::string, int> proba_cumsum, std::map<std::string, std::shared_ptr<BestioleFactory>> factories)
{

   for ( int i = 1; i <= proba_cumsum["nb_bestioles"]; ++i )
   {
      double proba_pop = rand() % 100;
      if (proba_pop < proba_cumsum["proba_cumsum_peureuse"])
      {
         my_milieu.addMember( factories["peureuse"]->BestioleFactoryMethod(0) );
      }
      else if (proba_pop < proba_cumsum["proba_cumsum_kamikaze"])
      {
         my_milieu.addMember( factories["kamikaze"]->BestioleFactoryMethod(0) );
      }
      else if (proba_pop < proba_cumsum["proba_cumsum_prevoyante"])
      {
         my_milieu.addMember( factories["prevoyante"]->BestioleFactoryMethod(0) );
      }
      else if (proba_pop < proba_cumsum["proba_cumsum_gregaire"])
      {
         my_milieu.addMember( factories["gregaire"]->BestioleFactoryMethod(0) );
      }
      else
      {
         my_milieu.addMember( factories["multipersonalite"]->BestioleFactoryMethod(0) );
      }
   }
}


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );
   std::map<std::string, int> tunable_variables;

   //factory init
   std::map<std::string, std::shared_ptr<BestioleFactory>> factories;
   factories["gregaire"] = std::make_shared<BestioleGregaireFactory>();
   factories["peureuse"] = std::make_shared<BestiolePeureuseFactory>();
   factories["kamikaze"] = std::make_shared<BestioleKamikazeFactory>();
   factories["prevoyante"] = std::make_shared<BestiolePrevoyanteFactory>();
   factories["multipersonalite"] = std::make_shared<BestioleMultiPersonaliteFactory>();

   std::string line;
   std::ifstream inputFile("config.dat");
   if (!inputFile.is_open())
   {
        std::cerr << "Unable to read file.\n";
        return 1;
   }

   while (std::getline(inputFile, line))
   {
      std::vector<std::string> result = split(line, ":");
      int i=0;
      std::string var_name;
      int value;
      for (const auto& token : result) 
      {
         if (i==1)
         {
            value = std::stoi(token);
         }
         else
         {
            var_name = token;
         }
         ++i;
      }
      i=0;
      tunable_variables[var_name] = value;
   }
    inputFile.close();

   create_aquarium(ecosysteme.getMilieu(), tunable_variables, factories);
   // for ( int i = 1; i <= NB_BESTIOLES; ++i )
   // {

   //    double proba_pop = rand() % 100;
   //    if (proba_pop < 30)
   //    {
   //       ecosysteme.getMilieu().addMember( PeurFacto.BestioleFactoryMethod() );
   //    }
   //    else if (proba_pop < 50)
   //    {
   //       ecosysteme.getMilieu().addMember( KamiFacto.BestioleFactoryMethod() );
   //    }
   //    else if (proba_pop < 55)
   //    {
   //       ecosysteme.getMilieu().addMember( PrevFacto.BestioleFactoryMethod() );
   //    }
   //    else
   //    {
   //       ecosysteme.getMilieu().addMember( GregFacto.BestioleFactoryMethod() );
   //    }
   // }
   
   ecosysteme.run(tunable_variables, factories);


   return 0;

}
