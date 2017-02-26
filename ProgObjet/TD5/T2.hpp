#ifndef T2_hpp
#define T2_hpp

#include "T1.hpp"
#include <iostream>

class T2 : public T1 {
  public:
    void afficher(){
      std::cout << "classe T2" << std::endl;
    };
    T2 () : T1(){};
    ~T2 (){
      std::cout << "destruction de T2" << std::endl;
      this->afficher();
    };
};

#endif
