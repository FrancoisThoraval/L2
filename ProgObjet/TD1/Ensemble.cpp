#include <iostream>
#include "Ensemble.hpp"

using namespace std;


template <class T>
Ensemble<T>::Ensemble(){
  this->liste.clear();
}

template <class T>
Ensemble<T>::~Ensemble(){
  this->liste.clear();
}

template <class T>
void Ensemble<T>::appartient(){

}

template <class T>
void Ensemble<T>::card(){

}

template <class T>
void Ensemble<T>::inserer(){

}

template <class T>
void Ensemble<T>::affiche(){

}

template <class T>
void Ensemble<T>::affiche(int i){
  list<T>::iterator it = liste.begin();
  liste.advance(it, i);
}
