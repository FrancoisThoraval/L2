#include "foret.hpp"

using namespace std;

Foret::Foret(){
  _nbA = 0;
}

Foret::~Foret(){

}

bool Foret::foretVide(){
  return (_nbA == 0);
}

void Foret::supprimerForet(){
  _nbA = 0;
}

void Foret::affichage(){
  Arbre A;
  if (!foretVide()) {
    for (int i = 0; i < _nbA; i++) {
      A = _foret[i];
      A.parcoursPrefixe();
    }
  }
}

void Foret::planter(Arbre A){
  _nbA++;
  _foret[_nbA-1] = A;
}

void Foret::supprimerArbre(Arbre A){
  int i = 0;
  while ((i<_nbA)&&(_foret[i].racine()!=A.racine())) {
    i++;
  }
  if (_foret[i].racine()==A.racine()) {
    for (i = i; i < _nbA; i++) {
      _foret[i] = _foret[i+1];
      _nbA --;
    }
  }
}

int Foret::nombreDArbres(){
  return _nbA;
}
