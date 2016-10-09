#include "Polynome.h"
#include <iostream>

void polynome::Build(int degree){
  _degree = degree;
}

void polynome::Build(){
  _degree = 0;
}

bool polynome::isNul(polynome A){
  return _isNul;
}

bool polynome::Equality(polynome A, polynome B){

  return _equal;
}

polynome polynome::Sum(polynome A, polynome B){
  polynome _sumPoly;
  
  return _sumPoly;
}

float polynome::Evaluate(polynome A, float B){

  return _evaluation;
}

unsigned int polynome::GetDegree(polynome A){

  return _degree;
}

float polynome::GetCoef(polynome A, int B){

  return _Coef;
}
