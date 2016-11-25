#include "set.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[]) {
  Set S;
  if (S.estVide()) {
    cout << "c'est vide !" << endl;
  }
  else
    cout << "c'est pas vide !" << endl;

  // S.afficher(S);
  S.ajouter(10);
  if (S.estVide()) {
    cout << "c'est vide !" << endl;
  }
  else
    cout << "c'est pas vide !" << endl;
  bool test = S.appartient(10);
  S.afficher();
  S.ajouter(9);
  S.afficher();
  S.enlever();
  S.afficher();
  cout << "on supprime !" << endl;
  S.setVide();
  S.afficher();
  return 0;
}
