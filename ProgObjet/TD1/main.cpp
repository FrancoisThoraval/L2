#include "HelloWorld.hpp"
#include "Personne.hpp"
#include "Voiture.hpp"
#include <iostream>


using namespace std;


void exo1(){
  HelloWorld a;

  a.sayHello();
}

void exo2(){
  Personne qqun;

  qqun.afficher();
  qqun.raz();
  qqun.afficher();
}

void exo3(){
  Voiture tuture;
  cout << "============ Afficher voiture ============" << endl;
  tuture.afficherVoiture();
  cout << "============ Ajout passager ============" << endl;
  tuture.ajoutPassager();
  cout << "============ Afficher voiture ============" << endl;
  tuture.afficherVoiture();
  cout << "============ Supprimer passager (2) ============" << endl;
  tuture.supprPassager(2);
  cout << "============ Afficher voiture ============" << endl;
  tuture.afficherVoiture();
}

int main() {
  // exo1(); //Faire une classe qui affiche HelloWorld
  // exo2(); //Faire une classe Personne
  exo3();

  return 0;
}
