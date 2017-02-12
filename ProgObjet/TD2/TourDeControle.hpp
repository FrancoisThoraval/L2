#ifndef TourDeControle_hpp
#define TourDeControle_hpp

#include <iostream>
#include <string>
#include "Avion.hpp"

#define NBAVIONS 20

using namespace std;

class TourDeControle {
private:
  Avion _listeDavion[NBAVIONS];
  int _nbAvionsListes;

public:
  TourDeControle ();
  ~TourDeControle ();

  void ajouterTabAvionNormal(string fabricant, string type, long altitude, int cap);
  void ajouterTabAvionAmie(string fabricant, string type, long altitude, int cap);
  // void affiche(ostream &os);
  void afficheTour();

  friend ostream & operator << (ostream &os, const TourDeControle &t);
};

#endif
