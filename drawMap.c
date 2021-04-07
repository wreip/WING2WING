#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include "loadMap.h"
#include "drawMap.h"
#include "game.h"

void drawBackground()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(Square_size, 30 * Square_size, 1);
	glVertex3f(Square_size, Square_size, 1);
	glVertex3f(30 * Square_size, 0, 1);
	glVertex3f(30 * Square_size, 30 * Square_size, 1);
	glEnd();
}

void drawWall(int *maxX, int *maxY)
{

	for (int j = 0; j < (*maxX); ++j)
	{
		for (int i = 0; i < (*maxY); ++i)
		{
			drawBackground();
			if (*(*(map + j) + i) == '#')
			{
				glColor3f(1.0f, 1.0f, 1.0f);
				glMatrixMode(GL_MODELVIEW);

				glLoadIdentity();
				glTranslatef(i * Square_size, j * Square_size, 0.0f);

				glBegin(GL_QUADS);
				glColor3f(0.0, 0.0, 0.0);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(Square_size, 0.0f, 0.0f);
				glVertex3f(Square_size, Square_size, 0.0f);
				glVertex3f(0.0f, Square_size, 0.0f);

				glEnd();
			}
		}
	}
}

void drawPlayer(player p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;

	glColor3f(0.53, 0.00, 0.80);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j * Square_size, i * Square_size, 0.0f);

	glBegin(GL_QUADS);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(Square_size, 0.0f, 0.0f);
	glVertex3f(Square_size, Square_size, 0.0f);
	glVertex3f(0.0f, Square_size, 0.0f);

	glEnd();
}

void drawTirs(tirsP p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;
	glColor3f(1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j * Shoot_size, i * Shoot_size, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(Shoot_size, 0.0f, 0.0f);
	glVertex3f(Shoot_size, Shoot_size, 0.0f);
	glVertex3f(0.0f, Shoot_size, 0.0f);
	glEnd();
}

void drawAllTirs(listetirsP t)
{
	tirsP first = malloc(sizeof(tirs));
	tirsP next = malloc(sizeof(tirs));
	first = t->starList;
	if (t->starList != NULL && t->starList->nextptr != NULL)
	{
		next = t->starList->nextptr;
	}
	if (t->starList != NULL || t->endList != NULL)
	{
		drawTirs(first);
		if (t->starList->nextptr != NULL)
		{
			drawTirs(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawTirs(next);
			}
		}
	}
}