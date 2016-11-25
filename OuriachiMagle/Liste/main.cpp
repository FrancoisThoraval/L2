#include <iostream>
#include <stdio.h>
#include "Liste.h"

// TODO: 	ecrire un menu pour simplifier les tests

int main();

using namespace std;

void init(Liste &L){
	int nbUser;
	int elt;
	cout << endl;
	cout << "Combien d'elements a entrer ?" << endl;
	cin >> nbUser;
	for (int i = 0; i < nbUser; i++) {
		cout << "Element n°" << i+1 << ": ";
		cin >> elt;
		L.creer(L,elt,i+1);
	}
}

void afficher(Liste &L){
	L.afficher(L);
	cout << endl;	
	cout << "Premier element: " << L.tete(L) << endl; //Affiche la tete
	cout << "Dernier element: " << L.fin(L) << endl;  //Affiche la fin
}

void ajouter(Liste &L){
	 int nbUser;
	 int elt;
	 cout << endl;
	 cout << "Emplacement nouvel element: ";
	 cin >> nbUser;
	 cout << "Element a ajouter: ";
	 cin >> elt;
	 L.ajoutElt(L,nbUser,elt);
}

void suppression(Liste &L){
	 int nbUser;
	 cout << endl;
	 cout << "Emplacement element a supprimer: ";
	 cin >> nbUser;
	 L.supprElt(L,nbUser);
}

void showEstVide(Liste &L){
	if (L.estVide())
	{
		cout << endl;
		cout << "La liste est vide " << endl;
	}
	else {
		cout << endl;
		cout << "La liste n'est pas vide" << endl;
	}
}

void rechElt(Liste &L){
	int element;

	cout << "Entrez un element a rechercher : ";
	cin >> element;
	L.rechercher(L, element);
}

void concat(Liste &L) {
	Liste L2;
	cout << "Saisie de la deuxieme liste: "<< endl;
	init(L2);

	L=L.concatener(L,L2);
}

void longueur(Liste &L){
	L.longueur(L);
}

int main() {
	 Liste L;
	 int choix=1;

	 while((choix==1) || (choix==2) || (choix==3) || (choix==4) || (choix==5) || (choix==6) || (choix==7) || (choix==8)) {
		 cout << "Que voulez vous faire avec la liste ?" << endl;
		 cout << "1. Initialiser" << endl;
		 cout << "2. Afficher" << endl;
		 cout << "3. Ajouter un element" << endl;
		 cout << "4. Supprimer un element" << endl;
		 cout << "5. Afficher si la liste est vide" << endl;
		 cout << "6. Rechercher un element" << endl;
		 cout << "7. Concatener deux listes" << endl;
		 cout << "8. Longueur de la liste" << endl;
		 cout << "0. Quitter le programme" << endl;
		 cin >> choix;

		 switch(choix){
		 	case 1: init(L);
		 		break;
		 	case 2: afficher(L);
		 		break;
		 	case 3: ajouter(L);
		 		break;
		 	case 4: suppression(L);
		 		break;
		 	case 5: showEstVide(L);
		 		break;
		 	case 6: rechElt(L);
		 		break;
		 	case 7: concat(L);
		 		break;
		 	case 8: longueur(L);
		 		break;
		 	default:
		 		cout << endl;
		 		return(0);
		 }
	}

	return 0;
}
