#include "actionnaire.hpp"

#include <iostream>

using namespace std;


Actionnaire::Actionnaire(){
  this->_id = -1;
  this->_metier = "";
}

Actionnaire::Actionnaire(int id, std::string metier){
  this->_id = id;
  this->_metier = metier;
}

Actionnaire::~Actionnaire(){

}

void Actionnaire::ordonner(){
  this->afficher();
  cout << "\nmon identifiant est: " << this->getID() << " Et mon métier est: " << this->getMetier() << endl;
}


void Actionnaire::setMetier(string metier){
  this->_metier = metier;
}

void Actionnaire::setID(int id){
  this->_id = id;
}

std::string Actionnaire::getMetier()const{
  return this->_metier;
}

int Actionnaire::getID()const{
  return this->_id;
}
