#include <iostream>
#include <cmath>

using namespace std;

double dr, ds, errorDer, errorDes, disc;

int iteraciones = 0, raicesR, raicesI, grado;

double discriminante(double r, double s) {
	return pow(r, 2) + 4*s;
}

double raiz1(double r, double s, double disc) {
	return (r + sqrt(disc)) / 2;
}

double raiz2(double r, double s, double disc) {
	return (r - sqrt(disc)) / 2;
}

double* divSint(double *polinomio, double raiz) {
	double *res = new double[grado - 1];
	res[0] = polinomio[0];
	for (int i = 1; i < grado; i++) {
		res[i] = polinomio[i] + (raiz*res[i - 1]);
	}
	grado--;
	return res;
}

double Bairstow(double r, double s, double a[], int tamaño) {

	double *b = new double[tamaño];

	double *c = new double[tamaño - 1];

	grado = tamaño - 1;

	double *raices = new double[grado - 1];

	while (grado >= 3){
		do {
			for (int i = 0; i < tamaño; i++) {
				if (i == 0) {
					b[i] = a[i];
				}
				else if (i == 1) {
					b[i] = a[i] + r*(b[0]);
				}
				else {
					b[i] = a[i] + r*(b[i - 1]) + s*(b[i - 2]);
				}
			}

			for (int i = 0; i < tamaño - 1; i++) {
				if (i == 0) {
					c[i] = b[i];
				}
				else if (i == 1) {
					c[i] = b[i] + r*(c[0]);
				}
				else {
					c[i] = b[i] + r*(c[i - 1]) + s*(c[i - 2]);
				}
			}

			dr = ((-b[tamaño - 2] * c[tamaño - 3]) - (c[tamaño - 4] * -b[tamaño - 1]))
				/ ((c[tamaño - 3] * c[tamaño - 3]) - (c[tamaño - 4] * c[tamaño - 2]));
			ds = ((c[tamaño - 3] * -b[tamaño - 1]) - (-b[tamaño - 2] * c[tamaño - 2]))
				/ ((c[tamaño - 3] * c[tamaño - 3]) - (c[tamaño - 4] * c[tamaño - 2]));

			r = r + dr;
			s = s + ds;

			errorDer = abs(dr / r) * 100;
			errorDes = abs(ds / s) * 100;

			iteraciones++;

		} while (errorDer > 0.05 && errorDes > 0.05);

		disc = discriminante(r, s);

		if (disc < 0) {
			raicesI += 2;
			grado -= 2;
		}
		if (disc == 0) {
			raices[raicesR] = raiz1(r, s, disc);
			raicesR++;
			grado -= 1;
		}
		else {
			raices[raicesR] = raiz1(r, s, disc);
			a = divSint(a, raices[raicesR]);
			raicesR++;
			tamaño--;
			raices[raicesR] = raiz2(r, s, disc);
			a = divSint(a, raices[raicesR]);
			raicesR++;
			tamaño--;
		}
	}
	return 0.0;
}

int main() {
	double a[] = {1, -3.5, 2.75, 2.125, -3.875, 1.25};
	Bairstow(-1, -1, a, sizeof(a) / sizeof(a[0]));
	return 0;
}

/*
#include <cmath>
#include <math.h>
#include <stdio.h>

using namespace std;

int r = -1, s = -1;

int bcount, rcount, scount, pcount;

//this only works for len < 3
void divicionSinteticaDoble(double polinomio[], int len){

  double *rn = new double[len - 1];
  double *sn = new double[len - 2];
  double *b = new double[len];
  double *c = new double[len];

  bcount = len;
  rcount = len - 1;
  scount = len - 2;
  pcount = len;

  //Calcular B
  b[bcount--] = polinomio[pcount--];
  rn[rcount--] =  r * b[bcount];
  b[bcount--] = polinomio[pcount--] + rn[rcount];

  do{
    rn[rcount--] = b[pcount] * r;
    sn[scount--] = rn[rcount + 1] * s;
    b[bcount--] = polinomio[pcount--] + rn[rcount] + sn[scount];
  }while(bcount < 0);
  //FIN Calcular B

  //imprime B
  int i = len - 1;
  for(; i >= 0; i--){
    cout << b[i] << "x^" << i << " + ";
  }
  cout << '\n';
  //FIN imprime B

  bcount = len;
  rcount = len - 1;
  scount = len - 1;
  pcount = len;

  //Calcular C
  c[bcount--] = polinomio[pcount--];
  rn[rcount] = c[bcount] * r;
  c[bcount--] = polinomio[pcount--] + rn[rcount];

  do{
    rn[rcount--] = b[pcount] * r;
    sn[scount--] = rn[rcount + 1] * s;
    c[bcount--] = polinomio[pcount--] + rn[rcount] + sn[scount];
  }while(bcount < 0);
  //Fin Calcular C

  //imprime C
  int j = len - 1;
  for(; j >= 0; j--){
    cout << c[j] << "x^" << j << " + ";
  }
  cout << '\n';
  //FIN imprime C
}

int main(int argc, char const *argv[]) {
  double polinomio[6] = {1.25, -3.875, 2.125, 2.75, -3.5, 1};
  divicionSinteticaDoble(polinomio, 6);

  return 0;
}
*/
