#include "Passager.hpp"
#include <iostream>

using namespace std;

Passager::Passager(){

}

Passager::~Passager(){}

void Passager::saisir(){
  cout << "Nom: ";
  cin >> this->nom;
  cout << "Prenom: ";
  cin >> this->prenom;
  cout << endl;
}

void Passager::afficher(){
  cout << this->nom << endl;
  cout << this->prenom << endl;
  cout << endl;
}
