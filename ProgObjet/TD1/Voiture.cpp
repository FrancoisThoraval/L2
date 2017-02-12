#include "Voiture.hpp"
#include <iostream>

using namespace std;

Voiture::Voiture (){
  cout << "Saisie Voiture" << endl;
  saisirVoiture();
}
Voiture::~Voiture (){}

void Voiture::afficherPassager(){
  if (nbPassager<=5 && nbPassager>0) {
    for (int i = 0; i < nbPassager; i++) {
      cout << "Passager n°" << i+1 << ":" << endl;
      people[i].afficher();
      cout << endl;
    }
  }
}

void Voiture::ajoutPassager(){
  if (nbPassager < nbPassagerMax) {
    people[nbPassager].saisir();
    nbPassager++;
  }else
    cerr<< "Pas assez de places dans la voiture !" << endl;
}
void Voiture::supprPassager(int position){
  Passager save;
  for (int i = position-1; i < nbPassager-1; i++) {
    people[i]=people[i+1];
  }
  nbPassager--;
}

void Voiture::afficherVoiture(){
  cout << "marque: " << marque << endl;
  cout << "modele: " << modele << endl;
  cout << "-------" << endl;
  afficherPassager();
}

void Voiture::saisirVoiture(){
  cout << "marque ?: ";
  cin >> marque;
  cout << "modele ?: ";
  cin >> modele;
  cout << endl;
  cout << "Y\'a t-il des passager dans cette voiture ?";
  cin >> this->nbPassager;
  if (nbPassager>5 || nbPassager<=0) {
      cerr << "Pas assez de places dans la voiture !" << endl;
    }else
      saisirPassagers();
}


void Voiture::saisirPassagers(){
  for (int i = 0; i < nbPassager; i++) {
    cout << "Passager n°" << i+1 << ":" << endl;
    people[i].saisir();
    cout << endl;
  }
}
