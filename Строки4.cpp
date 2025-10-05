#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "locale.h"

int main() {
	setlocale(LC_ALL, "russian");
	char s[256];
	fgets(s, 256, stdin);
	s[strlen(s) - 1] = '\0';
	int sum = 0, lastdig = 0;
	bool flag = true;
	for (int i = 0; i < strlen(s) && flag; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			sum += s[i] - 48;
		}
		else {
			flag = false;
		}
	}
	if (flag)
	{
		lastdig = s[strlen(s) - 1] - 48;

		if (sum % 3 == 0 && lastdig % 2 == 0)
		{
			printf_s("%s является числом и делится на 6", s);
		}
		else {
			printf_s("%s является числом, но не делится на 6", s);
		}
	}
	else {
		printf_s("%s не является числом",s);
	}
	return 0;
}