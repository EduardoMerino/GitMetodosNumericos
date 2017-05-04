#include <iostream>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;


double multiplicatoriaL(double num, int i, int n, double* x){
  double a = 1;
  for(int j=0; j < n; j++){
    if(i != j){
      a = a * ((num - x[j]) / (x[i] - x[j]));
      //cout << "multiplicatoriaL i: " << i <<" , j: " << j << " a: " << a << '\n';
    }
  }
  return a;
}

double sumatoriaF(double num, int n, double* y, double* x){ //the z is really the array of x
  double a = 0.0;
  for(int i=0; i < n; i++){
    a += multiplicatoriaL(num, i, n, x) * y[i];
  }
  return a;
}

double Lagranje(int n, double num){
  //file has to be 2 numbers per Line
  //Separated by a blank space
  ifstream file("EjemploInterpolacion.txt",  std::ios_base::in); //Replace this line to read different File
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

  double res = sumatoriaF(num, n, y, x);
  return res;
}

int main(int argc, char const *argv[]) {
  double num;
  cout << "Dame el valor a buscar en la linea: ";
  cin >> num;
  double ans = Lagranje(3, num);
  cout << "(" << num <<", " << ans <<")" << '\n';

  return 0;
}
