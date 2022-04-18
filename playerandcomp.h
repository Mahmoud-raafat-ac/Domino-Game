#ifndef playerandcomp
#define playerandcomp

#include "showcards.h"
// player definition
#define maxplayercompcards 21
typedef struct player
{
int score;
card *playercard[maxplayercompcards];
}player;
// computer definition
typedef struct computer
{
int score;
card *computercard[maxplayercompcards];
}computer;
// Function to intialize player
player playerinit()
{ 
    player player1;
    for(int i=0;i<MAX_CARDS;i++)
    {
        player1.playercard[i]=playercards[i];
    }
    return player1;
}
// Function to intialize computer
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