#pragma once
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
