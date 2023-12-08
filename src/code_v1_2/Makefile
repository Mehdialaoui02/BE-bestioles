all : test_oreille main

main : main.cpp Aquarium.o Bestiole.o Milieu.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o -I . -lX11 -lpthread

test_oreille : test_oreille.cpp Aquarium.o Bestiole.o Milieu.o Oreille.o Decorator.o
	g++ -Wall -std=c++11 -o test_oreille test_oreille.cpp Aquarium.o Bestiole.o Milieu.o Oreille.o Decorator.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Oreille.o : Oreille.h Oreille.cpp Decorator.h
	g++ -Wall -std=c++11  -c Oreille.cpp -I .

Decorator.o : Decorator.h Decorator.cpp Bestiole.h
	g++ -Wall -std=c++11  -c Decorator.cpp -I .

clean:
	rm -rf *.o main

