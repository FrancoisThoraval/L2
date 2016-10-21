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
			if ((pos>0)&&(pos<_nbE)) {
				for (i = _nbE-1; i >= pos-1; i--) {
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

void Liste::errorHandler(int i) {
	switch (i) {
		case 1: cout << "Error Code n°"<<i<<": La liste n'est pas vide !" << endl;
			exit(1);
			break;
		case 2: cout << "Error Code n°"<<i<<": Mauvaise position !" << endl;
			exit(2);
			break;
		case 3: cout << "Error Code n°"<<i<<": Liste pleine !" << endl;
			exit(3);
			break;
	}
}
