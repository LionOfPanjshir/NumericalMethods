#include <iostream>
#include <fstream>
#include <omp.h>

using namespace std;

float seq(float n, float num0=0, float num1=1) //Recursive Fibonacci Function
{
	if (n == 0)
		return num0;
	else if (n == 1)
		return num1;
	else
		return seq(n-1, num1, num0+num1); //n-1 to countdown, num1 passed to num0 place, num0+num1 passed to num1 place
}

int main()
{
	float n=0;
	//ofstream table;              Used to create table with values.
	//table.open("table.csv");

	while (n != 64)
	{
		cout << "n: ";
		cin >> n;

		double start = omp_get_wtime();
		cout << "\n" << seq(n); 
		double end = omp_get_wtime();
		double elapsedms = (end-start)*1000; //multiply by 1000 to get ms value
		cout << "\nTime: " << elapsedms << " ms" << endl;
		//table << n << "," << elapsedms << endl;
	}

	//table.close();
	return 0;
}