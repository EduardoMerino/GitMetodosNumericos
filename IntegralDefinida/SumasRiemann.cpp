#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>

double f(double x){
  return  0.2 + (25 * x) - (200 * (pow(x,2))) + (675 * (pow(x,3))) - (900 * (pow(x,4))) + (400 * (pow(x,5)));
}

double Riemann(double a, double b, int n){
  double sum = 0.0;
  double i = a;
  double base = (b - a) / n;
  for(; i <= b; i = i + base){
    sum += f(i) * base;
    //std::cout << "i: " << i << " sum: " << sum << '\n';
  }
  return sum;
}
int main(int argc, char const *argv[]) {
  double ans = Riemann(0, 0.8, 80);
  std::cout << "Integral: " << ans << '\n';
  return 0;
}
