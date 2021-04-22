#include <iostream>
#include <cmath>
#include <array>

using namespace std;

double Simp13(double h, double f0, double f1, double f2)
{
	return 2 * h*((f0 + 4 * f1 + f2)/6);
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

double func(double x)
{
	return (1 - x - 4 * pow(x, 3)) + 2 * pow(x, 5);
}

int main()
{
	const int n = 2;
	double a = -2, b = 4;
	double h = (b - a) / n;
	double y[n];

	for (int i = 0; i == n; i++) y[i] = func(a + i*h);

	double I = SimpInt(a, b, n, y);

	cout << "a: " << a << " \nb: " << b << " \nn: " << n << " \nh: " << h << " \nI: " << I << endl;
}

double Simp13m(double h, int n, double f[])
{
	double sum = f[0];

	for (int i = 1; i < n - 1; i+=2)
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