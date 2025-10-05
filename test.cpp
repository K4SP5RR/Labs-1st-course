#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double Space(double x, double y, double z) 
{	
	double p = (x + y + z) / 2;
	return sqrt(p * (p - x) * (p - y) * (p - z));
}


int main() 
{
	double x[5], y[5], s = 0;
	
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%lf", &x[i]);
		scanf_s("%lf", &y[i]);
	}


	double xc = fabs(x[3] - x[1]) / 2., yc = fabs(y[3] - y[1]) / 2., l1,l2,l3;
	 
	for (int i = 0; i < 5; i++)
	{
		l1 = sqrt(pow(x[(i + 1)%5] - x[i], 2) + pow(y[(i + 1)%5] - y[i], 2));
		l2 = sqrt(pow(xc - x[i], 2) + pow(yc - y[i], 2));
		l3 = sqrt(pow(xc - x[(i+1)%5], 2) + pow(yc - y[(i+1)%5], 2));

		s += Space(l1, l2, l3);
	} 

	printf_s("%lf", s);
	return 0;
}