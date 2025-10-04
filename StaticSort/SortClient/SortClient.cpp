#include "Header.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <windows.h>

int main() {
	int a[100000] = {0}, b[100000] = {0}, t[100] = { 0 }, n;
	srand(time(NULL));
	scanf_s("%d", &n);

	for (int i = 1; i < n+1; i++)
	{
		scanf_s("%d", t+i);
	}

	Print_Tabl(t, n);
	
	double n1, n2, n3, n4, l1, l2, l3, l4;
	double time1[100], time2[100], time3[100], time4[100];

	for (int i = 0; i < n; i++)
	{
		for (int j = t[i]; j < t[i+1]; j++)
		{
			a[j] = rand() % 101;
		}
		
		Copy(a, b, t[i + 1]);
		n4 = GetTickCount64();
		Shaker(b, t[i + 1]);
		l4 = GetTickCount64();

		Copy(a, b, t[i + 1]);
		n1 = GetTickCount64();
		direct_selection_sorting(b, t[i+1]);
		l1 = GetTickCount64();
		
		Copy(a, b, t[i+1]);
		n2 = GetTickCount64();
		direct_inserting_sorting(b, t[i+1]);
		l2 = GetTickCount64();

		Copy(a, b, t[i+1]);
		n3 = GetTickCount64();
		bubble_sorting(b, t[i+1]);
		l3 = GetTickCount64();

		time1[i] = l1 - n1;
		time2[i] = l2 - n2;
		time3[i] = l3 - n3;
		time4[i] = l4 - n4;
		
	}

	Print_Mass_Tabl(time1, n, 's');
	Print_Mass_Tabl(time2, n, 'i');
	Print_Mass_Tabl(time3, n, 'b');
	Print_Mass_Tabl(time4, n, 'h');
	return 0;
}
