#include "stdafx.h"
#include "lab.h"

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

