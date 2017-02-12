all: main
	rm *.o

main: Avion TourDeControle main.cpp
	g++ -Wall -o programme Avion.o TourDeControle.o main.cpp

Avion: Avion.cpp
	g++ -Wall -c -o Avion.o Avion.cpp

TourDeControle: TourDeControle.cpp
	g++ -Wall -c -o TourDeControle.o TourDeControle.cpp
