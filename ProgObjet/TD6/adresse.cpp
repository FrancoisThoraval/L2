#include "adresse.hpp"

using namespace std;

// Adresse::Adresse(){
//  this->_numero = -1;
//  this->_rue = "notSet";
//  this->_codePostal = -1;
//  this->_ville = "notSet";
// }

Adresse::Adresse(int n, std::string r, int c, std::string v){
 this->_numero = n;
 this->_rue = r;
 this->_codePostal = c;
 this->_ville = v;
}

Adresse::~Adresse(){

}

void Adresse::setNumero(int n){
  this->_numero = n;
}

void Adresse::setRue(std::string r){
  this->_rue = r;
}

void Adresse::setCodePostal(int c){
  this->_codePostal = c;
}

void Adresse::setVille(std::string v){
  this->_ville = v;
}

int Adresse::getNumero(){
  return this->_numero;
}

std::string Adresse::getRue(){
  return this->_rue;
}

int Adresse::getCodePostal(){
  return this->_codePostal;
}

std::string Adresse::getVille(){
  return this->_ville;
}
