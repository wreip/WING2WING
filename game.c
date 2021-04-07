#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "loadMap.h"
#include "drawMap.h"
#include "tirs.h"

bool UP = false;
bool LEFT = false;
bool RIGHT = false;
bool DOWN = false;
bool SHOOT = false;

//Function to handle the keyboard during the game
void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);

	case 'z':
		UP = true;
		break;

	case 'q':
		LEFT = true;
		break;

	case 'd':
		RIGHT = true;
		break;

	case 's':
		DOWN = true;
		break;

	case 32:
		SHOOT = true;
		break;
	}
}

//Game logic
void game(int *maxX, int *maxY, player p, listetirsP t)
{

	drawWall(maxX, maxY); //afficher la carte
	drawPlayer(p);

	if (t->starList != NULL || t->endList != NULL)
	{
		drawAllTirs(t);
	}

	glutKeyboardFunc(Keyboard); //fonction de glut gérant le clavier

	if (LEFT == true)
	{

		moveLeft(p); //va se déplacer vers la gauche si on appuie sur q
		LEFT = false;
	}
	if (RIGHT == true)
	{

		moveRight(p); //va se déplacer vers la droite si on apppuie sur d
		RIGHT = false;
	}
	if (UP == true)
	{
		moveUp(p);
		UP = false;
	}

	if (DOWN == true)
	{

		moveDown(p);
		DOWN = false;
	}
	if (SHOOT == true)
	{
		tirer(p, t);
		SHOOT = false;
	}

	glutPostRedisplay();
}