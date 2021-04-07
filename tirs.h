#ifndef _TIRS_H_
#define _TIRS_H_

#include <stdbool.h>

#include "player.h"

struct positionT
{
    int x;
    int y;
};

struct tirs
{
    struct positionT pos;
    bool active;
    struct tirs *prevptr;
    struct tirs *nextptr;
};
typedef struct tirs tirs;

struct listeTirs
{

    int quantite;
    struct tirs *starList;
    struct tirs *endList;
};
typedef struct listeTirs listeTirs;

typedef struct tirs *tirsP;
typedef struct listeTirs *listetirsP;
tirsP createTirs(player p);
listetirsP initialListeTirs();
void insertionTirs(listetirsP t, tirsP base);
void suppressionTirs(listetirsP t, bool test);
void tirer(player p, listetirsP t);
tirsP r;
listetirsP t;

#endif