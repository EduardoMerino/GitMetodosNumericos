//Método Gauss-Seidel
#include <iostream>
#include <cmath>
#include <math.h>
#define ERROR 0.00001

using namespace std;

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

//Modifica estas funciones según el sistema
double fun1(double y, double z){
  //the x one
  return (3 - y - z) / 6;
}

double fun2(double x, double z){
  //the y one
  return (40 - (6 * x) - z) / 9;
}

double fun3(double x, double y){
  //the z one
  return (50 + (3 * x) - y) / (-12);
}

int counter = 0;
//Modifica estas variables segun el sistema
double xant = 0.0, yant = 0.0, zant = 0.0;

void GaussSeidel(double x, double y, double z){
  do{
    counter++;

    xant = x;
    yant = y;
    zant = z;

    x = fun1(y , z);
    y = fun2(x, z);
    z = fun3(x, y);

    if(isinf(x) || isinf(y) || isinf(z)){
      cout << "La funcion diverge" << '\n';
      break;
    }

  }while (abs(calculaError(1, xant, x)) > ERROR || abs(calculaError(1, yant, y)) > ERROR); //ERROR
  //Especifica que tipo de error hay que calcular
  cout << counter << " iteracion(es)." << "\n\n";
  cout << "x = " << x << '\n';
  cout << "y = " << y << '\n';
  cout << "z = " << z << '\n';
}

int main(int argc, char const *argv[]) {
  GaussSeidel(0 , 0, 0);
  //cout << "x = "<< res[0] << " y = " << res [1] << '\n';

  return 0;
}
