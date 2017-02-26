#include "../TD1/Personne.hpp"
#include "etudiant.hpp"
#include "enseignant.hpp"
#include "T1.hpp"
#include "T2.hpp"
#include <iostream>

using namespace std;

void exo1(){
  Etudiant e("tom","korthal",123);
  Personne *p = &e;
  Enseignant ens("Francois","Thoraval","Professeur");
  p->afficher();
  p = &ens;
  cout << "=====================" << endl;
  p-> afficher();
}

void exo2(){
  cout << "création T1" << endl;
  T1 t1;
  cout << "création T2" << endl;
  T2 t2;
}

int main(int argc, char const *argv[]) {

  // exo1();
  exo2();
  return 0;
}
