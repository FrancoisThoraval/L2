#include "employe.hpp"
#include "actionnaire.hpp"
#include "entreprise.hpp"

#include <iostream>

using namespace std;

//1. On remarque que le constructeur de Personne s'éxecute lorsqu'on construit un employé

int main() {
  Employe e(325,"Pigiste");
  e.travailler();
  Employe eBis(325,"Pigiste");

  if (e == eBis) {
    cout << "c lé mèm bôloç" << endl;
  }
  cout << e-eBis << endl;

  Actionnaire a(321,"coco");
  a.ordonner();
  return 0;
}
