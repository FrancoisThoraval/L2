all: main
	rm *.o

main: adresse adherent main.cpp
	g++ -Wall -o programme adresse.o adherent.o main.cpp

adherent: adherent.cpp
	g++ -Wall -c -o adherent.o adherent.cpp

adresse: adresse.cpp
	g++ -Wall -c -o adresse.o adresse.cpp
