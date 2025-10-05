#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

int main()
{
	int n, sum=0, * mas;
	srand(time(NULL));
	scanf_s("%d", &n);
	mas = (int*)malloc(n * sizeof(int));
	
	for (int* k = mas; k < mas + n; k++)
	{
		*k = rand() % 20;
	}
	
	for (int* k = mas; k < mas + n; k++)
	{
		printf_s("%d ", *k);
	}

	bool fl = true;
	
	for (int* k = mas; k < mas+n; k++, fl = !fl)
	{
		if (fl)
		{
			sum += *k;
		}
		else
		{
			sum -= *k;
		}
	}

	free(mas);
	printf_s("\n%d", sum);

	return 0;
}	