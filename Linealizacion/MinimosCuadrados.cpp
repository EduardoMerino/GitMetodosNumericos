#include <iostream>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <fstream>
#define ARRSIZE 31

using namespace std;
//Regresión Lineal

double grados[ARRSIZE];
double* ObtenerGrados(){
  ifstream file("GradosF_ene17.txt",  std::ios_base::in);
  int i = 0;
  double a;
  while(file >> a){
    grados[i] = a;
    i++;
  }
  file.close();

  return grados;
}

void MinimosCuadrados(){
  double *grad = ObtenerGrados();

  // La entrada en el array representa la temperatura máxima en F.
  // La pocisión en el arry representa el día del mes.
  double sumXY;
  int i = 0;
  for(; i < ARRSIZE; i++){
    sumXY += i * grad[i];
  }

  double sumX;
  int k = 0;
  for(; k < ARRSIZE; k++){
    sumX += k;
  }

  double sumY;
  int j = 0;
  for(; j < ARRSIZE; j++){
    sumY += grad[j];
  }

  double sumX2;
  int l = 0;
  for(; l < ARRSIZE; l++){
    sumX2 += i * i;
  }

  double a1 = ((ARRSIZE * sumXY) - (sumX * sumY)) / ((ARRSIZE * sumX2) - (sumX * sumX));
  double promedio = sumY / ARRSIZE;
  double a0 = promedio - (a1 * (sumX / ARRSIZE));

  cout << "a1 = " << a1 << '\n'; //Pendiente.
  cout << "a0 = " << a0 << '\n'; //Ordenada al origen.

}

int main(int argc, char const *argv[]) {
  double *grad = ObtenerGrados();
  /*
  int i = 0;
  for(; i < ARRSIZE; i++){
    cout << i + 1 << " " << grad[i] << '\n';
  }
  */

  MinimosCuadrados();

  return 0;
}
