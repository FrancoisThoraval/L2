#include "arbre.hpp"
#include "foret.hpp"

using namespace std;

int main() {
  Foret F;
// premier arbre
  Arbre A;
  Arbre B;
  Arbre C;
// deuxieme arbre
  Arbre D;
  Arbre E;
  cout << "premier arbre   -----------------" << endl;
  cout << A.arbreVide() << endl;
  A.creerNoeud(2);
  B.creerNoeud(10);
  C.creerNoeud(6);

  A.ajouterFg(&B);
  A.ajouterFd(&C);
  A.parcoursPrefixe();

  cout << "deuxieme arbre   -----------------" << endl;
  cout << D.arbreVide() << endl;
  D.creerNoeud(60);
  E.creerNoeud(55);

  D.ajouterFg(&E);
  D.parcoursPrefixe();

  cout << "foret   -----------------" << endl;
  cout << "foret vide ?: " << F.foretVide() << endl;

  F.planter(A);
  F.planter(D);
  F.affichage();

  cout << "nombre d'arbres: " << F.nombreDArbres() << endl;
  F.supprimerArbre(D);
  F.affichage();

  cout << "Deforestation !!!" << endl;
  F.supprimerForet();
  cout << "affichage" << endl;
  F.affichage();
  return 0;
}
