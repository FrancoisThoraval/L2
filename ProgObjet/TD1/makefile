all: main
	rm *.o

main: HelloWorld Personne Passager Voiture main.cpp
	g++ -Wall -o programme Personne.o HelloWorld.o Passager.o Voiture.o main.cpp

HelloWorld: HelloWorld.cpp
	g++ -Wall -c -o HelloWorld.o HelloWorld.cpp

Personne: Personne.cpp
	g++ -Wall -c -o Personne.o Personne.cpp

Passager: Passager.cpp
	g++ -Wall -c -o Passager.o Passager.cpp

Voiture: Voiture.cpp
	g++ -Wall -c -o Voiture.o Voiture.cpp
