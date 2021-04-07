#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "loadMap.h"

bool loadMap(int *maxX, int *maxY)
{
	map = malloc(sizeof(char *) * (*maxX));
	FILE *f = NULL;
	f = fopen("map1.txt", "r");
	if (f == NULL)
	{
		printf("file empty");
		return false;
	}
	char c;
	int i = 0;
	int j = 0;

	printf("%d = mY \n", *maxY);
	printf("%d = mX \n", *maxX);

	for (i = 0; i < (*maxX); i++)
	{
		*(map + i) = malloc(sizeof(char *) * (*maxY));
		for (j = 0; j < (*maxY); j++)
		{
			c = fgetc(f);
			*(*(map + i) + j) = c;
		}
		fgetc(f);
	}

	fclose(f);

	printf("\n");

	for (i = 0; i < (*maxX); i++)
	{
		for (j = 0; j < (*maxY); j++)
		{
			printf("%c", *(*(map + i) + j));
		}
		printf("\n");
	}

	return true;
}
