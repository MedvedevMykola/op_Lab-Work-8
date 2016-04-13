#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <errno.h>

void filegeneration()
{
	char filename[20] = { 0 }, ch;
	puts("Enter name of file:");
	gets_s(filename);
	strcat(filename, ".txt");
	FILE *f = fopen(filename, "wt+");
	if (f != NULL)
		puts("\nfile created");
	else
	{
		perror("can not create file");
		_getch();
		exit(EXIT_FAILURE);
	}
	puts("Enter some string");
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

}

int main()
{
	filegeneration();
	_getch();
	return 0;
}

