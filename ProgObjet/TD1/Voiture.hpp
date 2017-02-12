#ifndef Voiture_hpp
#define Voiture_hpp
#include <string>
#include "Passager.hpp"

class Voiture {
private:
  static const int nbPassagerMax = 4;
  std::string marque;
  std::string modele;
  int nbPassager;
  Passager people[nbPassagerMax];

public:
  Voiture ();
  ~Voiture ();

  void saisirVoiture();
  void saisirPassagers();

  void afficherPassager();
  void ajoutPassager();
  void supprPassager(int position);
  void afficherVoiture();
};

#endif
