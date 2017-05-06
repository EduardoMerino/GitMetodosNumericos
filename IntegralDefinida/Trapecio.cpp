#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>

using namespace std;

double f(double x){
  //return  0.2 + (25 * x) - (200 * (pow(x,2))) + (675 * (pow(x,3)))
          //- (900 * (pow(x,4))) + (400 * (pow(x,5)));
  return exp(pow(x, 2));
}

void Trapecio(double a, double b, int n){
  double h = (b - a) / n;
	double res = 0;

	res += f(a);
	for (double i = a + h; i < b; i += h){
    res += 2 * f(i);
  }
  res += f(b);
	res = res* (h / 2);
	cout << "Area aproximada: " << res << endl;
	//cout << "Error: " << error(res) << endl;
}

int main(int argc, char const *argv[]) {
  double inf = 0;
  double sup = 0;
  int num = 0;
  cout << "Dame el límite inferior: ";
  cin >> inf;
  cout << "Dame el límite superior: ";
  cin >> sup;
  cout << "Dame el número de Trapecios: ";
  cin >> num;
  Trapecio(inf, sup, num);
  //cout << "Integral: " << ans << '\n';
  return 0;
}
