#include <iostream>
#include <omp.h>
#include <fstream>

using namespace std;

float seq(int n)
{
	float num0 = 0, num1 = 1, num2 = 1; //1st numbers in Fibonacci sequence
	for (int i = 0; i < n-1; i++)
	{
		num2 = num0 + num1; //Fibonacci # is sum of previoues two
		num0 = num1; //Exchange values for next # in sequence to be calculated
		num1 = num2;
	}

	return num2;
}

int main()
{
	int n=0;
	/* Used to create table
	ofstream table;
	table.open("table.csv");
	*/
	while (n != 64)
	{
		cout << "n: ";
		cin >> n;

		double start = omp_get_wtime();
		cout << "\n" << seq(n);
		double end = omp_get_wtime();
		double elapsedms = (end - start) * 1000; //multiply by 1000 to get ms value
		cout << "\nTime: " << elapsedms << " ms" << endl;
		//table << n << "," << elapsedms << endl;
	}

	//table.close();

	return 0;
}