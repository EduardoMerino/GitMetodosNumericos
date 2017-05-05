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
  double a;
  double b;
  while(file >> a >> b){
    x[i] = a;
    y[i] = b;
    i++;
  }
  file.close();

  double inpares = 0.0;
  for(int j = 1; j <= n-2;  j += 2){
    inpares = inpares + y[j] + 2;
  }

  double pares = 0.0;
  for(int k = 2; k <= n-3; k += 2){
    pares = pares + y[k];
  }

  return y[0] + (4 * inpares) + (2 * pares) + y[n];

}

int main(int argc, char const *argv[]) {
  double Integral = Simpson13(4);
  cout << "La Integral aproximada por este método es: " << Integral << '\n';
  return 0;
}
