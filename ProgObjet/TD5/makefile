all: main
	rm *.o

main: etudiant enseignant Personne T1 main.cpp
	g++ -Wall -o programme etudiant.o enseignant.o T1.o Personne.o main.cpp

etudiant: etudiant.cpp
	g++ -Wall -c -o etudiant.o etudiant.cpp

enseignant: enseignant.cpp
	g++ -Wall -c -o enseignant.o enseignant.cpp

Personne: ../TD1/Personne.cpp
	g++ -Wall -c -o Personne.o ../TD1/Personne.cpp

T1: T1.cpp
	g++ -Wall -c -o T1.o T1.cpp
