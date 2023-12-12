all : test_oreille main

main : main.cpp Aquarium.o Milieu.o IDecorator.o Oreille.o Nageoire.o Carapace.o Camouflage.o Yeux.o Bestiole.o Decorator.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Milieu.o IDecorator.o Oreille.o Nageoire.o Carapace.o Camouflage.o Yeux.o Bestiole.o Decorator.o -I . -lX11 -lpthread

test_oreille : test_oreille.cpp Aquarium.o Milieu.o IDecorator.o Oreille.o Nageoire.o Carapace.o Camouflage.o Yeux.o Bestiole.o Decorator.o
	g++ -Wall -std=c++11 -o test_oreille test_oreille.cpp Aquarium.o Milieu.o IDecorator.o Oreille.o Nageoire.o Carapace.o Camouflage.o Yeux.o Bestiole.o Decorator.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp IDecorator.o Milieu.o
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Nageoire.o : Nageoire.h Nageoire.cpp Decorator.o
	g++ -Wall -std=c++11  -c Nageoire.cpp Decorator.o -I .

Carapace.o : Carapace.h Carapace.cpp Decorator.o
	g++ -Wall -std=c++11  -c Carapace.cpp Decorator.o -I .

Camouflage.o : Camouflage.h Camouflage.cpp Decorator.o
	g++ -Wall -std=c++11  -c Camouflage.cpp Decorator.o -I .

Yeux.o : Yeux.h Yeux.cpp Decorator.o
	g++ -Wall -std=c++11  -c Yeux.cpp Decorator.o -I .

Oreille.o : Oreille.h Oreille.cpp Decorator.o
	g++ -Wall -std=c++11  -c Oreille.cpp Decorator.o -I .

Decorator.o : Decorator.h Decorator.cpp IDecorator.o
	g++ -Wall -std=c++11  -c Decorator.cpp -I .

IDecorator.o : IDecorator.h IDecorator.cpp Milieu.o
	g++ -Wall -std=c++11 -c IDecorator.cpp -I .

clean:
	rm -rf *.o main

