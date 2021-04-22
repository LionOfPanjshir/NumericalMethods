#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void Gseid(float A[][3], float b[], int n, float x[], int imax, float es, float lambda)
{
	for (int i = 0; i < n; i++)
	{
		float dummy = A[i][i];
		for (int j = 0; j < n; j++)
		{
			A[i][j] = A[i][j] / dummy;
		}
		b[i] = b[i] / dummy;
	}
	for (int i = 0; i < n; i++)
	{
		float sum = b[i];
		for (int j = 0; j < n; j++)
		{
			if (i != j) sum = sum - A[i][j];
		}
		x[i] = sum;
	}

	int iter = 1;
	int sentinel = 1;
	do
	{
		for (int i = 0; i < n; i++)
		{
			float old = x[i];
			float sum = b[i];
			for (int j = 0; j < n; j++)
			{
				if (i != j) sum = sum - A[i][j] * x[j];
			}
			x[i] = lambda*sum + (1 - lambda)*old;
			if ((sentinel == 1) && (x[i] != 0))
			{
				float ea = abs((x[i] - old) / x[i]) * 100;
				if (ea>es) sentinel = 0;
			}
		}
		iter++;
	} while ((sentinel != 1) && (iter <= imax));
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

void printvector(float A[], int n)
{
	int i;
	for (i = 0; i < n; i++){
		cout << setw(10) << A[i] << " ";
		cout << endl;
	};
}

int main()
{
	float A[3][3] = { { 3, -.1, -.2 }, { .1, 7, -.3 }, { .3, -.2, 10 } };
	float b[3] = { 7.85, -19.3, 71.4 };
	int n = 3;
	float x[3];
	float es = 0.05;
	int imax = 50;
	float lambda = 1.5;
	printmatrix(A, 3, 3);
	Gseid(A, b, n, x, imax, es, lambda);
	printmatrix(A, 3, 3);
	printvector(x, 3);
}