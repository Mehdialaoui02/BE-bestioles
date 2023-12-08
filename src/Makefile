main : main.cpp Aquarium.o BestiolePrevoyanteFactory.o BestioleGregaireFactory.o BestiolePeureuseFactory.o BestioleKamikazeFactory.o Bestiole.o BestiolePrevoyante.o BestioleKamikaze.o BestiolePeureuse.o BestioleGregaire.o Milieu.o
	g++ -Wall -std=c++17 -o main main.cpp Aquarium.o Bestiole.o BestiolePrevoyante.o BestioleKamikaze.o BestiolePeureuse.o BestioleGregaire.o Milieu.o BestiolePrevoyanteFactory.o BestioleGregaireFactory.o BestiolePeureuseFactory.o BestioleKamikazeFactory.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++17  -c Aquarium.cpp -I .

BestiolePrevoyanteFactory.o : BestioleFactory.h BestiolePrevoyanteFactory.h BestiolePrevoyanteFactory.cpp
	g++ -Wall -std=c++17  -c BestiolePrevoyanteFactory.cpp -I .

BestioleKamikazeFactory.o : BestioleFactory.h BestioleKamikazeFactory.h BestioleKamikazeFactory.cpp
	g++ -Wall -std=c++17  -c BestioleKamikazeFactory.cpp -I .

BestioleGregaireFactory.o : BestioleFactory.h BestioleGregaireFactory.h BestioleGregaireFactory.cpp
	g++ -Wall -std=c++17  -c BestioleGregaireFactory.cpp -I .

BestiolePeureuseFactory.o : BestioleFactory.h BestiolePeureuseFactory.h BestiolePeureuseFactory.cpp
	g++ -Wall -std=c++17  -c BestiolePeureuseFactory.cpp -I .


BestiolePrevoyante.o : BestiolePrevoyante.h BestiolePrevoyante.cpp
	g++ -Wall -std=c++17  -c BestiolePrevoyante.cpp -I .

BestioleKamikaze.o : BestioleKamikaze.h BestioleKamikaze.cpp
	g++ -Wall -std=c++17  -c BestioleKamikaze.cpp -I .

BestioleGregaire.o : BestioleGregaire.h BestioleGregaire.cpp
	g++ -Wall -std=c++17  -c BestioleGregaire.cpp -I .

BestiolePeureuse.o : BestiolePeureuse.h BestiolePeureuse.cpp
	g++ -Wall -std=c++17  -c BestiolePeureuse.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++17  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++17  -c Milieu.cpp -I .

clean:
	rm -rf *.o main

