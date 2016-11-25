#include "Liste.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Liste::Liste(){
	_nbE =0;
}

bool Liste::estVide(){
	return (_nbE==0);
}

int Liste::fin(Liste L){
	if (!(L.estVide())) {
		return _L[_nbE-1];
	}
	else{
		errorHandler(1);
		return 1;
	}
}

int Liste::tete(Liste L){
	if (!(L.estVide())) {
		return _L[0];
	}
	else{
		errorHandler(1);
		return 1;
	}
}

Liste Liste::ajoutElt(Liste L, int pos, int nb){
	int i;
	if (_nbE+1 <tailleListe){
			if ((pos>0)&&(pos<=_nbE)) {
				for (i = _nbE; i >= pos-1; i--) {
					_L[i+1]=_L[i];
				}
				_L[i+1]=nb;
				_nbE++;
				return L;
			}
			else{
				errorHandler(2);
				return L;
			}
	}
	else{
		errorHandler(3);
		return L;
	}
}

Liste Liste::supprElt(Liste L, int pos){
	int i;
	if (_nbE+1 <tailleListe){
			if ((pos>0)&&(pos<_nbE)) {
				for (i = pos-1; i < _nbE; i++) {
					_L[i]=_L[i+1];
				}
				_nbE--;
				return L;
			}
			else{
				errorHandler(2);
				return L;
			}
	}
	else{
		errorHandler(3);
		return L;
	}
}

int Liste::acceder(Liste L, int pos){
	if ((L.estVide())) {
		errorHandler(1);
		return 1;
	}
	else{
		if((pos <1) || (pos >_nbE)){
			errorHandler(2);
			return 2;
		}
		else
			return _L[pos-1];
		}
}

void Liste::creer(Liste L, int element, int pos){
	int i;

	if (_nbE == tailleListe)
	{
		errorHandler(3);
	}
	else{
		if ((pos<1) || (pos>_nbE+1))
		{
			errorHandler(2);
		}
		else{
			for (i = _nbE-1; i >(pos-1) ; i--)
			{
				_L[pos-1]=_L[i];
			}
			_L[pos-1]=element;
			_nbE++;
		}
	}
}

void Liste::afficher(Liste L){
	for (int i = 0; i < _nbE; i++) {
		cout << "["<<_L[i]<<"]";
	}
	cout << endl;
}

void Liste::rechercher(Liste L, int elt) {
	bool dieuExiste=false;

	if (L.estVide()) {
		errorHandler(1);
	}
	else {
		for (int i = 0; i < _nbE; i++) {
			if(_L[i]==elt) {
				cout << "L'element " << elt << " existe en position " << i+1 << "." << endl;
				dieuExiste=true;
			}
		}

		if(!dieuExiste) {
			cout << "L'element " << elt << " n'existe pas dans la liste.";
		}
	}
}

Liste Liste::concatener(Liste L1, Liste L2){
	int memory;
	Liste L;

	if(L1._nbE+L2._nbE>=tailleListe) {
		errorHandler(4);
	}
	else if((L1.estVide()) && (L2.estVide())) {
			errorHandler(1);
		}
		else {
			for(int i=1; i <= L1._nbE; i++) { //On demarre i a 1 car acceder retourne la position -1
				L.creer(L, L1.acceder(L1,i), i);
				memory=i;
			}

			for(int i=1; i <= L2._nbE; i++) {
				L.creer(L, L2.acceder(L2,i), memory+i);
			}
		}

	return(L);
}

void Liste::longueur(Liste &L){
	if (L.estVide())
	{
		errorHandler(1);
	}
	else{
		cout << "Longueur de la liste: "<<_nbE << endl;
	}
}


void Liste::errorHandler(int i) {
	switch (i) {
		case 1: cout << "Error Code n°"<<i<<": La liste est vide !" << endl;
			exit(1);
			break;
		case 2: cout << "Error Code n°"<<i<<": Mauvaise position !" << endl;
			exit(2);
			break;
		case 3: cout << "Error Code n°"<<i<<": Liste pleine !" << endl;
			exit(3);
			break;
		case 4: cout << "Error Code n°"<<i<<": Depassement !" << endl;
	}
}
