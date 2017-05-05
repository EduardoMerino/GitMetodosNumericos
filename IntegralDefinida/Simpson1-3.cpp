#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;

double Simpson13(int n){
  //file has to be 2 numbers per Line
  //Separated by a blank space
  ifstream file("simpsonPuntos.txt",  std::ios_base::in); //Replace this line to read different File
  double x[n];
  double y[n];
  int i = 0;
  double a = 0.0;
  double b = 0.0;
  while(file >> a >> b){
    x[i] = a;
    y[i] = b;
    i++;
  }
  file.close();

  double pares = 0.0;
  for(int j = 1; j <= n-2;  j += 2){
    pares += y[j];
  }

  double inpares = 0.0;
  for(int k = 2; k <= n-3; k += 2){
    inpares += y[k];
  }

  double ancho = (x[n - 1] - x[0]);
  double sumas = y[0] + (4 * pares) + (2 * inpares) + y[n - 1];
  return (x[n-1] - x[0]) * (sumas / (3 * (n - 1)));

}

int main(int argc, char const *argv[]) {
  double Integral = Simpson13(5);
  cout << "La Integral aproximada por este método es: " << Integral << '\n';
  return 0;
}
