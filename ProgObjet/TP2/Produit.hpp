#ifndef Produit_hpp
#define Produit_hpp

#include <iostream>
#include <string>

class Produit {
private:
  std::string _nom;
  int _id;

public:
  Produit ();
  virtual ~Produit ();

  int getId()const;
  std::string getNom()const;
  void setNom(std::string);
  void setId(int);

  friend std::ostream& operator<< (std::ostream &os, const Produit &p);

  Produit &operator=(const Produit& p){
    this->_nom = p._nom;
    this->_id = p._id;
    return *this;
  }
};


#endif
