#ifndef _UTILS_H
#define _UTILS_H

#include <stdbool.h>

//Help to write
//PRE : The position exist in the game, the string is not null
//POST : String appears on the scene
void displayRasterText(float x ,float y ,float z ,char *stringToDisplay);

//Return a random number between min and max
//PRE : Min and max are integers
//POST : The random number is between min and max
int randomNumber(int min, int max);

#endif
