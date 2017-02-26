#include "T1.hpp"
#include <iostream>

using namespace std;

T1::T1(){
  this->afficher();
}

T1::~T1(){
  cout << "On détruit T1" << endl;
  this-> afficher();
}

void T1::afficher(){
  cout << "classe T1" << endl;
}
