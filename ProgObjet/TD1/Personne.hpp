#ifndef Personne_hpp
#define Personne_hpp

#include <string>
#include <iostream>

class Personne {
protected:
  std::string nom;
  std::string prenom;

public:
  Personne ();
  Personne (std::string,std::string);
  ~Personne ();

  virtual void afficher();
  void saisir();
  void raz(); //Remise À Zéro

  std::string getNom();
  std::string getPrenom();
  void setNom(std::string);
  void setPrenom(std::string);
  friend std::ostream &operator<<(std::ostream &os,const Personne &p){
      os << p.nom << " ";
      os << p.prenom;
      os << "\n";
      return os;
  }
};

#endif
