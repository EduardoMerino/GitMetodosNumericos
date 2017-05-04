#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#define ERROR 0.0000001

using namespace std;

double x, x1, fx0, dfx0;
int counter;

double fun(double x){
   //return (log(x + 1)) + 1; //func 2
   //return ((1 - log(x)) / (pow(x,2))); //func 3
   //return (log(x) / x); //func 4
   //return pow(x,2); //func 5
   return pow(x, 3) + (5 * x) - 10;
}

double dfun(double x){
  //return (1 / (x + 1)); //func 2
  //return ((2 * log(x) - 3) / (pow(x,3))); //func 3
  //return ((1 - log(x)) / (pow(x,2))); //fun 4
  //return 2 * x; //func 5
  return (3 * pow(x,2)) + 5;
}

double calculaError(int t, double vant, double vact){
  //INPUT: tipo de Error, Valor Anterior, Valor Actual
  double err = 0.0;
  switch (t){
    case 0 :
      //Error Absoluto
      err = vant - vact;
      break;
    case 1 :
      //Error relativo
      err = (vant - vact) / vant;
      break;
    case 2 :
      //Error porcentual
      err = ((vant - vact) / vant) * 100;
      break;
  }
  return err;
}
double xant = 0.0;
double NewtonRaphson(double x0){

  //cout << "Ya entré al metodo newton Raphson" << '\n';

  x = x0;
  counter = 0;

  do{
    xant = x;

    fx0 = fun(x);
    dfx0 = dfun(x);
    x1 = x - (fx0 / dfx0);
    x = x1;
    counter ++;

    if(x1 != x1){
      cout << "La función se indetermina: " << '\n';
      return x1;
    }

    //cout << counter << " iteración" << '\n';
    //cout << "Raíz = " << x1 << '\n';
    //getchar();

  }while (calculaError(1, xant, x1) > ERROR );//ERROR
  cout << counter << " interacion(es)" << '\n';
  return x1;

}

int main(int argc, char const *argv[]) {

  double num;
  cout << "Dame un número: ";
  cin >> num;
  double raiz = NewtonRaphson(num);
  cout << "La raiz es: " << raiz << "\n";

  return 0;
}
