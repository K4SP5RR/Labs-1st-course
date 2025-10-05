#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
double Triangle_Matr(double**, int);


void Copy(double** a, double** b, int length) {

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			b[i][j] = a[i][j];
		}
	}

	return;
}

double Mass_Minor(double** mas, double** mas_minor, int n, int x, int y) {
	double det;
	int i1 = 0, j1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != x)
		{
			for (int j = 0; j < n; j++)
			{
				if (j != y) {
					mas_minor[i1][j1] = mas[i][j];
					j1++;
				}
			}
			i1++;
			j1 = 0;
		}
	}

	det = Triangle_Matr(mas_minor, n - 1);
	
	return det;
}


double Triangle_Matr(double** a, int length) {
	double det = 1, k;
	double** mas;
	mas = (double**)malloc(length * sizeof(double*));
	
	for (int i = 0; i < length; i++)
	{
		mas[i] = (double*)malloc(length * sizeof(double));
	}
	Copy(a, mas, length);
	
	
	for (int j = 0; j < length - 1; j++)
	{
		for (int i = j + 1; i < length; i++)
		{
			if (mas[i][j] == 0)
			{
				continue;
			}
			if (mas[j][j] == 0)
			{
				int c = i;
				while (c < length)
				{
					if (mas[c][j] != 0)
					{
						int rev;
						for (int g = 0; g < length; g++)
						{
							rev = mas[j][g];
							mas[j][g] = mas[c][g];
							mas[c][g] = rev;
						}
						det *= -1;
						break;
					}
					c++;
				}
			}
			if (mas[i][j] == 0)
			{
				continue;
			}
			k = mas[j][j] / mas[i][j];
			det *= 1 / k;
			for (int t = 0; t < length; t++)
			{
				mas[i][t] *= k;
				mas[i][t] -= mas[j][t];
			}
		}
	}
	for (int i = 0; i < length; i++)
	{	
		det *= mas[i][i];
	}

	for (int i = 0; i < length; i++)
	{
		free(mas[i]);
	}
	free(mas);
	
	return det;
}

int main() {
	srand(time(NULL));
	double** mas, ** mas_minor, **mas_reverse, det;
	int n;
	scanf_s("%d", &n);
	mas_minor = (double**)malloc((n - 1) * sizeof(double*));
	mas = (double**)malloc(n * sizeof(double*));
	mas_reverse = (double**)malloc(n * sizeof(double*));
	for (int i = 0; i < n; i++)
	{
		mas[i] = (double*)malloc(n * sizeof(double));
		mas_reverse[i] = (double*)malloc(n * sizeof(double));
	}
	for (int i = 0; i < n-1; i++)
	{
		mas_minor[i] = (double*)malloc((n - 1) * sizeof(double));
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = rand()%41-20;
			printf_s("%lf ", mas[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
	det = Triangle_Matr(mas, n);
	printf_s("det = %lf", det);
	
	if (det == 0)
	{
		return 0;
	}
	printf_s("\n");


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas_reverse[i][j] = Mass_Minor(mas, mas_minor, n, i, j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf_s("%lf ", mas_reverse[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas_reverse[i][j] *= pow(-1, i + j);
		}
	}
	
	int c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
			{
				c = mas_reverse[i][j];
				mas_reverse[i][j] = mas_reverse[j][i];
				mas_reverse[j][i] = c;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas_reverse[i][j] /= det;
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf_s("%lf ", mas_reverse[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");

	for (int i = 0; i < n; i++)
	{
		free(mas[i]);
		free(mas_reverse[i]);
	}
	free(mas);
	free(mas_reverse);
	
	
	for (int i = 0; i < n-2; i++)
	{
		free(mas_minor[i]);
	}
	free(mas_minor);
	return 0;
}
