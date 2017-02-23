#ifndef entreprise_hpp
#define entreprise_hpp

#include "./actionnaire.hpp"
#include "./employe.hpp"

class Entreprise: public Actionnaire, public Employe {
private:
  /* data */

public:
  Entreprise ();
  ~Entreprise ();
};

#endif
