#include "employe.hpp"

#include <iostream>

using namespace std;

Employe::Employe(){
 this->_id = -1;
}

Employe::Employe(int id, string metier){
 setID(id);
 setMetier(metier);
}

Employe::~Employe(){

}

void Employe::setMetier(string metier){
  this->_metier = metier;
}

void Employe::setID(int id){
  this->_id = id;
}

std::string Employe::getMetier(){
  return this->_metier;
}

int Employe::getID(){
  return this->_id;
}
