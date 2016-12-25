#include <stdio.h>

#include "save.h"

/* global variables */
const char *filename = "duck.sav";

/* publis functions */
int save_read()
{
	int ret = 1;
	FILE *file;
	
	file = fopen(filename, "rb");
	if (file != NULL)
	{
		fread(&ret, sizeof(int), 1, file);
		fclose(file);
	}
	return ret;
}

void save_write(int level)
{
	FILE *file;
	
	file = fopen(filename, "wb");
	
	if (file != NULL)
	{
		fwrite(&level, sizeof(int), 1, file);
		fclose(file);
	}
}
