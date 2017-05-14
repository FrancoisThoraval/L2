#ifndef __Matrix_h
#define __Matrix_h

#include  "vecteur.h"
#include  <cstdlib>
#include  <ext/numeric>
#include  <limits>
#include <iostream>

/*-----------------------------------------------------------------*/


  class Matrix : public Vecteur<double>
  {
private:

    //  _n est le nombre de lignes et _m le nombre de colonnes
    int _n, _m;

public:

    // Itérateur constant pour parcourir la matrice sans la modifier
    typedef typename  Vecteur<double>::const_iterator const_iterator;
    // Itérateur pour parcourir la matrice
    typedef typename  Vecteur<double>::iterator iterator;

    // Constructeur sans argument

    Matrix() : Vecteur<double>(), _n(0), _m(0) {}
    // Constructeur par recopie
    Matrix(const Matrix&A) : Vecteur<double>(A), _n( A.n() ), _m( A.m() )
    {
      *this = A;
    }


    // Fonction reinitialisant une matrice en la redimensionnant
    void reInit(int n, int m)
    {
      _n = n;
      _m = m;
      Vecteur<double>::reInit(n*m);
    }

    // Fonction renvoyant le nombre de lignes
    int n() const
    {
      return _n;
    }
    // Fonction renvoyant le nombre de colonnes
    int m() const
    {
      return _m;
    }

    // Opérateur d'accès en lecture à un coefficient de la matrice

    const double& operator()(int i, int j) const
    {
      return ( *this )[j+_m*i];
    }

    /// Opérateur d'accès en écriture à un coefficient de la matrice

   double&       operator()(int i, int j)
    {
      return ( *this )[j+_m*i];
    }

    /// Opérateur de recopie

    Matrix&   operator=(const Matrix& A)
    {

      (*this).reInit(A.n(),A.m());
      for(int i = 0; i < n(); i++)
      {
        for(int j = 0; j < m(); j++)
        {
          ( *this )( i, j ) = A(i, j);
        }
      }
      return *this;
    }

    //Fonction effectuant le produit matriciel: A = (*this) * B
    // à appeler avec un objet constant, pour lever l'ambiguïté
    //avec la fonction suivante (voir exemple dans le main)

    void productMatrix(Matrix& A, const Matrix& B) const
    {
      if (B.n()!=(*this).m())
      {
        std::cerr<<"Produit matriciel non défini\n";
        exit(1);
      }
      A.reInit((*this).n(),B.m());
      A.zero();
      for(int i = 0; i < A.n(); i++)
      {
        for(int j = 0; j < A.m(); j++)
        {
          for(int k = 0; k < (*this).m(); k++)
          {
            A(i, j) += ( *this )( i, k )*B(k, j);
          }
        }
      }
    }

    //Fonction effectuant : (*this) = A*B

    void productMatrix(const Matrix& A, const Matrix& B)
    {
      if (B.n()!=A.m())
      {
        std::cerr<<"Produit matriciel non défini\n";
        exit(1);
      }
      (*this).reInit(A.n(),B.m());
      (*this).zero();
      for(int i = 0; i < (*this).n(); i++)
      {
        for(int j = 0; j < (*this).m(); j++)
        {
          for(int k = 0; k < A.m(); k++)
          {
            (*this)(i, j) += A( i, k )*B(k, j);
          }
        }
      }
    }


    // Fonction effectuant le produit matrice-matrice colonne
    void productMatCol(Matrix& y, const Matrix& x) const
    {
      if (x.n()!=(*this).m())
      {
        std::cerr<<"Produit matriciel non défini\n";
        exit(1);
      }
      y.reInit((*this).n(),1);
      double s;
      for (int i=0; i<(*this).m(); i++)
      {
        s=0.0;
        for(int j = 0; j < m(); j++)
        {
          s+= (*this)(i,j)*x[j];
        }
        y[i]=s;
      }
    }
    // Fonction initialisant la matrice à partir d'une combinaison linéaire
    // (*this)= alpha*A +beta*B
    void linearCombi(double alpha, const Matrix& A, double beta, const Matrix& B)
    {
      if ((A.n()!=B.n()) ||(A.m()!=B.m()))
      {
        std::cerr<<"Combinaison linéaire non définie\n";
        exit(1);
      }
      (*this).reInit(A.n(),A.m());
      for(int i = 0; i < (*this).n(); i++)
      {
        for(int j = 0; j < (*this).m(); j++)
        {
            (*this)(i, j) = alpha*A( i, j )+beta*B(i, j);
        }
      }
    }

    // fonction initialisant une matrice carrée à l'identité
    void identity()
    {
      zero();
      for(int i = 0; i < n(); i++)
      {
        ( *this )( i, i ) = 1.;
      }
    }
    //opérateur de sortie
    friend std::ostream& operator<<(std::ostream &s, const Matrix& A)
    {
      if(!A.size()) return s;
      for(int i = 0; i < A.n(); i++)
      {
        for(int j = 0; j < A.m(); j++)
        {
           s<<A(i,j)<<" ";
        }
        s<<'\n';
      }
      return s;
    }
    void  LUv1(Matrix &L, Matrix& U,Vecteur<int> &stockImax){
      L.identity();

      for(int k =0; k <= (_n-2);k++){
        L(k,k)=1.0;
        if (U(0,k) < 1) {
          int imax = U.whereMax();
          stockImax.push_back(imax);
          stockImax.push_back(k);
          permutation(imax,k,U,L);
        }
        for(int i = k+1;i <= (_n-1);i++){
          L(i,k)= U(i,k) / U(k,k);
          U(i,k) = 0.0;
          for(int j = k+1; j <= (_n-1) ; j++){
            U(i,j) -= L(i,k) * U(k,j);
          }
        }
      }
    }

    int whereMax(){
      int imax = 0;
      for (int i = 0; i < _n; i++) {
        if (abs((*this)(i,0))>abs((*this)(imax,0))) {
          imax = i;
        }

      }
      return imax;
    }

    void permutation(int i,int k,Matrix &U, Matrix &L){
      Matrix aux;
      aux.reInit(_n,_m);
      if (i != k) {
        for (int ibisa = 0; ibisa < k; ibisa++) {
          aux(k,ibisa) = L(k,ibisa);
          L(k,ibisa) = L(i,ibisa);
          L(i,ibisa) = aux(k,ibisa);
        }

        for (int j = k; j < _n; j++) {
          aux(k,j) = U(k,j);
          U(k,j) = U(i,j);
          U(i,j) = aux(k,j);
        }
      }
    }

    int determinant(){
      int resPos=0;
      int resNeg=0;
      resPos += (*this)(0,0) * (*this)(1,1)* (*this)(2,2);
      resPos += (*this)(1,0)* (*this)(2,1)* (*this)(0,2);
      resPos += (*this)(2,0)* (*this)(0,1)* (*this)(1,2);
      resNeg += (*this)(2,0)* (*this)(1,1)* (*this)(0,2);
      resNeg += (*this)(2,1)* (*this)(1,2)* (*this)(0,0);
      resNeg += (*this)(2,2)* (*this)(1,0)* (*this)(0,1);

      return resPos - resNeg;
    }
};




#endif
