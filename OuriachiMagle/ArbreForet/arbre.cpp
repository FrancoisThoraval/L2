#include "arbre.hpp"

using namespace std;

Arbre::Arbre(){

}

Arbre::~Arbre(){

}

void Arbre::creerNoeud(int elt){
  _etiquette = elt;
  _fg = NULL;
  _fd = NULL;
}

void Arbre::ajouterFg(Arbre *B){
  _fg = B;
}

void Arbre::ajouterFd(Arbre *B){
  _fd = B;
}

void Arbre::supprimerFg(){
  _fg = NULL;
}

void Arbre::supprimerFd(){
  _fd = NULL;
}

bool Arbre::arbreVide(){
  return (this == NULL);
}

Arbre* Arbre::filsG(){
  return (_fg);
}

Arbre* Arbre::filsD(){
  return (_fd);
}

void Arbre::supprimerArbre(Arbre *A){
  if (this == NULL) {
    free(this);
  }else{
    if (_fg != NULL) {
      supprimerArbre(_fg);
    }
    if (_fd != NULL) {
      supprimerArbre(_fd);
    }
  }
}

int Arbre::racine(){
  return(this->_etiquette);
}

void Arbre::parcoursPrefixe(){
  if (!arbreVide()) {
    cout << '(' << racine() << ')' << endl;
    _fg -> parcoursPrefixe();
    _fd -> parcoursPrefixe();
  }
}
