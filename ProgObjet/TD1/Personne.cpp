#include "Personne.hpp"
#include <iostream>

using namespace std;

Personne::Personne(){
  // this->saisir();
}

Personne::Personne(string nom, string prenom){
  this->setNom(nom);
  this->setPrenom(prenom);
}

Personne::~Personne(){

}

void Personne::afficher(){
  cout << this->getNom() << endl;
  cout << this->getPrenom() << endl;
}

void Personne::saisir(){
  cout << "Nom: ";
  cin >> this->nom;
  cout << "\nPrenom: ";
  cin >> this->prenom;
  cout << endl;
}

void Personne::raz(){
  this->nom = "";
  this->prenom = "";
}

string Personne::getNom(){return this->nom;}
string Personne::getPrenom(){return this->prenom;}
void Personne::setNom(string nom){this->nom = nom;}
void Personne::setPrenom(string prenom){this->prenom = prenom;}
