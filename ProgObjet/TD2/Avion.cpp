#include <iostream>
#include "Avion.hpp"

using namespace std;

Avion::Avion(){
 this->fabricant ="";
 this->type ="";
 this->altitude=-1;
 this->cap =-1;
}

Avion::Avion(const std::string fabricant,const  std::string type,const long altitude, const int cap){
  this->fabricant = fabricant;
  this->type = type;
  this->altitude = altitude;
  this->cap = cap;
}

Avion::~Avion(){

}

void Avion::setFabricant(string fabricant){
  this->fabricant = fabricant;
}

void Avion::setType(string type){
  this->type = type;
}

void Avion::setAltitude(int altitude){
  this->altitude = altitude;
}

void Avion::setCap(int cap){
  this->cap = cap;
}

string Avion::getFabricant()const{
  return this->fabricant;
}

string Avion::getType()const{
  return this->type;
}

long Avion::getAltitude()const{
  return this->altitude;
}

int Avion::getCap()const{
  return this->cap;
}

void afficheFiche(Avion a){
  cout << "***** AVION *****" << endl;
  cout << "* " << a.fabricant << endl;
  cout << "* " << a.type << endl;
  cout << "* " << a.altitude << endl;
  cout << "* " << a.cap << endl;
  cout << "*****************" << endl;
};
