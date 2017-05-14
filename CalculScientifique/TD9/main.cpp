#include "matrix.h"
#include <iostream>

using namespace std;

int main(){
  Matrix A,B;
  Vecteur<int> stockImax;
  A.reInit(3,3);
  B.reInit(3,3);
  A(0,0) = 4;
  A(0,1) = 1;
  A(0,2) = 1;
  A(1,0) = 2;
  A(1,1) = 5;
  A(1,2) = 1;
  A(2,0) = 3;
  A(2,1) = 1;
  A(2,2) = 9;

  B(0,0) = 0;
  B(0,1) = 1;
  B(0,2) = 1;
  B(1,0) = 2;
  B(1,1) = 5;
  B(1,2) = 1;
  B(2,0) = 3;
  B(2,1) = 1;
  B(2,2) = 9;


  Matrix L;
  L.reInit(3,3);
  Matrix L3;
  L3.reInit(3,3);
  Matrix U;
  U.reInit(3,3);
  U = A;
  Matrix U2;
  U2.reInit(3,3);
  U2 = B;
  std::cout << "A : " << std::endl;
  cout<<A<<endl;
  std::cout<<" B : "<<std::endl;
  cout<<B<<endl;
  std::cout << "L : " << std::endl;
  cout<<L<<endl;
  std::cout << "U : " << std::endl;
  std::cout << U << std::endl;

  A.LUv1(L,U,stockImax);
  B.LUv1(L3,U2,stockImax);
  for (int i = 0; i < stockImax.size(); i+=2) {
    std::cout << "permutation de la ligne "<< stockImax[i]<< " avec la ligne "<< stockImax[i+1] << " !" << std::endl;
  }

  Matrix test,test2;
  test.reInit(3,3);
  test2.reInit(3,3);

  const Matrix& L2 =L;
  const Matrix& L4 =L3;

  test.productMatrix(L2,U);
  test2.productMatrix(L4,U2);

  cout << "DETERMINANT test = " << test.determinant()<< '\n';
  cout << "DETERMINANT test = " << test2.determinant()<< '\n';
  cout << "DETERMINANT B = " << B.determinant()<< '\n';

  std::cout << "test product : " << std::endl;
  cout<<test<<endl;
  std::cout << "test2 product : " << std::endl;
  cout<<test2<<endl;
}
