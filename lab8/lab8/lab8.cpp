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

void findword(char *filename, char ch)
{
	char l[1] = { 0 }, str[10000] = { 0 }, str1[10000] = { 0 }, d[1] = { 0 };
	d[0] = ch;
	FILE *f = fopen(filename, "rt");
	if (f != NULL)
	{
		puts("\nfile created");
		int i = 0;
		
		while (l[0] = getc(f) != EOF)
			str[i++] = l[0];
		str[i] = '\0';
		puts(str);
	}
	else
	{
		perror("can not create file");
		_getch();
		exit(EXIT_FAILURE);
	}
	
	char *delimiter = "\., !?:;";
	char *ptr;
	ptr = strtok(str,delimiter);
	while (ptr != NULL) 
	{
		if (strstr(ptr, d) == ptr) 
		{
			strcat(str1, ptr);
			strcat(str1, " ");
		}
		ptr = strtok(nullptr, delimiter);
	}
	fclose(f);
	char filename2[20] = { 0 };
	puts("Enter name of file:");
	gets_s(filename2);
	strcat(filename2, ".txt");
	FILE *fl = fopen(filename, "wt");
	if (fl != NULL)
		puts("\nfile created");
	else
	{
		perror("can not create file");
		_getch();
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < strlen(str1); i++)
	{
		printf("%c", str1[i]);
		putc(str1[i], fl);		
	}
	
	fclose(fl);
}

int main()
{
	char filename1[20] = { 0 }, filename2[20] = { 0 }, ch;
	puts("Enter name of file:");
	gets_s(filename1);
	strcat(filename1, ".txt");
	filegeneration(filename1);
	puts("Enter symbol:");
	scanf_s("%c\n",&ch);
	findword(filename1, ch);
	_getch();
	return 0;
}

