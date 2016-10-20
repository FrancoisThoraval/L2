#ifndef poly_h
#define poly_h

#include <iostream>

using namespace std;

class polynome {
private:
  int _degree;
  bool _isNul;
  float _evaluation;
  // polynome _sumPoly;
  float _Coef;
  bool _equal;
public:
  void Build(int degree); // create new polynome
  void Build(); //create the Zero polynomial
  bool isNul(polynome A);
  bool Equality(polynome A, polynome B);
  polynome Sum(polynome A, polynome B);
  float Evaluate(polynome A, float B);
  unsigned int GetDegree(polynome A);
  float GetCoef(polynome A, int B);

};

#endif
