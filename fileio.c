#include<stdio.h>

char exists(char *fn);
void initDataFile();
void readFile(char *fn);

int main()
{
	char *fn = "data.dat";
	while (!exists(fn))
		initDataFile(fn);
	readFile(fn);
	printf("\n");
	return 0;
}
char exists(char *fn)
{
	FILE *fp = fopen(fn, "r");
	if (fp == NULL)
		return 0;
	fclose(fp);
	return 1;
}
void initDataFile(char *fn)
{
	FILE *fp = fopen(fn, "w");
	fprintf(fp, "CONTENTS OF DATA FILE");
	fclose(fp);
}
void readFile(char *fn)
{
	char buffer = 0;
	FILE *fp = fopen(fn, "r");
	if (fp == NULL)
		printf("file does not exist");
	else {
		while ((buffer = getc(fp)) != EOF)
			putchar(buffer);
	}
	fclose(fp);
}