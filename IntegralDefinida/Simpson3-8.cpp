#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;

double Simpson38(double* y){
  double integral = 0.0;
  integral = y[0] + (3 * y[1]) + (3 * y[2]) + y[3]
  integral = integral * (y[3] - y[0]);
  integral = integral / 8;
  return integral;

}

int main(int argc, char const *argv[]) {
  double y[] = {};
  double Integral = Simpson38(y);
  std::cout << "La integral aproximada por este método es: " <<  Integral << '\n';
  return 0;
}
