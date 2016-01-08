#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void Substitute(float A[][3], int o[], int n, float b[], float x[])
{
	for (int i = 1; i < n; i++)
	{
		float sum = b[o[i]];

		for (int j = 0; j <= i - 1; j++)
		{
			sum = sum - A[o[i]][j] * b[o[j]];
		}
		b[o[i]] = sum;
	}
	x[n - 1] = b[o[n - 1]] / A[o[n - 1]][n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		float sum = 0;
		for (int j = i + 1; j < n; j++)
		{
			sum = sum + A[o[i]][j] * x[j];
		}
		x[i] = (b[o[i]] - sum) / A[o[i]][i];
	}
}

void Pivot(float A[][3], int o[], float s[], int n, int k)
{
	int p = k;
	float big = abs(A[o[k]][k] / s[o[k]]);
	for (int i = k + 1; i < n; i++)
	{
		float dummy = abs(A[o[i]][k] / s[o[i]]);
		if (dummy>big)
		{
			big = dummy;
			p = i;
		}
	}
	int dummy = o[p];
	o[p] = o[k];
	o[k] = dummy;
}

void Decompose(float A[][3], int n, float tol, int o[], float s[], int &er)
{
	for (int i = 0; i < n; i++)
	{
		o[i] = i;
		s[i] = abs(A[i][0]);
		for (int j = 1; j < n; j++)
		{
			if (abs(A[i][j])>s[i])
				s[i] = A[i][j];
		}
	}
	for (int k = 0; k < n - 1; k++)
	{
		Pivot(A, o, s, n, k);
		if (abs(A[o[k]][k] / s[o[k]]) < tol)
		{
			er = -1;
			break;
		}
		for (int i = k + 1; i < n; i++)
		{
			float factor = A[o[i]][k] / A[o[k]][k];
			A[o[i]][k] = factor;
			for (int j = k + 1; j < n; j++)
			{
				A[o[i]][j] = A[o[i]][j] - factor*A[o[k]][j];
			}
		}
		if (abs(A[o[k]][k] / s[o[k]]) < tol)
		{
			er = -1;
		}
	}
}

void MatrixInverse(float A[][3], float AI[][3], float b[], int n, float tol, float x[], int &er)
{
	int o[3];
	float s[3];
	er = 0;
	Decompose(A, n, tol, o, s, er);
	if (er == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) b[j] = 1;
				else b[j] = 0;
			}
			Substitute(A, o, n, b, x);
			for (int j = 0; j < n; j++)
			{
				AI[j][i] = x[j];
			}
		}
	}
	else cout << "\nill-conditioned system" << endl;
}

void printmatrix(float A[][3], int n, int m)
{//Prints out matrix A
	int i; int j;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			cout << setw(10) << A[i][j] << " ";
		}; cout << endl;
	};
}

void printvector(float A[], int n)
{//Prints out matrix A
	int i;
	for (i = 0; i < n; i++){
		cout << setw(10) << A[i] << " ";
		cout << endl;
	};
}

void multiply_matrices(float A[][3], float B[][3], float C[][3], int n, int m, int p)
{//calculates C(nxm) = A(nxp)*B(pxm)
	int i; int j; int k;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			C[i][j] = 0;
			for (k = 0; k < p; k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			};
		};
	};
}

int main()
{
	float b[3] = { 2, 9, 1 };
	float x[3];
	float A[3][3] = { { 1, 2, -1 }, { 5, 2, 2 }, { -3, 5, -1 } };
	float AA[3][3] = { { 1, 2, -1 }, { 5, 2, 2 }, { -3, 5, -1 } };
	float AI[3][3]; // = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
	float B[3][3];
	int n = 3, er;
	float tol = .001;

	cout << "A = \n";
	printmatrix(A, 3, 3);

	MatrixInverse(AA, AI, b, n, tol, x, er);
	cout << "\nThe inverse is: \n";
	printmatrix(AI, 3, 3);
	multiply_matrices(A, AI, B, 3, 3, 3);
	cout << "\nInverse multiplied by the original: \n";
	printmatrix(B, 3, 3);
	//printmatrix(A, 3, 3);
	//printvector(x, 3);

}