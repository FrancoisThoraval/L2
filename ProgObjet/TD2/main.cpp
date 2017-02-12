#include <iostream>
#include <string>

#include "Avion.hpp"
#include "TourDeControle.hpp"

using namespace std;


// void afficheFiche(Avion a){
//   cout << "***** AVION *****" << endl;
//   cout << "* " << a.fabricant << endl;
//   cout << "* " << a.type << endl;
//   cout << "* " << a.altitude << endl;
//   cout << "* " << a.cap << endl;
//   cout << "*****************" << endl;
// }

void exo1(){
  Avion a("boeing","777",11000,320);
  afficheFiche(a);
}

void exo2(){
  TourDeControle t;

  t.ajouterTabAvionNormal("Boeing", "777",11000,320);
  t.ajouterTabAvionAmie("Airbus", "a320",5360,30);

  // t.afficheTour();

//  Pour ajouter un avion sans passer par les accesseurs et les acces directs,
//  il faudrait supprimer la classe avion et l'integrer dans celle de la tour de
//  contrôle.

  cout << "Ma tour de controle: \n" << t << endl;
}

int main() {
  // exo1();
  exo2();

  return 0;
}
