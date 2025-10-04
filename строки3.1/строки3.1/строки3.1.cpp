#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

char* Delete(char* s) {
	char word = s[0];
	for (int i = 1; i < strlen(s); i++)
	{
		while (word == s[i])
		{
			for (int j = i; j < strlen(s)-1; j++)
			{
				s[j] = s[j + 1];
			}
			strncpy_s(s, 64, s, strlen(s) - 1);
		}
	}
	return s;
}


int main() {
	char s[256];
	fgets(s, 256, stdin);
	char** mas;
	int r = 0, l = 0, count = 0;
	s[strlen(s) - 1] = '\0';

	while (s[r] != '.' && s[r] != '\0')
	{
		if (s[r] == ',')
		{
			count++;
		}
		r++;
	}
	count++;

	mas = (char**)malloc(count * sizeof(char*));
	for (int i = 0; i < count; i++)
	{
		mas[i] = (char*)malloc(64 * sizeof(char));
	}

	r = 0, count = 0;
	while (s[r] != '.' && s[r] != '\0')
	{
		if (s[r] == ',')
		{
			strncpy_s(mas[count], 64, &s[l],  r - l);
			mas[count][r - l] = '\0';
			count++;
			l = r + 1;
		}
		r++;
	}
	
	strncpy_s(mas[count], 64, &s[l], r - l);
	mas[count][r - l] = '\0';
	count++;

	for (int i = 0; i < count-1; i++)
	{
		int flag = strcmp(mas[i], mas[count - 1]);
		if (flag != 0)
		{
			mas[i] = Delete(mas[i]);
			printf_s("%s\n", mas[i]);
		}
	}
	return 0;
}