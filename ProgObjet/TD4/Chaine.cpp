#include "Chaine.hpp"
#include <iostream>

using namespace std;

Chaine::Chaine(){
  this->_chaine=NULL;
  this->_capacite=10;
  this->_tailleChar=0;
}

Chaine::~Chaine(){
  delete []this->_chaine;
  this->_capacite = 10;
  this->_tailleChar = 0;
}

Chaine::Chaine(Chaine &c){
  this->_chaine = c._chaine;
  this->_capacite = c._capacite;
  this->_tailleChar = c._tailleChar;
}

void Chaine::setChaine(char *s){
  
}
