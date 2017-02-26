#ifndef Chaine_hpp
#define Chaine_hpp

#include <cstring>
#include <string>
#include <iostream>


class Chaine {
  private:
  char *_chaine;
  int _capacite;
  int _tailleChar;


  public:
  Chaine ();
  ~Chaine ();
  Chaine(Chaine &);

  void setChaine(char*);

  Chaine &operator=(const Chaine &c){
          if (strcmp(this->_chaine,c._chaine)==0) {
                  this->_chaine = c._chaine;
          }
          else{
                  delete []this->_chaine;
                  this->_chaine =  new char [c._tailleChar];
                  this->_chaine = c._chaine;
          }
          this->_capacite = c._capacite;
          this->_tailleChar = strlen(c._chaine);
          return (*this);
  }

  // Chaine &operator=(char &c){
  //         if (strcmp(this->_chaine,c)==0) {
  //                 this->_chaine = c;
  //         }
  //         else{
  //                 delete []this->_chaine;
  //                 this->_chaine =  new char [strlen(c)];
  //                 this->_chaine = c;
  //         }
  //         this->_capacite = strlen(c);
  //         this->_tailleChar = strlen(c);
  //         return (*this);
  // }

  friend std::ostream & operator << (std::ostream &os, const Chaine &c){
    return(os << c._chaine);

  }
};

#endif
