#ifndef adresse_hpp
#define adresse_hpp

#include <string>

class Adresse {
private:
  int _numero;
  std::string _rue;
  int _codePostal;
  std::string _ville;

public:
  // Adresse ();
  Adresse(int n = -1,std::string r= "notSet",int c= -1 ,std::string v = "notSet");
  ~Adresse ();

  void setNumero(int);
  void setRue(std::string);
  void setCodePostal(int);
  void setVille(std::string);

  int getNumero();
  std::string getRue();
  int getCodePostal();
  std::string getVille();
};

#endif
