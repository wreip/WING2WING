#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <time.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"
void displayRasterText(float x, float y, float z, char *stringToDisplay)
{
	int length;
	glRasterPos3f(x, y, z);
	length = strlen(stringToDisplay);

	for (int i = 0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, stringToDisplay[i]);
	}
}
