#include <iostream>
#include <cmath>
using namespace std;

#define N 1

double f(double a){
        return(sin(a));
}

// double f2(double a){
//         return(pow(pow(a,4),2));
// }
//
// double f3(double a){
//         return(pow(pow(a,4),3));
// }
//
// double f4(double a){
//         return(pow(pow(a,4),4));
// }
//
// double f5(double a){
//         return(pow(pow(a,4),5));
// }
//
// double f10(double a){
//         return(pow(pow(a,4),10));
// }

double Point_Milieu(double a, double b,int n, double (*f)(double)){
        double v= 0;
        double h = (b-a)/n;
        double x1 = a;
        double x2;
        int i;
        for(i = 0; i<n; i++ ) {
                x2 = x1+h;
                v = v+f((x1+x2)/2);
                x1 = x2;
        }
        v = v*h;
        return(v);
}

double trapeze ( double a, double b, int n, double (*f)(double)){
        double h = (b-a)/n;
        double r = (f(b)-f(a))/2;
        int i;
        for(i = 1; i<=n-1; i++) {
                r=r+f(h*i+a);
        }
        return(r*h);
}

double simpson ( double a, double b, int n, double (*f)(double)){
        double h= (b-a)/n;
        double r = 0;// (1/6)*f(a)+(1/6)*f(b)+(2/3)*f((a+b)/2);
        int i;
        double x1 =a;
        double x2;
        // double res = 0;
        for(i=0; i<=n-1; i++) {
                x2 = x1+h;
                r = r +(1.0/6.0)*f(x1)+(1.0/6.0)*f(x2)+(2.0/3.0)*f((x1+x2)/2.0); //(1/6)*f(x1)+(1/6)*f(x2)+(2/3)*f((x1+x2)/2);
                x1=x2;
        }
        return(r*h);
}


double cinqPoints ( double a, double b, int n, double (*f)(double)){
        const double divs = 1/90.0;
        double interv = b-a;
        double h= (b-a)/n;
        double r = 0;// (1/6)*f(a)+(1/6)*f(b)+(2/3)*f((a+b)/2);
        int i;
        double x1 =a;
        double x2,x3,x4,x5;
        // double res = 0;
        for(i=0; i<n; i++) {
                // x2 = x1+h;
                // r = r + interv*7*divs*f(x1)+interv*7*divs*f(x2)+interv*12*divs*f((x1+x2)/2.0)+ interv*32*divs*f((a+((x1+x2)/2.0))/2.0) + interv*32*divs*f((b +((x1+x2)/2.0))/2.0);

                x2 = x1+h/4.0;
                x3 = x1+h/2.0;
                x4 = x1+(3/4.0)*h;
                x5 = x1+h;
                r = r + divs*(7*f(x1)+32*f(x2)+12*f(x3)+32*f(x4)+7*f(x5));
                x1=x5;
        }
        return(r*h);
}

int main(){
        double a = 0;
        double b = M_PI/3.0;

        for (int i = 1; i <= 10; i++) {
                double ptm = Point_Milieu(a,b,i,f);
                double tr = trapeze(a,b,i,f);
                double sim = simpson(a,b,i,f);
                cout<<"Point milieu : "<<ptm<< " Erreur : "<<fabs(ptm-0.5)<<endl;
                cout<<"Trapeze      : "<<tr<< " Erreur : "<<fabs(tr-0.5)<<endl;
                cout<<"simpson      : "<<sim << " Erreur : "<<fabs(sim-0.5)<<endl<<endl;

        }


        cout << "=========================================" << endl<<endl;
        a=0;
        b=1;
        double cP,cP2,cP3,cP4,cP5,cP10;
        double save;
        // for (int i = 0; i <= 1; i++) {
                cP = cinqPoints(0,1,10,f);
                cout<<"cinqPoints     : "<<cP << " Erreur : "<<fabs(cP-(1/6.0))<<endl<<endl;
                cP = cinqPoints(0,1,20,f);
                cout<<"cinqPoints     : "<<cP << " Erreur : "<<fabs(cP-(1/6.0))<<endl<<endl;
                cP = cinqPoints(0,1,30,f);
                cout<<"cinqPoints     : "<<cP << " Erreur : "<<fabs(cP-(1/6.0))<<endl<<endl;
                cP = cinqPoints(0,1,40,f);
                cout<<"cinqPoints     : "<<cP << " Erreur : "<<fabs(cP-(1/6.0))<<endl<<endl;
                // cP2 = cinqPoints(a,b,i,f2);
                // cP3 = cinqPoints(a,b,i,f3);
                // cP4 = cinqPoints(a,b,i,f4);
                // cP5 = cinqPoints(a,b,i,f5);
                // cP10 = cinqPoints(a,b,i,f10);
                // cout<<"cinqPoints2    : "<<cP2 << " Erreur : "<<fabs(cP2-0.5*0.5)<<endl<<endl;
                // cout<<"cinqPoints3    : "<<cP3 << " Erreur : "<<fabs(cP3-pow(0.5,3))<<endl<<endl;
                // cout<<"cinqPoints4    : "<<cP4 << " Erreur : "<<fabs(cP4-pow(0.5,4))<<endl<<endl;
                // cout<<"cinqPoints5    : "<<cP5 << " Erreur : "<<fabs(cP5-pow(0.5,5))<<endl<<endl;
                // cout<<"cinqPoints10    : "<<cP10 << " Erreur : "<<fabs(cP10-pow(0.5,10))<<endl<<endl;

                // save = fabs(cP-0.5);
                // if (save>fabs(cP-0.5)) {
                //         cout << "convergence" << endl;
                // }
        // }

        // double valExacte = -cos(M_PI) + cos(0);
}
