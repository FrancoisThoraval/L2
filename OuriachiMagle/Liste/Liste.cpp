#include "Liste.h"
#include <iostream>

using namespace std;

Liste::Liste(){
	_nbE =0;
}

bool Liste::estVide(){
	return (_nbE==0);
}

int Liste::fin(int L[tailleListe]){
	int elt=0;

	return elt;
}

int Liste::Tete(int L[tailleListe]){
	int elt=0;

	return elt;
}

void Liste::inserer(Liste L, int element, int pos){
	int i;

	if (_nbE == tailleListe)
	{
		cout << "Liste pleine !" << endl;
	}
	else{
		if ((pos<1) || (pos>_nbE+1))
		{
			cout << "Mauvaise position !" << endl;
		}
		else{
			for (i = _nbE-1; i >(pos-1) ; --i)
			{
				_L[pos-1]=_L[i];
			}
			_L[pos-1]=element;
			_nbE++;
		}
	}
}
