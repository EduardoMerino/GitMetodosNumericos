#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;

double Simpson38(int n){
  //file has to be 2 numbers per Line
  //Separated by a blank space
  ifstream file("38.txt",  std::ios_base::in); //Replace this line to read different File
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

  double integral = 0.0;
  integral = y[0] + (3 * y[1]) + (3 * y[2]) + y[3];
  integral = integral / 8;
  integral = integral * (x[3] - x[0]);

  return integral;

}

int main(int argc, char const *argv[]) {
  double Integral = Simpson38(4);
  cout << "La integral aproximada por este método es: " <<  Integral << '\n';
  return 0;
}
