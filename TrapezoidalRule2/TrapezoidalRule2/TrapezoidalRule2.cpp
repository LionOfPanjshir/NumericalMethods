#include <iostream>
#include <cmath>
#include <array>

using namespace std;

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
	double a = 0, b = 240;
	const int n = 8;
	double h = (b - a) / n;
	double y[n + 1] = { 0, 340, 1200, 1600, 2700, 3100, 3200, 3500, 3800 };

	double I = Trapm(h, n, y);

	cout << "a: " << a << " \nb: " << b << " \nn: " << n << " \nh: " << h << " \nI: " << I << endl;

	return 0;
}