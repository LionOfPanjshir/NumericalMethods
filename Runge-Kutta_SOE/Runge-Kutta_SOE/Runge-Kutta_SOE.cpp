#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int n = 2;
const int o = 7;

void Derivs(double x, double y[], double dy[])
{
	double f = 60, L = 30, E = 1.25*pow(10, 8), I = .05;
	dy[0] = y[1];
	dy[1] = (f / (2 * E*I))*pow((L-x),2);
}

void RK4(double &x, double y[], double &h)
{
	double k1[n];
	Derivs(x, y, k1);
	double ym[n];
	for (int i = 0; i < n; i++)
	{
		ym[i] = y[i] + k1[i]*(h / 2);
	}
	
	double k2[n];
	Derivs(x + h / 2, ym, k2);

	for (int i = 0; i < n; i++)
	{
		ym[i] = y[i] + k2[i]*(h / 2);
	}
	double k3[n];
	Derivs(x + h / 2, ym, k3);
	double ye[n];

	for (int i = 0; i < n; i++)
	{
		ye[i] = y[i] + k3[i]*h;
	}

	double k4[n];
	Derivs(x + h, ye, k4);
	double slope[n];

	for (int i = 0; i < n; i++)
	{
		slope[i] = (k1[i] + 2 * (k2[i] + k3[i]) + k4[i]) / 6;
		y[i] = y[i] + slope[i]*h;
	}

	x = x + h;
}

void Integrator(double &x, double y[], double &h, double &xend)
{
	do
	{
		if (xend - x < h) h = xend - x;
		RK4(x, y, h);
	} while (x < xend);
}

int main()
{
	double yi[n] = { 0, 0 };
	double xi = 0;
	double xf = 30;
	double dx = .5;
	double xout = 5;
	
	double x = xi;
	int m = 0;
	double xp[o];
	double y[n];
	xp[m] = x;
	double yp[o][n]; // = { { -10, 10, 0 }, { 28, -1, -1 }, { 1, 0, -2.666667 } };

	for (int i = 0; i < n; i++)
	{
		yp[m][i] = yi[i];
		y[i] = yi[i];
	}


	do
	{
		double xend = x + xout;
		if (xend > xf) xend = xf;
		double h = dx;
		Integrator(x, y, h, xend);
		m++;
		xp[m] = x;

		for (int i = 0; i < n; i++)
		{
			yp[m][i] = y[i];
		}
	} while (x < xf);

	int colw = 11;

	cout << "z" << setw(colw) << "y1" << setw(colw) << "y2" << endl;

	for (int i = 0; i < o; i++)
	{
		if (xp[i] >= 10) colw = 10;
		cout << fixed << setprecision(4) << xp[i] << setw(colw);
		for (int j = 0; j < n; j++)
		{
			cout << fixed << setprecision(4) << setw(colw) << yp[i][j];
		}
		cout << endl;
	}
}