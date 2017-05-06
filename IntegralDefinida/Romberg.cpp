#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double x) {

    return exp(pow(x,2));
}

double trapezium(int n, double a, double b) {

    double h = (b-a)/n;
    double _a = a;
    double integral = f(a) + f(b);
    double integralSum = 0;
    for(double i = _a + h; i < b; i += h) {
        integralSum += f(i);
    }
    return (integral+ 2*integralSum)*h/2;
}


double rombergHelper(double* approximationsLvl1, int k, int me) {
    if(k == 1) {
        return approximationsLvl1[me];
    }
    else {
        return (pow(4, k-1)*rombergHelper(approximationsLvl1, k-1, me+1)
         - rombergHelper(approximationsLvl1, k-1, me))/(pow(4, k-1)-1);
    }
}

double romberg(double a, double b, int numberOfApprox) {

    double initialApprox[numberOfApprox];
    double h = (b-a)/numberOfApprox;
    double integral;

    for(int i = 0; i < numberOfApprox; i++) {
        double n;
        cout << "Número de trapecios para la approximación " << i + 1 << ": ";
        cin >> n;
        initialApprox[i] = trapezium(n, a, b);
    }

    integral = rombergHelper(initialApprox, numberOfApprox, 0);
    return integral;
}

int main() {
    double integral, a, b;
    int numberOfApprox;

    cout << "Límite inferior = ";
    cin >> a;
    cout << "Límite superior = ";
    cin >> b;
    cout << "Número de aproximaciones iniciales = ";
    cin >> numberOfApprox;

    integral = romberg(a, b, numberOfApprox);

    cout << "Integral = " << integral << endl;

}
