#ifndef Passager_hpp
#define Passager_hpp

#include <string>

class Passager {
private:
  std::string nom;
  std::string prenom;

public:
  Passager ();
  ~Passager ();

  void saisir();
  void afficher();
};

#endif
