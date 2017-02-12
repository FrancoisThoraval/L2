#ifndef Avion_hpp
#define Avion_hpp

#include <iostream>
#include <string>

using namespace std;

class Avion {
private:
  string fabricant;
  string type;
  long altitude;
  int cap;


public:
  Avion();
  Avion (const string fabricant,const string type,const long altitude,const int cap);
  ~Avion ();

  friend void afficheFiche(Avion a);

  friend class TourDeControle;

  void setFabricant(string fabricant);
  void setType(string type);
  void setAltitude(int altitude);
  void setCap(int cap);
  string getFabricant()const;
  string getType()const;
  long getAltitude()const;
  int getCap()const;
};

#endif
