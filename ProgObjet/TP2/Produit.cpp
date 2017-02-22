#include "Produit.hpp"
#include <iostream>

using namespace std;

Produit::Produit(){
  cout << "Construction du produit" << endl;
  this->_nom ="";
  this->_id = -1;
}

Produit::~Produit(){
  cout << "Au revoir mon ami" << endl;
}

string Produit::getNom()const{
  return this->_nom;
}

int Produit::getId()const{
  return this->_id;
}

void Produit::setNom(string nom){
  this->_nom = nom;
}

void Produit::setId(int id){
  this->_id = id;
}

ostream& operator<< (ostream &os, const Produit &p){
  os << "Produit: " << p.getId() << " | " << p.getNom() << endl;
  return os;
}
