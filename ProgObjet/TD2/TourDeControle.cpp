#include <iostream>
#include "TourDeControle.hpp"

using namespace std;

TourDeControle::TourDeControle(){
  _nbAvionsListes = 0;
}

TourDeControle::~TourDeControle(){

}

void TourDeControle::ajouterTabAvionNormal(string fabricant, string type, long altitude, int cap){
  int i = 0;
  while ((i<NBAVIONS)&&(_listeDavion[i].getFabricant() != "")) {
    i++;
  }
  _listeDavion[i].setFabricant(fabricant);
  _listeDavion[i].setType(type);
  _listeDavion[i].setAltitude(altitude);
  _listeDavion[i].setCap(cap);
  this->_nbAvionsListes++;
}

void TourDeControle::ajouterTabAvionAmie(string fabricant, string type, long altitude, int cap){
  int i = 0;
  while ((i<NBAVIONS)&&(_listeDavion[i].fabricant != "")) {
    i++;
  }
  _listeDavion[i].fabricant = fabricant;
  _listeDavion[i].type = type;
  _listeDavion[i].altitude = altitude;
  _listeDavion[i].cap = cap;
  this->_nbAvionsListes++;
}

void TourDeControle::afficheTour(){
  cout << "nbAvionsListe: " << this->_nbAvionsListes << endl;
  cout << "************************" << endl;
  for (int i = 0; i < this->_nbAvionsListes; i++) {
    afficheFiche(_listeDavion[i]);
  }
}

// void TourDeControle::affiche(ostream &os){
//   os << "nbAvionsListe: " << this->_nbAvionsListes << endl;
//   os << "***** AVIONS *****" << endl;
//   for (int i = 0; i < this->_nbAvionsListes; i++) {
//     os << "* " << _listeDavion[i].getFabricant() << endl;
//     os << "* " << _listeDavion[i].getType() << endl;
//     os << "* " << _listeDavion[i].getAltitude() << endl;
//     os << "* " << _listeDavion[i].getCap() << endl;
//     os << "******************" << endl;
//   }
// }

ostream& operator<< (ostream &os, const TourDeControle &t){
    os << "nbAvionsListe: " << t._nbAvionsListes << endl;
    os << "***** AVIONS *****" << endl;
    for (int i = 0; i < t._nbAvionsListes; i++) {
      os << "* " << t._listeDavion[i].getFabricant() << endl;
      os << "* " << t._listeDavion[i].getType() << endl;
      os << "* " << t._listeDavion[i].getAltitude() << endl;
      os << "* " << t._listeDavion[i].getCap() << endl;
      os << "******************" << endl;
    }

    return os;
}
