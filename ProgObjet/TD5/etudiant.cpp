#include "etudiant.hpp"
#include <iostream>
using namespace std;

Etudiant::Etudiant(string nom, string prenom, int numEtud){
  this->nom = nom;
  this->prenom = prenom;
  this->_numEtud = numEtud;
}

Etudiant::~Etudiant(){

}

void Etudiant::afficher(){
  cout << this->getNom() << endl;
  cout << this->getPrenom() << endl;
  cout << this->getNumEtud() << endl;

}

int Etudiant::getNumEtud(){
  return this->_numEtud;
}

Etudiant::Etudiant (Etudiant &e){
  this->_numEtud = e.getNumEtud();
  this->nom = e.getNom();
  this->prenom = e.getPrenom();
}
