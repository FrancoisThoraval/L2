#ifndef Foret_hpp
#define Foret_hpp

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "arbre.hpp"

#define TAILLEFORET 50

class Foret
{
private:
	Arbre _foret[TAILLEFORET];
  int _nbA;
public:
  // Foret
	Foret();
  ~Foret();
  bool foretVide();
  void planter(Arbre A);
  void supprimerArbre(Arbre A);
  void supprimerForet();
	int nombreDArbres();
	//Opération supplémentaire pour simplifier les tests
  void affichage();
};

#endif
