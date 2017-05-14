#include <iostream>
#include "vecteur.h"

using namespace std;

class Matrix : public Vecteur<double> {
     private:
     int _sizeX;
     int _sizeY;
     public:
     //  Matrix() : Vecteur<Vecteur<double>>();
     Matrix();
     ~Matrix();

     void setSizeX(int);
     void setSizeY(int);

     int getSizeX() const;
     int getSizeY() const;

     void reInit(int,int,double d =0);
     void zero();
     void linearCombi(double,double,Matrix&);
     void productMat(Matrix&,Matrix&);// Cette fonction permet egalement de calculer productMatCol !

     double& operator()(int ligne, int colonne){
             if((ligne<_sizeX) && (colonne <_sizeY)) {
                     return((*this)[ligne+colonne]);
             }
     }

     Matrix& operator=( Matrix& ma){
             for(double i = 0; i < ma.getSizeX(); i++) {
                     for(double j = 0; j < ma.getSizeY(); j++) {
                             (*this)(i,j) = ma(i,j);
                     }
             }
             this->_sizeX = ma.getSizeX();
             this->_sizeY = ma.getSizeY();
             return(*this);
     }


     friend ostream& operator<<(ostream& os, Matrix& m){
             for(double i = 0; i<m.getSizeX(); i++) {
                    os<<'(';
                     for(double j = 0; j<m.getSizeY(); j++) {
                             os<<m(i,j)<<" ";
                     }
                     os<<')'<<endl;
             }
             return(os);
     }
};

Matrix::Matrix(){

}

Matrix::~Matrix(){

}
void Matrix::setSizeX(int s){
        this->_sizeX = s;
}

void Matrix::setSizeY(int s){
        this->_sizeY = s;
}

int Matrix::getSizeX() const {
        return(this->_sizeX);
}

int Matrix::getSizeY() const {
        return(this->_sizeY);
}

void Matrix::reInit(int n, int p, double d ){
        _sizeX = n;
        _sizeY = p;
        Vecteur<double>::reInit(n*p,d);
}

void Matrix::zero(){
        for(double i = 0; i< _sizeX * _sizeY; i++ ) {
                (*this)[i]=0;
        }
}

void Matrix::linearCombi(double alpha,double beta,Matrix& B){
        //Vecteur<double>::add(alpha,*this,beta,B);
        for(double i =0; i<_sizeX * _sizeY; i++) {
                (*this)[i]*=alpha;
        }
        for(double i =0; i<_sizeX * _sizeY; i++) {
                B[i]*=beta;
        }
        for(double i =0; i<_sizeX * _sizeY; i++) {
                (*this)[i]+=B[i];
        }
}

void Matrix::productMat(Matrix& A,Matrix& B){
        if (A.getSizeY() != B.getSizeX()) {
                std::cerr << "Calcul impossible !" << '\n';
        }else{
                this->reInit(A.getSizeX(),B.getSizeY());
                for(double i = 0; i < A.getSizeX(); i++) {
                        for(double j = 0; j < B.getSizeY(); j++) {
                                (*this)(i,j)=0;
                                for(double k =0; k < A.getSizeY(); k++) {
                                        (*this)(i,j) +=   A(i,k) * B(k,j);
                                }
                        }

                }
        }
}

int main(){
        Matrix a,b,c,d,e,f,g;

        a.reInit(4,2,2); //4l 4c
        b.reInit(2,4,2); //2l 2c
        d.reInit(2,1,2); //2l 1c
        f.reInit(2,2,2); //2l 2c
        g.reInit(2,4,1); //2l 4c
        cout<<"a"<<endl<<a<<endl;
        cout<<"b"<<endl<<b<<endl;
        cout<<"d"<<endl<<d<<endl;
        cout<<"f"<<endl<<f<<endl;
        cout<<"g"<<endl<<g<<endl;
        g.linearCombi(2,1,b);
        std::cout << "=====================" << '\n';
        std::cout << "linearCombi:" << '\n';
        std::cout << g << '\n';
        std::cout << "=====================" << '\n';
        cout<<"Product 1 (productMatCol):"<<endl;
        c.productMat(f,d);
        cout<<c;
        cout<<endl;
        std::cout << "=====================" << '\n';
        cout<<"Product 2 (productMat):"<<endl;
        e.productMat(a,b);
        cout<<e;
        cout<<endl;
}
