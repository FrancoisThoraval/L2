#ifndef etudiant_hpp
#define etudiant_hpp

#include "../TD1/Personne.hpp"

class Etudiant : public Personne {
private:
  int _numEtud;

public:
  Etudiant (std::string,std::string,int);
  Etudiant (Etudiant &e);
  ~Etudiant ();

  int getNumEtud();
  void afficher();
};

#endif
