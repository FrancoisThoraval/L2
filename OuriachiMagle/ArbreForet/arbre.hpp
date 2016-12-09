#ifndef Arbre_hpp
#define Arbre_hpp

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class Arbre
{
private:
	Arbre *_fg;
  Arbre *_fd;
	int _etiquette;
public:
  // Arbre
	Arbre();
  ~Arbre();
  bool arbreVide();
  Arbre* filsG();
  Arbre* filsD();
  void supprimerArbre(Arbre *A);
  int racine();

  // Noeud
  void creerNoeud(int elt);
  void ajouterFg(Arbre *B);
  void ajouterFd(Arbre *B);
  void supprimerFg();
  void supprimerFd();

	//Opération supplémentaire pour simplifier les tests
  void parcoursPrefixe();
};

#endif
