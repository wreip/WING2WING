#ifndef _DRAWMAP_H_
#define _DRAWMAP_H_

#include "loadMap.h"
#include "player.h"
#include "tirs.h"

//Draw the Background of the Map
void drawBackground();
//Draw the Background of the Map
void drawWall(int *maxX, int *maxY);

void drawPlayer(player p);
//Draw the player with a position according to the map1.txt
void drawPTirs(tirsP p);
void drawAllTirs(listetirsP t);

#endif
