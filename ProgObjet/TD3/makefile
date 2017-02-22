all: main
	rm *.o

main: actionnaire employe entreprise Personne main.cpp
	g++ -Wall -o programme Personne.o entreprise.o actionnaire.o employe.o main.cpp

actionnaire: actionnaire.cpp
	g++ -Wall -c -o actionnaire.o actionnaire.cpp

employe: employe.cpp
	g++ -Wall -c -o employe.o employe.cpp

entreprise: entreprise.cpp
	g++ -Wall -c -o entreprise.o entreprise.cpp

Personne: ../TD1/Personne.cpp
	g++ -Wall -c -o Personne.o ../TD1/Personne.cpp
