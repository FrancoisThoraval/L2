#ifndef Elements_hpp
#define Elements_hpp

#include <list>

template <class T>
class Ensemble {
private:
  std::list<T> liste;
public:
  Ensemble ();
  ~Ensemble ();

  void affiche(int);
  void affiche();
  void appartient();
  void card();
  void inserer();
};

#endif
