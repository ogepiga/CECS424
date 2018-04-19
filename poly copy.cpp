#include <iostream>
#include <cmath>

using namespace std;

double poly(double *params, double size, double x)
{
	double y =0;
	for (int n = 0; n<=size-1; n++){		
		y += params[n]*(pow(x,n));
	}
	return y;
}

int main()
{
	int size = 3;
	double *params = new double[size];
	params[0] = 3.4;
	params[1] = 0.32;
	params[2] = 0.134;

	double x = 4;

	cout << (x*x*params[2] + x*params[1] + params[0]) << endl;
 	cout << poly(params, 3, x) << endl;
}