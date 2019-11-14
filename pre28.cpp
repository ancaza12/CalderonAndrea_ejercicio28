//Código tomado de https://www.geeksforgeeks.org/runge-kutta-4th-order-method-solve-differential-equation/

#include <fstream>
#include <iostream>
#include<stdio.h> 
#include <cmath>
#include <string> // String Manipulation c_str
#include <sstream> // Used For Variable String Name
using namespace std;

const double K=50.0;
double m= 0.2; //masa
const double nl= 1; // friccion para velocidades bajas 
const double nm=3/2; //friccion para velocidades medias
const double nh= 2; //friccion para velocidades altas

double f0(double t, double y0, double y1){
  return y1;
}

double f1(double t, double y0, double y1){
  return (-K/m)* std::pow (y0, nl);
}

float dydx(float x, float y) 
{ 
    return((x - y)/2); 
} 

float rk(float x0, float y0, float x, float h) 
{
	int n = (int)((x - x0) / h); 
	float k1, k2, k3, k4, k5; 
	float y = y0; 
	for (int i=1; i<=n; i++) 
	{ 
		k1 = h*dydx(x0, y); 
		k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1); 
		k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2); 
		k4 = h*dydx(x0 + h, y + k3); 

		y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);; 
		x0 = x0 + h; 
        return y; 

	} 

	return y; 
} 

int main() 
{ 
    const double ti=0;
    const double tf=17.0;
    double x=1;
    double v=0;
	float y = 1;
    float h = 0.2; 
	rk(ti, y, tf, h); 
	return 0; 
} 