#ifndef playerandcomp
#define playerandcomp

#include "showcards.h"

typedef struct player
{
int score;
card *playercard[MAX_CARDS];
}player;
typedef struct computer
{
int score;
card *computercard[MAX_CARDS];
}computer;

player playerinit()
{ 
    player player1;
    for(int i=0;i<MAX_CARDS;i++)
    {
        player1.playercard[i]=playercards[i];
    }
    return player1;
}
computer computerinit()
{ 
    computer computer1;
    for(int i=0;i<MAX_CARDS;i++)
    {
        computer1.computercard[i]=computercards[i];
    }
    return computer1;
}

#endif