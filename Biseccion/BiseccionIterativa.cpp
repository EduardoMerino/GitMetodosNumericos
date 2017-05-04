/*
Eduardo Merino.
2017
*/
#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>

//mi función a evaluar.
//#define FUNCION (pow(x,3)) + (5 * (pow(x,2))) + 2
#define FUNCION sin(x) + (2 * x) - 1
//#define FUNCION (pow(x, 4)) - (2 * (pow(x, 3))) - (3 * (pow(x, 2))) + (4 * x) - 4
//#define FUNCION ((pow(x,3)) - 1) / (x + 1)

using namespace std;

double x, lim0, lim1, xm;
x = 0.0;
lim0 = 0.0;
lim1 = 0.0;
xm = 0.0;
int c = 0;

double Biseccion(double x0, double x1) {

	x = x0;
	lim0 = FUNCION;

  x = x1;
  lim1 = FUNCION;

	//aquí regreso si un parametro es raiz.
  if(lim0 == 0){
    return  x0;
  }else if(lim1 == 0){
    return  x1;
  }else{
    c++;
  }//END if

	if ((lim0 * lim1) < 0) {

		xm = (x0 + x1) / 2;
		x = xm;
		lim1 = FUNCION;

		while ((lim0 * lim1) != 0) {

      c++;

			if ((lim0 * lim1) < 0) {
				x1 = xm;
				xm = (x0 + x1) / 2;
				x = xm;
				lim1 = FUNCION;
			}

			if ((lim0 * lim1) > 0) {
				x0 = xm;
				xm = (x0 + x1) / 2;
				x = xm;
				lim1 = FUNCION;
			}

		}//END while
	}else {
		//aquí valido si mi método no puede encontrar la raiz.
		cout << "No hay cambio de signo, la raiz no se encuentra entre esos dos puntos." << '\n';
		return 0;
	}//END if
	return xm;
}

int main() {

	double raiz = Biseccion(-2, 2);
	cout << "La raiz es: " << raiz << "\n";
  cout << "La consigue en: " << c << " iteracion(es). \n";
	return 0;
}
