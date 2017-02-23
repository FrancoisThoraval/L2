#ifndef employe_hpp
#define employe_hpp

#include <string>
#include "../TD1/Personne.hpp"

class Employe: public Personne{
private:
  std::string _metier;
  int _id;

public:
  Employe ();
  Employe(int,std::string);
  ~Employe ();

  void setMetier(std::string);
  void setID(int);
  std::string getMetier()const;
  int getID()const;
  void travailler();

  bool operator==(const Employe&);
  int operator-(const Employe&);
};

#endif
