#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <errno.h>

void filegeneration(char *filename)
{
	char ch;
	FILE *f = fopen(filename, "wt");
	if (f != NULL)
		puts("\nfile created");
	else
	{
		perror("can not create file");
		_getch();
		exit(EXIT_FAILURE);
	}
	puts("Enter some string:");
	do
	{
		ch = _getch();
		if (ch != 26)
		{
			if (ch == '\r')
				ch = '\n';
			printf("%c", ch);
			fputc(ch, f);
		}
		else
			break;

	} while (true);
	printf("\n");
	fclose(f);
}
void output(char *filename)
{
	FILE *f = fopen(filename, "rt");
	if (f != NULL) {
		while (!feof(f))
		{
			char ch;
			fscanf(f, "%c", &ch);
			printf("%c", ch);
		}
		printf("\n");
	}
	fclose(f);
}
void findword(char *filename, char *filename2, char ch)
{
	char l, str[10000] = { 0 }, str1[10000] = { 0 }, d[1] = { 0 }, *s;
	d[0] = ch;
	FILE *f = fopen(filename, "rt");
	if (f != NULL)
	{
		puts("file open");
		int i = 0;

		while (!feof(f)) {
			fscanf(f, "%c", &l);
			str[i++] = l;
		}
		str[i] = '\0';
		puts(str);
	}
	else
	{
		perror("can not open file");
		_getch();
		exit(EXIT_FAILURE);
	}

	char *delimiter = " .,!?";
	char *ptr;
	ptr = strtok(str, delimiter);
	while (ptr != NULL)
	{
		if (ptr[0]==d[0])
		{
			strcat(str1, ptr);
			strcat(str1, " ");
		}
		ptr = strtok(nullptr, delimiter);
	}
	puts(str1);
	fclose(f);

	FILE *fl = fopen(filename2, "wt");
	if (fl != NULL)
		puts("file created");
	else
	{
		perror("can not create file");
		_getch();
		exit(EXIT_FAILURE);
	}
	 fputs(str1, fl);
	fclose(fl);
}

int main()
{
	char filename[20] = { 0 }, filename2[20] = { 0 }, ch;
	puts("Enter name of file:");
	gets_s(filename);
	strcat(filename, ".txt");
	filegeneration(filename);
	output(filename);
	puts("Enter name of file:");
	gets_s(filename2);
	strcat(filename2, ".txt");
	puts("Enter symbol:");
	scanf("%c", &ch);
	findword(filename, filename2, ch);
	output(filename2);
	_getch();
	return 0;
}

