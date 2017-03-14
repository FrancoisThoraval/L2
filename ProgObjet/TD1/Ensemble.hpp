#ifndef Elements_hpp
#define Elements_hpp

#include <list>
#include <iterator>
#include <iostream>

template <class T>
class Ensemble {
  private:
    // std::list<T> liste;
    T *_tab;
  int _nbElt;
  public:
    Ensemble ();
    ~Ensemble ();

    void affiche(int);
    void affiche();
    bool appartient(T);
    int card();
    void inserer(T);

    friend std::ostream &operator<<(std::ostream &os,const Ensemble<T> &e){
        for (int i = 0; i < e._nbElt; i++) {
                os << e._tab[i] << " ";
        }
        os << "\n";
        return os;
    }

};

// Ecriture dans le hpp car sinon il faut spécifier des constructeurs particuliers
// Pour chaque type que l'on souhaite utiliser avec le template par la suite.

using namespace std;

// CONSTRUCTEUR ============================================

template <class T>
Ensemble<T>::Ensemble(){
        // this->liste.clear();
        this->_tab = NULL;
        this->_nbElt = 0;
}

// DESTRUCTEUR ============================================

template <class T>
Ensemble<T>::~Ensemble(){
        // this->liste.clear();
        this->_tab = NULL;
        delete [] this->_tab;
        this->_nbElt = 0;
}

// APPARTIENT ============================================

template <class T>
bool Ensemble<T>::appartient(T e){
        bool estPresent = (this->_tab[0] == e);
        int i=1;
        while ((i < this->_nbElt) && (!estPresent)) {
                estPresent = (this->_tab[i] == e);
                i++;
        }
        return estPresent;
}

// CARD ============================================

template <class T>
int Ensemble<T>::card(){
        return this->_nbElt;
}


// INSERER ============================================

template <class T>
void Ensemble<T>::inserer(T elem){
        T *recopie = new T [++this->_nbElt]; //On crèe un nouveau tableau
        int i;

        for (i = 0; i < _nbElt-1; i++) {         //On recopie l'ancien dans le nouveau
                recopie[i] = this->_tab[i];
        }
        recopie[i] = elem; //On ajoute l'element
        delete [] this->_tab; //On libère la mémoire de l'ancien tableau
        this->_tab = recopie; //On fais pointer _tab sur le nouveau tableau
}

// AFFICHE ============================================

template <class T>
void Ensemble<T>::affiche(){
        for (int i = 0; i < this->_nbElt; i++) {
                cout << this->_tab[i] << " ";
        }
        cout << endl;
}

// AFFICHE ieme ============================================

template <class T>
void Ensemble<T>::affiche(int i){
        // typename std::list<T>::iterator it = liste.begin();
        // advance(it, i);
        cout << this->_tab[i] << " ";
        cout << endl;
}

#endif
