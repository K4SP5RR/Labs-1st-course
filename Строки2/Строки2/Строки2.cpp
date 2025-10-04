#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
	char s[256];
	fgets(s, 256, stdin);
	int i = 0;
	bool flag = true;
	if (s[0] == '-' or s[0] == '+')
	{
		i++;
	}
	for (i; i < strlen(s)-1 and flag; i++) {
		if (strchr("0123456789", s[i]) == NULL) {
			flag = false;
		}
	}
	if (flag)
	{
		printf_s("Yes, an integer");
	}
	else 
	{
		printf_s("No, not an integer");
	}
	return 0;
}