#include "enseignant.hpp"
#include <iostream>

using namespace std;

Enseignant::Enseignant(string nom, string prenom, string metier){
  this->setNom(nom);
  this->setPrenom(prenom);
  this->setMetier(metier);
}

Enseignant::~Enseignant(){

}

void Enseignant::setMetier(string metier){
  this->_metier = metier;
}

void Enseignant::afficher(){
  cout << this->getNom() << endl;
  cout << this->getPrenom() << endl;
  cout << this->getMetier() << endl;

}

string Enseignant::getMetier(){
  return this->_metier;
}

Enseignant::Enseignant (Enseignant &e){
  this->_metier = e.getMetier();
  this->nom = e.getNom();
  this->prenom = e.getPrenom();
}
