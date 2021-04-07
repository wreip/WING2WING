#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "loadMap.h"
#include "menu.h"
#include "game.h"
#include "player.h"
#include "drawMap.h"
#include "utilities.h"

bool GAME = false;
bool MENU = false;
bool QUIT = false;

void keyboardMenu(unsigned char key, int x, int y) // fonction allant gérer les input
{
	switch (key)
	{
	case 'a':
		GAME = true;
		break;

	case 'd':
		QUIT = true;
		break;

	case 'r':
		MENU = true;
		break;
	}
}

void menuDisplay(int *maxX, int *maxY, player p)
{

	glLineWidth(50);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.53, 0.00, 0.80);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0, Square_size * 30, 0.5);
	glVertex3f(Square_size * 41, Square_size * 30, 0.5);
	glVertex3f(Square_size * 41, 0, 0.5);
	glEnd();

	glLineWidth(1);

	glColor3f(0.53, 0.00, 0.80);
	glBegin(GL_POLYGON);
	glVertex3f((41 * Square_size / 2) - 100, 200, 0.5);
	glVertex3f((41 * Square_size / 2) + 100, 200, 0.5);
	glVertex3f((41 * Square_size / 2) + 100, 250, 0.5);
	glVertex3f((41 * Square_size / 2) - 100, 250, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f((41 * Square_size / 2) - 100, 275, 0.5);
	glVertex3f((41 * Square_size / 2) + 100, 275, 0.5);
	glVertex3f((41 * Square_size / 2) + 100, 325, 0.5);
	glVertex3f((41 * Square_size / 2) - 100, 325, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f((41 * Square_size / 2) - 100, 350, 0.5);
	glVertex3f((41 * Square_size / 2) + 100, 350, 0.5);
	glVertex3f((41 * Square_size / 2) + 100, 400, 0.5);
	glVertex3f((41 * Square_size / 2) - 100, 400, 0.5);
	glEnd();

	glColor3f(1, 1, 1);
	displayRasterText((Square_size * 41 / 2) - 75, 230, 0.4, "'a' - START");
	displayRasterText((Square_size * 41 / 2) - 75, 310, 0.4, "'b' - RULES");
	displayRasterText((Square_size * 41 / 2) - 75, 380, 0.4, "'c' - SCORES");
	displayRasterText((Square_size * 41 / 2) + 280, 580, 0.4, "d - EXIT");

	glColor3f(1.0, 1.0, 1.0);
	displayRasterText((Square_size * 41 / 2) - 107, 480, 0.4, "Press a key to choose");
	displayRasterText((Square_size * 41 / 2) - 75, 100, 0.4, "WING2WING");

	glutKeyboardFunc(keyboardMenu);

	if (GAME == true)
	{
		game(&mX, &mY, p, t);
	}
	if (QUIT == true)
	{
		exit(0);
	}
}
