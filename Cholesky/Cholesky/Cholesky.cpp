#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void decomp(float A[][3], int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i <= k - 1; i++)
		{
			float sum = 0;
			for (int j = 0; j <= i - 1; j++)
			{
				sum += A[i][j] * A[k][j];
			}
			A[k][i] = (A[k][i] - sum) / A[i][i];
		}
		float sum = 0;
		for (int j = 0; j <= k - 1; j++)
		{
			sum += A[k][j] * A[k][j];
		}
		A[k][k] = sqrt(A[k][k] - sum);
	}
}

void printmatrix(float A[][3], int n, int m)
{
	int i; int j;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			cout << setw(10) << A[i][j] << " ";
		}; cout << endl;
	};
}

int main()
{
	float A[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5} };
	int n = 3;

	decomp(A, n);
	printmatrix(A, 3, 3);
}