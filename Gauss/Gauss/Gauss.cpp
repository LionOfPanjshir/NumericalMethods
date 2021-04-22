#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void Substitute(float A[][3], int n, float b[], float x[])
{
	x[n - 1] = b[n - 1] / A[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		float sum = 0;
		for (int j = i + 1; j < n; j++)
		{
			sum = sum + A[i][j] * x[j];
		}
		x[i] = (b[i] - sum) / A[i][i];
	}
}

void Pivot(float A[][3], float b[], float s[], int n, int k)
{
	int p = k;
	float big = abs(A[k][k] / s[k]);

	for (int i = k + 1; i < n; i++)
	{
		float dummy = abs(A[i][k] / s[i]);
		if (dummy>big)
		{
			big = dummy;
			p = i;
		}
	}

	if (p != k)
	{
		for (int j = k; j < n; j++)
		{
			float dummy = A[p][j];
			A[p][j] = A[k][j];
			A[k][j] = dummy;
		}
		float dummy = b[p];
		b[p] = b[k];
		b[k] = dummy;
		dummy = s[p];
		s[p] = s[k];
		s[k] = dummy;
	}
}

void Eliminate(float A[][3], float s[], int n, float b[], float tol, int &er)
{
	for (int k = 0; k < n - 1; k++)
	{
		Pivot(A, b, s, n, k);
		if (abs(A[k][k] / s[k]) < tol)
		{
			er = -1;
			break;
		}
		for (int i = k + 1; i < n; i++)
		{
			float factor = A[i][k] / A[k][k];
			for (int j = k + 1; j < n; j++)
			{
				A[i][j] = A[i][j] - factor*A[k][j];
			}
			b[i] = b[i] - factor*b[k];
		}
	}
	if (abs(A[n - 1][n - 1] / s[n - 1]) < tol)
		er = -1;
}

void Gauss(float A[][3], float b[], int n, float x[], float tol, int &er)
{
	float s[3];
	er = 0;
	for (int i = 0; i < n; i++)
	{
		s[i] = abs(A[i][0]);
		for (int j = 1; j < n; j++)
		{
			if (abs(A[i][j]) >s[i])
				s[i] = abs(A[i][j]);
		}
	}

	Eliminate(A, s, n, b, tol, er);
	if (er != -1)
		Substitute(A, n, b, x);
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
	float b[3] = { 2, 9, 1 };
	float x[3];
	float A[3][3] = { { 1, 2, -1 }, { 5, 2, 2 }, { -3, 5, -1 } };
	int n = 3, er;
	float tol = .001;
	
	//cout << "A = \n"; printmatrix(A, 3, 3);
	
	Gauss(A, b, n, x, tol, er);

	cout << "The matrix A is: " << endl;
	printmatrix(A, 3, 3);
	cout << "\nAnd the solution x is: \n" << endl;
	printvector(x, 3);

	return 0;
}