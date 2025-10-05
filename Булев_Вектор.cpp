#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
	int x,len=0;
	unsigned int vector = 0;
	char mas[64];
	scanf_s("%d", &x);
	while (x > 0)
	{
		if (x%2 == 1)
		{
			vector += 1 << len;
			mas[len] = '1';
		}
		else
		{
			mas[len] = '0';
		}
		x /= 2;
		len++;
	}
	mas[len] = '\0';

	printf_s("vector(bin) = ");
	for (int i = len-1; i >= 0; i--)
	{
		printf_s("%c", mas[i]);
	}

	printf_s("\nvector(dec) = %d\n", vector);
	bool flag = true;
	for (int j = 0; j < len/2 && flag; j++)
	{
		printf("%d and %d\n", ((1 << j) & vector) >> j, ((1 << (len - j - 1)) & vector) >> (len - j - 1));
		
		if ((((1 << j) & vector) >> j)^(((1 << (len - j - 1)) & vector) >> (len - j - 1)))
		{
			printf_s("Not a palindrome");
			flag = false;
		}
	}
	if (flag)
	{
		printf_s("A palindrome");
	}
	return 0;
}