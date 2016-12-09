#include "bag.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Bag::Bag(){
  _nbE = 0;
}

bool Bag::estVide(){
  return(_nbE == 0);
}

void Bag::bagVide(){
	_nbE=0;
}

int Bag::frequence(int elem){
  int freq =0;
  bool existe=false;
  if (estVide()) {
    cout << "C'est vide !" << endl;
    exit(1);
  }
  else {
    for (int i = 0; i < _nbE; i++) {
      if(_bag[i]==elem) {
        cout << "L'element " << elem << " existe en position " << i+1 << "." << endl;
        freq++;
        existe = true;
      }
    }
    if(!existe) {
      cout << "L'element " << elem << " n'existe pas dans le bag." << endl;
    }
  }
  return freq;
}

void Bag::ajouter(int elem){
  int i;
  _nbE++;
  if (!estVide()) {
      _bag[_nbE-1]=elem;
  }
}

void Bag::enlever(){
  int i = 0;
	int elem;
  int freq;
	cout << "Entrez la valeur à supprimer: ";
	cin >> elem;
	cout << endl;
  freq = frequence(elem);
	if (!estVide()) {
		if (freq!=0) {
			while ((i<_nbE)&&(_bag[i]!=elem)){
				i++;
      }
			for (int j = i;j < _nbE-1; j++) {
				_bag[j]=_bag[j+1];
			}
			_nbE--;
		}
	}
}

void Bag::afficher(){
  for (int i = 0; i < _nbE; i++) {
    cout << "["<<_bag[i]<<"]";
  }
	cout << endl;
}
