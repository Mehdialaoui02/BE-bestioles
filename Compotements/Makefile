main : main.cpp Aquarium.o Bestiole.o Milieu.o BestioleGregaire.o BestiolePeureuse.o BestioleKamikaze.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o BestioleGregaire.o BestiolePeureuse.o BestioleKamikaze.o -I. -lwinpthread -lgdi32

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


clean:
	del *.o ; del main.exe
