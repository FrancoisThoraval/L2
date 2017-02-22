all: main
	rm *.o

main: Produit main.cpp
	g++ -Wall -o programme Produit.o main.cpp

Produit: Produit.cpp
	g++ -Wall -c -o Produit.o Produit.cpp
