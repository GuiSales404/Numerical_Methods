#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#define e 2.7182

using namespace std;

//equation place
double equation(double value){
  return ((-1 * (pow(e, value)/2)) + 2 * cos(value));
}

double falsePosition(double a, double b){
  double fa;
  double fb; 
  double eps = 0.0001;
  double x;
  double fx;
  int cont = 1; 

  cout << fixed << setprecision(4);

//if it's true, the convergence is not guaranteed 
  if(fa*fb > 0) return -1; 
  
//while it's true the gap [a, b] is bigger than the eps accepeted 
  while(abs(b-a) > eps){
    x = (a * equation(a) - b * equation(b)) / (equation(a) - equation(b)); //the point where the secant line intersects the x axis
    fx = equation(x); 
    fa = equation(a);
    fb = equation(b);

//if it's true, return the root value x
    if(abs(fb - fa) < eps) return x; 

    cout << cont << "° Interaction" << endl;
    cout << "a: " << a << ", f(a): " << fa << endl;
    cout << "b: " << b << ", f(b): " << fb << endl;
    cout << "x: " << x << ", f(x): " << fx << endl;
    cout << endl;

//att the gap values 
    if((fa*fx) > 0){
      a = x; 
    }
    if((fb*fx) > 0){
      b = x; 
    }

    cont++;
  }
  return (a+b)/2; 
}

int main() {
  cout << falsePosition(0.9, 1.0) << " is the xsi root.\n";
  return 0;
} 