//Código tomado de https://www.geeksforgeeks.org/runge-kutta-4th-order-method-solve-differential-equation/

#include <fstream>
#include <iostream>
#include<stdio.h> 

using namespace std;

float nl= 1; // friccion para velocidades bajas 
float nm=3/2; //friccion para velocidades medias
float nh= 2; //friccion para velocidades altas

float fo,f1,f2,f3;





// A sample differential equation "dy/dx = (x - y)/2" 
float dydx(float x, float y) 
{ 
	return((x - y)/2); 
} 

// Finds value of y for a given x using step size h 
// and initial value y0 at x0. 
float rk(float x0, float y0, float x, float h) 
{ 
	int n = (int)((x - x0) / h); 
	float k1, k2, k3, k4, k5; 
	// Iterate for number of iterations 
	float y = y0; 
	for (int i=1; i<=n; i++) 
	{ 
		// Apply Runge Kutta Formulas to find 
		// next value of y 
		k1 = h*dydx(x0, y); 
		k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1); 
		k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2); 
		k4 = h*dydx(x0 + h, y + k3); 

		// Update next value of y 
		y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);; 

		// Update next value of x 
		x0 = x0 + h; 
	} 

	return y; 
} 

int main() 
{ 
	float x0 = 0, y = 1, x = 2, h = 0.2; 
	rk(x0, y, x, h); 
	return 0; 
} 
