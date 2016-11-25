#include "set.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void errorHandler(int errorCode){

}

Set::Set(){
	_nbE = 0;
}

bool Set::estVide(){
	return (_nbE==0);
}

bool Set::appartient(int elem){
	bool existe=false;

	if (estVide()) {
		errorHandler(1);
		exit(1);
	}
	else {
		for (int i = 0; i < _nbE; i++) {
			cout << "i: "<<i<<endl;
			if(_set[i]==elem) {
				cout << "L'element " << elem << " existe en position " << i+1 << "." << endl;
				existe=true;
			}
		}
		if(!existe) {
			cout << "L'element " << elem << " n'existe pas dans le set." << endl;
		}
	}
	return existe;
}

void Set::ajouter(int elem){
	int i;
	_nbE++;
	if (!estVide()) {
		if (!appartient(elem)) {
			_set[_nbE-1]=elem;
			// _nbE++;
		}
	}
}

void Set::setVide(){
	_nbE=0;
}

void Set::enlever(){
	int i = 0;
	int elem;
	cout << "Entrez la valeur à supprimer: ";
	cin >> elem;
	cout << endl;
	if (!estVide()) {
		if (appartient(elem)) {
			while ((i<_nbE)&&(_set[i]!=elem))
				i++;
			for (int j = i; i < _nbE-1; i++) {
				_set[j]=_set[j+1];
			}
			_nbE--;
		}
	}
}

void Set::afficher(){
  for (int i = 0; i < _nbE; i++) {
    cout << "["<<_set[i]<<"]";
  }
	cout << endl;
}
