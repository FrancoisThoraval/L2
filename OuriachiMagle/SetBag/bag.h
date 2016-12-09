#ifndef Bag_h
#define Bag_h

#define tailleBag 50

class Bag
{
private:
	int _bag[tailleBag];
	int _nbE;
public:
	Bag();
	void bagVide();
	bool estVide();
	int frequence(int elem);
	void ajouter(int elem);
	void enlever();

	//Opération supplémentaire pour simplifier les tests
	void afficher();
};

#endif
