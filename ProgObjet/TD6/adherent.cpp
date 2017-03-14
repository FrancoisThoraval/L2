#include "adherent.hpp"

using namespace std;

Adherent::Adherent(Adresse adr, std::string n, std::string p, int a,std::string i
){
  this->_nom = n;
  this->_prenom =p;
  this->_age=a;
  this->_id=i;
  this->_adresse = adr;
}

Adherent::~Adherent(){

}
