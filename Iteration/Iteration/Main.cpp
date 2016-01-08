#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double x = 1.0; double es = 1.0e-6; int maxit = 100;
	double sol; double solold; int iter; double fac; double ea;

	printf("\n----------------------------------\n");
	printf("\n iteration solution rel.error\n");
	printf("\n---------------------------------\n");

	iter = 1; sol = 1; ea = 100; fac = 1;
	printf("\n %5i %12.10f ", iter, sol, ea);
	do {
		solold = sol; fac = fac*iter;
		sol = sol + pow(x, iter) / fac;
		iter++;
		if (sol != 0)
			ea = abs((sol - solold) / sol) * 100;
		printf("\n &5i %12.10f ", iter, sol, ea);
	} while (ea > es && iter < maxit);
	if (ea <= es)
	{
		printf("\n---------------------------n");
		printf("\nsolution  x = %12.10f \n", sol);
		printf("\nerror = %12.10f \n", ea);
		printf("\n---------------------------n");
	}
	else if (iter >= maxit)
	{
		cout << "divergence - no solution" << endl;
	};

	system("pause");

	return 0;
}