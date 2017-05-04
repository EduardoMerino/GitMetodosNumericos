#include <iostream>
#include <cmath>
#define ITERACIONES 3

using namespace std;

double factorial(double n){
    double f=1;
    for(int c=2; c<=n; c++){
        f=f*c;
    }
    return(f);
}

int main(){
    double x,
    coseno=0,
    e_abs,
    e_rel;

    cout << "Dame el angulo en radianes:  ";
    cin >> x;
    cout << x << endl;

    int i=0;
    do{
        coseno = coseno +(pow(-1, i) * pow(x, 2*i))/factorial(2*i);
        e_abs = cos(x) - coseno;
        e_rel = abs(e_abs/cos(x));
        i++;
    }while(e_rel > 1E-10);

    cout << "Coseno aproximado: " << coseno << endl;
    cout << "Coseno por función: " << cos(x) << endl;



    return(0);
}
