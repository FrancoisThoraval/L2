#ifndef Personne_hpp
#define Personne_hpp

#include <string>

class Personne {
private:
  std::string nom;
  std::string prenom;

public:
  Personne ();
  ~Personne ();

  void afficher();
  void saisir();
  void raz(); //Remise À Zéro

  std::string getNom();
  std::string getPrenom();
};

#endif
