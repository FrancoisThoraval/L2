all : arbre.o foret.o main.o
	g++ arbre.o foret.o main.o -o programme
	rm *.o

main : main.o
	g++ -c main.cpp -Wall
arbre : arbre.o
	g++ -c arbre.cpp -Wall

foret : foret.o
	g++ -c foret.cpp -Wall
