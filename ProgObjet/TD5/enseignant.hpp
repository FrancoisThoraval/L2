#ifndef enseignant_hpp
#define enseignant_hpp

#include "../TD1/Personne.hpp"
#include <string>

class Enseignant : public Personne{
private:
  std::string _metier;

public:
  Enseignant (std::string,std::string,std::string);
  Enseignant (Enseignant &);
  ~Enseignant ();
  void setMetier(std::string);
  std::string getMetier();
  void afficher();
};

#endif
