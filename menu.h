#ifndef _MENU_H
#define _MENU_H

#include <stdbool.h>
#include "player.h"

//Commands of navigation in the menu of the game
void keyboardMenu(unsigned char key, int x, int y);

//Start the basic menu of the game
void menuDisplay(int *maxX, int *maxY, player p);

#endif
