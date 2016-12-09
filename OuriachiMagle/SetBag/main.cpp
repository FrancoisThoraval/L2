#include "set.h"
#include "bag.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void testBag() {
  Bag B;
  cout << "estvide()?" << endl;
  if (B.estVide()) {
    cout << "c'est vide !" << endl;
  }
  else
    cout << "c'est pas vide !" << endl;

  cout << "ajouter(10)" << endl;
  B.ajouter(10);
  cout << "ajouter(10)" << endl;
  B.ajouter(10);
  cout << "ajouter(10)" << endl;
  B.ajouter(10);
  cout << "ajouter(10)" << endl;
  B.ajouter(10);
  cout << "estvide()?" << endl;
  if (B.estVide()) {
    cout << "c'est vide !" << endl;
  }
  else
    cout << "c'est pas vide !" << endl;
  int freq = B.frequence(10);
  cout << "frequence(10): "<< freq << endl;
  cout << "afficher()" << endl;
  B.afficher();
  cout << "ajouter(9)" << endl;
  B.ajouter(9);
  cout << "afficher()" << endl;
  B.afficher();
  cout << "enlever()" << endl;
  B.enlever();
  cout << "afficher()" << endl;
  B.afficher();
  cout << "setVide()" << endl;
  B.bagVide();
  cout << "afficher()" << endl;
  B.afficher();
}

void testSet() {
  Set S;
  cout << "estvide()?" << endl;
  if (S.estVide()) {
    cout << "c'est vide !" << endl;
  }
  else
    cout << "c'est pas vide !" << endl;

  cout << "ajouter(10)" << endl;
  S.ajouter(10);
  cout << "estvide()?" << endl;
  if (S.estVide()) {
    cout << "c'est vide !" << endl;
  }
  else
    cout << "c'est pas vide !" << endl;
  bool test = S.appartient(10);
  cout << "afficher()" << endl;
  S.afficher();
  cout << "ajouter(9)" << endl;
  S.ajouter(9);
  cout << "afficher()" << endl;
  S.afficher();
  cout << "ajouter(10)" << endl;
  S.ajouter(10);
  cout << "afficher()" << endl;
  S.afficher();
  cout << "enlever()" << endl;
  S.enlever();
  cout << "afficher()" << endl;
  S.afficher();
  cout << "setVide()" << endl;
  S.setVide();
  cout << "afficher()" << endl;
  S.afficher();
}

int main(int argc, char const *argv[]) {
  system("clear");

  int answer;
  do {
    cout << "Bonjour, que souhaitez vous tester:" << endl;
    cout << "1) Set" << endl;
    cout << "2) Bag" << endl;
    cout << "Choix: ";
    cin >> answer;
    switch (answer) {
      case 1: testSet();
        break;
      case 2: testBag();
        break;
      default: cout << "Veuillez entrer une valeur correcte." << endl;
    }
  } while((answer >2) || (answer <1));
  return 0;
}
