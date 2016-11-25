#ifndef Liste_h
#define Liste_h

#define tailleListe 50

class Liste{
	private:
		int _L[tailleListe];
		int _nbE;
	public:
		Liste();
		~Liste();
		bool estVide();
		int fin(Liste _L);  //renvoie l'element en fin de liste
		int tete(Liste _L); //renvoie l'element en tete de liste
		void creer(Liste _L, int element, int pos);
		void afficher(Liste _L);
		void errorHandler(int i);
		int acceder(Liste L, int pos);
		void rechercher(Liste L, int elt);
		Liste ajoutElt(Liste L, int pos, int nb);
		Liste supprElt(Liste L, int pos);
		Liste concatener(Liste L1, Liste L2);
		void longueur(Liste &L);
};
#endif
//François Thoraval & Mael Rabasa
