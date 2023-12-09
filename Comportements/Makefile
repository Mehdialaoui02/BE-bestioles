main : main.cpp Aquarium.o Bestiole.o Milieu.o BestioleGregaire.o BestiolePeureuse.o BestioleKamikaze.o BestiolePrevoyante.o BestioleMultiPerso.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o BestioleGregaire.o BestiolePeureuse.o BestioleKamikaze.o BestiolePrevoyante.o BestioleMultiPerso.o -I. -lwinpthread -lgdi32

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11 -c Aquarium.cpp -I.

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11 -c Bestiole.cpp -I.

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11 -c Milieu.cpp -I.

BestioleGregaire.o : BestioleGregaire.h BestioleGregaire.cpp
	g++ -Wall -std=c++11 -c BestioleGregaire.cpp -I.

BestiolePeureuse.o : BestiolePeureuse.h BestiolePeureuse.cpp
	g++ -Wall -std=c++11 -c BestiolePeureuse.cpp -I.
BestioleKamikaze.o : BestioleKamikaze.h BestioleKamikaze.cpp
	g++ -Wall -std=c++11 -c BestioleKamikaze.cpp -I.

BestiolePrevoyante.o : BestiolePrevoyante.h BestiolePrevoyante.cpp
	g++ -Wall -std=c++11 -c BestiolePrevoyante.cpp -I.

BestioleMultiPerso.o : BestioleMultiPerso.h BestioleMultiPerso.cpp
	g++ -Wall -std=c++11 -c BestioleMultiPerso.cpp -I.

clean:
	del *.o ; del main.exe
