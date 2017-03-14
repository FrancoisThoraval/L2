#ifndef adherent_hpp
#define adherent_hpp

#include <string>
#include "adresse.hpp"

class Adherent {
private:
  std::string _nom;
  std::string _prenom;
  int _age;
  std::string _id;
  Adresse _adresse;

public:
  Adherent (Adresse, std::string n= "notSet", std::string p= "notSet", int a = -1, std::string i= "notSet");
  virtual ~Adherent ();
};


#endif
