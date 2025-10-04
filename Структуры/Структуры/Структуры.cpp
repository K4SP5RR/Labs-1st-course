#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
typedef struct DROB {
	int ch, zn;
};

int NOD(int x, int y) {
	x = abs(x);
	y = abs(y);
	int d = y;
	while (x % y != 0) {
		d = x % y;
		x = y;
		y = d;
	}
	return d;
}


int main() {
	srand(time(NULL));
	DROB d[15];
	for (int i = 0; i < 15; i++) {
		d[i] = { rand() % 50 - 25, rand() % 50 - 25 };
		while (d[i].ch == 0)
		{
			d[i].ch = rand() % 50 - 25;
		}
		while (d[i].zn == 0)
		{
			d[i].zn = rand() % 50 - 25;
		}
		printf_s("%d/%d\n", d[i].ch, d[i].zn);

	}
	printf_s("\n");
	DROB sum = d[0];
	int nod;
	for (int i = 1; i < 15; i++)
	{ 
		sum.ch = sum.ch * d[i].zn + d[i].ch * sum.zn;
		sum.zn *= d[i].zn;
		nod = NOD(sum.ch, sum.zn);
		sum.ch /= nod;
		sum.zn /= nod;
		if (sum.zn < 0)
		{
			sum.ch *= -1;
			sum.zn *= -1;
		}
		printf_s("%d/%d\n", sum.ch, sum.zn);
	}
	//printf_s("%d/%d\n", sum.ch, sum.zn);
	return 0;
}