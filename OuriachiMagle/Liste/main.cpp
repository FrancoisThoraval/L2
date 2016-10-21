#include <iostream>
#include <stdio.h>
#include "Liste.h"

// TODO: 	ecrire un menu pour simplifier les tests
// 				renommer l'tout en anglais pour plus de professionalisme et ouais mon gars! Ils sont montés sur scène, ils ont cramé 10 gars au premier rang
// 				Essayer de comprendre les 3 dernieres lignes de la spécification de l'autre tocard

using namespace std;

int main() {
	 Liste L;
	 int elt;
	 int nbUser;
	 cout << "====== Debut" << endl;
	 cout << "====== Creation: " << endl;
	 cout << "Combien d'elements a entrer ?" << endl;
	 cin >> nbUser;
	 for (int i = 0; i < nbUser; i++) {
	 		cout << "Element n°" << i+1 << ": ";
			cin >> elt;
			L.creer(L,elt,i+1);
	 }
	 L.afficher(L);
	 cout << endl;
	 cout << "Premier element: " << L.tete(L) << endl; //Affiche la tete
	 cout << "Dernier element: " << L.fin(L) << endl;  //Affiche la fin
	 cout << "====== Ajout d'un element" << endl;
	 cout << "Emplacement nouvel element: ";
	 cin >> nbUser;
	 cout << "Element a ajouter: ";
	 cin >> elt;
	 L.ajoutElt(L,nbUser,elt);
	 L.afficher(L);
	 cout << "====== Suppression element: " << endl;
	 cout << "Emplacement element a supprimer: ";
	 cin >> nbUser;
	 L.supprElt(L,nbUser);
	 L.afficher(L);


	return 0;
}
