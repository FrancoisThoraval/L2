#include <iostream>

#define tailleListe 50

class Liste
{
	private:
		int _L[tailleListe];
		int _nbE;
	public:
		Liste();
		bool estVide();
		int fin(int L[tailleListe]);  //renvoie l'element en fin de liste
		int Tete(int L[tailleListe]); //renvoie l'element en tete de liste
		void inserer(Liste _L, int element, int pos);
};

//François Thoraval & Mael Rabasa 