#ifndef Set_h
#define Set_h

#define tailleSet 50

class Set
{
	private:
		int _set[tailleSet];
		int _nbE;
	public:
		Set();
		bool estVide();
		bool appartient(int elem);
		void ajouter(int elem);
		void enlever();
		void setVide();
		
		//Opération supplémentaire pour simplifier les tests
		void afficher();
};

#endif
