#ifndef actionnaire_hpp
#define actionnaire_hpp

#include <string>
#include "../TD1/Personne.hpp"

class Actionnaire: public Personne {
private:
  int _id;
  std::string _metier;

public:
  Actionnaire();
  Actionnaire (int , std::string);
  ~Actionnaire ();

  void ordonner();
  void setMetier(std::string);
  void setID(int);
  int getID()const;
  std::string getMetier()const;
};

#endif
