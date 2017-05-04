//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <cmath>

using namespace std;

//n is the number of variables in system
int n;

//returns the value of the variable by simplifying
float jacobi(float matrix[], float aux[], int component);

//return an iterative error
float get_error(float x_prev[], float x[], int component);

int main(){
  cout << "How many variables? ";
  cin >> n;
  //a - coefficients of variables
  //b - coefficients of result of equation
  //x - current value of variable
  //x_prev - previous value of variable
  //aux - used for specifying a single equation
  //error - a vector with errors for each variable
  float a[n][n], b[n], x[n], x_prev[n], aux[n], error[n];

  //tolerance - allowed error difference
  float tolerance;
  //iterations - current iterations counter
  int iterations = 0;
  //max_iterations - number of iterations allowed
  int max_iterations;

  /*error_tolerance - boolean, true if all values
  in vector error are less than tolerance*/
  bool error_tolerance;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << "Coefficient of: " << i << ", " << j << ": ";
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    cout << "Equation " << i + 1 << " result: ";
    cin >> b[i];
  }

  cout << "Error: ";
  cin >> tolerance;

  cout << "Iterations: ";
  cin >> max_iterations;

  for(int i = 0; i < n; i++){
    cout << "Variable " << i << " initial value: ";
    cin >> x_prev[i];
  }

  do{
    for(int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        //shortening system to only one equation
        aux[j] = a[i][j];
      }

      //verifying new value of variables
      x[i] = (1/a[i][i]) * (b[i] - jacobi(aux, x_prev, i));
      //getting error of each variable
      error[i] = get_error(x, x_prev, i);
    }

    for(int i = 0; i < n; i++){
      if(error[i] <= tolerance){
        error_tolerance = true;
      }
      else{
        error_tolerance = false;
        break;
      }
    }

    cout << endl << "Iteration: " << iterations << endl;
    for(int i = 0; i < n; i++){
      //x current value is now previous value
      x_prev[i] = x[i];
      cout << "X" << i + 1 << " = " << x[i] << endl;
    }
    iterations++;
  } while( error_tolerance == false && iterations < max_iterations);
  cout << endl << "Execution ended" << endl << "Iterations: " << iterations - 1 << endl;

  for (int i = 0; i < n ; i++){
    cout << "X" << i + 1 << " approximate value = " << x[i] << endl;
  }
  return 1;
}

float get_error(float vector1[], float vector2[], int component){
  float error;

  // Absolute iterative error
  //error = fabs(vector1[component] - vector2[component]);

  // Relative iterative error
  error = fabs((vector1[component] - vector2[component]) / vector1[component]);
  return error;
}

float jacobi(float Matrix[], float aux[], int component){
  float temp = 0;
  for (int i = 0; i < n; i++){
    if (component != i){
      temp = temp + Matrix[i] * aux[i];
    }
  }
  return temp;
}
