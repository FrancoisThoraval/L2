#include "employe.hpp"

#include <iostream>

using namespace std;

Employe::Employe(){
 this->_id = -1;
}

Employe::Employe(int id, string metier){
 this->setID(id);
 this->setMetier(metier);
}

Employe::~Employe(){

}

void Employe::setMetier(string metier){
  this->_metier = metier;
}

void Employe::setID(int id){
  this->_id = id;
}

std::string Employe::getMetier()const{
  return this->_metier;
}

int Employe::getID()const{
  return this->_id;
}

void Employe::travailler(){
  this->afficher();
  cout << "\nmon identifiant est: " << this->getID() << " Et mon métier est: " << this->getMetier() << endl;
};

bool Employe::operator==(const Employe &e){
  return ((this->getID() == e.getID()) && (this->getMetier() == e.getMetier()));
}

int Employe::operator-(const Employe &e){
  return ((this->getID() - e.getID()));
}
