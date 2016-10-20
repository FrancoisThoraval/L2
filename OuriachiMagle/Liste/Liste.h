#ifndef Liste_h
#define Liste_h

#define tailleListe 50

class Liste{
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
#endif
//François Thoraval & Mael Rabasa
