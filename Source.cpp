#include "Header.h"
#include "stdio.h"
#include "stdlib.h"

void bubble_sorting(int* a, int length)
{
	int c;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				c = a[j];
				a[j] = a[j + 1];
				a[j + 1] = c;
			}
		}
	}
	return;
}

void direct_selection_sorting(int* a, int length)
{
	int c;
	for (int i = 1; i < length; i++)
	{
		for (int j = 0; j < length - i; j++)
		{
			if (a[length - i] < a[j])
			{
				c = a[length - i];
				a[length - i] = a[j];
				a[j] = c;
			}
		}
	}
	return;
}

void direct_inserting_sorting(int* a, int length)
{
	int c, j;
	for (int i = 1; i < length; i++)
	{
		j = 0;
		while (a[i - j] < a[i - j - 1] && i - j >= 0)
		{
			c = a[i - j];
			a[i - j] = a[i - j-1];
			a[i - j-1] = c;
			j++;
		}
	}
	return;
}

void Shaker(int* a, int length) {
	int l = 0, r = length-1, rt, lt, c, i; 

	while(r>l)
	{
		rt = l;
		for (i = l; i < r; i++)
		{
			if (a[i] > a[i + 1])
			{
				c = a[i];
				a[i] = a[i + 1];
				a[i + 1] = c;
				rt = i;
			}
		}
		r = rt;
		lt = r;
		for (i = r; i > l; i--)
		{
			if (a[i] < a[i - 1])
			{
				c = a[i];
				a[i] = a[i - 1];
				a[i - 1] = c;
				lt = i;
			}
		}
		l = lt;
	}
	return;
}

void Print_Mass(int* a, int length) {
	for (int i = 0; i < length; i++)
	{
		printf_s("%d ", a[i]);
	}
	printf_s("\n");
	return;
}
void Print_Mass_Tabl(double* time, int length, char x)
{
	printf_s("%c:\t", x);
	
	for (int i = 0; i < length; i++)
	{
		printf_s("%lf\t ", time[i]);
	}
	printf_s("\n");

	return;
}

void Print_Tabl(int* time, int length)
{
	printf_s("\t");

	for (int i = 1; i < length+1; i++)
	{
		printf_s("%d\t ", time[i]);
	}
	printf_s("\n");

	return;
}

bool Increasing(int* a, int length) {

	for (int i = 0; i < length - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}

	return true;
}

void Copy(int* a, int* b, int length) {
	
	for (int i = 0; i < length; i++)
	{
		b[i] = a[i];
	}

	return;
}