#include "stdafx.h"
#include "lab.h"


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
		{
			ch = ' ';
			fputc(ch, f);
			break;
		}


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
	char l[100], str[101] = { 0 }, str1[10000] = { 0 }, d[1] = { 0 }, *s, *delimiter = " .,!?", *ptr;
	d[0] = ch;
	FILE *f = fopen(filename, "rt");
	if (f != NULL)
	{
		puts("file open");
		int i = 0;

		while (!feof(f)) {
			fgets(str, 100, f);
			ptr = strtok(str, delimiter);
			while (ptr != NULL)
			{
				if (ptr[0] == d[0])
				{
					strcat(str1, ptr);
					strcat(str1, " ");
				}
				ptr = strtok(nullptr, delimiter);
			}
		}
	}
	else
	{
		perror("can not open file");
		_getch();
		exit(EXIT_FAILURE);
	}
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

void add(char *filename, char *filename2, char ch)
{
	rewrite(filename);
	findword(filename, filename2, ch);
	puts("\nResult file:\n");
	output(filename2);
}

void rewrite(char *filename)
{
	{
		char ch;
		FILE *f = fopen(filename, "at+");
		if (f != NULL)
			puts("\nfile created");
		else
		{
			perror("can not open file");
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
			{
				ch = ' ';
				fputc(ch, f);
				break;
			}

		} while (true);
		printf("\n");
		fclose(f);
	}
}
