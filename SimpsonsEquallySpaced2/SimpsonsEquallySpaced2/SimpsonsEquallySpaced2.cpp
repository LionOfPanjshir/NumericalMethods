#include <iostream>
#include <cmath>
#include <array>
#include <iomanip>

using namespace std;

double Simp13(double h, double f0, double f1, double f2)
{
	return 2 * h*((f0 + 4 * f1 + f2) / 6);
}

double Simp38(double h, double f0, double f1, double f2, double f3)
{
	return 3 * h*(f0 + 3 * (f1 + f2) + f3) / 8;
}

double Simp13m(double h, int n, double f[]);

double SimpInt(double a, double b, int n, double f[]);

double Trap(double h, double f0, double f1)
{
	return h / 2 * (f0 + f1);
}

int main()
{
	const int n = 7;
	double a = 0, b = 1.2;
	double h = (b - a) / (n-1);
	double y[n] = { .2, .3683, .3819, .2282, .0486, .0082, .1441 };

	double I = (1/pow(10,-5))*SimpInt(a, b, n, y);

	cout << "a: " << a << " \nb: " << b << " \nn: " << n << " \nh: " << h << " \nI: " << I << endl;
}

double Simp13m(double h, int n, double f[])
{
	double sum = f[0];

	for (int i = 1; i < n - 1; i += 2)
	{
		sum += 4 * f[i] + 2 * f[i + 1];
	}

	sum += 4 * f[n - 1] + f[n];

	return h*sum / 3;
}

double SimpInt(double a, double b, int n, double f[])
{
	double h = (b - a) / n;
	double sum = 0;

	if (n == 1) sum = Trap(h, f[n - 1], f[n]);

	else {
		double m = n;
		double odd = n / 2.0 - (int)(n / 2);

		if (odd > 0 && n > 1)
		{
			sum += Simp38(h, f[n - 3], f[n - 2], f[n - 1], f[n]);
			m = n - 3;
		}
		if (m > 1) sum += Simp13m(h, m, f);
	}

	return sum;
}