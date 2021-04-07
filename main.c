#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "loadMap.h"
#include "drawMap.h"
#include "game.h"
#include "player.h"
#include "tirs.h"
#include "menu.h"
bool test = false;

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int width, int heigth)
{
	glViewport(0, 0, width, heigth);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, heigth, 0);
}

void Display()
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	menuDisplay(&mX, &mY, p);
	glutSwapBuffers();
	glutPostRedisplay();

	glLoadIdentity();

	glFlush();
}

void updateTirs(int valeur)
{
	r = t->starList;
	if (t->starList != NULL)
	{
		r->pos.x -= 1;
		if (r->pos.x < 1)
		{
			r->pos.x = 88;
			r->active = false;
		}
		while (r->nextptr != NULL)
		{
			r = r->nextptr;
			r->pos.x -= 1;
			if (r->pos.x < 1)
			{
				r->pos.x = 88;
				r->active = false;
			}
		}
	}
	if (t->starList != NULL || t->endList != NULL)
	{
		suppressionTirs(t, test);
	}

	glutPostRedisplay();
	glutTimerFunc(50, updateTirs, 0);
}

int main(int argc, char *argv[])
{

	mX = 30;
	mY = 41;
	srand(time(NULL));

	loadMap(&mX, &mY);
	p = createPlayer(&mX, &mY);
	t = initialListeTirs();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(mY * Square_size, mX * Square_size);

	glutCreateWindow("Wing2Wing");

	initRendering();

	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);
	glutTimerFunc(50, updateTirs, 0);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 0;
}