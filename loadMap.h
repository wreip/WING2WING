#ifndef _LOADMAP_H_
#define _LOADMAP_H_

#include <stdbool.h>

#define Square_size 20.0
#define Shoot_size 10.0

char **map;

int mX;
int mY;

bool loadMap(int *maxX, int *maxY);

#endif
