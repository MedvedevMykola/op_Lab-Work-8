#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <errno.h>
void filegeneration(char *filename);
void findword(char *filename, char *filename2, char ch);
void output(char *filename);
void add(char *filename, char *filename2, char ch);
void rewrite(char *filename);

int main()
{
	char filename[20] = { 0 }, filename2[20] = { 0 }, ch;

	puts("Enter name of file:");
	gets_s(filename);
	strcat(filename, ".txt");
	filegeneration(filename);
	puts("\nYou wrote\n");
	output(filename);
	puts("Enter name of file:");
	gets_s(filename2);
	strcat(filename2, ".txt");
	puts("Enter symbol:");
	scanf("%c", &ch);
	findword(filename, filename2, ch);
	puts("\nResult file:\n");
	output(filename2);
	puts("Add?");
	puts("Enter y|n:");
	char c = _getch();
	while (c == 'y') {
		add(filename, filename2, ch);
		puts("Add?");
		puts("Enter y|n:");
		c = _getch();
	}
	puts("\n");
	_getch();
	return 0;
}

