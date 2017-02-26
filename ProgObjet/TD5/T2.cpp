#include "T2.hpp"
#include <iostream>

using namespace std;

T2::T2() : T1(){

}

T2::~T2(){
  cout << "On détruit T2" << endl;
  this-> afficher();
}

void T2::afficher(){
  cout << "classe T2" << endl;
}
