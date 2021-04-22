#include <iostream>
#include <cmath>

using namespace std;

double Bisect(double xl, double xu, int imax, double ea, double osf);

double func(double osf, double T)
{
	//return pow(xl, 2) - (5 * xl) + 6;
	return (osf - exp((-139.34411) + ((1.575701*pow(10, 5)) / (T + 273.15)) - ((6.642308 * pow(10, 7)) / pow((T + 273.15), 2))
		+ ((1.243800 * pow(10, 10)) / pow((T + 273.15), 3)) - ((8.621949 * pow(10, 11)) / pow((T + 273.15), 4))));
}

int main()
{
	double xl=0, xu, imax, osf, ea;

		
		cout << "xl: ";
		cin >> xl;
		cout << "\nxu: ";
		cin >> xu;
		cout << "\nosf: ";
		cin >> osf;
		cout << "\nea: ";
		cin >> ea;
		cout << "\nimax: ";
		cin >> imax;

		cout << "\n\nThe root is " << Bisect(xl, xu, imax, ea, osf) << " with an error bound of " << ea << "%\n";

	return 0;
}

double Bisect(double xl, double xu, int imax, double ea, double osf)
{
	int iter = 0;
	double xrold = 0;
	double xr = (xl + xu) / 2;
	double err;
	double fxl, fxr;
	do
	{
		xr = (xl + xu) / 2;
		//if (xr != 0)
			//ea = fabs((xr - xrold) / xr) * 100;
		fxl = func(osf, xl);
		fxr = func(osf, xr);
		if (fxl*fxr < 0)
			xu = xr;
		else if (fxl*fxr>0)
		{
			xl = xr;
		} 
		err = fabs((xr - xrold) / xr) * 100;
		xrold = xr;
		iter++;
	} while (err > ea || iter < imax);
	return xr;
}