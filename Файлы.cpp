#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#pragma warning(disable : 4996)
void CreateFileName(char* name){
	fgets(name, 128, stdin);
	name[strlen(name) - 1] = '\0';
	strcat(name, ".txt");
}

	
void CreateRandomFile(FILE** file, char* name) {
	int size = 1024 * (rand() % 1023 + 1) - 1;
	*file = fopen(name, "w+");

	if (!*file) {
		perror("Error");
		return;
	}
	
	for (int i = 0; i < size/sizeof(int); i++)
	{
		 fprintf(*file,"%d ", rand() % 1000);
	}
	
	fclose(*file);
}

unsigned int GetSizeFile(const char* name) {
	FILE* file = fopen(name, "rb");
	
	if (!file) {
		perror("Error");
		return 0;
	}

	fseek(file, 0, SEEK_END);
	unsigned int size = ftell(file);
	fclose(file);
	return size;
}
void MaxS(unsigned int s1, unsigned int s2, unsigned int s3, char* name1, char* name2, char* name3, char*n) {
	int max = 0;

	if (max < s1)
    {
		max = s1;
		strcpy(n, name1);
	}
	if (max < s2)
	{
		max = s2;
		strcpy(n, name2);
	}
	if (max < s3)
	{
		max = s3;
		strcpy(n, name3);
	}
}

void MinS(unsigned int s1, unsigned int s2, unsigned int s3, char* name1, char* name2, char* name3, char*n) {
	int min = s1;
	strcpy(n, name1);
	if (min > s2)
	{
		min = s2;
		strcpy(n, name2);
	}
	if (min > s3)
	{
		min = s3;
		strcpy(n, name3);
	}
}

void ChangeFile(char* max, char* min) {
	FILE* mxfile, *mnfile;
	FILE* t = tmpfile();
	mxfile = fopen(max, "r");
	int ch;
	while ((ch=fgetc(mxfile)) != EOF)
	{
		fputc(ch, t);
	}
	fclose(mxfile);
	mxfile = fopen(max, "w");
	mnfile = fopen(min, "r");
	while ((ch = fgetc(mnfile)) != EOF) {
		fputc(ch, mxfile);
	}
	fclose(mnfile);
	mnfile = fopen(min, "w");
	rewind(t);
	while ((ch = fgetc(t)) != EOF) {
		fputc(ch, mnfile);
	}
	fclose(mxfile);
	fclose(mnfile);
	fclose(t);
}


int main() {
	srand(time(NULL));
	char name1[128], name2[128], name3[128], mxs[128], mns[128];
	CreateFileName(name1);
	CreateFileName(name2);
	CreateFileName(name3);
	FILE* file1;
	FILE* file2; 
	FILE* file3;
	unsigned int size1, size2, size3;

	CreateRandomFile(&file1, name1);
	CreateRandomFile(&file2, name2);
	CreateRandomFile(&file3, name3);
	getchar();
	size1 = GetSizeFile(name1);
	size2 = GetSizeFile(name2);
	size3 = GetSizeFile(name3);
	MaxS(size1, size2, size3, name1, name2, name3, mxs);
	MinS(size1, size2, size3, name1, name2, name3, mns);

	ChangeFile(mxs, mns);
	
	return 0;
}