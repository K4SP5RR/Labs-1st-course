#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#pragma warning(disable : 4996)
int size = 1024 * (rand() % 1023 + 1) - 1;

void CreateFileName(char* name) {
	fgets(name, 128, stdin);
	name[strlen(name) - 1] = '\0';
	strcat(name, ".txt");
}


void CreateRandomFile(FILE** file, char* name) {
	*file = fopen(name, "w");

	if (!*file) {
		perror("Error");
		return;
	}

	for (int i = 0; i < size / sizeof(int); i++)
	{
		fprintf(*file, "%d ", rand() % 10000);
	}

	fclose(*file);
}


void Merge(int p, bool fl) {
	FILE* f1, *f2, *f3, *f4;
	if (fl) {
		f1 = fopen("F3.txt", "r");
		f2 = fopen("F4.txt", "r");
		f3 = fopen("F1.txt", "w");
		f4 = fopen("F2.txt", "w");
	}
	else {
		f1 = fopen("F1.txt", "r");
		f2 = fopen("F2.txt", "r");
		f3 = fopen("F3.txt", "w");
		f4 = fopen("F4.txt", "w");
	}
	
	int b1,b2;
	if (fscanf(f2, "%d", &b2)!=1) {
		FILE* f;
		f = fopen("result.txt", "w");
		int ch;
		while (fscanf(f1, "%d", &ch) == 1) {
			fprintf(f, "%d ", ch);
		}
		return;
	}
	rewind(f1);
	rewind(f2);

	int ch1, ch2;
	bool read1 = fscanf(f1, "%d", &ch1) == 1;
	bool read2 = fscanf(f2, "%d", &ch2) == 1;
	FILE* out = f3;

	while (read1 || read2) {
		int i = 0, j = 0;
		while (i < p && j < p && read1 && read2) {
			if (ch1 <= ch2) {
				fprintf(out, "%d ", ch1);
				read1 = fscanf(f1, "%d", &ch1) == 1;
				i++;
			}
			else {
				fprintf(out, "%d ", ch2);
				read2 = fscanf(f2, "%d", &ch2) == 1;
				j++;
			}
		}
		while (i < p && read1) {
			fprintf(out, "%d ", ch1);
			read1 = fscanf(f1, "%d", &ch1) == 1;
			i++;
		}
		while (j < p && read2) {
			fprintf(out, "%d ", ch2);
			read2 = fscanf(f2, "%d", &ch2) == 1;
			j++;
		}
		if (out == f3)
			out = f4;
		else
			out = f3;
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	Merge(p * 2, !fl);
	return;
}



void Splitting() {
	FILE* f1, *f3, *f4;
	f1 = fopen("F1.txt", "r");
	f3 = fopen("F3.txt", "w");
	f4 = fopen("F4.txt", "w");
	int ch;
	bool fl = true;
	while (fscanf(f1, "%d" , &ch) == 1) {
		if (fl)
			fprintf(f3, "%d ", ch);
		else 
			fprintf(f4, "%d ", ch);
		fl = !fl;
	}
	fclose(f1);
	fclose(f3);
	fclose(f4);
}


int main() {
	FILE* f1, *f;
	char n[128];
	CreateFileName(n);
	CreateRandomFile(&f, n);
	int ch;
	f = fopen(n, "r");
	f1 = fopen("F1.txt", "w");
	while ((ch = fgetc(f)) != EOF)
	{
		fputc(ch, f1);
	}
	fclose(f);
	fclose(f1);
	Splitting();
	Merge(1,true);
	return 0;
}