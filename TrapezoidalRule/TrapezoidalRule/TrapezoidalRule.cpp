#include <iostream>
#include <cmath>
#include <array>

using namespace std;

double func(double t)
{
	return (sqrt((9.8*68.1) / 0.25))*tanh(sqrt((9.8*0.25) / 68.1)*t);
}

double Trapm(double h, int n, double f[])
{
	double sum = f[0];
	for (int i = 1; i < n; i++)
	{
		sum = sum + 2 * f[i];
	}
	sum += f[n];

	return h*(sum / 2);
}

int main()
{
	double a=0, b=10;
	const int n = 5;
	double h = (b - a) / n;
	double y[n + 1];

	for (int i = 0; i == n; i++)
	{
		y[i] = func(a + i*h);
	}

	double I = Trapm(h, n, y);

	cout << "a: " << a << " \nb: " << b << " \nn: " << n << " \nh: " << h << " \nI: " << I << endl;

	return 0;
}